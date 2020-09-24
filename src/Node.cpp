/**
* @file Node.cpp
* @description Düðümleri oluþturan nextini previni tutan sýnýf
* @course 1/A
* @assignment 1. Ödev
* @date 26.07.2020
* @author Ahmet Mücahit Gürer
*/

//düðüm sýnýfý
#include "Node.hpp"
#include <iostream>
using namespace std;

	Dugum::Dugum(){ //PARAMETRESIZ YAPICI
	ileri=NULL;
	geri=NULL;
	}
	
	Dugum::Dugum(const int& veri,Dugum* ileri,Dugum* geri){ //PARAMETRELI
	this->veri=veri;                                     
	this->ileri=ileri;
	this->geri=geri;
	}

//Ýki ayrý yapýcý tanýmlamamýn sebebi Dugum::Dugum(const int& veri,Dugum* ileri=NULL,Dugum* geri=NULL) olarak tanýmladýðýmda 
//parametre vermesem bile parametre istiyor.