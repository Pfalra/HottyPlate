import cv2
from PIL import Image
import numpy as np
import fitz
import io
from tkinter import filedialog, Button, Tk, Label
import pytesseract
from scipy.interpolate import interp1d
import matplotlib.pyplot as plt
import pandas as pd


# Global variables
# If the max y-axis value is the highest point of the curve and not the highest point of the graph set this to the value
max_value = 260
filename = ""
tesseract_name = ""



# Callback function, which takes care of the cropping of the pdf images
def mouse_crop(event, x, y, flags, param):
    # grab references to the global variables
    global x_start, y_start, x_end, y_end, cropping, return_list
    # if the left mouse button was DOWN, start RECORDING
    # (x, y) coordinates and indicate that cropping is being
    if event == cv2.EVENT_LBUTTONDOWN:
        x_start, y_start, x_end, y_end = x, y, x, y
        cropping = True
    # Mouse is Moving
    elif event == cv2.EVENT_MOUSEMOVE:
        if cropping == True:
            x_end, y_end = x, y
    # if the left mouse button was released
    elif event == cv2.EVENT_LBUTTONUP:
        # record the ending (x, y) coordinates
        x_end, y_end = x, y
        cropping = False  # cropping is finished
        refPoint = [(x_start, y_start), (x_end, y_end)]
        if len(refPoint) == 2:  # when two points were found
            roi = oriImage[refPoint[0][1]:refPoint[1][1], refPoint[0][0]:refPoint[1][0]]
            cv2.imshow("Chosen Graph", roi)
            return_list.append(roi)
            print(f"Graphs added to List: {len(return_list)}")


# Setting up variables and start the image loop
def crop_image(image):
    global cropping, x_start, y_start, x_end, y_end, oriImage
    cropping = False
    x_start, y_start, x_end, y_end = 0, 0, 0, 0
    image = np.array(image)
    oriImage = image.copy()



    cv2.namedWindow("image")
    cv2.setMouseCallback("image", mouse_crop, 0)
    while True:
        i = image.copy()
        if not cropping:
            cv2.imshow("image", image)
        elif cropping:
            cv2.rectangle(i, (x_start, y_start), (x_end, y_end), (255, 0, 0), 2)
            cv2.imshow("image", i)
        cv2.waitKey(1)
        if cv2.getWindowProperty('image', cv2.WND_PROP_VISIBLE) < 1:
            break


# Callback to remove noise from the graph image
def mouse_black(event, x, y, flags, param):

    # grab references to the global variables
    global x_start, y_start, x_end, y_end, cropping, return_list
    # if the left mouse button was DOWN, start RECORDING
    # (x, y) coordinates and indicate that cropping is being
    if event == cv2.EVENT_LBUTTONDOWN:
        x_start, y_start, x_end, y_end = x, y, x, y
        cropping = True
    # Mouse is Moving
    elif event == cv2.EVENT_MOUSEMOVE:
        if cropping == True:
            x_end, y_end = x, y
    # if the left mouse button was released
    elif event == cv2.EVENT_LBUTTONUP:
        # record the ending (x, y) coordinates
        x_end, y_end = x, y
        cropping = False  # cropping is finished


# Function to "read" the graph given by the third cropped image
def traverse_graph(image, top=True):
    # Thresholds
    global longest_left_vert_line, longest_bot_hor_line, longest_right_vert_line, longest_top_hor_line
    image_h, image_w = image.shape

    length_counter = 0
    # remove horizontal and vetical lines
    for i in range(image_w):
        for j in range(image_h):
            if image[j, i] != 0:
                length_counter += 1

        if length_counter > (image_h / 4):
            image[0:image_h, i] = 0
            length_counter = 0
    for i in range(image_h):
        for j in range(image_w):
            if image[i, j] != 0:
                length_counter += 1

        if length_counter > (image_w / 4):
            image[i, 0:image_w] = 0
            length_counter = 0

    # Start the image loop to remove noise
    cv2.namedWindow("black_out")
    cv2.setMouseCallback("black_out", mouse_black, 0)
    while True:
        if not cropping:
            cv2.imshow("black_out", image)
        elif cropping:
            cv2.rectangle(image, (x_start, y_start), (x_end, y_end), (0, 0, 0), -1)
            cv2.imshow("black_out", image)
        cv2.waitKey(1)
        if cv2.getWindowProperty('black_out', cv2.WND_PROP_VISIBLE) < 1:
            break

    # Start "reading" of the curve
    interpolate_coordinate = []

    # Find the first white pixel in each column either from the bot or from the top
    if top:
        for i in range(image_w):
            for j in range(image_h):
                if image[j, i] != 0:
                    interpolate_coordinate.append((i - longest_left_vert_line[0][0], longest_bot_hor_line[0][1] - j))
                    break
    else:
        for i in range(image_w):
            for j in range(image_h):
                if image[image_h - j, i] != 0:
                    interpolate_coordinate.append((i - longest_left_vert_line[0][0], longest_bot_hor_line[0][1] - j))
                    break

    # The first white pixels are the points that define the curve
    coord = np.array(interpolate_coordinate)
    # Interpolate between the curve points in order to compensate the columns with no white pixels
    f = interp1d(coord[:, 0], coord[:, 1], bounds_error=False, fill_value="extrapolate")
    # show the interpolated curve
    plt.figure()
    plt.plot(np.arange(0, image_w, 1), f(np.arange(0, image_w, 1)))
    plt.show()
    return f


