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

    ll n,m;
    cin>>n>>m;

    ll a[n][m],b[n][m],a1[n][m],b1[n][m];

    f(0,n) for(ll j=0;j<m;j++) cin>>a[i][j];
    f(0,n) for(ll j=0;j<m;j++) cin>>b[i][j];


    f(0,n) for(ll j=0;j<m;j++) {a1[i][j]=min(a[i][j],b[i][j]); b1[i][j]=max(a[i][j],b[i][j]);}

	 bool ans=1;
	 
	 f(0,n)
	 {
	 	for(ll j=1;j<m;j++)
	 	{
	 		if(a1[i][j]<=a1[i][j-1])
	 		{
	 			ans=0; break;
	 		}
	 	}
	 	if(ans==0) break;
	 }   

	 f(0,m)
	 {
	 	for(ll j=1;j<n;j++)
	 	{
	 		if(a1[j][i]<=a1[j-1][i])
	 		{
	 			ans=0; break;
	 		}
	 	}
	 	if(ans==0) break;
	 }

	 f(0,n)
	 {
	 	for(ll j=1;j<m;j++)
	 	{
	 		if(b1[i][j]<=b1[i][j-1])
	 		{
	 			ans=0; break;
	 		}
	 	}
	 	if(ans==0) break;
	 }   

	 f(0,m)
	 {
	 	for(ll j=1;j<n;j++)
	 	{
	 		if(b1[j][i]<=b1[j-1][i])
	 		{
	 			ans=0; break;
	 		}
	 	}
	 	if(ans==0) break;
	 }   
    	
    if(ans==1) 
    {
    	cout<<"Possible"<<endl;
    }
    else cout<<"Impossible"<<endl;
    
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