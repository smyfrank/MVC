#include "demo_v1_User.h"
using namespace demo::v1;
//add definition of your processing function here

void User::login(const HttpRequestPtr &req,
                 std::function<void (const HttpResponsePtr &)> &&callback,
                 std::string &&userId,
                 const std::string &password)
{
    LOG_DEBUG<<"User " << userId << " Login";
    //认证算法，读数据库，验证身份等...
    Json::Value ret;
    ret["result"] = "ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp= HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
void User::getInfo(const HttpRequestPtr &req, std::function<void(const HttpRequestPtr &)> &&callback,
                   std::string userId, const std::string &token) const {
    LOG_DEBUG << "User " << userId <<" get his information";
    // 验证token有效性等
    // 读取数据库或缓存获取用户信息
    Json::Value ret;
    ret["result"] = "ok";
    ret["user_name"] = "Jack";
    ret["user_id"] = userId;
    ret["gender"] = 1;
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
