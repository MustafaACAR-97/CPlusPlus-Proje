#include"MUSTERI.h"

int satirSayisi(string dosyaAdi)    //Bu Fonksiyon Txt Dosyasında Kaç Satır Olduğunu Hesaplıyor Ve Çasğırıldığı Yere Döndürüyor
{
	int satirSys=0;
	ifstream satirSay(dosyaAdi);
	string satir;
	if (satirSay.is_open())
	{
		while (getline(satirSay, satir))
		{
			satirSys=(satirSys+1);
		}
		satirSay.close();
	}
	
	return(satirSys);
};

string dOkuma(int a, int b, int sutunSys, string dosyaAdi)    // Bu Fonksiyon Txt Dosyasından Verileri Fonsiyonun Çağırıldığı Yere Aktarılmasını Sağlıyor
{
	int satirSys=satirSayisi(dosyaAdi);
	string diziKelime[satirSys][sutunSys]={};
	ifstream dosyaOku(dosyaAdi);
	if (dosyaOku.is_open())
	{
		for(int i=0; i<satirSys; i++)        // Txt Dosyasındaki Her Kelimeyi Tek Tek Diziye Aktarıyor
		{
			for(int j=0; j<sutunSys; j++)
			{
				dosyaOku>>diziKelime[i][j];
			}
		}
		dosyaOku.close();
	}
	return(diziKelime[a][b]);
};

int numaraUreten(string isim, string dosyaAdi)      // Bu Fonksiyon Rastgele Sayı Üretmek İçin Dosyadaki Satır Sayısını Ve Çağırıldığı Yerdeki Müşteri Veya Ürün Adını Kullanır
{
	int satirSys=satirSayisi(dosyaAdi);
	int numara;
	int toplam=0;
	int random;
	int enFazla=999999999;
	char ad[5]={};
	for(int i=0; i<5; i++)     //Gönderilen String İsmi Chara Dönüştürür 
	{
		for(int j=0; j<5; j++)
		{
			ad[j]=isim[i,j];
		}
	}
	
	for(int i=0; i<strlen(ad); i++)   // Gönderilen Her Harfin Ascii Değerini Toplayan Döngü
	{
		toplam=(toplam+int(ad[i]));
	}
	
	srand(time(0));
	random=(rand()%(enFazla - satirSys+1)+satirSys);
	
	numara=(random+toplam);
	
	return(numara);
};

string harfUreten()   // Sipariş Txt İçindeki Her Sipariş için Harflerden Oluşan Rastgele Bir Değer Üreten Fonksiyon
{
	char harf[6]={};
	srand(time(0));
	for(int i=0; i<6; i++)    // Rastgele Harf Üreten Döngü
	{
		harf[i]=(char)(rand()%26)+97;
	}
	string sHarf(harf); 
	return(harf);
};

void dosyaSilme(string dosyaAdi)    // Txt Dosyasının İçindeki Verileri Silen Fonksiyon
{
	ofstream dosyaTemizle(dosyaAdi);
	if(dosyaTemizle.is_open())
	{
		dosyaTemizle<<"";
	}
	dosyaTemizle.close();
};

void Musteri::musteriIslemi()   // Mainden Sonraki Müşteriye Dair İşlem Menüsü Fonksiyonu
{
	int sec;
	cout<<"1- Musterileri Listele."<<endl;
	cout<<"2- Musteri Ekle."<<endl;
	cout<<"3- Musteri Ara."<<endl;
	cout<<"4- Musteri Sil."<<endl;
	cout<<"5- Musteri Duzenle."<<endl;
	cin>>sec;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	if(sec==1 ||sec==2 ||sec==3||sec==4||sec==5)
	{
		switch(sec)
		{
			case 1:
				musteriListele();
				break;
			case 2:
				musteriEkle();
				break;
			case 3:
				musteriAra();
				break;
			case 4:
				musteriSil();
				break;
			case 5:
				musteriDuzenle();
				break;
		}
	}
	else
	{
		cout<<"Hatali Secim"<<endl;
	}
};

void Musteri::musteriEkle()      //Müşteri Ekleme İşlemini Yapan Fonksiyon
{
	cout<<"    **MUSTERI EKLE**"<<endl<<"Firma Adinizi Giriniz: ";
	cin>>firmaAdi;
	cout<<"Firmaya Ait Telefon Numarasını Giriniz: ";
	cin>>firmaTel;
	cout<<"Firma Sorumlusunu Giriniz: ";
	cin>>firmaSorm;
	cout<<"Firma Sektorunu Giriniz: ";
	cin>>katagori;
	cout<<"Firma Sehrini Giriniz: ";
	cin>>adres;
	string dosyaAdi="cari.txt";
	int firmaNo=numaraUreten(firmaAdi,dosyaAdi);
	fstream dosya(dosyaAdi,ios::out|ios::app);
	if(dosya.is_open())
	{
		dosya<<firmaNo<<" "<<firmaAdi<<" "<<firmaTel<<" "<<firmaSorm<<" "<<katagori<<" "<<adres<<endl;
		dosya.close();
	}
};

