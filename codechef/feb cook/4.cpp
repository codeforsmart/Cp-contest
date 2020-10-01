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
ll a[100008]={0};
ll l[100008]={0};
  ll r[100008]={0};
ll n,k;
ll tree[400009][2]={0};
void build(int node, int start, int end)
{
    if(start == end)
    {
        if(a[start]==k+1) tree[node][1]=1;
        else tree[node][1]=0;

        if(a[start]==k) tree[node][0]=1;
        else tree[node][0]=0;
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node][1] = tree[2*node][1] + tree[2*node+1][1];
         tree[node][0] = tree[2*node][0] + tree[2*node+1][0];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node][1]-tree[node][0];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	

        ll t;
        cin>>t;
        ll ma= 100000;
        while(t--)
        {
        	
        	cin>>n>>k;
        	
        	f(0,ma+2)
        	{
        		a[i]=0;
        		l[i]=0;
        		r[i]=0;
        	}
        	
        	ll x,y;
        	ll l1[n],r1[n];
        	f(0,n)
        	{
        		cin>>x>>y;
        	
        		l1[i]=x; r1[i]=y;
        		l[x]++;
        		r[y+1]++;
        	}

        	f(1,ma+1) l[i]+=l[i-1];
        	f(1,ma+1) r[i]+=r[i-1];
        	f(1,ma+1) a[i]=(l[i]-r[i]);
     //  	f(1,ma+1) cout<<a[i]<<" ";

        	//cout<<endl;
        	ll ans=0;
        	ll ans1=0;
        	f(1,ma+1) if(a[i]==k) ans1++;
        	build(1,1,ma);
        	ll q;
        	f(0,n)
        	{
        		q=query(1,1,ma,l1[i],r1[i]);
        		ans=max(ans,ans1+q);
        		//cout<<q<<" "<<ans<<endl;
        	}

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