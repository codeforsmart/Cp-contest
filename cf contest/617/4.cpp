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

    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    ll h[n];
    f(i,0,n) cin>>h[i];
    ll ans = 0;
    vector<ll> wi;
    f(i,0,n)
    {
    	ll x = h[i]%(a+b);

    	if(x!=0 && x<=a)
    	{
    		ans++;
    		continue;
    	}

    	x = h[i]-((h[i]-1)/(a+b))*(a+b)-a;
    	ll ex = x/a;
    	if(x%a!=0) ex++;
    	wi.pb(ex);
    	//cout<<ex<<endl;
    }
     
    sort(wi.begin(),wi.end());
    ll sa = wi.size();
    f(i,0,sa)
    {
    	if(wi[i]>k) break;

    	k-=wi[i];
    	ans++;
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
