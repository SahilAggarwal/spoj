#include <iostream>
#include <string>
using namespace std;


string total;
string more;

strig mns(string a,string b) {
	int la=a.length();
        int lb=b.length();
        int ml;
        if(la>lb) {
                b.insert(0,la-lb,'0');
                ml=la;
        } else if(lb>la) {
                a.insert(0,lb-la,'0');
                ml=lb;
        } else {
                ml=lb;
        }
	for(int i=ml;i>=0;i--) {
		x=  a[i] - '0';
                y = b[i] - '0';
	        if(x<y) {
			int t=	
		}	
	}
	
}

/**
 205
  16
*/

string pls(string a,string b) {
	int la=a.length();
	int lb=b.length();
	int ml;
	if(la>lb) {
		b.insert(0,la-lb,'0');
		ml=la;
	} else if(lb>la) {
		a.insert(0,lb-la,'0');
		ml=lb;
	} else {
		ml=lb;
	}
	string ans =string(ml,'0');
	int carry=0;
	for(int i=ml-1;i>=0;i--) {
		int x,y;
		x=  a[i] - '0';
		y = b[i] - '0';
		int temp = x+y + carry;
		if(temp>9) {
			carry=1;
			ans[i] = '0' + temp%10;
		} else {
			carry=0;
			ans[i] = '0' + temp;
		}
	}
	if(carry!=0) {
		ans.insert(0,1,'1');
	}
	return ans;
	
}

void getAns() {
	string kl,nt;
	//nt = divide((minus(total,more)),2);
	//kl = plus(nt,more);
	string ans=pls(total,more);
	cout<<ans;
}

int main() {
	int i=0;
	while(i<1) {
		cin>>total;
		cin>>more;
		getAns();
		i++;
	}
}
