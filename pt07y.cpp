#include <iostream>
#include <vector>
using namespace std;

bool vis[10010];
vector<int> graph[10010];

void dfs(int u) {
	vis[u] = 1;
	for(int i=0;i<graph[u].size();i++) {
		if(!vis[graph[u][i]])
			dfs(graph[u][i]);
	}
}

int main() {
	int n,m;
	cin>>n;
	cin>>m;
	for(int i=1;i<n;i++) vis[i]=0;
	
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u;
		cin>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bool isTree=true;
	if(m != (n-1))
		isTree=false;
	else {
		dfs(1);
		for(int i=1;i<n;i++) {
			if(!vis[i]) {
				isTree=false;
				break;
			}
		}
		
	}
	isTree? cout<<"YES\n" : cout<<"NO\n";
	return 0;
}
