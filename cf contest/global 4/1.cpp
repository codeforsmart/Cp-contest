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


   ll sum = 0;

   f(0,n) sum+=a[i];

   vector<ll> ans;
   ll sum2=a[0];
   ans.pb(1);
   f(1,n)
   {
   	if(a[i]*2<=a[0])
   	{
   		sum2+=a[i];
   		ans.pb(i+1);
   	}
   }
   if(sum2*2<=sum)
   {
   	cout<<0<<endl;
   	return 0;
   }
   
   cout<<ans.size()<<endl;

   f(0,ans.size()) cout<<ans[i]<<" ";
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