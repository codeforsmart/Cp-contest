#include<bits/stdc++.h>
#define ll unsigned long long int
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

    ll n,I;
    cin>>n>>I;

    ll a[n];
    f(0,n) cin>>a[i];

    I = 8 * I;
    ll mk = I/n;
    ll dism = 1 << mk;
   	if(mk>=32) dism = n+2;
    
    sort(a,a+n);


    vector<ll> co;
    co.pb(1);

    ll va = a[0];

    f(1,n)
    {
    	if(a[i]==va)
    	{
    		co[co.size()-1]+=1;
    	}
    	else {co.pb(1); va=a[i];}
    }
    ll sum = 0 ;
    ll sz = co.size();
    f(0,sz) sum+=co[i];
    ll mi = sum;
    ll curr = 0;

    dism = min(dism,sz);
    f(0,dism) 
    {
    	curr+=co[i];
    	mi=min(mi,sum-curr);
    }

    f(dism,sz)
    {

    	curr+=co[i];
    	curr-=co[i-dism];
    	mi=min(mi,sum-curr);

    }
    cout<<mi<<endl;
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