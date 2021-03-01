.data
A: .word 98, 51, 43, 68, 75, 91, 94, 20, 97, 90, 48, 53, 45, 12, 10
newline: .asciiz "\n"
space: .asciiz " "

.text
main:
    la      s0, A               # s0 เก็บ address A
    addi    s1, x0, 0           # s1 เก็บ i=0
    addi    s2, x0, 15          # s2 เก็บ i=15
    addi    s3, x0, 0           # s3: 0

loop1:
    bge     s1, s2, end_loop1   # ถ้า s1>s2 ให้ทำ end_loop1

    add     s5, s0, s3
    lw      s4, 0(s5)           # s4 คือ A[i]
    addi    s3, s3, 4           # s3 += 4

    # printf("%d", A[i]);
    addi    a0, x0, 1          
    mv      a1, s4
    ecall
    addi    a0, x0, 4          
    la      a1, space
    ecall

    addi    s1, s1, 1           # i++
    j loop1

end_loop1:
    # printf("\n");
    addi    a0, x0, 4          
    la      a1, newline
    ecall

    addi    s1, x0, 1           # set i=1
    addi    s3, x0, 4           # s3: 4

loop2:
    bge     s1, s2, end_loop2   # ถ้า s1>s2 ให้ทำ end_loop2

    add     s5, s0, s3
    lw      s4, 0(s5)           # s4 คือ temp = A[i]
    addi    s3, s3, 4           # s3 += 4

    addi    s6, s1, -1          # j = i-1

    slli    s7, s6, 2           
    add     s7, a0, s7
    lw      s8, 0(s7)           # s8 เก็บ A[j]

    while:
        bge     s4, s8, end_while   
        blt     s6, x0, end_while

        addi    s7, s7, 4       # A[j+1]
        sw      s8, 0(s7)       # A[j+1] = A[j]
        addi    s7, s7, -4      # ถอย j กลับมา
        addi    s6, s6, -1      # j = j-1
        addi    s7, s7, -4      # ขยับ address j ตามค่า j ที่เปลี่ยนไป

        lw      s8, 0(s7)       # A[j]
        j while

    end_while:
        addi    s7, s7, 4       # Address j+1
        sw      s4, 0(s7)       # A[j+1] = temp

        addi    s1, s1, 1       # i++
        j loop2

end_loop2:    
    addi s1, s0, 0              # i=0

loop3:
    bge     s1, s2, end_loop3   # ถ้า s1>s2 ให้ทำ end_loop3

    add     s5, s0, s3
    lw      s4, 0(s5)           # s4 คือ A[i]
    addi    s3, s3, 4           # s3 += 4

    # printf("%d", A[i]);
    addi    a0, x0, 1          
    mv      a1, s4
    ecall
    addi    a0, x0, 4          
    la      a1, space
    ecall

    addi    s1, s1, 1           # i++
    j loop3

end_loop3:
    # printf("\n");
    addi    a0, x0, 4          
    la      a1, newline
    ecall