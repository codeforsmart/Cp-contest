#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
set<ll> tr[26];
ll vis[26]={0};

void dfs(ll a)
{
	if(vis[a]==1) return;

	vis[a]=1;

	for(auto po : tr[a])
	{
		dfs(po);
	}
}
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
    ll co[26]={0};
    f(i,0,n)
    {
    	cin>>s;

    	ll l = s.length();
    	co[s[0]-'a']++;
    	f(j,1,l)
    	{
    		co[s[j]-'a']++;
    		tr[s[0]-'a'].insert(s[j]-'a');
    		tr[s[j]-'a'].insert(s[0]-'a');
    	}
    }
    ll ans = 0;
    f(i,0,26)
    {
    	if(co[i])
    	{
    		if(vis[i]==0)
    		{
    			ans++;
    			dfs(i);
    		}
    	}
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
