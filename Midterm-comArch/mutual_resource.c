#include <stdio.h>

int is_odd(int n);

int is_even(int n) {
    if (n == 0) return 1;
    else return is_odd(n - 1);
}

int is_odd(int n) {
    if (n == 0) return 0;
    else return is_even(n - 1);

}

int main() {
    int x;
    x = 36;
    if (is_even(x) == 1) printf("x is even\n");
    else printf("x is odd\n");
    return 0;
}
