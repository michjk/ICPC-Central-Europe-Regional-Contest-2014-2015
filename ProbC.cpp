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
	int n;
	int x;
	int res1, res2;
		
	scanf("%d",&n);
	REP (i,1,n)
	{
		scanf("%d",&x);
		
		res1 = 0;
		res2 = 0;
			
		REP(j,2,x)
		{
			if ((2*x-j*j+j)%(2*j)==0)
			{
				res1= (2*x-j*j+j)/(2*j);
				res2= res1+j-1;
				break;
			}
		}
		
		if (res1==0 || res2==0)
			printf("IMPOSSIBLE\n");
		else
		{
			printf("%d = ", x);
			REP(j,res1,res2)
			{
				printf("%d",j);
				if (j < res2)
					printf(" + ");
			}
			printf("\n");
		}
	}
	return 0;
	
	
}
