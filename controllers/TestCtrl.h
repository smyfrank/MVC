#pragma once
#include <drogon/HttpSimpleController.h>
#include "../models/Students.h"
using namespace drogon;
class TestCtrl:public drogon::HttpSimpleController<TestCtrl>
{
  public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/test",Get, "TimeFilter");
    //list path definitions here;
    //PATH_ADD("/path","filter1","filter2",HttpMethod1,HttpMethod2...);
    PATH_LIST_END
};
