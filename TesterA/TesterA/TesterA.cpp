#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int find(string line, char c ) {
	for (int i = 0; i < line.size(); i++)
		if (line[i] = c)
			return i;
	return -1;
}

int main(int argC, char *argV[]) {
	int num = 0;
	cin >> num;
	if (num == 1) {
		fstream file((argC > 1)?argV[1]:"test.txt", ios::in);
		float s = 0;
		int c = 0;
		string n = "";
		if (!file) {
			cout << "File did't open.";
			return 0;
		}
		while (!file.eof()) {
			file >> n;
			s += stoi(n);
			c ++;
		}
		cout << (float)(s / c);
	}
	if (num == 2) {
		string line,word;
		fstream file("text.txt", ios::in);
		cout << "Input word! "; cin >> word;
		if (!file) {
			cout << "File did't open.";
			return 0;
		}
		while(!file.eof()){
			getline(file, line);
			if (line.find(word)!=-1)
				cout << line << endl;
		}
	}
	if (num == 3) {
		string text,line, word;
		word = "?";
		fstream file("text2.txt", ios::in);
		while (!file.eof()) {
			if(text.size()==0)
				getline(file, line);
			text += line;
			line = "";
			if (text.find("?") != -1) {
				cout << text.substr(0, text.find("?") + 1) << endl;
				text = text.substr(text.find("?") + 1, text.size());
			}
			else if (text.find(".") != -1) {
				text = text.substr(text.find(".")+1, text.size());
			}
			else if (text.find("!") != -1) {
				text = text.substr(text.find("!")+1, text.size());
			}
		}
	}
	//abracadanra
	return 0;
}