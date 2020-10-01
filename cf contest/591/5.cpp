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
ll n=0,k;
vector< pair<ll,ll> > tr[500002];
//ll co = 0;
pair<ll,ll> dfs(ll a, ll p)
{
	//co++;
	//if(co>5) return {0,0};
	//cout<<a<<" "<<p<<endl;
	ll sz = tr[a].size();
	vector< ll > sb;
	
	ll ans = 0;
	f(i,0,sz)
	{

		if(tr[a][i].ff==p) continue;

		ll wt = tr[a][i].ss; 
		 pair<ll,ll> msm = dfs(tr[a][i].ff,a);
		ans+=msm.ff;
		if(wt>msm.ff-msm.ss)
		{
			sb.pb(wt-(msm.ff-msm.ss));
		}
	}
	sort(sb.begin(),sb.end());
	reverse(sb.begin(),sb.end());
	ll pl = sb.size();
	f(i,0,min(k-1,pl))
	{
		ans+=sb[i];
	}

	ll ans2 = ans;

	if(k-1>=0 && k-1<=pl-1) ans2+=sb[k-1];

	return mp(ans2,ans);

}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    ll x,y,w;
    while(t--)
    {
    	//cout<<t<<endl;
    	f(i,0,n+1) tr[i].clear();
    	cin>>n>>k;
    	f(i,0,n-1)
    	{
    		cin>>x>>y>>w;
    		tr[x].pb(mp(y,w));
    		tr[y].pb(mp(x,w));
    	}
    	//cout<<n<<" "<<k<<endl;
   	pair<ll,ll> sbb = dfs(1,0);
    	cout<<max(sbb.ff,sbb.ss)<<endl;
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
