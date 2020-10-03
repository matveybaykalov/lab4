#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void Merge (int f1, int f2, std::vector<int>& vec){
    if (f2-f1+1>2) {
        int k = (f2-f1+1)/2;
        Merge(f1, f1+k-1, vec);
        Merge (f1+k, f2, vec);
    } else {
        if (f2 - f1 + 1 == 2)
            if (vec[f1] > vec[f2]) {
                int t = vec[f1];
                vec[f1] = vec[f2];
                vec[f2] = t;
            }
    }
    if (f2-f1+1 > 2) {
        int k = (f2 - f1 + 1) / 2;
        int flag1 = f1, flag2 = f1 + k;//нужно создать ещё один вектор длины f2-f1+1 и записывать туда упорядоченные элементы, после обменть данные с исходным вектором
        std::vector<int> mas(f2 - f1 + 1);
        int iterator = 0;
        while (flag1 <= f1 + k - 1 || flag2 <= f2) {
            if (vec[flag1] >= vec[flag2]) {
                mas[iterator] = vec[flag2];
                iterator++;
                if (flag2 < f2)
                    flag2++; else {
                        for(int i = flag1; i <= f1+k-1; i++){
                            mas[iterator] = vec[i];
                            iterator++;
                        }
                        break;
                    }
            } else {
                mas[iterator] = vec[flag1];
                iterator++;
                if (flag1 < f1 + k - 1)
                    flag1++; else {
                        for(int i = flag2; i <= f2; i++){
                            mas[iterator] = vec[i];
                            iterator++;
                        }
                        break;
                    }
            }
        }
        for (int i = f1; i <= f2; i++) {
            vec[i] = mas[i-f1];
        }
    }
    }

//cocktail sort
int main() {

    using std::cin;
    using std::cout;
    using std::endl;
    using std::vector;

    int l = 30;
    std::srand(std::time(nullptr));
    vector <int> arr(l);
    for (int i = 0; i<l; i++) {
        arr[i] = std::rand() % 201 - 100;
        cout << arr[i] << ' ';
    }
    cout << endl;

    bool flag = true;
    int iterator;
    int GrH = l;
    int GrL = 0;
    while (flag){
        flag = false;
        iterator = GrL;
        while (iterator < GrH-1){
            if (arr[iterator]>arr[iterator+1]) {
                int t = arr[iterator+1];
                arr[iterator+1] = arr[iterator];
                arr[iterator] = t;
                flag = true;
            }
            iterator++;
        }
        GrH--;
        while (iterator >= GrL+1){
            if (arr[iterator]<arr[iterator-1]) {
                int t = arr[iterator-1];
                arr[iterator-1] = arr[iterator];
                arr[iterator] = t;
                flag = true;
            }
            iterator--;
        }
        GrL++;
    }

    for (int i = 0; i<l; i++) {
        cout << arr[i] << ' ';
    }
    cout <<endl;

    //Merge sort
    std::srand(std::time(nullptr));
    vector <int> a1(l);
    for (int i = 0; i<l; i++) {
        a1[i] = std::rand() % 201 - 100;
        cout << a1[i] << ' ';
    }
    cout << endl;

    Merge(0, l-1, a1);
    for(int i: a1)
        cout << i << ' ';
    cout << endl;

    //Shell sort
    std::srand(std::time(nullptr));
    vector <int> a2(l);
    for (int j = 0; j<l; j++) {
        a2[j] = std::rand() % 201 - 100;
        cout << a2[j] << ' ';
    }
    cout << endl;
    int d=l/2;
    while (d>0){
        for (int i=0; i < d; i++)
            for (int j=i; j<l; j+=d)
                for (int k=j; k>i && a2[k-d]>a2[k]; k-=d) {
                    int t = a2[k - d];
                    a2[k - d] = a2[k];
                    a2[k] = t;
                }
        d/=2;
    }
    for(int i: a2)
        cout << i << ' ';
    cout << endl;

    return 0;
}
