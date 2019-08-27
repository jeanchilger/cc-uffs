.text

main:
	addi a0, zero, 25

	addi a1, zero, 9

	addi a2, zero, 23
   
	jal Menor

	ebreak

Menor:
	blt a0, a1, A0_smaller_A1
	blt a1, a0, A1_smaller_A0
      
# Utillity labels
A0_smaller_A1:
	blt a0, a2, RET_A0
	j RET_A2
      
A1_smaller_A0:
	blt a1, a2, RET_A1
	j RET_A2
	
# Return labels 
RET_A0:
	add s0, zero, a0
	ret
	
RET_A1:
	add s0, zero, a1
	ret
	
RET_A2:
	add s0, zero, a2
	ret