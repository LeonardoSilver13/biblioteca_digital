// Libro.cpp
#include "Libro.h"
#include <iostream>

using namespace std;

// Constructor
Libro::Libro(string titulo, string autor, string isbn, int anio, int copias)
    : titulo(titulo), autor(autor), isbn(isbn), anio(anio), copiasTotales(copias), copiasDisponibles(copias) {}

// Getters
string Libro::getTitulo() const { return titulo; }
string Libro::getAutor() const { return autor; }
string Libro::getISBN() const { return isbn; }
int Libro::getAnio() const { return anio; }
int Libro::getCopiasTotales() const { return copiasTotales; }
int Libro::getCopiasDisponibles() const { return copiasDisponibles; }

// Métodos
void Libro::prestar() {
    if (copiasDisponibles > 0)
        copiasDisponibles--;
}

void Libro::devolver() {
    if (copiasDisponibles < copiasTotales)
        copiasDisponibles++;
}

void Libro::mostrarInformacion() const {
    cout << "Título: " << titulo << "\n"
         << "Autor: " << autor << "\n"
         << "ISBN: " << isbn << "\n"
         << "Año: " << anio << "\n"
         << "Copias disponibles: " << copiasDisponibles << " / " << copiasTotales << "\n";
}
