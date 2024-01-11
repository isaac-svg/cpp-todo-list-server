#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "./src/lib/json.hpp"
#include "./src/lib/httplib.h"


using json = nlohmann::json;

std::string deleteTodo(const std::string& todos, const std::string& id) {
    try {
        json jsonData = json::parse(todos);

        auto& array = jsonData;
        auto it = std::remove_if(array.begin(), array.end(), [&id](const json& data) {
            return data["id"] == id;
        });

        array.erase(it, array.end());

        return jsonData.dump();
    } catch (const std::exception& e) {
        // Log or handle the exception as needed
        std::cerr << "Error parsing or updating TODOS: " << e.what() << std::endl;
        return todos;  // Return the original todos in case of an error
    }
}

int main() {
    std::string TODOS = R"([{"id":"0", "todo":"hello0"},{"id":"1", "todo":"hello1"},{"id":"2", "todo":"hello2"}])";
    std::string idToDelete = "1";

    std::string updatedTodos = deleteTodo(TODOS, idToDelete);

    std::cout << "Updated TODOS:\n" << updatedTodos << std::endl;

    return 0;
}
