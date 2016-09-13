/*Cracking the Coding Interview
Chapter 1
Interview Question 1.5
Write a method to compress strings. Return the original string.
Example:
	Input: "aabbccccaaa"
	Compression: "a2b2c4a3"
    Output: "aabbcccc"
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compressionStr(string);

int main(){
    string a = "BEAuuuutiful";
    compressionStr(a);
    
    return 0;
}

string compressionStr(string a){
    stringstream sBuff;    
    char last = a.at(0);
    int count = 1;

    for(int i = 1; i < a.length(); i++){
        if(a.at(i) == last){
            count++;
        }
        else{
            sBuff << last;
            sBuff << count;
            last = a.at(i);
            count = 1;
        }
    }

    sBuff << last;
    sBuff << count;
    string s = sBuff.str();
    cout << s << endl;
    
    return s;
}
