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

    string n;
    cin>>n;
   // ll p=1;
   
    ll l=n.length();

    if(l==1) 
    {
    	cout<<n<<endl;
    	return 0;
    }

    ll p9[l]={1};
    f(1,l) p9[i]=p9[i-1]*9;
    ll f1 = n[0]-'0';
    ll f2= n[1]-'0';
    ll on=1;
    ll p=1;
    ll pr=1,p1;
    f(0,l)
    {
    	ll va = (n[i]-'0');
    	if(i==0)  p1= pr * max(on,( va-on) ) * p9[l-i-1];
    	else  p1= pr * max(on,(va-1)) * p9[l-i-1];

    	pr *= va;

    	p=max(p,p1);
    }

    p=max(p,pr);

    cout<<p<<endl;
    
    
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