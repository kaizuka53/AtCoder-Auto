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
	int n;
	string s;
	cin >> n >> s;
	rep(i,n-1){
		if(s[i] =='a'&& s[i+1]=='b'){
			cout << "Yes" << endl;
			return 0;
		}else if(s[i] =='b'&& s[i+1]=='a'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
		
}