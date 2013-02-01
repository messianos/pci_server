
// Includes
#include "ViewContent.h"

// Namespaces
using namespace ViewContent;
using namespace std;

TemplateContent::TemplateContent() {
	user_signed_in = false;
}

NewProblemFormInfo::NewProblemFormInfo() {
	form_name.name("form_name");
	form_name.value("new_problem_form");

	description.message("Breve descripción");
	content.name("pci_texteditor");
	is_anonymous.message("Publicar anónimamente");
	submit.attributes_string("class='pci_submit'");
	submit.value("Publicar");

	add(form_name);
	add(description);
	add(content);
	add(is_anonymous);
	add(submit);
}

NewSolutionFormInfo::NewSolutionFormInfo() {
	form_name.name("form_name");
	form_name.value("new_solution_form");

	description.message("Breve descripción");
	content.name("pci_texteditor");
	is_anonymous.message("Publicar anónimamente");
	submit.attributes_string("class='pci_submit'");
	submit.value("Publicar");

	add(form_name);
	add(description);
	add(content);
	add(is_anonymous);
	add(submit);
}

SignInFormInfo::SignInFormInfo() {
	form_name.name("form_name");
	form_name.value("sign_in_form");
	user_name.attributes_string("class='pci_sign_in_textfield pci_textfield' id='pci_sign_in_textfield_user_name'");
	password.attributes_string("class='pci_sign_in_textfield pci_textfield' id='pci_sign_in_textfield_password'");
	submit.attributes_string("class='pci_submit' id='pci_sign_in_submit'");
	submit.value("Ingresar");

	add(form_name);
	add(user_name);
	add(password);
	add(submit);
}

SignUpFormInfo::SignUpFormInfo() {
	form_name.name("form_name");
	form_name.value("sign_up_form");

	first_name.attributes_string("class='pci_sign_up_textfield pci_textfield' id='pci_sign_up_textfield_first_name'");
	last_name.attributes_string("class='pci_sign_up_textfield pci_textfield' id='pci_sign_up_textfield_last_name'");
	user_name.attributes_string("class='pci_sign_up_textfield pci_textfield' id='pci_sign_up_textfield_user_name'");
	email.attributes_string("class='pci_sign_up_textfield pci_textfield' id='pci_sign_up_textfield_email'");
	password.attributes_string("class='pci_sign_up_textfield pci_textfield' id='pci_sign_up_textfield_password'");
	password_verification.attributes_string("class='pci_sign_up_textfield pci_textfield' id='pci_sign_up_textfield_password_verification'");
	birth_date.attributes_string("class='pci_sign_up_textfield pci_textfield' id='pci_sign_up_textfield_birth_date' readonly");
	genre.attributes_string("class='pci_dropdownlist pci_sign_up_dropdownlist' id='pci_sign_up_dropdownlist_genre'");
	submit.attributes_string("class='pci_submit' id='pci_sign_up_submit'");
	submit.value("Registrar");

	genre.add("Seleccione el sexo", "U");
	genre.add("Mujer", "F");
	genre.add("Hombre", "M");

	add(form_name);
	add(first_name);
	add(last_name);
	add(user_name);
	add(email);
	add(password);
	add(password_verification);
	add(birth_date);
	add(genre);
	add(submit);
}
