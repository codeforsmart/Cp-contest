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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;

    vector< pair<pair<ll,ll> , pair<ll,ll> > > sb;
    ll x,y,z;
    f(i,0,n)
    {
    	cin>>x>>y>>z;
    	sb.pb(mp(mp(x,y),mp(z,i+1)));
    }

    sort(sb.begin(),sb.end());
    bool vis[n+1]={0};
    for(ll i = 0;i<n;i++)
    {
    	if(vis[i]) continue;
    	vis[i]=1;
    	//ll mi = mod;
    	ll ind = n-1;
    	f(j,0,n-1)
    	{
    		if(i==j || vis[j]) continue;
    		ll pol = abs(sb[i].ff.ff-sb[j].ff.ff)+abs(sb[i].ff.ss-sb[j].ff.ss)+abs(sb[i].ss.ff-sb[j].ss.ff);
    		ll pol2 = abs(sb[i].ff.ff-sb[j+1].ff.ff)+abs(sb[i].ff.ss-sb[j+1].ff.ss)+abs(sb[i].ss.ff-sb[j+1].ss.ff);
    		if(pol<pol2)
    		{
    			ind = j;
    			break;
    		}
    		
    	}
    	vis[ind] = 1;

    	cout<<sb[i].ss.ss<<" "<<sb[ind].ss.ss<<endl;
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
