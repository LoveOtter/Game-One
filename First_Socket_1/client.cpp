//
// Created by zhanglian1314666 on 2025/7/23.
//
#include <iostream>
#include <boost/asio.hpp>
using namespace std;


int client_end_point() {
    string ip="127.0.0.1";
    unsigned short port=8080;

    boost::system::error_code ec;

    boost::asio::ip::address ip_address=boost::asio::ip::address::from_string(ip,ec);

    if (ec.value()!=0) {
        cout<<"failed to parse the ip address error code: "<<ec.value()<<".message"
        <<ec.message()<<endl;
        return ec.value();
    }

    boost::asio::ip::tcp::endpoint ep(ip_address,port);  //绑定ip 和端口

    return 0;
}

int create_tcp_socket() {
    boost::asio::io_context ios;

    boost::asio::ip::tcp protocol=boost::asio::ip::tcp::v4();

    boost::asio::ip::tcp::socket sock(ios);
    boost::system::error_code ec;

    sock.open(protocol,ec);

}