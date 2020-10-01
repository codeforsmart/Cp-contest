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

    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    ll pr[n];
    f(i,0,n) pr[i] = -1;
    
    ll co[26]={0};
    f(i,0,26) co[i] = -1;
    f(i,0,n) co[s[i]-'a'] = i;
    
    f(i,0,26)
    {
    	if(co[i]==-1) continue;
    	for(ll j = co[i];j>=0;j--)
    	{
    		if(pr[j]==-1)
    		{
    			ll nu = s[j]-'a';
    			if(nu==i) pr[j] = 1;
    			else pr[j] = 0;
    		}
    	}
    }

    string s1 = "a";
    f(i,0,n)
    {
    	if(pr[i]==0)
    	{
    		s1+=s[i];
    	}
    }
  
    string s2 = s1;
    sort(s1.begin(),s1.end());
    bool ans = 0;
    if(s1==s2)
    {
    	ans = 1;
    }

    if(ans==0) cout<<"NO"<<endl;
    else
    {
    cout<<"YES"<<endl;
    f(i,0,n) cout<<pr[i];
    cout<<endl;
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
