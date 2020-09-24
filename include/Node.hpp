//düðüm sýnýfý
#ifndef NODE_H
#define NODE_H
class Dugum{
	public:	
		int veri; //veriyi tutacak eleman;
		Dugum* ileri; //sonraki düðümün adresi
		Dugum* geri; //önceki düðümün adresi
		Dugum(); //YAPICI PARAMETRESIZ
		Dugum(const int&,Dugum*,Dugum*); //YAPICI PARAMETRELI 
};
#endif