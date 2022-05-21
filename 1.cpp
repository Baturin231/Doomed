#include <iostream>
#include <fstream>
using namespace std;

int main(){

	ifstream o_Pas("/home/batain/local_projects/Doomed/files/ABC.Net/1.pas");
	
	char separator;
	string word;
    
    o_Pas >> word;
    
    /*if(word.back() == ';'){
		word.pop_back();
		cout << word << " ";
	}*/
	cout << word << " ";

	if(word == ":=")
		cout << "Ghbrjk\n";

	return 0;
}
