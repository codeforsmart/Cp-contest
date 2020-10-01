#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

ll w[100005]={0,1,1};
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    f(3,100002) w[i]+=(w[i-1]+w[i-2]+w[i-3])%mod;

    /*f(0,10) cout<<w[i]<<" ";
    cout<<endl;*/
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	ll a[n];
    	f(0,n) cin>>a[i];
    	ll coun=0; ll st=n;
    	f(0,n)
    	{
    		if(a[i]==1) coun++;
    		else 
    		{
    			st=i;
    			break;
    		}
    	}
 
    	ll ans=coun;
    	ans=(ans%mod);
    	if(st==n)
    	{
    		cout<<ans<<endl;
    		continue;
    	}

    	vector<ll> va;
    	vector<ll> co;

    	va.pb(2);
    	co.pb(1);
    	ll ind=0;
    	ll com=2;

    	f(st+1,n)
    	{
    		if(a[i]!=com)
    		{
    			ind++;
    			va.pb(a[i]);
    			co.pb(1);
    			com=a[i];
    		}
    		else
    		{
    			co[ind]++;
    		}
    	}


    	ll ways=1,le;
    	ll w1=1,w2=0,w3=0;

    	for(ll p=0;p<=ind;p++)
    	{
    		le=co[p];

    		ways=ways%mod;
    		if(va[p]==2)
    		{

    			ans+=ways;
    			ans=ans%mod;
    			for(ll o=2;o<=le;o++)
    			{
    				ans+=(w[o])*ways;
    				ans=ans%mod;
    				ll d=le-o;
    				if(d%2==0 && p==ind) ans+=(( (((d/2)*2)*w[o-1])%mod)*ways)%mod;
    				else ans+= (( ( ((d/2)*2+1)*w[o-1]) %mod )*ways)%mod;

    				ans=ans%mod;
    				if(p+2<=ind && d%2==0 && co[p+1]==1)
    				{
    					ans+=(w[o-1]*ways)%mod;
    				}
    				ans=(ans%mod);
    				//cout<<"case2 take "<<p<<" "<<o<<" "<<ans<<endl;
    			}

    			w1=w[le]*ways;
    			if(le>=2) w2=w[le-1]*ways;
    			else w2=0;
    			if(le>=3) w3=w[le-2]*ways;
    			else w3=0;

    			w1=w1%mod; w2=w2%mod; w3=w3%mod;

    		}
    		else
    		{
    			if(p==ind && le==1)
    			{
    				ans+=(w1+w2+w3)%mod;
    				ans=ans%mod;
    			}
    			else if(le==1)
    			{
    				ll le2=co[p+1];
    				ll d2=le2-2;

    				ans+= 2*le*w1;
    			ans+= (2*le-1)*w2;
    		//	ans+=w2;
    			ans+= le*w3;

    			ans=ans%mod;
	    			if(d2>=0)
	    			{
	    				ans+=w1;
	    					ans=ans%mod;
	    				if(p+1==ind && d2%2==0)
	    				{
	    					ans+=((d2/2)*(w1*2)%mod)%mod;
	    					ans=ans%mod;
	    				}
	    				else
	    				{
	    					ans+=(((d2/2)*2+1)*w1)%mod;
	    					ans=ans%mod;
	    					if(p+3<=ind && d2%2==0 && co[p+2]==1)
	    					{
 								ans+=w1;
	    					}
	    					ans=ans%mod;
	    				}
	    				ans=ans%mod;
	    			}
    			}
    			else
    			{
    			ans+= (((2*le)%mod)*w1)%mod;
    			ans=ans%mod;
    			ans+= ((2*le-1)*w2)%mod;
    			ans+= (le*w3)%mod;
    			ans=ans%mod;
    			}

    			if(le==2 && p+1<=ind)
    			{
    				ans+=w1;
    				ans=ans%mod;
    			}
    			

    			ways=(w1*2+w2*2+w3)%mod;
    		}
    		ans=ans%mod;
    		//cout<<"w1 = "<<w1<<" w2="<<w2<<" w3="<<w3<<" ways = "<<ways<<endl;
    //	cout<<" case = "<<p<<" "<<ans<<endl;
    	}

    //	ans+=mod;
    //	if(va[ind]==1 && co[ind]==1) ans-=w1;
    	ans=ans%mod;
    //	if(ans<0) ans+=mod;

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