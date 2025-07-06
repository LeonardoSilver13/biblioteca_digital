// Biblioteca.cpp
#include "Biblioteca.h"
#include <iostream>
#include <fstream>

// Constructor
Biblioteca::Biblioteca() {}

// Destructor
Biblioteca::~Biblioteca() {
    for (Libro* l : libros) delete l;
    for (Usuario* u : usuarios) delete u;
    for (Prestamo* p : prestamos) delete p;
}

// Agregar
void Biblioteca::agregarLibro(Libro* libro) {
    libros.push_back(libro);
}

void Biblioteca::agregarUsuario(Usuario* usuario) {
    usuarios.push_back(usuario);
}

// Buscar
Libro* Biblioteca::buscarLibroPorISBN(const std::string& isbn) {
    for (Libro* l : libros)
        if (l->getISBN() == isbn)
            return l;
    return nullptr;
}

Usuario* Biblioteca::buscarUsuarioPorID(const std::string& id) {
    for (Usuario* u : usuarios)
        if (u->getID() == id)
            return u;
    return nullptr;
}

// Registrar préstamo
void Biblioteca::registrarPrestamo(const std::string& isbn, const std::string& idUsuario, const std::string& fecha) {
    Libro* libro = buscarLibroPorISBN(isbn);
    Usuario* usuario = buscarUsuarioPorID(idUsuario);
    if (libro && usuario && libro->getCopiasDisponibles() > 0) {
        libro->prestar();
        prestamos.push_back(new Prestamo(libro, usuario, fecha));
        std::cout << "? Préstamo registrado correctamente.\n";
    } else {
        std::cout << "? No se puede realizar el préstamo. Verifique disponibilidad o existencia.\n";
    }
}

// Devolver
void Biblioteca::devolverLibro(const std::string& isbn) {
    Libro* libro = buscarLibroPorISBN(isbn);
    if (libro) {
        libro->devolver();
        std::cout << "? Libro devuelto correctamente.\n";
    } else {
        std::cout << "? No se encontró el libro.\n";
    }
}

// Mostrar
void Biblioteca::mostrarLibros() const {
    std::cout << "?? Lista de libros:\n";
    for (Libro* l : libros)
        l->mostrarInformacion();
}

void Biblioteca::mostrarUsuarios() const {
    std::cout << "?? Lista de usuarios:\n";
    for (Usuario* u : usuarios)
        u->mostrarInformacion();
}

void Biblioteca::mostrarPrestamos() const {
    std::cout << "?? Lista de préstamos:\n";
    for (Prestamo* p : prestamos)
        p->mostrarInformacion();
}

// Archivo (implementaremos luego)
void Biblioteca::cargarDatos() {
    // Pendiente de implementar
}

void Biblioteca::guardarDatos() {
    // Pendiente de implementar
}
