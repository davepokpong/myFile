#include <iostream>

using namespace std;

void inc(int* y){
    (*y)++;
}

int main(){
    int x=10;
    cout << x << endl;
    inc(&x);
    cout << x << endl;
}