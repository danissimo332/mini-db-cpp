#include "db_logic.h"
#include <iostream>

using namespace std;

void clearInput() {
    cin.clear();
}

void addUser(vector<User>& db) {
    User u;

    cout<< "Имя: ";
    cin>> u.name;

    cout<< "Возраст: ";
    cin>> u.age;
    if (cin.fail() || u.age<0) {
        clearInput();
        cout<< "Ошибка ввода возраста" <<endl;
        return;
    }

    cout<< "Зарплата: ";
    cin>> u.salary;
    if (cin.fail() || u.salary<0) {
        clearInput();
        cout<< "Ошибка ввода зарплаты" <<endl;
        return;
    }

    db.push_back(u);
    cout<< "Запись добавлена" <<endl;
}

void showUsers(const vector<User>& db) {
    if (db.size()==0) {
        cout << "База пуста" << endl;
        return;
    }

    cout<<endl<< "№  Имя   Возраст  Зарплата" <<endl;
    for (int i = 0; i < db.size(); i++){
        cout<< i+1 << ") "
             << db[i].name <<"   "
             << db[i].age <<"      "
             << db[i].salary <<endl;
    }
}

void deleteUser(vector<User>& db) {
    if (db.size()==0) {
        cout<< "База пуста" <<endl;
        return;
    }

    int n;
    cout<< "Введите номер записи: ";
    cin>> n;

    if (cin.fail()) {
        clearInput();
        cout<< "Ошибка ввода" <<endl;
        return;
    }

    if (n<1 || n>db.size()) {
        cout<< "Неверный номер" <<endl;
        return;
    }

    db.erase(db.begin()+(n-1));
    cout<< "Запись удалена" <<endl;
}

void searchByField(const vector<User>& db) {
    if (db.size()==0) {
        cout<< "База пуста" <<endl;
        return;
    }

    cout<< "По какому полю искать?" <<endl;
    cout<< "1) Имя" <<endl;
    cout<< "2) Возраст" <<endl;
    cout<< "3) Зарплата" <<endl;

    int field;
    cout<< "Выбор: ";
    cin>>field;

    if (cin.fail()) {
        clearInput();
        cout << "Ошибка ввода" << endl;
        return;
    }

    bool found = false;

    if (field==1) {
        string name;
        cout<< "Введите имя: ";
        cin>>name;

        for (int i = 0; i < db.size(); i++) {
            if (db[i].name==name) {
                cout << db[i].name <<" "
                     << db[i].age <<" "
                     << db[i].salary <<endl;
                found = true;
            }
        }
    } else if (field==2) {
        int age;
        cout<< "Введите возраст: ";
        cin>>age;

        if (cin.fail()) {
            clearInput();
            return;
        }

        for (int i = 0; i < db.size(); i++) {
            if (db[i].age == age) {
                cout << db[i].name <<" "
                     << db[i].age <<" "
                     << db[i].salary << endl;
                found = true;
            }
        }
    } else if (field==3) {
        double sal;
        cout<< "Введите зарплату: ";
        cin>>sal;

        if (cin.fail()) {
            clearInput();
            return;
        }

        for (int i = 0; i < db.size(); i++) {
            if (db[i].salary == sal) {
                cout << db[i].name <<" "
                     << db[i].age <<" "
                     << db[i].salary <<endl;
                found=true;
            }
        }
    } else {
        cout<< "Неверный выбор поля" <<endl;
        return;
    }

    if (!found)
        cout<< "Ничего не найдено" <<endl;
}

void sortByField(vector<User>& db) {
    if (db.size()==0) {
        cout<< "База пуста" <<endl;
        return;
    }

    cout<< "По какому полю сортировать?" <<endl;
    cout<< "1) Имя" <<endl;
    cout<< "2) Возраст" <<endl;
    cout<< "3) Зарплата" <<endl;

    int field;
    cout<< "Выбор: ";
    cin>>field;

    if (cin.fail()) {
        clearInput();
        cout<< "Ошибка ввода" <<endl;
        return;
    }

    for (int i = 0; i < db.size(); i++) {
        for (int j = i + 1; j < db.size(); j++) {
            bool needSwap = false;

            if (field==1 && db[i].name>db[j].name) needSwap = true;
            if (field==2 && db[i].age>db[j].age) needSwap = true;
            if (field==3 && db[i].salary>db[j].salary) needSwap = true;

            if (needSwap) {
                User tmp=db[i];
                db[i]=db[j];
                db[j]=tmp;
            }
        }
    }

    cout<< "Отсортировано" <<endl;
}
