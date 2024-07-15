#include <iostream> 
#include <string>
#include <vector> 
#include <unordered_map>

class Ksiazka {
private:
	std::string tytul;
	std::string autor;
	std::string ISBN;

public:
	Ksiazka(const std::string& tytul, const std::string& autor, const std::string& ISBN)
		:tytul(tytul), autor(autor), ISBN(ISBN) {}
	
	std::string getTytul() const {
		return tytul;
	}
	std::string getAutor() const {
		return autor;
	}
	std::string getISBN() const {
		return ISBN;
	}

	void printInfo() const {
		std::cout << tytul << " " << autor << " " << ISBN << "\n";
	}
};

class Czytelnik {
private:
	std::string imie;
	std::string nazwisko;
	std::string numerKarty;

public:
	Czytelnik(const std::string& imie, const std::string& nazwisko, const std::string& numerKarty)
		:imie(imie), nazwisko(nazwisko), numerKarty(numerKarty) {}

	std::string getImie() const {
		return imie;
	}
	std::string getNazwisko() const {
		return nazwisko;
	}
	std::string getNumerKarty() const {
		return numerKarty;
	}

	void printInfo() const {
		std::cout << imie << " " << nazwisko << " " << numerKarty << "\n";
	}
};

class Biblioteka {
private: 
	std::vector<Ksiazka> ksiazki;
	std::vector<Czytelnik> czytelnicy;
	std::unordered_map<std::string, std::string> wypozyczenia;

public:
	void dodajKsiazke(const Ksiazka& ksiazka) {
		ksiazki.push_back(ksiazka);
	}
	void dodajCzytelnika(const Czytelnik& czytelnik) {
		czytelnicy.push_back(czytelnik);
	}
	void wypozyczKsiazke(const std::string& ISBN, const std::string& numerKarty) {
		for (const auto& ksiazka : ksiazki) {
			if (ksiazka.getISBN() == ISBN) {
				wypozyczenia[ISBN] = numerKarty;
				std::cout << "Ksiazka wypozyczona: " << ksiazka.getTytul() << " dla karty: " << numerKarty << "\n";
				return;
			}
		}
		std::cout << "Ksiazka o podanym ISBN nie zostala znaleziona.\n";
	}

	void zwrocKsiazke(const std::string& ISBN) {
		if (wypozyczenia.erase(ISBN)) {
			std::cout << "Ksiazka o ISBN: " << ISBN << " zostala zwrocona\n";
		}
		else {
			std::cout << "Ksiazka o podanym ISBN nie jest wypozyczona.\n";
		}
	}

	void printKsiazki() const {
		for (const auto& ksiazka : ksiazki) {
			ksiazka.printInfo();
		}
	}

	void printCzytelnicy() const {
		for (const auto& czytelnik : czytelnicy) {
			czytelnik.printInfo();
		}
	}
};

