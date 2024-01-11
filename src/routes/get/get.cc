#include "get.hpp"


void getTodos(const httplib::Request &req, httplib::Response &res)
{
    std::ifstream db_file("todos.json");
   if (db_file.is_open()) {
        std::stringstream buffer;
        buffer << db_file.rdbuf();
        db_file.close();
std::cout << "GET\n";
        res.set_content(buffer.str(), "application/json");
    } else {
        res.set_content("Unable to open todos.json", "text/plain");
    }
}