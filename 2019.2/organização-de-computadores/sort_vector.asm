.data

vector: .word 5 6 4 7 15 9 97


.macro print_int (%x)
	li a7, 1
	add a0, zero, %x
	ecall
.end_macro


.text 

main:

	# vector addres
	

	ebreak
	

###### SWAP TWO POSITIONS IN A VECTOR

# swap positions of the vector
swap:

	mul t1, a1, t0
	mul t2, a2, t0
	
	add t1, t1, a0
	add t2, t2, a0
	
	lw t3, 0(t1)
	lw t4, 0(t2)
	
	sw t4, 0(t1)
	sw t3, 0(t2)
	
	ret


###### FIND MIN VALUE	
# set registers and call loop body
find_min:
	
	add  t0, a0, zero     # vector address
	add  t1, a1, zero     # vector size
	
	lw   t2, 0(t0)        # register for smaller value
	add  t3, zero, zero   # register for smaller index
	
	add  t4, zero, zero   # register for current pos

	j    loop

# iterate and make conditional jumps
loop: 
	
	# val, pos(address)
	lw   t5, 0(t0) # aux: current value
	blt  t5, t2, found_new_min
	
	addi t0, t0, 4
	addi t4, t4, 1

	beq  t4, t1, end_loop
	
	j    loop
	
# a new min value candidate was found
found_new_min:

	add t2, t5, zero # t2 = t5 (t2 = new min value)
	add t3, t4, zero # t3 = t4 (t3 = new min position)
	
	addi t0, t0, 4
	addi t4, t4, 1
	
	j    loop
	
# set register and return
end_loop:

	add a0, t2, zero
	add a1, t3, zero
	
	ret