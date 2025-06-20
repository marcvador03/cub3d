**Purpose**

This is the second 42 School project dealing with graphics, this time in 3D. Purpose is to understand how 3D drawings were initially developed, using Raycasting as for the original game Wolfenstein3D.

*This was a group project, well executed with Milosz! Check his Github here: https://github.com/mpietrza*

**Installation**

the library compiles with gcc or clang, using "cc" alias command.
In your terminal run "make" in the main directory, which compiles all files and creates a program named cub3D.
"make bonus" compiles the game with a few features we added later.
launch in your terminal "./cub3D" with one argument containing the path to a valid map. Few test maps are provided within maps directory.

"make clean" removes object files created.
"make fclean" removes object files and the program.
"make re" does a "make fclean" followed by a "make" to regenerate all files.

**Dependencies**

- This project uses the MLX Codam graphic library to draw window and pictures (https://github.com/codam-coding-college/MLX42.git). The MLX library from Mar'24 is already shipped with this project, so no need to update it.
However to compile with MLX you need to ensure you have installed GLFW and CMake on your computer. MLX Codam describes steps to follow here:https://github.com/codam-coding-college/MLX42?tab=readme-ov-file#for-linux.

- My own library "Libft" which was developed as part of the school to mimic C standard functions is shipped with this project. We are restricted by the school in the external functions we can use for each project, but allowed to use our own functions and library such as Libft.

*Tested on Linux Debian Trixie and Ubuntu*

**Additional information**

Requirements for the project:
- ability to ingest and check 2D maps that are used to draw a 3D environment
- have different textures applied to north/south/east/west walls. Textures paths are provided in the map file (.ber extension).
- move within the map with keyboard
- in the bonus part, we also added wall collisions and ability to move with the mouse.

*For C Projects, 42 School imposes a norm to follow strictly. Amongst many things, we are restricted to write no more than 25 lines per function, and 5 functions per file. I really do love norms, but just mentioning this to explain why sometimes we split functions and multiply files :)*
