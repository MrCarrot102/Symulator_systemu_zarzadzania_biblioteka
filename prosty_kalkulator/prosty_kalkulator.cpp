#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Ksiazka {
private:
    std::string tytul;
    std::string autor;
    std::string ISBN;
    bool wypozyczona;

public:
    Ksiazka(const std::string& tytul, const std::string& autor, const std::string& ISBN)
        : tytul(tytul), autor(autor), ISBN(ISBN), wypozyczona(false) {}

    std::string getTytul() const { return tytul; }
    std::string getAutor() const { return autor; }
    std::string getISBN() const { return ISBN; }
    bool isWypozyczona() const { return wypozyczona; }

    void wypozycz() { wypozyczona = true; }
    void zwroc() { wypozyczona = false; }

    void printInfo() const {
        std::cout << "Tytul: " << tytul << ", Autor: " << autor << ", ISBN: " << ISBN << ", Wypozyczona: " << (wypozyczona ? "Tak" : "Nie") << std::endl;
    }
};

class Czytelnik {
private:
    std::string imie;
    std::string nazwisko;
    std::string numerKarty;

public:
    Czytelnik(const std::string& imie, const std::string& nazwisko, const std::string& numerKarty)
        : imie(imie), nazwisko(nazwisko), numerKarty(numerKarty) {}

    std::string getImie() const { return imie; }
    std::string getNazwisko() const { return nazwisko; }
    std::string getNumerKarty() const { return numerKarty; }

    void printInfo() const {
        std::cout << "Imie: " << imie << ", Nazwisko: " << nazwisko << ", Numer Karty: " << numerKarty << std::endl;
    }
};

class Biblioteka {
private:
    std::vector<Ksiazka> ksiazki;
    std::vector<Czytelnik> czytelnicy;

public:
    void dodajKsiazke(const Ksiazka& ksiazka) {
        ksiazki.push_back(ksiazka);
    }

    void dodajCzytelnika(const Czytelnik& czytelnik) {
        czytelnicy.push_back(czytelnik);
    }

    void wypozyczKsiazke(const std::string& ISBN, const std::string& numerKarty) {
        auto ksiazka = std::find_if(ksiazki.begin(), ksiazki.end(), [&ISBN](const Ksiazka& k) { return k.getISBN() == ISBN; });
        if (ksiazka != ksiazki.end() && !ksiazka->isWypozyczona()) {
            ksiazka->wypozycz();
            std::cout << "Ksiazka " << ksiazka->getTytul() << " zostala wypozyczona." << std::endl;
        }
        else {
            std::cout << "Ksiazka nie jest dostepna do wypozyczenia." << std::endl;
        }
    }

    void zwrocKsiazke(const std::string& ISBN) {
        auto ksiazka = std::find_if(ksiazki.begin(), ksiazki.end(), [&ISBN](const Ksiazka& k) { return k.getISBN() == ISBN; });
        if (ksiazka != ksiazki.end() && ksiazka->isWypozyczona()) {
            ksiazka->zwroc();
            std::cout << "Ksiazka " << ksiazka->getTytul() << " zostala zwrocona." << std::endl;
        }
        else {
            std::cout << "Ksiazka nie jest wypozyczona." << std::endl;
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

int main() {
    Biblioteka biblioteka;

    Ksiazka ks1("Pan Tadeusz", "Adam Mickiewicz", "123-456-789");
    Ksiazka ks2("Lalka", "Boleslaw Prus", "987-654-321");

    Czytelnik czyt1("Jan", "Kowalski", "C001");
    Czytelnik czyt2("Anna", "Nowak", "C002");

    biblioteka.dodajKsiazke(ks1);
    biblioteka.dodajKsiazke(ks2);

    biblioteka.dodajCzytelnika(czyt1);
    biblioteka.dodajCzytelnika(czyt2);

    std::cout << "Dostepne ksiazki:" << std::endl;
    biblioteka.printKsiazki();

    std::cout << "Czytelnicy:" << std::endl;
    biblioteka.printCzytelnicy();

    biblioteka.wypozyczKsiazke("123-456-789", "C001");
    biblioteka.zwrocKsiazke("123-456-789");

    return 0;
}
