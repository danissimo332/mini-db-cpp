#include <iostream>
#include <vector>
#include "db_logic.h"
#include "file_io.h"

using namespace std;

int main() {
    vector<User> db;
    int choice;

    do {
        cout<< endl << "МЕНЮ" <<endl;
        cout<< "1) Добавить запись" <<endl;
        cout<< "2) Вывод всех записей" <<endl;
        cout<< "3) Удаление по номеру" <<endl;
        cout<< "4) Поиск по полю" <<endl;
        cout<< "5) Сортировка по полю" <<endl;
        cout<< "6) Сохранить в файл" <<endl;
        cout<< "7) Загрузить из файла" <<endl;
        cout<< "0) Выход" <<endl;
        cout<< "Выбор: ";

        cin>>choice;

        if (cin.fail()) {
            cin.clear();

            string trash;
            cin >> trash;

            choice = -1;
            cout << "Ошибка ввода" << endl;
        } else {
            switch (choice) {
                case 1:
                    addUser(db);
                    break;
                case 2:
                    showUsers(db);
                    break;
                case 3:
                    deleteUser(db);
                    break;
                case 4:
                    searchByField(db);
                    break;
                case 5:
                    sortByField(db);
                    break;
                case 6:
                    saveToFile(db, "data.txt");
                    break;
                case 7:
                    loadFromFile(db, "data.txt");
                    break;
                case 0:
                    cout<< "Выход" <<endl;
                    break;
                default:
                    cout<< "Неверный пункт меню" <<endl;
            }
        }

    } while (choice!=0);

    return 0;
}
