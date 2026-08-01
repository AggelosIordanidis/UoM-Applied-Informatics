.data
string: .asciiz "Computer Systems"
msg: .asciiz "The length of the string is: "

.text

# Compute string length
li $t0, 0  # Counter
la $t1, string
j L2

L1: 
addi $t0, $t0, 1
addi $t1, $t1, 1

L2: 
lb $t2, ($t1)
bne $t2, $0, L1


# Print result
li $v0, 4
la $a0, msg
syscall

li $v0, 1
move $a0, $t0
syscall

# exit
la $v0, 10
syscall
