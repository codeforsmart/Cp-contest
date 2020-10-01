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
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

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
    	ll p[n+1]={0};
    	f(i,1,n+1) cin>>p[i];
    	ll c[n+1]={0};
    	f(i,1,n+1) cin>>c[i];

    	ll vis[n+1]={0};

    	vector<ll>sb[n+1];
    	f(i,1,n+1)
    	{
    		if(vis[i]==1) continue;

    		vis[i]=1;
    		sb[i].pb(i);
    		ll j = i;
    		while(p[j]!=i)
    		{
    			sb[i].pb(p[j]);
    			j = p[j];
    			vis[j] = 1;
    		}
    	}

    	ll st = 1, en = n;
    	/*debug(t);
    	f(i,1,n+1)
    	{
    		if(sb[i].size()==0) continue;
    		f(j,0,sb[i].size()) cout<<sb[i][j]<<" ";
    		cout<<endl;
    	}*/
    	//cout<<"ok"<<endl;
    	for(ll mi = 1; mi<=n;mi++)
    	{


    		//cout<<st<<" "<<en<<" "<<mi<<endl;
    		bool ok = 0;
    		bool msm[n+1]={0};
    		f(i,1,n+1)
    		{

    			ll sz = sb[i].size();
    			f(j,0,sz)
    			{
    				if(msm[sb[i][j]]==1) continue;
    				msm[sb[i][j]]=1;
    				ll pp = j;
    				ll ch = c[sb[i][j]];
    				//cout<<ch<<" ssss "<<j<<endl;
    				ok = 1;
    				while((pp+mi)%sz!=j)
    				{
    					pp = (pp +mi)%sz;
    					msm[ sb[i][pp] ] = 1;
    					if(c[sb[i][pp]]!=ch)
    					{
    						ok = 0;
    						break;
    					}
    				}
    				//if(ok==1) debug(i);
    				if(ok==1) break;
    			}

    			if(ok==1) break;
    			
    		}

    		//if(ok==0) st = mi+1;
    		//else en = mi;

    		if(ok==1)
    		{
    			cout<<mi<<endl;
    			break;
    		}
    	}

    //	cout<<st<<endl;
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
