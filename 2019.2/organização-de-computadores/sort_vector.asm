.data

vector:          .word 5 6 4 7 15 9 97
	
msg_vetor: 	 .string "Vetor: "
msg_new_line:	 .string "\n"
msg_space:	 .string " "


.macro print_int (%x)
	li a7, 1
	add a0, zero, %x
	ecall
.end_macro


.text 

main:

	# vector addres
	la a0, vector

	# vector size
	addi a1, zero, 7

	#jal imprime_vetor
	nop

	jal sort_vector
	nop
	
	jal imprime_vetor
	nop
	
	ebreak
	
###### SORTS THE VECTOR

# parameters: a0 -> vector addres
# 	      a1 -> vector size
# return:     none

# sorts the vector using bubble sort algorithm
sort_vector:

	# preserve original vector address and size
	add  s0, a0, zero  # vector address
	add  s1, a1, zero  # vector size

	add  s2, a0, zero  # vector original address (does not change)
	
	add  s3, zero, zero  # position to swap (store the smaller found in here)
	
	add  s6, ra, zero  # saves the callee address

	j   sort_loop
	

# iterates through the vector
sort_loop:

	ble  s1, s3, end_sort
	
	# load vector address and vector size
	add  a0, s0, zero
	add  a1, s1, zero
	
	# find min value between s3 and last member
	jal  find_min # here should be a j find_min
	nop
	
	add  a0, s2, zero
	add  a2, s3, zero
	
	# swap min value found and the current swap position
	jal  swap # here should be a j swap
	nop
	
	addi s3, s3, 1
	addi s0, s0, 4
	
	j    sort_loop

# set registers and return
end_sort:
	
	add a0, s2, zero  # reset vector address
	add a1, s1, zero  # reset vector size
	
	jr s6 # ret to main

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
	add  t3, s3, zero     # register for smaller index
	
	add  t4, s3, zero     # register for current pos

	j    fm_loop

# iterate and make conditional jumps
fm_loop: 
	
#	ble  t1, t4, end_fm_loop
	
	# val, pos(address)
	lw   t5, 0(t0) # aux: current value
	blt  t5, t2, found_new_min
	
	ble  t1, t4, end_fm_loop
	
	addi t0, t0, 4
	addi t4, t4, 1
	
	j    fm_loop
	
# a new min value candidate was found
found_new_min:

	add  t2, t5, zero # t2 = t5 (t2 = new min value)
	add  t3, t4, zero # t3 = t4 (t3 = new min position)
	
	addi t0, t0, 4
	addi t4, t4, 1
	
	j    fm_loop
	
# set register and return
end_fm_loop:

	add a0, t2, zero
	add a1, t3, zero
	
	ret
	
###### SWAP TWO POSITIONS IN A VECTOR

# parameters: a0 -> vector address
#	      a1 -> vector index
#	      a2 -> vector index
# return:     none

# swap two positions of the vector
swap:

	slli t1, a1, 2 # offset 1
	slli t2, a2, 2 # offset 2
	
	add  t1, t1, a0 # address 1
	add  t2, t2, a0 # address 2
	
	lw   t3, 0(t1)
	lw   t4, 0(t2)
	
	sw   t4, 0(t1)
	sw   t3, 0(t2)
	
	ret

#########################################################
# imprime_vetor
# argumentos: a0 - endereço inicial do vetor
#             a1 - tamanho do vetor
# retorno: ---- (nenhum retorno)
# registradores ocupados: a0 - argumento de entrada 
#			       e argumento para o ecall
#			  a1 - argumento de entrada
#			  a2 - ponteiro para o vetor
# 			  a7 - argumento para o ecall
# comentário: a função NÂO preserva os valores dos 
#	      argumentos passados para a função
#########################################################
	
imprime_vetor:
	add	a2, zero, a0	#transfere valor de a0 para a2

	la	a0, msg_vetor	# coloca endereço inicial da mensagem em a0
	li	a7, 4		# carrega a7 com valor correspondente a impressao de string na chamada de sistema
	ecall			# chamada de sistema (exception call)

laco_imp:	
	beq	a1, zero, fim	# verifica se percorreu todo o vetor. Caso sim, desvia para fim
	lw	a0, 0(a2)	# lê endereço atual do vetor e coloca em a0
	li	a7, 1		# carrega a7 com valor correspondente a impressao de inteiro na chamada de sistema
	ecall			# chamada de sistema (exception call)

	la	a0, msg_space	# coloca endereço inicial da mensagem em a0
	li	a7, 4		# carrega a7 com valor correspondente a impressao de string na chamada de sistema
	ecall			# chamada de sistema (exception call)
	
	addi	a2, a2, 4	# faz a2 apontar para próxima posição do vetor
	addi 	a1, a1, -1 	# decrementa variável de controle (para saber se percorreu todo o vetor)
	j	laco_imp	# desvia para laco
	
fim:
	la	a0, msg_new_line # coloca endereço inicial da mensagem em a0	
	li	a7, 4		 # carrega a7 com valor correspondente a impressao de string na chamada de sistema
	ecall			 # chamada de sistema (exception call)
	ret	
		
######################################################	
