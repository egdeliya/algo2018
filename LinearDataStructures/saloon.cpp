#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int minPerHour = 60;
const int workingTime = 20;

struct Client {
    Client(int hour, int min, int patience):
        _comingTime(minPerHour * hour + min),
        _patience(patience) {}

    bool operator<(const Client& r) {
        if (abs(r._comingTime - _comingTime) > workingTime) return _comingTime < r._comingTime;
        else {
            if (r._patience > _patience) return true;
            else {
                if (r._patience < _patience) return false;
                else return _comingTime < r._comingTime;
            }
        }
    }

    friend ifstream& operator>>(ifstream& in, Client& cl) {
        int hour;
        int min;

        in >> hour;
        in >> min;
        in >> cl._patience;

        cl._comingTime = hour * minPerHour + min;
        return in;
    }

    int _comingTime;
    int _patience;
};

void selectSort(vector<Client>& clients) {
    int cur = 0;
    int minInd;
    int ind;

    while (cur < clients.size()) {
        ind = cur + 1;
        minInd = cur + 1;
        while (ind < clients.size()) {
            if (clients[ind] < clients[cur]) minInd = ind;
            ind++;
        }
        swap(clients[cur], clients[minInd]);
        cur++;
    }
}

void saloon() {
    ifstream in;
    ofstream out;

    in.open("saloon.in");
    out.open("saloon.out");

    int clientsNum;
    in >> clientsNum;

    vector<Client> clients(clientsNum);
    for (int i = 0; i < clientsNum; ++i) {
        in >> clients[i];
    }

    selectSort(clients);


    in.close();
    out.close();

}

//int main() {
//    saloon();
//    return 0;
//}