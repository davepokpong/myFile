#include <bits/stdc++.h>

using namespace std;

set<long long> cartoon;
set<long long>::iterator pos;
map<long long, long long> store;

int main(){
    long long n, k, price, money, tmp=0;

    cin >> n >> k;
    for (long long i=1; i<n+1; i++){
        cin >> price;
        tmp += price;
        cartoon.insert(tmp);
        store[tmp] = i;
    }

    for (long long i=1; i<k+1; i++){
        cin >> money;
        cartoon.insert(money);
        pos = cartoon.lower_bound(money);
        if (store[*pos]) {
            cout << store[*pos] << "\n";
            continue;
        }
        pos--;
        cout << store[*pos] << "\n";
        cartoon.erase(money);
    }
}