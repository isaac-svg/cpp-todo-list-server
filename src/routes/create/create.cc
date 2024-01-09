#include "./create.hpp"
#include <iostream>

/**
 * handleCreateTodo - creates a todo list item
 * @req: Request Object
 * @res: Response Object
 * Return: void
 * 
 * (Description)
 * Takes a todo item from the client adds an id to it and then appends it to the db
*/
void handleCreateTodo(const httplib::Request& req, httplib::Response& res){

    // Get the body as a string
    std::string  new_task = req.body;
    const int NewCount = TODOCOUNT++;
    
    if (NewCount > 0){
        TODOS.insert((TODOS.begin()+(TODOS.find_last_of('}') + 1)), 1, ',');
        
    }
    json jsonData ={
        {"id",std::to_string(NewCount)},
        {"todo", new_task}
    };

    std::stringstream ss;
    ss << jsonData;
    // remove the the last ]
    TODOS.pop_back();

    TODOS.append(ss.rdbuf()->str());
    TODOS.append(" ]");

    
    
    

    res.set_content(TODOS, "text/plain");
}