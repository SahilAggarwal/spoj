#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 1000000

long long memory[MAX] = {0};

long long getMaxDollars(long long n) {
	if(n == 0) {
		return 0;
	}

	if(n<MAX) {
		if(memory[n] != 0) {
			return memory[n];
		}
	}
	long long c1=getMaxDollars(n/2);
	long long c2=getMaxDollars(n/3);
	long long c3=getMaxDollars(n/4);
	long long sum=c1+c2+c3;
	if(sum > n) {
		if(n<MAX) {
			memory[n] = sum;
		}
		return sum;
	}
	if(n<MAX) {
		memory[n] = n;
	}
	return n;
}

int main() {
	long long n;
	while(scanf("%ld",&n) != EOF) {
		printf("%lld\n",getMaxDollars(n));
	}
	return 0;
}
