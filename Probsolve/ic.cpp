#include <bits/stdc++.h>

using namespace std;

int main(){
    list<int> list1;
    list<int>::iterator pos;
    int m, i, num, n;
    char op[2];

    cin >> m;
    for (i=0; i<m; i++){
        cin >> op;
        if (strcmp(op,"li") == 0){
            cin >> num;
            list1.push_front(num);
        }
        else if (strcmp(op,"ri") == 0){
            cin >> num;
            list1.push_back(num); 
        }
        else if (strcmp(op,"lr") == 0){
            pos = list1.begin();
            n = *pos;
            list1.push_back(n);
            list1.pop_front();
        }
        else{
            n = list1.back();
            list1.push_front(n);
            list1.pop_back();
        }
        for (pos=list1.begin(); pos!=list1.end(); pos++){
        cout << *pos << "\n";
    }
    }

    for (pos=list1.begin(); pos!=list1.end(); pos++){
        cout << *pos << "\n";
    }
}