// db.cpp
#include "db.h"

// initialize the instance variable
Database* Database::instance = nullptr; 

void Database::resetInstance() {
    if(instance != nullptr) {
        delete instance; 
        instance = nullptr; 
    }
}