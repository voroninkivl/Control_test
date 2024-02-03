//
//  main.cpp
//  Control_test
//
//  Created by Кирилл Воронин on 03.02.2024.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>



// Функция для заполнения двумерного динамического массива случайными числами от минимально заданного до максимально заданного
void appendingArray(int** arr, int lines, int columns, int min, int max) {
    std:srand(time(nullptr)); // Инициализация генератора случайных чисел
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            arr[i][j] = rand() % (max - min + 1) + min; // Генерация случайного числа от минимального введенного до максимального введенного
        }
    }
}
// Функция для вывода элементов массива
void printArr(int** arr, int lines, int columns) {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int sumOfDiagonal(int** arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i][size - 1 - i];
    }
    return sum;
}



/*int main() {
    int lines = 0, columns = 0;
    
    // Просим пользователя ввести количество столбцов
    std::cout << "Введите количество строк: ";
    std::cin >> lines;
    std::cout << "Введите количество столбцов: ";
    std::cin >> columns;
    
    // Выделяем память под двумерный динамический массив
    int** array = new int*[lines];
    for (int i = 0; i < lines; ++i) {
        array[i] = new int[columns];
    }
    
    
    appendingArray(array, lines, columns, 1, 70); // Заполнение массива
    std::cout << "Двумерный динамический массив:" << std::endl; // Вывод массива на экран
    
    printArr(array, lines, columns);
    

    int sum = sumOfDiagonal(array, fmin(lines, columns)); // Вызываем функцию вычисления суммы на побочной диаграмме
    
    std::cout << "Сумма элементов на побочной диагонали: " << sum << std::endl;
    
    // Освобождение выделенной памяти
    for (int i = 0; i < lines; ++i) { // Освобождение внутри массива
        delete[] array[i];
    }
    
    delete[] array; // Удаление самого массива
    
    return 0;
}*/



// Структура для представления аккаунта пользователя

struct Account {
    std::string username;
    std::string password;
    std::string email;
};

// Функция для добавления нового аккаунта

void addAccount(std::vector<Account>& accounts) {
    Account newAccount;
    std::cout << "Введите имя пользователя: ";
    std::cin >> newAccount.username;
    std::cout << "Введите пароль: ";
    std::cin >> newAccount.password;
    std::cout << "Введите адрес электронной почты: ";
    std::cin >> newAccount.email;
    accounts.push_back(newAccount);
    std::cout << "Аккаунт успешно добавлен!" << std::endl;
}

// Функция для удаления существующего аккаунта
void removeAccount(std::vector<Account>& accounts) {
    std::string username;
    std::cout << "Введите имя пользователя для удаления: ";
    std::cin >> username;

    auto it = std::remove_if(accounts.begin(), accounts.end(), [&username](const Account& acc) { return acc.username == username; });

    if (it != accounts.end()) {
        accounts.erase(it, accounts.end());
        std::cout << "Аккаунт(ы) успешно удален(ы)!" << std::endl;
    } else {
        std::cout << "Аккаунт с таким именем пользователя не найден." << std::endl;
    }
}

// Функция для обновления информации об аккаунте
void updateAccount(std::vector<Account>& accounts) {
    std::string username;
    std::cout << "Введите имя пользователя для обновления: ";
    std::cin >> username;
    for (auto& account : accounts) {
        if (account.username == username) {
            std::cout << "Введите новый пароль: ";
            std::cin >> account.password;
            std::cout << "Введите новый адрес электронной почты: ";
            std::cin >> account.email;
            std::cout << "Информация об аккаунте успешно обновлена!" << std::endl;
            return;
        }
    }
    std::cout << "Аккаунт с таким именем пользователя не найден." << std::endl;
}

// Функция для вывода информации обо всех аккаунтах
void printAllAccounts(const std::vector<Account>& accounts) {
    if (accounts.empty()) {
        std::cout << "Нет доступных аккаунтов." << std::endl;
        return;
    }
    std::cout << "Список всех аккаунтов:" << std::endl;
    for (const auto& account : accounts) {
        std::cout << "Имя пользователя: " << account.username << std::endl;
        std::cout << "Пароль: " << account.password << std::endl;
        std::cout << "Email: " << account.email << std::endl << std::endl;
    }
}

int main() {
    std::vector<Account> accounts; // Хранение аккаунтов
    
    
    // Инициализация массива указателей на функции
    auto functions = std::vector<std::function<void(std::vector<Account>&)>> {
            addAccount,
            removeAccount,
            updateAccount,
            printAllAccounts
        };
    
    
    int number = 0;
    // Выполнение выбранного действия
    do {
        // Вывод меню
        std::cout << "Выберите действие для аккаунта:" << std::endl;
        std::cout << "1 - Добавить аккаунт" << std::endl;
        std::cout << "2 - Удалить аккаунт" << std::endl;
        std::cout << "3 - Обновить информацию об аккаунте" << std::endl;
        std::cout << "4 - Вывести информацию обо всех аккаунтах" << std::endl;
        std::cout << "0 - Выйти" << std::endl;
        std::cout << "Введите номер: ";
        std::cin >> number;
        
        // Выполнение выбранного действия
        switch (number) {
            case 1:
                addAccount(accounts);
                break;
            case 2:
                removeAccount(accounts);
                break;
            case 3:
                updateAccount(accounts);
                break;
            case 4:
                printAllAccounts(accounts);
                break;
            case 0:
                std::cout << "До свидания!" << std::endl;
                break;
            default:
                std::cout << "Нет доступных дейcтвий. Попробуйте снова." << std::endl;
        }
    } while (number != 0);
    
    return 0;
}
