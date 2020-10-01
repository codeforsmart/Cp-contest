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
ll n;
ll dif(ll a, ll b)
{
	if(b>=a) return b-a;
	else return n-a+b;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    
    cin>>n;
    ll a[n];
    f(i,0,n) cin>>a[i];

    vector< pair<ll,ll> > sb;
    f(i,0,n) sb.pb(mp(a[i],i));
    sort(sb.begin(),sb.end());

    bool min = 0;

    ll ip = sb[n-1].ss;
    ll ma = 0;
    for(ll j = 0;j<n;j++)
    {
    	ll j1 = (j+ip)%n;
    	ma = max(ma,a[j1]);

    	if(2*a[j1]<ma)
    	{
    		min = 1;
    		break;
    	}
    }

    if(min==0)
    {
    	f(i,0,n) cout<<-1<<" ";
    	cout<<endl;
    	return 0;
    }
    ll ka[n]={0};
    bool ans[n]={0};
    //f(i,0,n) ka[i] = (i+1)%n;
    f(i,0,n)
    {
    	ll i1 = sb[n-i-1].ss;
    	ll va = sb[n-i-1].ff;
        if(ans[i1]) continue;
    	vector<ll> msm;
    	if(ka[i1]>0) msm.pb(i1);
    	ll kahan = -1,ino = -1;
    	ll in2 = -1;
    	ll co = ka[i1];
        if(ka[i1]==0) co=-1;
    	for(ll j = 0;j<2*n+1;j++)
    	{
    		co++;
    		ll j1 = (i1+j+ka[i1])%n;
    		if(ans[j1])
    		{
    			kahan = ka[j1];
    			ino = j1;
    			break;
    		}
    		if(a[j1]*2<va)
    		{
                in2 = j1;
    			break;
    		}
    		msm.pb(j1);
    	}
    	ll sz = msm.size();
    	if(kahan!=-1)
    	{
    		
    		f(j,0,sz)
    		{
    			ans[msm[j]]=1;
    			ka[msm[j]] = dif(msm[j],ino) + kahan ;
    		}
    	}
    	else
    	{
    		ans[i1] = 1;
    		ka[i1] = co;
            f(j,1,sz)
            {
                //ans[msm[j]]=1;
                ka[msm[j]] = dif(msm[j],in2);
             //   cout<<j<<" "<<ka[msm[j]]<<" "<<msm[j]<<endl;
            }
    	}
       // cout<<ka[i1]<<" "<<i1<<" "<<ino<<" "<<kahan<<" "<<dif(i1,ino)<<endl;
       // if(i==1)return 0;
    }
    
    f(i,0,n) cout<<ka[i]<<" ";
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
