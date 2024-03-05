#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e6;
float *al = new float[MAXX/2+1];
float *ar = new float[MAXX/2+1];
void merge(float a[], int left, int mid, int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;
    
    for (int i=0; i<n1; i++)
        al[i] = a[left+i];

    for (int i=0; i<n2; i++)
        ar[i] = a[mid+1+i];
    
    int k = left;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (al[i] < ar[j]) 
            a[k++] = al[i++];
        else
            a[k++] = ar[j++];
    }

    while (i < n1)
        a[k++] = al[i++];
    
    while (j < n2)
        a[k++] = ar[j++];
}

void mergesort(float a[], int left, int right) {
    if (left < right) {
        int mid = left + (right-left)/2;
        mergesort(a, left, mid);
        mergesort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int main() {
   FILE *fp, *fo;
    fp = freopen("test.inp", "r", stdin);
    fo = freopen("merge.out", "w", stdout);
    int t = 10;
    float *a = new float[MAXX];
    while (t--) {
        for (int i=0; i<MAXX; i++)
            cin >> a[i];
        clock_t start, end;
        double time_used;
        start = clock();
        mergesort(a, 0, MAXX-1);
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
    delete[] a;
    delete[] ar;
    delete[] al;
    fclose(fp);
    fclose(fo);
}