void Musteri::musteriAra()     // Kodu Girilen Müşteri Bilgilerini Ekrana Yazan Fonksiyon
{
	string dosyaAdi="cari.txt";
	int satirSys=satirSayisi(dosyaAdi);
	int sutunSys=6;
	string araSirket;
	cout<<"    **MUSTERI ARA**"<<endl<<"Sirket Nosunu Giriniz: ";
	cin>>araSirket;
	int onay=0;
	string diziKelime[satirSys][sutunSys]={};
	for(int i=0; i<satirSys; i++)   //Txt Dosyasından Alınan Her Veriyi Diziye Aktaran Döngü
	{
		for(int j=0; j<sutunSys; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
		}
	}
	
	for(int i=0; i<satirSys; i++)   //Girilen Kodu Dizideki Kodlar İle Karşılaştıran Döngü
	{
		if(araSirket==diziKelime[i][0])
		{
			for(int j=0; j<sutunSys; j++)   //Bulunan Veriyi Ekrana Yazdıran Döngü
			{
				cout<<diziKelime[i][j]<<" ";
			}
			cout<<endl;
			onay=1;
			break;
		}
	}
	if(onay==0)
	{
		cout<<"!!!KAYIT BULUNAMADI!!!"<<endl;
	}
};
	
void Musteri::musteriListele()   // Cari Txt Dosyasındaki Her Satırı Ekrana Yazdıran Foksiyon
{

	ifstream dosyaOku("cari.txt");
	string satir;
	if (dosyaOku.is_open())
	{
		while (getline(dosyaOku, satir))  // Dosyadaki Verileri Stringe Atayıp Sonra da Ekrana Yazdıran Döngü 
		{
			cout<<satir<<endl;
		}
		dosyaOku.close();
	}
};

void Musteri::musteriSil()     // Kodu Girilen Müşteriyi Txt Dosyasından Silen Fonksiyon
{
	string dosyaAdi="cari.txt";
	int satirSys=satirSayisi(dosyaAdi);
	int sutunSys=6;
	string silinecekMust;
	cout<<"    **MUSTERI SIL**"<<endl<<"Silinecek Olan Firmanin Nosunu Giriniz: ";
	cin>>silinecekMust;
	int onay=0;
	string diziKelime[satirSys][sutunSys]={};
	for(int i=0; i<satirSys; i++)    //Dosyadaki Her Veriyi Dizine Atayan Döngü
	{
		for(int j=0; j<sutunSys; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
		}
	}
	
	for(int i=0; i<satirSys; i++)    // Silinecek Verinin Hangisi Olduğunu Bulmayı Sağlayan Döngü
	{
		if(silinecekMust==diziKelime[i][0])
		{
			for(int y=i; y<(satirSys-1); y++)  // Diziden Veriyi Silen Döngü
			{
				for(int j=0; j<sutunSys; j++)
				{
					diziKelime[y][j]=diziKelime[y+1][j];
				}
			}
			
			dosyaSilme(dosyaAdi);
			
			fstream dosya(dosyaAdi,ios::out|ios::app);
			if(dosya.is_open())
			{
				for(int k=0; k<(satirSys-1); k++)   //Yeni Dizinin İçindeki Verileri Txt Dosyasına Yazan Döngü
				{
					for(int l=0; l<sutunSys; l++)
					{
						dosya<<diziKelime[k][l]<<" ";
					}
					dosya<<endl;
				}

				dosya.close();
			}
			
			cout<<"Işlem Tamamlandi"<<endl;
			onay=1;
			break;
		}
	}
	if(onay==0)
	{
		cout<<"!!!KAYIT BULUNAMADI!!!"<<endl;
	}
	
};

