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
	la a0, vector
	

	ebreak
	
# sorts the vector using bubble sort algorithm
sort_vector:

	nop
	
	

###### SWAP TWO POSITIONS IN A VECTOR

# arguments: a0 -> index of vector
#	     a1 -> index of vector
# return:    none

# swap two positions of the vector
swap:

	slli t1, a1, 2 # offset 1
	slli t2, a2, 2 # offset 2
	
	add t1, t1, a0
	add t2, t2, a0
	
	lw  t3, 0(t1)
	lw  t4, 0(t2)
	
	sw  t4, 0(t1)
	sw  t3, 0(t2)
	
	ret


###### FIND MIN VALUE

# parameters: a0 -> vector addres
# 	      a1 -> vector size
# return:     a0 -> smaller value
# 	      a1 -> smaller index

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
