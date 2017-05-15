#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <map>
#include <vector>
#include <queue>


using namespace std;

bool isBipart(map<int,vector<int> > g, int n) {
	int *col = (int *)malloc(sizeof(int)*n);
	memset(col,-1,sizeof(int)*n);

	queue<int> q;

	q.push(0);
	col[0] = 1;

	while(q.size() != 0) {
	    int t = q.front();
	    q.pop();

            if(g.find(t) != g.end()) {
                vector<int> nodes = g.find(t)->second;

                for (int i = 0; i < nodes.size(); i++) {
                    if (col[nodes[i]] == -1) {
                        col[nodes[i]] = 1 - col[t];
                        q.push(nodes[i]);
                    } else if (col[nodes[i]] == col[t]) {
                        return false;
                    }
                }
                g.erase(t);
            }

            if(q.size() == 0 && g.size() > 0) {
                col[g.begin()->first] = 1;
                q.push(g.begin()->first);
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

		map<int,vector<int> > g;
		for(int j=0;j<m;j++) {
			int a,b;
			scanf("%d",&a);
			scanf("%d",&b);

			if(g.find(a-1) != g.end()) {
				g.find(a-1)->second.push_back(b-1);
			} else {
			    vector<int> v;
			    v.push_back(b-1);
			    g.insert(std::pair<int,vector<int> >(a-1,v));
			}

			if(g.find(b-1) != g.end()) {
            				g.find(b-1)->second.push_back(a-1);
            			} else {
            			    vector<int> v;
            			    v.push_back(a-1);
            			    g.insert(std::pair<int,vector<int> >(b-1,v));
            			}

		}

		printf("Scenario #%d:\n",i+1);
		if(!isBipart(g,n)) {
			printf("Suspicious bugs found!\n");
		} else {
        		printf("No suspicious bugs found!\n");
		}	
	}
}
