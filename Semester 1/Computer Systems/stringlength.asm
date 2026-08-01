.data
string: .asciiz "Computer Systems"
msg:    .asciiz "The length of the string is: "

.text
.globl main
main:
    li $t0, 0         
    la $t1, string     

loop:
    lb $t2, ($t1)   
    beq $t2, $zero, done   
    addi $t0, $t0, 1  
    addi $t1, $t1, 1   
    j loop

done:
    li $v0, 4
    la $a0, msg
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 10
    syscall
