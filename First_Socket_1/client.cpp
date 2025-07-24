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

//客户端socket
int create_tcp_socket() {
    boost::asio::io_context ios;

    boost::asio::ip::tcp protocol=boost::asio::ip::tcp::v4();

    boost::asio::ip::tcp::socket sock(ios);
    boost::system::error_code ec;

    sock.open(protocol,ec);

    if (ec.value()!=0) {
        cout<<"failed to open socket error code: "<<ec.value()<<".message"
        <<ec.message()<<endl;
        return ec.value();
    }

    return 0;

}

int create_acceptor_socket() {
    boost::asio::io_context ioc;

    boost::asio::ip::tcp protocol=boost::asio::ip::tcp::v4();
    boost::asio::ip::tcp::acceptor acceptor(ioc);

    boost::system::error_code ec;

    acceptor.open(protocol,ec);

    if (ec.value()!=0) {
        cout<<"failed to open socket error code: "<<ec.value()<<".message"
        <<ec.message()<<endl;
        return ec.value();
    }

    return 0;

}

int bind_acceptor_socket() {
    unsigned short port_num=3333;

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address_v4::any(),port_num);

    boost::asio::io_context ioc;

    boost::asio::ip::tcp::acceptor acceptor(ioc,endpoint.protocol());

    boost::system::error_code ec;

    acceptor.bind(endpoint,ec);

    if (ec.value()!=0) {
        cout<<"failed to bind socket error code: "<<ec.value()<<".message"
        <<ec.message()<<endl;
        return ec.value();
    }

    return 0;
}

int connect_to_end() {
    string ip="127.0.0.1";
    unsigned short port=8080;

    try {
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(ip),port);

        boost::asio::io_context ioc;

        boost::asio::ip::tcp::socket sock(ioc,endpoint.protocol());

        sock.connect(endpoint);

    }catch(...) {
        cout<<"failed to connect";
    }
}

int accept_new_connection() {
    const int sizecode=30;

    unsigned short port_num=3333;

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address_v4::any(),port_num);

    boost::asio::io_context ioc;

    try {

        boost::asio::ip::tcp::acceptor acceptor(ioc,endpoint.protocol());

        acceptor.bind(endpoint);

        acceptor.listen(sizecode);

        boost::asio::ip::tcp::socket sock(ioc);

        acceptor.accept(sock);
    }catch(...) {

    }
}