#include <iostream>
using namespace std;

// Función que determina si una persona tiene anemia o no
bool tiene_anemia(int edad, double hemoglobina) {
    // Valores mínimos de hemoglobina según la edad
    double min_hemoglobina[] = { 13, 10, 11, 13, 12, 14 };
    // Edades límite para cada rango
    int edades[] = { 1, 6, 12, 15, -1, -1 };
    // Índice del rango correspondiente a la edad
    int indice = 0;
    // Buscar el índice del rango
    while (indice < 6 && edades[indice] != -1 && edad > edades[indice]) {
        indice++;
    }
    // Comparar la hemoglobina con el valor mínimo
    return hemoglobina < min_hemoglobina[indice];
}

int main() {
    // Variables para almacenar la edad y la hemoglobina
    int edad;
    double hemoglobina;
    // Pedir al usuario que ingrese la edad y la hemoglobina
    cout << "Ingrese su edad en meses: ";
    cin >> edad;
    cout << "Ingrese su nivel de hemoglobina en g/dL: ";
    cin >> hemoglobina;
    // Llamar a la función tiene_anemia y mostrar el resultado
    if (tiene_anemia(edad, hemoglobina)) {
        cout << "Usted tiene anemia." << endl;
    }
    else {
        cout << "Usted no tiene anemia." << endl;
    }
    return 0;
}
