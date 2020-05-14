			section	.text
			global	_ft_read

_ft_read:
			mov		rax, 0x2000003 ;syscall for read is 3 on MacOs and 0 on linux
			syscall
			ret