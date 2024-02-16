#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
    int n,m;
    int X[21],A[21];
    int t = 0, res = 0, r = 0;
    void inp(){
        scanf("%d %d", &n, &m);
        for ( int i = 1 ; i <= n ; i++ ){
            scanf("%d",&A[i]);
        }
    }
	void PrintSolution(){
		res++;
		for ( int i = 1 ; i <= n ; i++ ){
			printf("%d ",X[i]);
		}
		printf("\n"); 
	}
	bool check(int v, int k){
		if ( k < n ) return true;
		else {
			if ( t + A[n]*v == m ) return true;
			return false;
		}
	}
	void Try( int k ){
		for ( int v = 1 ; v <= (m-t-r)/A[k] ; v++ ){
			if (check(v,k)){
				X[k] = v;
				t = t + A[k]*X[k];
				r = r - A[k+1];
				if (k == n) PrintSolution();
				else Try(k+1);
				t = t - A[k]*X[k];
				r = r + A[k+1];
			}
		}
	}
	int main(int argc, const char** argv){
		inp();
		for ( int i = 2 ; i <= n ; i++ ){
			r = r + A[i];
		}
		Try(1);
		printf("\n%d",res);
		return 0;
	}
	
