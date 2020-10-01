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
vector<ll> tr[600001];
ll n = 0;
ll mle = 0;
ll bap = 0;
void dfs(ll a, ll p, ll le)
{
	if(le>=mle)
	{
		mle=le;
		bap = a;

	}

	f(i,0,tr[a].size())
	{
		if(tr[a][i]==p) continue;

		dfs(tr[a][i],a,le+1);
	}
}

ll dfs2(ll a, ll p)
{
	ll mex = 1;
	ll ans1 = 0;
	f(i,0,tr[a].size())
	{
		if(tr[a][i]==p) continue;

		ll mo = dfs2(tr[a][i],a);

		if(mo == 1) ans1++;

		mex = max(mex,mo);
	}

	ans1 += mex + 1 - (mex==1);
	return ans1;

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
    	mle = 0,bap = 1;
    	f(i,0,n+1) tr[i].clear();

    	cin>>n;
    	ll x,y;
    	f(i,0,n-1)
    	{
    		cin>>x>>y;
    		tr[x].pb(y);
    		tr[y].pb(x);
    	}

    	dfs(1,0,0);
    	
    	mle = 0;
    	
    	//dfs(bap,0,0);
    	//cout<<bap<<endl;

    	ll ans = dfs2(bap,0);
    	cout<<ans+1<<endl;
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
