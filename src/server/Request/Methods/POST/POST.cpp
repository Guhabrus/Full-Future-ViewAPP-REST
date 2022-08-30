/**
 * @file POST.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "POST.h"
#include <Poco/StreamCopier.h>
#include <Poco/Net/MessageHeader.h>
#include <Poco/NullStream.h>
#include <Poco/CountingStream.h>
#include <Poco/Net/NameValueCollection.h>
Post::Post():_length(0){

}



void Post::handlePart(const Poco::Net::MessageHeader& header, std::istream& stream)
{
    this->_type = header.get("Content-Type", "(unspecified)");
		if (header.has("Content-Disposition"))
		{
			std::string disp;
			Poco::Net::NameValueCollection params;
			Poco::Net::MessageHeader::splitParameters(header["Content-Disposition"], disp, params);
			_name = params.get("name", "(unnamed)");
			_fileName = params.get("filename", "(unnamed)");
		}
		
		Poco::CountingInputStream istr(stream);
		Poco::NullOutputStream ostr;
		Poco::StreamCopier::copyStream(istr, ostr);
		this->_length = istr.chars();
        
}



int Post::get_length(){
    return this->_length;
}

std::string Post::get_type(){
    return this->_type;
}

std::string Post::get_name(){
    return this->_name;
}

std::string Post::get_filename(){
    return this->_fileName;
}
