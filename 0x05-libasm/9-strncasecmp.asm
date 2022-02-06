BITS 64
	global asm_strncasecmp
	section .text


asm_strncasecmp:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     QWORD [rbp-32], rsi
        mov     QWORD [rbp-40], rdx
        mov     QWORD [rbp-8], 0
        mov     DWORD [rbp-12], 0
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
        mov     BYTE [rbp-13], al
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
        mov     BYTE [rbp-14], al
        movsx   eax, BYTE [rbp-13]
        movsx   edx, BYTE [rbp-14]
        sub     eax, edx
        mov     DWORD [rbp-12], eax
        add     QWORD [rbp-24], 1
        add     QWORD [rbp-32], 1
        add     QWORD [rbp-8], 1
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
        cmp     DWORD [rbp-12], 0
        jne     .L8
        mov     rax, QWORD [rbp-8]
        cmp     rax, QWORD [rbp-40]
        jb      .L9
.L8:
        mov     eax, DWORD [rbp-12]
        pop     rbp
        ret
