/**
* @file Main.cpp
* @description n adet Listeyi oluşturan, dosyadan okuma işlemini yapıp ekleme için gerekli fonk. çağıran, ekrana yazdırmak için gerekli fonk çağıran, listeyi silip heap temizleyen kaynak dosyası.
* @course 1/A
* @assignment 1. Ödev
* @date 26.07.2020
* @author Ahmet Mücahit Gürer
*/

#include <cstdlib>
#include "CDLL.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;

int main()
{
	int satirsayi=0;
	int say=0;
	string satir,kelime;
	
    ifstream file("Sayilar.txt"); //dosya yolu

	while (getline(file, satir)) //getline ile satır sayısı bul
    {
		satirsayi++;
	}
	
	file.clear(); 
	file.seekg(0, ios::beg); //dosya indexini sıfırla başa al
	
	CDLL** sayilar = new CDLL*[satirsayi]; //satir sayisi kadar liste oluştur
	
	for(int i=0;i<satirsayi;i++)
	sayilar[i] = new CDLL();
	
	
    while (getline(file, satir)) { //satir satir al
		std::stringstream ss(satir); //diziyi ss e at
       
	    while(getline(ss, kelime, ' ')){ //satiri boşluğa göre parçala kelimeye at
			sayilar[say]->bul(stoi(kelime)); //kelimeyi int'e çevir sayilar[say] add fonksiyonuna gönder
		}
		
		say++;
	}
	
	file.close();//dosya kapa
	
	system("CLS");
	for(int i=0;i<satirsayi;i++)
	cout<<*sayilar[i]<<endl;//ekrana yazdır
	cin.get();

	for(int i=0;i<satirsayi;i++){ //liste içeriklerini temizle
		sayilar[i]->clear();
		delete sayilar[i];
	}
	
	delete sayilar; //liste sil
	
}