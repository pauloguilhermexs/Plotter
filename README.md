# MainPlotador

MainPlotador is a desktop application built with C++ and the Qt Framework designed to plot, visualize, and manage mathematical functions interactively.

## 🚀 Features

- **Dynamic Function Plotting**: Add multiple mathematical functions to a single graphical view. Each function is assigned a specific color.
- **Viewport Control**: Interactively adjust the minimum, maximum, and step (exponential) limits for both the X and Y axes using dedicated spin boxes.
- **Smart Axis Boundaries**: The application automatically prevents invalid viewport states (e.g., preventing the minimum axis value from exceeding or equaling the maximum value).
- **Function Table Manager**: A dynamic table displays all currently plotted functions alongside a visual color swatch (`QPixmap`) for easy identification.
- **Interactive Coordinates**: Clicking anywhere on the plotted graph instantly displays the exact (X, Y) coordinates in the application's status bar.
- **Error Handling**: Built-in exception catching alerts the user via a pop-up dialog (`QMessageBox`) if an invalid mathematical expression is entered.
- **Quick Clear**: Easily wipe the canvas and reset the function list with a single click.

## 🛠️ Technologies & Tools

- **Language**: C++
- **Framework**: Qt (QtWidgets, GUI, Core)
- **Key Components**: `QMainWindow`, `QTableWidget`, `QSpinBox`, `QLabel`, `QMessageBox`, `Grafico`, `LehFuncao`.

## 📁 Project Structure

- **`MainPlotador`**: The main application window (`QMainWindow`) that manages the user interface, the graph widget, and the function input dialog.
- **`Grafico`**: A custom widget responsible for rendering the mathematical functions and handling click events.
- **`LehFuncao`**: A secondary dialog/window where the user inputs the mathematical expression to be plotted.

## ⚙️ How to Run

1. Ensure you have the **Qt Framework** and **Qt Creator** installed on your machine.
2. Open the `.pro` (or `CMakeLists.txt`) file in Qt Creator.
3. Configure the project with your preferred C++ compiler kit (e.g., MinGW, MSVC, GCC).
4. Build and Run the project (`Ctrl+R`).
