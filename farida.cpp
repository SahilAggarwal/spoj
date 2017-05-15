#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <assert.h>

using namespace std;

vector<long long> coins;

unsigned long long dp[10010];

unsigned long long get(int i) {
  assert(i<=10000);
  
  if(i<0)
    return 0;

  if(dp[i] != -1)
    return dp[i];

  unsigned long long m;
  unsigned long long m1=coins[i] + get(i-2);
  unsigned long long m2=get(i-1);
  m = max(m1,m2);
  dp[i] = m;
  return m;
}

int main() {
  int t;
  cin>>t;
  int ti=1;
  while(ti<=t) {
    coins.clear();
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      long long c;
      cin>>c;
      coins.push_back(c);
    }
    cout<<"Case "<<ti<<": "<<get(coins.size()-1)<<"\n";
    ti++;
  }
  return 0;
}
