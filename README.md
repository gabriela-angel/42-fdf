# FDF - 3D Wireframe Renderer

A 3D wireframe renderer project from 42 School that visualizes 3D terrain maps in isometric projection.

## Overview

FdF (Fil de Fer, meaning "wireframe" in French) is a 42 School project that creates a 3D wireframe representation of landscapes. The program reads elevation data from a file and renders it as an isometric projection, connecting points with line segments to create a mesh visualization.
This project introduces fundamental concepts of:

Computer Graphics: Understanding 3D to 2D projection
Isometric Projection: Mathematical transformation of coordinates
Line Drawing Algorithms: Bresenham's line algorithm
Graphics Library Usage: Working with MiniLibX
Memory Management: Efficient handling of 2D arrays and structures

## Features

- **3D Wireframe Visualization**: Renders 3D terrain maps as connected wireframes
- **Isometric Projection**: Projects 3D coordinates to 2D isometric view
- **Color Support**: Supports colored vertices and gradient coloring between points
- **Custom Memory Management**: Implements dynamic memory allocation with tracking
- **Graphics Rendering**: Built with MLX42 for cross-platform graphics
- **Modular Architecture**: Organized code for map parsing, rendering, and utilities

## Building the Project

### Prerequisites

- GCC compiler
- Make
- GLFW3 development libraries
- OpenGL development libraries
- CMake (for building MLX42)

### Compilation

```bash
make
```

The Makefile will:
1. Build the custom libft library
2. Build the MLX42 graphics library
3. Compile the FDF project
4. Link all libraries together

### Other Make Targets

```bash
make clean      # Remove object files
make fclean     # Remove all build artifacts
make re         # Clean and rebuild
```

## Usage

```bash
./fdf <map_file>
```

### Example

```bash
./fdf maps/test_maps/42.fdf
```

### Controls

- **ESC**: Close the program

## Map File Format

Map files (.fdf) are text-based and contain:
- Each line represents a row of points
- Each column contains: `Z_coordinate` or `Z_coordinate,color_hex`
- Z coordinates represent altitude
- Colors are specified in hexadecimal format

### Example Map File

```
0 0 0 0 0 0 0 0 0 0
0 10 10 10 0 0 20 10 10 0
0 10 20,FF0000 10 0 0 20 10 10 0
```

## Project Structure

```
42-fdf/
├── include/           # Header files
│   └── fdf.h         # Main project header
├── src/              # Source files
│   ├── fdf.c         # Main entry point
│   ├── map.c         # Map parsing
│   ├── init.c        # Initialization
│   ├── draw.c        # Rendering logic
│   ├── line.c        # Line drawing (Bresenham)
│   ├── color.c       # Color handling
│   ├── error.c       # Error handling
│   ├── utils.c       # Utility functions
│   └── ft_malloc.c   # Memory management
├── lib/              # External libraries
│   ├── libft/        # Custom C library
│   └── MLX42/        # Graphics library
└── maps/             # Test map files
```

## Key Components

### Structures

- **t_fdf**: Main program structure containing MLX window, image, map, and camera data
- **t_map**: Map data structure with grid dimensions, points, and z-coordinate range
- **t_point**: Individual point with x, y, z coordinates and color
- **t_cam**: Camera configuration for projection and scaling
- **t_isometric**: Isometric projection data for line rendering

### Core Functions

- **validate_map()**: Validates input map file format
- **init_fdf()**: Initializes FDF with map data
- **draw_map()**: Renders the complete wireframe
- **bresenham()**: Draws lines using Bresenham algorithm
- **isometric_projection()**: Converts 3D to 2D isometric coordinates

## Constants

- **WIDTH**: 1600 pixels (default window width)
- **HEIGHT**: 900 pixels (default window height)
- **ANGLE**: 30 degrees (isometric projection angle)

### Color Palette

- BLACK: `0xFF000000`
- WHITE: `0xFFFFFFFF`
- PURPLE: `0x800080FF`
- ORANGE: `0xFF8C00FF`
- PINK: `0xFF69B4FF`
- BLUE: `0x00B7EBFF`

## Dependencies

### libft
Custom C library providing:
- String manipulation
- Memory utilities
- List operations
- I/O functions
- Printf implementation
- Get Next Line

### MLX42
Graphics library for 42 projects providing:
- Window management
- Image rendering
- Event handling
- OpenGL integration

## Error Handling

The project includes comprehensive error handling for:
- Invalid arguments
- Malformed map files
- Empty maps
- Invalid color formats
- Graphics initialization failures
- Image creation issues

## Author

Created by Gabriela Angel (ga)

## License

This project is part of the 42 School curriculum.
