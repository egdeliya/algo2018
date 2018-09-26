#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Participant {
public:
    Participant() = default;
    Participant(int n, int s): _num(n), _score(s) {}

    bool operator>(const Participant& r) const {
        return _score > r._score;
    }

    friend ofstream& operator<<(ofstream& os, const Participant& p) {
        os << p._num;
        return os;
    }

private:
    int _num;
    int _score;
};

void insertSort(vector<Participant>& part) {
    int cur = 1;
    int j;
    while (cur < part.size()) {
        if (part[cur] > part[cur - 1]) {
            j = cur;
            while (part[j] > part[j - 1] && j > 0) {
                swap(part[j], part[j - 1]);
                j--;
            }
        }
        cur++;
    }
}

void competition() {
    int n;
    int score;
    ifstream in;
    ofstream out;

    in.open("olymp.in");
    in >> n;
    vector<Participant> parts(n);
    for (int i = 0; i < n; i++) {
        in >> score;
        parts[i] = Participant(i + 1, score);
    }
    in.close();

    insertSort(parts);

    out.open("olymp.out");
    for (int i = 0; i < n; ++i) {
        out << parts[i] << " ";
    }
    out.close();
}


//int main() {
//    competition();
//    return 0;
//}