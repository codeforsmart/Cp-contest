#include<bits/stdc++.h>
#define int unsigned long long int
#define ll int
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
int gcde(int a, int b, int *x, int *y)  
{  
    // Base Case  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    int x1, y1; // To store results of recursive call  
    int gcd = gcde(b%a, a, &x1, &y1);  
  
    // Update x and y using results of  
    // recursive call  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
} 
signed main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    int n,p,w,d;
    cin>>n>>p>>w>>d;

    int x,y;
    int g = gcde(w,d,&x,&y);

    if(p%g!=0)
    {
    	cout<<-1<<endl;
    	return 0;
    }

    p/=g;

    x*=p;
    y*=p;
    w = w/g;
    d = d/g;
   // cout<<p<<" "<<x<<" "<<y<<endl;
  	if(x<0)
  	{
  		int ex = (-x)/d + ((-x)%d!=0);
  		if(y-ex*w>=0)
  		{
  			y -=ex*w;
  			x+=ex*d;
  		}
  	}
  	else if(y<0)
  	{
  		int ex = (-y)/w + ((-y)%w!=0);
  		if(x-ex*d>=0)
  		{
  			x -=ex*d;
  			y+=ex*w;
  		}
  	}
    
    if(x>=0 && y>=0)
    {
    		while(y-w>=0)
    		{
    			y-=w;
    			x+=d;
    			if(x+y<=n) break;
    		}
    	
    }


    if(x<0 || y<0 || x+y>n || x*w+y*d!=p || x>n || y>n) 
    {
    	cout<<-1<<endl;
    	return 0;
    } 

    //cout<<x+y-n<<endl;
    cout<<x<<" "<<y<<" "<<n-x-y<<endl;
    
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
