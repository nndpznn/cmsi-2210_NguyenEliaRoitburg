global      _findGCDFunc
extern      _fflush
default     rel

section     .text

_findGCDFunc:
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
