#include <iostream>
#include <vector>
using namespace std;

int base;
long long idx;
vector<int> lasts;

int getNum() {
	if(base==0)
		return 0;
	else if(idx==0)
		return 1;
	else {
		int last=base%10;
		int firstLast=last;
		lasts.push_back(last);
		while(1) {
			last=(last*base)%10;
			if(firstLast==last)
				break;
			lasts.push_back(last);
		}
		int t;
		t=idx%lasts.size();
		if(t==0)
			t=lasts.size()-1;
		else
			t=t-1;
		return lasts[t];
	}
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>base;
		cin>>idx;
		lasts.clear();
		cout<<getNum()<<"\n";
	}
	return 0;
}
