#include "wificontroller.h"
#include <QThread>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRandomGenerator>

WifiController::WifiController(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void WifiController::service(HttpRequest &request, HttpResponse &response) {

    qDebug()<< "Http Server start" << endl;
    QByteArray path = request.getPath();
    QHostAddress peer = request.getPeerAddress();

    qDebug()<< "Path - " << path << endl;

    if(path == "/"){
        response.write(R"(
                       <!DOCTYPE html>
                       <html>
                           <body>
                           <h1>Getting server updates</h1>
                           <div id="result"></div>

                           <script>
                               if(typeof(EventSource) !== "undefined")
                               {
                                 var source = new EventSource("http://localhost:8080/data");
                                 source.onmessage = function(event)
                                 {
                                   document.getElementById("result").innerHTML = event.data + "<br>";
                                   var jsondata = JSON.parse(event.data)
                                   //console.log(jsondata);
                                 };
                               }
                               else
                               {
                                 document.getElementById("result").innerHTML = "Sorry, your browser does not support server-sent events...";
                               }
                           </script>

                           </body>
                       </html>
                       )", false);
    }

    else if(path == "/data" && request.getMethod() == "GET")
    {
        qDebug()<< "start /data request"<< endl;
        response.setHeader("Content-Type","text/event-stream;charset=utf-8");
        response.setHeader("Cache-Control","no-cache");
        response.setHeader("Connection","keep-alive");
        response.setHeader("Access-Control-Allow-Origin","*");   // also important , if not set , the html application wont run.

         while(response.isConnected())
         {
             //qDebug() << "connected" << endl;
             QThread::msleep(20);
             QJsonDocument tmp;
             QJsonObject data;

             data.insert("name","Adward");
             data.insert("age",QRandomGenerator::global()->bounded(100));
             data.insert("marriage",false);
             data.insert("Salary",QRandomGenerator::global()->bounded(20000.0));
             tmp.setObject(data);
             QByteArray jsondata = tmp.toJson(QJsonDocument::Compact);

             response.write("data:" + jsondata + "\n\n");
             response.flush();
         }
         qDebug()<< "End Transport"<< endl;
    }
    else if(path == "/button"){
        qDebug() << "Button Clicked!!";
    }
    else
    {
        response.setStatus(404, "Not found");
        response.write("The URL is wrong, no such document",true);

    }

    /*
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
                             border: 2px solid #4CAF50;
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
*/
}
