# cub3d : A Raycasting 3D Engine

A **3D raycasting engine** inspired by the classic **Wolfenstein 3D**, developed as a project at [School 42](https://www.42.fr/).  
This project implements a **first-person 3D renderer** using **raycasting** to simulate a 3D environment from a 2D map, with textures, movement, and collisions.  
Developed in collaboration with [Milosz Pietrzak](https://github.com/mpietrza).

---

## **Purpose**

The goal of this project is to understand the fundamentals of **3D graphics rendering** using raycasting, a technique used in early first-person shooter games like *Wolfenstein 3D*.  
It covers:

- **2D map parsing** (`.ber` files) to generate a 3D world.
- **Texture mapping** for walls (North, South, East, West).
- **Player movement** (keyboard controls) and **collision detection**.
- **Bonus features**: Mouse movement support and wall collisions.

---

## **Features**

### **Core Requirements**

- **Map Parsing**: Ingest and validate 2D maps (`.ber` format) to create a 3D environment.
- **Texture Rendering**: Apply different textures to walls based on their orientation (North, South, East, West).
- **Player Movement**: Navigate the map using keyboard inputs (`WASD` + arrow keys).
- **Raycasting Algorithm**: Simulate 3D perspective using 2D calculations.

### **Bonus Features**

- **Wall Collisions**: Prevent the player from moving through walls.
- **Mouse Movement**: Look around and move using the mouse (bonus mode only).

---

## **Technologies & Requirements**

- **Language**: C (C99 standard).
- **Compiler**: `gcc` or `clang` (tested with `cc` alias).
- **Dependencies**:
  - **[MLX42](https://github.com/codam-coding-college/MLX42)**: Codam’s graphic library for window and image rendering (included in the repo).
    - Requires **GLFW** and **CMake** for compilation. Follow [MLX42 installation steps](https://github.com/codam-coding-college/MLX42?tab=readme-ov-file#for-linux) if not already set up.
  - **Libft**: Custom library (included) for standard C function replacements (developed at 42).
- **OS**: Tested on **Linux Debian Trixie** and **Ubuntu**.

---

## **Installation & Usage**

### 1. **Clone the Repository**

```bash
git clone https://github.com/marcvador03/cub3d.git
cd cub3d
```

### 2. **Install Dependencies**

```bash
# Debian/Ubuntu
sudo apt-get install cmake libglfw3-dev libx11-dev libxext-dev
```

### 3. **Compile the Project**

```bash
make          # Compiles the mandatory part (output: ./cub3D)
make bonus    # Compiles with bonus features (output: ./cub3D_bonus)
make clean    # Removes object files
make fclean   # Removes object files + executables
make re       # Full clean + recompile
```

### 4. **Run cub3d**

```bash
./cub3D maps/valid_map.ber
```

- Replace `valid_map.ber` with the path to a valid map file (examples provided in the `maps/` directory).

---

## **Project Structure**

```
cub3d/
├── include/          # Header files
├── libft/            # Custom library (42's Libft)
├── mlx42/            # MLX42 graphic library (included)
├── maps/             # Test maps (`.ber` files)
├── textures/         # Wall textures
├── src/              # Source files
│   ├── main/         # Initialization, game loop, and error handling
│   ├── parsing/      # Map parsing and validation
│   ├── rendering/    # Raycasting and 3D rendering logic
│   ├── movement/     # Player movement and collision detection
│   └── utils/        # Utility functions (memory, math, etc.)
├── Makefile          # Build configuration
└── README.md         # Project documentation
```

---

## **Map File Format (`.ber`)**

Your map file must follow these rules:

- **File Extension**: `.ber`.
- **Structure**:
  - The map must be **rectangular** (all lines must have the same length).
  - **Walls**: Represented by `1`.
  - **Empty Spaces**: Represented by `0`.
  - **Player Start Position**: Represented by `N`, `S`, `E`, or `W` (indicating the player’s initial orientation).
  - **Textures**: Paths to texture files for North, South, East, West walls, and sprites must be specified at the top of the file.
- **Example**:
  ```
  NO ./textures/north_texture.png
  SO ./textures/south_texture.png
  WE ./textures/west_texture.png
  EA ./textures/east_texture.png

  111111111111
  10000000001
  10010000001
  10000000001
  111111111111
  ```
- **Valid Maps**: Pre-made test maps are available in the `maps/` directory.

---

## **Controls**


| Key       | Action                   |
| --------- | ------------------------ |
| `W`       | Move forward             |
| `A`       | Move left                |
| `S`       | Move backward            |
| `D`       | Move right               |
| `←` / `→` | Rotate left/right        |
| `ESC`     | Close the window         |
| **Mouse** | Look around (bonus only) |


---

##  **42 Norminette Compliance**

- **25 lines max per function**.
- **5 functions max per file**.
- **No external libraries** (except MLX42, GLFW, and standard C libraries).
- **Strict error handling** (memory leaks, file descriptor leaks, invalid maps).

---

##  **Testing**

- **Robustness**: Passed all evaluations at 42, including edge cases (invalid maps, missing textures, etc.).
- **Leak Checks**: Verified with `valgrind` (memory and file descriptors).
- **Performance**: Optimized for smooth rendering on standard hardware.

---

##  **Resources**

- [Raycasting Tutorial (Lode's Computer Graphics)](https://lodev.org/cgtutor/raycasting.html)
- [MLX42 Documentation](https://github.com/codam-coding-college/MLX42)
- [42 Norminette](https://github.com/42School/norminette)
- [Wolfenstein 3D (Inspiration)](https://en.wikipedia.org/wiki/Wolfenstein_3D)

---

## **License**

This project is open-source and available under the [MIT License](LICENSE).

---

##  **Acknowledgments**

- Developed as part of the **42 School** curriculum.
- Special thanks to [Milosz Pietrzak](https://github.com/mpietrza) for collaboration and testing.
- Inspired by **Wolfenstein 3D** and the legacy of early 3D graphics.
- AI was NOT used for development, just to generate this README
