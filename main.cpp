#include <iostream>

using namespace std;

struct Persona {
    int identificacion;
    string nombre;
    int edad;
};
struct Libro {
    int codigo;
    string nombre;
    string autor;
    int year;
};

void menu () {
    cout<<"\n Desea hacer un nuevo registro  \n 1 para si \n 0 para no \n";
}
void registrarEstudiante(Persona estudiante[] , int cantidadEstudiantes) {
     cout<<" \n ingrese identificacion del estudiante \n";
    cin>>estudiante[cantidadEstudiantes].identificacion;
    cout<<" \n ingrese Edad del estudiante \n";
    cin>>estudiante[cantidadEstudiantes].edad;
    cout<<" \n ingrese el nombre del estudiante \n";
    cin.ignore();
    getline(cin, estudiante[cantidadEstudiantes].nombre);

    cout<<" \n Estudiante registrado  \n" <<estudiante[cantidadEstudiantes].nombre;
    cout<<" \n de identificacion nro "<<estudiante[cantidadEstudiantes].identificacion;
    cout<<" \n con una edad declarada de "<<estudiante[cantidadEstudiantes].edad;
}

void registrarLibro(Libro libros[] , int cantidadLibros) {
     cout<<" \n ingrese codigo del libro \n";
    cin>>libros[cantidadLibros].codigo;
    cout<<" \n ingrese fecha formato de año ejemplo 2025  \n";
    cin>>libros[cantidadLibros].year;
    cout<<" \n ingrese el nombre del Libro \n";
    cin.ignore();
    getline(cin, libros[cantidadLibros].nombre);
    cout<<" \n ingrese el nombre del Autor \n";
    cin.ignore();
    getline(cin, libros[cantidadLibros].autor);

    cout<<" \n Libro registrado  \n" <<libros[cantidadLibros].nombre;
    cout<<" \n  ISBN "<<libros[cantidadLibros].codigo;
    cout<<" \n de año "<<libros[cantidadLibros].year;
     cout<<" \n Autor "<<libros[cantidadLibros].autor;
}
string buscarLibro(Libro libros[], int identificacion, int cantidadLibros){
    string encontrado="No encontrado ";
    for(int i=0; i<cantidadLibros; i++){
        if(identificacion==libros[i].codigo){
            encontrado=libros[i].nombre;
        }
    }
    return encontrado;
}
void listarLibros(Libro libros[] , int cantidadLibros) {
       cout<<" \n ********* LISTADO DE LIBROS ******* \n";
    for(int i=0; i<cantidadLibros; i++){
        cout<<" \n Libro  \n" <<libros[i].nombre;
        cout<<" \n  ISBN "<<libros[i].codigo;
        cout<<" \n de año "<<libros[i].year;
        cout<<" \n Autor "<<libros[i].autor;
    }

}

int main()
{

Persona estudiante[20];
Libro libros[20];
int  respuestaEstudiante=1,cantidadEstudiantes=0, cantidadLibros=0;
int respuestaLibro=1, respuestaBusquedaLibro=1;
int codigoBuscar=0;
/* seccion del estudiante */
while (respuestaEstudiante>0){
    registrarEstudiante(estudiante, cantidadEstudiantes);
    cantidadEstudiantes++;

    menu ();
    cin>>respuestaEstudiante;
} /* FIN seccion del estudiante */

/* seccion del Libro */
while (respuestaLibro>0){
    registrarLibro(libros, cantidadLibros);
    cantidadLibros++;

    menu ();
    cin>>respuestaLibro;
}

/* libros disponible */

    listarLibros(libros, cantidadLibros);

/* FIN libros disponible */

/* FIN seccion del Libro */
while (respuestaBusquedaLibro>0){
string nombreResultadoBusquedaLibro;
    cout<<" \n  ingrese el codigo del libro que quieres \n ";
    cin>>codigoBuscar;
    nombreResultadoBusquedaLibro=buscarLibro(libros, codigoBuscar, cantidadLibros);
    cout<<" resultado de la busqueda "<< nombreResultadoBusquedaLibro;

    menu ();
    cin>>respuestaBusquedaLibro;
}


}
