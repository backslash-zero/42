# ft_printf

### Goal
  
Recode `printf` with [identical behaviour as the original](https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019).  

### External allowed functions

`malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`

All other functions must be self programmed.
  
The project is complicated as the number of parameters is indefinite. We use variadic arguments in this case.  
  
ft_printf must achieve the following mandatory requirements:  
  
* Manage the following conversions: `s`, `p`, `d`, `i`, `u`, `x`, `X`& `c`
* Manage `%%`
* Manage the flags `#`, `0`, `-`, `+`
* Manage the minimum field-width
* Manage the precision `.`
  
The function must conform to [42's norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf).  
The function cannot leak. All errors must be handled carefully. In no way can the function quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  

***
### Using the project
To compile, run `make`. This will compile **libftprintf.a**. To use, include `ft_printf.h` (located inside includes directory) and use just like `printf`:
```c
#include "ft_printf.h"

int				main(void)
{
	ft_printf("%s, %s!\n", "Hello", "world");
	return (0);
}
```
Then compile with a program:
```console
gcc -Wall -Werror -Wextra main.c libftprintf.a -I includes
```
