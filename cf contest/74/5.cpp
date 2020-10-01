#include<bits/stdc++.h>
#define ll int
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
ll a[500]={0};
ll n,m;
bool vis[26]={0};
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
     ll sz = m*m+1;
    cin>>n>>m;
    

    string s;
    cin>>s;

    f(i,0,n-1)
    {
    	ll f1 = s[i]-'a',f2=s[i+1]-'a';
    	if(f1==f2) continue;
    	ll mi = min(f1,f2);

    	a[mi*m+f1+f2-mi]++;
    }

    vector< pair<ll,ll> > sb;

    f(i,0,sz)
    {
    	if(a[i])
    	{
    		sb.pb(mp(-a[i],i));
    	}
    }
    sort(sb.begin(),sb.end());

    ll szz = sb.size();
    if(szz == 0)
    {
    	cout<<0<<endl;
    	return 0;
    }
    string ans = "";
    ll ans = 0;
    ll f1 = sb[0].ss/m , f2 = sb[0].ss%m;

    f(i,1,szz)
    {
    	f1 = sb[i].ss/m , f2 = sb[i].ss%m;
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
