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

    ll t;
    cin>>t;
    while(t--)
    {
    	ll n,m;
    	cin>>n>>m;

    	vector< pair<ll,ll> > sb;
    	ll x;
    	f(i,1,n+1)
    	{
    		cin>>x;
    		sb.pb(mp(x,i));
    	}

    	sort(sb.begin(),sb.end());

    	if(n<3 || m<3 || m<n) 
    	{
    		cout<<-1<<endl;
    		continue;
    	}

    	ll c = 0;
    	vector< pair<ll,ll> > pr;
    	f(i,0,n)
    	{
    		ll i1 = (i+1)%n;

    		c+= sb[i].ff + sb[i1].ff;
    		pr.pb(mp(sb[i].ss,sb[i1].ss));
    	}
    	f(i,n,m)
    	{
    		c+= sb[0].ff + sb[1].ff;
    		pr.pb(mp(sb[0].ss,sb[1].ss));
    	}

    	cout<<c<<endl;

    	f(i,0,pr.size()) cout<<pr[i].ff<<" "<<pr[i].ss<<endl;
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
