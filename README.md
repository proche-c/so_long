# 42cursus - so_long

## About

In this project, we'll code a simple 2D game to get familiar with the mlx library and UI in general.
## Game rules
The game we choose must follow a set of rules. The executable so_long will receive a map as the only argument, and this map will have a .ber filetype.

The file also must follow these rules:

Only P (Player), 1 (wall), 0 (empty), C (collectible), and E (exit) will be accepted characters in our map (except if you add enemies as bonus)
The map must be rectangular, i.e. all rows must have the same length
There must be at least one exit, one player, and one collectible on the map
The map must be closed, i.e. surrounded by walls
If any of these checks fail, the game must end with Error\n followed by a custom message.

The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps

## Algorithm

For the stacks with size less than 6 I wrote a simple bubble sort algorithm which.
For the stacks with size longer than 6, I used a combination of the insertion sort algorithm and the shellsort algorithm. I first move the numbers thar were already sorted from stack a to b. After that, I evaluate the number of movements requiered to place every single number that remains in the stack a to b and I choose the option that requieres less number of movements.

## How to use it  

### Cloning the repositories  
#### Mandatory
```shell
git clone https://github.com/proche-c/so_long.git
cd so_long_mandatory
make
```
#### Mandatory
```shell
git clone https://github.com/proche-c/so_long.git
cd so_long_mandatory
make
```
### Installing the MLX library

* ``Linux``

If you're not using a MacOS computer from 42, you'll need to install the libraries manually. Please refer to the [official github](https://github.com/42Paris/minilibx-linux) for more details. To install it, do the following (requires root access):

```shell
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
sudo cp mlx.h /usr/include
sudo cp libmlx.a /usr/lib
```

* ``MacOS``

To install the library, you will need to first install a package manager like homebrew (check [here](https://brew.sh/)) to then install the X11 package with ``brew install Xquartz``. After that you must extract the minilibx file called ``minilibx_opengl.tgz``. Then install it to your system with the following commands (requires sudo as well):

```shell
cd minilibx_opengl
make
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/local/lib
sudo reboot
```

