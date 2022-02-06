BITS 64
	global asm_strcasecmp
	SECTION .text


asm_strcasecmp:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     QWORD [rbp-32], rsi
        mov     DWORD [rbp-4], 0
        jmp     .L2
.L9:
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        cmp     al, 64
        jle     .L3
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        cmp     al, 90
        jg      .L3
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        add     eax, 32
        jmp     .L4
.L3:
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
.L4:
        mov     BYTE [rbp-5], al
        mov     rax, QWORD [rbp-32]
        movzx   eax, BYTE [rax]
        cmp     al, 64
        jle     .L5
        mov     rax, QWORD [rbp-32]
        movzx   eax, BYTE [rax]
        cmp     al, 90
        jg      .L5
        mov     rax, QWORD [rbp-32]
        movzx   eax, BYTE [rax]
        add     eax, 32
        jmp     .L6
.L5:
        mov     rax, QWORD [rbp-32]
        movzx   eax, BYTE [rax]
.L6:
        mov     BYTE [rbp-6], al
        movsx   eax, BYTE [rbp-5]
        movsx   edx, BYTE [rbp-6]
        sub     eax, edx
        mov     DWORD [rbp-4], eax
        add     QWORD [rbp-24], 1
        add     QWORD [rbp-32], 1
.L2:
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        test    al, al
        jne     .L7
        mov     rax, QWORD [rbp-32]
        movzx   eax, BYTE [rax]
        test    al, al
        je      .L8
.L7:
        cmp     DWORD [rbp-4], 0
        je      .L9
.L8:
        mov     eax, DWORD [rbp-4]
        pop     rbp
        ret
