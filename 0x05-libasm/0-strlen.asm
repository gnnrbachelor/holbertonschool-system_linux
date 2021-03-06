BITS 64

	global asm_strlen
	extern main
	SECTION .text

asm_strlen:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     DWORD [rbp-4], 0
        jmp     .L2
.L3:
        add     DWORD [rbp-4], 1
        add     QWORD [rbp-24], 1
.L2:
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        test    al, al
        jne     .L3
        mov     eax, DWORD [rbp-4]
        pop     rbp
        ret
