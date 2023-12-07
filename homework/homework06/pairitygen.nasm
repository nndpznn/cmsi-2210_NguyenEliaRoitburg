;------------------------------------------------------------------------------
; TO ASSEMBLE:   nasm -fmacho64 pairitygen.nasm
; TO COMPILE:    gcc -arch x86_64 pairitygen.o -o pairitygen 
; TO RUN:       ./pairitygen
;------------------------------------------------------------------------------

global      _main
extern      _printf
default    rel

section .text

_main:
    mov rsi, byt
    mov R8, 9
    mov rax, 0 ;is the count

    mov R9, 2
    mov R10, 1

loop:
    sub R8, 1
    cmp R8, 0
    jz result

    mov rcx, [rsi]
    sub rcx, 1
    cmp rcx, 0
    jz addtocount
    
    JMP loop
    
addtocount:
    mov R10, 1
    inc R10
    JMP loop

result:
    mov R9, 2
    div R9

    cmp rdx, 0
    jz printone

    lea rdi, [zero]
    call _printf
    JMP end

printone:
    lea rdi, [one]
    call _printf

end:
    pop rbx
    ret

section .data
    byt:   dd   10101010

    one:  db    "1", 0  
    zero  db    "0", 0
