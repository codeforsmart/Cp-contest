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
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
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
	ll x,y;
    
    vector<pl> sb;
    
    f(i,0,n)
    {
    	cin>>x>>y;
    	sb.pb({x,y});
    }

    vector<pl> msm;
    
    f(i,0,n)
    {
    	cin>>x>>y;
    	msm.pb({x,y});
    }
    msm.pb({-1,mod});
    msm.pb({mod,-1});
    sort(msm.begin(),msm.end());
    deque<pl> q;

    f(i,0,n)
    {
    	while (!q.empty() && (q.back().ff >= msm[i].ff && q.back().ss>=msm[i].ss)) q.pop_back();
		q.push_back(msm[i]);
    }


    sort(sb.begin(),sb.end());
    ll xs = sb[0].ff,ys = sb[0].ss;
    ll ans = mod;

    vector<pl> sbb;
    for(auto v: q)
    {
    	sbb.pb(v);
    }

    ll sz = sbb.size();

    f(i,1,sz)
    {
    	ll pox = sbb[i-1].ff +1,poy = sb[i].ss+1;

    	ll ans1 = 0;

    	if(xs<pox) ans1+=pox-xs;
    	if(ys<poy) ans1+=poy-ys;
    	ans = min(ans,ans1);
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
