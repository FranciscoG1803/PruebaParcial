#include <iostream>
#include <string>

using namespace std;

const int cantidad_facultades = 5;
const int cantidad_universidades = 3;

struct Facultad {
    int numero_facultad;
    string carrera_principal;
    int numero_estudiantes;
};

struct Universidad {
    string nombre;
    string direccion;
    Facultad facultad[cantidad_facultades];
};

Universidad ingresar_universidad(){
    Universidad u;
    cin.ignore();

    cout<<"------------------------------------"<<endl;
    cout<<"Ingrese el nombre de la universidad: ";
    getline(cin,u.nombre);

    cout<<"Ingrese la direccion de la universidad: ";
    getline(cin,u.direccion);

    cout<<"Ingrese los datos de las facultades "<<endl<<endl;
    for (int i = 0; i < cantidad_facultades; i++)
    {
        cout<<"\nIngrese el numero de facultad: ";
        cin>>u.facultad[i].numero_facultad;
        cin.ignore();

        cout<<"Ingrese el nombre de la carrera principal: ";
        getline(cin, u.facultad[i].carrera_principal);
        
        cout<<"Ingrese el numero de estudiantes: ";
        cin>>u.facultad[i].numero_estudiantes;
        cin.ignore();
    }

    return u;
}

void MostrarUniversidad(const Universidad &u){
    cout<<"\n------------------------------------"<<endl;
    cout<<"Nombre de la universidad: "<<u.nombre<<endl;
    cout<<"Direccion de la universidad: "<<u.direccion<<endl;

    cout<<"Facultades"<<endl;
    for (int i = 0; i < cantidad_facultades; i++)
    {
        cout<<"\nNumero de facultad: "<< u.facultad[i].numero_facultad;
        cout<<"\nCarrera principal: "<< u.facultad[i].carrera_principal;
        cout<<"\nCantidad de estudiantes: "<< u.facultad[i].numero_estudiantes;
    }
}

void TotalEstudiantesPorFacultad(const Universidad &u){
    int total = 0;
    for (int i = 0; i < cantidad_facultades; i++)
    {
        total += u.facultad[i].numero_estudiantes;
    }
    cout<<"\nEl total de estudiantes en la universidad "<<u.nombre<<" es: "<<total<<endl;
}

void BuscarCarrera(const Universidad &u, const string &carrera){
    bool encontrada = false;
    for (int i = 0; i < cantidad_facultades; i++)
    {
        if (u.facultad[i].carrera_principal == carrera)
        {
            cout<<"\nCarrera encontrada en la universidad "<<u.nombre<<endl;
            cout<<"Facultad numero: "<<u.facultad[i].numero_facultad<<endl;
            cout<<"Cantidad de estudiantes: "<<u.facultad[i].numero_estudiantes<<endl;
            encontrada = true;
        }
    }

    if (!encontrada)
    {
        cout<<"\nNo se encontro la carrera "<<carrera<<" en la universidad "<<u.nombre<<endl;
    }
}

int main() {
    Universidad u[cantidad_universidades];
    int total_universidades = 0; // cuántas hay registradas
    int opcion = 0;

    do
    {
        cout<<"\n-----Sistema de Gestionamiento de Universidades-----"<<endl<<endl;
        cout<<"1. Registrar universidad"<<endl;
        cout<<"2. Mostrar los datos de las universidades"<<endl;
        cout<<"3. Calcular total de estudiantes por facultad"<<endl;
        cout<<"4. Buscar carrera"<<endl;
        cout<<"5. Salir del programa"<<endl<<endl;
        cout<<"Que desea realizar: ";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            if (total_universidades < cantidad_universidades) {
                u[total_universidades] = ingresar_universidad();
                total_universidades++;
            } else {
                cout<<"Ya no se pueden registrar mas universidades (maximo "<<cantidad_universidades<<")."<<endl;
            }
            break;
        
        case 2:
            if (total_universidades == 0) {
                cout<<"No hay universidades registradas."<<endl;
            } else {
                for (int i = 0; i < total_universidades; i++) {
                    MostrarUniversidad(u[i]);
                }
            }
            break;

        case 3:
            if (total_universidades == 0) {
                cout<<"No hay universidades registradas."<<endl;
            } else {
                for (int i = 0; i < total_universidades; i++) {
                    TotalEstudiantesPorFacultad(u[i]);
                }
            }
            break;

        case 4: {
            if (total_universidades == 0) {
                cout<<"No hay universidades registradas."<<endl;
            } else {
                string carrera;
                cin.ignore();
                cout<<"Ingrese la carrera a buscar: ";
                getline(cin, carrera);
                for (int i = 0; i < total_universidades; i++) {
                    BuscarCarrera(u[i], carrera);
                }
            }
            break;
        }

        case 5:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            cout<<"Error, ingrese una opcion valida"<<endl;
            break;
        }

    } while (opcion != 5);

    return 0;
}
