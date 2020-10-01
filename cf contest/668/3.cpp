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
 
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n,k;
    	cin>>n>>k;

    	string s;
    	cin>>s;

    	bool ok = 0;
    	f(i,0,n-k)
    	{
    		if(s[i]!=s[i+k])
    		{
    			if(s[i]=='?') continue;
    			else if(s[i+k]!='?')
    			{
    				ok = 1;
    				break;
    			}
    			else s[i+k] = s[i];
    		}
    	}

    	for(ll i = n-1;i>=k;i--)
    	{
    		if(s[i]!=s[i-k])
    		{
    			if(s[i]=='?') continue;
    			else if(s[i-k]!='?')
    			{
    				ok = 1;
    				break;
    			}
    			else s[i-k] = s[i];
    		}
    	}

    	if(ok==1)
    	{
    		cout<<"NO"<<endl;
    		continue;
    	}

    	ll o=0,z=0,q=0;
    	f(i,0,k)
    	{
    		if(s[i]=='1') o++;
    		else if(s[i]=='0') z++;
    		else q++;
    	}

    	ll di = abs(o-z);

    	//cout<<s<<endl;
    	if(q>=di && (q-di)%2==0)
    	{
    		cout<<"YES"<<endl;
    		continue;
    	}
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
