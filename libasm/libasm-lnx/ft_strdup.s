			section	.text
			global	ft_strdup
			extern	malloc

; delete RDX, RCX, RAX and everything that malloc destroy

ft_strdup:									; rdi = src
			cmp		rdi, 0
			jz		error					; src is NULL
			xor		rcx, rcx
			jmp		compare
increment:
			inc		rcx
compare:
			cmp		BYTE [rdi + rcx], 0
			jne		increment
dup_malloc:
			inc		rcx
			push	rdi
			mov		rdi, rcx
			call	_malloc					
			pop		rdi
			cmp		rax, 0
			jz		error
			xor		rcx, rcx
			jmp		copy

increment_cpy:
			inc		rcx
copy:
			mov		dl, byte [rdi + rcx]
			mov		byte [rax + rcx], dl
			cmp		dl, 0
			jnz		increment_cpy
			jmp		return
error:
			xor		rax, rax
return:
            ret