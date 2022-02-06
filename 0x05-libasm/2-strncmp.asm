BITS 64

	global asm_strncmp
	extern main
	SECTION .text

asm_strncmp:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     QWORD [rbp-32], rsi
        mov     QWORD [rbp-40], rdx
        mov     QWORD [rbp-8], 0
        mov     DWORD [rbp-12], 0
        jmp     .L2
.L4:
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        movsx   edx, al
        mov     rax, QWORD [rbp-32]
        movzx   eax, BYTE [rax]
        movsx   ecx, al
        mov     eax, edx
        sub     eax, ecx
        mov     DWORD [rbp-12], eax
        add     QWORD [rbp-24], 1
        add     QWORD [rbp-32], 1
        add     QWORD [rbp-8], 1
.L2:
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        test    al, al
        je      .L3
        mov     rax, QWORD [rbp-32]
        movzx   eax, BYTE [rax]
        test    al, al
        je      .L3
        cmp     DWORD [rbp-12], 0
        jne     .L3
        mov     rax, QWORD [rbp-8]
        cmp     rax, QWORD [rbp-40]
        jb      .L4
.L3:
        cmp     DWORD [rbp-12], 0
        jle     .L5
        mov     eax, 1
        jmp     .L6
.L5:
        cmp     DWORD [rbp-12], 0
        jns     .L7
        mov     eax, -1
        jmp     .L6
.L7:
        mov     eax, 0
.L6:
        pop     rbp
        ret
