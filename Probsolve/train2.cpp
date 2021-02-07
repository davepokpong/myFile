#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a, num1, num2, i;
    char op;
    list<long long> plat[100001];

    cin >> a;
    for (i=0; i<a; i++){
        cin >> op >> num1 >> num2;
        if (op == 'N'){
            plat[num2].push_back(num1);
        }else{
            auto p = plat[num2].end();
			plat[num2].splice(p, plat[num1]);
        }
    }

    for (i=0; i<100001; i++){
        for (auto pos = plat[i].begin(); pos != plat[i].end(); pos++){
		cout << *pos << '\n';
		}
	}

}