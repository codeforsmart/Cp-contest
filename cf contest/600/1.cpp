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
   		ll a[n+1],b[n+1];
   		f(i,1,n+1) cin>>a[i];
   		f(i,1,n+1) cin>>b[i];

   		ll d[n+1]={0};

   		f(i,1,n+1) d[i] = a[i]-b[i];
   		ll ans = 0;
   		ll le = n+1,re = -1;
   		ll co = 0;
   		ll va = 0;
   		f(i,1,n+1)
   		{
   			if(d[i]>0)
   			{
   				ans++;
   				 break;
   			}
   			else if(d[i]<0)
   			{
   				le = min(le,i);
   				re = max(re,i);
   				co++;
   				va = d[i];
   			}

   		}

   		f(i,le,re+1)
   		{
   			if(d[i]!=va) 
   			{
   				ans=5;
   				break;
   			}
   		}

   		if(ans>=1) cout<<"NO"<<endl;
   		else cout<<"YES"<<endl;
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
