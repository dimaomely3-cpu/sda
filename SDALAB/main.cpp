#include <iostream>
#include <string>
#include <windows.h>  // Для установки кодировки в консоли
using namespace std;

// ===== СТРУКТУРА =====
struct ElectronicDevice {
    string name;
    string manufacturer;
    int year;
    double price;
    string type;
};

const int SIZE = 10;

// ===== ФУНКЦИЯ ВВОДА =====
void inputDevices(ElectronicDevice arr[], int count) {
    cin.ignore(); // Очистка буфера перед getline
    for (int i = 0; i < count; i++) {
        cout << "\nУстройство #" << i << endl;

        cout << "Название: ";
        getline(cin, arr[i].name);

        cout << "Производитель: ";
        getline(cin, arr[i].manufacturer);

        cout << "Год выпуска: ";
        cin >> arr[i].year;

        cout << "Цена: ";
        cin >> arr[i].price;
        cin.ignore(); // Очистка буфера после чисел

        cout << "Тип (телефон/ноутбук и т.д.): ";
        getline(cin, arr[i].type);
    }
}

// ===== ФУНКЦИЯ ВЫВОДА =====
void printDevices(ElectronicDevice arr[], int count) {
    cout << "\n===== СПИСОК УСТРОЙСТВ =====\n";
    for (int i = 0; i < count; i++) {
        cout << "Индекс: " << i << endl;
        cout << "Название: " << arr[i].name << endl;
        cout << "Производитель: " << arr[i].manufacturer << endl;
        cout << "Год: " << arr[i].year << endl;
        cout << "Цена: " << arr[i].price << endl;
        cout << "Тип: " << arr[i].type << endl;
        cout << "-------------------------\n";
    }
}

// ===== РЕДАКТИРОВАНИЕ ПО ИНДЕКСУ =====
void editDevice(ElectronicDevice arr[], int count) {
    int index;
    cout << "Введите индекс для редактирования: ";
    cin >> index;
    cin.ignore(); // Очистка буфера

    if (index < 0 || index >= count) {
        cout << "Ошибка индекса!\n";
        return;
    }

    int choice;
    cout << "\nЧто изменить?\n";
    cout << "1 - Название\n";
    cout << "2 - Производитель\n";
    cout << "3 - Год\n";
    cout << "4 - Цена\n";
    cout << "5 - Тип\n";
    cin >> choice;
    cin.ignore(); // Очистка буфера

    switch (choice) {
        case 1:
            cout << "Новое название: ";
            getline(cin, arr[index].name);
            break;
        case 2:
            cout << "Новый производитель: ";
            getline(cin, arr[index].manufacturer);
            break;
        case 3:
            cout << "Новый год: ";
            cin >> arr[index].year;
            cin.ignore();
            break;
        case 4:
            cout << "Новая цена: ";
            cin >> arr[index].price;
            cin.ignore();
            break;
        case 5:
            cout << "Новый тип: ";
            getline(cin, arr[index].type);
            break;
        default:
            cout << "Неверный выбор\n";
    }
}

// ===== ПОИСК ПО НАЗВАНИЮ =====
void searchDevice(ElectronicDevice arr[], int count) {
    string key;
    cin.ignore(); // Очистка буфера
    cout << "Введите название для поиска: ";
    getline(cin, key);

    bool found = false;

    for (int i = 0; i < count; i++) {
        if (arr[i].name == key) {
            cout << "\nНайдено устройство:\n";
            cout << "Название: " << arr[i].name << endl;
            cout << "Производитель: " << arr[i].manufacturer << endl;
            cout << "Год: " << arr[i].year << endl;
            cout << "Цена: " << arr[i].price << endl;
            cout << "Тип: " << arr[i].type << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Ничего не найдено.\n";
    }
}

// ===== ГЛАВНАЯ ФУНКЦИЯ =====
int main() {
    // Устанавливаем кодировку UTF-8 для консоли Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    ElectronicDevice devices[SIZE];
    int count;

    cout << "Сколько устройств ввести (макс 10)? ";
    cin >> count;
    cin.ignore(); // Очистка буфера

    inputDevices(devices, count);

    int menu;
    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 - Показать все устройства\n";
        cout << "2 - Редактировать устройство\n";
        cout << "3 - Поиск устройства по названию\n";
        cout << "0 - Выход\n";
        cin >> menu;

        switch (menu) {
            case 1:
                printDevices(devices, count);
                break;
            case 2:
                editDevice(devices, count);
                break;
            case 3:
                searchDevice(devices, count);
                break;
        }

    } while (menu != 0);

    return 0;
}
