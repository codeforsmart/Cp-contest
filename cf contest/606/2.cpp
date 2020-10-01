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

    	vector<ll> a;
    	ll x;
    	ll sz = 0;
    	f(i,0,n)
    	{
    		cin>>x;
    		if(x%2==0)
    		{
    			a.pb(x);
    			sz++;
    		}
    	}

    	map<ll,ll> sb;

    	f(i,0,sz)
    	{
    		ll va = 0;

    		while(a[i]%2==0)
    		{
    			a[i]/=2;
    			va++;
    		}

    		sb[a[i]] = max(sb[a[i]],va);
    	}
    	ll ans = 0;
    	for(auto it: sb)
    	{
    		ans+= it.ss;
    	}
    	cout<<ans<<endl;
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
