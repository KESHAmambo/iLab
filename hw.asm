.686
.model flat

includelib C:\Users\TEMP.blastfox.000\Desktop\MASM120\LIB\msvcrt.lib

gets proto c
puts proto c
strlen proto c
printf proto c

.data
msg db 100 dup(?)
msg1  db 100 dup(?)
.code

_main:
	push 	offset msg
	call 	gets
	add 	esp, 4

	push 	offset msg1
	pop	  esi
	
	
	push 	offset msg
	call 	strlen
	add 	esp, 4
	
	dec	  eax
	
	mov 	bl, msg[eax]
	cmp 	bl, 'A'
	jb  	r2
	cmp  	bl, 'Z'
	ja  	r2
	
	mov 	ecx, eax
	
compare:
	dec 	ecx
	cmp 	msg[ecx], bl
	je  	r2
	cmp 	ecx,0
	ja 	  compare
	push 	offset msg
	call 	RULE_1_4
	add 	esp, 4
	
	jmp 	ending                                                                                         
	
r2:	
	push 	offset msg
	call 	RULE_2_6
	add 	esp, 4
	jmp 	ending

	
RULE_1_4 proc
	push	ebp
	mov 	ebp, esp
	mov	  ecx, 0
	mov	  ebx, [ebp + 8]

cycle1:	
	cmp	  [ebx+ecx], 0
	je	  ret1
	cmp	  [ebx+ecx], 'a'
	jb 	  exchange
	cmp	  [ebx+ecx], 'z'
	ja   	exchange
	sub	  [ebx+ecx], 32
	inc	  ecx
	jmp	  cycle1
	
	
exchange:
	inc	  ecx
	jmp	  cycle1
	
ret1:
	RULE_1_4 endp
	push  offset msg
	call 	puts
	add   esp, 4
	mov  	esp, ebp
	pop	  ebp
	jmp   ending

	
	
RULE_2_6	proc
	push	ebp
	mov	  ebp,esp
	mov 	edx, [ebp + 8]
	xor	  ecx, ecx 

	
	mov 	bl, [edx]
	mov 	[esi], bl
	
	mov 	al, [edx+eax]
	cmp 	bl, al
	jne 	cycle2
	dec 	eax
	
cycle2: 
	inc 	ecx
	mov 	bl, [edx+ecx]
	cmp 	bl, [esi]
	je  	cycle2 
	add 	esi, 1
	mov 	[esi], bl
	
	cmp 	ecx, eax 
	jne 	cycle2
	
	push 	offset msg1
	call	puts
	add 	esp,4
	mov	  esp,ebp
	pop 	ebp



RULE_2_6	endp
	

ending:	
	xor 	eax,eax
	ret 	0
	
end _main
