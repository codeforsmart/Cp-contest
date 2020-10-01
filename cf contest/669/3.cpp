#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
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
 /*
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 */
    ll n;
    cin>>n;
    cout.flush();
    
    ll vis[n+1]={0};

    ll a = 1, b = 2;

    ll sb[n+1] = {0};

    f(i,1,n+1)
    {
    	vis[i] = 0;
    	sb[i] = 0;
    }

    while(b<=n)
    {
    	//cout<<"it"<<endl;
    	ll ans1,ans2;
    	//f(a==b) return 0;
    	cout<<"? "<<a<<" "<<b<<endl;
    	cout<<flush;
    	cin>>ans1;
    	cout<<flush;

    	cout<<"? "<<b<<" "<<a<<endl;
    	cout<<flush;
    	cin>>ans2;
    	cout<<flush;
    	if(ans1>ans2)
    	{
    		vis[ans1] = 1;
    		sb[a] = ans1;

    	//	debug(a);
    	//	debug(ans1);
    		a = b;
    	}
    	else
    	{
    		vis[ans2] = 1;
    		sb[b] = ans2;
    //		debug(b);
    	//	debug(ans2);
    	}

    	if(ans1==-1 || ans2==-1) return 0;
    	b++;
    }

    ll mi = 0;

    f(i,1,n+1)
    {
    	if(vis[i]!=1)
    	{
    		mi = i;
    		break;
    	}
    }

    f(i,1,n+1)
    {
    	if(sb[i]==0)
    	{
    		sb[i] = mi;
    		break;
    	}
    }
    

    cout<<"! ";
    f(i,1,n+1) cout<<sb[i]<<" ";
    cout<<endl;
    cout<<flush;
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
