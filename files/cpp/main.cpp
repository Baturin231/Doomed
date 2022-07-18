#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

enum OS {Windows, Linux, etc};
 
OS getOs ()
{
    return
#ifdef __linux
    Linux;
#elif defined _WIN32
    Windows;
#endif
}

struct Data{
    string input, s_input, output;
};

string replacement(Data* d, const int size, string word){
    for(int i = 0; i < size; i++)
        if(word == d[i].input || word == d[i].s_input)
            return d[i].output;
    return word;
}

int main() {
    if (getOs() == Linux) {
        system("i686-w64-mingw32-g++ -static-libgcc -static-libstdc++ main.cpp");
        char oldfilename[] = "a.exe", newfilename[] = "start.exe";
        rename(oldfilename, newfilename);
    }

    const int size = 20;
    Data d[size] = {{"write",    "Write",    "print"},
                    {"writeln",  "Writeln",  "print"},
                    {"Byte",     "byte",     "int"},
                    {"Shortint", "shortint", "int"},
                    {"Word",     "word",     "int"},
                    {"Smallint", "smallint", "int"},
                    {"Integer",  "integer",  "int"},
                    {"Longint",  "logint",   "int"},
                    {"int64",    "Int64",    "int"},
                    {"Real",     "real",     "float"},
                    {"Double",   "double",   "float"},
                    {"Single",   "single",   "float"},
                    {"div",      "Div",      "//"},
                    {"mod",      "Mod",      "%"},
                    {":=",       ":=",       "="},
                    {"Random",   "random",   "randint"},
                    {"then",     "do",       ":"},
                    {"else",     "else",     "else:"},
                    {"=",        "=",        "=="},
                    {"<>",       "<>",       "!="}};

    cout << "Enter full PATH with name file.pas:\n";
    string str = "/home/batain/local_projects/Doomed/files/ABC/111.pas"; //cin >> str;

    ifstream o_Pas(str);
    if (o_Pas.is_open()) {
        cout << "\nFile found :D\n\nEnter full PATH with name file.py:\n";
        str = "/home/batain/local_projects/Doomed/files/Python/HELLP.py";//cin >> str;

        ofstream w_Py(str);
        if (w_Py.is_open()) {
            cout << "\nPlease wait some time ^^\n";
            w_Py << "from random import*\nfrom math import*\n";

            string word;
            char separator;
            int kol = 0, place;
            while (!o_Pas.eof()) {
                //if (word == "var" || word == "Var") {
                /*place_o = o_Pas.tellg();
                while (word.back() != ':')
                    o_Pas >> word;

                o_Pas >> word;
                word.pop_back();
                word = replacement(d, size, word);
                string buffer = word;

                o_Pas.seekg(place_o, ios::beg);
                o_Pas >> word;
                while(word.back() != ':'){
                    cout << word << endl;
                    word.pop_back();
                    w_Py << buffer << " " << word << "=" << buffer << "(" << word << ")\n";
                    o_Pas >> word;
                }
                word.pop_back();
                w_Py << word << "=" << buffer << "(" << word << ")\n";
                o_Pas >> word;*/
                //while(word.back() != ';')
                //o_Pas >> word;
                //continue;
                //}
                place = o_Pas.tellg();
                o_Pas.get(separator);
                if (separator == '\t') {
                    while (separator == '\t') {
                        kol++;
                        o_Pas.get(separator);
                    }
                    kol--;
                }
                o_Pas.seekg(place);
                o_Pas >> word;
                cout << word << endl;
//READY
                if (word == "Program" || word == "program") {
                    o_Pas >> word;
                    o_Pas.get(separator);
                    kol = 0;
                    continue;
                }
//READY
                if (word == "var" || word == "Var") {
                    while (word.back() != ';')
                        o_Pas >> word;
                    kol = 0;
                    continue;
                }
//READY
                if (word == "Begin" || word == "End" || word == "end" || word == "begin") {
                    o_Pas.get(separator);
                    kol = 0;
                    continue;
                }
//READY
                if (word == "End." || word == "end.") {
                    o_Pas.get(separator);
                    break;
                } else {
                    if (separator == '\t') w_Py << '\t';

                    if (word.back() == ';') word.pop_back();
                    word = replacement(d, size, word);
                    for (int i = 0; i < kol; i++) w_Py << "\t";
                    w_Py << word;
                    o_Pas.get(separator);
                    w_Py << separator;
                    kol = 0;
                    continue;
                }
            }
            w_Py.close();
            o_Pas.close();
            cout << "\nThe process is completed =D\n";
        } else {
            cout << "\nUnsuccessful creation of the file.py :(\n";
            system("pause");
            return -2;
        }
    } else {
        cout << "\nFile not found :(\n";
        system("pause");
        return -1;
    }
    system("pause");
    return 0;
}
