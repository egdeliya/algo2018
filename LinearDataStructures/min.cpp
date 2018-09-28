#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

class minQueue {
public:
    void enqueue(int elem) {
        _q.push(elem);
        while (!_min.empty() && _min.back() > elem) {
            _min.pop_back();
        }
        _min.push_back(elem);
    }

    void dequeue() {
        int elem = _q.front();
        _q.pop();

        if (elem == _min.front()) _min.pop_front();
    }

    int getMin() {
        return _min.front();
    }
private:
    queue<int> _q;
    deque<int> _min;
};

void min() {
    ifstream in;
    ofstream out;
    int n;
    int k;
    int num;

    in.open("min.in");
    out.open("min.out");

    in >> n;
    in >> k;

    minQueue qMin;
    for (int i = 0; i < k; ++i) {
        in >> num;
        qMin.enqueue(num);
    }

    out << qMin.getMin() << endl;
    qMin.dequeue();

    for (int j = k; j < n; ++j) {
        in >> num;
        qMin.enqueue(num);

        out << qMin.getMin() << endl;
        qMin.dequeue();
    }
    in.close();
    out.close();
}

//int main() {
//    min();
//    return 0;
//}