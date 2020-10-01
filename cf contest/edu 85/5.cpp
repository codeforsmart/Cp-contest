#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 998244353
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll exp(ll a,ll b,ll m);
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll d;
    cin>>d;

    vector<ll> pr;

    ll sq = sqrt(d);

    ll d1 = d;

    ll su = 0;
    for(ll i = 2;i<=sq;i++)
    {
    	if(d1%i==0)
    	{
    		pr.pb(i);
    		while(d1%i==0) {d1/=i; su++;}
    	}
    }


    if(d1>1) {pr.pb(d1); su++;}


    ll fact[su+1]={0};
    fact[0] = 1;

    f(i,1,su+1) 
    {
    	fact[i] = i*fact[i-1];
    	fact[i] = fact[i]%mod;
    }

    ll sz = pr.size();


    ll q;
    cin>>q;
    ll u,v;

   	while(q--)
   	{
   		cin>>u>>v;
   		ll f1 = 0, f2 = 0;
   		ll ans = 1;

   		f(i,0,sz)
   		{
   			
   			ll a1 = 0;
   			while(u%pr[i]==0)
   			{
   				u/=pr[i];
   				a1++;
   			}	

   			ll a2 = 0;
   			while(v%pr[i]==0)
   			{
   				v/=pr[i];
   				a2++;
   			}
   			

   			ll lc = 0;
        lc = max(lc,a1);
   			lc = max(lc,a2);
   			ll b1 = lc - a1, b2 = lc - a2;
   			
   			f1+=b1;
   			f2+=b2;

   			ans*=exp(fact[b1],mod-2,mod);
   			ans = ans%mod;
   			ans*=exp(fact[b2],mod-2,mod);
   			ans = ans%mod;

   			
   		}
   		//debug(f2);
   		ans*=fact[f1];
   		ans = ans%mod;

   		ans*=fact[f2];
   		ans = ans%mod;

   		cout<<ans<<endl;
 	
   	}

return 0;
}

ll exp(ll a,ll b,ll m)
{
	a = a%m;
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
