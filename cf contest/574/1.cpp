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

    ll n,k;
    cin>>n>>k;
    ll a[k+1]={0};
    ll x;
    f(0,n)
    {
    	cin>>x;
    	a[x]++;
    }

    ll ans=0;
    ll co = n/2 + (n%2!=0);
    f(1,k+1)
    {
    	if(co==0) break;

    		ll an = min(co,a[i]/2);

    		co-=an;

    		ans+=an*2;
    		a[i]-=an*2;

    }

    f(1,k+1)
    {
    	if(co==0) break;

    		ll an = min(co,a[i]);

    		co-=an;

    		ans+=an;
    		a[i]-=an*2;

    }
    
    cout<<ans<<endl;
    
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