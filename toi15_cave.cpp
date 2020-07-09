#include<bits/stdc++.h>
using namespace std;
int n,p,u,e,q,r,t,l,h,arr[2005][2005],dist,node,pass,new_dist,new_node,mi;
vector<pair<int,int> > v[2005];
typedef pair<pair<int,int>,int> pa;
priority_queue<pa,vector<pa>,greater<pa> > pq;
int main(){
	scanf("%d%d%d%d",&n,&p,&u,&e);
	for(int i=1;i<=e;i++){
		scanf("%d%d%d",&q,&r,&t);
		v[q].push_back(make_pair(r,t));
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			arr[i][j] = 1e9;
		}
	}
	//dis pass node
	pq.push(make_pair(make_pair(0,0),p));
	arr[p][0] = 0;
	while(!pq.empty()){
		dist = pq.top().first.first;
		pass = pq.top().first.second;
		node = pq.top().second;
		pq.pop();
		for(int i=0;i<v[node].size();i++){
			new_node = v[node][i].first;
			new_dist = dist + v[node][i].second;
			if(arr[new_node][pass+1] > new_dist){
				arr[new_node][pass+1] = new_dist;
				pq.push(make_pair(make_pair(new_dist,pass+1),new_node));
			}
		}
	}
	scanf("%d",&l);
	for(int i=1;i<=l;i++){
		scanf("%d",&h);
		mi = 2e9;
		for(int j=1;j<=n;j++){
			mi = min(mi,arr[u][j]+(j-1)*h);
		}
		printf("%d ",mi);
	}
}