void Musteri::musteriDuzenle()    // Kodu Girilen Müşteri Bilgilerini Düzenleyen Fonksiyon
{
	string dosyaAdi="cari.txt";
	int satirSys=satirSayisi(dosyaAdi);
	string araSirket;
	cout<<"    **MUSTERI DUZENLE**"<<endl<<"Sirket Nosunu Giriniz: ";
	cin>>araSirket;
	int sayac=-1;
	int sutunSys=6;
	string diziDegis[sutunSys]; 
	string diziKelime[satirSys][sutunSys]={};
	for(int i=0; i<satirSys; i++)    //Dosyadaki Her Veriyi Dizine Atayan Döngü
	{
		for(int j=0; j<sutunSys; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
		}
	}
	
	for(int i=0; i<satirSys; i++)   // Düzenlenecek Verinin Hangisi Olduğunu Bulmayı Sağlayan Döngü
	{
		if(araSirket==diziKelime[i][0])
		{
			sayac=i;
			cout<<"Duzenlenecek Musteri Eski Bilgileri: "<<endl;
			for(int j=0; j<sutunSys; j++)    // Düzenlenecek Veri Hakkındaki Eski Bilgiyi Ekrana Yazan Döngü
			{
				cout<<diziKelime[i][j]<<" ";
			}
			cout<<endl;
			break;
		}
	}
	if(sayac==-1)
	{
		cout<<"!!!KAYIT BULUNAMADI!!!"<<endl;
	}
	else
	{
		cout<<"Yeni Bilgileri Giriniz:"<<endl;
		cout<<"Firma Adinizi Giriniz: ";
		cin>>diziDegis[1];
		cout<<"Firmaya Ait Telefon Numarasını Giriniz: ";
		cin>>diziDegis[2];
		cout<<"Firma Sorumlusunu Giriniz: ";
		cin>>diziDegis[3];
		cout<<"Firma Sektorunu Giriniz: ";
		cin>>diziDegis[4];
		cout<<"Firma Sehrini Giriniz: ";
		cin>>diziDegis[5];
		diziDegis[0]=araSirket;
		for(int i=0; i<sutunSys; i++)  //Yeni Bilgileri Diziye Yazan Döngü
		{
			diziKelime[sayac][i]=diziDegis[i];
		}
	
		dosyaSilme(dosyaAdi);
		
		for(int i=0; i<satirSys; i++)  // Yeni Veriyi Dosyaya Yazan Dongü
		{
			fstream dosya("cari.txt",ios::out|ios::app);
			if(dosya.is_open())
			{
				dosya<<diziKelime[i][0]<<" "<<diziKelime[i][1]<<" "<<diziKelime[i][2]<<" "<<diziKelime[i][3]<<" "<<diziKelime[i][4]<<" "<<diziKelime[i][5]<<endl;
				dosya.close();
			}
		}
		cout<<"Işlem Tamamlandi"<<endl;
	}
};

void Urun::urunIslemi()   // Mainden Sonraki Ürüne Dair İşlem Menüsü Fonksiyonu
{
	int sec;
	cout<<"1- Urunleri Listele."<<endl;
	cout<<"2- Urun Ekle."<<endl;
	cout<<"3- Urun Ara."<<endl;
	cout<<"4- Urun Sil."<<endl;
	cout<<"5- Urun Duzenle."<<endl;
	cin>>sec;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	if(sec==1 ||sec==2 ||sec==3||sec==4||sec==5)
	{
		switch(sec)
		{
			case 1:
				urunListele();
				break;
			case 2:
				urunEkle();
				break;
			case 3:
				urunAra();
				break;
			case 4:
				urunSil();
				break;
			case 5:
				urunDuzenle();
				break;
		}
	}
	else
	{
		cout<<"hatalı sec"<<endl;
	}
};

void Urun::urunEkle()    //Ürün Ekleme İşlemini Yapan Fonksiyon
{
	cout<<"    **URUN EKLE**"<<endl<<"Urun Adinizi Giriniz: ";
	cin>>urunAdi;
	cout<<"Uretici Firmayi Giriniz: ";
	cin>>uretici;
	cout<<"Temin Suresini Giriniz(Gun): ";
	cin>>teminSuresi;
	cout<<"Uretim Tarihini Giriniz: ";
	cin>>uretimTarih;
	cout<<"Fiyati Giriniz: ";
	cin>>urunFiyat;
	cout<<"Indirimi Giriniz: ";
	cin>>indirim;
	cout<<"KDV Oranını Giriniz: %";
	cin>>kdv;
	cout<<"Stok Adedini Giriniz: ";
	cin>>stok;
	string dosyaAdi="urun.txt";
	urunNo=numaraUreten(urunAdi,dosyaAdi);
	fstream dosya(dosyaAdi,ios::out|ios::app);
	if(dosya.is_open())
	{
		dosya<<urunNo<<" "<<urunAdi<<" "<<uretici<<" "<<teminSuresi<<" "<<uretimTarih<<" "<<urunFiyat<<" "<<indirim<<" "<<kdv<<" "<<stok<<endl;
		dosya.close();
	}
};

void Urun::urunListele()   // Ürün Txt Dosyasındaki Her Satırı Ekrana Yazdıran Foksiyon
{
	ifstream dosyaOku("urun.txt");
	string satir;
	if (dosyaOku.is_open())
	{
		while (getline(dosyaOku, satir))   // Dosyadaki Verileri Stringe Atayıp Sonra da Ekrana Yazdıran Döngü
		{
			cout<<satir<<endl;
		}
		dosyaOku.close();
	}
};

