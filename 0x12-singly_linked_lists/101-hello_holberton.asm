; Declare external functions
extern printf
extern exit

section .data
    ; String for printf
    hello_string db "Hello, Holberton", 10, 0

section .text
    global main

main:
    ; Save the current stack pointer
    mov rbp, rsp

    ; Align the stack to a 16-byte boundary
    and rsp, -16

    ; Call printf with one argument: address of hello_string
    ; First argument: address of hello_string
    lea rdi, [rel hello_string]

    ; Set RAX to 0 (Number of SSE registers used)
    xor rax, rax

    ; Save the current stack pointer in rbx
    mov rbx, rsp

    ; Reserve 8 bytes on the stack for printf
    sub rsp, 8

    ; Call printf
    call printf

    ; Restore the stack pointer
    mov rsp, rbx

    ; Call exit with return code 0
    xor edi, edi
    call exit
