#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

char getPair(char second) {
    char res;
    switch (second) {
        case ')':
            res = '(';
            break;
        case '}':
            res = '{';
            break;
        case ']':
            res = '[';
            break;
    }
    return res;
}

void brackets() {
    ifstream in;
    ofstream out;
    stack<char> st;
    char last;
    char cur;

    in.open("brackets.in");
    out.open("brackets.out");

    while (in >> cur) {
        if (cur == '(' || cur == '[' || cur == '{') {
            last = cur;
            st.push(cur);
        } else {
            if (last == getPair(cur)) {
                st.pop();
                if (!st.empty())
                    last = st.top();
                else
                    last = '|';
            } else {
                out << "NO";
                in.close();
                out.close();
                return;
            }
        }
    }

    if (st.empty())
        out << "YES";
    else
        out << "NO";

    in.close();
    out.close();
}

//int main() {
//    brackets();
//    return 0;
//}
