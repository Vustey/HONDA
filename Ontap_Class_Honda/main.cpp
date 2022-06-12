#include <iostream>
using  namespace std;
class Hanghoa{
public:
    int soluong;
    string tenhang;
    string mahang;
    virtual void input(){
        cout<<"Nhap so luong hang hoa :";
        cin>>soluong;
        cin.ignore();
        cout<<"Nhap ma hang hoa :";
        getline(cin,mahang);
        cout<<"Nhap ten hang hoa :";
        getline(cin,tenhang);
    }
    virtual void output(){
        cout<<"Ma hang:"<<mahang<<"  "<<"Ten hang:"<<tenhang<<"  "<<"So luong:"<<soluong<<"  ";
    }
     virtual int X25(){
         return 0;
    }
    virtual void sumSL(){};
    virtual bool check_honda(){};
};
class XeMay:public Hanghoa{
public:
    float giaxe;
    string nhasanxuat;
    void input(){
        Hanghoa::input();
        cout<<"Gia xe :";
        cin>>giaxe;
        cin.ignore();
        cout<<"Nha san xuat :";
        getline(cin,nhasanxuat);
    }
    void output(){
        Hanghoa::output();
        cout<<"Nha san xuat:"<<nhasanxuat<<" "<<"Gia xe:"<<giaxe<<endl;
    }
    int X25(){
        int check=0;
        if(giaxe<25){
            return check=1;
        }
    }
    bool check_honda(){
        string search;
        cout<<"\nNhap nha san xuat ban muon tinh tong :";
        getline(cin,search);
        if(nhasanxuat==search){
            return true;
        }else{
            return false;
        }
    }
//    int sumSL(){
//
//    }
};
class ListXemay{
public:
    Hanghoa *h[100];
    int n;
    void input(){
        cout<<"Nhap so luong :";
        cin>>n;
        for(int i=0;i<n;i++){
            h[i]=new XeMay;
            cout<<"Don so "<<i+1<<endl;
            h[i]->input();
        }
    }
    void output(){
        cout<<"\nDanh sach cac mat hang"<<endl;
        for(int i=0;i<n;i++){
            h[i]->output();
        }
    }
    //Hien thi xe co gia xe nho hon 25
    void X25(){
        cout<<"\nNhung xe co gia duoi 25 trieu"<<endl;
        for(int i=0;i<n;i++){
            if(h[i]->X25()==1){
                h[i]->output();
            }
        }
    }
    //Hien thi so luong xe va doanh thu ban cua hang xe Honda
    void SumHonda(){
        int sum=0;
        for(int i=0;i<n;i++){
            if(h[i]->check_honda()==true){
                sum+=XeMay().soluong;
            }
        }
        cout<<"Tong so luong la :"<<sum<<endl;
    }
};
int main() {
    ListXemay l;
    l.input();
    l.output();
    l.X25();
    l.SumHonda();
    return 0;
}
