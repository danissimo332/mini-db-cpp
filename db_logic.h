#ifndef DB_LOGIC_H
#define DB_LOGIC_H
#include <string>
#include <vector>

struct User{
    std::string name;
    int age;
    double salary;
};

void addUser(std::vector<User>& db);
void showUsers(const std::vector<User>& db);
void deleteUser(std::vector<User>& db);
void searchByField(const std::vector<User>& db);
void sortByField(std::vector<User>& db);

#endif
