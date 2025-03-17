#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;

void kedong(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
void ketieude() {		
	kedong(119);	
	cout << left << setw(5)  << "STT";	
	cout << left << setw(25) << "Ho va ten";
	cout << left << setw(12) << "ID";
	cout << left << setw(10) << "Gioi tinh";
	cout << left << setw(6)  << "Tuoi";
	cout << left << setw(31) << "Dia chi";
	cout << left << setw(13) << "SDT";
	cout << left << setw(15) << "Tien khach da tra" << endl;
}

void TiepTuc() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
}
void menu2() {
	system("cls");
	cout << "+----------------CHUONG TRINH QUAN LY-----------------+\n";
	cout << "|------------------------MENU-------------------------|\n";
    cout << "|  1. Sap xep theo thu tu tang dan.                   |\n";
    cout << "|  2. Sap xep theo thu tu giam dan.                   |\n";
    cout << "|  3. Quay lai.                                       |\n";
    cout << "+-----------------------------------------------------+\n";
	cout << "Vui long chon chuc nang: ";
}
void thongbao() {
	system("cls");
	cout << "\nKhong co chuc nang nay, vui long thu lai.";	
	TiepTuc();
}
class khachhang {		
	string ten, diachi, gioitinh;
	int tuoi, sdt, tien, id;	
    public:
	    void setTen(string ten) {
	    	this->ten=ten;
		}
		void setGioitinh(string gioitinh) {
	    	this->gioitinh=gioitinh;
		}
		void setTuoi(int tuoi) {
	    	this->tuoi=tuoi;
		}
		void setDiaChi(string diachi) {
	    	this->diachi=diachi;
		}
		void setSDT(int sdt) {
	    	this->sdt=sdt;
		}
		void setTien(int tien) {
	    	this->tien=tien;
		}  
		void setId(int id) {
	    	this->id=id;
		} 		   	
		khachhang() {
			tuoi=0; sdt=0;  ten=""; diachi=""; tien=0; gioitinh=""; id=0;
		}
		khachhang(string ten, string diachi, string gioitinh, int tuoi, int sdt, int tien, int id) {
			this -> ten=ten;
			this -> diachi=diachi;
			this -> tuoi=tuoi;
			this -> sdt=sdt;
			this -> tien=tien;
			this -> gioitinh=gioitinh;
			this -> id=id;
		}
		void congtien(khachhang kh[], int &tim, int &sum) {
			kh[tim-1].tien+=sum+(sum/100*5);
		}
		void nhap() {							
			cout << "\nNhap thong tin khach hang: " << endl << endl;
			cout << "Nhap ho va ten: ";			
			cin.ignore();
			getline(cin, ten);		
			cout << "Nhap ID: ";
			cin >> id;
			cout << "Nhap gioi tinh: ";
			cin >> gioitinh;
			cout << "Nhap tuoi: ";
			cin >> tuoi;
			cout << "Nhap dia chi: ";
			cin.ignore();
			getline(cin, diachi);
			cout << "Nhap so dien thoai: ";
			cin >> sdt;  
		}
		void vethongtin(khachhang kh[], int &dem) {
			for (int i=0; i<dem; i++) {	
				cout <<  left << setw(5)  << i+1 ;		
				cout <<  left << setw(25) << kh[i].ten;
				cout <<  left << setw(12) << kh[i].id;
				cout <<  left << setw(10) << kh[i].gioitinh;
				cout <<  left << setw(6)  << kh[i].tuoi;
				cout <<  left << setw(31) << kh[i].diachi << "0";
				cout <<  left << setw(12) << kh[i].sdt;
				cout <<  left << setw(15) << kh[i].tien <<endl;
			    }
			kedong(119);			
		}
		void xuat(khachhang kh[], int &dem) {
			if (dem==0) {				
				cout << "\n\nDanh sach trong.";
			}
			else {
				ketieude();
				vethongtin(kh, dem);		
			}
		}
		void capnhat(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDanh sach khach hang:";
				xuat(kh, dem);
				cout << "\nNhap so thu tu khach hang can cap nhat: ";
				cin >> id;
				if (id < 1 || id > dem) {
					cout << "\nKhong tim thay thong tin khach hang. Thu lai.";
				}
				else {
				    kh[id-1].nhap();
				    system("cls");
				    cout << "\nCap nhat thong tin khach hang thanh cong. Danh sach khach hang:";
				    xuat(kh, dem);
			    }	
			}			
		}
		void xoa(khachhang kh[], int &dem, int &tim) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDanh sach khach hang:";
				xuat(kh, dem);				
				cout << "\nNhap so thu tu khach hang can xoa: ";
				cin >> tim;
				if (tim < 1 || tim > dem) cout << "\nKhong tim thay thong tin khach hang. Thu lai.";
			    else {
				    for (int i=tim; i<=dem; i++) {
		    	        kh[i-1].id=kh[i].id;
			            kh[i-1].ten=kh[i].ten;
			            kh[i-1].gioitinh=kh[i].gioitinh;
			            kh[i-1].tuoi=kh[i].tuoi;
			            kh[i-1].diachi=kh[i].diachi;
			            kh[i-1].sdt=kh[i].sdt;
			            kh[i-1].tien=kh[i].tien;
			        }
			        kh[dem].ten="";
			        kh[dem].gioitinh="";
			        kh[dem].tuoi=0;			        
			        kh[dem].diachi="";
			        kh[dem].sdt=0;
			        kh[dem].tien=0;
			        dem--;
			        system("cls");
			        cout << "\nXoa thong tin khach hang thanh cong. Danh sach khach hang.";	
			        xuat(kh, dem);
			    }				
			}										
		}
		void timtheoid(khachhang kh[], int &dem, int &tim) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nNhap ID cua khach hang can tim: ";
				cin >> tim;
				ketieude();
                for (int i=0; i<dem; i++) {
            	    if (kh[i].id==tim) {
            	    cout <<  left << setw(5)  <<i+1;	
				    cout <<  left << setw(25) <<kh[i].ten;
				    cout <<  left << setw(12) <<kh[i].id;
				    cout <<  left << setw(10) <<kh[i].gioitinh;
				    cout <<  left << setw(6)  <<kh[i].tuoi;
				    cout <<  left << setw(31) <<kh[i].diachi << "0";
				    cout <<  left << setw(12) <<kh[i].sdt;
				    cout <<  left << setw(15) <<kh[i].tien << endl;
				    }				
			    }
			    kedong(119);
			    cout << "\nDa tim kiem xong. ";				
			}          
		}		
		void timtheosdt(khachhang kh[], int &dem, int &tim) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nNhap so dien thoai cua khach hang can tim: ";
				cin >> tim;
				ketieude();
                for (int i=0; i<dem; i++) {
            	    if (kh[i].sdt==tim) {
            	    cout <<  left << setw(5)  <<i+1;	
				    cout <<  left << setw(25) <<kh[i].ten;
				    cout <<  left << setw(12) <<kh[i].id;
				    cout <<  left << setw(10) <<kh[i].gioitinh;
				    cout <<  left << setw(6)  <<kh[i].tuoi;
				    cout <<  left << setw(31) <<kh[i].diachi << "0";
				    cout <<  left << setw(12) <<kh[i].sdt;
				    cout <<  left << setw(15) <<kh[i].tien << endl;
				    }				
			    }
			    kedong(119);
			    cout << "\nDa tim kiem xong. ";				
			}          
		}
		void timtheosotien(khachhang kh[], int &dem, int &tim) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nNhap so tien da chi tieu cua khach hang can tim: ";
				cin >> tim;
				ketieude();
                for (int i=0; i<dem; i++) {
            	    if (kh[i].tien==tim) {
            	    cout <<  left << setw(5)  <<i+1;	
				    cout <<  left << setw(25) <<kh[i].ten;
				    cout <<  left << setw(12) <<kh[i].id;
				    cout <<  left << setw(10) <<kh[i].gioitinh;
				    cout <<  left << setw(6)  <<kh[i].tuoi;
				    cout <<  left << setw(31) <<kh[i].diachi << "0";
				    cout <<  left << setw(12) <<kh[i].sdt;
				    cout <<  left << setw(15) <<kh[i].tien << endl;
				    }				
			    }
			    kedong(119);
			    cout << "\nDa tim kiem xong. ";				
			}          
		}
		void timtheotuoi(khachhang kh[], int &dem, int &tim) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nNhap tuoi cua khach hang can tim: ";
				cin >> tim;
				ketieude();
                for (int i=0; i<dem; i++) {
            	    if (kh[i].tuoi==tim) {
            	    cout <<  left << setw(5)  <<i+1;	
				    cout <<  left << setw(25) <<kh[i].ten;
				    cout <<  left << setw(12) <<kh[i].id;
				    cout <<  left << setw(10) <<kh[i].gioitinh;
				    cout <<  left << setw(6)  <<kh[i].tuoi;
				    cout <<  left << setw(31) <<kh[i].diachi << "0";
				    cout <<  left << setw(12) <<kh[i].sdt;
				    cout <<  left << setw(15) <<kh[i].tien << endl;
				    }				
			    }
			    kedong(119);
			    cout << "\nDa tim kiem danh sach khach hang xong. ";				
			}          
		}
		void sapxeptentang(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {				
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].ten > kh[j].ten) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";
			}
		}
		void sapxeptengiam(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDa sap xep danh sach: " << endl;
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].ten < kh[j].ten) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";				
			}
		}
		void sapxepidtang(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDa sap xep danh sach: " << endl;
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].id > kh[j].id) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";
			}
		}
		void sapxepidgiam(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDa sap xep danh sach: " << endl;
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].id < kh[j].id) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";				
			}
		}		
		void sapxeptuoitang(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDa sap xep danh sach. " << endl;
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].tuoi > kh[j].tuoi) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";				
			}
		}
		void sapxeptuoigiam(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDa sap xep danh sach. " << endl;
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].tuoi < kh[j].tuoi) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";				
			}
		}
		void sapxepdiachitang(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDa sap xep danh sach: " << endl;
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].diachi > kh[j].diachi) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";				
			}
		}
		void sapxepdiachigiam(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDa sap xep danh sach: " << endl;
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].diachi < kh[j].diachi) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";				
			}
		}		
		void sapxeptientang(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDa sap xep danh sach: " << endl;
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].tien > kh[j].tien) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";				
			}
		}
		void sapxeptiengiam(khachhang kh[], int &dem) {
			if (dem==0) {
				cout << "\nDanh sach khach hang: ";
				cout << "\n\nDanh sach trong. ";
			}
			else {
				cout << "\nDa sap xep danh sach: " << endl;
				for (int i=0; i<dem-1; i++) {
					for (int j = i+1; j < dem; j++) {
						if (kh[i].tien < kh[j].tien) {
							swap(kh[i].ten, kh[j].ten);
							swap(kh[i].id, kh[j].id);
						 	swap(kh[i].gioitinh, kh[j].gioitinh);
						 	swap(kh[i].tuoi, kh[j].tuoi);
						 	swap(kh[i].diachi, kh[j].diachi);
						 	swap(kh[i].sdt, kh[j].sdt);
						 	swap(kh[i].tien, kh[j].tien);
						}
					}
				}
				system("cls");
				xuat(kh, dem);
				cout << "\nDa sap xep danh sach khach hang xong. ";				
			}
		}																		
		void xuatfile(khachhang kh[], int &dem) {
			ofstream xuat1; 
            xuat1.open("danhsachkhachhang.csv");                        
            xuat1 << "STT" << "," << "Ho va ten" << "," << "ID" << ","<< "Gioi tinh"<< "," << "Tuoi" << "," << "Dia chi" << "," << "SDT" << "," << "Tien khach da tra" <<endl;               
            for (int i=0; i<=dem-1;i++) {      	
                xuat1 << i+1 << "," << kh[i].ten << "," << kh[i].id << "," << kh[i].gioitinh << ","<< kh[i].tuoi << "," << "\"" << kh[i].diachi << "\"" << "," << "\'"<< 0 << kh[i].sdt  << ","  << kh[i].tien << endl;
		        }
            xuat1.close();
			cout << "\nXuat danh sach khach hang thanh cong.";
		}
		void saoluu(khachhang kh[], int &dem) {
			ofstream outfile; 
            outfile.open("bonhodem.txt");                        
            outfile << dem << endl;
            for (int i=0; i<=dem-1;i++) {      	
                outfile << kh[i].ten << endl;
                outfile << kh[i].id << endl;
                outfile << kh[i].gioitinh << endl;
			    outfile << kh[i].tuoi << endl;
			    outfile << kh[i].diachi << endl;
			    outfile << kh[i].sdt << endl;
			    outfile << kh[i].tien << endl;
		        }
            outfile.close(); 	
			cout << "\nSao luu du lieu thanh cong.";		
		}
		void khoiphuc(khachhang kh[], int &dem, int &c, int &stuoi, int &ssdt, int &stien, string &sten, string &sdc, string &sgioitinh, int &sid) {
            ifstream infile; 
            infile.open("bonhodem.txt");      
	        infile >> c;  
            for (int i=0; i<=c; i++) {
    	    infile.ignore();
	        getline(infile, sten);
            kh[i].setTen(sten);	
            infile >> sid;
			kh[i].setId(sid);    	                   	    
	        infile >> sgioitinh;
	        kh[i].setGioitinh(sgioitinh);
			infile >> stuoi;	        
	        kh[i].setTuoi(stuoi);
	        infile.ignore();
            getline(infile, sdc);
            kh[i].setDiaChi(sdc);
            infile >> ssdt;
            kh[i].setSDT(ssdt);
            infile >> stien;
            kh[i].setTien(stien);
     	}
        infile.close();		
		dem=c;
		cout << "\nKhoi phuc du lieu thanh cong.";			
	}
	~khachhang() {
	}
};

