#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


int next_id=0;
string street_name;
map<string,int>encode_ID;
map<int,string>decode_ID;

class street{
public:
	int Begin; int End; int Length; int Id;
	void read(){
		cin>>Begin; cin>>End;
		cin>>street_name;
		if(encode_ID.find(street_name)==encode_ID.end()){
			encode_ID[street_name]=next_id++;
			decode_ID[next_id-1]=street_name;
		}
		Id=encode_ID[street_name];
		cin>>Length;
	}
};
int ma = 0;
class car{
public:
	int num_streets;
	vector<int>sequence;
	void read(){
		cin>>num_streets;
		ma = max(ma,num_streets);
		//cout<<num_streets<<"YO"<<endl;
		sequence.resize(num_streets);
		for(int i=0;i<num_streets;i++){
			cin>>street_name;
			sequence[i]=encode_ID[street_name];
		}
	}
};

class street_Map{
public:
	int intersections; int count_streets; int count_cars;
	vector<street>streets; vector<car>cars;
	int finish_score; int duration;
	void read(){
		cin>>duration; cin>>intersections; cin>>count_streets; cin>>count_cars; cin>>finish_score;
		streets.resize(count_streets); cars.resize(count_cars);
		for(int i=0;i<count_streets;i++){
			streets[i].read();
		}
		for(int i=0;i<count_cars;i++){
			cars[i].read();
		}
	}
};

vector<pl> tr[100005];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("/home/savish/Downloads/e.txt", "r", stdin);
		freopen("e_out.txt", "w", stdout);
	#endif
	street_Map St;
	St.read();
	//cout<<ma<<" ss"<<endl;
	int I = St.intersections;
	vector<street>streets = St.streets;
	map<int, street>id_to_street;
	for(auto st: streets)
	{
		id_to_street[st.Id] = st;
	}
	vector<car>cars = St.cars;
	int t_strts = streets.size();
	int used_streer[t_strts] = {0};
	int inter_traffic[I] = {0};
	int total_seq_inter[I] = {0};
	int total_seq_street[t_strts] = {0};
	for(auto cr: cars)
	{
		vector<int>sequence = cr.sequence;
		int szz = sequence.size();
		int preD = 0;
		for(int i = 0;i < szz-1;i++)
		{
			int stId = sequence[i];
			street st = id_to_street[stId];
			used_streer[st.Id] += 1;
			inter_traffic[st.End] += 1;
			total_seq_street[st.End] += preD;
			preD += st.Length;
		}
	}

	/*for(auto pp: used_streer)
	{
		cout<<pp<<endl;
	}
	cout<<"END"<<endl;*/
	for(auto st : streets)
	{
		tr[st.End].pb(mp(st.Begin,st.Id));
	}
	//cout<<I<<endl;
	vector<pair<int, vector<pair<string,int> > > > pr_out;
	for(int i = 0; i < I;i++)
	{
		//cout<<i<<endl;
		int szz = tr[i].size();
		for(auto a: tr[i])
		{
			if(used_streer[a.ss] == 0)
			{
				szz--;
			}
			//cout<<decode_ID[a.ss]<<" "<<1<<endl;
		}

		if(szz==0) continue;
		//cout<<szz<<endl;
		vector<pair<string,int> >temp;
		for(auto a: tr[i])
		{
			if(used_streer[a.ss] == 0)
			{
				continue;
			}
			//cout<<decode_ID[a.ss]<<" "<<1<<endl;
			double rr = used_streer[a.ss]/inter_traffic[i];
			int mi = 1;
			if(used_streer[a.ss]>3)
			{
				mi = 2;
			}
			int fv = max(mi, int(rr*12));

			/*if(used_streer[a.ss]>=8)
			{
				fv += used_streer[a.ss]/8;
			}
			if(used_streer[a.ss]>=10)
			{
				cout<<"YES"<<used_streer[a.ss]<<endl;
				fv += 50;
			}*/

			//cout<<total_seq_street[i]<<" "<<used_streer[a.ss]<<" "<<inter_traffic[i]<<endl;

			fv = used_streer[a.ss];
			temp.pb(mp(decode_ID[a.ss],fv));
		}

		int sszz = temp.size();
		int su = 0;
		for(auto &a:temp)
		{
			su+=a.ss;
		}

		for(auto &a:temp)
		{
			a.ss = max(1,int((a.ss*8)/su));
		}
		//cout<<endl;
		pr_out.pb(mp(i,temp));

	}
	//cout<<I<<" "<<pr_out.size()<<endl;
	cout<<pr_out.size()<<endl;
	for(auto pr: pr_out)
	{
		cout<<pr.ff<<endl;
		cout<<pr.ss.size()<<endl;;
		for(auto s_time: pr.ss)
		{
			cout<<s_time.ff<<" "<<s_time.ss<<endl;
		}
	}
	return 0;
}
