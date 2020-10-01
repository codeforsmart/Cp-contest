#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 998244353 
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

    ll n,m;
    cin>>n>>m;

    ll a[m];
    f(0,m) cin>>a[i];
    ll ka[n+1];
    f(0,m) ka[a[i]]=i+1;

    map<ll,bool> pos;
    map<ll,bool> ne;

    pos[n+1]=1;
    ne[0]=1;
    ll ans = 1;
    f(1,n+1)
    {
    	ll i1 = ka[i];
    	ll ri = pos.upper_bound(i1)->ff;
    	ll le = - ne.upper_bound(-i1)->ff;
    	//cout<<ri<<" "<<le<<" "<<i1<<endl;
    	ans *= (i1-le)*(ri-i1);
    	ans = ans%mod;
    	pos[i1]=1;
    	ne[-i1]=1;
    	//cout<<ans<<endl;
    }
    
    cout<<ans-1<<endl;
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