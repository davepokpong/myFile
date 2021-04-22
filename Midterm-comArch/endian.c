#include <stdio.h>

int is_big_endian(){
    unsigned int x = 0x76543210;
    char *c = (char*) &x;
 
    //printf ("*c is: 0x%x\n", *c);
    if (*c != 0x10) return 1;
    else  return 0;
}

int is_little_endian(){
    unsigned int x = 0x76543210;
    char *c = (char*) &x;
 
    //printf ("*c is: 0x%x\n", *c);
    if (*c == 0x10) return 1;
    else return 0;
}

int main(){

    if (is_big_endian()){
        printf("This is a big-endian computer.\n");
    }else if (is_little_endian()){
        printf("This is a little-endian computer.\n");
    }
    return 0;
}