#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, chk;

    cin >> n;
    if (n==1) {
        cout << "0" << "\n";
        return 0;
    }
    int sum=1, next_kee=3, floor=0;
    
    while (n>sum){
        sum += next_kee;
        next_kee += 2;
        floor++;
        //cout <<sum << "\n";
    }

    //cout << "floor: " << floor << "\n";

    sum-=next_kee;
    if ((n-sum)%2!=0) chk = 0; //หงาย
    else chk = 1; //คว่ำ
    //cout << "chk: " << chk << "\n";

    if (chk==0) cout << 2*floor << "\n";
    else cout << 2*floor-1 << "\n";
}