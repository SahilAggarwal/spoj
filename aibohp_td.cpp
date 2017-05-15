#include <iostream>
#include <cstring>
#include <assert.h>
#include <algorithm>

using namespace std;

int dp[6110][6110];

long long c=0;

char s[6110];

int get(int a,int b) {
  c++;
  
  int m;
  int l = b-a+1;
  if(l < 2) {
    m = 0;
  }
  else if(s[a] == s[b]) {
    if(dp[a+1][b-1] != -1)
      m=dp[a+1][b-1];
    else
      m = get(a+1,b-1);
  }
  else {
    int m1,m2;
    if(dp[a][b-1] != -1)
      m1=dp[a][b-1];
    else
      m1=get(a,b-1);

    if(dp[a+1][b] != -1)
      m2=dp[a+1][b];
    else
      m2=get(a+1,b);
    m = min(m1,m2);
    m++;  
  }
  dp[a][b]=m;
  return m;
}

int main() {
  int t;
  cin>>t;
   while(t--) {
    memset(dp,-1,sizeof(dp));
    scanf("%s",&s[0]);
    printf("%d\n",get(0,strlen(s)-1));
  }
}

