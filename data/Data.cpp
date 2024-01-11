#include "Data.h"


Data::Data(int d, int m, int r) : m_nDzien(d), m_nMiesiac(m), m_nRok(r) {
	this->Koryguj();
}


void Data::Koryguj() {
	if (this->m_nDzien <= 0) this->m_nDzien = 1;

	if (this->m_nMiesiac <= 0) this->m_nMiesiac = 1;

	if (this->m_nMiesiac > 12) this->m_nMiesiac = 12;

	if (this->m_nRok < 0) this->m_nRok = 0;


	if (this->m_nMiesiac == 2 && this->m_nDzien >= 28) {
		if (this->m_nRok % 4 == 0) {
			this->m_nDzien = 29;
		}
		else {
			this->m_nDzien = 28;
		}
		return;
	}

	if (this->m_nDzien > 30 && (this->m_nMiesiac % 2 == 0  && this->m_nMiesiac < 7 )) {
		this->m_nDzien = 30;
		return;
	}

	if ( this->m_nDzien > 31 && (this->m_nMiesiac % 2 != 0 && this->m_nMiesiac < 7)) {
		this->m_nDzien = 31;
		return;
	}


	if (this->m_nMiesiac == 7 || this->m_nMiesiac == 8) {
		this->m_nDzien = 31;
		return;
	}

	if ((this->m_nMiesiac % 2 == 0) && this->m_nDzien > 30) {
		this->m_nDzien = 31;
		return;
	}

	if ((this->m_nMiesiac % 2 != 0) && this->m_nDzien > 31) {
		this->m_nDzien = 30;
		return;
	}
}



void Data::Ustaw(int d, int m, int r) {
	this->m_nDzien = d;
	this->m_nMiesiac = m;
	this->m_nRok = r;
	this->Koryguj();
}


void Data::Wypisz() const {
	std::cout << this->m_nDzien << '-' << this->m_nMiesiac << '-' << this->m_nRok;
}


void Data::Wpisz() {
	int d, m, r;
	std::cout << "Podaj dzien: ";
	std::cin >> d;

	std::cout << "Podaj miesiac: ";
	std::cin >> m;

	std::cout << "Podaj rok: ";
	std::cin >> r;

	this->Ustaw(d, m, r);
}


int Data::Porownaj(const Data& wzor) const {
	if (this->m_nDzien == wzor.m_nDzien && this->m_nMiesiac == wzor.m_nMiesiac && this->m_nRok == wzor.m_nRok) {
		return 0;
	}

	if (wzor.m_nRok > this->m_nRok) return 1;

	if (wzor.m_nRok < this->m_nRok) return -1;


	if (wzor.m_nDzien > this->m_nDzien && wzor.m_nMiesiac >= this->m_nMiesiac) {
		return 1;
	}

	if (wzor.m_nDzien <= this->m_nDzien && wzor.m_nMiesiac > this->m_nMiesiac) {
		return 1;
	}

	return -1;
}


int Data::Dzien() const {
	return this->m_nDzien;
}


int Data::Miesiac() const {
	return this->m_nMiesiac;
}


int Data::Rok() const {
	return this->m_nRok;
}

std::ostream& operator<<(std::ostream& wy, const Data& d) {
	wy << d.m_nDzien << '-' << d.m_nMiesiac << '-' << d.m_nRok;
	return wy;
}

std::istream& operator>>(std::istream& we, Data& d) {
	we >> d.m_nDzien;
	we >> d.m_nMiesiac;
	we >> d.m_nRok;
	return we;
}
