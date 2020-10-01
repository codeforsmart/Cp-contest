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
    ll a[n+2];
    f(1,n+1)cin>>a[i];
    a[0]=-1;
    a[n+1]=-1;

    ll mi = 1;
    ll me = a[1];
    f(1,n+1)
    {
    	if(a[i]>me)
    	{
    		me = a[i];
    		mi =i;
    	}
    }

    ll le = mi-1,re = mi+1;
    ll top = a[mi];
    while(le>=0 && re<=n+1)
    {
    	//cout<<le<<" "<<re<<" "<<top<<endl;
    	ll mii;
    	if(a[le]>a[re]) mii =le;
    	else mii =re;

    	if(a[mii]>top) break;
    	else
    	{
    		top = a[mii];

    		if(mii == le) le--;
    		else re++;
    	}


    }
    
    if(le>0 || re<=n) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    
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