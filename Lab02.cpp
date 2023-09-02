#include <iostream>
using namespace std;

float suma(float a, float b) {
    return a + b;
}
float resta(float a, float b) {
    return a - b;
}
float multi(float a, float b) {
    return a * b;
}
float divi(float a, float b) {
    return a / b;
}

int main() {
    float num1, num2;
    float rpta;
    // Declaración de punteros a funciones
    float (*operacion)(float, float);
    
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    int opcion;
    cout << "\nQue opcion va a tomar: \n1) Suma\n2) Resta\n3) Multi\n4) Divi\n";
    cin >> opcion;
    // Asigna el puntero a la función correspondiente según la elección 
    // switch(opcion)
    //   {
    //     case 1:
    //       {
    //          operacion = suma; 
    //       }
    //     case 2:
    //       {
    //          operacion = resta; 
    //       }
    //     case 3:
    //       {
    //          operacion = multi; 
    //       }
    //     case 4:
    //       {
    //          operacion = divi; 
    //       }
    //   }
   if (opcion == 1) {
        operacion = suma;
    } else if (opcion == 2) {
        operacion = resta;
    }else if (opcion == 3) {
        operacion = multi;
    }else if (opcion == 4) {
        operacion = divi;
    }
    // Llama a la función a través del puntero y muestra el rpta
    rpta = operacion(num1, num2);
    cout << "La rpta es: " << rpta;   
    return 0;
}


