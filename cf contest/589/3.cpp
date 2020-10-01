#include<bits/stdc++.h>
#define ll unsigned long long int
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

    ll x,n;
    cin>>x>>n;

    vector<ll> pr;

    for(ll i = 2;i<=sqrt(x);i++)
    {
    	if(x%i==0) pr.pb(i);
    	while(x%i==0) x/=i;
    }
    if(x>1) pr.pb(x);

    ll ans = 1;

    f(i,0,pr.size())
    {
    	ll p = pr[i];

    	ll to = p;
    	while(to<=n)
    	{
    		
    		/*ll y = n/(to*p);

    		ans*=exp(to,(y*(p-1))%(mod-1),mod);
    		ll re = (n-to*p*y)/p;
    		ans*=exp(to,re,mod);*/
    		ll nu = n/to;
    		ll mi = mod-1;
    		nu = nu%mi;
    		ans*=exp(p,nu,mod);
    		//cout<<n<<" "<<to<<" "<<p<<" "<<nu<<endl;
    		ans = ans%mod;
    		if(n/p<to) break;
    		to*=p;
    		
    	}
    	//ll x2 = n/to;
    	//ans*=exp(to,x2,mod);
    	ans = ans%mod;
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
