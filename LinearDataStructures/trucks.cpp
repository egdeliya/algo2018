#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

//int main() {
//    ifstream in;
//    ofstream out;
//    int n;
//    int k;
//    int counter = 0;
//    int buf;
//    stack<int> st;
//
//    in.open("trucks.in");
//    in >> n;
//    in >> k;
//    st.push(n);
//
//    while (!st.empty()) {
//        buf = st.top();
//        st.pop();
//        if (buf <= k) counter++;
//        else {
//            st.push(buf / 2);
//            st.push(buf - buf / 2);
//        }
//    }
//
//    out.open("trucks.out");
//    out << counter;
//    in.close();
//    out.close();
//
//    return 0;
//}
