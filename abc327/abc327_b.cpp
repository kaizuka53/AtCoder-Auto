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
	ll b;
	cin >> b;

	repl(i,15){
		ll a=i+1;
		ll c=b;
		bool flag=true;
		rep(j,a){
			if(c%a!=0){
				flag=false;
				break;
			}
			c/=a;
		}
		if(flag&&c==1){
			cout << a << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
		
}