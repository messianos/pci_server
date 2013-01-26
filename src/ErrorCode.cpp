
// Includes
#include "ErrorCode.h"

// Namespaces
using namespace std;

// Initializations
const string ErrorCode::ERROR_DESCRIPTIONS[] = {
	"No se produjo ningun error",
	"Nombre de usuario o password invalido"
	// TODO: completar las descripciones
};
const short int ErrorCode::CODE_NONE = 0;
const short int ErrorCode::CODE_INVALID_SIGN_IN = 1;
// TODO: completar esta lista

ErrorCode::ErrorCode(short int code) {
	this->code = code;
}

ErrorCode::~ErrorCode() {}

bool ErrorCode::isAnError() {
	return code != CODE_NONE;
}

string ErrorCode::getErrorDescription() {
	return ERROR_DESCRIPTIONS[code];
}
