/*Cracking the Coding Interview
Chapter 1
Interview Question 1.4
Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please use a character array so that you can perform this operation in place.)

Example:
	Input: "Mr John Smith	", 13
	Output: "Mr%20John%20Smith"

*/

#include <iostream>
#include <string>
#include <array>

using namespace std;

string replace_space(string, int);


int main(){

	replace_space("Good Morning ! All of my friends are at a brunch this Sunday!", 30);

	system("pause");
	return 0;
}

string replace_space(string str, int size){
	string n_str = "";

	for (int j = 0; j < str.length() && j < size; j++){
		if (str.at(j) == ' '){
			n_str.append("%20");
		}
		else{
			n_str.push_back(str.at(j));
		}
	}

	cout << n_str << endl;
	return n_str;
}