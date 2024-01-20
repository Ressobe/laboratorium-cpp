#include "ListaPracownikow.h"
#include "Kierownik.h"


void ListaPracownikow::Dodaj(const Pracownik& p) {
    if (this->Szukaj(p.Nazwisko(), p.Imie()) != nullptr) {
        return;
    }

    Pracownik* newPracownik = p.KopiaObiektu();
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
    }

    if (previous == nullptr && current != nullptr ) {
      m_pPoczatek = current->m_pNastepny;
      delete current;
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
		p->WypiszDane();
    std::cout << std::endl;
		p = p->m_pNastepny;
	}
  std::cout << std::endl;
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
   std::cout << std::endl;
   std::cout << "Lista pracownikow menu:" << std::endl;
   std::cout << "a) Dodaj pracownika" << std::endl;
   std::cout << "b) Usun pracownika" << std::endl;
   std::cout << "c) Wypisz liste pracownikow" << std::endl;
   std::cout << "d) Znajdz pracownika po nazwisku i imieniu" << std::endl;
   std::cout << "s) Zapisz liste pracownikow do pliku" << std::endl;
   std::cout << "r) Wczytaj liste pracownikow z pliku" << std::endl;
   std::cout << "q) Zakoncz program" << std::endl;
}


void ListaPracownikow::Interfejs() {
   char opcja, typPracownika;

   do {
       WyswietlMenu();
       std::cout << "\nWybierz opcje: ";
       std::cin >> opcja;

       #ifdef _WIN32
        std::system("cls");
       #else
        std::system("clear");
       #endif

       switch (opcja) {
           case 'a': {
               std::cout << "Wybierz typ pracownika. pracowika (p), kierownik (k): ";
               std::cin >> typPracownika;


               if (typPracownika == 'p') {
                 std::cin.ignore();
                 Pracownik nowyPracownik = Pracownik();
                 std::cin >> nowyPracownik;
                 this->Dodaj(nowyPracownik);
                 std::cout << "Pracownik zostal dodany" << std::endl;
               }

               if (typPracownika == 'k') {
                 std::cin.ignore();
                 Kierownik nowyKierownik = Kierownik();
                 std::cin >> nowyKierownik;
                 this->Dodaj(nowyKierownik);
                 std::cout << "Kierownik zostal dodany" << std::endl;
               }

               break;
           }
           case 'b': {
               std::cin.ignore();
               Pracownik wzorzec;
               std::cin >> wzorzec;
               this->Usun(wzorzec);
               std::cout << "Pracownik zostal usuniety" << std::endl;
               break;
           }
           case 'c':
               this->WypiszPracownikow();
               break;
           case 'd': {
               std::cin.ignore();
               char nazwisko[40], imie[40];
               std::cout << "Podaj nazwisko: ";
               std::cin >> nazwisko;
               std::cout << "Podaj imie: ";
               std::cin >> imie;

               const Pracownik* znaleziony = this->Szukaj(nazwisko, imie);

               if (znaleziony != nullptr) {
                   std::cout << "\nZnaleziono pracownika:" << std::endl;
                   std::cout << znaleziony;
               } else {
                   std::cout << "\nPracownik nie znaleziony." << std::endl;
               }

               break;
           }
           case 's':
                char save_file[40];
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> save_file;
                this->ZapiszDoPliku(save_file);
                break;
           case 'r':
                char read_file[40];
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> read_file;
                this->WczytajZPliku(read_file);
                break;
           case 'q':
               break;
           default:
               std::cout << "Niepoprawna opcja." << std::endl;
               break;
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
      if (Kierownik* kierownik = dynamic_cast<Kierownik*>(current)) {
         outputFile << (*kierownik) << std::endl;
      } else {
        outputFile << (*current) << std::endl;
      }
      current = current->m_pNastepny;
    }
    outputFile.close();
}

void ListaPracownikow::WczytajZPliku(const char* filename) {
    std::ifstream inputFile(filename, std::ios::in);

    if (!inputFile.is_open()) {
      std::cerr << "Failed to open the file. Probably wrong file name" << std::endl;
      std::exit(1);
    }

    char line[256];
    while (inputFile.getline(line, sizeof(line))) {

        char imie[50], nazwisko[50], nazwaDzialu[50];
        int dzien, miesiac, rok, liczbaPracownikow;

        int result = sscanf(line, "%49[^,],%49[^,],%d-%d-%d,%49[^,\n],%d", imie, nazwisko, &dzien, &miesiac, &rok, nazwaDzialu, &liczbaPracownikow);
        if (result == 5) {
            Pracownik* newPracownik = new Pracownik(imie, nazwisko, dzien, miesiac, rok);
            Dodaj(*newPracownik);
        } else if (result == 7) {
            Kierownik* newKierownik = new Kierownik(nazwaDzialu, liczbaPracownikow, imie, nazwisko, dzien, miesiac, rok);
            Dodaj(*newKierownik);
        } else {
            std::cerr << "Unknown format encountered in the file." << std::endl;
        }
    }
    inputFile.close();
}
