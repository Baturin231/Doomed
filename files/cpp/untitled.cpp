#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
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
    const int size = 26;
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
                    {"then",     "do",       ":"},
                    {"else",     "Else",     "else:"},
                    {"=",        "=",        "=="},
                    {"<>",       "<>",       "!="},
                    {"If",       "IF",       "if"},
                    {"Ceil",       "CEIL",       "ceil"},
                    {"Floor",       "FLOOR",       "floor"},
                    {"Trunc",       "TRUNC",       "trunc"},
                    {"Exp",       "EXP",       "exp"},
                    {"Power",       "POWER",       "pow"},
                    {"Sqr",       "SQR",       "sqrt"}};
    cout << "Enter full PATH with name file.pas:\n";
    string str = "/home/n_malder/projects/Doomed/files/Паскалюка/main.pas", str2, word, buffer;//cin >> str;
    char separator;
    bool fl = false;
    ifstream o_Pas(str);
    if (o_Pas.is_open()) {
        cout << "\nFile found :D\n\nEnter full PATH with name file.py:\n";
        str = "/home/n_malder/projects/Doomed/files/Змея/main.py";//cin >> str;
        str2 = str; str2.pop_back();
        ofstream w_Py(str2);
        if (w_Py.is_open()) {
            cout << "\nPlease wait some time ^^\n";
            w_Py << "from random import*\nfrom math import*\n";
            int place = 0, kol = 0;
            while (!o_Pas.eof()) {
                place = o_Pas.tellg();
                o_Pas.get(separator);
                if(separator == '\t'){
                    while(separator == '\t'){
                            kol++;
                            o_Pas.get(separator);
                    }
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
                    while(word.back() != ';')
                        o_Pas >> word;
                    word.pop_back();
                    buffer = replacement(d, size, word);
                    kol = 0;
                    continue;
                }
//READY
                if(word=="Begin"||word=="End"||word=="end"||word=="begin" || word=="Begin;"||word=="End;"||word=="end;"||word=="begin;"){
                    o_Pas.get(separator);
                    kol = 0;
                    continue;
                }
                if(word=="End." || word=="end."){
                    o_Pas.get(separator);
                    kol = 0;
                    break;
                }
//READY
                if(word == "Read" || word == "read"){
                    o_Pas.get(separator);
                    o_Pas >> word;
                    while(!o_Pas.eof()){
                        for(int i = 0; i < kol-1; i++) w_Py << "\t";
                        if(word.back() == ';'){
                            if(word[0] == '(')word.erase(0, 1);
                            word.pop_back();word.pop_back();
                            w_Py << word << " = " << buffer << "(input())\n";
                            break;
                        }
                        else{
                            if(word[0] == '(')word.erase(0, 1);
                            word.pop_back();
                            w_Py << word << " = " << buffer << "(input())\n";
                        }
                        o_Pas >> word;
                    }
                    kol = 0;
                    continue;
                }
//READY
                if(word == "Readln" || word == "readln"){
                    o_Pas.get(separator);
                    o_Pas >> word;
                    while(!o_Pas.eof()){
                        for(int i = 0; i < kol-1; i++) w_Py << "\t";
                        if(word.back() == ';'){
                            if(word[0] == '(')word.erase(0, 1);
                            word.pop_back();word.pop_back();
                            w_Py << word << " = " << buffer << "(input())\n";
                            w_Py << "print()" << endl;
                            break;
                        }
                        else{
                            if(word[0] == '(')word.erase(0, 1);
                            word.pop_back();
                            w_Py << word << " = " << buffer << "(input())\n";
                        }
                        w_Py << "print()" << endl;
                        o_Pas >> word;
                    }
                    kol = 0;
                    continue;
                }

                if(fl){
                    w_Py << "print()";
                    fl = false;
                }
//READY
                if(word == "Random" || word == "random"){
                    w_Py << "random.randint";
                    kol = 0;
                    continue;
                }
//вроде работает
                else {
                    if(word == "Readln" || word == "readln") fl = true;
                    if (word.back() == ';') word.pop_back();
                    word = replacement(d, size, word);
                    for(int i = 0; i < kol-1; i++) w_Py << "\t";
                    w_Py << word;
                    o_Pas.get(separator);
                    w_Py << separator;
                    kol = 0;
                    continue;
                }
            }
            w_Py.close();
            o_Pas.close();
            //READY
            ifstream pythonB(str2); ofstream pythonA(str);
            if(pythonB.is_open() && pythonA.is_open()){
                while(!pythonB.eof()){
                    pythonB.get(separator);
                    if(separator == '\'' || separator == '‘' || separator == '’') 
                        pythonA << '"';
                    else pythonA << separator;
                }
                pythonA.close();
                pythonB.close();
                remove(str2.c_str());
                cout << "\nThe process is completed =D\n";
            }
        }
        else {
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