#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
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

    ll t;
    cin>>t;
    while(t--)
    {
	    ll n,a,b;
	    cin>>n>>a>>b;
	    string s;
	    cin>>s;
	    vector< pair<char,ll> > sb;

		sb.pb(mp('0',1));
		ll l = s.length();

		f(i,1,l)
		{
			if(s[i]==sb.back().ff) sb.back().ss++;
			else 
			{
				if(i+1<l && s[i]=='0' && s[i+1]=='1') sb.back().ss++;
				else sb.pb(mp(s[i],1));
			}
		}

		ll cost = n*a+(n+1)*b;

		ll sz = sb.size();

		for(ll i = 2; i<=sz-2;i+=2)
		{
			cost+=min((sb[i].ss-1) * b,2*a);
		}
		//cout<<"ccd "<<cost<<endl;
		if(sz>1)
		{
			cost+=2*a;
		}

		for(ll i = 1;i<sz;i+=2)
		{
			cost += b*(sb[i].ss+1);
		}
		cout<<cost<<endl;
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