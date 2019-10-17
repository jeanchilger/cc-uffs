.text

main: 
	
	# n-th Fibonacci number
	addi a0, zero, 4

	jal Fibonacci
	nop

	ebreak

Fibonacci:
# Calculates the n-th Fibonacci number defined as
# F(n) = F(n - 1) + F(n - 2)
#
# paramenters: a0 -> the n number
# return:      s1 -> the n-th number

	addi t1, zero, 1 # holds the value 1
	
	add  s0, zero, zero
	add  s1, zero, zero
	
	addi sp, sp, 4
	
	sw   ra, 0(sp)

	jal  N_1
	nop
	
	lw   ra, 0(sp)
	
	ret
	

N_1: 
# Calculates the n-1 branch
# Stores the calculated value in s0

	beq  a0, t1, N_1EqualsOne
	beqz a0, N_1EqualsZero
	
	addi sp, sp, -8
	
	sw   ra, 4(sp)
	sw   a0, 0(sp)
	
	addi a0, a0, -1
	
	jal  N_1
	nop
	
	lw   a0, 0(sp)
	addi a0, a0, -2

	jal  N_2
	nop
	
	lw   ra, 4(sp)
	
	add  s0, s0, s1
	
	addi sp, sp, 8
	
	ret

N_2:
# Calculates the n-2 branch
# Stores the calculated value in s1
	beq  a0, t1, N_2EqualsOne
	beqz a0, N_2EqualsZero
	
	addi sp, sp, -8
	
	sw   ra, 4(sp)
	sw   a0, 0(sp)
	
	addi a0, a0, -2
	
	jal  N_2
	nop
	
	lw   a0, 0(sp)
	addi a0, a0, -1
	
	jal  N_1
	nop
	
	lw   ra, 4(sp)
	
	add  s1, s1, s0
	
	addi sp, sp, 8
	
	ret
	

N_1EqualsOne:
	addi s0, zero, 1
	
	ret
	
N_1EqualsZero:
	add  s0, zero, zero
	
	ret
#	
N_2EqualsOne:
	addi s1, zero, 1
	
	ret
	
N_2EqualsZero:
	add  s1, zero, zero
	
	ret