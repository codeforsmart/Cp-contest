#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
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
    	ll n,g,d;
    	cin>>n>>g>>d;

    	ll ans = n;

    	
    	ll k = n/(g+d);
    	ll n1 = n - k*(g+d);
    	
    	ll g1 = g*k, d1 =  d*k;

    	if(n1<=g) g1+=n1;
    	else g1+=g;

    	if(n1>g) d1+=(n1-g);

    	if(g1>=d1)
    	{
    		cout<<ans<<endl;
    	}
    	else
    	{
    		ll ex = 0;
    		ll di = d1-g1;
    		
    		ll p1 = n-(n/(2*g))*2*g;

    		ll ans1 = n/(2*g);
    		if(n%(2*g)!=0) ans1++;

    		ans1--;

    		ex+= ans1*(d-g);
    		//debug(ex);
    		ll pv = 0;
    		if(p1 == 0) p1 = 2*g;
    		if(p1>g) {ex -= (p1-g); pv = g;}
    		else pv = p1;
    		//debug(ans1);
    		ex-=(pv-1)/2;
    		//debug(ex);
    		cout<<ans+ex<<endl;

    	}
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
