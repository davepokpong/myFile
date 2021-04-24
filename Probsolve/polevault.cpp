#include <bits/stdc++.h>

using namespace std;

set<long long> s;
set<long long>::iterator it;
long long wood[100001];

int main(){
    long long n, q, i, j, tmp, num;

    scanf("%lld %lld", &n, &q);
    for(i=1; i<=n; i++){
        scanf("%lld", &wood[i]);
    }

    for (i=1 ;i<=n; i++){
        s.insert(wood[i]);

        tmp = wood[i];
        for (j=i+1; j<=n; j++){
            tmp += wood[j];
            s.insert(tmp);
        }
    }

    for (i=0; i<q; i++){
        scanf("%lld", &num);

        it = s.lower_bound(num);
        if(*it == num) printf("Y");
        else printf("N");
    }
    printf("\n");

}