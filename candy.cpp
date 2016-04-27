#include <iostream>
#include <vector>
using namespace std;
int total;
vector<int> nums;

void getMovements(int sum) {
	int avg = sum/nums.size();
	if(avg*nums.size() != sum) {
		cout << -1 << "\n";
	} else {
		int mov=0;
		for(int i=0;i<nums.size();i++) {
			if(nums[i] < avg)
				mov += avg-nums[i];
		}
		cout<<mov<<"\n";
	}
}

int main() {
	int t;
	cin>>total;
	int sum = 0;
	while(total != -1)  {
		for(int i=0;i<total;i++) {
			cin>>t;
			sum+=t;	
			nums.push_back(t);
		}
		getMovements(sum);
		nums.clear();
		sum=0;
		cin>>total;
	}
	return 0;
}
