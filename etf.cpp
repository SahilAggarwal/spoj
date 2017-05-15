#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> primes;

void get_primes() {
  int n=1000;
  int t[1000];
  memset(t,1,sizeof(t));
  t[0]=0; t[1]=0;
  for(int i=2;i<=1000;i++) {
    if(t[i]) {
      primes.push_back(i);
      for(int j=i;j<=1000;j=j+i){
	t[j]=0;
      }
    }
  }
}

long long get_totient(long long n) {
  int p = primes[0];
  long long ans=n;
  int pi=0;
  if(n==1){
    return 1;
  }
  while(n!=1 && (p*p<=n)) {
    if(n%p==0) {
      ans=ans-(ans/p);
    }
    while(n%p==0) n=n/p;
    pi++;
    p=primes[pi];
  }
  if(n!=1){
    ans = ans - (ans/n); 
  }
  return ans;
}

int main() {
  get_primes();
  int t;
  cin>>t;
  while(t--) {
    long long n;
    scanf("%lld",&n);
    printf("%lld\n",get_totient(n));
  }
}
