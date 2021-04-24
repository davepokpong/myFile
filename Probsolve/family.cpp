#include <bits/stdc++.h>

using namespace std;

map<int,int> animal;

int findPar(int a, int b){
    int ch = a;
    
    while(animal[ch] != b){
        
        if(animal[ch] == 0) return -1;
        ch = animal[ch];
    }
    return b;
}


int main(){
    int n, m, i, x, a, b, res;

    cin >> n >> m;

    animal[1] = 0;
    for(i=2; i<n+1; i++){
        cin >> x;
        animal[i] = x;
    }

    for(i=1; i<=m; i++){
        cin >> a >> b;

        res = findPar(a, b);
        if(res == -1){
            res = findPar(b, a);
        }
        cout << res << "\n";
    }

}