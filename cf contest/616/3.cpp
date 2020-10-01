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
ll sgtr[35000];
ll a[3505];
void build(int node, int start, int end)
{
    if(start == end)
    {
        sgtr[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        
        // Internal node will have the sum of both of its children
        sgtr[node] = min(sgtr[2*node],sgtr[2*node+1]);
    }
}
ll query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return mod;
    }
    if(l <= start and end <= r)
    {
        return sgtr[node];
    }
    
    int mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1,p2);
}

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
    	a[0] = 0;
    	a[n+1] = 0;
    	f(i,1,n+1) cin>>a[i];
    	
    	k = min(k,m-1);
    	ll ans = 0;
    	for(ll le = 0;le<=k;le++)
    	{
    	//	debug(le);
    		ll re = k -le;
    		ll ans1 = mod;
    		for(ll j = 0; j<=m-1-k;j++)
    		{
    			ll j2 = m-1-j-k;
    			ans1 = min(ans1,max(a[1+le+j],a[n-re-j2]));
    		//	debug(j);
    		//	cout<<1+le+j<<" "<<n-re-j2<<endl;
    			
    		}
    		ans = max(ans, ans1);
    	}
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
