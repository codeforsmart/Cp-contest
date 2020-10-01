#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
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
    	ll n,m,k;
    	cin>>n>>m>>k;

    	ll a[n];
    	f(0,n) cin>>a[i];

    	bool ans = 1;

    	f(0,n-1)
    	{
    		if(a[i]+m<a[i+1]-k) 
    		{
    			ans = 0;
    			break;
    		}
    		else if(a[i]<a[i+1]-k)
    		{
    			m-=(a[i+1]-k-a[i]);
    		}
    		else
    		{
    			ll mi = 0;
    			mi = max(mi,a[i+1]-k);

    			m+=a[i]-mi;
    		}

    	}
    	if(ans) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
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