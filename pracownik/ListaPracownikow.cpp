#include "ListaPracownikow.h"


void ListaPracownikow::Dodaj(const Pracownik& p) {
    if (this->Szukaj(p.Nazwisko(), p.Imie()) != nullptr) {
        return;
    }

    Pracownik* newPracownik = new Pracownik(p);
    Pracownik* current = m_pPoczatek;
    Pracownik* previous = nullptr;

    while (current != nullptr && current->Porownaj(*newPracownik) < 0) {
        previous = current;
        current = current->m_pNastepny;
    }

    if (previous == nullptr) {
        Pracownik* save = m_pPoczatek;
        m_pPoczatek = newPracownik;
        m_pPoczatek->m_pNastepny = save;
    }
    else {
        Pracownik* save = previous->m_pNastepny;
        previous->m_pNastepny = newPracownik;
        newPracownik->m_pNastepny = save;
    }

    m_nLiczbaPracownikow++;
}


void ListaPracownikow::Usun(const Pracownik& wzorzec) {
    if (this->Szukaj(wzorzec.Nazwisko(), wzorzec.Imie()) == nullptr) {
        return;
    }

    Pracownik* current = m_pPoczatek;
    Pracownik* previous = nullptr;

    
    while (current != nullptr && current->Porownaj(wzorzec) != 0) {
        previous = current;
        current = current->m_pNastepny;
    }

    if (previous != nullptr && current != nullptr) {
        previous->m_pNastepny = current->m_pNastepny;
        delete current;
        m_nLiczbaPracownikow--;
    }
}


ListaPracownikow::ListaPracownikow() {
  this->m_nLiczbaPracownikow = 0;
  this->m_pPoczatek = nullptr;
}


ListaPracownikow::~ListaPracownikow() {
  if (m_pPoczatek == nullptr) return;

  Pracownik* next = m_pPoczatek;
  Pracownik* temp = nullptr;

  while (next != nullptr) {
    temp = next;
    next = next->m_pNastepny;
    delete temp;
  }
}


void ListaPracownikow::WypiszPracownikow() const {
	Pracownik* p = this->m_pPoczatek;
	while (p != nullptr) {
		p->Wypisz();
		p = p->m_pNastepny;
	}
}


const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) {
	Pracownik* p = this->m_pPoczatek;
	while (p != nullptr) {
		int checkImie = p->SprawdzImie(imie);
		int checkNazwisko = p->SprawdzNazwisko(nazwisko);

		if ((checkImie == 0) && (checkNazwisko == 0)) {
			return p;
		}
      p = p->m_pNastepny;
	}
	return nullptr;
}

void ListaPracownikow::WyswietlMenu() {
   std::cout << "Menu:\n";
   std::cout << "a) Dodaj pracownika\n";
   std::cout << "b) Usun pracownika\n";
   std::cout << "c) Wypisz liste pracownikow\n";
   std::cout << "d) Znajdz pracownika po nazwisku i imieniu\n";
   std::cout << "q) Zakoncz program\n";
}

void ListaPracownikow::InterfejsDoListy() {
   ListaPracownikow lista;
   char opcja;

   do {
       WyswietlMenu();
       std::cout << "Wybierz opcje: ";
       std::cin >> opcja;
       switch (opcja) {
           case 'a': {
               Pracownik nowyPracownik;
               nowyPracownik.Wpisz();
               lista.Dodaj(nowyPracownik);
               break;
           }
           case 'b': {
               Pracownik wzorzec;
               wzorzec.Wpisz();
               lista.Usun(wzorzec);
               break;
           }
           case 'c':
               lista.WypiszPracownikow();
               break;
           case 'd': {
               char nazwisko[40], imie[40];
               std::cout << "Podaj nazwisko: ";
               std::cin >> nazwisko;
               std::cout << "Podaj imie: ";
               std::cin >> imie;

               const Pracownik* znaleziony = lista.Szukaj(nazwisko, imie);

               if (znaleziony != nullptr) {
                   std::cout << "Znaleziono pracownika:\n";
                   znaleziony->Wypisz();
               } else {
                   std::cout << "Pracownik nie znaleziony.\n";
               }

               break;
           }
           case 'q':
               std::cout << "Koniec programu.\n";
               break;
           default:
               std::cout << "Niepoprawna opcja.\n";
       }

   } while (opcja != 'q');
}

void ListaPracownikow::ZapiszDoPliku(const char* filename) {
    std::ofstream outputFile(filename, std::ios::out);

    if (!outputFile.is_open()) {
      std::cerr << "Failed to open the file. Probably wrong file name" << std::endl;
      std::exit(1);
    }

    Pracownik* current = m_pPoczatek;
    while (current != nullptr) {
      outputFile << (*current) << std::endl;
      current = current->m_pNastepny;
    }
    outputFile.close();
}

void ListaPracownikow::OdczytajZPliku(const char* filename) {
    std::ifstream inputFile(filename, std::ios::in);

    if (!inputFile.is_open()) {
      std::cerr << "Failed to open the file. Probably wrong file name" << std::endl;
      std::exit(1);
    }

    std::string linia;
    while (std::getline(inputFile, linia)) {
        std::cout << linia << std::endl;
    }

    inputFile.close();
}
