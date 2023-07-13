### **Make it :**
  ```
make
./cub3d maps/*.cub
  ```

# Goals :
- This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.
- As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.
- To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.

With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.

# Common Instructions
We display a prompt when waiting for a new command.
### All the features we implemented :
- Use the miniLibX. Either the version that is available on the operating system, or from its sources.
- The management of the window must remain smooth: changing to another window, minimizing, etc.
- Display different wall textures that vary depending on which side the wall is facing (North, South, East, West).
- The program must be able to set the floor and ceiling colors to two different ones.
- The program displays the image in a window and respects the following rules:
    - The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
    - The W, A, S, and D keys must allow you to move the point of view through the maze.
    - Pressing ESC must close the window and quit the program cleanly.
    - Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
    - The use of images of the minilibX is strongly recommended.

Your program must take as a first argument a scene description file with the .cub
extension.

The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.

This is a simple **valid map**:
  ```
111111
100101
101001
1100N1
111111
  ```
- The map must be closed/surrounded by walls, if not the program must return an error.
- Except for the map content, each type of element can be separated by one or more empty line(s).
- Except for the map content which always has to be the last, each type of element can be set in any order in the file.
- Except for the map, each type of information from an element can be separated by one or more space(s).
- The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.

Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order such as :

North texture: Identifier: NO : path to the north texure
  ```
NO ./path_to_the_north_texture
  ```

South texture: Identifier: SO : path to the south texure
  ```
SO ./path_to_the_south_texture
  ```

West texture: Identifier: WE : path to the west texure
  ```
WE ./path_to_the_west_texture
  ```

East texture: Identifier: EA : path to the east texure
  ```
EA ./path_to_the_east_texture
  ```

- Color : 
  - Floor color: F 220,100,0 Identifier: F
  - Ceiling color: C 220,100,0 Identifier: C
  - R,G,B colors in range [0,255]: 0, 255, 255

Example of the mandatory part with a minimalist .cub scene:
  ```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
          1111111111111111111111111
          1000000000110000000000001
          1011000001110000000000001
          1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
  ```

**If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice.**
