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

   ll q;
   cin>>q;
   ll n1 = n;
   n =q;
   ll ind = -1;
   ll aq[q][3];
   f(0,n)
   {
    cin>>aq[i][0];
    cin>>aq[i][1];
    if(aq[i][0]==1) {cin>>aq[i][2];}
   }
   ll su[n];
   ll x = 0;
   
   f(0,n)
   {
    if(aq[n-i-1][0] == 2) x = max(x,aq[n-i-1][1]);
    su[n-i-1] = x;
   }

   f(0,n1) a[i] = max(a[i],x);
   f(0,n)
   {
    if(aq[i][0]==1)
    {
     
        a[aq[i][1]-1] = max(su[i],aq[i][2]);
     
    }
   }

   f(0,n1) cout<<a[i]<<" ";
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