void Urun::urunSil()   // Kodu Girilen Ürünü Silen Fonksiyon
{
	string dosyaAdi="urun.txt";
	int satirSys=satirSayisi(dosyaAdi);
	int sutunSys=9;
	string silinecekUrun;
	cout<<"    **URUN SIL**"<<endl<<"Silinecek Olan Urunun Nosunu Giriniz: ";
	cin>>silinecekUrun;
	int onay=0;
	string diziKelime[satirSys][sutunSys]={};
	for(int i=0; i<satirSys; i++)  //Dosyadaki Her Veriyi Dizine Atayan Döngü
	{
		for(int j=0; j<sutunSys; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
		}
	}
	
	for(int i=0; i<satirSys; i++)  // Silinecek Verinin Hangisi Olduğunu Bulmayı Sağlayan Döngü
	{
		if(silinecekUrun==diziKelime[i][0])
		{
			for(int y=i; y<(satirSys-1); y++)   // Diziden Veriyi Silen Döngü
			{
				for(int j=0; j<sutunSys; j++)
				{
					diziKelime[y][j]=diziKelime[y+1][j];
				}
			}
			
			dosyaSilme(dosyaAdi);
			
			fstream dosya(dosyaAdi,ios::out|ios::app);
			if(dosya.is_open())
			{
				for(int k=0; k<(satirSys-1); k++)   //Yeni Dizinin İçindeki Verileri Txt Dosyasına Yazan Döngü
				{
					for(int l=0; l<sutunSys; l++)
					{
						dosya<<diziKelime[k][l]<<" ";
					}
					dosya<<endl;
				}

				dosya.close();
			}
			
			cout<<"Işlem Tamamlandi"<<endl;
			onay=1;
			break;
		}
	}
	if(onay==0)
	{
		cout<<"!!!KAYIT BULUNAMADI!!!"<<endl;
	}
};

void Urun::urunAra()   // Kodu Girilen Ürünün Bilgilerini Ekrana Yazan Fonksiyon
{
	string dosyaAdi="urun.txt";
	int satirSys=satirSayisi(dosyaAdi);
	int sutunSys=9;
	string araUrun;
	cout<<"    **URUN ARA**"<<endl<<"Urun Nosunu Giriniz: ";
	cin>>araUrun;
	int onay=0;
	string diziKelime[satirSys][sutunSys]={};
	for(int i=0; i<satirSys; i++)  //Txt Dosyasından Alınan Her Veriyi Diziye Aktaran Döngü
	{
		for(int j=0; j<sutunSys; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
		}
	}
	
	for(int i=0; i<satirSys; i++)  //Girilen Kodu Dizideki Kodlar İle Karşılaştıran Döngü
	{
		if(araUrun==diziKelime[i][0])
		{
			for(int j=0; j<sutunSys; j++)  //Bulunan Veriyi Ekrana Yazdıran Döngü
			{
				cout<<diziKelime[i][j]<<" ";
			}
			cout<<endl;
			onay=1;
			break;
		}
	}
	if(onay==0)
	{
		cout<<"!!!KAYIT BULUNAMADI!!!"<<endl;
	}
};

