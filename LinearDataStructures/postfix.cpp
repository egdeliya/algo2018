#include <fstream>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return b - a;
}

int mult(int a, int b) {
    return a * b;
}

int processOperation(stack<int>& st, int (*op)(int, int)) {
    int first = st.top();
    st.pop();
    int sec = st.top();
    st.pop();

    return (*op)(first, sec);
}

void postfix() {
    ifstream in;
    ofstream out;
    int buf = 0;
    stack<int> numbers;

    in.open("postfix.in");
    char s;

    while (in >> s) {
        switch (s) {
            case '+':
                buf = processOperation(numbers, add);
                break;
            case '-':
                buf = processOperation(numbers, sub);
                break;
            case '*':
                buf = processOperation(numbers, mult);
                break;
            default: buf = s - '0';
        }
        numbers.push(buf);
    }

    out.open("postfix.out");

    if (numbers.size() == 1)
        out << numbers.top();
    else {
        out << "error";
    }
    out.close();

}

//int main() {
//    postfix();
//    return 0;
//}
