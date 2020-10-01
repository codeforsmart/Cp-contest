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

    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n) cin>>a[i];

    f(i,1,n) a[i]+=a[i-1];

    map<ll,ll> co;
    co[0]=-1;

    vector< pair<ll,ll> > sb;

    f(i,0,n)
    {
    	if(co.count(a[i]))
    	{	
    		ll l = co[a[i]]+1;
    		sb.pb(mp(l,i));
    	}
    	co[a[i]]=i;
    }
    

    ll sz = sb.size();

    map<ll,ll> msm;

    msm[n]=n;

    f(i,0,sz)
    {
    	ll l = sb[i].ff,r = sb[i].ss;

    	ll r1 = msm.upper_bound(l)->ss;

    	r = min(r,r1);

    	msm[l] = r;
    }
    
    ll ans = 0;

    f(i,0,n)
    {
    	ans += msm.lb(i)->ss - i;
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
