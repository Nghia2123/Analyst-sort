#include <bits/stdc++.h>
using namespace std;

const int MAXX = int(1e6);

int partition(vector<double> &a, int low, int high) {
    double pivot = a[high];
    
    int i = low-1;
    for (int j = low; j<high; j++)
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[i+1], a[high]);
    return i+1;
}

int partition_r(vector<double> &a, int low, int high) {
    srand(time(NULL));
    int pivot = low + rand() % (high-low);
    swap(a[pivot], a[high]);
    return partition(a, low, high);
}

void quicksort(vector<double> &a, int low, int high) {
    if (low < high) {
        int pivot = partition_r(a, low, high);
        quicksort(a, low, pivot-1);
        quicksort(a, pivot+1, high);
    }
}

int main() {
    FILE *fp, *fo;
    fp = freopen("test.inp", "r", stdin);
    fo = freopen("quick.out", "w", stdout);
    int t = 10;
    while (t--) {
        vector<double> a(MAXX);
        for (int i=0; i<MAXX; i++)
            cin >> a[i];
        clock_t start, end;
        double time_used;
        start = clock();
        quicksort(a, 0, MAXX-1);
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