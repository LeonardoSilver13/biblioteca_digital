// main.cpp
#include <iostream>
#include <string>
#include "Biblioteca.h"

using namespace std;

void mostrarMenu() {
    cout << "\n===== Sistema de Gestión de Biblioteca Digital =====\n";
    cout << "1. Registrar libro\n";
    cout << "2. Registrar usuario\n";
    cout << "3. Prestar libro\n";
    cout << "4. Devolver libro\n";
    cout << "5. Mostrar libros\n";
    cout << "6. Mostrar usuarios\n";
    cout << "7. Mostrar préstamos\n";
    cout << "0. Salir\n";
    cout << "====================================================\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Biblioteca biblioteca;
    int opcion;
    string titulo, autor, isbn, id, correo, fecha;
    int anio, copias;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpia el salto

        switch (opcion) {
            case 1: {
                cout << "Título: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);
                cout << "ISBN: ";
                getline(cin, isbn);
                cout << "Año: ";
                cin >> anio;
                cout << "Número de copias: ";
                cin >> copias;
                cin.ignore();

                biblioteca.agregarLibro(new Libro(titulo, autor, isbn, anio, copias));
                cout << "? Libro registrado.\n";
                break;
            }

            case 2: {
                cout << "Nombre: ";
                getline(cin, titulo); // reutilizo la variable
                cout << "ID (DNI): ";
                getline(cin, id);
                cout << "Correo: ";
                getline(cin, correo);

                biblioteca.agregarUsuario(new Usuario(titulo, id, correo));
                cout << "? Usuario registrado.\n";
                break;
            }

            case 3: {
                cout << "ISBN del libro: ";
                getline(cin, isbn);
                cout << "ID del usuario: ";
                getline(cin, id);
                cout << "Fecha del préstamo (YYYY-MM-DD): ";
                getline(cin, fecha);

                biblioteca.registrarPrestamo(isbn, id, fecha);
                break;
            }

            case 4: {
                cout << "ISBN del libro a devolver: ";
                getline(cin, isbn);
                biblioteca.devolverLibro(isbn);
                break;
            }

            case 5:
                biblioteca.mostrarLibros();
                break;

            case 6:
                biblioteca.mostrarUsuarios();
                break;

            case 7:
                biblioteca.mostrarPrestamos();
                break;

            case 0:
                cout << "?? Saliendo del sistema. ¡Hasta luego!\n";
                break;

            default:
                cout << "? Opción no válida.\n";
        }

    } while (opcion != 0);

    return 0;
}