void Urun::urunDuzenle()  
{
	string dosyaAdi="urun.txt";
	int satirSys=satirSayisi(dosyaAdi);
	string araUrun;
	cout<<"    **URUN DUZENLE**"<<endl<<"Urun Nosunu Giriniz: ";
	cin>>araUrun;
	int sayac=-1;
	int sutunSys=9;
	string diziDegis[sutunSys]; 
	string diziKelime[satirSys][sutunSys]={};
	for(int i=0; i<satirSys; i++)  //Dosyadaki Her Veriyi Dizine Atayan Döngü
	{
		for(int j=0; j<sutunSys; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
		}
	}
	
	for(int i=0; i<satirSys; i++)   // Düzenlenecek Verinin Hangisi Olduğunu Bulmayı Sağlayan Döngü
	{
		if(araUrun==diziKelime[i][0])
		{
			sayac=i;
			cout<<"Duzenlenecek Urun Eski Bilgileri: "<<endl;
			for(int j=0; j<sutunSys; j++)  // Düzenlenecek Veri Hakkındaki Eski Bilgiyi Ekrana Yazan Döngü
			{
				cout<<diziKelime[i][j]<<" ";
			}
			diziDegis[0]=diziKelime[i][0];
			cout<<endl;
			break;
		}
	}
	if(sayac==-1)
	{
		cout<<"!!!KAYIT BULUNAMADI!!!"<<endl;
	}
	else
	{
		cout<<"Yeni Bilgileri Giriniz:"<<endl;
		cout<<"Urun Adinizi Giriniz: ";
		cin>>diziDegis[1];
		cout<<"Uretici Firmayi Giriniz: ";
		cin>>diziDegis[2];
		cout<<"Temin Suresini Giriniz(Gun): ";
		cin>>diziDegis[3];
		cout<<"Uretim Tarihini Giriniz: ";
		cin>>diziDegis[4];
		cout<<"Fiyati Giriniz: ";
		cin>>diziDegis[5];
		cout<<"Indirimi Giriniz: ";
		cin>>diziDegis[6];
		cout<<"KDV Oranını Giriniz: ";
		cin>>diziDegis[7];
		cout<<"Stok Adedini Giriniz: ";
		cin>>diziDegis[8];
	
		for(int i=0; i<sutunSys; i++)   //Yeni Bilgileri Diziye Yazan Fonksiyon
		{
			diziKelime[sayac][i]=diziDegis[i];
		}
	
		dosyaSilme(dosyaAdi);
		
		for(int i=0; i<satirSys; i++)   // Yeni Veriyi Dosyaya Yazan Dongü
		{
			fstream dosya(dosyaAdi,ios::out|ios::app);
			if(dosya.is_open())
			{
				dosya<<diziKelime[i][0]<<" "<<diziKelime[i][1]<<" "<<diziKelime[i][2]<<" "<<diziKelime[i][3]<<" "<<diziKelime[i][4]<<" "<<diziKelime[i][5]<<" "<<diziKelime[i][6]<<" "<<diziKelime[i][7]<<" "<<diziKelime[i][8]<<endl;
				dosya.close();
			}
		}
		cout<<"Işlem Tamamlandi"<<endl;
	}
};

void Siparis::siparisIslemi()   // Mainden Sonraki Siparişe Dair İşlem Menüsü Fonksiyonu
{
	int sec;
	cout<<"1- Siparis Listele."<<endl;
	cout<<"2- Siparis Olustur."<<endl;
	cout<<"3- Siparis Ara."<<endl;
	cout<<"4- Siparis Sil."<<endl;
	cout<<"5- Siparis Duzenle."<<endl;
	cin>>sec;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	if(sec==1 ||sec==2 ||sec==3||sec==4||sec==5)
	{
		switch(sec)
		{
			case 1:
				siparisListele();
				break;
			case 2:
				siparisOlustur();
				break;
			case 3:
				siparisAra();
				break;
			case 4:
				siparisSil();
				break;
			case 5:
				siparisDuzenle();
				break;
		}
	}
	else
	{
		cout<<"hatalı sec"<<endl;
	}
};

