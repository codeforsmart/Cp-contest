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

    vector<ll> one, two, ze;

    f(i,0,n)
    {
    	if(a[i]%3==0) ze.pb(i);
    	else if(a[i]%3==1) one.pb(i);
    	else two.pb(i);
    }
    
    ll ons = one.size();
    ll tws = two.size();
    ll zes = ze.size();

    //cout<<ons<<" "<<tws<<" "<<zes<<endl;
    if((zes>ons + tws + 1) || (ons>0 && tws>0 && zes == 0) )
    {
    	cout<<"Impossible"<<endl;
    	return 0;
    }

    cout<<"Possible"<<endl;
    vector<ll> pr;
    ll twss = 0 , onss = 0;
    if(zes <= ons + tws)
    {
    	if(onss!=ons)
    		{
    			pr.pb(one[onss]);
    			onss++;
    		}
    		else if(tws!=twss)
    		{
    			pr.pb(two[twss]);
    			twss++;
    		}
    	f(i,0,zes)
    	{
    		pr.pb(ze[i]);
    		if(i==zes-1) continue;
    		if(onss!=ons)
    		{
    			pr.pb(one[onss]);
    			onss++;
    		}
    		else if(tws!=twss)
    		{
    			pr.pb(two[twss]);
    			twss++;
    		}
    	}

    	if(tws!=twss)
    	{
    		pr.pb(two[twss]);
    		twss++;
    	}
    	else if(onss!=ons)
    	{
    		pr.pb(one[onss]);
    		onss++;
    	}
    }
    else
    {
    		
    	f(i,0,zes)
    	{
    		pr.pb(ze[i]);
    		if(onss!=ons)
    		{
    			pr.pb(one[onss]);
    			onss++;
    		}
    		else if(tws!=twss)
    		{
    			pr.pb(two[twss]);
    			twss++;
    		}
    	}    	
    }
    

    ll sz = pr.size();
   // cout<<twss<<" "<<onss<<endl;
    f(i,0,sz)
    {
    	while(onss!=ons && a[pr[i]]%3==1)
    	{
    		cout<<one[onss]<<" ";
    		onss++;
    	}
    	while(tws!=twss  && a[pr[i]]%3==2)
    	{
    		cout<<two[twss]<<" ";
    		twss++;
    	}
    	cout<<pr[i]<<" ";
    }

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
