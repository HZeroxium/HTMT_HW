.data
prompt_N: .asciiz "Input N: "
prompt_open_array: .asciiz "a["
prompt_close_array: .asciiz "] = "
output_msg: .asciiz "Sum of array: "
space: .asciiz " "

.text
.globl main

main:
    # Input N
    li $v0, 4
    la $a0, prompt_N
    syscall
    
    li $v0, 5
    syscall
    move $s0, $v0
    
    # Create space for array
    li $v0, 9
    move $a0, $s0
    sll $a0, $a0, 2
    syscall
    move $s1, $v0
    
    # Input array elements
    move $t0, $s1  # $t0 points to the beginning of the array
    li $t1, 0  # loop counter i = 0
    
input_loop:
    beq $t1, $s0, find_sum  # jump to print_array if i = N
    move $a0, $t1  # printf("a[%d] = ", i)
    li $v0, 4
    la $a0, prompt_open_array
    syscall
    li $v0, 1
    la $a0, ($t1)
    syscall
    li $v0, 4
    la $a0, prompt_close_array
    syscall
    
    li $v0, 5  # scanf("%d", &array[i])
    syscall
    sw $v0, ($t0)
    
    addiu $t0, $t0, 4  # increment the array pointer by 4
    addiu $t1, $t1, 1  # increment i by 1
    j input_loop
    
find_sum:
    # Print the array
    move $t0, $s1  # $t0 points to the beginning of the array
    li $s1, 0 # Sum
    li $t1, 0  # loop counter i = 0  
    
sum_loop:
    beq $t1, $s0, end_program  # jump to end_program if i = N
    lw $s2, ($t0)
    add $s1, $s1, $s2
    addiu $t0, $t0, 4  # increment the array pointer by 4
    addiu $t1, $t1, 1  # increment i by 1
    
    j sum_loop

end_program:
    # Exit the program
    li $v0, 4
    la $a0, output_msg
    syscall
    li $v0, 1
    move $a0, $s1
    syscall
    li $v0, 10
    syscall
