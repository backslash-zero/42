# Libasm

Assembly language library in ASM 64 bits (Intel Syntax). Compilation with nasm

### Assembly language

```An assembly language is a low-level programming language designed for a specific type of processor.```

### Calling conventions

[Calling convetions ](https://www.agner.org/optimize/calling_conventions.pdf)


## Structure 
[image](https://cs.lmu.edu/~ray/images/nasmstructure.png)

## Instructions

_inc_ increments by 1 a register
_cmp_
_jmp_ jump 
_jne_ conditional jump that follows a test. 

## Registers

_RAX_ contains the return value of the function
_RSI_ source        address for cmp or mov
_RDI_ destination   address for cmp or mov