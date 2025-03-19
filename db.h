#ifndef DB_H
#define DB_H

#include <iostream>
#include <string>
#include <stdexcept>

class Database{
    private: 
        //member variable "db" is of string type
        //ToDo
        std::string db; 

        //member variable "username" is of string type
        //ToDo
        std::string username; 

        //member variable "password" is of string type
        //ToDo
        std::string password; 

        //member variable "connected" is of boolean type
        //The "connected" is set to false initially.
        //ToDo
        bool connected{false}; 

        //member variable "instance" is static 
        //"instance" (pointer to Database) is a staic variable that stores the instance of the database. Its value is set in the function "getInstance"
        //ToDo
        static Database* instance; 

        //constructor that helps creating instance of db(e.g. sales.db) accepts name of the database, username, password. 
        //ToDo
        Database(const std::string& dname, const std::string& uname, const std::string& pword) 
        : db{dname}, username{uname}, password{pword} {} 

        //destructor that disconnects the connection if connected.
        //ToDo
        ~Database() {
            if(connected) {
                disconnect(); 
            } 
        } 

    public: 
        //"getInstance" that creates and returns the instance of the database (Database*). If called first time it sets the username and password. However, subsequent time, it matches the database name, username and password and returns the previous instance if matched else it throws std::runtime_error("invalid database name, username or password"). We are using Singleton Design Pattern that creates only one instance of the databse. The instance is still created by the constructor.
        //ToDo
        static Database* getInstance(const std::string& dname, const std::string& uname, const std::string& pword) {
            if(nullptr == instance) {
                instance = new Database(dname, uname, pword); 
            }
            else if(instance->db != dname || instance->username != uname || instance->password != pword) {
                throw std::runtime_error("invalid database name, username or password"); 
            }
            
            return instance; 
        }

        //"connect" that sets "connected" to true (return void)
        //ToDo
        void connect() {
            if(!connected) {
                connected = true; 
            }
        }
        
        //"disconnect" that sets "connected" to false (return void)
        //ToDo
        void disconnect() {
            if(connected) {
                connected = false; 
            }        
        }

        // return status of connected true/false (return bool)
        //ToDo
        bool isConnected() const {
            return connected; 
        }

        //overload the new operator that allocates memory using malloc of given size and returns pointer of type void and prints " overloaded new " (cout is okay in this case). std::cout << "overloaded new ";
        //If the memory allocation fails it should throw std::bad_alloc()
        //ToDo
        void* operator new(size_t size) {
            void* ptr = malloc(size); 
            if(!ptr) {
                throw std::bad_alloc(); 
            }
            std::cout << " overloaded new "; 
            return ptr; 
        }
        
        //overload the delete operator that deallocates memory and prints "overloaded delete " (cout is okay in this). std::cout << "overloaded delete ";
        //ToDo
        void operator delete(void* ptr) {
            free(ptr); 
            std::cout << "overloaded delete"; 
        }

        //set_username and get_username for username
        //ToDo
        //ToDo
        void set_username(const std::string& uname) {
            username = uname; 
        }

        std::string get_username() {
            return username; 
        }

        //set_password and get_password for password.
        //ToDo
        //ToDo
        void set_password(const std::string& pword) {
            password= pword; 
        }

        std::string get_password() {
            return password; 
        }
        //The static "resetInstance" as defined below.
        static void resetInstance();
};


#endif