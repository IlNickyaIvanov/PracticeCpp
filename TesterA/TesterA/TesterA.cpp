#include <iostream>
#include <time.h>
using namespace std;


int main() {
	srand(time(0));
	int n = 0;
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Input n: ";
	cin >> n;
	switch (n) {
		case(1):
			int *m;
			for (int i = 0; i < 10; i++) {
				m = a+i;
				for (int j = i + 1; j < 10; j++)
					if (*m > a[j])
						m = a+j;
				if (*m != a[i])
					swap(*(a + i), *m);
			}
			for (int i = 0; i < 10; i++) 
				cout << a[i] << " ";
		break;
		case(2):
			int x;
			for (int i = 1; i < 10; i++) {
				x = a[i];
				int j = i;
				while (j > 0 && a[j - 1] > x) {
					a[j] = a[j - 1];
					j--;
				}
				a[j] = x;	
			}
			for (int i = 0; i < 10; i++)
				cout << a[i] << " ";
		break;
		case(3):
			int lo, hi, mid;
			for (int i = 1; i < 10; i++) {
				if (a[i - 1] > a[i]) {
					x = a[i];
					lo = 0;
					hi = i - 1;
					do {
						mid = (lo + hi) / 2;
						if (a[mid] < x) lo = mid + 1;
						else  hi = mid - 1;
					} while (lo <= hi);
					for (short j = i - 1; j >= lo; j--)
						a[j + 1] = a[j];
					a[lo] = x;
				}
			}
			for (int i = 0; i < 10; i++)
				cout << a[i] << " ";
		break;
	}
	cout << endl <<endl; 
	main();
	return 0;
}