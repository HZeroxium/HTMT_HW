.data
prompt: .asciiz "Input a character: "
result_uppercase: .asciiz "\nResult: Uppercase\n"
result_lowercase: .asciiz "\nResult: Lowercase\n"
result_invalid: .asciiz "\nResult: Invalid (not a character)\n"
.text
.globl main

main:
    # Print prompt
    li $v0, 4
    la $a0, prompt
    syscall

    # Read character from input
    li $v0, 12
    syscall
    move $s0, $v0
    
    # Check if the character is uppercase or lowercase
    li $t0, 'a'
    li $t1, 'z'
    li $t2, 'A'
    li $t3, 'Z'
    # If (c < 'A')
    blt $s0, $t2, print_invalid 
    # If (c > 'z')
    bgt $s0, $t1, print_invalid
    # Now (c in range ['A' .. 'z']
    # If (c <= 'Z') -> Uppercase
    ble $s0, $t3, print_uppercase
    # If (c >= 'a') -> Lowercase
    bge $s0, $t0, print_lowercase
    # If (c > 'Z' && c < 'a') -> Invalid
    li $v0, 4
    la $a0, result_invalid
    syscall
    j end
    
less_than_z:
   
    
print_lowercase:
    # Print the result (lowercase)
    li $v0, 4
    la $a0, result_lowercase
    syscall
    j end
    
print_uppercase:
    li $v0, 4
    la $a0, result_uppercase
    syscall
    j end
    
print_invalid:
    li $v0, 4
    la $a0, result_invalid
    syscall
    j end
    
end:
    # Exit the program
    li $v0, 10
    syscall
