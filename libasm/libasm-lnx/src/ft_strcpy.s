	        section     .text
    	    global      ft_strcpy

ft_strcpy:
            mov         rcx, 0                  ;init loop counter
            cmp         rsi, 0                  ;check if source string points to NULL
            je          done
            jmp         copy

increment:
            inc         rcx

copy:
            mov         dl, byte[rsi + rcx]
            mov         byte[rdi + rcx], dl
            cmp         dl, 0                   ;check if byte is \0
            jne         increment

done:
            mov         rax, rdi
			ret