#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class bk;
class hh;

class nsx
{
	private:
		char tennsx[20];
		char dc[30];
	friend class hh;
	friend class bk;
};

class date
{
	private:
		int d,m,y;
	friend class bk;
	friend void sx(bk a[75], int n);
	
};

class hh
{
	protected:
		char tenH[30];
		nsx x;
		int dg;
	public:
		void nhap();
		void xuat();

};

class bk:public hh
{
	private:
		int kt;
		date nn;
	public:
		void nhap();
		void xuat();
		void tim_bk();
		friend void hoanvi(bk *a, bk *b);
		friend void sx(bk a[75], int n);
		friend void chen(bk a[75],int *n);
		
};

void hh::nhap() 
{
	cout<<"\nNhap ten hang hoa: ";		fflush(stdin);		gets(tenH);
	cout<<"\nNhap ten nsx: ";			fflush(stdin);		gets(x.tennsx);
	cout<<"\nNhap dia chi nsx: ";		fflush(stdin);		gets(x.dc);
	cout<<"\nNhap don gia: ";								cin>>dg;
}

void hh::xuat()
{
	cout<<setw(20)<<tenH<<setw(20)<<x.tennsx<<setw(20)<<x.dc<<setw(10)<<dg;
}

void bk::nhap()
{
	cout<<"\nNhap kich thuoc ";					cin>>kt;
	hh::nhap();
	cout<<"\nNhap ngay: ";						cin>>nn.d;
	cout<<"\nNhap thang: ";						cin>>nn.m;
	cout<<"\nNhap nam: ";						cin>>nn.y;	
}

void bk::xuat()
{
	hh::xuat();
	cout<<setw(10)<<kt<<setw(15)<<nn.d<<"/"<<nn.m<<"/"<<nn.y<<endl;
	
}

void hoanvi(bk *a, bk *b)
{
	bk tg=*a;
	*a=*b;
	*b=tg;
}

void bk::tim_bk()
{
	if(stricmp(x.tennsx,"Hai Ha")==0 && stricmp(tenH,"Keo chew")==0)
		xuat();
}

void sx(bk a[75], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i].nn.y > a[j].nn.y)
				hoanvi(&a[i],&a[j]);
}

void chen(bk a[75], int *n)
{
	int k;
	cout<<"\nNhap vi tri can chen: ";	
	cin>>k;
	
	bk p; 
	p.nhap();
	
	for(int i=*n;i>k;i--)
		a[i]=a[i-1];
	a[k]=p;
	(*n)++;
}
main()
{
	bk *a;
	int n;
	
	cout<<"\nNhap so luong banh keo: ";	
	cin>>n;
	
	a=new bk[n];
	
	for(int i=0;i<n;i++)
		a[i].nhap();
	
	cout<<"SO BANH KEO VUA NHAP:"<<endl;
	cout<<setw(20)<<"TEN HH"<<setw(20)<<"TEN NSX"<<setw(20)<<"DIA CHI"<<setw(10)<<"DON GIA"<<
	setw(10)<<"KTHUOC"<<setw(15)<<"NGAY NHAP"<<endl;
	for(int i=0;i<n;i++)
		a[i].xuat();
	
	cout<<"Hang hoa can tim la: "<<endl;	
	cout<<setw(20)<<"TEN HH"<<setw(20)<<"TEN NSX"<<setw(20)<<"DIA CHI"<<setw(10)<<"DON GIA"<<
	setw(10)<<"KTHUOC"<<setw(15)<<"NGAY NHAP"<<endl;
	for(int i=0;i<n;i++)
		a[i].tim_bk();
		
	sx(a,n);
	cout<<"SO BANH KEO SAU KHI SAP XEP TANG DAN THEO NAM:"<<endl;
	cout<<setw(20)<<"TEN HH"<<setw(20)<<"TEN NSX"<<setw(20)<<"DIA CHI"<<setw(10)<<"DON GIA"<<
	setw(10)<<"KTHUOC"<<setw(15)<<"NGAY NHAP"<<endl;
	for(int i=0;i<n;i++)
		a[i].xuat();
		
	chen(a,&n);
	cout<<"SO BANH KEO SAU CHEN THEM :"<<endl;
	cout<<setw(20)<<"TEN HH"<<setw(20)<<"TEN NSX"<<setw(20)<<"DIA CHI"<<setw(10)<<"DON GIA"<<
	setw(10)<<"KTHUOC"<<setw(15)<<"NGAY NHAP"<<endl;
	for(int i=0;i<n;i++)
		a[i].xuat();
	
}



