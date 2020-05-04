# Libasm

Assembly language library in ASM 64 bits (Intel Syntax). Compilation with nasm

### Assembly language

```An assembly language is a low-level programming language designed for a specific type of processor.```

### Calling conventions

[Calling convetions ](https://www.agner.org/optimize/calling_conventions.pdf)


## Structure 
![image](https://cs.lmu.edu/~ray/images/nasmstructure.png)

## Used Instructions

_inc_ increments by 1 a register
_cmp_ compare to arguments seperated by a comma
_jmp_ simple jump
_jne_ jump if not equal: conditional jump that follows a test. 

## Used Registers

_rax_ contains the return value of the function
_rsi_ source        address for cmp or mov
_rdi_ destination   address for cmp or mov
_rcx_ loop counter
_rdx_ loop counter 2