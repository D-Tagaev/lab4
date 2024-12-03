#include <iostream>
using namespace std;

// Оголошення функцій

bool inputNumbers(double& A, double& B, double& C); // // Функція для введення трьох чисел з перевіркою на коректність введення
void sortDescending(double& A, double& B, double& C); // Функція для впорядкування трьох чисел за спаданням
void outputSortedNumbers(double A, double B, double C); // Виводить на екран три числа в порядку спадання
void SortDec3();

bool inputTwoDigitNumber(int& number); // Функція для введення двозначного числа з перевіркою на коректність
int rearrangeDigits(int number); // Функція для перестановки цифр двозначного числа, повертає нове число з переставленими цифрами
void outputRearrangedNumber(int result);
void Integer8();

bool inputTwoIntegers(int& A, int& B);
bool checkParity(int A, int B);
void outputParityResult(bool result);
void Boolean10();

// Головна програма
int main() {
    int menu;

    do {
        cout << "Choose task:" << endl;
        cout << "1. Sort two sets of numbers in descending order" << endl;
        cout << "2. Permutation of the digits of a two-digit number" << endl;
        cout << "3. Parity check (exactly one odd number)" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> menu;

        switch (menu) {
        case 1:
            SortDec3();
            break;
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
            cout << "Incorrect choice. Try again." << endl;
        }

        cout << endl;

    } while (menu != 0);

    return 0;
}

// Функція для введення трьох чисел і перевірки на коректність

// Головна функція для виконання завдання 1
void SortDec3() {
    double A1, B1, C1, A2, B2, C2; // Змінні для двох наборів чисел

    // Введення чисел для першого набору
    if (!inputNumbers(A1, B1, C1)) {
        cout << "Error: Invalid input. Please enter valid numbers." << endl;
        return;
    }

    // Введення чисел для другого набору
    if (!inputNumbers(A2, B2, C2)) {
        cout << "Error: Invalid input. Please enter valid numbers." << endl;
        return;
    }

    // Впорядкування чисел для кожного набору по спаданню
    sortDescending(A1, B1, C1);
    sortDescending(A2, B2, C2);

    // Виведення результату
    cout << "Sorted numbers of the first set: ";
    outputSortedNumbers(A1, B1, C1);
    cout << "Sorted numbers of the second set: ";
    outputSortedNumbers(A2, B2, C2);
}

bool inputNumbers(double& A, double& B, double& C) {
    cout << "Task 1: Sort three numbers in descending order." << endl;
    cout << "Enter three numbers (A, B, C) in the range [-100, 100]: ";
    cin >> A >> B >> C;

    if (cin.fail()) {
        return false; // Помилка введення
    }

    // Перевірка діапазону чисел
    if (A < -100 || A > 100 || B < -100 || B > 100 || C < -100 || C > 100) {
        cout << "Error: Numbers must be in the range [-100, 100]." << endl;
        return false; // Помилка діапазону
    }

    return true; // Успішне введення
}

// Функція для впорядкування трьох чисел по спаданню
void sortDescending(double& A, double& B, double& C) {
    if (A < B) swap(A, B);
    if (A < C) swap(A, C);
    if (B < C) swap(B, C);
}

// Функція для виведення результату
void outputSortedNumbers(double A, double B, double C) {
    cout << "Sorted numbers: " << A << ", " << B << ", " << C << endl;
}

// Функція для введення двозначного числа з перевіркою

// Головна функція для виконання завдання 2
void Integer8() {
    int number; // Змінна для зберігання числа

    // Введення числа і перевірка на коректність
    if (!inputTwoDigitNumber(number)) {
        cout << "Error: Invalid input. Please enter a valid two-digit number." << endl;
        return;
    }

    // Перестановка цифр і виведення результату
    int result = rearrangeDigits(number);
    outputRearrangedNumber(result);
}

bool inputTwoDigitNumber(int& number) {
    cout << "Task 2: Rearrange the digits of a two-digit number." << endl;
    cout << "Enter a two-digit number in the range [-100, 100]: ";
    cin >> number;

    if (cin.fail()) {
        return false; // Помилка введення
    }

    // Перевірка діапазону (двозначне число)
    if (number < -100 || number > 100 || (number > -10 && number < 10)) {
        cout << "Error: The number must be two-digit and in the range [-100, 100]." << endl;
        return false; // Некоректне число
    }

    return true; // Успішне введення
}

// Функція для перестановки цифр числа
int rearrangeDigits(int number) {
    int dozens = abs(number) / 10; // Десятки
    int units = abs(number) % 10; // Одиниці
    int newNumber = units * 10 + dozens;
    return (number < 0) ? -newNumber : newNumber; // Зберегти знак
}

// Функція для виведення результату перестановки
void outputRearrangedNumber(int result) {
    cout << "The number with rearranged digits: " << result << endl;
}

// Функція для введення двох чисел із перевіркою на коректність

// Головна функція для виконання завдання 3
void Boolean10() {
    int A, B; // Змінні для двох чисел

    // Введення чисел і перевірка на коректність
    if (!inputTwoIntegers(A, B)) {
        cout << "Error: Invalid input. Please enter valid integers." << endl;
        return;
    }

    // Перевірка на парність і виведення результату
    bool result = checkParity(A, B);
    outputParityResult(result);
}

bool inputTwoIntegers(int& A, int& B) {
    cout << "Task 3: Check if exactly one number is odd." << endl;
    cout << "Enter two integers in the range [-100, 100]: ";
    cin >> A >> B;

    if (cin.fail()) {
        return false; // Помилка введення
    }

    // Перевірка діапазону
    if (A < -100 || A > 100 || B < -100 || B > 100) {
        cout << "Error: Numbers must be in the range [-100, 100]." << endl;
        return false; // Некоректне число
    }

    return true; // Успішне введення
}

// Функція для перевірки, чи є одне непарне число
bool checkParity(int A, int B) {
    return (A % 2 != 0) ^ (B % 2 != 0); // Виключне АБО (одне непарне)
}

// Функція для виведення результату перевірки парності
void outputParityResult(bool result) {
    cout << "Exactly one number is odd: " << (result ? "Yes" : "No") << endl;
}
