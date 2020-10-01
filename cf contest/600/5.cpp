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
map<ll,ll> sb;


ll co[100005]={0};
ll pt[100005]={0};
ll n,m;
ll maxx;
void solve(ll a, ll cos)
{
	//cout<<a<<" "<<cos<<endl;
	if(a>m)
	{
		maxx = min(maxx,cos);
		return;
	}
	if(a!=pt[a])
	{
		solve(pt[a],cos);
		return;
	}

	auto msm = sb.upper_bound(a);

	
	//ll copo = 0;
	while(msm!=sb.end())
	{
		//copo++;
		ll f1 = msm->ff, f2 = msm->ss;
		if(f1==mod)
		{
			maxx = min(maxx,cos + m-a+1);
			break;
		}
		else
		{
			ll ex = f1-a;
			solve(f2+1+ex,cos+ex);
		}

		msm++;

	}	

}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    sb[mod] = -1;
    cin>>n>>m;
    ll x[n],v[n];
    maxx = m;
    f(i,0,n)cin>>x[i]>>v[i];
    ll on = 1;
    vector< pair<ll,ll> > por;
    f(i,0,n)
    {
    	ll mi = max(on,x[i]-v[i]), ma = min(m,x[i]+v[i]);
    	//cout<<mi<<" "<<ma<<endl;
    	co[mi]++;
    	co[ma+1]--;
    	por.pb(mp(mi,ma));
    	
    }
    sort(por.begin(),por.end());
    ll pos = por.size();
    ll rm = 0;
    f(i,0,pos)
    {
    	if(por[i].ff>=rm)
    	{
    		rm = por[i].ss;
    		sb[por[i].ff] = max(sb[por[i].ff],por[i].ss);
    	}
    }
    f(i,1,m+1)
    {
    	co[i]+=co[i-1];
    }
  /*  f(i,1,m+1)
    {
    	cout<<co[i]<<" ";
    }
    cout<<endl;*/
    ll va = m+1;
    for(ll j = m;j>=1;j--)
    {
    	if(co[j]==0) va = j;

    	pt[j] = va;
    }
    solve(1,0);
    cout<<maxx<<endl;
    
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
