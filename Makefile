all:	poco_uri_normal.cpp remove_dot.cpp
	g++ -o poco_uri_normal poco_uri_normal.cpp remove_dot.cpp -L/usr/local/lib -lPocoNet -lPocoFoundation
