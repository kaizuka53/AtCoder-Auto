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
	vector<vector<int>> masu(9, vector<int>(9));
	rep(i, 9)rep(j, 9)cin >> masu[i][j];
	


	rep(i, 9){
		vector<bool> check(9, false);
		rep(j, 9){
			if(check[masu[i][j]-1]){
				cout <<"No" << endl;
				return 0;
			}
			check[masu[i][j]-1] = true;
		}
	}

	rep(i, 9){
		vector<bool> check(9, false);
		rep(j, 9){
			if(check[masu[j][i]-1]){
				cout <<"No" << endl;
				return 0;
			}
			check[masu[j][i]-1] = true;
		}
	}

	rep(i,3){
		rep(j,3){
			vector<bool> check(9, false);
			rep(k,3){
				rep(l,3){
					if(check[masu[i*3+k][j*3+l]-1]){
						cout <<"No" << endl;
						return 0;
					}
					check[masu[i*3+k][j*3+l]-1] = true;
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
		
}