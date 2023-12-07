;------------------------------------------------------------------------------
; TO ASSEMBLE:   nasm -fmacho64 findGCD.nasm
; TO COMPILE:    gcc -arch x86_64 findGCD.o -o findGCD
; TO RUN:       ./findGCD
;------------------------------------------------------------------------------


global      _main
extern      _printf,    _scanf,     _fflush
default     rel

section     .text

_main:
    push rbx

    xor rdi, rdi
    call _fflush

    lea rdi, [prompt]
    call _printf

    lea rdi, [numformat]
    mov rsi, num1
    call _scanf

    lea rdi, [prompt]
    call _printf

    lea rdi, [numformat]
    mov rsi, num2
    call _scanf

start:
    mov rax, num1
    mov rbx, num2

gcd:
    cmp rax, 0
    jz done

    xor rdx, rdx
    
    idiv rbx
    mov rax, rbx
    mov rbx, rdx

    JMP gcd


done:
    mov rsi, rax
    lea rdi, [gcdformat]
    call _printf

end:
    pop rbx
    ret


section     .data
    num1:       dd 0
    num2:       dd 0

    numformat:  db "%d", 0
    prompt:     db      "Enter a number:", 10, 0
    gcdformat:  db "GCD: %d", 0