#include <bits/stdc++.h>

using namespace std;

int a[1010];

int main(){
    int i, n, m, k, overall=0, hungry=0;

    cin >> n >> m >> k;
    for (i=1; i<=n; i++){
        cin >> a[i];
    }

    for (i=1; i<=n; i++){
        overall += a[i];
        if (i+1<=n){
            if (overall>=k){
                overall -= k;
                continue;
            }
        }
        if (overall<m){
            hungry = -1;
            break;
        }else{
            overall -= m;
            hungry += 1;
            continue;
        }
        // cout << "i:" << i << "\n"; 
        // cout << "overall:" << overall << "\n"; 
    }

    cout << hungry << "\n";
}