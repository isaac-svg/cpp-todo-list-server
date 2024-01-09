#pragma once

#include "../../lib/httplib.h"
#include "../../lib/json.hpp"
#include "../../resource/global.h"

void handleDelete(const httplib::Request &req, httplib::Response &res);