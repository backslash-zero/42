            section	.text
			global	_ft_write

_ft_write:
            mov         rax, 0x2000004 ;syscall for write is 4 on MacOs and 1 on linux
            syscall
            ret