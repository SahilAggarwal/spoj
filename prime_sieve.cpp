#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX 100000
#define MAX_INTERVAL 100000

using namespace std;
int no;

int prime_nos[MAX];

void find_primes() {
	bool primes[MAX];
	memset(primes, 1, sizeof primes);
	
	primes[0] = false;
	primes[1] = false;
	primes[2] = true;

	for(int i = 2; i <= MAX; ++i) {
		if(primes[i]) {
			for(int j = i + i; j <= MAX; j += i)
				primes[j] = false;
		}
	}

	no = 0;
	for(int i = 2;i <= MAX; ++i) {
		if(primes[i]) {
			prime_nos[no] = i;
			no++;
		}
	}
}

int main() {
	find_primes();
	int t,m,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d", &m, &n);
		bool primeinterval[MAX_INTERVAL];
		memset(primeinterval, 1, sizeof primeinterval);
		if(m==0) {
			primeinterval[0] = false;
			if(n - m > 1) primeinterval[1] = false;
		}
		
		if(m==1) primeinterval[0] = false;
		
		for(int i = 0; i < no; ++i) {
			int prime = prime_nos[i];
			if((prime^2) > n) break;
			int j = m / prime;
			if (j < 2) j = 2;
			for(;;) {
				int next_non_prime = prime*j;
				if(next_non_prime > n) break;
				if(next_non_prime >= m)
					primeinterval[next_non_prime - m] = false;
				j++;
			}	
		}
		for(int i = m; i <= n; i++) {
			if(primeinterval[i - m])
				cout << i << "\n";
		}
	printf("\n");
	}
}
