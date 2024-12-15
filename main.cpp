#include <iostream>
using namespace std;

// оголошення функцій
bool in_sort_numbers(double& A, double& B, double& C); // введеня з перевіркою чисел A, B, C
void sortDescending(double& A, double& B, double& C); // сортування трьох чисел
void out_sorted_numbers(double A, double B, double C); // виведення результату відсортованих чисел
void task_SortDec3(); // задача 1

bool in_A_B(int& A, int& B); // введення з перевіркою чисел A та B
bool is_one_odd(int A, int B); // перевірка на непарність
void out_res_bool(bool result); // виведення результату для булевого типу
void task_Boolean10(); // задача 2

bool in_number(int& num); // введення з перевіркою двозначного числа
int swap_digits(int num); // перестановка цифр числа
void out_res_int(int result); // виведення результату для цілого числа
void task_Int8(); // задача 3

// основна функція
int main() {
    int menu;
    // Виведення меню
    cout << "\nSelect a task:" << endl;
    cout << "1. Sort three numbers in descending order." << endl;
    cout << "2. Check if exactly one of A and B is odd." << endl;
    cout << "3. Swap digits of a two-digit number." << endl;
    cout << "4. Exit." << endl;
    cout << "Enter your choice: ";
    cin >> menu;

    // Перевірка вибору
    if (cin.fail() || menu < 1 || menu > 4) {
        cout << "Invalid choice. Please try again." << endl;
        return 0; // Якщо вибір некоректний, завершуємо програму
    }

    switch (menu) {
    case 1:
        task_SortDec3(); // виклик задачі 1
        break;
    case 2:
        task_Boolean10(); // виклик задачі 2
        break;
    case 3:
        task_Int8(); // виклик задачі 3
        break;
    case 4:
        cout << "Exiting the program." << endl;
        return 0; // вихід з програми
    }
}

void task_SortDec3() {
    double A1, B1, C1, A2, B2, C2;

    // Введення та перевірка даних для першого набору
    if (in_sort_numbers(A1, B1, C1)) { // некоректні дані
        cout << "A1, B1, C1 must be integers in the range [-100, 100]!" << endl;
    }
    else {
        // Сортування та виведення результату для першого набору
        sortDescending(A1, B1, C1);
        out_sorted_numbers(A1, B1, C1);
    }

    // Введення та перевірка даних для другого набору
    if (in_sort_numbers(A2, B2, C2)) { // некоректні дані
        cout << "A2, B2, C2 must be integers in the range [-100, 100]!" << endl;
    }
    else {
        // Сортування та виведення результату для другого набору
        sortDescending(A2, B2, C2);
        out_sorted_numbers(A2, B2, C2);
    }
}

// Функція для введення трьох чисел з перевіркою
bool in_sort_numbers(double& A, double& B, double& C) {
    cout << "Enter three numbers (A, B, C) in the range [-100, 100]: ";
    cin >> A >> B >> C;

    // Перевірка на коректність введення
    if (A < -100 || A > 100 || B < -100 || B > 100 || C < -100 || C > 100) {
        cout << "Error: Numbers must be in the range [-100, 100]." << endl;
        return true; // некоректні дані
    }
    return false; // коректні дані
}

// Функція для сортування чисел по спадаючій
void sortDescending(double& A, double& B, double& C) {
    if (A < B) swap(A, B);
    if (A < C) swap(A, C);
    if (B < C) swap(B, C);
}

// Функція для виведення відсортованих чисел
void out_sorted_numbers(double A, double B, double C) {
    cout << "Sorted numbers in descending order: " << A << " " << B << " " << C << endl;
}

void task_Boolean10() {
    int A, B; // декларація змінних
    // введення даних
    if (in_A_B(A, B)) // некоректні дані
        cout << "A and B must be integers in the range [-100, 100]!" << endl;
    else
        // підрахунок і виведення результату
        out_res_bool(is_one_odd(A, B));
}

// функція для введення та перевірки коректності введених чисел
bool in_A_B(int& A, int& B) {
    cout << "Enter two integers A and B (in the range [-100, 100]):" << endl;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;

    // Перевірка на коректність введення
    if (cin.fail() || A < -100 || A > 100 || B < -100 || B > 100) { // якщо число не в діапазоні або не ціле
        return true;
    }
    return false;
}

// функція перевірки, чи рівне одне з чисел непарне
bool is_one_odd(int A, int B) {
    return (A % 2 != 0 && B % 2 == 0) || (A % 2 == 0 && B % 2 != 0);
}

// функція виведення результату для булевого значення
void out_res_bool(bool result) {
    if (result)
        cout << "The statement is true: exactly one of A and B is odd." << endl;
    else
        cout << "The statement is false: either both are odd or both are even." << endl;
}

// задача для перестановки цифр двозначного числа
void task_Int8() {
    int num; // декларація змінної для двозначного числа
    // введення даних
    if (in_number(num)) // некоректні дані
        cout << "Please enter a valid two-digit number!" << endl;
    else {
        // підрахунок і виведення результату
        int result = swap_digits(num);
        out_res_int(result);
    }
}

// функція для введення двозначного числа з перевіркою коректності
bool in_number(int& num) {
    cout << "Enter a two-digit number: " << endl;
    cin >> num;

    // Перевірка на коректність введення двозначного числа
    if (cin.fail() || (num > -10 && num < 10) || (num > 99 || num < -99)) {
        return true; // некоректне введення
    }
    return false;
}

// функція для перестановки цифр двозначного числа
int swap_digits(int num) {
    int tens = num / 10; // десятки
    int ones = num % 10; // одиниці

    // формуємо нове число після перестановки цифр
    return ones * 10 + tens;
}

// функція виведення результату для цілого числа
void out_res_int(int result) {
    cout << "The number after swapping the digits is: " << result << endl;
}
