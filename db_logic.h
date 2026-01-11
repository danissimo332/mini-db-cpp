#ifndef DB_LOGIC_H
#define DB_LOGIC_H
#include <string>
#include <vector>

//структура для хранения данных пользователя
struct User {
    std::string name;   // имя
    int age;            // возраст
    double salary;      // зарплата
};

void addUser(std::vector<User>& db);
void showUsers(const std::vector<User>& db);
void deleteUser(std::vector<User>& db);
void searchByField(const std::vector<User>& db);
void sortByField(std::vector<User>& db);

#endif
