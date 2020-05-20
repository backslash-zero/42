			global	ft_strdup
			extern	malloc

ft_strdup:									; rdi = src
			cmp		rdi, 0					; check if dest string points to NULL
			je		error
			xor		rcx, rcx				; init iteration counter
			jmp		compare
increment:
			inc		rcx
compare:
			cmp		BYTE [rdi + rcx], 0		; iterate until \0
			jne		increment
dup_malloc:
			inc		rcx						; add one more iteration for \0 char
			push	rdi						; write rdi value onto the stack
			mov		rdi, rcx				; moves iteration counts into RDI to malloc "count" bytes
			call	malloc					
			pop		rdi						; restores value from the stack 
			cmp		rax, 0					; check if rax points to a new allocated string
			je		error
			xor		rcx, rcx				; init iteration counter for copy
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