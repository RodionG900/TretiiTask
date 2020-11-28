
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int m, n;
    cout << "¬ведите m, n:\n";
    cin >> m;
    cin >> n;
    vector<int> A(m * n);
    cout << "¬ведите строку:\n";
    for (auto t = A.begin(); t != A.end(); t++) cin >> *t;
    cout << "\n";



    vector<vector<int>> B(m);
    for (int i = 0; i < B.capacity(); i++)B[i].resize(n);
    vector<int> C(m * n);



    for (auto t = A.begin(); t != A.end(); t++) {
        //cout << *t<< endl;
        int k = distance(A.begin(), t);
        //cout << k;
        int str = k / n;
        int dec = k % n;
        auto b = B.begin() + str;
        auto d = (*b).begin() + dec;
        *d = *t;
    }



    for (auto b = B.begin(); b != B.end(); b++) {
        for (auto c = (*b).begin(); c != (*b).end(); c++) {
            auto r = C.begin() + n * distance(B.begin(), b) + distance((*b).begin(), c);
            *r = *c;
        }
    }


    for (auto b : B) {
        for (auto t : b) {
            cout << t << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    for (auto c : C) {
        cout << c << " ";
    }
    cout << endl;
}