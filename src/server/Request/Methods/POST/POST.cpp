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

#include <fstream>


//****************************LOCAL****************************
#include "../../RequestObject/ObjectBase/ObjectBase.h"
#include "../../../../debug/debug.h"

Post::Post():_length(0){

}



void Post::handlePart(const Poco::Net::MessageHeader& header, std::istream& stream)
{
	
    this->_type   = header.get("Content-Type", "(unspecified)");

	if (header.has("Content-Disposition"))
	{
		std::string disp;
		Poco::Net::NameValueCollection params;
		Poco::Net::MessageHeader::splitParameters(header["Content-Disposition"], disp, params);
		this->_name 	= params.get("name", "(unnamed)");
		this->_fileName = params.get("filename", "(unnamed)");
		
		
	}
	Poco::CountingInputStream istr(stream);
	this->_length = istr.chars();
	print_debug("leng = %d\n", this->_length);
	// Poco::CountingInputStream istr(stream);
		

	char* buffer = new char [1024];
	stream.read(buffer, sizeof(char) * 1024);





	// Poco::NullOutputStream ostr;
	// Poco::StreamCopier::copyStream(istr, is);
	
	


	delete buffer;
		
        
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


ERROR_HANDLER Post::send_to(ObjectBase* obj_p){
	
	if(!obj_p->send_request()){
		return ERROR_HANDLER::ERROR_SEND;
	}


	return ERROR_HANDLER::SUCCES;

	

}