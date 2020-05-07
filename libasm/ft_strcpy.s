	        section     .text
    	    global      _ft_strcpy

_ft_strcpy:
            mov         rcx, 0
            cmp         rsi, 0
            je          done
            jmp         copy

increment:
            inc         rcx

copy:
            mov         dl, byte[rsi + rcx]
            mov         byte[rdi + rcx], dl
            cmp         dl, 0
            jne         increment

done:
            mov         rax, rdi
			ret