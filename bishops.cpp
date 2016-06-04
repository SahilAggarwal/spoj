#include <iostream>
#include <string>

using namespace std;

string n;

int getMax() {
	if(n.size()==1 && n[0]=='1') {
		cout<<"1\n";
		return 0;
	}

	string ans(n.size(),'0');
	int carry=0;

	int li = n.size()-1;
	int last = n[li] - '0';
        if(last>0){
                last=last-1;
                n[li] = '0' + last;
        } else {
		while(last==0){
			n[li] = '9';
			li--;
			last=n[li] - '0';
		}
		n[li] = '0' + (last-1);
	}

	for(int i=n.size()-1;i>=0;i--){
		int n1=n[i] - '0';
		int t = n1*2 + carry;
		carry=0;
		ans[i]='0' + t%10;
		carry=t/10;
	}
	if(carry>0){
		ans.insert(0,1,'0'+carry);
	}
	cout<<ans<<"\n";
	return 0;
}

int main() {
	int t=1024;
	while(t--) {
		cin>>n;
		getMax();
	}
	return 0;
}
