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
ll ek[1000002]={0};
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

    ll co = 0;

    ll ans = 0;
    ll v[1000001]={0};
    ll la = 0;
    vector<ll> pr;
    f(i,0,n)
    {
    	if(a[i]<0)
    	{
    		if(v[-a[i]]==0)
    		{
    			ans = 1;
    			break;
    		}
    		else v[-a[i]]=0;
    		co--;
    	}
    	else
    	{
    		if(v[a[i]]>0)
    		{
    			ans = 1;
    			break;
    		}
    		else v[a[i]]=1;
    		co++;
    	}

    	if(co==0)
    	{
    		pr.pb(i-la+1);
    		la = i+1;
    	}
    	//cout<<ans<<endl;
    }
    
    if(ans || co!=0) cout<<-1<<endl;
    else
    {
    	ll sz = pr.size();
    	ll ind = -1;
    	ll ind2 = -1;
    	f(i,0,sz)
    	{
    		
    		f(j,0,pr[i])
    		{
    			ind++;
    			if(a[ind]>0)
    			{
    				if(ek[a[ind]]==1) 
    				{
    					ans = 1;
    					break;
    				}
    				else ek[a[ind]]=1;
    			} 
    		}

    		f(j,0,pr[i])
    		{
    			ind2++;
    			if(a[ind2]<0)
    			{
    				ek[-a[ind2]]--;
    			} 
    		}
    	}

    	if(ans) {cout<<-1<<endl; return 0;}
    	cout<<pr.size()<<endl;
    	f(i,0,pr.size()) cout<<pr[i]<<" ";
    	cout<<endl;
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
