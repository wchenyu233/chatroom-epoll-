all: test_server.cpp server.cpp server.h test_client.cpp client.cpp client.h global.h
	g++ -o test_client test_client.cpp client.cpp -lpthread -lboost_system
	g++ -o test_server test_server.cpp server.cpp -lboost_system -lpthread -lboost_filesystem -lboost_thread -lmysqlclient -lhiredis