.data 
even:   .asciiz "x is even\n"
odd:    .asciiz "x is odd\n"

.text
main:
    addi    s0, x0, 36          # s0 เก็บ x=36
    mv      a0, s0              # a0 เก็บ s0 เข้า function
    jal     chk_even            # jump to chk_even 
    
    addi    s1, x0, 1           # s1 = 1
    beq     a0, s1, is_even     # if (is_even(x) == 1)

    # printf("x is odd\n")
    addi    a0, x0, 4
    la      a1, odd
    ecall   
    addi    a0, x0, 10          # terminate ecall
    ecall

is_even:
    # printf("x is even\n")
    addi    a0, x0, 4
    la  a1, even
    ecall
    addi    a0, x0 ,10          # terminate ecall
    ecall

chk_even:
    beq     a0, x0, return1     # if (n == 0) go to return1
    
    addi    a0, a0, -1          # n-1
    j       chk_odd             # jump to chk_odd

return1:
    # return 1
    addi    a0, x0, 1      
    jr      ra     

chk_odd:
    beq     a0, x0, return0      # if (n == 0) go to return0

    addi    a0, a0, -1           # n-1
    j chk_even                   # jump to chk_even

return0:
    addi    a0, x0, 0            # return 0
    jr      ra