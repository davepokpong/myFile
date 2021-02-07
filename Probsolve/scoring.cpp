#include <bits/stdc++.h>

using namespace std;

int marks[101] = {0};
int chk[101] = {0};

int main(){
    int n, m, i, no, mark;
    int res=0;
    
    cin >> n >> m;
    for (i=0; i<m; i++){
        cin >> no >> mark;
        if (marks[no]<mark) marks[no]=mark;
        chk[no]++;
    }

    for (i=1; i<=101; i++){
        if (chk[i]>5) marks[i]=0;
    }

    for (i=0; i<n; i++){
        res += marks[i+1];
    }

    cout << res << "\n";
}