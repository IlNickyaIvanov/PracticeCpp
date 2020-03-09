#include <iostream>
#include <string>
#include <iostream>

#include "TesterA.h"
#include <vector>
#include <algorithm>
using namespace std;

class StringNum {
public:
	string num="";
	StringNum(string n) {
		num = n;
	}
	StringNum(int n) {
		num = to_string(n);
	}
	StringNum(const StringNum &other) {
		this->num = other.num;
	}

	StringNum operator *(const StringNum& other) {
		StringNum res("0");
		vector <string> nums;

		string mul_ed = num;
		string mul_er = other.num;
		reverse(mul_ed.begin(), mul_ed.end());
		reverse(mul_er.begin(), mul_er.end());

		int rem = 0;
		string r = "";
		for (int i = 0; i < mul_er.size(); i++) {
			for (int j = 0; j < mul_ed.size(); j++) {
				rem = (mul_er[i] - '0') * (mul_ed[j] - '0') + rem;
				r += to_string(rem % 10);
				rem /= 10;
			}
			if (rem != 0)
				r += to_string(rem);
			reverse(r.begin(), r.end());
			r += string(i, '0');
			nums.push_back(r);
			r = "";
			rem = 0;
		}
		StringNum R("");
		for (int i = 0; i < nums.size(); i++) {
			R = R + StringNum(nums[i]);
		}
		return R.num;
	}

	StringNum operator + (const StringNum &other) {
		StringNum res("");
		string a = num;
		string b = other.num;
		string r;
		int rem=0;

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		for (int i = 0; i <= max(a.size(), b.size()); i++) {
			if (i < a.size() && i < b.size()) {
				rem = rem + a[i] - '0' + b[i] - '0';
				r += to_string(rem % 10);
				rem = rem / 10;
			}
			else if (i < a.size()) {
				rem = rem + a[i] - '0';
				r += to_string(rem%10);
				rem = rem / 10;
			}
			else if (i < b.size()) {
				rem = rem + b[i] - '0';
				r += to_string(rem % 10);
				rem = rem / 10;
			}
			else if (rem > 0)
				r += to_string(rem);
		}
		reverse(r.begin(), r.end());
		res.num = r;
		return res;
	}
};

string factorial(int fac) {
	StringNum p(2);
	if (fac == 1)
		return "1";
	if (fac == 2)
		return "2";
	for (int i = 3; i <= fac; i++) {
		p = p * StringNum(to_string(i));
	}
	return p.num;
}

int main() {
	//string text = "asdas";
	//text += string(3,'0');
	//cout << text;
	//StringNum C = StringNum(123456) * StringNum(7654);
	//cout << C.num;
	cout << factorial(3);
	return 0;
}