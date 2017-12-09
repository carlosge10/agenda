#include <iostream>
#include <string>
using namespace std;

#define MAX 33

int mat[MAX][MAX];

bool outside(int x, int y, int r, int c) {
	int i,corners=0;
	bool is_corner = false;
	for(i=x;i>=0;i--) {
		if(mat[i][y] == 1) {
			is_corner = true;
			break;
		}
	}
	if(is_corner) {
		is_corner = false;
		corners++;
	}
	for(i=y;i<c;i++) {
		if(mat[x][i] == 1) {
			is_corner = true;
			break;
		}
	}
	if(is_corner) {
		is_corner = false;
		corners++;
	}
	for(i=x;i<r;i++) {
		if(mat[i][y] == 1) {
			is_corner = true;
			break;
		}
	}
	if(is_corner) {
		is_corner = false;
		corners++;
	}
	for(i=y;i>=0;i--) {
		if(mat[x][i] == 1) {
			is_corner = true;
			break;
		}
	}
	if (is_corner)
		corners++;
	return corners < 4;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int r,c;
		cin>>r>>c;
		string row;
		for(int i = 0; i < r; i++) {
			cin>>row;
			for(int j = 0; j < c; j++) {
				mat[i][j] = row[j] - 48;
			}
		}
		unsigned long long count = 0;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(!mat[i][j] && outside(i,j,r,c)) {
					count++;
				}
			}
		}
		cout<<count<<endl;
		count = 0;
	}
	return 0;
}