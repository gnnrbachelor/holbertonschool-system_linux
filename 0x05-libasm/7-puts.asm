BITS 64
	global asm_puts
	extern asm_strlen
	SECTION .text

asm_puts:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     QWORD [rbp-24], rdi
        mov     rax, QWORD [rbp-24]
        mov     rdi, rax
        mov     eax, 0
        call    asm_strlen
        cdqe
        mov     QWORD [rbp-8], rax
        mov     rdx, QWORD [rbp-8]
        mov     rax, QWORD [rbp-24]
        mov     rsi, rax
        mov     edi, 1
        mov     eax, 1
	syscall
        cdqe
        leave
        ret
