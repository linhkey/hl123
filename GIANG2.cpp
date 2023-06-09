#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class NS
{
	protected:
		char HOTEN[20];
		char NGAY[15];
		char GIOITINH[5];
	public:
		void NHAP();
		void XUAT();
};

class NV:public NS
{
	private:
		char PB[15];
		char DC[25];
		int HSL;
		int HSPC;
		int GIAM;
	public:
		void NHAP();
		void XUAT();
		friend void TONG_TN(NV a[], int n);	
		friend void HOANVI(NV *a, NV *b);
		friend void SX(NV a[], int n);	
		friend void SUA(NV a[], int n);
};

void NS::NHAP()
{
	fflush(stdin);		
	cout<<"\nNHAP HO TEN: "; 			
	gets(HOTEN);
	
	fflush(stdin);
	cout<<"\nNHAP NGAY SINH: "; 	
	gets(NGAY);
	
	fflush(stdin);	
	cout<<"\nNHAP GIOI TINH: ";
	gets(GIOITINH);
}

void NS::XUAT()
{
	cout<<setw(20)<<HOTEN<<setw(15)<<NGAY<<setw(5)<<GIOITINH;
}

void NV::NHAP()
{
	
	NS::NHAP();
	fflush(stdin);
	cout<<"\nNHAP PHONG BAN:";
	gets(PB);
	
	fflush(stdin);
	cout<<"\nNHAP DIA CHI:";
	gets(DC);
	
	cout<<"\nNHAP HE SO LUONG:";
	cin>>HSL;
	
	cout<<"\nNHAP HE SO PHU CAP:";
	cin>>HSPC;
	
	cout<<"\nNHAP GIAM TRU:";
	cin>>GIAM;
}

void NV::XUAT()
{
	NS::XUAT();
	cout<<setw(15)<<PB<<setw(25)<<DC<<setw(5)<<HSL<<setw(5)<<HSPC<<setw(5)<<GIAM<<setw(10)<<830*(HSL+HSPC)-GIAM<<endl;
}

void TONG_TN(NV a[], int n)
{
	int S=0;
	for(int i=0;i<n;i++)
		if(stricmp(a[i].PB,"Hanh chinh")==0)
			S=S + (830*(a[i].HSL + a[i].HSPC) - a[i].GIAM);	
			
	cout<<"\nTONG THU NHAP CUA PHONG HANH CHINH LA:"<<S;
}

void HOANVI( NV *a, NV *b)
{
	NV tg=*a;
	*a=*b;
	*b=tg;	
}

void SX(NV a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i].HSL > a[j].HSL)
				HOANVI(&a[i],&a[j]);
				
	cout<<"\nDANH SACH NHAN VIEN SAP XEP TANG DAN HE SO LUONG LA: "<<endl;
	cout<<setw(20)<<"HO VA TEN"<<setw(15)<<"NGAY SINH"<<setw(5)<<"GT"<<
	setw(15)<<"PHONG"<<setw(25)<<"DIA CHI"<<setw(5)<<"HSL"<<setw(5)<<"HSP"<<setw(5)<<"GT"<<setw(10)<<"THU NHAP"<<endl;
	for(int i=0;i<n;i++)
		a[i].XUAT();
}

void SUA(NV a[], int n)
{
	for(int i=0;i<n;i++)
		if(stricmp(a[i].HOTEN,"NV01")==0)
			strcpy(a[i].PB,"Hanh chinh");
			
	cout<<"\nDANH SACH SAU KHI SUA LAI LA: "<<endl;
	cout<<setw(20)<<"HO VA TEN"<<setw(15)<<"NGAY SINH"<<setw(5)<<"GT"<<
	setw(15)<<"PHONG"<<setw(25)<<"DIA CHI"<<setw(5)<<"HSL"<<setw(5)<<"HSP"<<setw(5)<<"GT"<<setw(10)<<"THU NHAP"<<endl;
	for(int i=0;i<n;i++)
		a[i].XUAT();
}
main()
{
	NV p[100];
	int n;
	
	cout<<"\nNHAP SO NHAN VIEN: "; cin>>n;
	
	for(int i=0;i<n;i++)
		p[i].NHAP();
		
		
		cout<<"\n-----------------DANH SACH NHAN VIEN VUA NHAP LA----------------"<<endl;
	cout<<setw(20)<<"HO VA TEN"<<setw(15)<<"NGAY SINH"<<setw(5)<<"GT"<<
	setw(15)<<"PHONG"<<setw(25)<<"DIA CHI"<<setw(5)<<"HSL"<<setw(5)<<"HSP"<<setw(5)<<"GT"<<setw(10)<<"THU NHAP"<<endl;
		for(int i=0;i<n;i++)
		p[i].XUAT();
		
	TONG_TN(p,n);
	SX(p,n);
	SUA(p,n);
		
}


