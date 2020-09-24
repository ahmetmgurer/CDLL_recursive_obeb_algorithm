/**
* @file Node.cpp
* @description D���mleri olu�turan nextini previni tutan s�n�f
* @course 1/A
* @assignment 1. �dev
* @date 26.07.2020
* @author Ahmet M�cahit G�rer
*/

//d���m s�n�f�
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

//�ki ayr� yap�c� tan�mlamam�n sebebi Dugum::Dugum(const int& veri,Dugum* ileri=NULL,Dugum* geri=NULL) olarak tan�mlad���mda 
//parametre vermesem bile parametre istiyor.