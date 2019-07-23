// TravellingSMan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int map[15][15];
int dp[(1<<12)+5][12];

int main() {
    int i,j,n,ans,k,p;
    while(1) {
        //scanf("%d",&n);
		cin>>n;
 
		
		for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                //scanf("%d",&map[i][j]);
				cin>>map[i][j];
            }
        }
        
		//floyd algorithm, get any two points's minimum distance
        for (k=0; k<n; k++) {
            for (i=0; i<n; i++) {
                for (j=0; j<n; j++) {
                    if (i!=j && i!=k && j!=k) map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        dp[1][0]=0;
        // TSP solution here,bitmask and DP
        for (i=1; i<(1<<n); i++) {// the current state
            for (j=0; j<n; j++) {// during the current state,the last station is j
                if (dp[i][j]==-1) continue;
                for (k=1; k<n; k++) {//the next state is k
                    if ((i & (1<<k))!=0) continue;
                    p=(i | (1<<k));// the new state(join k)
                    if (dp[p][k]==-1) dp[p][k]=dp[i][j]+map[j][k];
                    dp[p][k]=min(dp[p][k],dp[i][j]+map[j][k]);
                }
            }
        }
        ans=INT_MAX;
        // get answer
        for (i=1; i<n; i++) {
            if (dp[(1<<n)-1][i]>0) ans=min(ans,dp[(1<<n)-1][i]+map[i][0]);
        }
        //printf("%d\n",ans);
		cout<<endl<<ans;
    }
    return 0;
}


