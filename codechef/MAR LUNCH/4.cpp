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
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

        ll n,k;
        cin>>n>>k;

        ll a,b;
        cin>>a>>b;

        ll f1 = abs(b-a);
        ll f2 = k-a-b;
        ll f3 = a+b;
        if(f1==0) f1 = k;
        if(f2==0) f2 = k;
        if(f3==0) f3 = k;

        if(b==a || a+b==k) cout<<1<<" ";
        else
        {
        	ll m1 = ((n*k)  / gcd(n*k,f1))/f1;
        	ll m2 = ((n*k)/(gcd(n*k,f2)))/f2;
        	ll m3 = ((n*k)/(gcd(n*k,f3)))/f3;

        	cout<<min(m1,min(m2,m3))<<" ";
        }


        ll mio= min(f1,min(f2,f3));

        cout<<((n*k)/gcd(n*k,mio))/mio<<endl;
    
    
    
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