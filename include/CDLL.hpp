//Çift yönlü dairesel bağlı lsite sınıfı
#ifndef CDLL_HPP
#define CDLL_HPP
#include "Iter.hpp"
using namespace std;
#include<iostream>
class CDLL{
	private:
		Dugum *basDugum; // içinde eleman olmayan sadece listenin başını tutan düğüm.
		Dugum *temp;
		int size=0;
		int hata;
		int obeb=0;
		int gecici=0;
		int mod=0;
		int index=0;
		int gobeb=0;
		
		int OBEB(int, int);
		Iter oncekidugumbul(int);	
		Iter ilkdugum();
		/// Listenin ilk düğümünü döndürür
		
		
		
	public:
		CDLL(); //kurucu
		bool bosmu() const;
		int Count() const;
		/// Listenin ilk elemanını döndürür
		const int& ilkveri();
		/// Listenin son elemanını döndürür
		const int& sonveri();
		
		
		/// Liste İndis Bulma
		void bul(const int&);
		// Eleman Ekleme
		void ekle(int,const int&);
			
		// Liste Yazdırma	
		friend ostream& operator<<(ostream&, CDLL&);
		
		
		// Liste temizleme
		void clear();
		
		~CDLL();//yıkıcı
		
};
#endif