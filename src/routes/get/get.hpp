#pragma once

#include "../../lib/httplib.h"
#include "../../lib/json.hpp"
#include "../../resource/global.h"
#include <fstream>

void getTodo(const httplib::Request &req, httplib::Response &res);
void getTodos(const httplib::Request &req, httplib::Response &res);

