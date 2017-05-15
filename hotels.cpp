#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;
int m;
long long get() {
	long long sum=0;
        long long max=0;
        
        int s=0;
        for(int i=0;i<v.size();i++) {
            sum += v.at(i);

            if(sum>m) {
                while (sum > m && s<i) {
                    sum -= v.at(s);
                    s++;
                }
                if(sum > max && sum<=m) {
                    max = sum;
                }
            } else if(sum > max) {
                max = sum;
            }

            if(max==m)
                break;
        }
        return max;
}

int main() {
	int n;
	scanf("%d", &n);
        scanf("%d", &m);
        
	for(int i=0;i<n;i++){
        	int t;
		scanf("%d",&t);
                v.push_back(t);
	}

        printf("%lld",get());
}
