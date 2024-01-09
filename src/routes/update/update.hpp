#pragma once

#include "../../lib/httplib.h"
#include "../../lib/json.hpp"


void handleUpdate(const httplib::Request &req, httplib::Response &res);