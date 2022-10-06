#include "klass.h"
#include "elev.h"
//Fick error här när jag försökte skapa en ny vector det var för att jag hade döpt det man stoppade in i funktionen till samma som typen,

void klass::addtoo(elev elev) {
	elever.push_back(elev);
	std::cout << "Du la till " << elev.namn << " till klassen " << namn << "\n";
}
void klass::seestudent() {
	for (int i = 0; i < elever.size(); i++) {
		std::cout << "Elev: " << elever[i].namn << " Ålder: " << elever[i].age << "\n";
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
	std::cout << "Du tog bort eleven " << eleven.namn << " från klassen " << namn << "\n";
}