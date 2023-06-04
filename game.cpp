//#include<iostream>
//#include<fstream> // doc va ghi file
//#include<cstdlib>
//#include<cstring>
//#include<string> // dung cho getline
//#include <stdlib.h> //thu vien mau`
//#include <unistd.h> // thu vien dung cho ham sleep
#include<bits/stdc++.h>
using namespace std;
//khai bao cac kieu du lieu su dung xuyen suot qua trinh 
string HoTen[300];
string NgheNghiep[300];
string Truong[300];
string QueQuan[300];
string CauHoi[500];
string DapAnA[300];
string DapAnB[300];
string DapAnC[300];
string DapAnD[300];
string DapAnDung[300];
string DapAnDung1[300];
string DapAnDung2[300];
string NamMuoiNamMuoi[200];
string GoiDienThoai[200];
string HoiKhanGia[200];
string NguoiTroGiup;
string TraLoiCauHoi;
string Reply;
string Enter;
string Cmd;
int SoCapDapAnDung;
int SoNguoiChoi;
int SoTroGiup;
int SoCauHoi;
//Khai bao ham nguyen mau
void NguoiChoi(string HoTen[],string NgheNghiep[],string Truong[],string QueQuan[]);
void DocNguoiChoi(string HoTen[],string NgheNghiep[],string Truong[],string QueQuan[]);
void LuuNguoiChoi(string HoTen[],string NgheNghiep[],string Truong[],string QueQuan[]);
void DocCauHoi(string CauHoi[],string DapAnA[],string DapAnB[],string DapAnC[],string DapAnD[],string DapAnDung[]);
void TroGiup(string NamMuoiNamMuoi[],string GoiDienThoai[],string HoiKhanGia[]);
void LoaiDapAnSai(string DapAnDung1[],string DapAnDung2[]);
void SanSang(string HoTen[],string Truong[],string QueQuan[]);
void BatDau(string Reply);

/*
0 = Black         8 = Gray
1 = Blue          9 = Light Blue
2 = Green         10 = Light Green
3 = Aqua          11 = Light Aqua
4 = Red           12 = Light Red
5 = Purple        13 = Light Purple
6 = Yellow        14 = Light Yellow
7 = White         15 = Bright White
*/
 
class Guest {	
public:
//Dinh nghia ham - Nguoi choi
void NguoiChoi(string HoTen[], string NgheNghiep[], string Truong[], string QueQuan[]) {
	cout<<"\t\tChao mung quy vi da den voi chuong trinh Ai La Trieu Phu (Enter)";
	getline(cin,Enter);
	cout<<endl;
	cout<<"Xin moi ban gioi thieu doi chut ve ban than minh: "<<endl;
	cout<<"- Ho va ten: ";
	getline(cin,HoTen[SoNguoiChoi]);
	cout<<"- Nghe nghiep: ";
	getline(cin,NgheNghiep[SoNguoiChoi]);
	if (NgheNghiep[SoNguoiChoi] == "sinh vien" || NgheNghiep[SoNguoiChoi] == "Sinh vien" || NgheNghiep[SoNguoiChoi] == "Sinh Vien") {
		cout << "- Ban la sinh vien truong nao: ";
		getline(cin, Truong[SoNguoiChoi]);										
	}
	cout<<"- Que Quan: ";
	getline(cin,QueQuan[SoNguoiChoi]);
	SoNguoiChoi++;
}

//------------------------------
void DocNguoiChoi(string Hoten[],string NgheNghiep[],string Truong[],string QueQuan[]){
	//Doc du lieu tu file nguoichoi.txt
	SoNguoiChoi=0;
	fstream fin("nguoichoi.txt");
	fin>>SoNguoiChoi;
	char temp[100];
	fin.getline(temp,100);
	for(int i=0;i<SoNguoiChoi;i++){
		getline(fin,HoTen[i]);
		getline(fin,NgheNghiep[i]);
		getline(fin,Truong[i]);
		getline(fin,QueQuan[i]);
	}
	fin.close();
}

//------------------------------
void LuuNguoiChoi(string HoTen[],string NgheNghiep[],string Truong[],string QueQuan[]){
	/*Luu du lieu xuong file nguoichoi.txt*/
	ofstream fout("nguoichoi.txt");
	fout<<SoNguoiChoi<<endl;
	for(int i=0;i<SoNguoiChoi;i++){
		fout<<HoTen[i]<<endl<<NgheNghiep[i]<<endl<<Truong[i]<<endl<<QueQuan[i]<<endl;
	}
	fout.close();
}
};



