#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

int h,w;

int tiles[110][110];

int dp[110][110];

int getMax(int r, int c) {
	assert(r>=0 && c>=0 && r<h && c<w);
		if(dp[r][c] != -1) {
			return dp[r][c];
		}

		int m;
		int str=0,left=0,right=0;
		if(r+1<=h)
			str=tiles[r][c] + (r+1<h ? getMax(r+1,c): 0);	
		if(c-1>=0 && r+1<h)
			left = tiles[r][c] + getMax(r+1,c-1);
		if(c+1<w && r+1<h)
			right = tiles[r][c] + getMax(r+1,c+1);

		m = max(str,max(left,right));
		dp[r][c] = m;
		return m;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>h;
		cin>>w;
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				int n;
				cin>>n;
				tiles[i][j] = n;
			}
		}
		memset(dp,-1,sizeof dp);
		int m = 0;
		for(int i=0;i<w;i++) {
			int t= getMax(0,i);
			if(t>m)
				m=t;
		}
		cout<<m<<"\n";
	}
	return 0;
}
