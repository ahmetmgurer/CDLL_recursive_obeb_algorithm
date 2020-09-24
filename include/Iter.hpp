//Iterator sınıfı liste yani düğümler üzerinde gezinen sınıf
#ifndef ITER_HPP
#define ITER_HPP
#include "Node.hpp"
class Iter{
	public:
		Dugum* suanki; // listedeki o an ki konumu ifade edecek olan pointer.
		Iter(Dugum*); //yapici
		bool sonmu(); //listenin sonunda old. söyleyecek fonk
		void sonraki(); //sonrakine gececek metod
		void onceki(); // öncekine gececek metod
		const int& suankiveriyigoster() const; //oldugum konumdaki veriyi dondurecek fonk
};
#endif