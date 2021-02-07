#include <bits/stdc++.h>

using namespace std;

int main(){
    float n, a, b, r, x, y, i;
    int count=0;
    
    cin >> n >> a >> b >> r;
    for (i=0; i<n; i++){
        cin >> x >> y;
        if (sqrt(pow((a-x),2)+pow((b-y),2))<=r) count++;
    }

    cout << count << "\n";
}