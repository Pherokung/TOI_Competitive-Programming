#include<bits/stdc++.h>
using namespace std;
int n,c[500005],p[500005],mi_tall=2e9;
long long ans=1e18,pos=-1,qs_a[500005],qs_b[500005],val,a,b;
vector<pair<int,int> > v;
#define F first
#define S second 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		mi_tall = min(mi_tall,c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++)
	{
		v.push_back({p[i],c[i]});
	}
	v.push_back({-1,-1});
	sort(v.begin(),v.end());
	for(int i=1;i<v.size();i++)
	{
		a = v[i].F;
		b = v[i].S;
		qs_a[i] = qs_a[i-1] + a;
		qs_b[i] = qs_b[i-1] + b;
	}
	for(int i=1;i<v.size();i++)
	{
		a = v[i].F;
		b = v[i].S;
		if(a > mi_tall)
			break;
		val = (qs_b[i-1] - (a*(i-1) - qs_a[i-1])) + ((qs_a[n] - qs_a[i]) - ((n-i)*a));
		if(val < ans){
			ans = val;
			pos = a;
		}
	}
	printf("%lld %lld",pos,ans);
}
