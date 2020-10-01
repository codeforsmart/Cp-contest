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
    	string s;
    	cin>>s;
    	string pas = "";

    	ll n = s.length();
    	pas+=s[0];
    	bool ans = 1;
    	ll ind = 0;
    	bool vis[26]={0};
    	vis[s[0]-'a'] = 1;
    	f(i,1,n)
    	{
    		if(s[i]==s[i-1])
    		{
    			ans = 0;
    			break;
    		}
    		if(vis[s[i]-'a'] ==1 ) continue;

    		if(s[i-1]==pas[0]) 
    		{
    			pas = s[i] + pas;
    			ind++;
    		}
    		else if(s[i-1]==pas[ind])
    		{
    			pas += s[i];
    			ind++;
    		}
    		else
    		{
    			ans = 0;
    			break;
    		}

    		vis[s[i]-'a'] = 1;
    	}

    	f(i,0,26)
    	{
    		if(vis[i]==0) pas+= char('a'+i);
    	}

    	ll lo[26]={0};

    	f(i,0,26)
    	{
    		lo[pas[i]-'a'] = i;
    	}

    	f(i,1,n)
    	{
    		if(abs(lo[s[i]-'a']-lo[s[i-1]-'a'])!=1) 
    		{
    			ans = 0;
    			break;
    		}
    	}

    	if(ans==0) 
    	{
    		cout<<"NO"<<endl;
    	}
    	else
    	{
    		cout<<"YES"<<endl;
    		cout<<pas<<endl;
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
