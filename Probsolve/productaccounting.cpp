#include <bits/stdc++.h>

using namespace std;

map<int, int> stock;

int main(){
    int m, key, num, i, op;

    cin >> m;
    for (i=0; i<m; i++){
        cin >> op;
        if (op == 1){
            cin >> key >> num;
            stock[key] += num;
        }
        if (op == 2){
            cin >> key;
            cout << stock[key] << "\n";
        }
        if (op == 3){
            cin >> key >> num;
            if (stock[key]<num){
                cout << stock[key] << "\n";
                stock[key] = 0;
                continue;
            }
            stock[key] -= num;
            cout << num << "\n";
        }
    }
}