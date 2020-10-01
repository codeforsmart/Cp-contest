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
vector<ll> tr[200005];
ll di[200005]={0};

void dfs(ll a, ll d)
{
	//debug(a);
	if(di[a]<=d) return;

	di[a] = d;

	for(auto v: tr[a])
	{
		//debug(v);
		dfs(v,d+1);
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,m,k;
    cin>>n>>m>>k;

    ll a[k];
    f(i,0,k) cin>>a[i];

    ll x,y;
    f(i,0,m)
    {
    	cin>>x>>y;
    	tr[x].pb(y);
    	tr[y].pb(x);
    }
    
    ll d1[n+1]={0},nd[n+1]={0};

    f(i,1,n+1) di[i]=mod;
    

    dfs(1,0);
    f(i,1,n+1)
    {
    	d1[i] = di[i];
    }
    f(i,1,n+1) di[i]=mod;
    dfs(n,0);
    f(i,1,n+1)
    {
    	nd[i] = di[i];
    }

    vector<ll> dn;

    f(i,0,k)
    {
    	dn.pb(nd[a[i]]);
    }

    sort(dn.begin(),dn.end());

    ll anm = d1[n];
    dn.pb(mod);
    ll co = 0;
    ll ans = -1;
    f(i,0,k)
    {
    	ll le = upper_bound(dn.begin(), dn.end(), anm-d1[a[i]]-1) - dn.begin();

    	co+=le;

    	if(le==0) continue;

    	ans = max(ans,d1[a[i]]+dn[le-1]+1);
    }

    //debug(anm);
    if(co!=(k*(k-1))/2 || ans==-1) cout<<anm<<endl;
    else 
    {
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
