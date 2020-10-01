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
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    string s;
    cin>>s;
    ll l = s.length();
    vector< pair<char,ll> > sb;
    sb.pb(mp(s[0],1));

    f(1,l)
    {
    	if(s[i]==sb.back().ff) sb.back().ss++;
    	else sb.pb(mp(s[i],1));
    }
    ll ans = 0;
    while(sb.size()>1)
    {

    	ans++;
    	f(0,sb.size())
    	{
    		if(i == 0 || i == sb.size()-1) sb[i].ss--;
    		else sb[i].ss-=2;
    	}
    	vector< pair<char,ll> > msm;
    	f(0,sb.size()) if(sb[i].ss>0) msm.pb(sb[i]);
    	if(msm.size()==0) break;
    	sb.clear();
    	sb.pb(msm[0]);
    	f(1,msm.size())
    	{
    		if(msm[i].ff==sb.back().ff) sb.back().ss+=msm[i].ss;
    		else sb.pb(msm[i]);
    	}
    	
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