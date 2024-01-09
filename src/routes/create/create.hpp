#pragma once

#include "../../lib/json.hpp"
#include "../../lib/httplib.h"
#include "../../resource/global.h"
#include <fstream>
#include <string>

using json = nlohmann::json;

void handleCreateTodo(const httplib::Request& req, httplib::Response& res);