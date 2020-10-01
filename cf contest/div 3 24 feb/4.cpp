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
    	ll a,b,c;
    	cin>>a>>b>>c;

    	ll ans = mod,ans1,ans2;
    	ll a1 =0, b1 = 0, c1 = 0;
    	//cout<<ans<<endl;

    	f(i,1,10000+1)
    	{
    		ll a11 = i, b11,b12,c11,c12;

    		b11 = i;
    		
    		while(b11<=10000)
    		{


    		if(abs(c - (c/b11)*b11) <= abs((c/b11+1)*b11-c) ) c11 = (c/b11)*b11;
    		else c11 = (c/b11 + 1)*b11;

    		

    		ans1 = abs(a11-a) + abs(b11-b) + abs(c11-c);
    		
    	
    		if(ans1<ans)
    		{
    			ans = ans1;
    			a1 = a11;
    			b1 = b11;
    			c1 =c11;
    		}
    		
    		b11+=i;
    		}
    		
    	}

    	cout<<ans<<endl;
    	cout<<a1<<" "<<b1<<" "<<c1<<endl;
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
