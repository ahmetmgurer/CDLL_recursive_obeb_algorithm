/**
* @file CDLL.cpp
* @description Çiftyönlü dairesel bağıl listenin oluşturulduğu ve gerekli algoritmalardan geçirdikten sonra ekleyen, yazdıran, silen sınıf
* @course 1/A
* @assignment 1. Ödev
* @date 26.07.2020
* @author Ahmet Mücahit Gürer
*/

#include "CDLL.hpp"
#include <iostream>
using namespace std;

		Iter CDLL::oncekidugumbul(int konum){
			if(!(konum < 0 || konum > Count())) //eğer verilen konum 0'dan küçükse veya konum liste boyutundan büyük DEĞİLSE
			{
				int index=0;
				Iter iter(basDugum);//Iter sinifinden iter nesnesi tanımla ve basduğum şuanki düğümü olsun
				while(!iter.sonmu() && konum != index++) //iter nesnesinin suanki düğüm boş değilse ve(&&) konum index'e eşit değilse
					iter.sonraki(); //sonraki düğüme geç
				return iter; //örneğim konum olarak 5 girdiysek geriye 4. düğümü döndürecek.
			}
			return NULL;
		}	

		int CDLL::OBEB(int a, int b){ //Rekürsif OBEB fonk
	    if(b==0) { return a; }
	    int k = a%b;
	    if (k==0) { return b; }
	    return OBEB(b,k); //gerçekleşene kadar obebi çağır.
		}
		
		
		/// Listenin ilk düğümünü döndürür
		Iter CDLL::ilkdugum(){
			if(!bosmu()) //eğer headin ilerisi ilk düğüm doluysa
				return Iter(basDugum->ileri); //ilk düğümü iter'e yola yani şuanki düğüm o olsun
			return NULL; // eğer boşsa yani true dönerse NULL döndürsün
		}
		
		
		CDLL::CDLL(){ //kurucu metod
			basDugum = new Dugum(); // Buraya bak boş olmuyor. Boş bir düğüm oluşturuluyor. parametre vermediğim için veri=-1, ileri=NULL, geri=NULL)
			size=0; //boyutu sifir olsun
		}
		bool CDLL::bosmu() const{
			return basDugum->ileri == NULL; // basdugumun ilerisi yani ilk eleman düğüm yani nullsa true dönsün
		}
		int CDLL::Count() const{ //bunu kullanma sebebimiz size private olduğu için.
			return size;
			
		}
		/// Listenin ilk elemanını döndürür
		const int& CDLL::ilkveri(){
			if(!bosmu())
				return basDugum->ileri->veri;
			return hata;
		}
		/// Listenin son elemanını döndürür
		const int& CDLL::sonveri() {
			if(!bosmu())
				return basDugum->ileri->geri->veri;
			return hata;
		}
		
		
		/// Liste İndis Bulma
		void CDLL::bul(const int& yeni){
			/*Iter iter; //hata veriyor illa parametre istiyor. hocaya sor
			iter=Iter(basDugum);*/
			Iter iter = Iter(basDugum);
			index=0;
			if (OBEB(yeni,gecici)>obeb && size!=0) obeb=OBEB(yeni,gecici);
			if (size != 0 && yeni != 0 && gecici != 0) gobeb=OBEB(yeni,gecici);
			if (size != 0 && yeni == 0 || gecici == 0) gobeb=0;
			
			while (gobeb < obeb && index!=Count())
			{
				iter.sonraki();
				gecici=iter.suankiveriyigoster();
				if (yeni != 0 && gecici != 0) gobeb=OBEB(yeni,gecici);
				if (yeni == 0 || gecici == 0) gobeb=0;
				index++;	
			}

			if (gecici>yeni && size!=0 && yeni!=0 && gecici!=0) mod=gecici%yeni;
			if (yeni>=gecici && size!=0 && yeni!=0 && gecici!=0) mod=yeni%gecici;
			if (yeni==0 || gecici==0) mod=0; 
			if (size == 0)
			{
				mod=0;
				obeb=0;
			}
			
			int say=0;
			while(mod!=say++ && index!=0){ //iter nesnesinin suanki düğüm boş değilse ve(&&) konum index'e eşit değilse
				iter.onceki(); //onceki düğüme geç
				index--;
			}
			
			ekle(index,yeni); //Elemani şu indise ekle.
			gecici=ilkveri();
			
		}
		// Eleman Ekleme
			void CDLL::ekle(int konum,const int& yeni){ //hangi indise ekleyeceksin neyi ekleyeceksin

			Iter iter2 = oncekidugumbul(konum);
			Dugum *newNext = iter2.suanki->ileri;
			iter2.suanki->ileri = new Dugum(yeni,newNext,iter2.suanki);
			if(newNext != NULL){
				Dugum *sonveri = newNext->geri;
				newNext->geri = iter2.suanki->ileri;
				if(konum == 0) basDugum->ileri->geri = sonveri;
			}
			if(size == 0) basDugum->ileri->ileri = basDugum->ileri->geri = basDugum->ileri;
			size++;			
		}
			
		// Liste Yazdırma	
		ostream& operator<<(ostream& screen, CDLL& right){
		char ascii;
			if(right.bosmu()) screen<<"Liste bos";
			else{
				int index=0;
				screen<<"Sifre: ";
				for(Iter iter = right.ilkdugum();index<right.size;iter.sonraki(),index++)
				{
					ascii=static_cast<char>(iter.suankiveriyigoster()); //sayisal degeri karaktere çevir.
					screen<<ascii;
				}
				screen<<endl;
			}
			return screen;
		}
		
		// Liste temizleme
		void CDLL::clear(){
			while(!bosmu())
			{
				Iter onceki = oncekidugumbul(0);;
				int konum=0;
				
				if(onceki.suanki->ileri != NULL){
					Dugum *eskiDugum = onceki.suanki->ileri;
					onceki.suanki->ileri = onceki.suanki->ileri->ileri;
					eskiDugum->ileri->geri = eskiDugum->geri;
					delete eskiDugum;
					if(konum == 0) basDugum->ileri->geri->ileri = basDugum->ileri;
					size--;
					if(size == 0) onceki.suanki->ileri = NULL;
				}
			}				
		} 
		
		CDLL::~CDLL(){ //yıkıcı metod
			clear();
			delete basDugum;
		} 
