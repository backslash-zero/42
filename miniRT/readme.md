# MiniRT

![miniRT_Cele](https://github.com/backslash-zero/42/miniRT/save.png)

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

I used [this ressource](https://raytracing.github.io/books/RayTracingInOneWeekend.html), [this one](https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/definition-ray) & [this great book](https://www.gabrielgambetta.com/computer-graphics-from-scratch/introduction.html) to get started.

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

## Compilation 

@42 the MinilibX is already installed and you can run you program with the command below:

```
gcc -Wall -Wextra -Werror -fsanitize=address -I ./incs/ /usr/local/lib/libmlx.a  -framework OpenGL -framework AppKit ./srcs/main.o -o miniRT
```
On linux machine we cannot use OpenGL and Appkit. The compilation looks like this:
```
-lm -lbsd -lX11 -lXext
```
