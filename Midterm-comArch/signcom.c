#include <stdio.h>

int x = 0x80000000;

int absolute(int x){
    if (x > 0) return x;
    else return -x;
}

int is_signed_two_complement(){
    if(absolute(x) <= 0) return 1;
    return 0;
}

int is_signed_magnitude(){
    if(absolute(x) > 0) return 1;
    return 0;
}

int main(){
    if (is_signed_two_complement()){
        printf("This computer uses signed two complement representation.\n");
    }
    else if (is_signed_magnitude()){
        printf("This computer uses signed magnitude representation.\n");
    } 
    return 0;
}