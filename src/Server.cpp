
// Includes
#include "Server.h"

// Namespaces
using namespace ViewContent;

Server::Server(cppcms::service &service) {
	dispatcher().assign("", &Server::welcome, this);
	mapper().assign("");

	mapper().root("/pci");
}

Server::~Server() {}

void Server::welcome() {
	testContent content;
	content.text = "Esto es un texto de prueba";
	render("welcome", content);
}
