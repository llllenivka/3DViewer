# 3DViewer

3DViewer is a program for visualizing wireframe models in 3D space, developed in C++ language using the principles of object-oriented programming and integrating a graphical user interface. The program supports working with wireframe models of .obj format, allows manipulating objects in space using various affine transformations and visualizing models with a high level of detail

This project was realized in a team. I was responsible for the implementation of the visual part of the program.

## Contents
1.  [Program Features](#program-features)
2.  [Requirements](#requirements)
3.  [Build and Install](#build-and-install)
2.  [How to Use](#how-to-use)
2.  [Architecture](#architecture)
2.  [Testing](#testing)
2.  [Additional Features](#additional-features)

## Program Features

- Model loading: The program supports loading wireframe models from .obj files with data types: vertex and surface list.
- Affine Transformations: Features include moving, rotating and scaling the model in X, Y, Z axes.
- GUI: Developed using the Qt library, providing a user-friendly interface for interacting with the program.
- Projection types: Support for parallel and center projection.
- Settings and visualization: Ability to adjust the thickness and type of edges, background color, and save settings between program restarts.
- Image saving: Ability to save rendered images in BMP and JPEG format.
- Animation generation: The program supports the creation of GIF-animated screencasts.
- Performance: Supports models with up to 1,000,000 vertices without interface freezes.

## Requirements

Program Requirements:
- Language: C++17
- Compiler: GCC (GNU Compiler Collection)
- GUI library: Qt
- Build system: Makefile
- Dependencies: Qt 5+

## Build and Install

- Repository cloning:
```
git clone https://github.com/llllenivka/3DViewer.git
cd 3DViewer
```
- Build using Makefile:
- Open a terminal in the project directory and run the command:
```
cd src
make
```
- To install, run:
```
make install
```
- To clean up all compiled files:
```
make clean
```

## How to Use

The program interface contains the following elements:
- Load model: Button to select .obj file and display the name of the selected file.
- Affine Transformations: Input fields and buttons to move, rotate and scale the model.
- Model information: Display information about the model (number of vertices and edges).
- Settings: Ability to adjust the projection type, background color, rib type and color.
- To save an image in BMP or JPEG format, use the “Save Image” button.
- To record an animation (GIF), click on the “Save Gif” button.

## Architecture

The program uses the Model-View-Controller (MVC) design pattern to separate business logic, user interface, and controllers:
- Model (Model): Contains the data and business logic. In this case, these are classes for working with 3D models and affine transformations.
- View (View): Responsible for displaying the data, using the Qt library for the interface.
- Controller: Handles user actions.
The design patterns used to implement the design patterns are:
- Strategy (Athene Transformations).
- Singleton (Parser Implementation).
- Facade (Frontend Implementation).

## Testing

Unit tests to verify the correctness of the program are located in the src/Test/ folder. They include tests for:
Loading .obj models.
Affine transformations (move, scale, rotate).
To run the tests, run the command:
```
make tests
```

## Additional features
- The program is optimized to work with models up to 1 000 000 vertices.
- Saving settings: All user settings are saved to a configuration file and restored the next time the program is run.