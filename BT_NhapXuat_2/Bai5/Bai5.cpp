#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
#define FI "Input.inp"
#define FO "Output.out"
ifstream fi;
ofstream fo;
int choice,n,m;
vector<vector<int>> Matran;
vector<vector<int>> DSK;
vector<pair<int,int>> DSC;

void MTKconvertDSK(){
    fi.open(FI);
    fo.open(FO);
    fi>>n;
    Matran.assign(n+1,vector<int>(n+1,0));
    DSK.assign(n+1,vector<int>());
    for(int i= 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            fi >> Matran[i][j];
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            if (Matran[i][j]==1){
                DSK[i].push_back(j);
            }
        }
    }
    for (int i = 1;i<=n;i++){
        fo << i<<": ";
        for (int j = 1;j<=DSK[i].size();j++){
            fo << DSK[i][j] << " ";
        }
        fo <<endl;
    }
    fi.close();
    fo.close();
}

void MTKconvertDSC(){
    fi.open(FI);
    fo.open(FO);
    fi>>n;
    Matran.assign(n+1,vector<int>(n+1,0));
    DSC.clear();
    for(int i= 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            fi >> Matran[i][j];
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            if (Matran[i][j]==1&&i<j){
                DSC.push_back({i,j});
            }
        }
    }
    for (auto x: DSC){
        fo<<x.first<<" "<<x.second<<endl;
    }
    fi.close();
    fo.close();
}

void DSKconvertMTK(){
    fi.open(FI);
    fo.open(FO);
    fi>> n;
    fi.ignore();
    Matran.assign(n+1,vector<int>(n+1,0));
    string line;
    for (int i = 1;i<=n;i++){
        getline(fi,line);
        stringstream ss(line);
        int x;
        while (ss>>x){
            Matran[i][x] = 1;
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            fo << Matran[i][j] << " ";
        }
        fo << endl;
    }
    fi.close();
    fo.close();
}

void DSKconvertDSC(){
    fi.open(FI);
    fo.open(FO);
    fi>>n;
    fi.ignore();
    DSC.clear();
    string line;
    for (int i = 1;i<=n;i++){
        getline(fi,line);
        stringstream ss(line);
        int x;
        while (ss>>x){
            if (i<x){
            DSC.push_back({i,x});
            }
        }
}
        for(auto a:DSC){
            fo << a.first << " " << a.second<<endl;
        }
}

void DSCconvertMTK(){
    fi.open(FI);
    fo.open(FO);
    fi>>n>>m;
    Matran.assign(n+1,vector<int>(n+1,0));
    for (int i = 1;i<=m;i++){
        int a , b;
        fi >> a >> b;
        Matran[a][b] = Matran[b][a] = 1;
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            fo << Matran[i][j]<< " ";
        }
        fo << endl;
    }
    fi.close();
    fo.close();
}

void DSCconvertDSK(){
    fi.open(FI);
    fo.open(FO);
    fi >> n >> m ;
    DSK.assign(n+1,{});
    for (int i = 1;i<=m;i++){
        int a , b;
        fi >> a >> b;
        if (a<b){
            DSK[a].push_back(b);
            DSK[b].push_back(a);
        }
    }
    for (auto x:DSC){
        fo << x.first << " " << x.second << endl;
    }
}

int main(){
      do{
        cout <<"____convert tools____\n";
        cout <<"1.Ma tran ke -> Danh sach ke\n";
        cout <<"2.Ma tran ke -> Danh sach canh\n";
        cout <<"3.Danh sach ke -> Ma tran ke\n";
        cout <<"4.Danh sach ke -> Danh sach canh\n";
        cout <<"5.Danh sach canh -> Ma tran ke\n";
        cout <<"6.Danh sach canh -> Danh sach ke\n";
        cout <<"7.Thoat chuong trinh!\n";
        cout <<"chon lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            MTKconvertDSK();
            break;
        case 2:
            MTKconvertDSC();
            break;
        case 3:
            DSKconvertMTK();
            break;
        case 4:
            DSKconvertDSC();
            break;
        case 5:
            DSCconvertMTK();
            break;
        case 6:
            DSCconvertDSK();
            break;
        case 7:
            cout <<"Ket thuc chuong trinh....";
            break;
        default: cout <<"So nhap ko hop le....";
            break;
        }
      }while (choice != 7);
      return 0;
    }
