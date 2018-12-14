/*
 * @Description: 201703-3
 * @Author: lichunyu
 * @Date: 2018-12-14 18:26:29
 * @LastEditTime: 2018-12-14 20:14:55
 * @LastEditors: Please set LastEditors
 */
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

string int_to_string(int &a) {
    stringstream ss;
    ss << a;
    return ss.str();
}

int main() {
    string s;
    string block_text = "";
    bool flag = false;
    getline(cin, s);
    while (true) {
        if (s.size() > 0) {
            block_text += s + "\n"; 
        } else
        if (s.size() == 0 && block_text.size() > 0){
            // end of block process
            size_t pos = block_text.find("_");
            while (pos != string::npos) {
                block_text.replace(pos, 1, "<em>");
                size_t nxt_pos = block_text.find("_", pos);
                block_text.replace(nxt_pos, 1, "</em>");
                pos = block_text.find("_", nxt_pos);
            }
            pos = block_text.find("[");
            while (pos != string::npos) {
                size_t nxt_pos = block_text.find("]", pos);
                string txt = block_text.substr(pos+1, nxt_pos-pos-1);
                size_t link_pos = block_text.find("(");
                size_t link_npos = block_text.find(")");
                string link = block_text.substr(link_pos+1, link_npos-link_pos-1);
                block_text.replace(block_text.begin()+pos, block_text.begin()+link_npos+1, "<a href=\""+link+"\">"+txt+"</a>");
                pos = block_text.find("[");
            }

            if (block_text[0] == '#') {
                int i = 0;
                while (block_text[i] == '#') i++;
                block_text = block_text.substr(i+1);
                block_text.insert(0, "<h" + int_to_string(i) + ">");
                block_text.insert(block_text.size()-1, "</h" + int_to_string(i) + ">");
            } else if (block_text[0] == '*') {
                block_text.insert(0, "<ul>\n");
                block_text.insert(block_text.size(), "</ul>\n");
                pos = block_text.find("*");
                while(pos != string::npos) {
                    block_text.replace(pos, 2, "<li>");
                    size_t end_item_pos = block_text.find("\n", pos);
                    block_text.insert(end_item_pos, "</li>");
                    pos = block_text.find("*");
                }
            } else {
                block_text.insert(0, "<p>");
                block_text.insert(block_text.size()-1, "</p>");
            }
            cout << block_text;
            block_text = "";
        }
        s = "";
        if (flag) break;
        if (!getline(cin, s)) {
            flag = true;
            s = "";
        }
    }
    return 0;
}