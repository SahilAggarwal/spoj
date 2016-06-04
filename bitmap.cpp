#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


int bmap[200][200];
int bfs[200][200];
int vis[200][200];
int n,m;

queue<pair<int,int> > q;
vector<pair<int,int> > v;

void add_near(int i, int j) {
	if(!vis[i-1][j] && (i-1>=0 && j>=0 && i-1<n && j<m))
		q.push(make_pair(i-1,j));
	if(!vis[i+1][j] && (i+1>=0 && j>=0 && i+1<n && j<m))
		q.push(make_pair(i+1,j));
	if(!vis[i][j+1] && (i>=0 && j+1>=0 && i<n && j+1<m))
		q.push(make_pair(i,j+1));
	if(!vis[i][j-1] && (i>=0 && j-1>=0 && i<n && j-1<m))
		q.push(make_pair(i,j-1));	
}

void compute() {
	for(int k=0;k<v.size();k++) {
		memset(vis,0,sizeof(vis));
		pair<int,int> p = v[k];
		int i=p.first; int j=p.second;
		bfs[i][j]=0; vis[i][j]=1;
		add_near(i,j);
		while(!q.empty()) {
			pair<int,int> p = q.front(); q.pop();
			int ii=p.first; int jj=p.second;
			int dist=abs(ii-i) + abs(jj-j);
			vis[ii][jj]=1;
			if(bfs[ii][jj] == -1) {
				bfs[ii][jj]=dist;
				add_near(ii,jj);
			} else if(bfs[ii][jj] > dist) {
				bfs[ii][jj] = dist;
				add_near(ii,jj);
			}	
		}
	}
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		cin>>m;
		v.clear();
		for(int i=0;i<n;i++) {
				string s;
				cin>>s;
				for(int j=0;j<m;j++){
					bmap[i][j] = s[j] - '0';
					if(bmap[i][j]==1)
						v.push_back(make_pair(i,j));				
				}
		}
		memset(bfs, -1, sizeof(bfs));
		compute();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cout<<bfs[i][j];
				if(j<(m-1))
					cout<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
}