# Get all images from a pdf
def get_image(path="graph_pdf.pdf"):
    # image list to return
    global return_list
    return_list = []
    # open the file
    pdf_file = fitz.open(path)
    # get the page itself
    # iterate over PDF pages
    for page_index in range(len(pdf_file)):
        # get the page itself
        page = pdf_file[page_index]
        image_list = page.getImageList()
        # printing number of images found in this page
        if image_list:
            print(f"[+] Found a total of {len(image_list)} images in page {page_index}")
        else:
            print("[!] No images found on page", page_index)
        for image_index, img in enumerate(page.getImageList(), start=1):
            # get the XREF of the image
            xref = img[0]
            # extract the image bytes
            base_image = pdf_file.extractImage(xref)
            image_bytes = base_image["image"]
            # load it to PIL
            image = Image.open(io.BytesIO(image_bytes))
            # get the graph images from the list
            crop_image(image)
        print(f"Graphs added to List: {len(return_list)}")
    cv2.destroyAllWindows()
    return return_list


# Main function
def process(path, tesseract):
    # Pytesseract is a neural network designed to detect text or numbers, this is used to detect the y and x axis values
    # Load it here
    pytesseract.pytesseract.tesseract_cmd = tesseract
    # get images in the form {(y axis, x axis, graph) x n }
    images = get_image(path)
    # Set up variables
    y_max = 0
    x_max = 0
    y_min = 10000
    x_min = 10000
    global longest_left_vert_line, longest_bot_hor_line, longest_right_vert_line, longest_top_hor_line
    longest_left_vert_line = [[100000, 0, 100000, 0]]
    longest_bot_hor_line = [[1000000, 0, 1000000, 0]]
    longest_right_vert_line = [[0, 100000, 0, 100000]]
    longest_top_hor_line = [[1000000, 100000, 1000000, 100000]]
    triple_counter = 0
    if len(images) > 0:
        for img in images:
            # Process the y axis image
            if triple_counter == 0:
                triple_counter += 1
                conc = ""
                # Get the max and min y axis value depending on what pytesseract detected
                print(pytesseract.image_to_string(img, config='--psm 6'))
                for i in pytesseract.image_to_string(img, config='--psm 6'):
                    if i.isnumeric():
                        conc += i
                    else:
                        if conc is not "" and int(conc) > y_max:
                            y_max = int(conc)
                        if conc is not "" and int(conc) < y_min:
                            y_min = int(conc)
                        conc = ""

                continue
            # Process the x axis
            if triple_counter == 1:
                triple_counter += 1
                conc = ""
                print(pytesseract.image_to_string(img, config='--psm 6'))
                # Get the max and min x axis value depending on what pytesseract detected
                for i in pytesseract.image_to_string(img, config='--psm 6'):
                    if i.isnumeric():
                        conc += i
                    else:
                        if conc is not "" and int(conc) > x_max:
                            x_max = int(conc)
                        if conc is not "" and int(conc) < x_min:
                            x_min = int(conc)
                        conc = ""
                continue
            # Process graph image
            if triple_counter == 2:
                triple_counter = 0
                tmp = img.copy()
                # Get straight lines
                edges = cv2.Canny(img, 50, 150, apertureSize=3)
                minLineLength = 100
                lines = cv2.HoughLinesP(image=edges, rho=1, theta=np.pi / 180, threshold=100, lines=np.array([]),
                                        minLineLength=minLineLength, maxLineGap=80)

                a, b, c = lines.shape
                h, w, _ = img.shape
                # Find the longest straight vertical and horizontal lines
                for i in range(a):
                    if (np.abs(lines[i][0][0] - lines[i][0][2]) > (np.abs(
                            longest_bot_hor_line[0][0] - longest_bot_hor_line[0][2]))/2) and (
                            lines[i][0][3] > longest_bot_hor_line[0][3]) and (lines[i][0][3] > (h / 2)):
                        longest_bot_hor_line = lines[i]
                    if (np.abs(lines[i][0][1] - lines[i][0][3]) > (np.abs(
                            longest_left_vert_line[0][1] - longest_left_vert_line[0][3]))/2) and (
                            lines[i][0][0] < longest_left_vert_line[0][0]) and (lines[i][0][0] < (w / 2)):
                        longest_left_vert_line = lines[i]
                    if (np.abs(lines[i][0][0] - lines[i][0][2]) > (np.abs(
                            longest_top_hor_line[0][0] - longest_top_hor_line[0][2]))/2) and (
                            lines[i][0][3] < longest_top_hor_line[0][3]) and (lines[i][0][3] < (h / 2)):
                        longest_top_hor_line = lines[i]
                    if (np.abs(lines[i][0][1] - lines[i][0][3]) > (np.abs(
                            longest_right_vert_line[0][1] - longest_right_vert_line[0][3]))/2) and (
                            lines[i][0][0] > longest_right_vert_line[0][0]) and (lines[i][0][0] > (w / 1.2)):
                        longest_right_vert_line = lines[i]

                # The graph is everything inside the four lines
                left_top_intersection = (longest_left_vert_line[0][0], longest_top_hor_line[0][1])
                left_bot_intersection = (longest_left_vert_line[0][0], longest_bot_hor_line[0][3])
                right_top_intersection = (longest_right_vert_line[0][2], longest_top_hor_line[0][1])
                right_bot_intersection = (longest_right_vert_line[0][2], longest_bot_hor_line[0][3])

                # Draw the lines in order to show the user if the graph was correctly identified
                cv2.line(tmp, left_top_intersection, right_top_intersection, (0, 255, 0), 3,
                        cv2.LINE_AA)
                cv2.line(tmp, left_bot_intersection, right_bot_intersection, (0, 255, 0), 3,
                        cv2.LINE_AA)
                cv2.line(tmp, left_bot_intersection, left_top_intersection, (0, 255, 0), 3,
                        cv2.LINE_AA)
                cv2.line(tmp, right_bot_intersection, right_top_intersection, (0, 255, 0), 3,
                        cv2.LINE_AA)
                cv2.imshow("result", tmp)
                cv2.waitKey(0)

                result = img.copy()
                # Make the image black and white
                gray = cv2.cvtColor(result, cv2.COLOR_BGR2GRAY)
                thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)[1]

                alpha = cv2.threshold(thresh, 100, 255, cv2.THRESH_BINARY)[1]

                # Get the interpolation function
                interp = traverse_graph(alpha)

                # calculate the length of the horizontal and vertical graph line
                length_x = np.abs(longest_left_vert_line[0][2] - longest_right_vert_line[0][0])
                length_y = np.abs(longest_bot_hor_line[0][1] - longest_top_hor_line[0][3])
                # Minutes as unit is assumed
                x_max_seconds = x_max * 60
                # 5ms granularity chosen
                num_values = int(x_max_seconds/0.005)
                # Create the x points to look at
                x_values = np.linspace(0, length_x, num_values)
                # Get the final y value by using the interpolation function on the x values
                # Also map the y and x values into the correct range
                if max_value > 0:
                    final_y = np.interp(interp(x_values), [0, np.max(interp(x_values))], [y_min, max_value])
                    final_x = np.interp(x_values, [0, length_x], [x_min, x_max])
                else:
                    final_y = np.interp(interp(x_values), [0, length_y], [y_min, y_max])
                    final_x = np.interp(x_values, [0, length_x], [x_min, x_max])
                # Show the final "read" curve in the right range
                plt.figure()
                plt.plot(final_x, final_y)
                plt.show()
                # write a CSV file with the values
                df = pd.DataFrame({'X_Values': final_x, 'Y_Values': final_y})
                print("Writing CSV ...")
                df.to_csv("Output")
                print("Writing CSV done")


