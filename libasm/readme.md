# Libasm

Assembly language library in ASM 64 bits (Intel Syntax). Compilation with nasm

### Assembly language
```An assembly language is a low-level programming language designed for a specific type of processor.```

### Calling conventions
[Calling conventions ](https://www.agner.org/optimize/calling_conventions.pdf)


## Structure 
![image](https://cs.lmu.edu/~ray/images/nasmstructure.png)

## Used Instructions
_inc_       increments by 1 a register\
_cmp_       compare to arguments seperated by a comma\
_jmp_       simple jump\
_jne/jnz_   jump if not equal: conditional jump that follows a test.\
_je/jz_     jump if equal\
_call_      call external function\
_push_      writing a value onto the stack\
_pop_       restoring value

## Used Registers
_rax_       contains the return value of the function\
_rdi_       destination   address for cmp or mov, usually input string 1\
_rsi_       source        address for cmp or mov, usually inpuy string 2\
_rcx_       loop counter\
_rdx_       loop counter 2\
_dl_        least significant byte of dx\
_byte[]_    allows character operands with a single character or strings

## Syscall
[MacOS](https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master)\
[Linux](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
