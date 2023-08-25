section .data
    hello_msg db "Hello, Holberton", 0
    format db "%s", 0

section .text
    global main
    extern printf

main:
    push rdi                  ; Save any needed registers
    push rsi
    push rax
    lea rdi, [hello_msg]      ; Load the address of the message into rdi
    mov rax, 0                ; Clear rax (since printf expects return value there)
    call printf               ; Call the printf function
    pop rax                   ; Restore the registers
    pop rsi
    pop rdi

    mov eax, 0                ; Exit with status 0
    ret

