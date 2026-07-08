# Function Graph Plotter 📈

This project is a function graph plotter program developed using **C++** and the **Qt** graphical interface library. 

## 🚀 Features

- **Function Plotting**: The program is capable of plotting and visualizing multiple mathematical functions using the provided `Evaluator` class to evaluate the expressions.
- **Color Control**: When adding a new function through the plotting menu, the user can select the curve color from the following options: Blue, Red, Green, or Black.
- **Graph Management**: The main window features a visual table (`QTableWidget`) that displays all currently plotted functions and their corresponding colors.
- **Axis Adjustment**: The X and Y axis limits (minimum, maximum, and exponential values) can be dynamically adjusted by the user through components in the interface.
- **Automatic Resizing**: The graph image dynamically and automatically adjusts and redraws itself whenever the main window's size is modified by the user.
- **Coordinate Inspection**: The user can click with the mouse anywhere on the graph area, and the exact coordinates of that point (X and Y) will be displayed in the bottom status bar.
- **Error Handling**: If the user attempts to enter an invalid mathematical expression, the application intercepts the error and displays an alert window reporting the failure.
- **Quick Clear**: A "Clear" command allows removing all curves at once and resetting the visualization interface.

## 🛠️ Structure and Main Classes

- **`MainPlotador`**: This is the class corresponding to the main application window (inheriting from `QMainWindow`), which acts by interconnecting the menus, layout, and system interactions.
- **`LehFuncao`**: This is the auxiliary dialog window class that contains text boxes and buttons to register the newly entered mathematical expressions.
- **`Grafico`**: A customized class that inherits the properties of a standard `QLabel`. This class houses the graph data management and overrides system events (`resizeEvent` and `mouseReleaseEvent`) to allow for resizing and interactive clicking.
- **`Evaluator`**: The class used to validate and calculate the value of the mathematical function to be plotted.

## 💻 Technologies

- **Programming Language**: C++
- **UI Framework**: Qt
- **Environments**: Qt Creator and Qt Designer
