#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l, i, j;

    cin >> n >> l;
    int N[n];
    int L[l];
    int res[n];

    for (i=0; i<n; i++){
        cin >> N[i];
    }

    for (i=0; i<l; i++){
        cin >> L[i];
    }

    int max=N[0];
    for (i=1; i<n; i++){
        if (max<N[i]){
            max = N[i];
            res[i] = 0;
            continue;
        }   
        res[i] = max - N[i] + 1;
    }

    for (i=0; i<l; i++){
        cout << res[L[i]-1] << "\n";
    }
}