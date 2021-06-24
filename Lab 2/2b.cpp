#include <iostream>
#include <vector>
using namespace std;

void merge(vector<string> &country,vector<string> &name, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int i = 0, j = 0, k = l;
    vector<string> left_name(n1);
    vector<string> right_name(n2);
    vector<string> right_country(n2);
    vector<string> left_country(n1);

    for(int i = 0; i < n1; i++) {
        left_country[i] = country[l + i];
        left_name[i] = name[l + i];
    }

    for(int j = 0; j < n2; j++) {
        right_country[j] = country[m + 1 + j];
        right_name[j] = name[m + 1 + j];
    }

    while(i < n1 && j < n2){
        if(left_country[i] <= right_country[j]){
            country[k] = left_country[i];
            name[k] = left_name[i];
            i++;
        } else{
            country[k] = right_country[j];
            name[k] = right_name[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        country[k] = left_country[i];
        name[k] = left_name[i];
        i++;
        k++;
    }
    while (j < n2) {
        country[k] = right_country[j];
        name[k] = right_name[j];
        k++;
        j++;
    }
}

void sort(vector<string> &country, vector<string> &name, int left, int right){
    if(left < right){
        int middle = left + (right - left)/2;
        sort(country , name, left, middle);
        sort(country , name, middle+1, right);
        merge(country , name, left, middle, right);
    }
}


int main(){
    freopen("race.in", "r", stdin);
    int n;
    cin >> n;
    vector<string> country(n), name(n);
    for(int i = 0; i < n; i++)
        cin >> country[i] >> name[i];
    sort(country, name, 0,  n-1);

    freopen("race.out", "w", stdout);
    int count = 0;
    for(int i = 0; i < n-1; i++) {
        if(count == 0)
            cout << "=== " << country[i] << " ===" << endl;
        cout << name[i] << endl;
        if(country[i] == country[i+1])
            count++;
        else count = 0;
    }
    if(country[n-1] == country[n-2])
        cout << name[n-1];
    else {
        cout << "=== " << country[n-1] << " ===" << endl;
        cout << name[n-1];
    }
    return 0;
}