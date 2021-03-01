# x = 5
# if ((x > 0) && (x < 10)) {
#     i++;
# }
# else {
#    i--;
# }
# x += 2;

# x -> t0
# i -> t1

            
            addi s0, x0, 10 # put constant 10 to s0
            addi t0, x0, 5 # put constant 5 to t0 x (t0)

            # if ((x > 0) && (x < 10)) // short-circuit evaluation
            bge x0, t0, else_block # if 0 >= x goto else_block
            bge t0, s0, else_block # if x >= 10 goto else_block

            # i++
            addi t1, t1, 1
            j join_block

else_block:

            # i--
            addi t1, t1, -1

join_block:

            # x += 2
            addi t0, t0, 2

            addi a0, x0, 10
            ecall # Terminate ecall
