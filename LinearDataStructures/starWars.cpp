#include <fstream>
#include <vector>
#include <climits>
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

void starWars() {
    ifstream in;
    ofstream out;
    int n;
    int min = INT_MAX;
    vector<int> counter(10000, 0);

    in.open("input");
    in >> n;
    vector<int> sorted(n);

    for (int i = 0; i < n; i++) {
        in >> sorted[i];
        if (sorted[i] < min) min = sorted[i];
    }

    for (int i = 0; i < n; i++) {
        counter[sorted[i] - min]++;
    }

    out.open("output");
    int i = 0;
    for (int j = 0; j < counter.size(); ++j) {
        while (counter[j] > 0) {
            out << j + min << " ";
            counter[j]--;
            i++;
        }
        i++;
    }
    in.close();
    out.close();
}


//int main() {
//    starWars();
//    return 0;
//}