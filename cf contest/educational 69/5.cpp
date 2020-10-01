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
struct sb
{
	ll out;
	ll in;
};

bool comp(sb a, sb b) 
{ 
    
    if (a.out <= b.in ) 
        return false;
    else if(a.in >= b.out)
    	return true;
  	else if(a.out == b.out)
  		return a.in>=b.in;
  	
  	return a.out >=b.out;
   
} 

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;

    sb ar[n];

    f(0,n)
    {
    	cin>> ar[i].out >> ar[i].in;
    }
    sort(ar,ar+n,comp);
    f(0,n)
    {
    	cout<<ar[i].out<<" "<<ar[i].in<<endl;
    }
    ll ans = 1;
    ll ans1=1;
    ll inr = ar[n-1].in;
    for(ll i = n-2;i>=0;i--)
    {
    	if(ar[i].out>inr && ar[i].in>=inr) ans1++;
    	else if(ar[i].out<=inr)
    	{
    		ans*=ans1;
    		ans = ans%mod;
    		ans1=1;
    		inr = ar[i].in;
    	}
    }
    ans*=ans1;
    ans = ans%mod;

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