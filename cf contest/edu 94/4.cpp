#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define lll long long int
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

ll dp[3005][3005];
ll a[3005];
/*
vector<lll> solve(ll a, ll b, ll st, ll en)
{
	
	vector<lll> te(7,0);
	
	if(st>en) return te;
	if(st==en)
	{
		if(a1[st]==a) te[1] = 1;
		if(a1[st]==b) te[2] = 1;

	//	cout<<a<<" "<<b<<" "<<st<<" "<<en<<endl;
	//f(i,0,7) cout<<te[i]<<" ";
	//cout<<endl;
		return te;
	}

	ll mi = (st+en)/2;

	vector<lll> te1 =  solve(a,b,st,mi);
	vector<lll> te2 = solve(a,b,mi+1,en);

	
	f(i,0,7)
	{
		te[i] = te1[i] + te2[i];
	}

	te[3] += te1[1]*te2[2];
	te[4] += te1[2]*te2[1];
	te[5] += te1[3]*te2[1];
	te[5] += te1[1]*te2[4];

	te[6] += te1[4]*te2[2];
	te[6] += te1[2]*te2[3];

	te[0] += te1[1]*te2[6];
	te[0] += te1[3] * te2[3];
	te[0] += te1[5]*te2[2];


	//cout<<a<<" "<<b<<" "<<st<<" "<<en<<endl;
	//f(i,0,7) cout<<te[i]<<" ";
	//cout<<endl;
	return te;

}
*/
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

    	
    	f(i,0,n) cin>>a[i+1];

    	//ll co[n+1] = {0};
    	//f(i,0,n) co[i]=0;
    	//f(i,0,n) co[a1[i]]++;
    	
    	f(i,0,n+1) f(j,0,n+1) dp[i][j] = 0;

    	f(i,1,n+1)
    	{
    		dp[a[i]][i] = 1;

    		f(j,1,n+1)
    		{
    			dp[j][i]+=dp[j][i-1];
    		}
    	}

    	vector<ll> sb[n+1];

    	f(i,0,n) sb[a[i]].pb(i+1);


    	



    	

    	lll ans = 0;

    	f(i,1,n+1)
    	{
    		f(j,i+1,n+1)
    		{
    			ans+= dp[a[j]][i-1]*(dp[a[i]][n]-dp[a[i]][j]);
    		}
    	}
    	/*
    	f(i,1,n+1)
    	{
    		if(co[i]==0) continue;
    		f(j,1,n+1)
    		{
    			if(co[j]==0) continue;
    			ll ad = solve(i,j,0,n-1)[0];
    			ans+= ad;
    			//if(ad) cout<<i<<" "<<j<<" "<<ad<<endl;
    		}
    	}
    	*/
    	//ans+=solve(1,11,0,n-1)[0];
    	cout<<ans<<endl;
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
