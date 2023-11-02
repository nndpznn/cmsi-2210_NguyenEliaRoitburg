; ----------------------------------------------------------------------------------------
; This is a Mac OSX console program that displays the contents of the flags register on
;     the display.  In addition, if the carry flag is set, it outputs a message to that
;     effect, and if the overflow flag gets set, it outputs that message as well.
;
;  to assemble:   nasm -fmacho64 flagsMac.nasm
;  to link:       gcc -no_pie flagsMac.o -o flagsMac
;  to run:        ./flagsMac
; ----------------------------------------------------------------------------------------

            global      _start
            extern      _printf
            default     rel

            section     .text
_start:     pushfd                          ; push the value of the flags onto the stack
            pop         r8                  ; pop flags and load into r8
            mov         rax,  addend        ; initialize the RAX register

display1:   mov         rsi, r8             ; display the starting value of the flags using printf
            lea         rdi, [hexformat]    ; loads data from r8, uses format specified below
            call        _printf

            mov         rdi, rax            ; display the starting value of the rax register using printf
            lea         rdi, [hexformat]       
            call        _printf

addloop:    add         rax, rax            ; add the rax register to itself

carrychk:   pushfd                          ; get the flag values
            pop         r8                  ;  and save 'em
            AND         r8, 0x00000001      ; mask off the carry flag [bit zero]
            cmp         r8, 0x00000001      ; check if the carry flag is set
            jnz         display2            ; it's set, so output the message
            jmp         ovrflwchk           ; it's not, so check for overflow flag

display2:   mov         rsi, carryset       ; display the carry flag set message
            lea         rdi, [strformat]            
            call        _printf

ovrflwchk:  pushfd                          ; get the flag values again
            pop         r8                  ;  and save 'em
            AND         r8, 0x00000800      ; mask off the overflow flag [bit eleven]
            cmp         r8, 0x00000800      ; check if the overflow flag is set
            jnz         display3            ; it's set, so output the message
            jmp         addloop             ; if it is NOT, go again

display3:   mov         rsi, overflwset     ; display the overflow flag is set message
            lea         rdi, [strformat]
            call        _printf

quit:       mov         rax, 0x02000001     ; system call for exit
            xor         rdi, rdi            ; exit code 0
            syscall                         ; invoke operating system to exit

            section     .data
hexformat:  db          0x0A, '%0x', 0x0A, 0x00
strformat:  db          0x0A, '%s', 0x0A, 0x00

            section     .bss
carryset:   equ         'Carry set!'
overflwset: equ         'Overflow set!'
addend:     equ          0x87654321

; define your variables down here
; this includes the two messages, and perhaps the value to add each time