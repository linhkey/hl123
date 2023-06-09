#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class maytinh;

class nsx
{	
	private:
		char ten_nsx[20];
		char dc[25];
	public:
		void nhap();
		void xuat();
		friend void hienthi(maytinh a[30], int n);
};

class may
{
	protected:
		char nhanhieu[15];
		nsx x;
		float gia;
	public:
		void nhap();
		void xuat();
		friend void hienthi(maytinh a[30], int n);
};

class maytinh:public may
{
	private:
		int tocdo;
		int dl_ram;
		int dl_hdd;
	public:
		void nhap();
		void xuat();
		friend void hienthi(maytinh a[30], int n);
		friend void sx(maytinh a[30], int n);
		friend void hoanvi(maytinh *a, maytinh *b);
		friend void xoa(maytinh a[30], int *n);
};

void nsx::nhap()
{
	cout<<"\nNhap ten nha san xuat: ";			fflush(stdin);		gets(ten_nsx);
	cout<<"\nNhap dia chi nha san xuat: ";		fflush(stdin);		gets(dc);
}

void nsx::xuat()
{
	cout<<setw(15)<<ten_nsx<<setw(20)<<dc;
}

void may::nhap()
{
	cout<<"\nNhap nhan hieu: ";		fflush(stdin);		gets(nhanhieu);
	x.nhap();
	cout<<"\nNhap gia thanh: ";							cin>>gia;
}

void may::xuat()
{
	x.xuat();
	cout<<setw(10)<<nhanhieu<<setw(10)<<gia;
}

void maytinh::nhap()
{
	may::nhap();
	cout<<"\nNhap toc do: ";				cin>>tocdo;
	cout<<"\nNhap dung luong RAM: ";		cin>>dl_ram;
	cout<<"\nNhap dung luong o HDD: ";		cin>>dl_hdd;
}

void maytinh::xuat()
{
	may::xuat();
	cout<<setw(10)<<tocdo<<setw(5)<<dl_ram<<setw(5)<<dl_hdd<<endl;
}

void hienthi(maytinh a[30], int n)
{
	for(int i=0;i<n;i++)
		if(stricmp(a[i].x.ten_nsx,"IBM")==0)
			a[i].xuat();
}

void hoanvi(maytinh *a, maytinh *b)
{
	maytinh tg=*a;
	*a=*b;
	*b=tg;
}

void sx(maytinh a[30], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i].gia > a[j].gia)
				hoanvi(&a[i],&a[j]);
}

void xoa(maytinh a[30], int *n)
{
	for(int i=0;i<*n;i++)
		if(stricmp(a[i].nhanhieu,"Intel")==0)
		{
			for(int j=i;j<*n-1;j++)
				a[j]=a[j+1];
			(*n)--;
		}
}

main()
{
	maytinh a[30];
	int n;
	do
	{
		cout<<"\nNhap so luong may tinh: ";
		cin>>n;
	}while(n<2||n>30);
	
	for(int i=0;i<n;i++)
		a[i].nhap();
		
	cout<<"\nDANH SACH MAY TINH SAU KHI NHAP LA: "<<endl;
	cout<<setw(15)<<"TEN NSX"<<setw(20)<<"DIA CHI"<<setw(10)<<"N/HIEU"<<setw(10)<<"GIA"
	<<setw(10)<<"V"<<setw(5)<<"RAM"<<setw(5)<<"HDD"<<endl;
	for(int i=0;i<n;i++)
		a[i].xuat();
		
	cout<<"\nDANH SACH MAY TINH CUA IBM LA: "<<endl;
	cout<<setw(15)<<"TEN NSX"<<setw(20)<<"DIA CHI"<<setw(10)<<"N/HIEU"<<setw(10)<<"GIA"
	<<setw(10)<<"V"<<setw(5)<<"RAM"<<setw(5)<<"HDD"<<endl;
	hienthi(a,n);
	
	cout<<"\nDANH SACH SAU KHI SAP XEP TANG DAN GIA MAY LA: "<<endl;
	cout<<setw(15)<<"TEN NSX"<<setw(20)<<"DIA CHI"<<setw(10)<<"N/HIEU"<<setw(10)<<"GIA"
	<<setw(10)<<"V"<<setw(5)<<"RAM"<<setw(5)<<"HDD"<<endl;
	sx(a,n);
	for(int i=0;i<n;i++)
		a[i].xuat();
	
	cout<<"\nDANH SACH SAU KHI XOA MAY NHAN HIEU INTEL LA: "<<endl;
	cout<<setw(15)<<"TEN NSX"<<setw(20)<<"DIA CHI"<<setw(10)<<"N/HIEU"<<setw(10)<<"GIA"
	<<setw(10)<<"V"<<setw(5)<<"RAM"<<setw(5)<<"HDD"<<endl;
	xoa(a,&n);
	for(int i=0;i<n;i++)
		a[i].xuat();
	
	
}