void Siparis::siparisOlustur()   // Sipariş Oluşturan Fonksiyon
{
	char eH;
	cout<<"    **SİPARİS OLUSTUR**"<<endl<<"Isminizi Giriniz: ";
	cin>>siparisiAlan;
	bool kapat;
	do
	{
		kapat=false;
		cout<<"Musteri Noyu Giriniz: ";
		cin>>firmNo;
		stringstream out;
		string karsilastir;
		out<<firmNo;
		karsilastir=out.str();
		string dosyaAdi="cari.txt";
		int satirSys=satirSayisi(dosyaAdi);
		int sutunSys=6;
		string diziKelime[satirSys][sutunSys]={};
		for(int i=0; i<satirSys; i++)   // Dosyadaki Verileri Diziye Atan Döngü
		{
			for(int j=0; j<sutunSys; j++)
			{
				diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
			}
		}
		
		for(int i=0; i<satirSys; i++)   // Girilen Kodu Dosyadaki İle Karşılaştıran Döngü
		{
			if(karsilastir==diziKelime[i][0])
			{
				kapat=true;
				break;
			}
		}	
		if(kapat==false)
		{
			cout<<"!!!Musteri Bulunamadı!!!"<<endl;
		}
		
	}
	while(kapat!=true);   //Girilen Müşteri Kodunu Kontrol Eden Ve Yanlış İse Uyarı Veren Döngü
	{
		
	}
	
	do
	{
		kapat=false;
		cout<<"Urun Kodunu Giriniz: ";
		cin>>uruNo;
		stringstream out;
		string karsilastir;
		out<<uruNo;
		karsilastir=out.str();
		string dosyaAdi="urun.txt";
		int satirSys=satirSayisi(dosyaAdi);
		int sutunSys=9;
		string diziKelime[satirSys][sutunSys]={};
		for(int i=0; i<satirSys; i++)  // Dosyadaki Verileri Diziye Atan Döngü
		{
			for(int j=0; j<sutunSys; j++)
			{
				diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
			}
		}
		
		for(int i=0; i<satirSys; i++)  // Girilen Kodu Dosyadaki İle Karşılaştıran Döngü
		{
			if(karsilastir==diziKelime[i][0])
			{
				kapat=true;
				break;
			}
		}	
		if(kapat==false)
		{
			cout<<"!!!Urun Bulunamadı!!!"<<endl;
		}
		
	}
	while(kapat!=true); //Girilen Ürün Kodunu Kontrol Eden Ve Yanlış İse Uyarı Veren Döngü
	{
		
	}
	cout<<"Urun Adedini Giriniz: ";
	cin>>urunAdedi;
	cout<<"Indirim Yapilacak Mi "<<"(Var Ise 'E' Yok Ise 'H')?";
	cin>>eH;
	double hamTutar;
	double KDV;
	double indirim;
	
	string urunTxt="urun.txt";
	int satirSys = satirSayisi(urunTxt);
	string diziKelime[satirSys][9]={};
	for(int i=0; i<satirSys; i++)  // Dosyadaki Verileri Diziye Atan Döngü
	{
		for(int j=0; j<9; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,9,urunTxt);
		}
	}
	
	for(int i=0; i<satirSys; i++)  // Dosyadan Girilen Ürüne Dair Verileri Alan Döngü
	{
		if(uruNo==diziKelime[i][0])
		{
			hamTutar=stoi(diziKelime[i][5]);
			KDV=stoi(diziKelime[i][7]);
			indirim=stoi(diziKelime[i][6]);
			
			break;
		}
	}
	
	if(eH=='E'||eH=='e')
	{
		siparisTutari=urunAdedi*(hamTutar-((hamTutar*indirim)/100)+((hamTutar*KDV)/100));
	}
	else
	{
		siparisTutari=urunAdedi*(hamTutar+((hamTutar*KDV)/100));
	}
	
	time_t tarih = time(NULL);
	struct tm *tarih_bilgisi = localtime(&tarih);
	char mTarih[50];
	strftime(mTarih, sizeof(mTarih), "%d-%m-%Y", tarih_bilgisi);
	siparisTarihi=mTarih;
	
	siparisNo=harfUreten();
	
	string dosyaAdi="siparis.txt";
	fstream dosya(dosyaAdi,ios::out|ios::app);
	if(dosya.is_open())
	{
		dosya<<siparisNo<<" "<<siparisiAlan<<" "<<siparisTutari<<" "<<siparisTarihi<<endl; 
		dosya.close();
	}
	siparisNo=siparisNo+".txt";
	fstream siparisListesi(siparisNo,ios::out|ios::app);
	if(siparisListesi.is_open())
	{
		siparisListesi<<siparisNo<<" "<<siparisiAlan<<" "<<firmNo<<" "<<uruNo<<" "<<urunAdedi<<" "<<siparisTutari<<" "<<siparisTarihi<<endl;
	}
	
};

void Siparis::siparisListele()   // Sipariş Txt Dosyasındaki Her Satırı Ekrana Yazdıran Fonksiyon
{
	ifstream dosyaOku("siparis.txt");
	string satir;
	if (dosyaOku.is_open())
	{
		while (getline(dosyaOku, satir))
		{
			cout<<satir<<endl;
		}
		dosyaOku.close();
	}
};

void Siparis::siparisAra()   // Girilen Koda Sahip Siparişi Dosyada Arayan Ve Verileri Ekrana Yazan Döngü
{
	string dosyaAdi="siparis.txt";
	int satirSys=satirSayisi(dosyaAdi);
	int sutunSys=4;
	string araSiparis;
	cout<<"    **SIPARIS ARA**"<<endl<<"Siparis Nosunu Giriniz: ";
	cin>>araSiparis;
	int onay=0;
	string diziKelime[satirSys][sutunSys]={};
	for(int i=0; i<satirSys; i++)  //Dosyadaki Her Veriyi Dizine Atayan Döngü
	{
		for(int j=0; j<sutunSys; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
		}
	}
	
	for(int i=0; i<satirSys; i++)   // Verinin Hangisi Olduğunu Bulmayı Sağlayan Döngü
	{
		if(araSiparis==diziKelime[i][0])
		{
			for(int j=0; j<sutunSys; j++)  // Aranan Sipariş Bilgilerini EKrana Yazan Döngü
			{
				cout<<diziKelime[i][j]<<" ";
			}
			cout<<endl;
			onay=1;
			break;
		}
	}
	if(onay==0)
	{
		cout<<"!!!KAYIT BULUNAMADI!!!"<<endl;
	}
};

