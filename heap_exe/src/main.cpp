#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Heap {
public:
    void siftUp(int i);
    void siftDown(int i);
    void insert(int x);
    int getMin();
    void extractMin();
    int size();

private:
    vector <int> a;
    int n = 0;
};

void Heap::siftUp(int i) {
    while (a[i] < a[i/2]) {
        std::swap(a[i], a[i/2]);
        i /= 2;
    }
}

void Heap::siftDown(int i) {
    while (2*i < n) {
        int j = -1;
        if (a[2*i] < a[i]) {
            j = 2*i;
        }
        if (2*i+1 < n && a[2*i+1] < a[i] && (j == -1 || a[2*i] > a[2*i+1])) {
            j = 2*i+1;
        }
        if (j == -1) break;
        else {
            std::swap(a[i], a[j]);
            i = j;
        }
    }
}

int Heap::size() {
    return a.size();
}

int Heap::getMin() {
    return a[0];
}

void Heap::insert(int x) {
    a.push_back(x);
    n++;
    siftUp(n-1);
}

void Heap::extractMin() {
    a[0] = a[n];
    a.erase(a.begin()+n);
    n--;
    siftDown(0);
}

int main() {

    Heap pr;
    map <int, int> indx;

    int n, k;
    cin >> n >> k;

    vector <int> a(n), ans(n, 0);
    for (int i = 0; i<n; ++i) cin >> a[i];

    long long i = 0, ans0 = 0, j = 0;
    while (j < n) {

        while (j-i < k && j < n) {
            if (a[j] < a[i]) {
                indx[a[j]] = j;
                pr.insert(a[j]);
                break;
            }

            if (i != j) {
                indx[a[j]] = j;
                pr.insert(a[j]);
            }
            
            ans0 += a[i];
            ans[i]++;

            j++;
        }

        if (pr.size() != 0) {
            i = indx[pr.getMin()];
            pr.extractMin();
        } else {
            i = j;
        }
    }
    cout << ans0 << '\n';
    for (int i = 0; i<ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
}