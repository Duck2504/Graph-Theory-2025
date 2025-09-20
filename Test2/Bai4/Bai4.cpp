#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define IF "DanhSachCanh.inp"
#define OF "DanhSachCanh.out"
ifstream fi;
ofstream fo;
int n, m;
vector<vector<int>> Matran;

void Nhap(){
    fi.open(IF);
    fi >> n >> m;
    Matran.resize(n+1,vector<int>(n+1,0));
    for (int i = 1;i<=m;i++){
        int u ,v;
        fi>>u>>v;
        Matran[u][v] = Matran[v][u] = 1;
    }
    fi.close();
}

void Xuat(){
    fo.open(OF);
    fo << n << endl;
    for (int i=1;i<=n;i++){
        int dem = 0;
        for (int j=1;j<=n;j++){
            if (Matran[i][j] == 1) dem++;
        }
        fo << dem<<"\n";
    }
    fo.close();
}
int main(){
    Nhap();
    Xuat();
    return 0;
}