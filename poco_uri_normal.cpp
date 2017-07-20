#include <Poco/URI.h>
#include "Poco/Exception.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

#include "remove_dot.h"

extern char *optarg;

int main(int argc, char **argv){
	string inputFile="";
	string outputFile="";
	char opt;
	while((opt = getopt(argc, argv, "-i:-o:")) != -1) {
		switch(opt){
		case 'i':
			inputFile=optarg;
			break;
		case 'o':
			outputFile=optarg;
			break;
			}
	}
	if( outputFile.empty() || inputFile.empty()){
		cerr << "Usage: poco_uri_normal -i InputFile -o OutputFile" << endl;
		return 1;
	}
	string line;
	int i=0;
	ifstream urls_in (inputFile.c_str());
	ofstream urls_out (outputFile.c_str());
	if (urls_in.is_open()){
	while ( getline (urls_in,line) ){
			//cout << line << '\n';
		try{
			urls_out << remove_dot(line) << endl;
			i++;
			//cout << i << endl;
		} catch( Poco::URISyntaxException& exc ) { 
			cout << line << exc.displayText() << endl; }
	}
	urls_in.close();
	urls_out.close();
	} else cout << "Unable to open file";
	cout << "Count lines " << i << endl;
return 0;
}
