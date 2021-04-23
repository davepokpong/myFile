#include <bits/stdc++.h>

using namespace std;

int table[1001];


int main(){
    int n, m, go, i;
    cin >> n >> m;

    for (i=1; i<=n; i++){
        cin >> table[i];
    }

    int now = 0;
    for (i=0; i<m; i++){
        cin >> go;

        now += go;
        if (table[now]!=0) now+=table[now];
        if (now>n){
            now = n;
            break;
        } 
        if (now<=0){
            now = 0;
        }
    }

    cout << now << "\n";
}