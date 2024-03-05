#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e6;

void heapify(float a[], int n, int root) {
    int largest = root;

    int left_child = 2*root + 1;
    int right_child = 2*root + 2;
    
    if (left_child < n && a[left_child] > a[largest])
        largest = left_child;
    
    if (right_child < n && a[right_child] > a[largest])
        largest = right_child;
    
    if (largest != root) {
        swap(a[largest], a[root]);
        heapify(a, n, largest);
    }
}   

void build_maxheap(float a[], int n) {
    for (int i = n/2-1; i>=0; i--)
        heapify(a, n, i);
}

void heapsort(float a[], int n) {
    build_maxheap(a, n);

    for (int i = n-1; i>=1; i--) {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

int main() {
    FILE *fp, *fo;
    fp = freopen("test.inp", "r", stdin);
    fo = freopen("heap.out", "w", stdout);
    int t = 10;
    float *a = new float[MAXX];
    while (t--) {
        for (int i=0; i<MAXX; i++)
            cin >> a[i];
        clock_t start, end;
        double time_used;
        start = clock();
        heapsort(a, MAXX);
        end = clock();
        time_used = double(end-start)/CLOCKS_PER_SEC;   
        cout << time_used*1000 << '\n';
        // bool check = true;
        // for (int i=1; i<MAXX; i++)
        //     if (a[i] < a[i-1]) {
        //         check = false;
        //         break;
        //     }
        // cout << check << endl;
    }
    delete[] a;
    fclose(fp);
    fclose(fo);
}