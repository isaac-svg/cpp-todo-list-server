#include "delete.hpp"

using json = nlohmann::json;

void handleDelete(const httplib::Request &req, httplib::Response &res){
    std::multimap<std::string, std::string>  params = req.params;

    std::string id ="\0";

    for (auto &&data : params)
    {
        if (data.first == "id")
        {
            id = data.second;
            break;
        }
    }

    if (id == "\0")
    {
        res.set_content("Please specify the id in the params", "text/plain");
    }
    
    // update the TODOS now
    json jsonData;
  jsonData =  jsonData.parse(TODOS);

  auto array = jsonData.array();
  int count = 0;
  for (auto &&data : array)
  {
    if (data.dump(4,',', true) == id){
        array.erase(count);
    }
    ++count;
  }
  
  
    TODOS = jsonData.dump();

    res.set_content(TODOS, "text/plain");
}