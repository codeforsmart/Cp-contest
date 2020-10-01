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

 /*	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
*/
    
    ll t;
    cin>>t;
    f(tt,1,t+1)
    {
    	cout<<"Case #"<<tt<<": ";
    	//ll co[100001]={0};
    	ll n;
    	cin>>n;

    	ll a[n];
    	f(i,0,n) cin>>a[i];
    	ll ans = 0;
    	multiset<ll> sb;
    	f(i,0,n)
    	{
    		if(a[i]<=ans)
    		{
    			cout<<ans<<" ";
    			continue;
    		}
    		sb.insert(a[i]);
    		if(sb.size()>=ans+1)
    		{
    			ans++;
    			sb.erase(ans);
    		}
    		cout<<ans<<" ";
    	}
    	cout<<endl;
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
