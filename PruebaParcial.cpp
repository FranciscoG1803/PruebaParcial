#include <iostream>
#include <string>


using namespace std;

const int cantidad_facultades = 5;

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
    cout<<"Ingrese el nombre de la univercidad: ";
    getline(cin,u.nombre);

    cout<<"Ingrese la direccion de la univercidad: ";
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
    cout<<"------------------------------------"<<endl;
    cout<<"Nombre de la universidad: "<<u.nombre<<endl;
    cout<<"Direccion de la universidad: "<<u.direccion<<endl;

    cout<<"Facultades"<<endl;
    for (int i = 0; i < cantidad_facultades; i++)
    {
        cout<<"\nNumero de facultad: "<< u.facultad[i].numero_facultad;
        cout<<"\nCarreara principal: "<< u.facultad[i].carrera_principal;
        cout<<"\nCantidad de estudiantes: "<< u.facultad[i].numero_estudiantes;
    }
}

int main() {
    Universidad u;
    int opcion = 0;

    do
    {
        cout<<"\n-----Sistema de Gestionamiento de Universidades-----"<<endl<<endl;
        cout<<"1. Registrar universidad"<<endl;
        cout<<"2. Mostrar los datos de las univesidades"<<endl;
        cout<<"3. Calcular total de estudiantes por facultad"<<endl;
        cout<<"4. Buscar carrera"<<endl;
        cout<<"5. Salir del programa"<<endl<<endl;
        cout<<"Que desea realizar: ";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            u = ingresar_universidad();
            break;
        
        case 2:
            MostrarUniversidad(u);
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

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