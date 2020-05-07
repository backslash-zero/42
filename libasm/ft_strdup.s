	        section     .text
    	    global      _ft_strdup
            extern      _malloc

_ft_strdup:
            cmp         rdi, 0
            jne         error
            xor         rcx, rcx

increment:
            inc         rcx

start:
            cmp         byte[rdi + rcx], 0
            jne         increment

malloc_new:
            inc         rcx                     ;this adds one more char for \0

copy:
            mov         dl, byte[rsi + rcx]
            mov         byte[rdi + rcx], dl
            cmp         dl, 0
            jne         increment

error:
            xor         rax, rax

done:
			ret