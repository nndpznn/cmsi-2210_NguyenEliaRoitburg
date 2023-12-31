;------------------------------------------------------------------------------
; TO ASSEMBLE:   nasm -fmacho64 findGCDfunc.nasm -o findGCDfunc.o
; TO LINK:       gcc -arch x86_64 -o gcdFinder gcdFinder.c findGCDfunc.o 
; TO RUN:        ./gcdFinder
;------------------------------------------------------------------------------

global      _findGCDFunc
extern      _fflush
default     rel

section     .data
section     .text

_findGCDFunc:
    mov rax, rdi
    mov rbx, rsi

    cmp rax, 0
    jz end

    xor rdx, rdx

    div rbx
    mov rax, rbx
    mov rbx, rdx

    JMP _findGCDFunc

end:
    mov rax, rbx
    ret


section     .data
    num1:       dd 0
    num2:       dd 0

    numformat:  db "%d", 0
    prompt:     db      "Enter a number:", 10, 0
    gcdformat:  db "GCD: %d", 0
