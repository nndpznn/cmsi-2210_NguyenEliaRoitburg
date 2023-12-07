;------------------------------------------------------------------------------
; TO ASSEMBLE:   nasm -fmacho64 makeNBON.nasm
; TO LINK:       gcc -arch x86_64 makeNBON.o makeNBOC.c -o makeNBON
; TO RUN:       ./makeNBON
;------------------------------------------------------------------------------

section .data
    ; Define constants or data here if needed

section .text
    global _main
    extern _makeNBO

_main:
    mov rdi, 5
    call _makeNBO

    mov rdi, 7
    call _makeNBO

    mov rdi, 9
    call _makeNBO

    mov rdi, 11
    call _makeNBO

    mov rdi, 13
    call _makeNBO
    

exit:
    mov rax, 0x2000001    ; syscall number for exit
    xor rdi, rdi          ; exit code 0
    syscall
