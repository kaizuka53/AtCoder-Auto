#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (llabs)(n); i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int main(){
	int x,y;
	cin>>x>>y;
	int d=y-x;
	if(3>d&&d>-4){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	
	return 0;
		
}