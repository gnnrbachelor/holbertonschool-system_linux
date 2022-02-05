BITS 64

	global asm_strstr
	extern main
	SECTION .text

asm_strstr:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     QWORD [rbp-32], rsi
        mov     DWORD [rbp-4], 0
        jmp     .L2
.L8:
        mov     DWORD [rbp-8], 0
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   edx, BYTE [rax]
        mov     eax, DWORD [rbp-8]
        movsx   rcx, eax
        mov     rax, QWORD [rbp-32]
        add     rax, rcx
        movzx   eax, BYTE [rax]
        cmp     dl, al
        jne     .L4
        mov     eax, DWORD [rbp-4]
        mov     DWORD [rbp-12], eax
        jmp     .L4
.L5:
        add     DWORD [rbp-4], 1
        add     DWORD [rbp-8], 1
.L4:
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   edx, BYTE [rax]
        mov     eax, DWORD [rbp-8]
        movsx   rcx, eax
        mov     rax, QWORD [rbp-32]
        add     rax, rcx
        movzx   eax, BYTE [rax]
        cmp     dl, al
        je      .L5
        mov     eax, DWORD [rbp-8]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-32]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        test    al, al
        jne     .L6
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        jmp     .L7
.L6:
        add     DWORD [rbp-4], 1
.L2:
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        test    al, al
        jne     .L8
        mov     eax, 0
.L7:
        pop     rbp
        ret
