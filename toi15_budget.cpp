#include<bits/stdc++.h>
using namespace std;
int b,e,s,t,l,r,P[3005],p,c,d,dis[1000005],cost,ans,path=0;
vector<pair<int,pair<int,int> > > v;
vector<pair<int,pair<int,int> > > mst;
int find_(int x){
	if(P[x] == x){
		return x;
	}
	else{
		return P[x] = find_(P[x]);
	}
}
P[1] = 5
P[5] = 3
P[3] = 7;
int union_(int x,int y){
	x = find_(x);
	y = find_(y);
	P[x] = y;
}
int main(){
	scanf("%d%d",&b,&e);
	for(int i=0;i<=b;i++){
		P[i] = i;
	}
	for(int i=1;i<=e;i++){
		scanf("%d%d%d%d",&s,&t,&l,&r);
		if(r == 0){
			v.push_back(make_pair(l,make_pair(s,t)));
		}
		else{
			if(find_(s) != find_(t)){
				union_(s,t);
				path++;
			}
		}
	}
	scanf("%d",&p);
	for(int i=0;i<=1000001;i++){
		dis[i] = 2e9;
	}
	for(int i=1;i<=p;i++){
		scanf("%d%d",&c,&d);
		dis[c] = min(dis[c],d);
	}
	cost = dis[1000001];
	for(int i=1000000;i>=0;i--){
		if(dis[i] >= cost){
			dis[i] = cost;
		}
		else{
			cost = dis[i];
		}
	}
	for(int i=0;i<v.size();i++){
		l = v[i].first;
		s = v[i].second.first;
		t = v[i].second.second;
		mst.push_back(make_pair(dis[l],make_pair(s,t)));
	}
	ans = 0;
	sort(mst.begin(),mst.end());
	for(int i=0;i<mst.size();i++){
		cost = mst[i].first;
		s = mst[i].second.first;
		t = mst[i].second.second;
		if(find_(s) != find_(t)){
			union_(s,t);
			path++;
			ans += cost;
		}
		if(path == b-1){
			break;
		}
	}
	printf("%d",ans);
}
