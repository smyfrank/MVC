#include "TestCtrl.h"
void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    //write your application logic here
    auto resp = HttpResponse::newHttpResponse();
    auto clientPtr = drogon::app().getDbClient();
    clientPtr->execSqlAsync("select * from students where student_id=1971653",
                            [](const Result &r) {
                                std::cout << r.size() << " rows selected!" << std::endl;
                                int i = 0;
                                for (auto row : r)
                                {
                                    std::cout << "query by dbClient" << ": student name is " << row["identity_number"].as<std::string>() << std::endl;
                                }
                            },
                            [](const DrogonDbException &e) {
                                std::cerr << "error:" << e.base().what() << std::endl;
                            },
                            "default");

    Mapper<drogon_model::DAC::Students> mp(clientPtr);
    auto stuInfo = mp.findBy(Criteria(drogon_model::DAC::Students::Cols::_student_id, CompareOperator::EQ, 1971653));
    for(auto i : stuInfo) {
        std::cout << "query from model" << i.getValueOfIdentityNumber() << std::endl;
    }

    resp->setBody("<p>Hello, world!</p>");
    resp->setExpiredTime(0);
    callback(resp);
}