void Siparis::siparisSil()    // Kodu Girilen Siparişi Dosyadan Silen Fonksiyon
{
	string dosyaAdi="siparis.txt";
	int satirSys=satirSayisi(dosyaAdi);
	int sutunSys=4;
	string silinecekSiparis;
	cout<<"    **SIPARIS SIL**"<<endl<<"Silinecek Olan Siparisin Nosunu Giriniz: ";
	cin>>silinecekSiparis;
	int onay=0;
	string diziKelime[satirSys][sutunSys]={};
	for(int i=0; i<satirSys; i++)  //Dosyadaki Her Veriyi Dizine Atayan Döngü
	{
		for(int j=0; j<sutunSys; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
		}
	}
	
	for(int i=0; i<satirSys; i++)  // Silinecek Verinin Hangisi Olduğunu Bulmayı Sağlayan Döngü
	{
		if(silinecekSiparis==diziKelime[i][0])
		{
			for(int y=i; y<(satirSys-1); y++)    // Diziden Veriyi Silen Döngü
			{
				for(int j=0; j<sutunSys; j++)
				{
					diziKelime[y][j]=diziKelime[y+1][j];
				}
			}
			
			dosyaSilme(dosyaAdi);
			
			fstream dosya(dosyaAdi,ios::out|ios::app);
			if(dosya.is_open())
			{
				for(int k=0; k<(satirSys-1); k++)   //Yeni Dizinin İçindeki Verileri Txt Dosyasına Yazan Döngü
				{
					for(int l=0; l<sutunSys; l++)
					{
						dosya<<diziKelime[k][l]<<" ";
					}
					dosya<<endl;
				}

				dosya.close();
			}
			
			cout<<"Işlem Tamamlandi"<<endl;
			onay=1;
			break;
		}
	}
	if(onay==0)
	{
		cout<<"!!!KAYIT BULUNAMADI!!!"<<endl;
	}
};

