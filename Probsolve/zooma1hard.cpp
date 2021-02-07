#include <bits/stdc++.h>

using namespace std;

map<int, int> seq;

int main(){
    int n, m, i, ball, color;

    cin >> n >> m;
    for (i=0; i<n; i++){
        cin >> color;
        if (i==n-1) break;

        seq[i+1] = i+2;
    }

    for (i=n; i<m+n; i++){  
        cin >> color >> ball;
        int next = seq[ball];
        seq[ball] = i+1;
        seq[i+1] = next;
    }

    int next = 1;
    cout << 1 << "\n";
    for (i=0; i<m+n-1; i++){
        cout << seq[next] << "\n";
        next = seq[next];
    }
}