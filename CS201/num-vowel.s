/*********************************************************************
 * FileName:        num-vowel.s
 *
 * Processor:       PIC32MX
 * 
 * Assembler/Compiler/Linker:  MPLAB C32
 *
 * 
 * Description:
 * This project asks the user to enter a string.  
 * The program then counts the number of vowels in the string.
 *
 ********************************************************************/

#include <p32xxxx.h>

#################################################
  .data

  prompt1:     		.asciiz "Please enter a string up to 50 chars long:\n\000"
  stringBuffer:		.space 50
  endl:				.asciiz "\n\000"
  printNumVowels: 	.asciiz "The number of vowels is: %d\n\000"
  printNumConso:  	.asciiz "The number of consonents are: %d\n\000"
  
  #Used for debugging
  #printChar:   .asciiz "The var sitting in the return is: %c\n\000"
  #printInt:    .asciiz "The int sitting in the return is: %d\n\000"

## Students DO NOT edit this section
#################################################
#                                               #
#               text segment                    #
#                                               #
#################################################
  .text
  .align	2
  .globl	main
  .ent	main
  .type	main, @function

main:
  .frame	$fp,512,$31	# vars= 8, regs= 1/0, args= 0, gp= 8
  .mask	0x40000000,-8
  .fmask	0x00000000,0
  .set	noreorder
  .cpload	$25
  .set	reorder
  addiu	$sp,$sp,-512
  sw	$31,508($sp)
  sw	$fp,504($sp)
  move	$fp,$sp
  .cprestore  16
## END Students DO NOT edit this section


## Students edit here  #################################################

  la	$a0, prompt1		# print prompt on terminal
  jal 	printf				# out a string

  la	$a0, stringBuffer	# load the address of the stringBuffer
  li	$a1,50				# load the length
  jal	mreads
  
  la 	$s0, stringBuffer	# load the string inside $s0

loop:
  lb 	$a0, ($s0) 		# loading single character from stringBuffer
  beqz 	$a0, End 		# if end of string then jump to End 
  jal 	vowelp 			# procedure call
  addi 	$s0, $s0, 1 	# or else move character by character in example 
  beqz 	$v0, plusConso 	# If return value is 1 than the character is vowel 
  addi  $s1,$s1,1 		# increment consonent count 
  j loop 				# reenter loop 

plusConso: 
  addi $s2,$s2,1 		# increment vowel count 
  j loop 				# reenter loop 
  
End:
 # la $a0, endl			# print newline on terminal
 # jal printf

  la $a0, printNumVowels	# print the value of 
  move $a1, $s1
  jal printf

  la $a0, printNumConso
  move $a1, $s2
  jal printf

  la $a0, endl			# print newline on terminal
  jal printf

	    
## Do not edit  below ######################################

  move	$sp,$fp
  lw	$31,508($sp)
  lw	$fp,504($sp)
  addiu	$sp,$sp,512
  j	$31
  .end	main

## Do not edit  above ######################################	


vowelp: 
  beq $a0,'A',yes 
  beq $a0,'a',yes 
  beq $a0,'E',yes 
  beq $a0,'e',yes 
  beq $a0,'I',yes 
  beq $a0,'i',yes 
  beq $a0,'O',yes 
  beq $a0,'o',yes 
  beq $a0,'U',yes 
  beq $a0,'u',yes
  j no
  jr $ra 
yes: 
  li $v0, 1 	# its vowel than return 1 
  jr $ra

no: 
  li $v0, 0
  jr $ra