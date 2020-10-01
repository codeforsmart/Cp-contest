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

ll tree[4000005][2],lazy[4000005]={0};
void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node][0] += lazy[node];    // Update it
         tree[node][1] += lazy[node];
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node][0] += val;
         tree[node][1] += val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node][0] = max(tree[node*2][0],tree[node*2+1][0]);  
          // Updating root with max value 
    tree[node][1] = min(tree[node*2][1],tree[node*2+1][1]); 
}

pair<int,int> queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return {-mod,mod};         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node][0] += lazy[node];    // Update it
         tree[node][1] += lazy[node];       // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return {tree[node][0], tree[node][1]};
    int mid = (start + end) / 2;
    pair<int,int> p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    pair<int,int> p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return {max(p1.ff,p2.ff),min(p1.ss,p2.ss)};
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;

    char sb[n+2];
    memset(sb,'A',sizeof(sb));
    ll ind = 1;
    ll co = 0;
    char tu ;
    f(i,0,n)
    {
    	cin>>tu;

    	if(tu=='R')
    	{
    		ind++;
    		
    	}
    	else if(tu=='L')
    	{
    		ind--;
    		
    	}
    	else if(sb[ind]==tu) {}
    	else if(tu==')')
    	{
    		if(sb[ind]=='(')
    		{
    			co-=2;
    			updateRange(1,1,n,ind,n,-2);
    		}
    		else 
    		{
    			co--;
    			updateRange(1,1,n,ind,n,-1);
    		}
    		sb[ind] = tu;
    	}
    	else if(tu=='(')
    	{
    		if(sb[ind]==')')
    		{
    			co+=2;
    			updateRange(1,1,n,ind,n,2);
    		}
    		else 
    		{
    			co++;
    			updateRange(1,1,n,ind,n,1);
    		}

    		sb[ind] = tu;
    	}
    	else 
    	{
    		if(sb[ind]==')')
    		{
    			co++;
    			updateRange(1,1,n,ind,n,1);
    		}
    		else if(sb[ind]=='(')
    		{
    			co--;
    			updateRange(1,1,n,ind,n,-1);
    		}
    		sb[ind]=tu;
    	}

    	if(co==0)
    	{
    		pair<int,int> pk = queryRange(1,1,n,1,n);

    		if(pk.ss<0)
    		{
    			cout<<-1<<" ";
    		}
    		else cout<<pk.ff<<" ";
    	}
    	else cout<<-1<<" ";
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
