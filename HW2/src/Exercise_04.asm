.data
prompt: .asciiz "Input a string: "
output_msg: .asciiz "Length of string:"
newline: .asciiz "\n"

.text
.globl main

main:
    # Input string
    li $v0, 4
    la $a0, prompt
    syscall
    
    li $v0, 8
    la $a0, buffer
    li $a1, 100
    syscall
    
    # Find the string length
    la $s0, buffer  # $s0 points to the beginning of the string
    li $s1, 0  # initialize length counter to 0
    
    length_loop:
        lb $t0, ($s0)  # load a character from memory
        
        beqz $t0, print_length  # exit the loop if null terminator is found
        addiu $s0, $s0, 1  # increment the string pointer by 1
        addiu $s1, $s1, 1  # increment length counter by 1
        j length_loop
        
    print_length:
        # Print the string length
        li $v0, 4
        la $a0, output_msg
        syscall
        
        li $v0, 1
        sub $s1, $s1, 1
        move $a0, $s1
        syscall
        
        # Print newline
        li $v0, 4
        la $a0, newline
        syscall
        
        # Exit the program
        li $v0, 10
        syscall

.data
buffer: .space 100  # buffer to store the input string
