#include "schoolsystem.h"

void schoolsystem::start() {
	bool inloggad = false;
	std::cout << "Välkommen till skolsystem\n";
	std::string input;
	for (int i = 0; i < 3; i++) {
		std::cout << "Skriv användernamnet för att logga in\n";
		std::cin >> input;
		if (input == "abd") {
			std::cout << "Skriv nu lösenordet!\n";
			std::string lösen;
			std::cin >> lösen;
			if (lösen == "abd") {
				inloggad = true;
				break;
			}
		}
	}
	if (inloggad == true) {
		bool kör = true;
		std::cout << "Du är nu inloggad!\n";
		while (kör) {
			std::string namn;
			std::string klass;
			int ålder;
			std::cout << "1. Lägg till Elev\n2. Ta bort Elev från system\n3. Byt klass på Elev/Lägg till elev i klass\n4. Ta bort Elev från sin klass\n5. Information om klass\n6. Information om Elev\n7. Skapa klass\n8. Kolla om en Elev finns\n9. Stäng av\n";
			char val;
			std::cin >> val;
			switch (val) {
			case '1':
				std::cout << "Skriv namnet på din elev\n";
				std::cin >> namn;
				std::cout << "Skriv åldern på din elev\n";
				std::cin >> ålder;
				Add(namn, ålder);
				break;
			case '2':
				std::cout << "Skriv namnet på din elev\n";
				std::cin >> namn;
				removee(namn);
				break;
			case '3':
				std::cout << "Skriv namnet på din elev\n";
				std::cin >> namn;
				std::cout << "Skriv namnet på den nya klassen\n";
				std::cin >> klass;
				changeclass(namn, klass);
				break;
			case '4':
				std::cout << "Skriv namnet på din elev\n";
				std::cin >> namn;
				removestudentclass(namn);
				break;
			case '5':
				std::cout << "Skriv klassens namn\n";
				std::cin >> klass;
				classinfo(klass);
				break;
			case '6':
				std::cout << "Skriv elevens namn\n";
				std::cin >> namn;
				infostudentt(namn);
				break;
			case '7':
				std::cout << "Skriv klassens namn\n";
				std::cin >> klass;
				createclass(klass);
				break;
			case '8':
				std::cout << "Skriv elevens namn\n";
				std::cin >> namn;
				if (serchstudent(namn)) {
					std::cout << "Eleven finns!\n";
				}
				else {
					std::cout << "Eleven finns inte!\n";
				}
				break;
			case '9':
				kör = false;
				break;
			}
		}
	}
}

void schoolsystem::Add(std::string nam, int age) {
	elev student(nam, age);
	elever.push_back(student);
	std::cout << "Du la till eleven " << nam << "\n";
}
void schoolsystem::removee(std::string namn) {
	std::vector<elev> nyaelever;
	for (int i = 0; i < elever.size(); i++) {
		if (elever[i].namn != namn) {
			nyaelever.push_back(elever[i]);
		}
	}
	elever = nyaelever;
	std::cout << "Du tog bort eleven " << namn << "\n";
}
bool schoolsystem::serchstudent(std::string namn) {
	for (int i = 0; i < elever.size(); i++) {
		if (elever[i].namn == namn) {
			return true;
		}
	}
	return false;
}
void schoolsystem::infostudentt(std::string namn) {
	std::string klass = "Ingen klass";
	for (int i = 0; i < klasser.size(); i++) {
		for (int l = 0; l < klasser[i].elever.size(); l++) {
			if (klasser[i].elever[l].namn == namn) {
				klass = klasser[i].namn;
			}
		}
	}
	for (int i = 0; i < elever.size(); i++) {
		if (elever[i].namn == namn) {
			std::cout << "Elev: " << elever[i].namn << ", Klass: " << klass << ", Ålder: " << elever[i].age << "\n";
			return;
		}
	}
	std::cout << "Eleven finns inte!\n";
}
void schoolsystem::changeclass(std::string namn, std::string klassNamn) {
	bool lyckades = false;
	for (int i = 0; i < klasser.size(); i++) {
		for (int l = 0; l < klasser[i].elever.size(); l++) {
			if (klasser[i].elever[l].namn == namn) {
				klasser[i].removefrome(elever[l]);
			}
		}
		if (klasser[i].namn == klassNamn) {
			for (int l = 0; l < elever.size(); l++) {
				if (elever[l].namn == namn) {
					klasser[i].addtoo(elever[l]);
					lyckades = true;
				}
			}
		}
	}
	if (lyckades) {
		std::cout << "Eleven bytte klass till " << klassNamn << "\n";
	}
	if (lyckades == false) {
		std::cout << "Det fanns ingen klass som hette " << klassNamn << "\n";
	}
}
void schoolsystem::removestudentclass(std::string namn) {
	for (int i = 0; i < klasser.size(); i++) {
		for (int l = 0; l < klasser[i].elever.size(); l++) {
			if (klasser[i].elever[l].namn == namn) {
				klasser[i].removefrome(klasser[i].elever[l]);
			}
		}
	}
}
void schoolsystem::classinfo(std::string klass) {
	for (int i = 0; i < klasser.size(); i++) {
		if (klasser[i].namn == klass) {
			klasser[i].seestudent();
		}
	}
}
void schoolsystem::createclass(std::string namn) {
	klass klass;
	klass.namn = namn;
	klasser.push_back(klass);
	std::cout << "Du skapade klassen " << namn << "\n";
}