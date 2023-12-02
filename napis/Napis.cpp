#include "Napis.h"


Napis::Napis(const char* nap) {
    m_nDl = strlen(nap) + 1;
    m_pszNapis = new char[this->m_nDl];
    strcpy(m_pszNapis, nap);
}


Napis::~Napis() {
	delete[] m_pszNapis;
	m_pszNapis = nullptr;
}


Napis::Napis(const Napis& wzor) {
    m_nDl = strlen(wzor.Zwroc()) + 1;
    m_pszNapis = new char[m_nDl];
    strcpy(m_pszNapis, wzor.Zwroc());
}


Napis& Napis::operator=(const Napis& wzor) {
    if (this != &wzor) {
        delete[] this->m_pszNapis;
        this->m_nDl = strlen(wzor.Zwroc()) + 1;
        this->m_pszNapis = new char[this->m_nDl];
        strcpy(this->m_pszNapis, wzor.Zwroc());
    }

    return *this;
}

const char* Napis::Zwroc() const {
    return m_pszNapis;
}


void Napis::Ustaw(const char* nowy_napis) {
     delete[] m_pszNapis;
     m_nDl = strlen(nowy_napis) + 1;
     m_pszNapis = new char[m_nDl];
     strcpy(m_pszNapis, nowy_napis);
}


void Napis::Wypisz() const {
    std::cout << m_pszNapis;
}


void Napis::Wpisz() {
    delete[] m_pszNapis;
    const int maxBufferSize = 1000;

    char buffer[maxBufferSize];
    std::cin.getline(buffer, maxBufferSize);

    m_nDl = strlen(buffer) + 1;
    m_pszNapis = new char[m_nDl];
    strcpy(m_pszNapis, buffer);
}


int Napis::SprawdzNapis(const char* por_napis) const {
    return strcmp(m_pszNapis, por_napis);
}
