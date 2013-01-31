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

	content.name("pci_text_editor");

	submit.attributes_string("class='submit'");

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

	content.name("pci_text_editor");

	submit.attributes_string("class='submit'");

	add(description);
	add(content);
	add(is_anonymous);
	add(submit);
}

SignInFormInfo::SignInFormInfo() {
	password.name("password");

	user_name.attributes_string(
			"class='pci_textfield pci_textfield_sign_in required' id='pci_textfield_sign_in_user_name'");
	password.attributes_string(
			"class='pci_textfield pci_textfield_sign_in required' id='pci_textfield_sign_in_password'");

	submit.attributes_string("class='submit'");
	submit.value("Ingresar");

	add(user_name);
	add(password);
	add(submit);
}

SignUpFormInfo::SignUpFormInfo() {

	password.name("password");
	password_verification.name("password_verification");

	first_name.attributes_string(
			"class='pci_textfield pci_textfield_sign_up required' id='pci_textfield_sign_up_first_name'");
	last_name.attributes_string(
			"class='pci_textfield pci_textfield_sign_up required' id='pci_textfield_sign_up_last_name'");
	user_name.attributes_string(
			"class='pci_textfield pci_textfield_sign_up required' id='pci_textfield_sign_up_user_name'");
	email.attributes_string(
			"class='pci_textfield pci_textfield_sign_up required email' id='pci_textfield_sign_up_email'");
	password.attributes_string(
			"class='pci_textfield pci_textfield_sign_up required' id='pci_textfield_sign_up_password'");
	password_verification.attributes_string(
			"class='pci_textfield pci_textfield_sign_up required' id='pci_textfield_sign_up_password_verification'");
	date.attributes_string(
			"class='pci_textfield pci_textfield_sign_up required' id='pci_textfield_sign_up_date' readonly");
	genre.attributes_string(
			"class='pci_dropdownlist pci_dropdownlist_sign_up' id='pci_dropdownlist_sign_up_genre'");
	submit.attributes_string("class='submit'");

	genre.add("Seleccione el sexo", "U");
	genre.add("Mujer", "F");
	genre.add("Hombre", "M");

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
