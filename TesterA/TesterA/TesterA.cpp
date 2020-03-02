#include <iostream>
#include <string>
#include <iostream>
#include <random>

#include <time.h>

#include "TesterA.h"
using namespace std;

template <typename T> class Storage {
private:
	T* data;
	size_t size;
public:
	Storage() {
		data = nullptr;
		size = 0;
	};

	void add(T e) {
		T* ndata = new T[size + 1];
		for (int i = 0; i < size; i++) {
			ndata[i] = data[i];
		}
		ndata[size] = e;
		delete[]data;
		data = ndata;
		size++;
	}

	T get(size_t i) {
		if (i < size)
			return data[i];
	}

	size_t lenght() {
		return size;
	}

	void rev() {
		T* ndata = new T[size];
		for (int i = size-1; i >= 0; i--) {
			ndata[size-1-i] = data[i];
		}
		delete[]data;
		data = ndata;
	}

	void del(size_t e) {
		if (e < size) {
			T* ndata = new T[size-1];
			for (int i = 0; i < e; i++) {
				ndata[i] = data[i];
			}
			for (int i = e + 1; i < size; i++) {
				ndata[i - 1] = data[i];
			}
			delete[]data;
			data = ndata;
			size--;
		}
	}
};

int* maxEl(int* matrix[]) {
	int coor [2] = { 0,0 };
	int m = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (matrix[i][j] > m) {
				coor[0] = i;
				coor[1] = j;
				m = matrix[i][j];
			}
	return coor;
}

int main() {
	int num = 0;
	cout << "Input task: ";
	cin >> num;
	if (num == 1) {
		Storage<int> storage;
		string line;
		cin.ignore();
		cout << endl;
		getline(cin, line);
		string num;

		for (int i = 0; i < line.length() + 1; i++) {
			if (i == line.length() && num != "")
				storage.add(stoi(num));
			if (line[i] == ' ' && num != "") {
				storage.add(stoi(num));
				num = "";
			}
			else if (line[i] != ' ') {
				num += line[i];
			}
		}

		storage.rev();
		size_t s = 1;
		while (s < storage.lenght()) {
			if (storage.get(s - 1) == storage.get(s))
				storage.del(s);
			else
				s++;
		}

		for (int i = 0; i < storage.lenght(); i++) {
			cout << storage.get(i) << " ";
		}
	}
	if (num == 2) {
		srand(time(0));
		int* matrix[10];
		for (int i = 0; i < 10; i++) {
			matrix[i] = new int[10];
			for (int j = 0; j < 10; j++)
				matrix[i][j] = rand() % 1000;
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}

		cout << endl;

		for (int i = 0; i < 10; i++) {
			int *coor = maxEl(matrix);
			swap(matrix[i][i], matrix[coor[0]][coor[1]]);
			for (int j = 0; j < 10; j++)
				cout << matrix[i][j] << " ";
			matrix[i][i] = 0;
			cout << endl;
		}

	}
	if (num == 3) {
		srand(time(0));
		int n;
		cout << "Input n: "; cin >> n; 
		vector<int> a;
		int c;
		for (int i = 0; i < 2 * n; i++) {
			cin >> c;
			a.push_back(c);
		}
		sort(a.begin(), a.end());
		cout << endl;
		for (int i = 0; i < a.size()/2; i++) {
			cout << a[i] << " " << a[2*n-1-i];
			cout << endl;
		}
	}
	cout << endl;
	main();
	return 0;
}