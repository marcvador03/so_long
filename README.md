# so_long : A 2D Game with MLX

A **2D game** developed as part of the [School 42](https://www.42.fr/) curriculum, focusing on **graphics programming** using the **MLX library**.  
This project introduces the basics of **window management, pixel manipulation, image rendering, and input handling** (keyboard/mouse).  
It also includes **custom features** like sprite animations, collectible items, and enemy interactions.

---

##  **Purpose**

The goal of *so_long* is to:

- Learn how to **create a simple 2D game** from scratch.
- Understand **graphics rendering** (windows, images, sprites) using **MLX42**, a lightweight graphic library.
- Implement **game logic**, such as:
  - Map parsing and validation.
  - Player movement with collision detection.
  - Event handling (e.g., exiting the game, collecting items).
- Explore **game design** with bonus features like animations, enemies, and interactive elements.

---

##  **Features**

### **Core Requirements**

- **Map Parsing & Validation**:
  - Ingest and validate 2D maps (`.ber` format).
  - Ensure maps are **closed** (surrounded by walls).
  - Check for **one player start position**, **one exit**, and a **valid path** from start to exit.
- **Player Movement**:
  - Move the character using **keyboard inputs** (`WASD` or arrow keys).
  - **Wall collision**: Prevent movement through walls.
- **Game Events**:
  - Exit the game when the player reaches the exit tile.
  - Track and display **steps taken** (movement count).

### **Bonus Features**

- **Sprite Animations**: Smooth animations for the player and other elements.
- **Collectibles**: Chests with items to collect before exiting.
- **Enemies**: Monsters that can be **killed with arrows** or will **kill the player on contact**.
- **Custom Graphics**: Textures and sprites for a more immersive experience.

---

##  **Technologies & Requirements**

- **Language**: C (C99 standard).
- **Compiler**: `gcc` or `clang` (tested with `cc` alias).
- **Dependencies**:
  - **[MLX42](https://github.com/codam-coding-college/MLX42)**: Codam’s graphic library for window and image rendering (included in the repo).
    - Requires **GLFW** and **CMake** for compilation. Follow [MLX42 installation steps](https://github.com/codam-coding-college/MLX42?tab=readme-ov-file#for-linux) if not already set up.
  - **Libft**: Custom library (included) for standard C function replacements (developed at 42).
- **OS**: Tested on **Linux Debian Trixie** and **Ubuntu**.

---

##  **Installation & Usage**

### 1. **Clone the Repository**

```bash
git clone https://github.com/marcvador03/so_long.git
cd so_long
```

### 2. **Install Dependencies**

```bash
# Debian/Ubuntu
sudo apt-get install cmake libglfw3-dev libx11-dev libxext-dev
```

### 3. **Compile the Project**

```bash
make          # Compiles the program (output: ./so_long)
make clean    # Removes object files
make fclean   # Removes object files + executable
make re       # Full clean + recompile
```

### 4. **Run so_long**

```bash
./so_long maps/valid_map.ber
```

- Replace `valid_map.ber` with the path to a valid map file (examples provided in the `maps/` directory).

---

##  **Project Structure**

```
so_long/
├── include/          # Header files
├── libft/            # Custom library (42's Libft)
├── mlx42/            # MLX42 graphic library (included)
├── maps/             # Test maps (`.ber` files)
├── textures/         # Sprites and textures
├── src/              # Source files
│   ├── main/         # Initialization, game loop, and error handling
│   ├── parsing/      # Map parsing and validation
│   ├── rendering/    # Graphics rendering (sprites, animations)
│   ├── game/         # Game logic (movement, collisions, events)
│   └── utils/        # Utility functions (memory, file handling, etc.)
├── Makefile          # Build configuration
└── README.md         # Project documentation
```

---

##  **Map File Format (`.ber`)**

Your map file must follow these rules:

- **File Extension**: `.ber`.
- **Structure**:
  - The map must be **rectangular** (all lines must have the same length).
  - **Walls**: Represented by `1`.
  - **Empty Spaces**: Represented by `0`.
  - **Player Start Position**: Represented by `P`.
  - **Exit**: Represented by `E`.
  - **Collectibles**: Represented by `C` (chests/items).
  - **Enemies**: Represented by `M` (monsters).
- **Validation Rules**:
  - The map must be **closed** (surrounded by walls).
  - There must be **exactly one `P` (player)**, **one `E` (exit)**, and **at least one `C` (collectible)**.
  - A **valid path** must exist from the player to the exit and all collectibles.
- **Example**:
  ```
  1111111
  1P00C01
  101M101
  100E001
  1111111
  ```
- **Valid Maps**: Pre-made test maps are available in the `maps/` directory.

---

##  **Controls**


| Key       | Action                       |
| --------- | ---------------------------- |
| `W` / `↑` | Move forward                 |
| `A` / `←` | Move left                    |
| `S` / `↓` | Move backward                |
| `D` / `→` | Move right                   |
| `ESC`     | Close the window             |
| **Mouse** | Aim and shoot arrows (bonus) |


---

## **42 Norminette Compliance**

- **25 lines max per function**.
- **5 functions max per file**.
- **No external libraries** (except MLX42, GLFW, and standard C libraries).
- **Strict error handling** (memory leaks, file descriptor leaks, invalid maps).

> *Note*: Some minor leaks may originate from **X11/GLFW libraries** (used by MLX42). These are outside the scope of the project.

---

##  **Testing**

- **Robustness**: Passed all evaluations at 42, including edge cases (invalid maps, missing collectibles, etc.).
- **Leak Checks**: Verified with `valgrind` (excluding X11/GLFW-related warnings).
- **Performance**: Optimized for smooth gameplay on standard hardware.

---

##  **Resources**

- [MLX42 Documentation](https://github.com/codam-coding-college/MLX42)
- [42 Norminette](https://github.com/42School/norminette)
- [2D Game Development Tutorials](https://gamedev.net/tutorials/_/technical/game-programming/)
- [Simple Raycasting for 2D Games](https://lodev.org/cgtutor/raycasting.html) (for inspiration)

---

##  **License**

This project is open-source and available under the [MIT License](LICENSE).

---

##  **Acknowledgments**

- Developed as part of the **42 School** curriculum.
- Inspired by classic 2D games and the retro gaming era.
- No AI was used during development, just to generate this README
