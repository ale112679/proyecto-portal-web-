#include <iostream>
#include <fstream> // Manejo de archivos
#include <string>  // Cadenas de caracteres
#include <ctime>   // Para fecha de noticias

using namespace std;

// -------------------------------
// --- FUNCIONES DE ESTUDIANTES ---
// -------------------------------

void agregarEstudiante() {
    ofstream archivo("contactos.txt", ios::app);

    if (!archivo) {
        cout << "Error al abrir el archivo de estudiantes\n";
        return;
    }

    string nombre, grado, seccion;

    cout << "\n--- Registrar Estudiante ---\n";
    // Limpiamos el buffer para usar getline correctamente
    cin.ignore();
    cout << "Ingrese nombre completo: ";
    getline(cin, nombre);

    cout << "Ingrese grado: ";
    getline(cin, grado);

    cout << "Ingrese seccion: ";
    getline(cin, seccion);

    // Guardamos: nombre,grado,seccion
    archivo << nombre << "," << grado << "," << seccion << endl;
    cout << "Registro exitoso\n";

    archivo.close();
}

void mostrarEstudiantes() {
    ifstream archivo("contactos.txt");

    if (!archivo) {
        cout << "No hay estudiantes registrados\n";
        return;
    }

    string linea;
    cout << "\n--- Lista de Estudiantes ---\n";

    while (getline(archivo, linea)) {
        // Logica para separar los 3 campos: nombre, grado, seccion
        size_t pos1 = linea.find(",");
        string nombre = linea.substr(0, pos1);

        string resto = linea.substr(pos1 + 1);
        size_t pos2 = resto.find(",");
        string grado = resto.substr(0, pos2);
        string seccion = resto.substr(pos2 + 1);

        cout << "Nombre: " << nombre << " | Grado: " << grado << " | Seccion: " << seccion << "\n";
    }

    archivo.close();
}

void buscarEstudiante() {
    ifstream archivo("contactos.txt");

    if (!archivo) {
        cout << "No hay estudiantes registrados\n";
        return;
    }

    string linea, nombreBuscar;
    bool encontrado = false;

    // Limpiamos el buffer para leer el nombre completo a buscar
    cin.ignore();
    cout << "\nIngrese nombre a buscar: ";
    getline(cin, nombreBuscar);

    while (getline(archivo, linea)) {
        // Logica para extraer el nombre
        size_t pos1 = linea.find(",");
        string nombre = linea.substr(0, pos1);

        string resto = linea.substr(pos1 + 1);
        size_t pos2 = resto.find(",");
        string grado = resto.substr(0, pos2);
        string seccion = resto.substr(pos2 + 1);

        if (nombre == nombreBuscar) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << nombre << " | Grado: " << grado << " | Seccion: " << seccion << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado\n";
    }

    archivo.close();
}

// -------------------------------
// --- FUNCIONES DE NOTICIAS ---
// -------------------------------

void agregarNoticia() {
    ofstream archivo("noticias.txt", ios::app);

    if (!archivo) {
        cout << "Error al abrir el archivo de noticias\n";
        return;
    }

    string titulo, cuerpo;

    // Obtenemos la fecha actual (ctime no usa acentos)
    time_t tiempo = time(0);
    tm* info = localtime(&tiempo);
    string fecha = to_string(info->tm_mday) + "/" +
                    to_string(1 + info->tm_mon) + "/" +
                    to_string(1900 + info->tm_year);

    cin.ignore();
    cout << "\nIngrese titulo: ";
    getline(cin, titulo);

    cout << "Ingrese contenido: ";
    getline(cin, cuerpo);

    // Guardamos: Fecha|titulo|cuerpo
    archivo << fecha << "|" << titulo << "|" << cuerpo << endl;
    cout << "Noticia registrada\n";

    archivo.close();
}

void mostrarNoticias() {
    ifstream archivo("noticias.txt");

    if (!archivo) {
        cout << "No hay noticias registradas\n";
        return;
    }

    string linea;
    int contador = 1;

    cout << "\n--- Noticias del Liceo ---\n";

    while (getline(archivo, linea)) {
        // Logica para separar los 3 campos: fecha, titulo, cuerpo (separador '|')
        size_t pos1 = linea.find("|");
        string fecha = linea.substr(0, pos1);

        string resto = linea.substr(pos1 + 1);
        size_t pos2 = resto.find("|");
        string titulo = resto.substr(0, pos2);
        string cuerpo = resto.substr(pos2 + 1);

        cout << "(" << contador << ") [" << fecha << "] " << titulo << "\n";
        cout << "Contenido: " << cuerpo << "\n";
        contador++;
    }

    archivo.close();
}

// -------------------------------
// --- MENU PRINCIPAL ---
// -------------------------------

int main() {
    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Ver estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Registrar noticia\n";
        cout << "5. Ver noticias\n";
        cout << "6. Salir\n";
        cout << "Ingrese opcion: ";

        if (!(cin >> opcion)) {
            cout << "Entrada invalida\n";
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = 0;
            continue;
        }

        switch (opcion) {
            case 1: agregarEstudiante(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: buscarEstudiante(); break;
            case 4: agregarNoticia(); break;
            case 5: mostrarNoticias(); break;
            case 6: cout << "Hasta luego\n"; break;
            default: cout << "Opcion no valida\n";
        }

    } while (opcion != 6);

    return 0;
}
