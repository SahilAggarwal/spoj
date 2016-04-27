#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

void check() {
	vector<int> inverse(nums.size(),-1);
	int flag=0;
	for(int i=0;i<nums.size();i++) {
		int iv = nums[i] - 1;
		inverse[iv] = i+1;
		if(inverse[iv] != nums[iv]) {
			flag=1;
			cout<<"not ambiguous\n";
			break;
		}
	}

	if(!flag) {
		cout<<"ambiguous\n";
	}
}

int main() {
	int n;
	while(1) {
		cin>>n;
		if(n==0)
			break;
		for(int i=0;i<n;i++) {
			int num;
			cin>>num;
			nums.push_back(num);
		}
		check();
		nums.clear();
	}
	return 0;
}
