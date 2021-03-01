#include <stdio.h>

int main() {
    int count1, count2, x;
    count1 = 1;
    count2 = 2;
    x = 3;
    count1++;
    count2++;
    x++;
    printf("%d", x);
    printf(" ");
    printf("%d", count1);
    printf(" ");
    printf("%d", count2);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}
/*
.data
newline:    .asciiz "\n"
spacebar:   .asciiz " "        
hello:      .asciiz "Hello World!"

.text
main:
    addi s0, x0, 1 # count1 = 1
    addi s1, x0, 2 # count2 = 2
    addi s2, x0, 3 # x = 3

    addi s0, s0, 1 # count1++
    addi s1, s1, 1 # count2++
    addi s2, s2, 1 # x++

# to print a string:
# a0 must have the value of 4
# a1 must contain the address of the first byte of the string to be printed

print_and_exit:
    addi a0, x0, 1 # print integer
    mv a1, s2
    ecall # print x
    addi a0, x0, 4 # print string
    la a1, spacebar # print space
    ecall
    addi a0, x0, 1 # print integer
    mv a1, s0
    ecall # print count1
    addi a0, x0, 4 # print string
    la a1, spacebar # print space
    ecall
    addi a0, x0, 1 # print integer
    mv a1, s1
    ecall # print count2
    addi a0, x0, 4 # print string
    la a1, newline # print new line
    ecall
    addi a0, x0, 4 # print string
    la a1, hello # print Hello World!
    ecall 
    addi a0, x0, 4 # print string
    la a1, newline # print new line
    ecall
    addi a0, x0, 10
    ecall # Terminate ecall

*/