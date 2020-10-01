#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
ll n=0,m=0,a,b;
vector<ll> tr[300005];
ll val[300005]={0};
bool vis[300005][2];
void pre()
{
	f(i,0,n+2)
	{
		tr[i].clear();
		val[i]=0;
		vis[i][0]=0;
		vis[i][1]=0;
	}
}

void dfs(ll a1, ll ch, ll su)
{
	if(vis[a1][ch]==1) return;
	vis[a1][ch] = 1;
	val[a1]+=su;
	f(i,0,tr[a1].size())
	{
		dfs(tr[a1][i],ch,su);
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    while(t--)
    {
    	pre();
    	cin>>n>>m>>a>>b;
    	ll x,y;
    	f(i,0,m)
    	{
    		cin>>x>>y;
    		tr[x].pb(y);
    		tr[y].pb(x);
    	}
    	vis[b][0] = 1;
    	vis[a][1] = 1;
    	val[a] = 15;
    	val[b] = 15;

    	dfs(a,0,1);
    	dfs(b,1,3);

    	ll co1 = 0 , co2 = 0;

    	f(i,1,n+1)
    	{
    		if(val[i]==1) co1++;
    		else if(val[i]==3) co2++;
    	}

    	cout<<co1*co2<<endl;
    }
    
    
return 0;
}

ll exp(ll a,ll b,ll m)
{
	if(b==0)
	{
		return 1;
	}
	ll temp =exp(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)
	{
		return (temp*(a%m))%m;
	}
	return temp;
}
