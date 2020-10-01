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
vector<ll> tr[100001];

vector<ll> sb;

void dfs(ll a, ll p)
{
	sb.pb(a);

	f(i,0,tr[a].size())
	{
		if(tr[a][i]!=p) dfs(tr[a][i],a);
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;
    ll c[n+1][3];

    f(i,0,3)
    {
    	f(j,1,n+1) cin>>c[j][i];
    }
    ll co[n+1]={0};
    ll x,y;
    f(i,0,n-1)
    {
    	cin>>x>>y;
    	tr[x].pb(y);
    	tr[y].pb(x);
    	co[x]++;
    	co[y]++;

    	if(co[x]>=3 || co[y]>=3)
    	{
    		cout<<-1<<endl;
    		return 0;
    	}
    }

    ll st = 0;
    f(i,1,n+1)
    {
    	if(co[i]==1)
    	{
    		st = i;
    		 break;
    	}
    }

    dfs(st,0);
   	ll sz = sb.size();
   	if(sz!=n)
   	{
   		cout<<-1<<endl;
   		return 0;
   	}

   	ll dp[sz+1][3];
   	memset(dp,-1,sizeof(dp));
   	dp[0][0]=0;
   	dp[0][1]=0;
   	dp[0][2]=0;

   	dp[1][0]=c[st][0];
   	dp[1][1]=c[st][1];
   	dp[1][2]=c[st][2];


   	f(i,1,sz)
   	{
   		ll ind = sb[i];

   		f(j,0,3)
   		{
   			f(k,0,3)
   			{
   				if(j==k) continue;
   				ll z = 6 - (j+1) - (k+1) -1;

   				if(dp[i+1][z]==-1)
   				{
   					dp[i+1][z] = dp[i][j] + dp[i-1][k] + c[ind][z]; 
   				}

   				else
   				{
   					dp[i+1][z] = min( dp[i+1][z],dp[i][j] + dp[i-1][k] + c[ind][z]); 
   				}
   			}
   		}
   	}

   	cout<<min(dp[sz][0],min(dp[sz][1],dp[sz][2]))<<endl;
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
