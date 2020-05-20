			extern __errno_location
			global	ft_read

ft_read:
			mov			rax, 0 					;syscall for read is 3 on MacOs and 0 on linux
			syscall
			cmp			rax, 0
			jl			error					;check if syscall returned an error message
			ret								;if read is ≥ 0 then return number of bytes read

error:
			neg			rax
			mov			rdx, rax
			call		__errno_location
			mov			[rax], rdx
			mov			rax, -1 				;return value is -1
			ret