int menu(khachhang kh[], int &dem, int &dem1, int &tim, int &c, int &stuoi, int &ssdt, int &stien, string &sten, string &sdc, string &sgioitinh, int &sid, int &sum, int&madon) {	
    while(true) {
    	quaylai1:
		system("cls");
		cout << "+----------------CHUONG TRINH QUAN LY-----------------+\n";
		cout << "|------------------------MENU-------------------------|\n";
        cout << "|  1. Them thong tin khach hang.                      |\n";
        cout << "|  2. Hien thi danh sach khach hang.                  |\n";
        cout << "|  3. Cap nhat thong tin khach hang.                  |\n";
        cout << "|  4. Xoa thong tin khach hang.                       |\n";
        cout << "|  5. Tim kiem thong tin khach hang.                  |\n";
        cout << "|  6. Sap xep danh sach khach hang.                   |\n";
        cout << "|  7. Chon san pham, in hoa don.                      |\n";
        cout << "|  8. Xuat danh sach khach hang thanh file.           |\n";
        cout << "|  9. Khoi phuc du lieu khach hang truoc do.          |\n";
        cout << "| 10. Thoat.                                          |\n";
        cout << "+-----------------------------------------------------+\n";
		cout << "Vui long chon chuc nang: ";
		int key;	
		cin >> key;
		switch (key) {
		    case 1:
		    	system("cls");
		    	kh[dem].nhap();
		    	dem++;
		    	TiepTuc();
		    	break;
		    case 2:
			    system("cls");
				cout << "\nDanh sach khach hang:";		    		
		    	kh[dem].xuat(kh, dem);
		    	TiepTuc();
		    	break;
		    case 3:
		    	system("cls"); 		    	
                kh[dem].capnhat(kh, dem);
                TiepTuc();
                break;
            case 4:   
			    system("cls");         	
                kh[dem].xoa(kh, dem, tim);
                TiepTuc();
                break;
            case 5:
                while (true) {             	
                	system("cls");
		            cout << "+----------------CHUONG TRINH QUAN LY-----------------+\n";
		            cout << "|------------------------MENU-------------------------|\n";
		            cout << "|  1. Tim kiem theo ID.                               |\n";
                    cout << "|  2. Tim kiem theo sdt.                              |\n";
                    cout << "|  3. Tim kiem theo so tien.                          |\n";
                    cout << "|  4. Tim kiem theo tuoi.                             |\n";
                    cout << "|  5. Quay lai.                                       |\n";
                    cout << "+-----------------------------------------------------+\n";
		            cout << "Vui long chon chuc nang: ";
		            int key;	
		            cin >> key;
		            switch (key) {
		            	case 1:
		            		system("cls");
		            		kh[dem].timtheoid(kh, dem, tim);
		            		TiepTuc();
                            break;		            		
		            	case 2:		 
						    system("cls");           		
		            		kh[dem].timtheosdt(kh, dem, tim);
		            		TiepTuc();
                            break; 
						case 3:
						    system("cls");							
							kh[dem].timtheosotien(kh, dem, tim);
		            		TiepTuc();
                            break;
		            	case 4:	
						    system("cls");							            		
		            		kh[dem].timtheotuoi(kh, dem, tim);
		            		TiepTuc();
                            break; 												     
		            	case 5:
		            		goto quaylai1;
		            	default:
		            		thongbao();
							break;		
					}
				}
			case 6:
                while (true) {
                    quaylai2:
               	    system("cls");
		            cout << "+----------------CHUONG TRINH QUAN LY-----------------+\n";
		            cout << "|------------------------MENU-------------------------|\n";
                    cout << "|  1. Sap xep theo ten.                               |\n";
                    cout << "|  2. Sap xep theo ID.                                |\n";
                    cout << "|  3. Sap xep theo so tuoi.                           |\n";
                    cout << "|  4. Sap xep theo dia chi.                           |\n";
                    cout << "|  5. Sap xep theo so tien.                           |\n";
                    cout << "|  6. Quay lai.                                       |\n";
                    cout << "+-----------------------------------------------------+\n";
		            cout << "Vui long chon chuc nang: ";
		            int key;	
		            cin >> key;
		            switch (key) {
		            	case 1:	
							while (true) {
								menu2();
								int key;
								cin >> key;
								switch (key) {
									case 1:
										system("cls");
										kh[dem].sapxeptentang(kh, dem);
										TiepTuc();
										break;
									case 2:
										system("cls");
										kh[dem].sapxeptengiam(kh, dem);
									    TiepTuc(); 
									    break;
									case 3:
										goto quaylai2;
									default:
									    thongbao();			    
				                        break;									    	
								}
							}   
						case 2:
							while (true) {
								menu2();
								int key;
								cin >> key;
								switch (key) {
									case 1:
										system("cls");
										kh[dem].sapxepidtang(kh, dem);
										TiepTuc();
										break;
									case 2:
										system("cls");
										kh[dem].sapxepidgiam(kh, dem);
									    TiepTuc(); 
									    break;
									case 3:
										goto quaylai2;
									default:
									    thongbao();		    
				                        break;										
								}
							} 						           		
						case 3:
							while (true) {
								menu2();
								int key;
								cin >> key;
								switch (key) {
									case 1:
										system("cls");
										kh[dem].sapxeptuoitang(kh, dem);
										TiepTuc();
										break;
									case 2:
										system("cls");
										kh[dem].sapxeptuoigiam(kh, dem);
									    TiepTuc(); 
									    break;
									case 3:
										goto quaylai2;
									default:
									    thongbao();		    
				                        break;										
								}
							} 
		            	case 4:		            		
							while (true) {
								menu2();
								int key;
								cin >> key;
								switch (key) {
									case 1:
										system("cls");
										kh[dem].sapxepdiachitang(kh, dem);
										TiepTuc();
										break;
									case 2:
										system("cls");
										kh[dem].sapxepdiachigiam(kh, dem);
									    TiepTuc(); 
									    break;
									case 3:
										goto quaylai2;
									default:
									    thongbao();			    
				                        break;										
								}
							}
						case 5:
							while (true) {
								menu2();
								int key;
								cin >> key;
								switch (key) {
									case 1:
										system("cls");
										kh[dem].sapxeptientang(kh, dem);
										TiepTuc();
										break;
									case 2:
										system("cls");
										kh[dem].sapxeptiengiam(kh, dem);
									    TiepTuc(); 
									    break;
									case 3:
										goto quaylai2;
									default:
									    thongbao();			    
				                        break;										
								}
							}						    						     												     
		            	case 6:		            		
		            		goto quaylai1;
		            	default:
		            		thongbao();
							break;		
					}
				}					
				case 7:
					while (true) {
						system("cls");
						if (dem==0) {
							cout << "\nDanh sach trong. ";
							TiepTuc();
							goto quaylai1;
						}
						system("cls");
						cout << "\nDanh sach khach hang:";
						kh[dem].xuat(kh, dem);
						cout << "\nNhap so thu tu cua khach hang can thanh toan: ";
						cin >> tim;	
						if (tim < 1 || tim > dem) {
							cout << "\nKhong tim thay thong tin khach hang. Thu lai.";
							TiepTuc();	
							goto quaylai1;
						}
						quaylai3:										
						system("cls");
                        cout  <<"+------------------------CHUONG TRINH QUAN LY--------------------+\n";
                        cout  <<"|--------------------------------MENU----------------------------|\n";
                     	cout  <<"| STT  |               San pham                  |    Gia tien   |"<< endl;
	                    cout  <<"|------|-----------------------------------------|---------------|"<< endl;
	                    cout  <<"| 1.   |   Ao vest                               |   500.000 dong|" << endl;
	                    cout  <<"|------|-----------------------------------------|---------------|"<< endl;
	                    cout  <<"| 2.   |   Ao thun                               |    75.000 dong|" << endl;
	                    cout  <<"|------|-----------------------------------------|---------------|"<< endl;
	                    cout  <<"| 3.   |   Ao somi                               |   150.000 dong|" << endl;
	                    cout  <<"|------|-----------------------------------------|---------------|"<< endl;
	                    cout  <<"| 4.   |   Ao gile                               |    95.000 dong|" << endl;
	                    cout  <<"|------|-----------------------------------------|---------------|"<< endl;
	                    cout  <<"| 5.   |   Ao chong nang                         |   175.000 dong|" << endl;
	                    cout  <<"|------|-----------------------------------------|---------------|"<< endl;
	                    cout  <<"| 6.   |   Quan jean                             |   195.000 dong|" << endl;
	                    cout  <<"|------|-----------------------------------------|---------------|"<< endl;
	                    cout  <<"| 7.   |   Quan tay                              |   700.000 dong|" << endl;
	                    cout  <<"|------|-----------------------------------------|---------------|"<< endl;
	                    cout  <<"| 8.   |   Quan the thao                         |    50.000 dong|" << endl;
	                    cout  <<"|------|-----------------------------------------|---------------|"<< endl;
	                    cout  <<"| 9.   |   Non the thao                          |    45.000 dong|" << endl;
	                    cout  <<"|------|---------------------------------------------------------|"<< endl;
	                    cout  <<"| 0.   |   QUAY LAI                                              |" << endl;
	                    cout  <<"+----------------------------------------------------------------+"<< endl;
	                    cout  << endl;
	                    cout <<"Nhap so loai san pham can thanh toan: ";
	                    int thanhtoan, soluong[10], giatien[10], sum=0;
	                    int no[10];
	                    int gia1hang[10]={500000, 75000, 150000, 95000, 175000, 195000, 700000, 50000, 45000};
	                    string name[10], size[10];
						int key, n;
						cin >> n;
						if(n>0 && n<=9) {														
							for(int i=0; i<n; i++) {
								cout << "\nChon san pham thu " << i+1 <<": ";
								cin >> no[i];
								if (no[i]==0) goto quaylai1;
			                    else if (no[i]==1)
			                    {
               				        name[i]="Ao vest";              				    
               				        cout << "Chon so luong: ";
               				        cin >> soluong[i];
               				        cout << "Chon kich thuoc (S, M, L, XL): ";
               				        cin >> size[i];
               				        giatien[i]=500000*soluong[i];
			                    }
                    			else if (no[i]==2)
                    			{
                   				    name[i]="Ao thun";
                   				    cout << "Chon so luong: ";
                   				    cin >> soluong[i];
               				        cout << "Chon kich thuoc (S, M, L, XL): ";
               				        cin >> size[i];                   				    
                    			    giatien[i]=75000*soluong[i];
                    			}	
                    			else if (no[i]==3)
                    			{
                    				name[i]="Ao somi";
                    				cout << "Chon so luong: ";
                    				cin >> soluong[i];
               				        cout << "Chon kich thuoc (S, M, L, XL): ";
               				        cin >> size[i];                    				              				        
                    				giatien[i]=150000*soluong[i];
                    			}
                    			else if (no[i]==4)
                    			{
               				        cout << "Chon so luong: ";
               				        cin >> soluong[i]; 
               				        cout << "Chon kich thuoc (S, M, L, XL): ";
               				        cin >> size[i];									                      				
                    				name[i]="Ao gile";
                    				giatien[i]=95000*soluong[i];
                    			}
                    			else if (no[i]==5)
                    			{
                    				cout << "Chon so luong: ";
               				        cin >> soluong[i];
               				        cout << "Chon kich thuoc (S, M, L, XL): ";
               				        cin >> size[i];               				        
                    				name[i]="Ao chong nang";
                    				giatien[i]=175000*soluong[i];
                    			}
                    			else if (no[i]==6)
                    			{
                    				cout << "Chon so luong: ";
               				        cin >> soluong[i];
               				        cout << "Chon kich thuoc (S, M, L, XL): ";
               				        cin >> size[i];               				        
                    				name[i]="Quan jean";
                    				giatien[i]=195000*soluong[i];
                    			}
                    			else if (no[i]==7)
                    			{
                    				cout << "Chon so luong: ";
               				        cin >> soluong[i];
               				        cout << "Chon kich thuoc (S, M, L, XL): ";
               				        cin >> size[i];               				        
                    				name[i]="Quan tay";
                    				giatien[i]=700000*soluong[i];
                    			}
                    			else if (no[i]==8)
                    			{
                    				cout << "Chon so luong: ";
               				        cin >> soluong[i];
               				        cout << "Chon kich thuoc (S, M, L, XL): ";
               				        cin >> size[i];               				        
                    				name[i]="Quan the thao";
                    				giatien[i]=50000*soluong[i];
                    			}
                    			else if (no[i]==9)
                    			{
                    				cout << "Chon so luong: ";
               				        cin >> soluong[i];
               				        cout << "Chon kich thuoc (S, M, L, XL): ";
               				        cin >> size[i];               				        
                    				name[i]="Non the thao";
                    				giatien[i]=45000*soluong[i];
                    			}
                    			else {
                    				cout << "\nThong tin nhap khong hop le, vui long thu lai.";
                    				TiepTuc();
                    				goto quaylai3;
								}
                    			sum+=giatien[i];
							}
							quaylai4:
							system("cls");
	                        cout << "+----------------CHUONG TRINH QUAN LY-----------------+\n";
	                        cout << "|------------------------MENU-------------------------|\n";
                            cout << "|  1. In hoa don.                                     |\n";
                            cout << "|  2. Quay lai.                                       |\n";
                            cout << "+-----------------------------------------------------+\n";
                        	cout << "Vui long chon chuc nang: ";
							int key;
							cin >> key;
							switch (key) {
								case 1:
									system("cls"); 
									cout << "\nThong tin don hang cua khach: ";
									kedong(60);	
	                                cout << left << setw(5) << "STT";	
                                	cout << left << setw(17)<< "Ten mat hang";
                                	cout << left << setw(5)<< "Size";
                                	cout << left << setw(10) << "So luong";
                                	cout << left << setw(14)<< "Gia/mat hang";
                                	cout << left << setw(19)<< "Tong cong" << endl;
									for(int i=0; i<n; i++)
									{
									cout <<left << setw(5)<< i+1;
									cout <<left << setw(17)<< name[i];
									cout << left << setw(5)<< size[i];
									cout <<left << setw(10)<< soluong[i];
									cout <<left << setw(14)<< gia1hang[i];
									cout <<left << setw(19)<< giatien[i];
									cout << endl;									
									}
									kedong(60);
									cout << endl;
									cout << "THANH TIEN:                         "<< sum;
									cout << endl;
									cout << "THUE VAT (5% TONG HOA DON):         "<< sum/100*5;	
									cout << endl;			
									cout << "TONG SO TIEN CAN THANH TOAN:        "<< sum+(sum/100*5);
									cout << endl;
									cout << "TIEN KHACH DUA:                     ";
									cin >> thanhtoan;
									if (thanhtoan >= (sum+(sum/100*5))) {
									    cout << "TIEN THUA:                          " << thanhtoan - (sum+(sum/100*5))<<endl;
										cout << "\nIN HOA DON THANH CONG, BAM PHIM BAT KY DE XEM HOA DON.";
										getch();
										system ("cls");
										cout <<"\n                  =======    HOA-DON    =======                  ";
										cout << endl << endl;
										cout << "----------------------------------------------------------------\n";
					                	cout << "                          "<<"MA HOA DON: " << madon+1 << endl;
					                	madon++;
										time_t now = time(0);
                                        tm *ltm = localtime(&now);
                                        cout << "           "<<"NGAY, GIO, IN HOA DON: " << ltm->tm_mday << "/" <<1 + ltm->tm_mon<< "/"<<1900 + ltm->tm_year << ", "<<ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec ;					                					                	
					                	cout << endl;
            							cout << "----------------------------------------------------------------"<< endl;
            							cout << "                       DANH SACH MAT HANG                       ";
									    kedong(64);	
	                                    cout << left << setw(5) << "STT";	
                                	    cout << left << setw(17)<< "Ten mat hang";
                                	    cout << left << setw(5)<< "Size";
                                	    cout << left << setw(10) << "So luong";
                                	    cout << left << setw(14)<< "Gia/mat hang";
                                	    cout << left << setw(19)<< "Tong cong" << endl;
									    for(int i=0; i<n; i++)
									    {
									    cout <<left << setw(5)<< i+1;
									    cout <<left << setw(17)<< name[i];
									    cout << left << setw(5)<< size[i];
									    cout <<left << setw(10)<< soluong[i];
									    cout <<left << setw(14)<< gia1hang[i];
									    cout <<left << setw(19)<< giatien[i];
									    cout << endl;									
								     	}
									    kedong(64);
            							cout<<endl;
            							cout <<"THANH TIEN:                                        " << sum <<endl;            							
            							cout <<"THUE VAT (5% TONG HOA DON):                        "<< sum/100*5;
            							cout << endl;
            							cout <<"----------------------------------------------------------------"<< endl;
            							cout<<endl;
            							cout <<"THANH TOAN:                                        " << sum+(sum/100*5) <<endl;
            							cout << endl;
            							cout <<"TIEN KHACH DUA:                                    " << thanhtoan << endl;
            							cout <<"TIEN THUA:                                         " << thanhtoan-(sum+(sum/100*5))<<endl;
										kh[dem].congtien(kh, tim, sum); 										       							
            							cout<<endl;
					                	cout<<"======================  CAM-ON-QUY-KHACH  ======================"<<endl;
						                cout<<endl;
						                cout<<"=======================   HEN-GAP-LAI   ========================";
            							TiepTuc();
            							goto quaylai1;
									}
									else
   				   				    {
			                        cout << "\nSO TIEN KHONG DU.";
			                        TiepTuc();
			                        goto quaylai4;
				                    }
								case 2:
									goto quaylai3;
								default:
									thongbao();
									goto quaylai4;
							}							
						}
						else if (n==0) goto quaylai1;
						else {
							cout << "\nSo loai san pham khong hop le, vui long nhap lai.";
							TiepTuc();
							goto quaylai3;							
						}						                              
					}
				case 8:
					system ("cls");
                    kh[dem].xuatfile(kh, dem);
				    TiepTuc();
				    break;	
				case 9:
					system ("cls");
				    kh[dem].khoiphuc(kh, dem, c, stuoi, ssdt, stien, sten, sdc, sgioitinh, sid);
					TiepTuc();
				    break;			   			          	
		    	case 10:
		    		system ("cls");
                    kh[dem].saoluu(kh, dem);		    		
		    		cout << "\n\nDa thoat khoi chuong trinh. Hen gap lai. ";
		    		return 0;
		    	default:
                    thongbao();
                    break;
			}
	}
}


int main() {
	int c, stuoi, ssdt, stien, sid, sum, madon=0;
    string sten, sdc, sgioitinh;
	khachhang kh[1000];
	int dem=0, dem1=0, tim;
    menu(kh, dem, dem1, tim, c, stuoi, ssdt, stien, sten, sdc, sgioitinh, sid, sum, madon);
    return 0;
} 








