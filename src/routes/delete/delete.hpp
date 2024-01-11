#pragma once

#include "../../lib/httplib.h"
#include "../../lib/json.hpp"
#include "../../resource/global.h"

void handleDelete(const httplib::Request &req, httplib::Response &res);

[[nodiscard]] std::string deleteTodo(const std::string& todos, const std::string& id);