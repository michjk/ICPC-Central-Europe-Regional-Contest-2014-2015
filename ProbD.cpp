#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

int main()
{
	int t;
	int n;
	int x[1001], y[1001],r[1001];
	bool touch[1001][1001];
		
	vector<int> connect[1001];
	
	scanf("%d",&t);
	
	REP(i,1,t)
	{
		scanf("%d",&n);
		
		memset(touch,0,sizeof(touch));
			
		REP(j,0,n-1)
		{
			scanf("%d%d%d",&x[j],&y[j],&r[j]);
			
			REP(k,0,j)
			{
				if (touch[j][k] || touch[k][j]) continue;
				if ( (x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j])==r[j]+r[k] )
				{
					touch[k][j]=1;
					touch[j][k]=1;
					connect[j].push_back(k);
					connect[k].push_back(j);
				}
			}
		}
		
		queue<int> q; map<int,pair< int,int> > rot; 
		q.push(0); rot[0] = 1;
		int
		
		
		while (!q.empty()) {
			int u = q.front(); 
			q.pop(); 
			printf("Visit %d, Layer %d\n", u, dist[u]);
			
			TRvii (AdjList[u], v) // for each neighbours of u
				if (!dist.count(v->first)) { // dist.find(v) != dist.end() also works
					dist[v->first] = dist[u] + 1; // if v not visited before + reachable from u
					q.push(v->first); // enqueue v for next steps
				} 		
		}
		
		
			
	}
	
	
	
}
