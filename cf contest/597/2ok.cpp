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

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a,b,c;
        cin>>a>>b>>c;

        string s1;
        cin>>s1;

        char pr[n];

        f(i,0,n)
        {
            if(s1[i]=='R' && b>0)
            {
                b--;
                pr[i]='P';
            } 
            else if(s1[i]=='P' && c>0) 
            {
                c--;
                pr[i]='S';
            }
            else if(s1[i] == 'S' && a>0)
            {
                a--;
                pr[i]='R';
            }
            else pr[i]='a';
        }

        f(i,0,n)
        {
            if(pr[i]=='a')
            {
                if(b>0)
                {
                    b--;
                    pr[i]='P';
                } 
                else if(c>0) 
                {
                    c--;
                    pr[i]='S';
                }
                else if(a>0)
                {
                    a--;
                    pr[i]='R';
                }   
            }
        }

        ll ans1 = 0;

        f(i,0,n)
        {
            if(pr[i]=='R' && s1[i]=='S') ans1++;
            else if(pr[i]=='P' && s1[i]=='R') ans1++;
            else if(pr[i]=='S' && s1[i]=='P') ans1++;
        }

        if(ans1*2 < n)
        {
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
        f(i,0,n)
        {
            cout<<pr[i];
        }
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
