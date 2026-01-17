_This project was created as part of the 42 curriculum by svaladar._

## Description

**FDF** (Fil de Fer, meaning "wireframe" in French) is a 3D wireframe renderer that creates isometric and perspective projections of landscapes from heightmap files. The project explores fundamental graphics programming concepts including line drawing algorithms, 3D transformations, projections, and event handling.

The program reads `.fdf` map files containing elevation data and renders them as interactive 3D wireframes using the MiniLibX graphics library. Users can manipulate the visualization in real-time through rotation, translation, zoom, and projection changes.

### Key Features

- **Multiple Projection Modes**: Isometric, perspective, and top-down views
- **Interactive Controls**: Real-time rotation on all three axes (X, Y, Z)
- **Dynamic Transformations**: Zoom, pan, and altitude scaling
- **Color Gradients**: Automatic color mapping based on elevation
- **Custom Colors**: Support for user-defined colors in map files
- **Optimized Rendering**: Bresenham's line algorithm for efficient pixel drawing

## Instruções

### Prerequisites

- Linux operating system (required for MiniLibX)
- X11 development libraries
- GCC compiler
- Make

### Compilation

```bash
make
```

This will compile the project and generate the `fdf` executable.

### Execution

```bash
./fdf <map_file.fdf>
```

**Example:**
```bash
./fdf maps/42.fdf
```

### Map File Format

Map files (`.fdf`) consist of rows of space-separated integers representing elevation:

```
0  0  0  0  0
0 10 10 10  0
0 10 20 10  0
0 10 10 10  0
0  0  0  0  0
```

Optional hexadecimal colors can be specified after a comma:
```
0,0xFF0000  0,0x00FF00  0,0x0000FF
```

### Controls

**View Manipulation:**
- **Arrow Keys**: Pan the view (translation)
- **Mouse Scroll / +/-**: Zoom in/out
- **Z/X**: Decrease/increase altitude scaling

**Rotation:**
- **W/S**: Rotate around X-axis
- **Q/E**: Rotate around Y-axis
- **A/D**: Rotate around Z-axis

**Projection Modes:**
- **I**: Isometric projection
- **P**: Perspective projection
- **O**: Top-down view

**Other:**
- **SPACE**: Toggle color palette
- **R**: Reset to default view
- **ESC**: Exit program

### Cleaning

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile everything
```

## Technical Concepts Implemented

### 1. Bresenham's Algorithm
Efficient implementation for line drawing using only integer arithmetic, avoiding costly floating-point operations.

### 2. 3D Transformations
- **Rotation**: Use of rotation matrices for all three axes
- **Scale**: Proportional adjustment of coordinates
- **Translation**: Object movement in space

### 3. Projections
- **Isometric**: Parallel projection maintaining 30° angles
- **Perspective**: Simulates depth with Z-division
- **Top-down**: Orthogonal top view

### 4. Color Interpolation
Smooth gradient between colors using RGB linear interpolation.

### 5. Memory Management
Careful allocation and deallocation of complex structures to avoid memory leaks.

## Resources

### Graphics Programming

- [Bresenham's Line Algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) - Efficient rasterization technique
- [Isometric Projection](https://en.wikipedia.org/wiki/Isometric_projection) - Mathematical foundation for isometric view
- [3D Rotation Matrices](https://en.wikipedia.org/wiki/Rotation_matrix) - Theory behind rotation transformations
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - Graphics library reference

### Articles & Tutorials

- [Scratchapixel - Computer Graphics](https://www.scratchapixel.com/) - Comprehensive graphics programming resource
- [Line Drawing on a Grid](https://www.redblobgames.com/grids/line-drawing.html) - Interactive visualization of line algorithms
- [3D Projection](https://www.scratchapixel.com/lessons/3d-basic-rendering/computing-pixel-coordinates-of-3d-point/mathematics-computing-2d-coordinates-of-3d-points.html) - Detailed explanation of perspective projection
- [Linear Algebra Tutorial](https://www.khanacademy.org/math/linear-algebra) - Khan Academy

### AI Usage

AI assistance (Claude) was used for the following tasks:

1. **Code Documentation**: Generation of comprehensive inline comments explaining algorithms and data structures throughout the codebase
2. **README Creation**: Structuring and formatting this README file based on project requirements
3. **Algorithm Explanation**: Clarification of mathematical concepts behind rotation matrices and projection transformations
4. **Debugging Support**: Assistance in identifying edge cases in coordinate validation and memory management
5. **Translation and Localization**: Help creating English versions of comments and documentation

**Note**: All core algorithms (Bresenham's algorithm, rotation matrices, color interpolation, file parsing) were implemented manually. AI was used solely for documentation, explanation, and organizational purposes, not for generating functional code logic.
