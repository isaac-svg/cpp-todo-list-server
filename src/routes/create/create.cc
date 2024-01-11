#include "./create.hpp"
#include <iostream>
#include <fstream>

void handleCreateTodo(const httplib::Request& req, httplib::Response& res) {
    try {
        std::string TODOS_FILE_PATH = "todos.json";

        // Get the body as a string
        std::string new_task = req.body;
        const int NewCount = TODOCOUNT++;

        std::ifstream file(TODOS_FILE_PATH);

        if (file.is_open()) {
            json todos;
            file >> todos;
            file.close();

            std::cout << "Current todos size: " << todos.size() << std::endl;
            std::cout << "New task: " << new_task << std::endl;

            json jsonData = {
                {"id", todos.size()},
                {"todo", new_task}
            };

            todos.push_back({
                {"id", NewCount},
                {"todo", new_task}
            });

            std::cout << "Updated todos:\n" << todos.dump(4) << "\n";

            // Save the updated todos back to the file
            std::ofstream outFile(TODOS_FILE_PATH);

            if (outFile.is_open()) {
                outFile << todos.dump(4);  // The '4' argument adds indentation for better readability
                outFile.close();

                res.set_content(todos.dump(), "text/plain");
            } else {
                res.set_content("Unable to open file for writing", "text/plain");
            return;

            }
        } else {
            res.set_content("Unable to open file for reading", "text/plain");
            return;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        res.set_content(e.what(), "text/plain");
    }
}
