BITS 64

	global asm_strcmp
	extern main
	SECTION .text

asm_strcmp:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-8], rdi
        mov     QWORD [rbp-16], rsi
        jmp     .L2
.L4:
        add     QWORD [rbp-8], 1
        add     QWORD [rbp-16], 1
.L2:
        mov     rax, QWORD [rbp-8]
        movzx   eax, BYTE [rax]
        test    al, al
        je      .L3
        mov     rax, QWORD [rbp-16]
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
        mov     rax, QWORD [rbp-8]
        movzx   edx, BYTE [rax]
        mov     rax, QWORD [rbp-16]
        movzx   eax, BYTE [rax]
        cmp     dl, al
        jle     .L5
        mov     eax, 1
        jmp     .L6
.L5:
        mov     rax, QWORD [rbp-8]
        movzx   edx, BYTE [rax]
        mov     rax, QWORD [rbp-16]
        movzx   eax, BYTE [rax]
        cmp     dl, al
        jge     .L7
        mov     eax, -1
        jmp     .L6
.L7:
        mov     eax, 0
.L6:
        pop     rbp
        ret
