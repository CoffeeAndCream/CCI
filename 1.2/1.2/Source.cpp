//Cracking the Coding Interview
//Chapter 1
//Interview Question 1.2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverse(char*);

int main(){
	char *str = "It's getting late."; 
	reverse(str);

	system("pause");
	return 0;
}

void reverse(char *str){
	//reverses a null-terminated string
	string s(str);
	vector<char> reverse;
	for (auto i : s){
		reverse.push_back(i);
	}

	for (auto character = reverse.crbegin(); character != reverse.crend(); character++){
		cout << *character;
	}
	cout << endl;
}