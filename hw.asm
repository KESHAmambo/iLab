.686
.model flat

global main
extern fread
extern fwrite
extern stdin
extern stdout
extern putchar
extern printf
extern strlen
extern isupper
extern toupper

%define MAX_TEXT_SIZE 100

section .text

main:

; read input into the buffer
push dword [stdin]
push MAX_TEXT_SIZE
push 1
push input
call fread
add esp, 16;

mov byte [input+eax], 0

push input
call strlen
add esp, 4
mov [input_size], eax

; prepare variables for the rule, while at it
mov dword [output_ptr], input
mov dword [output_size], eax

push dword [stdout]
push eax
push 1
push input
call fwrite
add esp, 16

push 0x0A
call putchar
add esp, 4

call dword [property_1]

mov eax, [rule_1_4]
mov ebx, [rule_2_6]
cmovnc eax, ebx;
call eax

push eax
push rule_fmt
call printf
add esp, 8

; write back the output
push dword [stdout]
push dword [output_size]
push 1
push dword [output_ptr]
call fwrite
add esp, 16

push 0x0A
call putchar
add esp, 4

normal_exit:

xor eax, eax
ret

error_exit:

mov eax, 1
ret

true_ret:

stc
ret

false_ret:

clc
ret


property_1:

mov ebx, input
add ebx, dword [input_size]
dec ebx

movzx eax, byte [ebx];
push eax
call isupper
add esp, 4
test eax, eax
jz false_ret

; check for other occurrences
mov esi, input
mov ecx, [input_size]
dec ecx
mov al, byte [ebx]
repne scasb
je false_ret

jmp true_ret


rule_1_0:

mov eax, rule_1_0_desc
ret


rule_2_0:

mov eax, rule_2_0_desc
ret


rule_1_4:

mov esi, input

.processing_loop:
xor eax, eax
lodsb

test eax, eax
jz .exit

push eax
call toupper
add esp, 4
mov byte [esi-1], al

jmp .processing_loop

.exit:
mov eax, rule_1_4_desc
ret


rule_2_6:

mov esi, input
mov edi, input
xor ebx, ebx

.processing_loop:
xor eax, eax
lodsb

test eax, eax
jz .exit

cmp eax, ebx
je .skip

stosb

.skip:
mov ebx, eax
jmp .processing_loop

.exit:
sub edi, input
mov dword [output_size], edi
mov eax, rule_2_6_desc
ret


section .bss

input_size resd 1
output_size resd 1
input resb MAX_TEXT_SIZE + 1
output resb MAX_TEXT_SIZE * 2 + 1


section .data

rule_fmt db "Rule applied: '%s'.", 0x0A, 0

rule_1_0_desc db "The property is fulfilled", 0
rule_1_4_desc db "Each lower-case letter is replaced with a corresponding upper-case letter", 0
rule_2_0_desc db "The property is NOT fulfilled", 0
rule_2_6_desc db "All characters equal to the previous one are removed", 0

output_ptr dd input
