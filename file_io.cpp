#include "file_io.h"
#include <fstream>
#include <iostream>

using namespace std;

bool saveToFile(const vector<User>& db, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout<< "Ошибка: не удалось открыть файл для записи" <<endl;
        return false;
    }

    for (int i = 0; i < db.size(); i++) {
        file << db[i].name <<" "
             << db[i].age <<" "
             << db[i].salary <<endl;
    }

    file.close();
    cout<< "Сохранено в файл: " <<filename<<endl;
    return true;
}

bool loadFromFile(vector<User>& db, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout<< "Ошибка: файл не найден" <<endl;
        return false;
    }

    db.clear();
    User u;

    while (file>>u.name>>u.age>>u.salary) {
        db.push_back(u);
    }

    file.close();
    cout<< "Загружено из файла: " <<filename<<endl;
    return true;
}
