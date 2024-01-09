#include "get.hpp"


void getTodos(const httplib::Request &req, httplib::Response &res)
{
    res.set_content(TODOS, "text/plain");
}