//====================================================
//Dinh nghia ham - Cau hoi va dap an
void DocCauHoi(string CauHoi[],string DapAnA[],string DapAnB[],string DapAnC[],string DapAnD[],string DapAnDung[]){
	//Doc du lieu tu file cauhoi.txt
	SoCauHoi=15;
	fstream fin("cauhoi.txt");
	fin>>SoCauHoi;
	char temp[100];
	fin.getline(temp,100);
	for(int i=0;i<SoCauHoi;i++){
		//Doc tu file in vao mang
		getline(fin,CauHoi[i]);
		getline(fin,DapAnA[i]);
		getline(fin,DapAnB[i]);
		getline(fin,DapAnC[i]);
		getline(fin,DapAnD[i]);
		getline(fin,DapAnDung[i]);
		//In cau hoi ra man hinh
		TroGiup(NamMuoiNamMuoi,GoiDienThoai,HoiKhanGia);
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
	
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi[0]==DapAnDung[i][0]||DapAnDung[i][0]==TraLoiCauHoi[0]-32){
			
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
			getline(cin, Enter);
			system("cls");
		}
		//50/50 (1)
		else if(TraLoiCauHoi=="1"){
			system("cls");
			TroGiup(NamMuoiNamMuoi,GoiDienThoai,HoiKhanGia);
			cout<<"Chung toi xin moi may tinh loai bo di 2 phuong an sai"<<endl;
			sleep(3);
			cout << "\n";
			cout<<CauHoi[i]<<endl;
			cout<<endl;
			LoaiDapAnSai(DapAnDung1,DapAnDung2);
			cout<<DapAnDung1[i]<<"\t\t\t\t"<<DapAnDung2[i]<<endl;
			cout<<endl;
			cout<<"=> Cau tra loi cuoi cung cua ban la: ";
			getline(cin,TraLoiCauHoi);
			if(TraLoiCauHoi[0]==DapAnDung[i][0]||DapAnDung[i][0]==TraLoiCauHoi[0]-32){
				
				cout<<"=> Do la cau cau tra loi dung !"<<endl;
				getline(cin, Enter);
				system("cls");
			}
			else{
				cout<<"=> Do la cau tra loi sai, rat tiec ban da phai dung cuoc choi o day !"<<endl;
				exit(0);
			}		
		}
		//Goi dien thoai (2)
		else if(TraLoiCauHoi=="2"){
			cout<<"- Va ban muon goi dien thoai cho ai ? - ";
			getline(cin,NguoiTroGiup);
			cout<<"- Chung toi xin ket noi dien thoai den ban "<<NguoiTroGiup<<" !"<<endl;
			sleep(3);
			cout<<"- \"Sau 30s goi dien, ban "<<NguoiTroGiup<<" xin tro giup dap an la: "<<DapAnDung[i]<<"\""<<endl;
			cout<<"=> Cau tra loi cuoi cung cua ban la: ";
			getline(cin,TraLoiCauHoi);
			if(TraLoiCauHoi[0]==DapAnDung[i][0]||DapAnDung[i][0]==TraLoiCauHoi[0]-32){
				
			
				cout<<"=> Do la cau cau tra loi dung !"<<endl;
				getline(cin, Enter);
				system("cls");
			}
			else{
				cout<<"=> Do la cau tra loi sai, rat tiec ban da phai dung cuoc choi o day !"<<endl;
			
				exit(0);
			}		
		}
		//Hoi khan gia (3)
		else if(TraLoiCauHoi=="3"){
		
			
		
			cout << "\nBan vui long doi trong giay lat"<<endl;
			cout << "........................" <<endl;
			sleep(3);
			cout<<"\t\"100% khan gia chon "<<DapAnDung[i]<<"\""<<endl;
			cout<<"=> Cau tra loi cuoi cung cua ban la: ";
			getline(cin,TraLoiCauHoi);
			if(TraLoiCauHoi[0]==DapAnDung[i][0]||DapAnDung[i][0]==TraLoiCauHoi[0]-32){
				
			
				cout<<"=> Do la cau cau tra loi dung !"<<endl;
					getline(cin, Enter);
					system("cls");	 
			
			}
			else{	
				cout<<"=> Do la cau tra loi sai, rat tiec ban da phai dung cuoc choi o day !"<<endl;
				
				exit(0);
			}		
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tiec ban da phai dung cuoc choi o day !"<<endl;
			
			exit(0);
		}
	}
	fin.close();
}

