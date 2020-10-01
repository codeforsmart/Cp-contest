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

    ll a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    ll tp = a1+a2;
   	if(k1>k2)
   	{
   		swap(a1,a2);
   		swap(k1,k2);
   	}

   	ll m1 = a1*(k1-1) + a2*(k2-1);

   	if(n>m1)
   	{
   		cout<<n-m1<<endl;
   	}
   	else cout<<0<<endl;

    ll ma = 0;

    if(n>a1*k1)
    {
    	ma+=a1;
    	n-=a1*k1;
    }
    else 
    {
    	
    	ma += n/k1;
    	n = 0;
    }

   	
    ma += n/k2;

    cout<<ma<<endl;
    
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
