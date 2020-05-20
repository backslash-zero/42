            global      ft_strcmp

ft_strcmp:
            mov			rax, 0          		;init register
            mov			rcx, 0          		;init loop counter
            cmp			rdi, 0          		;init dest string
            je          check_null      		;check if address pointed by dest string is NULL
            cmp			rsi, 0          		;init src string
            je          check_null      		;check if NULL
            jmp			check

check_null:
            cmp         rdi, rsi
            je          equal
            jg          greater
            jl          smaller

greater:
            mov			rax, 1
            jmp			done
smaller:
            mov			rax, -1
            jmp			done

equal:
            mov         rax, 0
            jmp         done

check_end:
			cmp			dl, 0
			je			done

increment:
            inc			rcx

check:
            mov			dl, byte[rsi + rcx]		;we use dl to store a 1 byte char 
            cmp			byte[rdi + rcx], dl
            je			check_end				;check if we've reached \0
            jg			greater
            jl			smaller

done:
			ret 