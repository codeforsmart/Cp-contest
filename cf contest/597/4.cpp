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

    ll x[n],y[n];

    f(i,0,n) cin>>x[i]>>y[i];
    ll ans = 0;
    ll c[n];
    f(i,0,n) cin>>c[i];

    ll k[n];
    f(i,0,n) cin>>k[i];

    vector< pair<ll , pair<ll,ll> > >sb;

    f(i,0,n)
    {
    	sb.pb(mp(c[i],mp(k[i],i)));
    }
    sort(sb.begin(),sb.end());

    ll li[n]={0};

    //li[sb[0].ss.ss]=1;
    ll e = 0;
    vector< pair<ll,ll> > pr;
    ll mi = 0;
    ll cos[n]={0};
    f(i,0,n)
    {	
    	ll in = sb[i].ss.ss;
    	mi = c[in];
    	ll ko = -1;
    	f(j,0,n)
    	{
    		if(i==j) continue;
    		ll jn = sb[j].ss.ss;

    		ll mi2 = (k[in]+k[jn])*(abs(x[in]-x[jn]) + abs(y[in]-y[jn]));
    		if(mi2 < mi)
    		{
    			mi = mi2;
    			ko = jn;
    		}
    	}

    	if(ko == -1) 
    	{
    		li[in]=1;
    	}
    	else
    	{
    		e++;
    		pr.pb(mp(in,ko));
    	}
    	ans += mi;
    }
    
    ll v = 0;
    vector<ll> st;
    f(i,0,n) 
    {
    	if(li[i]==1) 
    	{
    		v++;
    		st.pb(i);
    	}
    }
    cout<<ans<<endl;
    cout<<v<<endl;
    f(i,0,v) cout<<st[i]+1<<" ";
    cout<<endl;

    cout<<e<<endl;
    f(i,0,e) cout<<pr[i].ff+1 <<" "<<pr[i].ss+1<<endl;

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