void Siparis::siparisDuzenle()   // Kodu Girilen Müşteri Bilgilerini Düzenleyen Fonksiyon
{
	char eH;
	string dosyaAdi="siparis.txt";
	int satirSys=satirSayisi(dosyaAdi);
	string araSiparis;
	cout<<"    **SIPARIS DUZENLE**"<<endl<<"Siparis Nosunu Giriniz: ";
	cin>>araSiparis;
	int sayac=-1;
	int sutunSys=4;
	string diziDegis[sutunSys]; 
	string diziKelime[satirSys][sutunSys]={};
	for(int i=0; i<satirSys; i++)  //Dosyadaki Her Veriyi Dizine Atayan Döngü
	{
		for(int j=0; j<sutunSys; j++)
		{
			diziKelime[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
		}
	}
	
	for(int i=0; i<satirSys; i++)  // Düzenlenecek Verinin Hangisi Olduğunu Bulmayı Sağlayan Döngü
	{
		if(araSiparis==diziKelime[i][0])
		{
			sayac=i;
			cout<<"Duzenlenecek Siparis Eski Bilgileri: "<<endl;
			for(int j=0; j<sutunSys; j++)  // Düzenlenecek Veri Hakkındaki Eski Bilgiyi Ekrana Yazan Döngü
			{
				cout<<diziKelime[i][j]<<" ";
			}
			diziDegis[0]=diziKelime[i][0];
			cout<<endl;
			break;
		}
	}
	if(sayac==-1)
	{
		cout<<"!!!KAYIT BULUNAMADI!!!"<<endl;
	}
	else
	{
		cout<<"Yeni Bilgileri Giriniz:"<<endl;
		cout<<"Isminizi Giriniz: ";
		cin>>siparisiAlan;
		bool kapat;
		do
		{
			kapat=false;
			cout<<"Musteri Noyu Giriniz: ";
			cin>>firmNo;
			stringstream out;
			string karsilastir;
			out<<firmNo;
			karsilastir=out.str();
			string dosyaAdi="cari.txt";
			int satirSys=satirSayisi(dosyaAdi);
			int sutunSys=6;
			string diziKelimeM[satirSys][sutunSys]={};
			for(int i=0; i<satirSys; i++) // Dosyadaki Verileri Diziye Atan Döngü
			{
				for(int j=0; j<sutunSys; j++)
				{
					diziKelimeM[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
				}
			}
		
			for(int i=0; i<satirSys; i++)  // Girilen Kodu Dosyadaki İle Karşılaştıran Döngü
			{
				if(karsilastir==diziKelimeM[i][0])
				{
					kapat=true;
					break;
				}
			}	
			if(kapat==false)
			{
				cout<<"!!!Musteri Bulunamadı!!!"<<endl;
			}	
		}
		while(kapat!=true);   //Girilen Müşteri Kodunu Kontrol Eden Ve Yanlış İse Uyarı Veren Döngü
		{}
	
		do
		{
			kapat=false;
			cout<<"Urun Kodunu Giriniz: ";
			cin>>uruNo;
			stringstream out;
			string karsilastir;
			out<<uruNo;
			karsilastir=out.str();
			string dosyaAdi="urun.txt";
			int satirSys=satirSayisi(dosyaAdi);
			int sutunSys=9;
			string diziKelimeU[satirSys][sutunSys]={};
			for(int i=0; i<satirSys; i++)
			{
				for(int j=0; j<sutunSys; j++) // Dosyadaki Verileri Diziye Atan Döngü
				{
					diziKelimeU[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
				}
			}
		
			for(int i=0; i<satirSys; i++)  // Girilen Kodu Dosyadaki İle Karşılaştıran Döngü
			{
				if(karsilastir==diziKelimeU[i][0])
				{
					kapat=true;
					break;
				}
			}	
			if(kapat==false)
			{
				cout<<"!!!Urun Bulunamadı!!!"<<endl;
			}		
		}
		while(kapat!=true); //Girilen Ürün Kodunu Kontrol Eden Ve Yanlış İse Uyarı Veren Döngü
		{}
		cout<<"Urun Adedini Giriniz: ";
		cin>>urunAdedi;
		cout<<"Indirim Yapilacak Mi "<<"(Var Ise 'E' Yok Ise 'H')?";
		cin>>eH;
		double hamTutar;
		double KDV;
		double indirim;
		
		string urunTxt="urun.txt";
		int satirSys = satirSayisi(urunTxt);
		string diziKelimeU2[satirSys][9]={};
		for(int i=0; i<satirSys; i++)  // Dosyadaki Verileri Diziye Atan Döngü
		{
			for(int j=0; j<9; j++)
			{
				diziKelimeU2[i][j]=dOkuma(i,j,9,urunTxt);
			}
		}
	
		for(int i=0; i<satirSys; i++)  // Dosyadan Girilen Ürüne Dair Verileri Alan Döngü
		{
			if(uruNo==diziKelimeU2[i][0])
			{
				hamTutar=stoi(diziKelimeU2[i][5]);
				KDV=stoi(diziKelimeU2[i][7]);
				indirim=stoi(diziKelimeU2[i][6]);	
				break;
			}
		}
	
		if(eH=='E'||eH=='e')
		{
			siparisTutari=urunAdedi*(hamTutar-((hamTutar*indirim)/100)+((hamTutar*KDV)/100));
		}
		else
		{
			siparisTutari=urunAdedi*(hamTutar+((hamTutar*KDV)/100));
		}
	
		time_t tarih = time(NULL);
		struct tm *tarih_bilgisi = localtime(&tarih);
		char mTarih[50];
		strftime(mTarih, sizeof(mTarih), "%d-%m-%Y", tarih_bilgisi);
		siparisTarihi=mTarih;
	
		siparisNo=araSiparis;
		dosyaAdi="siparis.txt";
		satirSys = satirSayisi(dosyaAdi);
		string diziKelimeS[satirSys][sutunSys]={};
		for(int i=0; i<satirSys; i++)  // Dosyadaki Verileri Diziye Atan Döngü
		{
			for(int j=0; j<sutunSys; j++)
			{
				diziKelimeS[i][j]=dOkuma(i,j,sutunSys,dosyaAdi);
			}
		}
		
		stringstream out;
		string tutar;
		out<<siparisTutari;
		tutar=out.str();
		
		diziDegis[0]=siparisNo;
		diziDegis[1]=siparisiAlan;
		diziDegis[2]=tutar;
		diziDegis[3]=siparisTarihi;
		
		siparisNo=siparisNo+".txt";
		fstream siparisListesi(siparisNo,ios::out);
		if(siparisListesi.is_open())
		{
			siparisListesi<<siparisNo<<" "<<siparisiAlan<<" "<<firmNo<<" "<<uruNo<<" "<<urunAdedi<<" "<<siparisTutari<<" "<<siparisTarihi<<endl;
		}

		for(int i=0; i<sutunSys; i++)   // Girilen Yeni Veriyi Diziye Aktaran Döngü
		{
			diziKelimeS[sayac][i]=diziDegis[i];
		}
		
		dosyaSilme(dosyaAdi);
		
		for(int i=0; i<satirSys; i++)   //Yeni Verileri Dosyaya Yazan Döngü
		{
			fstream dosya(dosyaAdi,ios::out|ios::app);
			if(dosya.is_open())
			{
				dosya<<diziKelimeS[i][0]<<" "<<diziKelimeS[i][1]<<" "<<diziKelimeS[i][2]<<" "<<diziKelimeS[i][3]<<endl;
				dosya.close();
			}
		}
		cout<<"Işlem Tamamlandi"<<endl;
	}
};
