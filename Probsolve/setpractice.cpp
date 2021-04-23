#include <bits/stdc++.h>

using namespace std;

set<int> s;
set<int>::iterator it1, it2, it3;
int res[100001];

int main(){
    int n, m, i, num;

    cin >> n >> m;
    for (i=0; i<n; i++){
        cin >> num;
        s.insert(num);
    }
    
    for (i=0; i<m; i++){
        cin >> num;
        
        it1 = s.lower_bound(num);
        it2 = it1;
        it2--;
        // it3 = it1;
        // it3++;
        if (abs(num-*it1)<abs(num-*it2)) res[i] = *it1;
        else res[i] = *it2;
    }
    for (i=0; i<m; i++){
        cout << res[i] << "\n";
    }
    
}
//upper >
//lower >=