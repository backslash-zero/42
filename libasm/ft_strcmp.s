	        section     .text
    	    global      _ft_strcmp

_ft_strcmp:
            mov			rax, 0
            mov			rcx, 0
            cmp			rdi, 0
            cmp			rsi, 0
            jmp			check

greater:
            mov			rax, 1
            jmp			done
smaller:
            mov			rax, -1
            jmp			done

check_null:
			cmp			dl, 0
			je			done

increment:
            inc			rcx

check:
            mov			dl, byte[rdi + rcx]
            cmp			byte[rsi + rcx], dl
            je			check_null
            jl			greater
            jg			smaller

done:
			ret 