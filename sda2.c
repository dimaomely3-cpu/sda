#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура устройства
typedef struct {
    int id;
    char name[50];
} Device;

// Глобальные переменные массива
Device* devices = NULL;
int size = 0;       // количество элементов
int capacity = 0;   // выделенная память

// Функция расширения массива (БЕЗ realloc)
void expandArray(int extra)
{
    int newCapacity = capacity + extra;

    Device* newArray = (Device*)malloc(newCapacity * sizeof(Device));
    if (newArray == NULL)
    {
        printf("Ошибка выделения памяти\n");
        return;
    }

    // копируем старые данные
    for (int i = 0; i < size; i++)
    {
        newArray[i] = devices[i];
    }

    // освобождаем старую память
    free(devices);

    devices = newArray;
    capacity = newCapacity;

    printf("Массив расширен. Новая вместимость: %d\n", capacity);
}

// Добавление устройства
void addDevice()
{
    if (size >= capacity)
    {
        expandArray(2); // увеличиваем на 2 элемента
    }

    printf("Введите ID: ");
    scanf("%d", &devices[size].id);

    printf("Введите имя устройства: ");
    scanf("%s", devices[size].name);

    size++;

    printf("Устройство добавлено.\n");
}

// Удаление последнего устройства
void removeLastDevice()
{
    if (size == 0)
    {
        printf("Список пуст.\n");
        return;
    }

    size--;

    printf("Последнее устройство удалено.\n");
}

// Показать список
void showDevices()
{
    if (size == 0)
    {
        printf("Список пуст.\n");
        return;
    }

    printf("\nСписок устройств:\n");

    for (int i = 0; i < size; i++)
    {
        printf("ID: %d | Name: %s\n", devices[i].id, devices[i].name);
    }
}

// Очистка памяти
void clearDevices()
{
    free(devices);
    devices = NULL;
    size = 0;
    capacity = 0;

    printf("Память очищена.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== МЕНЮ =====\n");
        printf("1. Добавить устройство\n");
        printf("2. Удалить последнее устройство\n");
        printf("3. Показать устройства\n");
        printf("4. Очистить память\n");
        printf("0. Выход\n");

        printf("Выберите: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addDevice();
            break;

        case 2:
            removeLastDevice();
            break;

        case 3:
            showDevices();
            break;

        case 4:
            clearDevices();
            break;

        case 0:
            clearDevices();
            return 0;

        default:
            printf("Неверный выбор\n");
        }
    }

    return 0;
}