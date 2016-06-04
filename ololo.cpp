#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

vector<long long> nums;


int find() {
	sort(nums.begin(),nums.end());
	int f=0;
	int last=nums.size()-1;
	int l=last;
	int m;
	while(f!=l) {
		m=(f+l)/2;
		if(m%2==0) {
			if(m-1 > -1 && nums[m] == nums[m-1])
				l=m-1;
			else if(m+1<=last && nums[m] == nums[m+1])
				f=m+1;
			else  {
				break;
			}
		} else {
			if(m+1 <= last && nums[m] == nums[m+1])
				l=m-1;
			else if(m-1 > -1 && nums[m] == nums[m-1])
				f=m+1;
			else {
				break;
			}
		}
	}
	m=(f+l)/2;
	cout<<nums[m];
	return 0;
}

int main() {
	int n;
	cin>>n;
	while(n--) {
		long long t;
		scanf("%lld",&t);
		nums.push_back(t);
	}
	find();
	return 0;
}
