BITS 64

	global asm_strncmp
	extern main
	SECTION .text

asm_strncmp:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-8], rdi
        mov     QWORD [rbp-16], rsi
        mov     QWORD [rbp-24], rdx
        jmp     .L2
.L4:
        add     QWORD [rbp-8], 1
        add     QWORD [rbp-16], 1
        sub     QWORD [rbp-24], 1
.L2:
        cmp     QWORD [rbp-24], 0
        je      .L3
        mov     rax, QWORD [rbp-8]
        movzx   eax, BYTE [rax]
        test    al, al
        je      .L3
        mov     rax, QWORD [rbp-8]
        movzx   edx, BYTE [rax]
        mov     rax, QWORD [rbp-16]
        movzx   eax, BYTE [rax]
        cmp     dl, al
        je      .L4
.L3:
        cmp     QWORD [rbp-24], 0
        jne     .L5
        mov     eax, 0
        jmp     .L6
.L5:
        mov     rax, QWORD [rbp-8]
        movzx   eax, BYTE [rax]
        movzx   edx, al
        mov     rax, QWORD [rbp-16]
        movzx   eax, BYTE [rax]
        movzx   ecx, al
        mov     eax, edx
        sub     eax, ecx
.L6:
        pop     rbp
        ret
