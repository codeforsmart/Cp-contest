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
    	ll n;
    	cin>>n;
    	ll a[n];
    	f(i,0,n) cin>>a[i];

    	ll co[n]={0},co2[n]={0};
    	ll va[n]={0},va2[n]={0};
    	ll ma = 0;
    	ll pr = 0;
    	f(i,0,n)
    	{
    		ma = max(ma,a[i]);

    		va[a[i]]++;
    		if(va[a[i]]==1) pr++;
    		if(va[a[i]]>1) break;
    		if(pr==ma)
    		{
    			co[i]=1;
    		}

    		
    	}
    	pr = 0;
    	ma = 0;
    	f(i1,0,n)
    	{
    		ll i = n-i1-1;
    		ma = max(ma,a[i]);

    		va2[a[i]]++;
    		if(va2[a[i]]==1) pr++;
    		if(va2[a[i]]>1) break;
    		if(pr==ma)
    		{
    			co2[i]=1;
    		}

    		
    	}

    	/*f(i,0,n) cout<<co[i]<<" ";
    	cout<<endl;
    	f(i,0,n) cout<<co2[i]<<" ";
    	cout<<endl;*/
    	vector< ll > anss;

    	f(i,0,n-1)
    	{
    		if(co[i]==1 && co2[i+1]==1) anss.pb(i+1);
    	}

    	ll sz = anss.size();

    	cout<<sz<<endl;

    	f(i,0,sz)
    	{
    		cout<<anss[i]<<" "<<n-anss[i]<<endl;
    	}

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
