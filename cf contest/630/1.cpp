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
    	ll a,b,c,d;
    	cin>>a>>b>>c>>d;

    	ll x,y,x1,y1,x2,y2;
    	cin>>x>>y>>x1>>y1>>x2>>y2;

    	bool ans = 1;

    	if((a || b) && x2==x1) ans = 0;
    	if((c || d) && y2==y1) ans = 0;

    	ll xi = min(b,a);
    	ll yi = min(d,c);

    	a-=xi;
    	b-=xi; c-=yi; d-=yi;

    	

    	if(a>x-x1 || b>x2-x || c>y-y1 || d>y2-y) ans = 0;

    	if(ans==1) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
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
