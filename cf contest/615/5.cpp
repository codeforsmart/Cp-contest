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

    ll n,m;
    cin>>n>>m;
    ll coi = 0;
    
    ll a[n][m];
    f(i,0,n) f(j,0,m) cin>>a[i][j];
    ll ans = 0;
    f(j,0,m)
    {
    	ll a1[n]={0};
    	ll ans1 = n;
    	f(i,0,n) 
    	{
    		if((a[i][j]-1)%m==j && a[i][j]<=n*m)
    		{
    			a1[(i-(a[i][j]-1)/m+n)%n]++;
    		}
    	}
    	ll ma =0;
    	f(i,0,n)
    	{
    		ans1 = min(ans1,i+n-a1[i]);
    	} 
    	//cout<<ans<<" "<<j<<" "<<ma<<" hh "<<a1[0]<<endl;
    	//f(i,0,n) cout<<a1[i]<<" ";
    	//cout<<endl;
    	ans+=min(ans1,n);
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
