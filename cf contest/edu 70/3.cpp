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

    ll t;
    cin>>t;
    while(t--)
    {
    	string s;
    	cin>>s;
    	ll vmi=0,vma=0;
    	ll l = s.length();
    	ll co = 0;
    	ll sdmi=0,sdma=0;
    	ll sdmi1=0,sdma1=0;
    	f(0,l)
    	{
    		if(s[i]=='S') co--;
    		else if(s[i]=='W') co++;
    		vmi=min(vmi,co);
    		vma=max(vma,co);
    		sdma=max(sdma,vma-co);
    		sdmi=max(sdmi,co-vmi);
    	}
    	ll l1 = vma-vmi;
    	ll vmi1=0,vma1=0,co1=0;
    	f(0,l)
    	{
    		if(s[i]=='A') co1--;
    		else if(s[i]=='D') co1++;
    		vmi1=min(vmi1,co1);
    		vma1=max(vma1,co1);
    		sdma1=max(sdma1,vma1-co1);
    		sdmi1=max(sdmi1,co1-vmi1);
    	}
    	ll l2 = vma1-vmi1;

    	ll ar = (l1+1)*(l2+1);

    	if(l1>1 && (sdma!=sdmi)) ar = min(ar,(l1)*(l2+1));
    	if(l2>1 && (sdma1!=sdmi1)) ar = min(ar,(l1+1)*(l2));
    	cout<<ar<<endl;
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