#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1000000010;
vector<long long> h; 

long long get_min(int n,int k){
  long long min=MAX;
  k=k-1;
  for(int i=0;i+k<n;i++){
    int t=h[i+k]-h[i];
    if(t<min)
      min=t;
  }
  return min;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    h.clear();
    scanf("%d",&n); scanf("%d",&k);
    for(int i=0;i<n;i++){
      int p;
      scanf("%d",&p);
      h.push_back(p);
    }
    sort(h.begin(),h.end());
    printf("%lld\n",get_min(n,k));
 }
}
