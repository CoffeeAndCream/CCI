//Cracking the Coding Interview
//Chapter 1
//Interview Question 1.3
//Given two strings, write a method to decide if one is a permutation of the other.

#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <algorithm>

using namespace std;

bool permutation(string, string);

int main(){
	
	permutation("magic", "gImaC");

	system("pause");
	return 0;
}

bool permutation(string a, string b){

	//checks lengths because if the # of char != then it cannot be a permutation
	if (a.length() != b.length()){
		return false;
	}

	int size_a = 1;
	int size_b = 1;
	for (auto i : a){
		i = putchar(tolower(i));
		size_a = size_a * (int)i;
	}
	for (auto j : b){
		j = putchar(tolower(j));
		size_b = size_b * (int)j;
	}
	cout << "\n\n\n";
	if (size_a != size_b){
		cout << "Not a permutation: " << size_a << " AND " << size_b << endl;
	}
	else{
		cout << "It is a permutation: " << size_a << " AND " << size_b << endl;
	}
}
