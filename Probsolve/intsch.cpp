#include <bits/stdc++.h>

using namespace std;

set<pair<int,int>> timee;
set<pair<int,int>>::iterator p;

int main() {
    int n, start, end, count=1, temp;

    cin >> n;
    for (int i=0; i<n; i++){
        
        cin >> start >> end;
        timee.insert(make_pair(end, start));
    }
    // p = timee.begin();
    for (p=timee.begin(); p!=timee.end(); p++){

        if (p==timee.begin()){
            temp = p->first;
            continue;
        }

        if (temp > p->second){
            continue;
        }

        count++;
        // cout << p->second << "\n";
        temp = p->first;
    }

    cout << count << "\n";
}   