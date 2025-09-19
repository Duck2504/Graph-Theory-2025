#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#define FI "DanhSachKe.inp"
#define FO "DanhSachKe.out"
ifstream fi;
ofstream fo;
int n;
vector<vector<int>> Matran;

void Nhap(){
    fi.open(FI);
    fi >> n;
    fi.ignore();
    Matran.assign(n+1,{});
    string line;
    for (int i= 1;i<=n;i++){
        getline(fi,line);
        stringstream ss(line);
        int x;
        while (ss>>x){
            Matran[i].push_back(x);
        }
    }
    fi.close();
}

void Xuat(){
    fo.open(FO);
    fo<<n<<endl;
    for (int i= 1;i<=n;i++){
        fo << Matran[i].size() << endl;
    }
    fo.close();
}

int main(){
    Nhap();
    Xuat();
    return 0;
}