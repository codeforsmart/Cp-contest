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
   ll a[n];
   f(0,n) cin>>a[i];

  	ll l1=a[0];
  	ll l2;
  	ll ind=n;
   f(0,n)
   {
   		if(a[i]!=l1)
   		{
   			l2=a[i];
   			ind=i;
   			break;
   		}
   }

   ll en=a[n-1];
   ll en2;
   ll ind2=0;

   for(ll i= n-1;i>=0;i--)
   {
   	if(a[i]!=en)
   	{
   		ind2=i;
   		en2=a[i];
   		break;
   	}
   }
   ll ans=0;
   if(l1!=en) ans= n-1;
   else
   {
   		ans=max(ans,ind2);
   		ans=max(ans,n-ind-1);
   }

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