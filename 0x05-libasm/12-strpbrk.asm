BITS 64
	global asm_strpbrk
	SECTION .text


asm_strpbrk:
        push    rbp
        mov     rbp, rsp
        mov     QWORD  [rbp-24], rdi
        mov     QWORD  [rbp-32], rsi
        mov     QWORD  [rbp-8], 0
        jmp     .L2
.L8:
        mov     rax, QWORD  [rbp-32]
        mov     QWORD  [rbp-8], rax
        jmp     .L3
.L5:
        add     QWORD  [rbp-8], 1
.L3:
        mov     rax, QWORD  [rbp-8]
        movzx   eax, BYTE  [rax]
        test    al, al
        je      .L4
        mov     rax, QWORD  [rbp-8]
        movzx   edx, BYTE  [rax]
        mov     rax, QWORD  [rbp-24]
        movzx   eax, BYTE  [rax]
        cmp     dl, al
        jne     .L5
.L4:
        mov     rax, QWORD  [rbp-8]
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L11
        add     QWORD  [rbp-24], 1
.L2:
        mov     rax, QWORD  [rbp-24]
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L8
        jmp     .L7
.L11:
        nop
.L7:
        cmp     QWORD  [rbp-8], 0
        je      .L9
        mov     rax, QWORD  [rbp-8]
        movzx   eax, BYTE  [rax]
        test    al, al
        je      .L9
        mov     rax, QWORD  [rbp-24]
        jmp     .L10
.L9:
        mov     eax, 0
.L10:
        pop     rbp
        ret
