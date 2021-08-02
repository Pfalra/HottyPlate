### HOW TO USE CV2_GRAPH_READER ###

1. Click the button "GetFileName" and choose the PDF file containing the graph to read.

2. Click the button "GetTesseractName" and choose the tesseract.exe file.

3. Close all windows, which do not contain the image of your graph.

4. Press and hold the left mouse button in order to mark the values corresponding to the
   y axis of your graph. Make sure that all values are in the blue rectangle.

5. Do the same thing for the x axis values.

6. Mark the whole graph.

7. Close all remaining windows or repeat step 3-5 if you want to process multiple graphs.

8. Close the window showing the outline of the recognized graph. Close the program if the 
   graph was not recognized correctly.

9. Press and holf the left mouse button to remove noise in the shown window. Only the 
   outline of the curve to read should be left.

10. Close the window. The next window shows an image of the interpolated graph. Close this 
   window too. The next window shows an image of the graph, which was read. Check if the
   min and max y and x axis values are correct and the curve looks right.

11. Also close this window. If everything worked correctly a CSV file is now written to
    your current directory.

### REQUIREMENTS ###
In order to use the module you need to have tesseract.exe installed.