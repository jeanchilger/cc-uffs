.text

main:

	addi a0, zero, 15

	addi a1, zero, 9

	addi a2, zero, 13

	jal CheckTriangle
	
	ebreak
	
CheckTriangle:
	bgt a0, a1, a0_check
	bgt a1, a0, a1_check

	
a0_check: # a0 > a1
	bgt a0, a2, a0_bigger
	j a2_bigger
	
a1_check: # a1 > a0
	bgt a1, a2, a1_bigger
	j a2_bigger

# Bigger number was found	
a0_bigger:
	add t0, a1, a2
	sgt s0, a0, t0 # if s0=1, not a triangle
	ret

a1_bigger:
	add t0, a0, a2
	sgt s0, a1, t0 # if s0=1, not a triangle
	ret

a2_bigger:
	add t0, a0, a1
	sgt s0, a2, t0 # if s0=1, not a triangle
	ret
