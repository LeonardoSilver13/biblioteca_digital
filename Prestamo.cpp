// Prestamo.cpp
#include "Prestamo.h"
#include <iostream>

// Constructor
Prestamo::Prestamo(Libro* libro, Usuario* usuario, std::string fecha)
    : libroPrestado(libro), usuario(usuario), fechaPrestamo(fecha) {}

// Getters
Libro* Prestamo::getLibro() const { return libroPrestado; }
Usuario* Prestamo::getUsuario() const { return usuario; }
std::string Prestamo::getFechaPrestamo() const { return fechaPrestamo; }

// Muestra info
void Prestamo::mostrarInformacion() const {
    std::cout << " Libro prestado:\n";
    libroPrestado->mostrarInformacion();
    std::cout << " Usuario:\n";
    usuario->mostrarInformacion();
    std::cout << " Fecha de préstamo: " << fechaPrestamo << "\n";
}
