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
    	ll n;
    	cin>>n;

    	ll a[n];
    	f(i,0,n) cin>>a[i];

    	vector<ll> co[n+1];

    	f(i,0,n) co[a[i]].pb(i);
    	ll ans = mod;
    	f(i,0,n+1)
    	{
    		ll sz = co[i].size();

    		if(sz<=1) continue;

    		f(j,0,sz-1)
    		{
    			ans = min(ans, co[i][j+1]-co[i][j]+1);
    		}
    	}

    	if(ans==mod)
    	{
    		cout<<-1<<endl;
    	}
    	else cout<<ans<<endl;
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
