

#include <iostream>
#include <string>
#include "./src/lib/json.hpp"
using json = nlohmann::json;

int main(){

static int count = 0;
   json jsonData ={
        {"id",std::to_string(count++)},
        {"todo", "I am new"}
    };

    std::stringstream ss;
    ss << jsonData;
std::string data =  R"([{"id":"0", "todo":"hello0"},{"id":"1", "todo":"hello1"},{"id":"2", "todo":"hello2"}, ])";
data.pop_back();
std::string newdata = ss.rdbuf()->str();
data += newdata;
data.append(", ]");
std::cout << data;

    return (0);
}