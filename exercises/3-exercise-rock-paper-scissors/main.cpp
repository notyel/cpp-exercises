#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdio.h>
#include <locale.h>
#include <windows.h>

using namespace std;

int rounds_to_win = 2;
int user_wins = 0;
int computer_wins = 0;

string get_user_choice()
{
    string choice;
    while (true)
    {
        cout << "Elige 'piedra', 'papel' o 'tijeras' (o escribe 'salir' para salir): ";
        cin >> choice;
        if (choice == "piedra" || choice == "papel" || choice == "tijeras" || choice == "salir")
        {
            return choice;
        }
        else
        {
            cout << "Selección no válida. Por favor, elige 'piedra', 'papel' o 'tijeras', o escribe 'salir' para salir." << endl;
        }
    }
}

string get_computer_choice()
{
    string options[] = {"piedra", "papel", "tijeras"};
    int index = rand() % 3;
    return options[index];
}

string determine_winner(const string &user_choice, const string &computer_choice)
{
    if (user_choice == "salir")
    {
        return "Gracias por jugar. ¡Hasta la próxima!";
    }

    if (user_choice == computer_choice)
    {
        return "Empate";
    }
    else if ((user_choice == "piedra" && computer_choice == "tijeras") ||
             (user_choice == "papel" && computer_choice == "piedra") ||
             (user_choice == "tijeras" && computer_choice == "papel"))
    {
        return "¡Ganaste!";
    }
    else
    {
        return "La computadora gana.";
    }
}

void draw_score(int user_wins, int computer_wins)
{
    cout << "[Marcador] Tú: " << user_wins << " - Computadora: " << computer_wins << endl;
}

int main(void)
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    SetConsoleOutputCP(CP_UTF8);

    srand(time(0)); // inicializar el generador de números aleatorios
    int round = 1;
    cout << "Juguemos a Piedra, Papel y Tijeras. Escribe 'salir' para terminar el juego." << endl;

    while (true)
    {
        cout << string(40, '*') << endl;
        cout << "RONDA " << round << endl;
        cout << string(40, '*') << endl;

        string user_choice = get_user_choice();
        if (user_choice == "salir")
        {
            break;
        }

        string computer_choice = get_computer_choice();

        cout << "Elegiste: " << user_choice << endl;
        cout << "La computadora eligió: " << computer_choice << endl;

        string result = determine_winner(user_choice, computer_choice);
        cout << result << endl;

        if (result == "¡Ganaste!")
        {
            user_wins += 1;
        }
        else if (result == "La computadora gana.")
        {
            computer_wins += 1;
        }

        draw_score(user_wins, computer_wins);

        if (user_wins == rounds_to_win)
        {
            cout << "¡Felicidades! Has ganado 2 rondas de 3. ¡Ganaste el juego!" << endl;
            break;
        }
        else if (computer_wins == rounds_to_win)
        {
            cout << "La computadora ha ganado 2 rondas de 3. ¡La computadora gana el juego!" << endl;
            break;
        }

        round += 1;
    }

    return 0;
}
