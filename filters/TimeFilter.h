/**
 *
 *  TimeFilter.h
 *  return false if the last visiting time of client is in 10 seconds, else return ok
 */

#pragma once
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <drogon/HttpFilter.h>

#define VDate "visitDate"
using namespace drogon;


class TimeFilter : public HttpFilter<TimeFilter>
{
  public:
    TimeFilter() {}
    virtual void doFilter(const HttpRequestPtr &req,
                          FilterCallback &&fcb,
                          FilterChainCallback &&fccb) override;
};

