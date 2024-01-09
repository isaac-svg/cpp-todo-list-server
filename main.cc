#include "./src/lib/httplib.h"
// #include "./src/routes/*/*.hpp"
#include "./src/routes/create/create.hpp"
#include "./src/routes/get/get.hpp"
#include "./src/routes/delete/delete.hpp"
#include <string>
using namespace std;
httplib::Server server;


int main(){

    // show the html page on the on "/"
    // serve the UI
    server.set_base_dir("./static");

    // route for creating a todo
    server.Post("/todo", handleCreateTodo);

    // get all the todos
    server.Get("/todos", getTodos);
    server.Delete("/:id", handleDelete);

    // start and listen to the server
    server.listen("localhost",3000);
    return (0);
}