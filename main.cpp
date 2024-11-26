#include <iostream>
using namespace std;

// Процедура для впорядкування чисел по спаданню
void Proc13(double& A, double& B, double& C);

// Функція для перестановки цифр двозначного числа
void Integer8();

// Функція для перевірки на парність
void Boolean10();

int main() {
    int menu;

    do {
        // Меню вибору завдання
        cout << "Choose task:" << endl;
        cout << "1. Sort two sets of numbers in descending order" << endl;
        cout << "2. Permutation of the digits of a two-digit number" << endl;
        cout << "3. Parity check(exactly one odd number)" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> menu;

        switch (menu) {
        case 1: {
            // Введення двох наборів
            double A1, B1, C1, A2, B2, C2;
            cout << "Enter three numbers for the first set (A1, B1, C1): ";
            cin >> A1 >> B1 >> C1;
            cout << "Enter three numbers for the second set(A2, B2, C2): ";
            cin >> A2 >> B2 >> C2;

            // Перевірка діапазону
            if ((A1 < -100 || A1 > 100) || (B1 < -100 || B1 > 100) || (C1 < -100 || C1 > 100) ||
                (A2 < -100 || A2 > 100) || (B2 < -100 || B2 > 100) || (C2 < -100 || C2 > 100)) {
                cout << "Error: All numbers must be in the range[-100, 100]." << endl;
            }
            else {
                Proc13(A1, B1, C1);
                Proc13(A2, B2, C2);
                cout << "Ordered numbers of the first set: " << A1 << ", " << B1 << ", " << C1 << endl;
                cout << "Ordered numbers of the second set: " << A2 << ", " << B2 << ", " << C2 << endl;
            }
            break;
        }
        case 2:
            Integer8();
            break;
        case 3:
            Boolean10();
            break;
        case 0:
            cout << "The program is complete." << endl;
            break;
        default:
            cout << "Incorrect choice.Try again." << endl;
        }

        cout << endl;

    }

    return 0;
}

// Визначення функцій

// Процедура для впорядкування трьох чисел по спаданню
void Proc13(double& A, double& B, double& C) {
    if (A < B) swap(A, B);
    if (A < C) swap(A, C);
    if (B < C) swap(B, C);
}

// Перестановка цифр двозначного числа
void Integer8() {
    int a;
    cout << "Enter a two-digit number: ";
    cin >> a;

    if (a < -100 || a > 100 || (a > -10 && a < 10)) { // перевірка, входить число до діапазону -100 до 100
        cout << "Error: The number must be two - digit and in the range[-100, 100]." << endl; 
        return;
    }

    int dozens = a / 10; // десятки
    int units = a % 10;  // одиниці
    int newNumber = units * 10 + dozens; // нове число з перестановкою

    cout << "A number with rearranged digits: " << newNumber << endl;
}

// Перевірка на парність
void Boolean10() {
    int A, B;
    cout << "Enter two integers: ";
    cin >> A >> B;

    if (A < -100 || A > 100 || B < -100 || B > 100) { // перевірка, входить число до діапазону -100 до 100
        cout << "Error: Numbers must be in the range [-100, 100]." << endl;
        return;
    }

    bool exactlyOneIsNotPaired = (A % 2 != 0) ^ (B % 2 != 0); // перевірка, ділиться число з остачею на 2 чи без
    cout << "Exactly one number is odd: " << (exactlyOneIsNotPaired ? "Yes" : "No") << endl;
}
