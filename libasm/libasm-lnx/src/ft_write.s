            extern __errno_location
			global	ft_write

ft_write:
            mov     rax, 1                  ;syscall for write is 4 on MacOs and 1 on linux
            syscall
            cmp     rax, 0
            jl      error
            ret

error:
			neg		rax
			mov		rdx, rax
			call	__errno_location
			mov		[rax], rdx
			mov		rax, -1 				;return value is -1
			ret