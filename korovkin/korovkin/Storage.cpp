#pragma once

#include <iostream>
using namespace std;
#define T int 


class Storage {
private:
	T* data;
	size_t size;

public:
	Storage() {
		data = nullptr;
		size = 0;
	}

	void AddElem(T val) {
		if (data == nullptr) {
			data = new T[1];
			data[0] = val;
			size = 1;
		}
		else {
			T* buf = new T[size + 1];
			for (size_t i = 0; i < size; i++) {
				buf[i] = data[i];
			}
			buf[size] = val;
			delete[] data;
			data = buf;
			size++;
		}
	};

	T GetElemByNum(size_t num) {
		return data[num];
	};
	size_t TotalSize() {
		return size;
	};

};

bool testStorage4() {
	Storage storage;
	for (T k = 0; k < 4; k++) {
		storage.AddElem(k);
	}
	if (storage.TotalSize() != 4) return false;
	for (T k = 0; k < 4; k++) {
		if (storage.GetElemByNum(k) != k) {
			cout << storage.GetElemByNum(k) << k << endl;
			return false;
		}
	}
	return true;
}
