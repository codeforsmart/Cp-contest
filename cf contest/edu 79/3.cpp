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
    	ll n,m;
    	cin>>n>>m;

    	ll a[n],b[m];

    	f(i,0,n) cin>>a[i];

    	f(i,0,m) cin>>b[i];

    	ll vis[n+2]={0};

    	ll kah[n+2]={0};

    	f(i,0,n)
    	{
    		kah[a[i]]=i;
    	}

    	ll ans = 0;
    	f(i,0,m)
    	{
    		ll ind= kah[b[i]];
    		if(vis[ind]==0)
    		{
    			ans+= 2*(ind-i) + 1;

    			for(ll j = ind;j>=0;j--)
    			{
    				if(vis[j]==1) break;
    				vis[j]=1;
    			}
    		}
    		else ans++;
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
