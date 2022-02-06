BITS 64
	global asm_strspn
	section .text

asm_strspn:
        push    rbp
        mov     rbp, rsp
        mov     QWORD  [rbp-24], rdi
        mov     QWORD  [rbp-32], rsi
        mov     QWORD  [rbp-8], 0
        mov     QWORD  [rbp-16], 0
        jmp     .L2
.L8:
        mov     rax, QWORD  [rbp-32]
        mov     QWORD  [rbp-16], rax
        jmp     .L3
.L5:
        add     QWORD  [rbp-16], 1
.L3:
        mov     rax, QWORD [rbp-16]
        movzx   eax, BYTE [rax]
        test    al, al
        je      .L4
        mov     rax, QWORD [rbp-16]
        movzx   edx, BYTE  [rax]
        mov     rax, QWORD  [rbp-24]
        movzx   eax, BYTE  [rax]
        cmp     dl, al
        jne     .L5
.L4:
        mov     rax, QWORD  [rbp-16]
        movzx   eax, BYTE  [rax]
        test    al, al
        je      .L10
        add     QWORD  [rbp-8], 1
        add     QWORD  [rbp-24], 1
.L2:
        mov     rax, QWORD  [rbp-24]
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L8
        jmp     .L7
.L10:
        nop
.L7:
        mov     rax, QWORD  [rbp-8]
        pop     rbp
        ret
