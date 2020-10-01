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
 
    ll n;
    cin>>n;

    ll a[n];
    f(i,0,n) cin>>a[i];

    ll a0 = a[0];

    vector<ll> sb;

    ll po = 0;
    f(i,1,n)
    {
    	ll va = a[i]-a[i-1];
    	if(va>0) po+=va;
    	sb.pb(va);
    }
    ll sz = n-1;

    ll msm = (a0 + po)/2;

    if((a0+po)%2==1) msm++;
    cout<<msm<<endl;

    ll q;
    cin>>q;
    ll l,r,x;
    while(q--)
    {
    	cin>>l>>r>>x;
    	l--;
    	r--;

    	if(l==0) a0+=x;

    	if(l-1>=0)
    	{
    		ll i1 = sb[l-1];

    		sb[l-1]+=x;

    		if(sb[l-1]>0 && x>=0)
    		{
    			po+=min(sb[l-1],x);
    		}
    		else if(x<0 && i1>0)
    		{
    			po -= min(i1,-x);
    		}
    	}

    	if(r<sz)
    	{
    		ll i1 = sb[r];
    		x = -x;
    		sb[r]+=x;

    		if(sb[r]>0 && x>=0)
    		{
    			po+=min(sb[r],x);
    		}
    		else if(x<0 && i1>0)
    		{
    			po -= min(i1,-x);
    		}
    	}

    	msm = (a0 + po)/2;
	    if((a0+po)%2==1) msm++;
	    cout<<msm<<endl;

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
