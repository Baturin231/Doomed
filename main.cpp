#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct Data{
    string input, output;
};

string replacement(Data d, string word){

}

int main() {

    Data d = {{"shortint", "int"}, {"byte", "int"}, {"smallint", "int"}, {"word", "int"}, {"integer", "int"},
              {"int64",    "int"}, {"longword", "int"}, {"uint64", "int"}, {"BigInteger", "int"}, {"real", "float"},
              {"char",     "bytes"}, {"string", "str"}, {"boolean", "bool"}, {"var", "NoneType"}, {":=", "="},
              {"div",      "//"}, {"mod", "%"}};

    cout << "Enter full PATH with name file.pas:\n";
    string str = "/home/batain/local_projects/Doomed/files/ABC.Net/1.pas"; //cin >> str;
    ifstream o_Pas(str);
    if (o_Pas.is_open()) {
        cout << "\nFile found :D\n\nEnter full PATH with name file.py:\n";
        str = "/home/batain/local_projects/Doomed/files/Python/HELLP.py";//cin >> str;
        ofstream w_Py(str);
        if(w_Py.is_open()) {
            cout << "\nPlease wait some time ^^\n";
            w_Py << "from random import*\nfrom math import*\n";
            string word; char separator;
            while (!o_Pas.eof()) {
                o_Pas >> word;
                if(word != "const") {//если не константа
                    if (word.back() == ';')
                        word.pop_back();
                    word = replacement(d, word);
                    w_Py << word << " ";
                    o_Pas.get(separator);
                    w_Py << separator;
                    continue;
                }
                else {
                    o_Pas >> word;
                    transform(word.begin(), word.end(),word.begin(), ::toupper);
                    w_Py << word << " ";
                    o_Pas.get(separator);
                    w_Py << separator;
                    continue;
                }
                //СИМВОЛ БЛЯТЬ ПРОПИСАТЬ
            }
            w_Py.close();
            cout << "\nThe process is completed =D\n";
        }
        else{
            cout << "\nUnsuccessful creation of the file.py :(\n";
            return -2;
        }
        o_Pas.close();
    }
    else {
        cout << "\nFile not found :(\n";
        return -1;
    }
    return 0;
}