#include "delete.hpp"
#include <filesystem>

using json = nlohmann::json;


void saveTodos(const json& todos) {
    // Write the updated todos back to the file
    std::ofstream outFile("todos.json");
    outFile << todos.dump(4);  // The '4' argument adds indentation for better readability
    outFile.close();
}

void handleDelete(const httplib::Request &req, httplib::Response &res){
   std::multimap<std::string, std::string> params = req.params;

    std::string id = req.path_params.at("id");

    if (id.empty()) {
        res.set_content("Please specify the id in the params", "text/plain");
        return; // return early if id is not specified
    }

    


  std::ifstream file("todos.json");
    json todos;
    file >> todos;
    file.close();

    // Find and remove the todo with the specified id
    auto it = std::remove_if(todos.begin(), todos.end(), [&id](const json& todo) {
        return todo["id"].get<std::string>() == id;
    });

    if (it != todos.end()) {
        todos.erase(it, todos.end());

        // Save the updated todos
        saveTodos(todos);

        res.set_content("Todo deleted successfully", "text/plain");
    } else {
        res.set_content("Todo not found", "text/plain");
    }
}



