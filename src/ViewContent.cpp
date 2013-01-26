
// Includes
#include "ViewContent.h"

// Namespaces
using namespace ViewContent;
using namespace std;

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

	// FIXME: All months with 31 days!!!
	day.add("Día");
	for (int i = 1; i < 31; i++) {
		stringstream stream;
		stream << i;
		day.add(stream.str());
	}

	month.add("Mes");
	month.add("Enero");
	month.add("Febrero");
	month.add("Marzo");
	month.add("Abril");
	month.add("Mayo");
	month.add("Junio");
	month.add("Julio");
	month.add("Agosto");
	month.add("Septiembre");
	month.add("Octubre");
	month.add("Noviembre");
	month.add("Diciembre");

	int current_year = 2013; // TODO: auto calculate it
	int oldest_year = 2013 - 121;
	year.add("Año");
	for (int i = current_year; i > oldest_year; i--) {
		stringstream stream;
		stream << i;
		year.add(stream.str());
	}

	genre.add("Mujer");
	genre.add("Hombre");
	submit.value("Registrar");

	add(first_name);
	add(last_name);
	add(user_name);
	add(email);
	add(password);
	add(password_verification);
	add(day);
	add(month);
	add(year);
	add(genre);
	add(submit);
}
