#include <stdio.h>
#include <stdlib.h>

int A[15] = {98, 51, 43, 68, 75, 91, 94, 20, 97, 90, 48, 53, 45, 12, 10};

int main() {
    int i, j, temp;

    for (i=0; i<15; i++) {
        printf("%d", A[i]);
        printf(" ");
    }
    printf("\n");
    for(i=1; i<15; i++) {
        temp = A[i];
        j = i - 1;
        while ((temp < A[j]) && (j >= 0)) {
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = temp;
   }

    for (i=0; i<15; i++) {
        printf("%d", A[i]);
        printf(" ");
    }
    printf("\n");
}
