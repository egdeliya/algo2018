#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Queue {
public:

    Queue() {
        _storageSize = _defaultSize;
        _storage.resize(_storageSize);
    }

    void push_back(int elem) {
        if (_curSize >= _storageSize - 1) {
            realloc(true);
        }
        _storage[_tail] = elem;
        _tail = (_tail + 1) % _storageSize;
        _curSize++;
    }

    void push_front(int elem) {
        if (_curSize >= _storageSize - 1) {
            realloc(true);
        }
        if (_head - 1 < 0) _head = _storageSize - 1;
        else _head = _head - 1;
        _storage[_head] = elem;
        _curSize++;
    }

    int pop_front() {
        int res = _storage[_head];
        _head = (_head + 1) % _storageSize;
        _curSize--;

        if (_storageSize > _defaultSize
            && _curSize < static_cast<int>(_storageSize / _cutFactor)) {
            realloc(false);
        }

        return res;
    }

    bool isEmpty() {
        return _curSize == 0;
    }

    int size() {
        return _curSize;
    }

private:
    void realloc(bool increase) {
        int newSize;
        if (increase)
            newSize = _storageSize * _growthFactor;
        else
            newSize = static_cast<int>(_storageSize / _cutFactor);

        vector<int> temp(newSize);

        copy(_head, _curSize, temp, 0);
        _tail = _curSize;

        _head = 0;
        _storageSize = newSize;

        swap(_storage, temp);
        temp.clear();
    }

    void copy(int stInd, int elemNum, vector<int>& dest, int destInd) {
        int curElemNum = 0;
        while (curElemNum < elemNum) {
            dest[destInd] =  _storage[stInd];

            destInd = destInd + 1;
            stInd = (stInd + 1) % _storageSize;
            curElemNum++;
        }
    }

    int _growthFactor = 2;
    float _cutFactor = 3;
    int _head = 0;
    int _tail = 0;
    int _curSize = 0;
    int _storageSize;
    int _defaultSize = 2;
    vector<int> _storage;
};

class GoblinsQueue {
public:
    void enqueue(int elem) {
        _afterMiddle.push_back(elem);
        _curSize++;
    }

    void insert(int elem) {
        int middle;
        if (_curSize % 2 == 0) {
            middle = _curSize / 2;
        } else {
            middle = (_curSize + 1) / 2;
        }

        _curSize++;
        if (_afterMiddle.isEmpty()) {
            _afterMiddle.push_back(elem);
            return;
        }

        int befMidElem;
        while (_beforeMiddle.size() < middle) {
            befMidElem = _afterMiddle.pop_front();
            _beforeMiddle.push_back(befMidElem);
        }
        _afterMiddle.push_front(elem);
    }

    int dequeue() {
        _curSize--;
        if (_beforeMiddle.isEmpty()) {
            return _afterMiddle.pop_front();
        } else {
            return _beforeMiddle.pop_front();
        }
    }

private:
    int _curSize = 0;
    Queue _beforeMiddle;
    Queue _afterMiddle;
};


void queue() {
    ifstream in;
    ofstream out;
    int n;
    char op;
    int num;

    in.open("queue.in");
    out.open("queue.out");
    in >> n;

    GoblinsQueue q;

    while (n > 0) {
        in >> op;
        switch (op) {
            case '+':
                in >> num;
                q.enqueue(num);
                break;
            case '*':
                in >> num;
                q.insert(num);
                break;
            case '-':
                num = q.dequeue();
                out << num << endl;
                break;
        }
        n--;
    }

    in.close();
    out.close();
}

// int main() {
//    queue();
//    return 0;
//}