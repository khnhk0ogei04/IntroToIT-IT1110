#include<stdio.h>
#include<math.h>
#include<string.h>
#define ll long long
#define FOR(i,l,r) for ( int i = l ; i <= r ; i++ )
#define FOD(i,l,r) for ( int i = l ; i >= r ; i-- )
    int n,m,X[100],S[100];
    int mp[100];

        void solve(){
        int t;
        scanf("%d", &t);
        while (t--) {
            memset(mp,0,sizeof(mp));
            scanf("%d %d", &n, &m );
            FOR(i,1,m) scanf("%d", &X[i]);
            int j = m;
            while ( j >= 1 && (X[j] == n - m + j) ){
                j--;
            }
            if ( j == 0 ){
                printf("%d", m);
                continue;
            }
            else {
                ll cnt = 0;
                FOR(i,1,j-1) {
                    S[i] = X[i];
                }
                S[j] = X[j] + 1;
                FOR(i,j+1,m) {
                    S[i] = S[i-1] + 1;
                }
                FOR(i,1,m) {
                    mp[X[i]]++;
                    mp[S[i]]++;
                }
               FOR(i,1,n) {
               if (mp[i] == 2) cnt++;
            }
            printf("%d", m - cnt);
        }
    }
        }
        int main(){

            solve();
            return 0;
        }
  
/*
3
5 3
1 3 5
1
5 3
1 4 5
2
7 5
3 4 5 6 7
5
*/