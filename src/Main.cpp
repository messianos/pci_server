
// Includes
#include "Main.h"

// Namespaces
using namespace cppcms;
using namespace std;

int main(int argc, char **argv) {
	try {
		service service(argc, argv);
		service.applications_pool().mount(applications_factory<Server>());
		cerr << "Server started!" << endl;
		service.run();

	} catch (exception const &e) {
		cerr << e.what() << endl;
	}
}
