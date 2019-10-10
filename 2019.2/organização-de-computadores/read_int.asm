.data

	input_int:  .string "Insira um valor para k: "
	output_int: .string "Valor informado: "
	
	break_line: .string "\n"
	

.text

main:
	
	jal Input
	nop
	
	ebreak
	
Input:
# make the input for the program
#
# parameters: NONE
# return:     NONE

	add t0, ra, zero

	jal PrintInputString
	nop
	
	jal ReadInteger
	nop
	
	add t1, a0, zero
	
	jal BreakLine
	nop
	
	add a0, t1, zero
	
	jal PrintInteger
	nop
	
	add ra, t0, zero
	ret
	
	
ReadInteger:
# reads one integer value from keyboard
#
# parameters: NONE
# return:     a0 -> number read

	#jal PrintString
	nop
	
	addi a7, zero, 5
	
	ecall

	ret

PrintInputString:
# prints the string for input
#
# parameters: NONE
# return:     NONE
	
	addi a7, zero, 4
	la   a0, input_int
	
	ecall
	
	ret
	
BreakLine:
# prints a break line
#
# parameters: NONE
# return:     NONE

	addi a7, zero, 4
	la   a0, break_line
	
	ecall
	
	ret
	
PrintInteger:
# prints a integer value
#
# parameters: a0 -> integer to print
# return:     NONE

	addi a7, zero, 1
	
	ecall
	
	ret