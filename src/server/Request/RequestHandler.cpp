/**
 * @file RequestHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//************************LOCAL****************************
#include "RequestHandler.h"
#include "../../debug/debug.h"
#include "include/Method.h"

#include "Methods/GET/GET.h"
#include "Methods/DELETE/DELETE.h"
#include "Methods/POST/POST.h"
#include "Methods/PUT/PUT.h"

#include "RequestObject/ModelRequest/ModelRequest.h"

//**************************POCO**************************
#include "Poco/Net/HTMLForm.h"
#include "Poco/JSON/Stringifier.h"
#include <Poco/StreamCopier.h>
#include <Poco/Util/Application.h>
#include <Poco/Net/NameValueCollection.h>

#include <iostream>
#include <sstream>
#include <fstream>

//TODO  удалить //*****************TEMP******************
#include "RequestObject/ModelRequest/ModelRequest.h"

RequestHendler::    RequestHendler(const std::string &html_requestt):prvt_html_requestt(html_requestt)
{
    this->get_method_p      = new Get();
    this->delete_method_p   = new Delete();
    this->post_method_p     = new Post();
    this->put_method_p      = new Put();
}

void RequestHendler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    Poco::Util::Application& app = Poco::Util::Application::instance();
	app.logger().information("Request from " + request.clientAddress().toString());

    response.setChunkedTransferEncoding(true);

    response.setContentType("text/html");
    
    std::ostream& ostr = response.send();

    switch (string_to_enum(REST_METHOD, request.getMethod().c_str()))
    {
        case REST_METHOD::GET:{    }break;
        
        case REST_METHOD::POST: { this->post_handl(request); }break;

        case REST_METHOD::PUT:{     }break;

        case REST_METHOD::DELETE:{      }break;

        default:
        {    //TODO кинуть ошибку клиенту
        }   break;
    }

    ostr <<"succes \n";


    
}



void RequestHendler::post_handl(Poco::Net::HTTPServerRequest &request)
{
    
    Poco::Net::HTMLForm form(request, request.stream(), *this->post_method_p);
    this->post_method_p->send_to(new ModelRequest);
    
    
}


RequestHendler::~RequestHendler(){
    if(this->get_method_p)
        delete this->get_method_p;

    if(this->delete_method_p)
        delete this->delete_method_p;

    if(this->post_method_p)
        delete this->post_method_p;

    if(this->put_method_p)
        delete this->put_method_p;
}









// class MyPartHandler: public Poco::Net::PartHandler
// {
// public:
// 	MyPartHandler():
// 		_length(0)
// 	{
// 	}
	
// 	void handlePart(const MessageHeader& header, std::istream& stream)
// 	{
// 		_type = header.get("Content-Type", "(unspecified)");
// 		if (header.has("Content-Disposition"))
// 		{
// 			std::string disp;
// 			NameValueCollection params;
// 			MessageHeader::splitParameters(header["Content-Disposition"], disp, params);
// 			_name = params.get("name", "(unnamed)");
// 			_fileName = params.get("filename", "(unnamed)");
// 		}
// 		std::ofstream fout;
//         fout.open("file.biny");
// 		CountingInputStream istr(stream);
// 		NullOutputStream ostr;
// 		StreamCopier::copyStream(istr, fout);
// 		_length = istr.chars();
//         fout.close();
// 	}
	
// 	int length() const
// 	{
// 		return _length;
// 	}
	
// 	const std::string& name() const
// 	{
// 		return _name;
// 	}
// 	const std::string& fileName() const
// 	{
// 		return _fileName;
// 	}
	
// 	const std::string& contentType() const
// 	{
// 		return _type;
// 	}
	
// private:
// 	int _length;
// 	std::string _type;
// 	std::string _name;
// 	std::string _fileName;
// };








// RequestHendler::    RequestHendler(const std::string &html_requestt):prvt_html_requestt(html_requestt)
// {
//     this->get_method_p      = new Get();
//     this->delete_method_p   = new Delete();
//     this->post_method_p     = new Post();
//     this->put_method_p      = new Put();
// }




// void RequestHendler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
// {
    
// 		Application& app = Application::instance();
// 		app.logger().information("Request from " + request.clientAddress().toString());
// 		MyPartHandler partHandler;
// 		HTMLForm form(request, request.stream(), partHandler);
// 		response.setChunkedTransferEncoding(true);
// 		response.setContentType("text/html");
// 		std::ostream& ostr = response.send();
		
// 		ostr <<
// 			"<html>\n"
// 			"<head>\n"
// 			"<title>POCO Form Server Sample</title>\n"
// 			"</head>\n"
// 			"<body>\n"
// 			"<h1>POCO Form Server Sample</h1>\n"
// 			"<h2>GET Form</h2>\n"
// 			"<form method=\"GET\" action=\"/form\">\n"
// 			"<input type=\"text\" name=\"text\" size=\"31\">\n"
// 			"<input type=\"submit\" value=\"GET\">\n"
// 			"</form>\n"
// 			"<h2>POST Form</h2>\n"
// 			"<form method=\"POST\" action=\"/form\">\n"
// 			"<input type=\"text\" name=\"text\" size=\"31\">\n"
// 			"<input type=\"submit\" value=\"POST\">\n"
// 			"</form>\n"
// 			"<h2>File Upload</h2>\n"
// 			"<form method=\"POST\" action=\"/form\" enctype=\"multipart/form-data\">\n"
// 			"<input type=\"file\" name=\"file\" size=\"31\"> \n"
// 			"<input type=\"submit\" value=\"Upload\">\n"
// 			"</form>\n";
			
// 		ostr << "<h2>Request</h2><p>\n";
// 		ostr << "Method: " << request.getMethod() << "<br>\n";
// 		ostr << "URI: " << request.getURI() << "<br>\n";
// 		NameValueCollection::ConstIterator it = request.begin();
// 		NameValueCollection::ConstIterator end = request.end();
// 		for (; it != end; ++it)
// 		{
// 			ostr << it->first << ": " << it->second << "<br>\n";
// 		}
// 		ostr << "</p>";
// 		if (!form.empty())
// 		{
// 			ostr << "<h2>Form</h2><p>\n";
// 			it = form.begin();
// 			end = form.end();
// 			for (; it != end; ++it)
// 			{
// 				ostr << it->first << ": " << it->second << "<br>\n";
// 			}
// 			ostr << "</p>";
// 		}
		
// 		if (!partHandler.name().empty())
// 		{
// 			ostr << "<h2>Upload</h2><p>\n";
// 			ostr << "Name: " << partHandler.name() << "<br>\n";
// 			ostr << "File Name: " << partHandler.fileName() << "<br>\n";
// 			ostr << "Type: " << partHandler.contentType() << "<br>\n";
// 			ostr << "Size: " << partHandler.length() << "<br>\n";
// 			ostr << "</p>";
// 		}t
// 		ostr << "</body>\n";
// 	}

