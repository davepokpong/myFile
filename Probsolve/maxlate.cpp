#include <bits/stdc++.h>

using namespace std;

list<pair<int,int>> timee;
list<pair<int,int>>::iterator p;
int over[100001];

int main() {
    int n, fin, deadline, dist=0, a=0, max=0;

    cin >> n;
    for (int i=0; i<n; i++){
        
        cin >> deadline >> fin;
        timee.push_back(make_pair(deadline, fin))
    }
    timee.sort();

    for (p=timee.begin(); p!=timee.end(); p++){

        dist += p->second;
        over[a] = dist-(p->first+10);
        a++;
    }

    for (int i=0; i<n; i++){
        
        if(max<over[i]) max=over[i];
    }

    cout << max*1000 << "\n";
}