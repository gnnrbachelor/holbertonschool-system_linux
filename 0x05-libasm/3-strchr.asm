BITS 64

	global asm_strchr
	extern main
	SECTION .text

asm_strchr:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     eax, esi
        mov     BYTE [rbp-28], al
        mov     DWORD [rbp-4], 0
        jmp     .L2
.L5:
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     BYTE [rbp-28], al
        jne     .L3
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
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
        jne     .L5
        mov     eax, 0
.L4:
        pop     rbp
        ret
