#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <string>
#include "db_logic.h"

bool saveToFile(const std::vector<User>& db, const std::string& filename);
bool loadFromFile(std::vector<User>& db, const std::string& filename);

#endif