# Starts processing if the file is chosen
def askopenfilename():
    # get filename, this is the bit that opens up the dialog box this will
    # return a string of the file name you have clicked on.
    global filename, tesseract_name
    filename = filedialog.askopenfilename()
    if filename:
        if tesseract_name is not "":
            # Will print the file name to the text box
            process(filename, tesseract_name)


# Starts processing if the file is chosen
def askopenfilename1():
    # get filename, this is the bit that opens up the dialog box this will
    # return a string of the file name you have clicked on.
    global filename, tesseract_name
    tesseract_name = filedialog.askopenfilename()
    if tesseract_name:
        if filename is not "":
            # Will print the file name to the text box
            process(filename, tesseract_name)


# Main setting up the small 'GUI'
if __name__ == '__main__':

    # Make the root window
    root = Tk()

    # Make a button to get the file name
    # The method the button executes is the askopenfilename from above
    # You don't use askopenfilename() because you only want to bind the button
    # to the function, then the button calls the function.
    label = Label(root, text="Choose your PDF File").grid(row=0)
    button = Button(root, text='GetFileName', command=askopenfilename).grid(row=1)
    button1 = Button(root, text='GetTesseractPath', command=askopenfilename1).grid(row=2)
    # Start the application mainloop
    root.mainloop()


