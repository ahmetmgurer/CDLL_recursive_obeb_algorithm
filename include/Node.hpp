//d���m s�n�f�
#ifndef NODE_H
#define NODE_H
class Dugum{
	public:	
		int veri; //veriyi tutacak eleman;
		Dugum* ileri; //sonraki d���m�n adresi
		Dugum* geri; //�nceki d���m�n adresi
		Dugum(); //YAPICI PARAMETRESIZ
		Dugum(const int&,Dugum*,Dugum*); //YAPICI PARAMETRELI 
};
#endif