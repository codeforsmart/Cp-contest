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
    	ll n;
    	cin>>n;

    	ll ind = 1;
    	vector<ll> sb;
    	ll in = -1;
    	while(ind<=n+1)
    	{
    		if(n/ind != in)
    		{
    			sb.pb(n/ind);
    			in = n/ind;
    			ind++;
    		}
    		else
    		{
    			ind = 1+n/(n/ind);
    		}

    	}
    	ll sz = sb.size();

    	cout<<sz<<endl;;

    	reverse(sb.begin(),sb.end());

    	f(i,0,sz) cout<<sb[i]<<" ";
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
