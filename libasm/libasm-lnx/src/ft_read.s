			section	.text
			global	ft_read

ft_read:
			mov		rax, 0 ;syscall for read is 3 on MacOs and 0 on linux
			syscall
			ret