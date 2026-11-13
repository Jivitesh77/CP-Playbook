#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    int N, Q;
    fin >> N >> Q;

    vector<int> haybales(N);
    for (int i = 0; i < N; ++i) {
        fin >> haybales[i];
    }

    sort(haybales.begin(), haybales.end());

    for (int i = 0; i < Q; ++i) {
        int A, B;
        fin >> A >> B;

        auto it_up = upper_bound(haybales.begin(), haybales.end(), B);
        auto it_low = lower_bound(haybales.begin(), haybales.end(), A);

        fout << (it_up - it_low) << "\n";
    }

    return 0;
}