//====================================================
//Dinh nghia ham - san sang va bat dau choi
void SanSang(string HoTen[],string Truong[], string QueQuan[]){
	if (NgheNghiep[SoNguoiChoi-1] == "sinh vien" || NgheNghiep[SoNguoiChoi-1] == "Sinh vien" || NgheNghiep[SoNguoiChoi-1] == "Sinh Vien") {
		cout<<"=> Nguoi choi cua chung ta, ban "<<HoTen[SoNguoiChoi-1]<<" den tu "<<QueQuan[SoNguoiChoi-1]<<", la sinh vien cua " << Truong[SoNguoiChoi-1]<<" !"<<endl ;	
	} else {
	cout<<"=> Nguoi choi cua chung ta, ban "<<HoTen[SoNguoiChoi-1]<<" den tu "<<QueQuan[SoNguoiChoi-1]<<" !";
	getline(cin,Enter); }
	cout<<"=> Co tat ca 15 cau hoi dang doi ban !";
	getline(cin,Enter);
	cout<<"=> Co 3 moc cau hoi quan trong ban can vuot qua do la: " << endl;
	sleep(1);
	cout<<"\t\t=> 5 <=";
	cout <<endl;
	sleep(2);
	cout<<"\t\t=> 10 <=";
	cout <<endl;
	sleep(2);
	cout<<"\t\t=> 15 <=";
	cout <<endl;
	sleep(2);
}

//------------------------------
void BatDau(string Reply){

	char y,n;
	Nhap:
	cout<<endl<<"=> Ban da san sang choi chua ? (y/n) - ";
	getline(cin,Reply);
	if(Reply=="y"){
	
		cout<<"=> Nguoi choi da san sang va chung ta bat dau di tim ai la trieu phu !";
		getline(cin,Enter);
		
		system("cls");
	
		DocCauHoi(CauHoi,DapAnA,DapAnB,DapAnC,DapAnD,DapAnDung);
	}
	else if(Reply=="n"){
		cout<<"=> Rat tiec, nguoi choi cua chung ta chua san sang. Hen gap ban vao mot ngay khac."<<endl;
	}
	else{
		cout<<"=> Ban da nhap sai, vui long nhap lai !"<<endl;
		goto Nhap;
	}
}
//====================================================




//====================================================
//Tro giup
void TroGiup(string NamMuoiNamMuoi[],string GoiDienThoai[],string HoiKhanGia[]){
	SoTroGiup=1;
	fstream fin("trogiup.txt");
	fin>>SoTroGiup;
	char temp[100];
	fin.getline(temp,100);
	for(int i=0;i<SoTroGiup;i++){
		getline(fin,NamMuoiNamMuoi[i]);
		getline(fin,GoiDienThoai[i]);
		getline(fin,HoiKhanGia[i]);
		//In ra man hinh
		cout<<NamMuoiNamMuoi[i]<<"\t\t"<<GoiDienThoai[i]<<"\t\t"<<HoiKhanGia[i]<<endl;
	}
	cout<<"------------------------------------------------------------------------"<<endl;
	fin.close();
}
//------------------------------
//5050
void LoaiDapAnSai(string DapAnDung1[],string DapAnDung2[]){
	SoCapDapAnDung=15;
	fstream fin("5050.txt");
	fin>>SoCapDapAnDung;
	char temp[100];
	fin.getline(temp,100);
	for(int i=0;i<SoCapDapAnDung;i++){
		getline(fin,DapAnDung1[i]);
		getline(fin,DapAnDung2[i]);
	}
	fin.close();
}


//====================================================
int main(){
	system("color 2");
	Guest G;
	G.DocNguoiChoi(HoTen,NgheNghiep,Truong,QueQuan);
	G.NguoiChoi(HoTen,NgheNghiep,Truong,QueQuan);
	G.LuuNguoiChoi(HoTen,NgheNghiep,Truong,QueQuan);
	SanSang(HoTen,Truong,QueQuan);
	BatDau(Reply);
	return 0;
}
//====================================================






