#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string int_to_string(int a) {
    stringstream ss;
    ss << a;
    string ret = ss.str();
    return ret;
}

int block_type(string s) {
    if (s.size() == 0)
        return -1;
    if (s[0] == '#') return 1;
    if (s[0] == '*') return 2;
    return 0;
}


void text_process(string line) {
    int flag = 0;
    string out;
    for (int i=0; i<line.size(); ++i) {
        if (line[i] == '_'){
            if (flag){
                flag = 0;
                out = out + "</em>";
            }else{
                flag = 1;
                out = out + "<em>";
            }
        } else {
            out = out + line.substr(i, 1);
        }
    }
    cout << out;
}

void empty_line_process(string line) {
    cout << endl;
}

void ephasis_process(string line) {
    return;
}

void head_process(string line) {
    int sharps = 0;
    int text_s = 0;
    string out;
    for (int i=0; i<line.size(); ++i) {
        if (line[i] == '#')
            sharps++;
        else{
            text_s = i;
            break;
        }          
    }
    while (line[text_s] == ' ') {
        text_s++;
    }
    out = "<h" + int_to_string(sharps) + ">" + line.substr(text_s) + "</h" + int_to_string(sharps) + ">";
    cout << out << endl;
}

void list_process(string line) {
    int item_s = 1;
    string out;
    while (line[item_s] == ' ') {
        item_s++;
    }
    out = "<li>" + line.substr(item_s) + "</li>";
    cout << out << endl; 
}

int main() {
    vector<string> markdown;
    vector<string> html;
    string line;
    int item_flag = 0;
    int text_flag = 0;
    int empty_line_flag = 0;
    while (getline(cin, line)) {
        int block = block_type(line);
        if (item_flag == 1 && block != 2) {
            cout << "</ul>" << endl;
            item_flag = 0;
        }
        if (text_flag == 1 && block != 0) {
            cout << "</p>" << endl;
            text_flag = 0;
        }
        if (empty_line_flag == 1 && block != -1) {
            empty_line_flag = 0;
        }
        switch(block) {
            case 0:
                if (text_flag == 0) {
                    cout << "<p>";
                    text_flag = 1;
                } else {
                    cout << endl;
                }
                text_process(line);
                break;
            case 1:
                head_process(line);
                break;
            case 2:
                if (item_flag == 0) {
                    cout << "<ul>" << endl;
                    item_flag = 1;
                } 
                list_process(line);
                break;
            case -1:
                if (empty_line_flag == 0){
                    empty_line_process(line);
                    empty_line_flag = 1;
                }
            default:
                break;
        }
    }
    return 0;
}