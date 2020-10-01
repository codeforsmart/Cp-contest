#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll int
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
    	string s1,s2;
    	cin>>s1>>s2;

    	map<ll,bool> sb[26];

    	ll l1 = s1.length();
    	ll n = l1;
    	f(i,0,l1)
    	{
    		sb[s1[i]-'a'][i] = 1;
    	}
    	f(i,0,26) sb[i][n+9] = 1;

    	ll l2 = s2.length();

    	ll ans = 0;
    	ll ind = -1;
    	//for(auto pp : sb[0])
    	//{
    	//	cout<<pp.ff<<" "<<pp.ss<<endl;
    	//}
    	f(i,0,l2)
    	{
    		ind = sb[s2[i]-'a'].upper_bound(ind)->ff;
    		//debug(ind);
    		if(ind>n) 
    		{
    				ans++;
    		ind = -1;
    		ind = sb[s2[i]-'a'].upper_bound(ind)->ff;
    		if(ind>n)
    		{
    			ans = -1;
    			break;
    		}
    		}
    		
    		
    	}

    	if(ans!=-1) ans++;

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
