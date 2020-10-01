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
ll tr[400010];

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
    	ll n;
    	cin>>n;

    	f(i,0,2*n+2) tr[i] = 0;
    	ll l[n],r[n];

    	set<ll> nu;
    	f(i,0,n) cin>>l[i]>>r[i];

    	f(i,0,n)
    	{
    		nu.insert(l[i]);
    		nu.insert(r[i]);
    	}
    	vector<ll> msm;
    	for(auto y: nu)
    	{
    		msm.pb(y);
    	}
    	ll sz = msm.size();
    	map<ll,ll> sb;

    	sb[msm[0]] = 1;

    	ll va = 1;

    	f(i,1,sz)
    	{
    		if(msm[i]==msm[i-1]+1)
    		{
    			va++;
    		}
    		else
    		{
    			va+=2;
    		}
    		sb[msm[i]] = va;
    	}

    	f(i,0,n)
    	{
    		l[i] = sb[l[i]];
    		r[i] = sb[r[i]];
    	}

    	f(i,0,n)
    	{
    		tr[l[i]]++;
    		tr[r[i]]--;
    	}

    	f(i,1,2*n+2)
    	{
    		tr[i]+=tr[i-1];
    	}

    	ll ans = 1;
    	bool ch = 0;
    	f(i,0,2*n+1)
    	{
    		if(tr[i]==1) ch = 1;
    	}

    	vector< pair<ll,ll> > sbb;

    	f(i,0,n) sbb.pb(mp(l[i],r[i]));

    	sort(sbb.begin(),sbb.end());
    	ll r2 = sbb[0].ss;
    	f(i,1,n)
    	{
    		if(sbb[i].ff<=r2)
    		{
    			r2 = max(r2,sbb[i].ss);
    		}
    		else ans++;
    	}

    	if(ch==1) ans--;
    	cout<<ans<<endl;
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
