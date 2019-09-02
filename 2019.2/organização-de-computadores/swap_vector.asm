.data

vector: .word 5 6 4 7 15 9 97


.macro print_int (%x)
	li  a7, 1
	add a0, zero, %x
	ecall
.end_macro


.text 

main:

	# vector addres
	la   a0, vector
	add  t5, zero, a0
	
	addi a1, zero, 0 # index to swap
	addi a2, zero, 2 # index to swap
	
	addi t0, zero, 4 # constant to multiply (get address)
	
	jal  swap

	ebreak
	
# swap positions of the vector
swap:

	mul t1, a1, t0 # offset 1
	mul t2, a2, t0 # offset 2
	
	add t1, t1, a0
	add t2, t2, a0
	
	lw  t3, 0(t1)
	lw  t4, 0(t2)
	
	sw  t4, 0(t1)
	sw  t3, 0(t2)
	
	ret