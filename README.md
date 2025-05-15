# C_Fract_ol
## Interactive fractal renderer (Mandelbrot, Julia &amp; Multibrot sets)

### Introduction
Fract'ol is a computer graphics project focused on rendering beautiful mathematical fractals. The program should allow users to explore infinitely complex patterns by visualizing different fractal sets with interactive zoom capabilities and colorful rendering. This project demonstrates fundamental principles of computer graphics, complex number mathematics, and event-driven programming.

### Project Purpose & Objectives
    1. Gain proficiency with the MiniLibX (X11 simplified analog) graphics library
    2. Apply complex number mathematics in a practical application
    3. Implement efficient rendering algorithms and optimization techniques
    4. Develop skills in event handling and user interaction
    5. Create visually appealing graphical output with color management

### Key Concepts & Features
Fractals are infinitely complex patterns that are self-similar across different scales. The project focuses on implementing algorithms to render these mathematical objects by:

    1. Calculating complex number iterations using the specific formula for each fractal type
    2. Complex number mathematics (real and imaginary components)
    3. Determining pixel colors based on iteration counts and escape values
    4. Implementing precision zoom functionality to explore fractal details

### Core Functionality
    1. Rendering of multiple fractal types (Mandelbrot and Julia sets required, Multibrot is a bonus)
    2. Near-infinite zoom capability with the mouse wheel
    3. Double-precision floating-point calculations for deep zoom accuracy
    4. Parameter customization for Julia sets through command-line arguments
    5. Psychedelic color mapping to visualize fractal depth
    6. Clean window management and event handling for user interaction

### Libraries & Technologies
    1. MiniLibX: A simplified X11 programming API providing basic graphical functions
    2. Math Library: Used for complex number operations and calculations
    3. Custom Libft Library: A self-implemented library of standard functions

### How to test?
1. Clone the repository
2. Clone the Libft repository https://github.com/gtretiak/C_libft
3. Compile with make command
4. Run the program with a fractal type
# For Mandelbrot set
./fractol mandelbrot

# For Julia set with parameters
./fractol julia -0.7 0.27

### Usage Examples
./fractol [fractal_type] [optional_parameters]
#### Available fractal types:
mandelbrot - The classic Mandelbrot set
julia [real] [imaginary] - Julia set with customizable complex constant
julia [imaginary] - Julia set with only the imaginary part customized (real set to 0); alters symmetry and complexity.
BONUS:
julia Golden_ratio - Julia set using the golden ratio as part of the complex constant c; often results in naturally aesthetic structures.
julia Golden_ratio2 - Julia set variation with a modified golden ratio value, offering a different visual twist.
julia Dance - An animated Julia variation with dynamic complex constant changes, producing a "dancing" visual effect.
Multibrot - realtive to mandelbrot, but with variety of shapes depending on the exponent used

### Controls
1. Mouse Wheel: Zoom in and out (with centering on the current mouse position and color palette shifting)
2. Arrow Keys: Move the view
3. + and - keys - Increasing/decreasing complexity (depth)
4. P Key: Shift exponent
5. ESC, q Key: Exit the program

### Advanced Implementation Details
1. Calculation Optimization: Early escape detection for non-belonging points
2. Memory Management: Efficiently storing and updating pixel data
3. Render Chunking: Dividing the screen into sections for potential multi-threading

### Mathematical Foundation
The core of fractal rendering relies on iterative functions:
1. Mandelbrot Set: z = z² + c, where z starts at 0 and c is the pixel coordinate
2. Julia Set: z = z² + c, where z is the pixel coordinate and c is a constant
3. Julia Set with only imaginary part: z = z² + c, with c having only an imaginary component, creating symmetric and fluid visuals
4. Julia Golden_ratio: z = z² + c, with c incorporating the golden ratio (φ ≈ 1.618), producing aesthetically pleasing spirals
5. Julia Golden_ratio2: A variation using another expression involving the golden ratio, emphasizing denser spiraling patterns
6. Julia Dance: A dynamic variant where c changes over time or space, creating animated or rhythmically shifting fractals
7. Multibrot: z = zⁿ + c, where the exponent n > 2 (e.g., 3, 4…), generalizing Mandelbrot with diverse and exotic shapes depending on n

### Real-World Applications
1. Scientific Visualization Software: The techniques used for rendering fractals are directly applicable to visualizing scientific data, such as weather patterns, fluid dynamics, or biological systems. Understanding how to map complex data to visual representations is a transferable skill in scientific computing fields.
2. Game Development: The graphics programming, optimization techniques, and event handling implemented in this project are foundational skills for game development.
3. Medical Imaging: The precision zooming and color mapping techniques have parallels in medical imaging software, where visualizing detailed scans (Magnetic Resonance Imaging, Computed Tomography) requires similar technical approaches to highlight different data aspects through color.
4. Financial Analysis Tools: The mathematical understanding of complex systems and visualization of data patterns is valuable in financial technology, particularly for visualizing market trends and complex mathematical models.
5. Geographic Information Systems (GIS): The implementation of zooming, and rendering large datasets efficiently applies directly to mapping applications and geographical visualization tools used in urban planning, logistics, and environmental monitoring.

### Conclusion
The Fract-ol project presents a fascinating journey into computer graphics programming, mathematical implementation, and user interface design. Creating an interactive application that visualizes complex mathematical concepts enhances understanding of what it takes to translate abstract theory into practical, visually engaging software.
