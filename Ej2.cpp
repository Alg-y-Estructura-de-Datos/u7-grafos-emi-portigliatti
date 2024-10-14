#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;

void menu()
{
    cout << "Comision de Colegio / Universidad" << endl;
    cout << "1. Agregar miembro" << endl;
    cout << "2. Establecer colaboracion"<< endl;
    cout << "3. Buscar miembro"<< endl;
    cout << "4. Eliminar miembro "<< endl;
    cout << "5. Mostrar estructura de la comision"<< endl;
    cout << "6. Salir"<< endl;
    cout << "Seleccione una opcion: "<< endl;
}

int main(){
    Grafo<string> comision;
    int opc;
    string miembro, colaborador;

    do
    {
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el nombre del nuevo miembro: " << endl;
            cin >> miembro;
            try
            {
                comision.agregarNodo(miembro);
            }
            catch (int e)
            {
                cout << "Error: el miembro ya existe." << endl;
            }
            break;
        case 2:
            cout << "Ingrese el nombre del miembro: " << endl;
            cin >> miembro;
            cout << "Ingrese el nombre del miembro con el que desea establecer colaboracion: " << endl;
            cin >> colaborador;
            try
            {
                comision.agregarArista(miembro, colaborador);
            }
            catch (int e)
            {
                if (e == 200)
                {
                    cout << "Error: uno de los dos miembros no existe." << endl;
                }
            }
            break;
        case 3:
            cout << "Ingrese el nombre del miembro a buscar: " << endl;
            cin >> miembro;
            if (comision.buscarNodo(miembro))
            {
                cout << "El miembro " << miembro << " se encuentra en la comision." << endl;
            }
            else
            {
                cout << "El miembro " << miembro << " no se encuentra en la comision." << endl;
            }
            break;
        case 4:
            cout << "Ingrese el nombre del miembro a eliminar: " << endl;
            cin >> miembro;
            try
            {
                comision.eliminarNodo(miembro);
            }
            catch (int e)
            {
                cout << "Error: el miembro no existe." << endl;
            }
            break;
        case 5:
            comision.imprimir();
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    } while (opc!=6);
    
}