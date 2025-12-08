#include <iostream>
#include <string>
using namespace std;

// Estructura para guardar datos de un usuario
struct Usuario {
    int id;
    string nombre;
    string correo;
    string contrasena;
};

// Estructura para guardar datos de una noticia
struct Noticia {
    int codigo;
    string titulo;
    string autor;
    string contenido;
    int anio;
};

// Funcion para registrar un usuario
void registrarUsuario(Usuario usuarios[], int &cantidadUsuarios) {
    cout << "\n--- Registro de Usuario ---\n";
    cout << "Ingrese ID del usuario: ";
    cin >> usuarios[cantidadUsuarios].id;
    cin.ignore();

    cout << "Ingrese nombre del usuario: ";
    getline(cin, usuarios[cantidadUsuarios].nombre);

    cout << "Ingrese correo del usuario: ";
    getline(cin, usuarios[cantidadUsuarios].correo);

    cout << "Ingrese contrasena del usuario: ";
    getline(cin, usuarios[cantidadUsuarios].contrasena);

    cout << "\nUsuario registrado exitosamente: " << usuarios[cantidadUsuarios].nombre << "\n";
    cantidadUsuarios++;
}

// Funcion para registrar una noticia
void registrarNoticia(Noticia noticias[], int &cantidadNoticias) {
    cout << "\n--- Registro de Noticia ---\n";
    cout << "Ingrese codigo de la noticia: ";
    cin >> noticias[cantidadNoticias].codigo;

    cout << "Ingrese anio de publicacion: ";
    cin >> noticias[cantidadNoticias].anio;
    cin.ignore();

    cout << "Ingrese titulo de la noticia: ";
    getline(cin, noticias[cantidadNoticias].titulo);

    cout << "Ingrese autor de la noticia: ";
    getline(cin, noticias[cantidadNoticias].autor);

    cout << "Ingrese contenido de la noticia: ";
    getline(cin, noticias[cantidadNoticias].contenido);

    cout << "\nNoticia registrada exitosamente: " << noticias[cantidadNoticias].titulo << "\n";
    cantidadNoticias++;
}

// Funcion para listar las noticias registradas
void listarNoticias(Noticia noticias[], int cantidadNoticias) {
    cout << "\n--- Listado de Noticias ---\n";
    if (cantidadNoticias == 0) {
        cout << "No hay noticias registradas.\n";
    } else {
        for (int i = 0; i < cantidadNoticias; i++) {
            cout << "Titulo: " << noticias[i].titulo
                 << " | Codigo: " << noticias[i].codigo
                 << " | Anio: " << noticias[i].anio
                 << " | Autor: " << noticias[i].autor
                 << "\nContenido: " << noticias[i].contenido << "\n\n";
        }
    }
}

// Funcion para buscar una noticia por codigo
string buscarNoticia(Noticia noticias[], int codigo, int cantidadNoticias) {
    for (int i = 0; i < cantidadNoticias; i++) {
        if (noticias[i].codigo == codigo) {
            return noticias[i].titulo;
        }
    }
    return "No encontrada";
}

int main() {
    Usuario usuarios[20];
    Noticia noticias[20];
    int cantidadUsuarios = 0, cantidadNoticias = 0;
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n=== PORTAL WEB DE NOTICIAS ===\n";
        cout << "1. Registrar Usuario\n";
        cout << "2. Registrar Noticia\n";
        cout << "3. Listar Noticias\n";
        cout << "4. Buscar Noticia\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarUsuario(usuarios, cantidadUsuarios);
                break;
            case 2:
                registrarNoticia(noticias, cantidadNoticias);
                break;
            case 3:
                listarNoticias(noticias, cantidadNoticias);
                break;
            case 4: {
                int codigoBuscar;
                cout << "Ingrese codigo de la noticia a buscar: ";
                cin >> codigoBuscar;
                cout << "Resultado: " << buscarNoticia(noticias, codigoBuscar, cantidadNoticias) << "\n";
                break;
            }
            case 0:
                cout << "Saliendo del portal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }

    return 0;
}
