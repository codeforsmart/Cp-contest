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

 	

    ll t;
    cin>>t;
    while(t--)
    {
    	cout.flush();
    	ll n;
    	cin>>n;

    	ll nu = 1;

    	f(i,0,n) nu*=10;

    	ll a,c,d;

    	cin>>a;

    	cout<<a+2*nu<<endl;

    	cin>>c;
    	cout<<nu-c<<endl;
    	cin>>d;
    	cout<<nu-d<<endl;
    	cin>>a;
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
