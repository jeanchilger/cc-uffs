.text

main:

	addi a0, zero, 6
	addi a1, zero, 9
	
	jal Multiply
	
	ebreak

# Set variables to start the "loop"	
Multiply:

	add s0, zero, zero
	
	j LoopCondition

# Like while(a0 != 0) do LoopBody
LoopCondition:

	bne a0, zero, LoopBody
	
	ret

LoopBody:

	add s0, s0, a1
	addi a0, a0, -1
	
	j LoopCondition
	