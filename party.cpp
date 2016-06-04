#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int am,c;
int  p[102][2];

pair<int,int> dp[502][102];

pair<int,int> getMax(int amt, int i) {
	pair<int,int> ans(0,0);
	if(amt<5)
		return ans;
	if(dp[amt][i].first != -1)
		return dp[amt][i];
	for(int j=i;j<c;j++) {
		pair<int,int> f(0,0);
		if(amt>=p[j][0]) {
			int t=p[j][1];
			pair<int,int> pp=getMax(amt-p[j][0],j+1);
			f.first = p[j][0] + pp.first;
			f.second = p[j][1] + pp.second;
		} else {
			f = getMax(amt,j+1);
		}
		if(ans.second==f.second) {
		 	if(ans.first>f.first)
				ans=f;
		} else if(f.second>ans.second) {
			ans = f;
		}
	}
	dp[amt][i] = ans;
	return ans;
}

int main() {
	cin>>am;cin>>c;
	while(am || c) {
		for(int i=0;i<c;i++) {
			int t1,t2;
			cin>>t1;cin>>t2;
			p[i][0] = t1;p[i][1] = t2;
		}
		memset(dp,-1,sizeof dp);
		pair<int,int> ans = getMax(am,0);
		cout<<ans.first<<" "<<ans.second<<"\n";
		cin>>am;cin>>c;
	}
	return 0;
}
