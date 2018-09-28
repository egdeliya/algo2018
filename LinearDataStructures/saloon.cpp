#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int minPerHour = 60;
const int workingTime = 20;

class Client {
public:

    friend ifstream& operator>>(ifstream& in, Client& cl) {
        in >> cl._comingHour;
        in >> cl._comingMin;
        in >> cl._patience;

        return in;
    }

    int getComingTime() const {
        return _comingHour * minPerHour + _comingMin;
    }

    int getPatience() const {
        return _patience;
    }

    int getOutTime() {
        return _outTime;
    }

    void setOutTime(int time) {
        _outTime = time;
    }

private:
    int _comingMin;
    int _comingHour;
    int _patience;
    int _outTime;
};

void saloon() {
    ifstream in;
    ofstream out;

    in.open("saloon.in");
    out.open("saloon.out");

    int clientsNum;
    in >> clientsNum;

    queue<Client> clientsInQueue;
    Client cur;
    int lastQuitTime = 0;

    for (int i = 0; i < clientsNum; ++i) {
        in >> cur;

        while (!clientsInQueue.empty() &&
               clientsInQueue.front().getOutTime() - cur.getComingTime() <= 0) {
            clientsInQueue.pop();
        }

        if (cur.getPatience() < clientsInQueue.size()) {
            out
                    << cur.getComingTime() / minPerHour
                    << " "
                    << cur.getComingTime() % minPerHour
                    << endl;
        } else {
            if (lastQuitTime == 0 || lastQuitTime <= cur.getComingTime()) {
                lastQuitTime = cur.getComingTime() + workingTime;
            } else {
                lastQuitTime += workingTime;
            }

            cur.setOutTime(lastQuitTime);
            clientsInQueue.push(cur);
            out
                    << lastQuitTime / minPerHour
                    << " "
                    << lastQuitTime % minPerHour
                    << endl;
        }

    }

    in.close();
    out.close();
}

int main() {
    saloon();
    return 0;
}