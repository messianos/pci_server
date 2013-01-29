// Includes
#include "ViewContent.h"

// Namespaces
using namespace ViewContent;
using namespace std;

TemplateContent::TemplateContent() {
	user_signed_in = false;
}

NewProblemFormInfo::NewProblemFormInfo() {
	description.message("Breve descripción");
	content.message("Contenido");
	is_anonymous.message("Publicar anónimamente");
	submit.value("Publicar");

	add(description);
	add(content);
	add(is_anonymous);
	add(submit);
}

NewSolutionFormInfo::NewSolutionFormInfo() {
	description.message("Breve descripción");
	content.message("Contenido");
	is_anonymous.message("Publicar anónimamente");
	submit.value("Publicar");

	add(description);
	add(content);
	add(is_anonymous);
	add(submit);
}

SignInFormInfo::SignInFormInfo() {
	user_name.message("Nombre de usuario");
	password.message("Contraseña");
	submit.value("Ingresar");

	add(user_name);
	add(password);
	add(submit);
}

SignUpFormInfo::SignUpFormInfo() {

	first_name.message("Nombre");
	last_name.message("Apellido");
	user_name.message("Nombre de usuario");
	email.message("E-mail");
	password.message("Contraseña");
	password_verification.message("Repita la contraseña");

	date.message("Nacimiento");
	date.id("datepicker");
	date.attributes_string("readonly = 'true'");

	genre.add("Mujer");
	genre.add("Hombre");
	submit.value("Registrar");

	add(first_name);
	add(last_name);
	add(user_name);
	add(email);
	add(password);
	add(password_verification);
	add(date);
	add(genre);
	add(submit);
}
