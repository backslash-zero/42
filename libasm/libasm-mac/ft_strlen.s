	        section     .text
    	    global      _ft_strlen

_ft_strlen:
			mov			rax, 0
			jmp			compare

increment:
			inc			rax

compare:
			cmp			byte [rdi + rax], 0
			jne			increment

done:
			ret