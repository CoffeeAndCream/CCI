#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string p[] = { "morning", "breaking", "burning", "fat", "uglier", "fattier", "brilliant", "fleece" };
	for (int q = 0; q < 8; q++){
		string s = p[q];
		unsigned int j = 0;
		for (auto i : s){
			if (s.find(i) < j){
				cout << "This string, " << s << ", doesn't have unique values" << endl;
				break;
			}
			j++;
		}
	}
		
	system("pause");
	return 0;
}