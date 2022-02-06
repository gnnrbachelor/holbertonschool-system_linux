BITS 64
	global asm_memcpy
	extern main
	SECTION .text


asm_memcpy:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-40], rdi
        mov     QWORD [rbp-48], rsi
        mov     QWORD [rbp-56], rdx
        mov     rax, QWORD [rbp-40]
        mov     QWORD [rbp-16], rax
        mov     rax, QWORD [rbp-48]
        mov     QWORD [rbp-24], rax
        cmp     QWORD [rbp-16], 0
        je      .L2
        cmp     QWORD [rbp-24], 0
        jne     .L3
.L2:
        mov     rax, QWORD [rbp-40]
        jmp     .L4
.L3:
        mov     QWORD [rbp-8], 0
        jmp     .L5
.L6:
        mov     rdx, QWORD [rbp-24]
        mov     rax, QWORD [rbp-8]
        add     rax, rdx
        mov     rcx, QWORD [rbp-16]
        mov     rdx, QWORD [rbp-8]
        add     rdx, rcx
        movzx   eax, BYTE [rax]
        mov     BYTE [rdx], al
        add     QWORD [rbp-8], 1
.L5:
        mov     rax, QWORD [rbp-8]
        cmp     rax, QWORD [rbp-56]
        jb      .L6
        mov     rax, QWORD [rbp-40]
.L4:
        pop     rbp
        ret
