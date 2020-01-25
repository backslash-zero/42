# MiniRT

MiniRT is an introduction to raytracing.
The goal is too use the raytracing techniauqe to represent a *scene*, seen from a specific angle with a *camera*, *lights* and with simple geometric shapes:
* plane
* sphere
* cylindre
* square
* triangle

The program should be able to apply transformations to all objects in the scene, save a picture of the scene as a BMP file if the _-save_ flag is on.

> The function must conform to [42's norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf).  
>The function cannot leak. All errors must be handled carefully. In no way can the function quit in an unexpected manner (Segmentation fault, bus error, double free, etc).

## Libraries & authorized functions

* open, read, write, malloc, free, perror, strerror, exit
* [math lib](https://linux.die.net/man/3/math) functions
* 42's [MinilibX](https://github.com/pbondoer/MinilibX/blob/master/README.md) functions.

_Any other functions are forbidden and must be self-programmed._

-------------

# How to do raytracing

I used [this ressource](https://raytracing.github.io/books/RayTracingInOneWeekend.html) & [this great book](https://www.gabrielgambetta.com/computer-graphics-from-scratch/introduction.html) to get started.

### Camera Position
Our camera will be set at the origin (0, 0, 0).
```
camera_pos_x = 0;
camera_pos_y = 0;
camera_pos_z = 0;
```
With a fixed orientation:
```
camera_rot_x = 0;
camera_rot_y = 0;
camera_rot_z = 0;
```

### The Viewport
Our viewport is the frame through which are rays are being casted, from the camera(at the origin) and the objects. The viewport is what we are rendering inside of our window. Therefore:
```
# Rx and Ry are being parsed with our scene.rt
VIEWPORT_WIDTH = Rx;
VIEWPORT_HEIGHT = Ry;
```
Our viewport is aligned to the x and y axis, but at a certain distance `d` from the camera. The size of the viewport and this distance create and angle called `FOV`(Field of View) which should generally be set around 60°.
```
VIEWPORT_WIDTH = VIEWPORT_HEIGHT = d
```
![image](https://www.gabrielgambetta.com/computer-graphics-from-scratch/images/03-basic-raytracer.png)

### Centering things on the canvas
We need to center stuff because we want to use a more "human-friendly" matrix with point 0,0 is in the center of the canvas.
```
x = (WINDOW_WIDTH / 2) + x;
y = (WINDOW_HEIGHT / 2) - y;
```

### Colors
We are using [bitwise operators](https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm) to translate ar RGB colors in an `int` format.

--------------

# Development flow

- [ ] Find some similar project and study the code structure.
- [ ] Structure files & directories according to step 1:
	* Makefiles
	* Headers
	* Libraries:
		* [Minilibx](https://github.com/pbondoer/MinilibX) + cmd: _man mlx_
		* [Libft](https://github.com/backslash-zero/42/tree/master/Libft)
		* [Get Next Line](https://github.com/backslash-zero/42/commit/2950a77a9cbf4cefd31b1b14fec3e820db11b5e5)
	_This is allows us to get working and starting testing our code right away. It also save times reoganizing_
- [ ] Setup basic parsing for our scene
	- [ ] Window 

--------------

# MinilibX

## Initialise MinilibX
`man mlx`

MiniLibX - Simple Graphical Interface Library for students
```
#include <mlx.h>
# mlx_init returns a non-null pointer returned as a connection identifier
mlx_init ();
```

## Manage windows
`man mlx_new_window`

#### mlx_new_window
*void *mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );*
Creates a new window

#### mlx_clear_window
*int mlx_clear_window ( void *mlx_ptr, void *win_ptr )*
Clear a window

#### mlx_destroy_window
*int mlx_destroy_window ( void *mlx_ptr, void *win_ptr );*
Destroys a window

## draw inside window
`man mlx_pixel_put`

#### mlx_pixel_put
*int mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );*
Draws a defined pixel in the window win_ptr using the ( x , y );

The color should be written in this format `0xff5d6c` but is given in an RGB format. 
[This article](https://timseverien.github.io/binary-cheatsheet/) helps with conversion.

## manipulate images
`man mlx_new_image`


## handle keyboard or mouse events
`man mlx_loop`


## Compilation 

@42 the MinilibX is already installed and you can run you program with the command below:
```
gcc -Wall -Wextra -Werror -fsanitize=address -I ./incs/ /usr/local/lib/libmlx.a  -framework OpenGL -framework AppKit ./srcs/main.o -o miniRT
```