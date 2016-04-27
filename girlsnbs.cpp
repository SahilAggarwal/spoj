#include <iostream>
#include <queue>

using namespace std;
queue<int> temp;
int g,b;

int getMin() {
	if(g==0 && b==0) {
		cout<<0<<"\n";
		return 0;
	}
	if(g==0) {
		cout<<b<<"\n";
		return 0;
	}
	if(b==0) {
		cout<<g<<"\n";
		return 0;
	}
	if(g==b) {
		cout<<1<<"\n";
		return 0;
	}

	int max, min;
	if(b>g) {
		max=b;
		min=g;
	} else {
		min=b;
		max=g;
	}

	int ans=0;
	ans=max/(min+1);
	int left = max - (ans*(min+1));
	if(left>0) {
		ans++;
	}
	cout<<ans<<"\n";
	return 0;
}


int main() {
	cin>>g;
	cin>>b;
	while(g!=-1 && b!=-1) {
		getMin();
		cin>>g;
		cin>>b;
		temp = queue<int>();
	}
	return 0;
}
