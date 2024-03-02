#include <bits/stdc++.h>
using namespace std;

const int MAXX = int(1e6);

int main() {
    FILE *fp, *fo;
    fp = freopen("test.inp", "r", stdin);
    fo = freopen("sortc.out", "w", stdout);
    int t = 10;
    while (t--) {
        vector<double> a(MAXX);
        for (int i=0; i<MAXX; i++)
            cin >> a[i];
        clock_t start, end;
        double time_used;
        start = clock();
        sort(a.begin(), a.end());
        end = clock();
        time_used = double(end-start)/CLOCKS_PER_SEC;   
        cout << time_used*1000 << '\n';
        /*bool check = true;
        for (int i=1; i<MAXX; i++)
            if (a[i] < a[i-1]) {
                check = false;
                break;
            }
        cout << check << endl;*/
    }
    fclose(fp);
    fclose(fo);
}