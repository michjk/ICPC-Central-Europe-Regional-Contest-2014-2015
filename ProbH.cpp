#include<bits/stdc++.h>
using namespace std;
#define zero(n) memset(n,0,sizeof(n))
#define init(n) memset(n,-1,sizeof(n))
#define REP(i,n) for(i=0;i<n;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORD(i,a,b) for(i=a;i>=b;i--)
#define FOR2(i,a,b,c) for(i=a;i<=b;i+=c)
#define FORD2(i,a,b,c) for(i=a;i>=b;i-=c)
#define PB push_back
#define INF 1e9
map<int, vector<int> > Adj;

void initz(){
	Adj[1].PB(1); Adj[1].PB(2); Adj[1].PB(4);
	Adj[2].PB(2); Adj[2].PB(3); Adj[2].PB(5);
	Adj[3].PB(3); Adj[3].PB(6);
	Adj[4].PB(4); Adj[4].PB(5); Adj[4].PB(7); 
	Adj[5].PB(5); Adj[5].PB(6); Adj[5].PB(8); 
	Adj[6].PB(6); Adj[6].PB(9); 
	Adj[7].PB(7); Adj[7].PB(8);
	Adj[8].PB(8); Adj[8].PB(9); Adj[8].PB(0);
	Adj[9].PB(9);
	Adj[0].PB(0); 
}

char str[4];
char ans[4];
vector<int> stac;

int main(){
	initz();
	int t, u,v,cur, next,choice,c,i,j,k,diff;
	scanf("%d",&t);
    getchar();
	while(t--){
		gets(str);
        zero(ans);
        
        if((int)strlen(str) == 3 && str[1] == '0' && str[2]-'0' > 5) 	strcpy(str,"110");
        if((int)strlen(str) == 2 && str[0] == '6' && str[1]-'0' <= 2)
			strcpy(str,"59");
        if((int)strlen(str) == 3 && str[0] == '1' && str[1] == '6' && str[2]-'0' <= 2)
			strcpy(str,"159");
			
		if((int)strlen(str) == 2 && str[0] == '9' && str[1]-'0' <= 4)
			strcpy(str,"89");
        if((int)strlen(str) == 3 && str[0] == '1' && str[1] == '9' && str[2]-'0' <= 4)
			strcpy(str,"189"); 
        
        if((int)strlen(str) == 2 && str[0] == '3' && str[1] == '0')
			strcpy(str,"29");
        if((int)strlen(str) == 3 && str[0] == '1' && str[1] == '3' && str[2] == '0')
			strcpy(str,"129"); 
        
        ans[0] = str[0];
		cur = str[0] - '0';
		FOR(i,1,(int)strlen(str)-1){
			next = str[i] - '0';
			diff = INF;
			c = -1;
            
			stac.clear();
			stac.PB(cur);
			
            set<int> visited; visited.clear();
            
            while((int)stac.size() > 0){
				u = stac[(int)stac.size()-1];
				stac.pop_back();
                for(auto s: Adj[u]){
					if(abs(s-next) < diff){
						diff = abs(s-next);
						c = s;
					}
					if(visited.count(s) == 0) stac.PB(s);
                    visited.insert(s);
				}
			}
            
			cur = c;
			ans[i] = (char)(cur + '0');
		}
		printf("%s\n",ans);
	}
	return 0;
}
