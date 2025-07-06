// Biblioteca.cpp
#include "Biblioteca.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

// Guardar 
void Biblioteca::guardarDatos() {
    std::ofstream archivoLibros("libros.txt");

    for (Libro* l : libros) {
        archivoLibros << l->getTitulo() << "," << l->getAutor() << "," << l->getISBN()
                      << "," << l->getAnio() << "," << l->getCopiasTotales() << ","
                      << l->getCopiasDisponibles() << "\n";
    }

    archivoLibros.close();
    std::cout << "? Libros guardados en libros.txt\n";
}

//Cargar
void Biblioteca::cargarDatos() {
    std::ifstream archivoLibros("libros.txt");
    std::string linea;

    while (getline(archivoLibros, linea)) {
        std::stringstream ss(linea);
        std::string titulo, autor, isbn, anioStr, copiasTotalesStr, copiasDisponiblesStr;

        getline(ss, titulo, ',');
        getline(ss, autor, ',');
        getline(ss, isbn, ',');
        getline(ss, anioStr, ',');
        getline(ss, copiasTotalesStr, ',');
        getline(ss, copiasDisponiblesStr, ',');

        int anio = std::stoi(anioStr);
        int copiasTotales = std::stoi(copiasTotalesStr);
        int copiasDisponibles = std::stoi(copiasDisponiblesStr);

        Libro* libro = new Libro(titulo, autor, isbn, anio, copiasTotales);
        for (int i = 0; i < (copiasTotales - copiasDisponibles); ++i) {
            libro->prestar();
        }

        agregarLibro(libro);
    }

    archivoLibros.close();
    std::cout << "?? Libros cargados desde libros.txt\n";
}
