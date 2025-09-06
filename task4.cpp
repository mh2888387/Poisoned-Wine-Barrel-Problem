#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

// Return S base-B digits of x, least significant first.
// Unused higher digits are set to (B-1) meaning "no taste".
vector<int> baseDigits(long long x, int B, int S) {
    vector<int> d(S, B - 1);
    for (int j = 0; j < S; ++j) {
        d[j] = int(x % B);
        x /= B;
    }
    return d; // d[0] -> Slave #1, ..., d[S-1] -> Slave #S
}

// Decode o[0..S-1] (LSB-first) as base-B number.
long long decodeBase(const vector<int>& o, int B) {
    long long x = 0, w = 1;
    for (int j = 0; j < (int)o.size(); ++j) {
        x += 1LL * o[j] * w;
        w *= B;
    }
    return x;
}

int main() {


    long long N; // number of barrels
    int S, D;    // slaves, extra observable days
{
    const int L = 20, R = 36;  // column widths

    auto sep = [&](){
        cout << "+" << string(L+2,'-') << "+" << string(R+2,'-') << "+\n";
    };
    auto row = [&](const string& a, const string& b){
        cout << "| " << left << setw(L) << a
             << " | " << left << setw(R) << b << " |\n";
    };

    sep();
    row("SETUP PARAMETERS", "(enter as: N S D)");
    sep();
    row("N (barrels >= 1)",  "total wine barrels");
    row("S (slaves  >= 1)",  "number of testers");
    row("D (days    >= 0)",  "extra days beyond 30");
    sep();
    row("Tips", "binary: D=0   |   5-week: D=4");
    sep();

    cout << ">> Input N S D: " << flush;
}

    cin >> N >> S >> D;


    int B = D + 2;
    if(pow(B,S)<N)
        return -1;
    for (long long i = 0; i < N; ++i) {
        auto d = baseDigits(i, B, S);
        for (int j = 0; j < S; ++j) {
            if (d[j] < B - 1) {
                // "Instruct Slave j+1 to drink from barrel i on day d[j]"
                cout << "Barrel " << i << " -> Slave #" << (j + 1)
                     << " on day " << d[j] << "\n";
            }
        }
    }

const int L = 30;  // left column width
const int R = 44;  // right column width

auto sep = [&]() {
    cout << "+" << string(L + 2, '-') << "+" << string(R + 2, '-') << "+\n";
};
auto row = [&](const string& a, const string& b) {
    cout << "| " << left << setw(L) << a
         << " | " << left << setw(R) << b << " |\n";
};

sep();
row("OUTCOME NOTATION", "(enter o[j] for j = 1..S)");
sep();
row("o[j] = t  (0 <= t <= D)", "Slave #(j+1) DIED on day 30 + t");
row("o[j] = " + to_string(B - 1), "Slave #(j+1) SURVIVED (no taste)");
sep();
row("Parameters", "D = " + to_string(D) + ", B = D+2 = " + to_string(B));
row("Input", "Enter " + to_string(S) + " integers: o[1]..o[" + to_string(S) + "]");
sep();
    vector<int> o(S);
    for (int j = 0; j < S; ++j) {
        cin >> o[j];
    }

    long long X = decodeBase(o, B);
    cout << "Poisoned barrel label = " << X << "\n";

    return 0;
}
