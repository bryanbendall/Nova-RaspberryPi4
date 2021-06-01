#include "wificontroller.h"

WifiController::WifiController(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void WifiController::service(HttpRequest &request, HttpResponse &response) {

    QByteArray path=request.getPath();

    if (path=="/" || path=="/hello") {

        response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
        response.write("<html><body>");

        response.write("<a href=\"http://localhost:8080/list\"");
        response.write("<button>");
        response.write("Test Button");
        response.write("</button");
        response.write("</a");

        response.write("<br>");
        response.write("<button>");
        response.write("Test Button");
        response.write("</button");

        response.write("<br>");
        response.write("<button style=\"background-color:#AAAAAA;\">");
        response.write("Test Button");
        response.write("</button");

        response.write("</body></html>",true);


        //response.write("Hello World",true);
    }
    else if (path=="/list") {
        response.write("List",true);
    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.",true);
    }

}
