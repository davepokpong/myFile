#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int, int> likemax;
    int n, i, max=0, pos, like;
    
    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%d", &like);
        likemax[like]++;
        
        if (likemax[like]>=max){
            max = likemax[like];
            pos = like;
        }
        
        printf("%d\n", pos);
    }

}