#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define FI "MaTranKe.inp"
#define FO "MaTranKe.out"
ifstream fi;
ofstream fo;

int n;
vector<vector<int>> maTran;

void Nhap(){
    fi.open(FI);
    fi>>n;
    maTran.assign(n,vector<int>(n));
    for (int i= 0;i<n;i++){
        for (int j = 0;j<n;j++){
            fi >> maTran[i][j];
        }
    }
    fi.close();
}

void Xuat(){
    fo.open(FO);
    fo << n <<"\n";
    for (int i= 0;i<n;i++){
        int bac = 0;
        for (int j = 0 ;j<n;j++){
            if (maTran[i][j]==1) bac++;
        }
        fo <<bac<<"\n";
    }
    fo.close();
}

int main(){
    Nhap();
    Xuat();
    return 0;
}