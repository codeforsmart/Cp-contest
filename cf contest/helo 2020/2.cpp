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
    ll va[1000005]={0};
    vector< pair<ll,ll> > sb;
    ll l;
    ll co = 0;
    f(i,0,n)
    {
    	cin>>l;
    	ll s[l];
    	f(j,0,l)
    	{
    		cin>>s[j];
    	}

    	ll mi =s[0], ma = s[0];

    	f(j,0,l)
    	{
    		mi = min(mi,s[j]);
    		ma = max(ma,s[j]);
    	}

    	bool ch = 0;

    	f(j,1,l)
    	{
    		if(s[j]>s[j-1])
    		{
    			ch = 1;
    			break;
    		}
    	}

    	if(ch==1) co++;
    	else
    	{
    		sb.pb(mp(mi,ma));
    		va[ma]++;
    	}

    	

    }

    for(ll i = 1000001;i>=0;i--)
    {
    	va[i]+=va[i+1];
    }
    
    ll le = sb.size();
    ll ans = 0;

    //f(i,0,9) cout<<va[i]<<" ";
    //cout<<endl;
     ans+= co*co;
   ans+= 2*co*(n-co);
   //cout<<ans<<endl;
    f(i,0,le)
    {
    	ans+=va[sb[i].ff+1];

    	//if(sb[i].ss==sb[i].ff) ans--;
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
