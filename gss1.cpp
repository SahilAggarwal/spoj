#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

struct nd {
	long ls;long rs;long bs;long ts;
};

typedef struct nd node; 

int n;
int a[50010];
node tr[250000];
int q1,q2,tt;

int len;

node combine(node ln, node rn) {
	long left=ln.ls;
	if(ln.ts+rn.ls>left) left=ln.ts+rn.ls;
	long right=rn.rs;
	if(rn.ts+ln.rs>right) right=rn.ts+ln.rs;
	long best=max(ln.rs+rn.ls,max(ln.bs,rn.bs));
	node n;
	n.ls=left;n.rs=right;n.ts=ln.ts+rn.ts;n.bs=best;
	return n;
}

int cr_tree(int i,int l, int r) {
	
	if(l==r) {
		node tn;
		tn.ls=a[l];tn.rs=a[l];tn.ts=a[l];tn.bs=a[l];
		tr[i]=tn;
		return 0;
	}
	int nl = (l+r)/2; int nr = nl+1;
	cr_tree(2*i+1,l,nl);
	cr_tree(2*i+2,nr,r);
	
	node ln=tr[2*i+1];
	node rn=tr[2*i+2];

	//cout<<"\nl:"<<l<<" "<<"r:"<<r<<" "<<"bs:"<<tn.bs<<" "<<"ls:"<<tn.ls<<" rs:"<<tn.ts<<" ts:"<<tn.ts;
	tr[i]=combine(ln,rn);
	return 0;
}

node g_max(int a, int b,int i, int l, int r) {
	if(a==l && b==r)
		return tr[i];
	
	int mid=(l+r)/2;
	if(b<=mid)
		return g_max(a,b,2*i+1,l,mid);
	if(a>mid)
		return g_max(a,b,2*i+2,mid+1,r);
	
	node left = g_max(a,mid,2*i+1,l,mid);
	node right = g_max(mid+1,b,2*i+2,mid+1,r);

	return combine(left,right);
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&tt);
		a[i]=tt;
	}
	len = (int) (2 * (pow(2,floor(log(n)/log(2) +1))));
	cr_tree(0,0,n-1);
//	cout<<"\n";
//	for(int i=0;i<len;i++) {
//		cout<<tr[i].bs<<" ";
//	}
	int m;
        scanf("%d",&m);
	while(m--) {
		scanf("%d",&q1);
		scanf("%d",&q2);
		printf("%ld\n",g_max(q1-1,q2-1,0,0,n-1).bs);
	}
}
