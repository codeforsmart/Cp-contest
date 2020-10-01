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

    ll n;
    cin>>n;
    string s[n];
    f(0,n) cin>>s[i];

    ll w[n][n];

    f(0,n)
    {
    	for(ll j=0;j<n;j++)
    	{
    		if(s[i][j]=='0') w[i][j]=mod;
    		else w[i][j]=1;
    	}
    }
    
    for(ll k = 0;k<n;k++)
    {
    	for(ll i=0;i<n;i++)
    	{
    		for(ll j=0;j<n;j++)
    		{
    			w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
    		}
    	}
    }

    
    
    ll k;
    cin>>k;
    vector<ll> sb;
   	ll bd[k];
   	f(0,k) cin>>bd[i];

   	sb.pb(bd[0]);

   	ll li = 0;
   	f(2,k)
   	{
   		if(bd[i-1]==bd[li]) {sb.pb(bd[i-2]); li=i-2;}
   		if(i-li>w[bd[li]-1][bd[i]-1])
   		{
   			//cout<<"dd "<< i<<" "<<li<<endl;
   			
   			sb.pb(bd[i-1]);
   			li=i-1;
   		}
   	}
   	if(bd[k-1]==bd[li]) sb.pb(bd[k-2]);
    sb.pb(bd[k-1]);

    cout<<sb.size()<<endl;
    f(0,sb.size()) cout<<sb[i]<<" ";
    cout<<endl;
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