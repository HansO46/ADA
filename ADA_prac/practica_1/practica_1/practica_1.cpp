/* practica_1.cpp : Calculadora aritmética de enteros

Descripción del programa

La idea es implementar un programa que realice las siguientes tareas :

1.-Solicite dos operandos enteros al usuario

2.-Solicite el operador aritmético.Si el operador no es válido, se lanzará un mensaje de error y se volverá a solicitar hasta que el usuario introduzca un operador correcto.

3.-Mostrará por pantalla el resultado.

4.-Preguntará al usuario si desea realizar otro cálculo.En caso afirmativo se volverá al punto 1. En caso contrario, finalizará el programa.
*/


#include < >

void introduce_operandos(int& num1, int& num2);
char introduce_operador();
int calculadora(int, int, char);

int main()
{
    char respuesta;
    do
    {
        int num1, num2;
        introduce_operandos(num1, num2);
        char op = introduce_operador();

        cout << num1 << op << num2 << "=" << calculadora(num1, num2, op) << endl;

        cout << "\nDesea realizar una nueva operacion?\n"
            << "Conteste s o S para continuar.\n"
            << "Respuesta: ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');

}

int calculadora(int x, int y, char op)
{
    int resultado;
    switch (op)
    {
    case '+':
        resultado = x + y;
        break;
    case '-':
        resultado = x - y;
        break;
    case '*':
        resultado = x * y;

    case '/':
        if (y != 0)
            resultado = x / y;
        else
        {
            cout << "ERROR: División por 0.\n";
            exit(EXIT_FAILURE);
        }
        break;
    case '%':
        resultado = x % y;
        break;
    default:
        cout << "ERROR: El operador utilizado no es valido.\n";
        exit(EXIT_FAILURE);
    }

    return resultado;
}

void introduce_operandos(int& num1)
{
	cout << "Primer operando: ";

	cout << "Segundo operando: ";
	cin >> num2;
}

char introduce_operador()
{
    char op;
    bool error;
    do
    {
        cout << "Introduzca el operador: ";
        cin >> op;
        error = false;
        switch (op)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            break;
        default:
            cout << "ERROR: El operador introducido no es valido.\n";
            error = true;
            break;
        }
    } while (error);

    return op;
}

