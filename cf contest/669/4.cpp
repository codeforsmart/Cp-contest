#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
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
    f(i,0,n) cin>>a[i];

    stack<pl> S; 
  	
  	ll sm[n] = {0};

    for (ll i1=0; i1<n; i1++) 
    { 
    	ll i = n-i1-1;
        while (!S.empty() && S.top().ss > a[i]) 
            S.pop();

        if (S.empty()) sm[i] = -1;
        else  sm[i] = S.top().ff;
        S.push({i,a[i]}); 
    } 

    //S.clear();
     stack<pl> S1; 
    ll la[n] = {0};

    for (ll i1=0; i1<n; i1++) 
    { 
    	ll i = n-i1-1;
        while (!S1.empty() && S1.top().ss < a[i]) 
            S1.pop();

        if (S1.empty()) la[i] = -1;
        else  la[i] = S1.top().ff;
        S1.push({i,a[i]}); 
    }


    stack<pl> Sa; 
    ll sm1[n] = {0};

    for (ll i=0; i<n; i++) 
    { 
    	//ll i = n-i1-1;
        while (!Sa.empty() && Sa.top().ss > a[i]) 
            Sa.pop();

        if (Sa.empty()) sm1[i] = -1;
        else  sm1[i] = Sa.top().ff;
        Sa.push({i,a[i]}); 
    } 

    //S.clear();
     stack<pl> S1a; 
    ll la1[n] = {0};

    for (ll i=0; i<n; i++) 
    { 
    	//ll i = n-i1-1;
        while (!S1a.empty() && S1a.top().ss < a[i]) 
            S1a.pop();

        if (S1a.empty()) la1[i] = -1;
        else  la1[i] = S1a.top().ff;
        S1a.push({i,a[i]}); 
    }


    ll dp[n]={0};

    /*f(i,0,n) cout<<sm[i]<<" ";
    cout<<endl;
    f(i,0,n) cout<<la[i]<<" ";
    cout<<endl;*/
    f(i,1,n) dp[i] = mod;
    f(i,0,n)
    {
    	if(i>1) dp[i] = min(dp[i-1]+1,dp[i]);
    	if(sm[i]!=-1) dp[sm[i]] = min(dp[sm[i]],dp[i]+1);
    	if(la[i]!=-1) dp[la[i]] = min(dp[la[i]],dp[i]+1);


    	if(sm1[i]!=-1) dp[i] = min(dp[i],dp[sm1[i]]+1);
    	if(la1[i]!=-1) dp[i] = min(dp[i],dp[la1[i]]+1);
    }
    
    cout<<dp[n-1]<<endl;
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
