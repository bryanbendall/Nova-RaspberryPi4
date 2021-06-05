#ifndef WIFICONTROLLER_H
#define WIFICONTROLLER_H

#include "httprequesthandler.h"
using namespace stefanfrings;

class WifiController : public HttpRequestHandler
{
    Q_OBJECT

public:
    WifiController(QObject* parent = nullptr);
    void service(HttpRequest& request, HttpResponse& response);

};

#endif // WIFICONTROLLER_H
