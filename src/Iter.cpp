/**
* @file Iter.cpp
* @description Iterator sınıfı liste yani düğümler üzerinde gezinen sınıf
* @course 1/A
* @assignment 1. Ödev
* @date 26.07.2020
* @author Ahmet Mücahit Gürer
*/


#include "Iter.hpp"
#include <iostream>
using namespace std;

		Iter::Iter(Dugum* dugum=NULL) //yapici metod eğer dügüm gonderilmezse null ata 
		{                              //fakat düğüm göndermezsem null atamıyor. Hocaya sor?
			suanki=dugum; //şu düğüm üzerinde gezinmeye başla.
		}
		
		bool Iter::sonmu(){
			return suanki == NULL; // suanki=NULL ise true değilse false döndür
		}
		void Iter::sonraki(){ // bi sonraki düğüme geç yani suanki düğüm bi ileri düğümü göstersin
			if(!sonmu())
			suanki = suanki->ileri;
		}
		void Iter::onceki(){ // bi önceki düğüme geç yani suanki düğüm bi geri düğümü göstersin
			if(!sonmu())
			suanki = suanki->geri;
		}
		const int& Iter::suankiveriyigoster()const{
			return suanki->veri;
		}