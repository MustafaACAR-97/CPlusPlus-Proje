#include"MUSTERI.h"

using namespace std;

int main()
{
	int secim;
	do
	{
		cout<<"###################################################"<<endl;
		cout<<"Yapacaginiz islemi secizniz;"<<endl;
		cout<<"1- Musteri Islemi."<<endl;
		cout<<"2- Urun Islemi."<<endl;
		cout<<"3- Siparis Islemi."<<endl;
		cout<<"4- CIKIS."<<endl;
		cout<<"###################################################"<<endl;
		cin>>secim;
		
		Musteri musteri1;
		Urun urun1;
		Siparis siparis1;
		
		if(secim>0 ||secim<5)
		{
			switch(secim)
			{
				case 1:
					musteri1.musteriIslemi();
					break;
				case 2:
					urun1.urunIslemi();
					break;
				case 3:
					siparis1.siparisIslemi();
					break;
				case 4:
					cout<<"*-*-*-*-*-*Gorusmek Uzere*-*-*-*-*-*"<<endl;
					break;
			}
		}
	}	
	while(secim!=4);
	{
		
	}
}