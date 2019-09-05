main:
addi $a0,$0,1
jal recurs_sum

# Final result is stored in $s0.
# program to calculate f(n)=f(n-1)+n.
#total instructions used 10.
add $s0,$0,$v0   
j end

recurs_sum:
addi $t0,$0,2
slt $t1,$a0,$t0
beq $t1,$0,loop
addi $v0,$a0,0
jr $ra



loop:
addi $sp,$sp,-8
sw $a0,$sp,0
sw $ra,$sp,4
addi $a0,$a0,-1
jal recurs_sum
lw $t0,$sp,0
add $v0,$v0,$t0
lw $ra,$sp,4
addi $sp,$sp,8
jr $ra



end:
xori $v0,$0,10