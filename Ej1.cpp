/*
En una red social, los usuarios son representados como nodos, y las relaciones de amistad o conexión entre ellos son aristas. Este grafo es no dirigido, ya que, si dos usuarios son amigos, la relación es bidireccional. También puedes almacenar atributos adicionales, como el número de interacciones entre ellos, que podrían ser ponderaciones en las aristas.
Descripción del problema:
•	Cada usuario de la red social es un nodo en el grafo.
•	Las amistades entre usuarios son las aristas.
•	Puedes buscar si dos usuarios son amigos.
•	Puedes agregar nuevas amistades.
•	Eliminar amistades o usuarios de la red.
•	Mostrar los amigos de un usuario específico.
Operaciones:
1.	Insertar Usuario: Añadir un nodo al grafo representando a un nuevo usuario.
2.	Agregar Amistad: Añadir una arista entre dos nodos (usuarios) para representar una amistad.
3.	Eliminar Amistad: Quitar la conexión entre dos usuarios.
4.	Buscar Usuario: Ver si un usuario está en la red social.
5.	Imprimir la Red Social: Mostrar todos los usuarios y sus amigos (las conexiones en el grafo).
*/

#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;

void menu()
{
    cout << "--------------------------MENU--------------------------" << endl;
    cout << "1. Agregar Persona" << endl;
    cout << "2. Agregar Amistad" << endl;
    cout << "3. Buscar Persona" << endl;
    cout << "4. Eliminar Persona" << endl;
    cout << "5. Imprimir la Red Social" << endl;
    cout << "6. Salir" << endl;
    cout << "--------------------------------------------------------" << endl;
}

int main()
{
    Grafo<string> red;
    int opcion;
    string persona, amigo;

    do
    {
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese el nombre del nuevo usuario: " << endl;
            cin >> persona;
            try
            {
                red.agregarNodo(persona);
            }
            catch (int e)
            {
                cout << "Error: la persona ya existe." << endl;
            }
            break;
        case 2:
            cout << "Ingrese el nombre de la persona: " << endl;
            cin >> persona;
            cout << "Ingrese el nombre de la persona con la que desea agregar amistad: " << endl;
            cin >> amigo;
            try
            {
                red.agregarArista(persona, amigo);
            }
            catch (int e)
            {
                if (e == 200)
                {
                    cout << "Error: una de las dos personas no existe." << endl;
                }
            }
            break;
        case 3:
            cout << "Ingrese el nombre de la persona a buscar: " << endl;
            cin >> persona;
            if (red.buscarNodo(persona))
            {
                cout << "La persona " << persona << " esta en la red social." << endl;
            }
            else
            {
                cout << "Persona no encontrada." << endl;
            }
            break;
        case 4:
            cout << "Ingrese el nombre de la persona a eliminar: " << endl;
            cin >> persona;
            try
            {
                red.eliminarNodo(persona);
            }
            catch (int e)
            {
                cout << "Error: la persona no existe." << endl;
            }
            break;
        case 5:
            cout << "Red social actual: " << endl;
            red.imprimir();
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 6);
}