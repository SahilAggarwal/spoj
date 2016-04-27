#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[10010];
bool vis[10010];
queue<int> q;
vector<int> dist(10010,0);
int n;

void bfs(int u) {
	int last=-1;
	q.push(u);
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		vis[f] = 1;
		for(int i=0;i<tree[f].size();i++) {
			if(!vis[tree[f][i]])
				q.push(tree[f][i]);
		}
		if(q.empty())
			last=f;
	}
	memset(vis,0, sizeof(vis));
	
	//cout<<last<<"\n";
	q.push(last);
	int ans = 0;
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		vis[f] = 1;
		for(int i=0;i<tree[f].size();i++) {
			if(!vis[tree[f][i]]) {
				q.push(tree[f][i]);
				dist[tree[f][i]] = dist[f] + 1;
			}
		}
		if(q.empty()) {
			ans = dist[f];
		}
		
	}
	cout<<ans<<"\n";

}

int main() {
	cin>>n;
	while(n>1) {
		int a,b;
		cin>>a;
		cin>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		n--;
	}
	bfs(1);
	return 0;
}

