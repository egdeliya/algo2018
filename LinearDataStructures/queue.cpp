#include <iostream>
#include <vector>

using namespace std;

class Queue {
public:

    Queue() {
        _storageSize = 100;
        _storage = (int*) malloc(100 * sizeof(int));
    }

    bool enqueue(int elem) {
        if (_curSize == _storageSize) {
//            realloc()
        }
    }

    bool insert(int elem) {
        if (_curSize == _storageSize) {
            realloc();
        }
    }

    bool dequeue(int elem) {
        if (_curSize == 0) return false;


    }

private:
    void realloc() {
//        _storageSize *
//        int* temp = (int*) malloc()
    }

    int _grawnFactor = 2;
    int _cutFactor = 3;
    int _head = 0;
    int _tail = 0;
    int _curSize = 0;
    int _storageSize;
    int* _storage;
};

//int main() {
//    Queue q;
//    return 0;
//}