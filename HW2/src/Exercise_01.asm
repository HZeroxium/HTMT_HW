.data
    aPrompt: .asciiz "Input a: "
    bPrompt: .asciiz "Input b: "
    eq: .asciiz "Result: a = b \n"
    gt: .asciiz "Result: a > b\n"
    lt: .asciiz "Result: a < b\n"

.text
    # Nh?p s? nguy�n a
    li $v0, 4
    la $a0, aPrompt
    syscall
    li $v0, 5
    syscall
    move $s0, $v0  # L?u gi� tr? c?a a v�o $s0

    # Nh?p s? nguy�n b
    li $v0, 4
    la $a0, bPrompt
    syscall
    li $v0, 5
    syscall
    move $s1, $v0  # L?u gi� tr? c?a b v�o $s1

    # So s�nh a v� b
    bgt $s0, $s1, a_gt_b
    blt $s0, $s1, a_lt_b

    # N?u kh�ng th?a m�n ?i?u ki?n n�o th� a b?ng b
    li $v0, 4
    la $a0, eq
    syscall
    j end

a_gt_b:
    # a > b
    li $v0, 4
    la $a0, gt
    syscall
    j end

a_lt_b:
    # a < b
    li $v0, 4
    la $a0, lt
    syscall

end:
    # K?t th�c ch??ng tr�nh
    li $v0, 10
    syscall
