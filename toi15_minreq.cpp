#include<bits/stdc++.h>
using namespace std;
int n,m,x,L[15],A[15],S[10000005],T[15],Q1[15],Q2[15],dp[1100005],val[15],mx,sum,di;
vector<int> v;
bool minreq(int mask1,int mask2,int lv){
	if(lv == n+1){
		return 1;
	}
	if(dp[(mask1<<n)+mask2] != -1){
		return dp[(mask1<<n)+mask2];
	}
	for(int i=0;i<n;i++){
		if((mask1 & (1<<i)) == 0){
			int new_mask1 = mask1 | (1<<i);
			for(int j=0;j<n;j++){
				if((mask2 & (1<<j)) == 0){
					int new_mask2 = mask2 | (1<<j);
//					printf("%d %d %d %d %d\n",i,j,lv,L[i]-A[j],val[lv]);
					if(L[i+1]-A[j+1] >= val[lv]){
						if(minreq(new_mask1,new_mask2,lv+1)){
							dp[(mask1<<n)+mask2] = 1;
							return 1;
						}
					}
				}
			}
		}
	}
	dp[(mask1<<n)+mask2] = 0;
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&L[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(L[i]-A[j]>0){
				v.push_back(L[i]-A[j]);
			}	
		}
	}
	sort(v.begin(),v.end());
//	qs[0] = 0;
	for(int i=1;i<=m;i++){
		scanf("%d",&S[i]);
//		qs[i] = qs[i-1] + S[i];
	}
	for(int i=1;i<=x;i++){
		scanf("%d",&T[i]);
	}
	for(int i=1;i<=x;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&Q1[j]);
		}
		for(int j=1;j<n;j++){
			Q2[j] = Q1[j+1]-1;
		}
		Q2[n] = m;
		for(int j=1;j<=n;j++){
			mx = 0;
			sum = 0;
			for(int k=Q1[j];k<=Q2[j];k++){
				mx = max(mx,S[k]);
				sum += S[k];
			}
			di = sum / T[i];
			if(sum % T[i] != 0){
				di++;
			}
			val[j] = max(mx,di);
		}
		memset(dp,-1,sizeof dp);
		if(minreq(0,0,1)){
			printf("P\n");
		}
		else{
			printf("F\n");
		}
	}
}
