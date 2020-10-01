#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
map< vector<ll> , bool > sb;

ll a[100005]; ll n;
ll ans=0;
void solve(vector<ll> te, ll aa)
{
	f(0,te.size()) if(te[i]==aa) return;

	te.pb(aa);
	ans++;
	sb[te]=1;
	ans=ans%mod;
	if(a[aa]==1)
	{
		if(aa-1>=0) solve(te,aa-1);
		if(aa+1<=n-1) solve(te,aa+1);
	}
	else
	{
		if(aa-1>=0) solve(te,aa-1);
		if(aa+1<=n-1) solve(te,aa+1);
		if(aa-2>=0) solve(te,aa-2);
		if(aa+2<=n-1) solve(te,aa+2);
	}
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
     while(t--)
     {
     	ans=0;
     	
     	cin>>n;
     	
     	f(0,n) cin>>a[i];
     	vector<ll> pa;

     	solve(pa,0);

     	cout<<ans%mod<<endl;
     	/*ll co[n]={0};
     	for(auto a1 : sb)
     	{
     		vector<ll> poi = a1.ff;
     		co[poi.back()]++;
     	}

     	f(1,n) co[i]+=co[i-1];
     	f(0,n) cout<<co[i]<<" ";
     	cout<<endl;*/

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