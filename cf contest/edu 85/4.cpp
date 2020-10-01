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
ll n,l,r;
pair<ll,ll> msm(ll a, ll b)
{	if(a==n-1) return mp(1,n);
	if(b<n) return mp(a,b+1);
	else return mp(a+1,a+2);
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
    	
    	cin>>n>>l>>r;

    	if(l==n*(n-1)+1) 
    	{
    		cout<<1<<endl;
    		continue;
    	}
    	ll st = 0;
    	ll curr = n-1;

    	ll ind = 1;
    	while(st + 2*curr < l)
    	{
    		ind++;
    		st+=2*curr;
    		curr--;
    	}

    	st++;
    	//cout<<ind<<endl;
    	ll a = ind, b =ind+1;

    	for(ll i = st;i<=r;i+=2)
    	{
    		//debug(i);
    		if(i+1==l) cout<<b<<" ";
    		else if(i==r) cout<<a<<" ";
    		else if(i>=l) cout<<a<<" "<<b<<" ";
    		auto pp = msm(a,b);
    		a = pp.ff; b = pp.ss;
    	}
    	cout<<endl;
    	//return 0;
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
