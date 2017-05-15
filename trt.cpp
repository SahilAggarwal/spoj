#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
vector<int> t;

long dp[2005][2005] = {-1};

long compute(int s, int e, int a){
  if(dp[s][e] != -1) {
   return dp[s][e];
  }
  
  if(s==e)
    return a*t[s];

  long ms = a*t[s] + compute(s+1,e,a+1);
  long me = a*t[e] + compute(s,e-1,a+1);
  long m=max(ms,me);
  dp[s][e] = m;
  return m;
} 

int main() {
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    int tt;
    scanf("%d", &tt);
    t.push_back(tt);
  }
  memset(dp,-1, sizeof(dp));
  long ans= compute(0,n-1,1);
  printf("%ld",ans);
  return 0;
}
