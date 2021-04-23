#include <bits/stdc++.h>

using namespace std;

int prime[200003];

int main(){
    int l, r, i, j;

    cin >> l >> r;
    prime[1] = 1;

    for(i=2; i<=sqrt(200000); i++){
        if(prime[i] == 0){  //เป็น prime
            for(j=i*i; j<=200000; j+=i){
                prime[j] = 1;
            }
        }
    }
    int n=0;
    for (i=l; i<=r-2; i++){
        if(prime[i]==0 && prime[i+2]==0) n+=1;
    }

    cout << n << "\n";
}