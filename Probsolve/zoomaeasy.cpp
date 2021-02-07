#include <bits/stdc++.h>

using namespace std;

list<int> seq;
list<int>::iterator p;

int main(){
    int n, m, i, ball, color;

    cin >> n >> m;
    for (i=0; i<n; i++){
        cin >> ball;
        seq.push_back(i+1);
    }

    for (i=n; i<m+n; i++){  
        cin >> color >> ball;
        for (p=seq.begin(); p!=seq.end(); p++){
            if (*p == ball){
                p++;
                seq.insert(p, i+1);
                break;
            }
        }
    }

    for (p=seq.begin(); p!=seq.end(); p++){
        cout << *p << "\n";
    }
}