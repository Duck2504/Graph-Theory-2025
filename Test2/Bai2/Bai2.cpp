#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define FI "BacVaoBacRa.inp"
#define FO "BacVaoBacRa.out"

ifstream fi;
ofstream fo;
int n;
vector<vector<int>> Matran;

void Nhap(){
    fi.open(FI);
    fi >> n;
    Matran.assign(n,vector<int>(n));
    for (int i= 0;i<n;i++){
        for (int j = 0;j<n;j++){
            fi >> Matran[i][j];
        }
    }
    fi.close();
}

void Xuat(){
    fo.open(FO);
    fo << n <<"\n";
    for (int i= 0;i<n;i++){
        int bacvao = 0;
        int bacra=0;
        for (int j= 0;j<n;j++){
        if (Matran[i][j]) bacra++;
        if (Matran[j][i]) bacvao++;
        }
        fo << bacvao << " " << bacra<< "\n";
    }
}

int main(){
    Nhap();
    Xuat();
    return 0;
}