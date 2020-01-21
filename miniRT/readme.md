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
_Any other functions are forbidden and must be self-programmed_

-------------

# How to do raytracing

I used this [ressource](https://raytracing.github.io/books/RayTracingInOneWeekend.html) to get started.