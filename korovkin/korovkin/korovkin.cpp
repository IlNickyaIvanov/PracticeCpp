#include <iostream>
using namespace std;
int static count = 0;

void check_board(int *a,int s){
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			*a = (i + j) % 2;
			a += 1;
		}
	}
}

int main()
{
	int a[4][4];
	
	check_board(*a, 4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}