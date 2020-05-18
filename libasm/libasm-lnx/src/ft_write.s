            section	.text
			global	ft_write

ft_write:
            mov         rax, 1 ;syscall for write is 4 on MacOs and 1 on linux
            syscall
            ret