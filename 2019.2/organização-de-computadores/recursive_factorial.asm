.text

main:

	addi a0, zero, 6
	
	jal Factorial

	ebreak

Factorial:
# Calculates the factorial of a given number

# parameters: a0 -> number N
# retrun:     a1 -> factorial of N

	beqz a0, EndFactorial
	
	addi sp, sp, -8
	sw   ra, 4(sp)
	sw   a0, 0(sp)
	
	addi a0, a0, -1
	
	jal Factorial
	nop
	
	lw   a0, 0(sp)
	jal  Multiply
	
	lw   ra, 4(sp)
	addi sp, sp, 8
	
	add a1, zero, s0
	
	ret
	
EndFactorial:
	
	addi a1, zero, 1
	
	ret

Multiply:
# Multiplies two numbers

# parameters: a0 -> number
#	      a1 -> number
# return:     s0 -> a0 x a1

	add s0, zero, zero

	j MultiplyLoopCondition

MultiplyLoopCondition:

	bne a0, zero, MultiplyLoopBody
	
	ret

MultiplyLoopBody:

	add s0, s0, a1
	addi a0, a0, -1

	j MultiplyLoopCondition