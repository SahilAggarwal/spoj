#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <map>
#include <vector>
#include <queue>


using namespace std;

int g[2000][2000];

bool isBipart(int n) {
	int *col = (int *)malloc(sizeof(int)*n);
	memset(col,-1,sizeof(int)*n);

	queue<int> q;

	q.push(0);
	col[0] = 1;

	while(q.size() != 0) {
	    int t = q.front();
	    q.pop();

        for(int i=0;i<n;i++) {
            if(g[t][i] && col[i] == -1) {
                col[i] = 1-col[t];
                q.push(i);
            } else if(g[t][i] && col[t] ==col[i]){
                return false;
            }
        }
	}
	return true;
}


int main() {
	int t;
	scanf("%d",&t);

	for(int i=0;i<t;i++) {
		int n,m;
		scanf("%d",&n);
		scanf("%d",&m);

        memset(g,0,sizeof(g[0][0]*2000*2000));

		for(int j=0;j<m;j++) {
			int a,b;
			scanf("%d",&a);
			scanf("%d",&b);
			g[a-1][b-1] =1; g[b-1][a-1]=1;
		}

		printf("Scenario #%d:\n",i+1);
		if(!isBipart(n)) {
			printf("Suspicious bugs found!\n");
		} else {
        		printf("No suspicious bugs found!\n");
		}
	}
}
