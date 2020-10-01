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

    ll a = n ,b = 1;


    ll n1 = n;
    vector<ll> sb;
    for(ll i = 2;i<=sqrt(n1);i++)
    {	
    	ll va = 1;
    	if(n1%i==0)
    	{
    		

    		while(n1%i==0)
    		{
    			va*=i;
    			n1/=i;
    		}
    		sb.pb(va);
    	}
    }
    
    sb.pb(n1);

    ll sz = sb.size();

    ll lk = 1 << sz;

  //  cout<< lk<<endl;


    f(i,0,lk)
    {
    	ll pr = 1;
    	ll i1 = i;
    	f(j,0,sz)
    	{
    		if(i1%2==0) pr*=sb[j];
    		i1/=2;
    	}
    	if(max(pr,n/pr)<max(a,b))
    	{
    		a = pr;
    		b = n/pr;
    	}
    }
    
    cout<<a<<" "<<b<<endl;
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
