#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

string s1,s2;
int score[2010][2010];

int getDist() {
	int size1=s1.length();
	int size2=s2.length();

	memset(score,-1, sizeof(score));
	
	score[0][0] = 0;
	for(int i=0;i<=size1;i++) {
		for(int k=0;k<=size2;k++) {
			if(i==0) {
				score[i][k]=k;
			} 
			else if(k==0) {
				score[i][k]=i;
			} else {
				int cost= s1[i-1] != s2[k-1] ? 1 : 0;
				int fromUp = score[i-1][k] + 1;
				int fromLeft = score[i][k-1] + 1;
				int fromDiagnal = score[i-1][k-1] + cost;
				score[i][k] = min(fromUp, min(fromLeft, fromDiagnal));
			}
//			cout<<score[i][k]<<" ";
		}
//		cout<<"\n";
	}
        int ans = score[size1][size2] ;
        assert( ans >= 0 && ans <= max(size1,size2));
	cout<<score[size1][size2];
	return 0;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>s1;
		cin>>s2;
		getDist();
		cout<<"\n";
	}
	return 0;
}
