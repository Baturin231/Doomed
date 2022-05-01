#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Enter full PATH with name file.pas:\n";
    string str; cin >> str;
    ifstream o_Pas(str);
    if (o_Pas.is_open()) {
        string str2;
        cout << "\nFile found :D\n\nEnter full PATH with name file.py:\n";
        cin >> str;
        ofstream w_Py(str);
        if(w_Py.is_open()) {
            cout << "\nPlease wait some time ^^\n";
            char symbol;
            while (!o_Pas.eof()) {
                o_Pas.get(symbol);
                w_Py << symbol;
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