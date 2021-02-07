#include <bits/stdc++.h>

using namespace std;

list<int> dna;
list<int>::iterator virus;

int main(){
    int N, n, m, i, op, j;
    long long x;

    cin >> N >> m;
    for (i=0; i<N; i++){
        cin >> n;
        dna.push_back(n);
    }
    virus = dna.begin();

    for (i=0; i<m; i++){
        cin >> op;
        if (op==1) virus = dna.begin();
        if(op==2){
            if (virus==dna.end()) virus = dna.begin();
            virus++;
        }
        if(op==3){
            cin >> x;
            dna.insert(virus, x);
        }if(op==4){
            cin >> x;
            virus++;
            dna.insert(virus, x);
            for (j=0; j<2; j++){
                virus--;
            }
        }
    }

    //cout << *virus << "\n";

    for (virus=dna.begin(); virus!=dna.end(); virus++){
        cout << *virus << "\n";
    }

}