
global      ft_strcmp

ft_strcmp:
            mov			rax, 0
            mov			rcx, 0
            cmp			rdi, 0
            je          check_null
            cmp			rsi, 0
            je          check_null
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
            mov			dl, byte[rdi + rcx]
            cmp			byte[rsi + rcx], dl
            je			check_end
            jl			greater
            jg			smaller

done:
			ret 