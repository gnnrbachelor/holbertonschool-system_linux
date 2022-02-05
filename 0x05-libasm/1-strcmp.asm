BITS 64

	global asm_strcmp
	extern main
	SECTION .text

asm_strcmp:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     QWORD [rbp-32], rsi
        mov     DWORD [rbp-4], 0
        jmp     .L2
.L6:
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   edx, BYTE [rax]
        mov     eax, DWORD [rbp-4]
        movsx   rcx, eax
        mov     rax, QWORD [rbp-32]
        add     rax, rcx
        movzx   eax, BYTE [rax]
        cmp     dl, al
        je      .L3
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        movsx   eax, al
        mov     edx, DWORD [rbp-4]
        movsx   rcx, edx
        mov     rdx, QWORD [rbp-32]
        add     rdx, rcx
        movzx   edx, BYTE [rdx]
        movsx   edx, dl
        sub     eax, edx
        jmp     .L4
.L3:
        add     DWORD [rbp-4], 1
.L2:
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        test    al, al
        je      .L5
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-32]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        test    al, al
        jne     .L6
.L5:
        mov     eax, 0
.L4:
        pop     rbp
        ret
