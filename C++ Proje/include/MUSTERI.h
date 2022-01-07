#ifndef MUSTERI_H
#define MUSTERI_H
#include <iostream>
#include<fstream>
#include <sstream>
#include <cstring>
#include<ctime>
using namespace std;

class Musteri
{
public:
	int firmaNo;
	string firmaAdi;
	string firmaTel;
	string firmaSorm;
	string katagori;
	string adres;
	
	void musteriIslemi();
	void musteriEkle();
	void musteriAra();
	void musteriListele();
	void musteriSil();
	void musteriDuzenle();
};

class Urun
{
public:
	int urunNo;
	string urunAdi;
	string uretici;
	int teminSuresi;
	string uretimTarih;
	double urunFiyat;
	int indirim;
	int kdv;
	int stok;
	
	void urunIslemi();
	void urunEkle();
	void urunAra();
	void urunListele();
	void urunSil();
	void urunDuzenle();
	
};

class Siparis :Musteri, Urun
{
public:
	string firmNo;
	string uruNo;
	string siparisNo;
	string siparisTarihi;
	double siparisTutari;
	string siparisDosyasi;
	string siparisiAlan;
	int urunAdedi;
	
	
	void siparisIslemi();
	void siparisOlustur();
	void siparisAra();
	void siparisListele();
	void siparisSil();
	void siparisDuzenle();
	
};

#endif
