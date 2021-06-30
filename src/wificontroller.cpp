#include "wificontroller.h"

WifiController::WifiController(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void WifiController::service(HttpRequest &request, HttpResponse &response) {

    QByteArray path=request.getPath();

    if (path=="/" || path=="/unlock" || path=="/lock") {

        response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
        response.write("<html><body style=\"background-color:rgb(34, 34, 34)\";>");

        response.write(R"(
                       <style>
                           .button {
                             display: block;
                             margin-left: 10%;
                             width: 35%;
                             height: 80px;
                             background-color: rgb(85, 85, 85);
                             color: snow;
                             border-radius: 20px;
                             float: left;
                             font-size: 20px;
                             border: 2px solid #4CAF50; /* Green */
                             box-shadow: 0 8px 16px 0 rgba(0, 0, 0, 0.548), 0 6px 20px 0 rgba(0, 0, 0, 0.541);
                           }
                           .button:active{
                               background-color: steelblue;
                           }
                           .title{
                               color: snow;
                               margin: 20px;
                               font-size: 100px;
                               font-weight: bolder;
                               text-align: center;
                               font-family: Impact, Haettenschweiler, 'Arial Narrow Bold', sans-serif;
                           }
                       </style>

                   <p class="title">Brytec</p>

                   <a href="http://localhost:8080/unlock">
                   <button class="button">
                       Unlock
                   </button>
                   </a>

                   <a href="http://localhost:8080/lock">
                   <button class="button">
                       Lock
                   </button>
                   </a>

                       )");

        response.write("</body></html>",true);

    }
    else if (path=="/list") {
        response.write("List",true);
    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.",true);
    }

}
