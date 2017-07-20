#include <Poco/URI.h>
#include <iostream>
using namespace std;
#include "remove_dot.h"

string remove_dot(string uri){
	//string uri = "http://ynet.co.il.//articles//0,7340,L-4715257,00.html.";
	//cout << uri[uri.length()-1] << endl;
	string host="";
	string path="";

	if( ! uri.empty()){
	int last_char_uri=uri.length()-1;
	if( uri[last_char_uri]=='.' || uri[last_char_uri]=='%' ){
		uri.erase(last_char_uri,1);
	}
	Poco::URI uri1("http://"+uri);
	uri1.normalize();
	host=uri1.getAuthority();
	path=uri1.getPathAndQuery();

	int last_char_host=host.length()-1;
	if(!host.empty()  && host[last_char_host]=='.'){
		host.erase(last_char_host,1);
	}
	}
	
	//cout << host << endl;
	//cout << path << endl;
	
	//uri1.~URI();
return host+path;
}
