#include "klass.h"
#include "elev.h"
//Fick error h�r n�r jag f�rs�kte skapa en ny vector det var f�r att jag hade d�pt det man stoppade in i funktionen till samma som typen,

void klass::addtoo(elev elev) {
	elever.push_back(elev);
	std::cout << "Du la till " << elev.namn << " till klassen " << namn << "\n";
}
void klass::seestudent() {
	for (int i = 0; i < elever.size(); i++) {
		std::cout << "Elev: " << elever[i].namn << " �lder: " << elever[i].age << "\n";
	}
	std::cout << "Totalt: " << elever.size() << " Elever\n";
}
void klass::removefrome(elev eleven) {
	std::vector<elev> nyElever;
	for (int i = 0; i < elever.size(); i++) {
		if (elever[i].namn != eleven.namn) {
			nyElever.push_back(elever[i]);
		}
	}
	elever = nyElever;
	std::cout << "Du tog bort eleven " << eleven.namn << " fr�n klassen " << namn << "\n";
}