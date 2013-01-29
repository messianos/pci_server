
// Includes
#include "ErrorCode.h"

// Namespaces
using namespace std;

// Initializations
const string ErrorCode::ERROR_DESCRIPTIONS[] = {
	"No se produjo ningun error",
	"Nombre de usuario o password invalido",
	"Completar el campo de la descripción",
	"Completar el campo de contenido",
	"Campo de usuario vacio",
	"Campo de contraseña vacio",
	"Nombre de usuario muy corto",
	"Contraseña muy corta,debe tener más de 6 caracteres o números",
	"Apellido muy corto",
	"Email invalido",
	"La contraseña ingresada no es la misma que la de la verificación"
	// TODO: completar las descripciones
};
const short int ErrorCode::CODE_NONE = 0;
const short int ErrorCode::CODE_INVALID_SIGN_IN = 1;
const short int ErrorCode::CODE_SHORT_DESCRIPTION = 2;
const short int ErrorCode::CODE_SHORT_CONTENT = 3;
const short int ErrorCode::CODE_VOID_USERNAME_FIELD = 4;
const short int ErrorCode::CODE_VOID_PASSWORD_FIELD = 5;
const short int ErrorCode::CODE_SHORT_USERNAME = 6;
const short int ErrorCode::CODE_SHORT_PASSWORD = 7;
const short int ErrorCode::CODE_SHORT_LASTNAME = 8;
const short int ErrorCode::CODE_EMAIL_INVALID = 9;
const short int ErrorCode::CODE_INVALID_PASSWORD_VERIFICATION = 10;
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
