#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (llabs)(n); i++)
using Graph = vector<vector<int>>;
#define ll long long
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

struct UnionFind{
	vector<int> par;

	UnionFind(int N):par(N){
		rep(i,N)par.at(i)=i;
	}

	int root(int x){
		if(par.at(x)==x)return x;
		par.at(x)=root(par.at(x));
		return par.at(x);
	}

	void unite(int x,int y){
		int rx=root(x);
		int ry=root(y);
		//cout<<"unite rx="<<rx<<" ry="<<ry<<endl;
		if(rx==ry) return;
		par.at(rx)=ry;
		return;
	}



	bool same(int x,int y){
		int rx=root(x);
		int ry=root(y);
		if(rx==ry){	
			return true;
		}else{
			return false;
		}
	}

	void printp(int n){
		rep(i,n)cout<<par.at(i)<<" ";
		cout<<endl;
	}

};

template<class Abel> struct UnionFindWithWeight {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFindWithWeight(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

vector<bool> seen;
int deep=0;
int deepmax=0;
bool flag=false;
int target=0;
void dfs(const Graph &G,int v){
	if(flag)return;
	seen.at(v)=true;
	deep++;
	deepmax=max(deepmax,deep);
	if(v==target){
		flag=true;
		return;
	}
	//cout<<"dfs v:"<<v<<" deep:"<<deep<<" deepmax:"<<deepmax<<endl;
	for(auto next_v:G.at(v)){
		if(seen.at(next_v))continue;
		dfs(G,next_v);
	}
	deep--;
	return;
}

int main(){
	int n,m;
	cin >> n >> m;
	UnionFindWithWeight<int> tree(n);
	vector<int> a(m);
	vector<int> b(m);
	rep(i,m){
		int A;
		cin>>A;
		a.at(i)=A-1;
		}
	rep(i,m){
		int B;
		cin>>B;
		b.at(i)=B-1;
		}

	Graph G(n);
	rep(i,m){
		//cout<<"check same a:"<<a.at(i)<<" b:"<<b.at(i)<<endl;
		if(tree.same(a.at(i),b.at(i))){
			if(tree.diff(a.at(i),b.at(i))%2==0){
				cout<<"No"<<endl;
				return 0;
			}
		}
		tree.unite(a.at(i),b.at(i),1);
		G.at(a.at(i)).pb(b.at(i));
		G.at(b.at(i)).pb(a.at(i));
	}
	
	cout<<"Yes"<<endl;

	return 0;
		
}