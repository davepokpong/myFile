#include <bits/stdc++.h>

using namespace std;

list<int> cache;
list<int>::iterator p;
int arrayy[1001000] = {0};

int main(){
    int i, j, n, m, c, miss=0, tmp;
    cin >> n >> m;

    for (i=0; i<n; i++){
        cache.push_back(0);
    }
    
    for (i=0; i<m; i++){
        cin >> c;
        if (arrayy[c]==1) continue;
        arrayy[c] = 1;
        
        tmp = cache.front();
        arrayy[tmp] = 0;
        cache.pop_front();
        cache.push_back(c);
        miss++;
        /*
        for (p=cache.begin(); p!=cache.end(); p++){
            cout << *p << "\n";
        }
        cout << "-------" << "\n";
        */
    }

    cout << miss << "\n";
}