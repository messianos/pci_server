
var signUpConstants = {
	/* Customizable ------------------------------------------------------- */
		firstNameErrorDescription: 'Error description first_name',
		firstNameMaxLength: 128,
		firstNameMinLength: 2,
		lastNameErrorDescription: 'Error description last_name',
		lastNameMaxLength: 128,
		lastNameMinLength: 2,
		userNameErrorDescription: 'Error description user_name',
		userNameRegExp: /^[a-zA-Z][a-zA-Z0-9_]*$/g,
		emailErrorDescription: 'Error description email',
		emailRegExp: /^[A-Z0-9._+-]+@[A-Z0-9.]+\.[A-Z0-9]{2,}$/i,
		passwordErrorDescription: 'Error description password',
		passwordId: 'pci_sign_up_textfield_password',
		passwordMaxLength: 128,
		passwordMinLength: 2,
		passwordVerificationErrorDescription: 'Error description password_verification',
		passwordVerificationId: 'pci_sign_up_textfield_password_verification',
		genreErrorDescription: 'Error description genre',
		genreRegExp: /^[FM]$/g
	/* -------------------------------------------------------------------- */
};

function validateFirstName(firstName) {
	return	validateMinLength(firstName, signUpConstants.firstNameMinLength) &&
					validateMaxLength(firstName, signUpConstants.firstNameMaxLength);
}

function validateLastName(lastName) {
	return 	validateMinLength(lastName, signUpConstants.lastNameMinLength) &&
					validateMaxLength(lastName, signUpConstants.lastNameMaxLength);
}

function validateUserName(userName) {
	return validateRegExp(userName, signUpConstants.userNameRegExp);
}

function validateEmail(email) {
	return validateRegExp(email, signUpConstants.emailRegExp);
}

function validatePassword(password) {
	return 	validateMinLength(password, signUpConstants.passwordMinLength) &&
					validateMaxLength(password, signUpConstants.passwordMaxLength);
}

function validatePasswordVerification(password, passwordVerification) {
	return password == passwordVerification;
}

function validateGenre(genre) {
	return validateRegExp(genre, signUpConstants.genreRegExp);
}

function firstNameOnChange(element) {
	if (validateFirstName(element.val()))
		hideErrorBox(element.attr('id'));
	else
		showErrorBox(element.attr('id'), signUpConstants.firstNameErrorDescription);
}

function lastNameOnChange(element) {
	if (validateLastName(element.val()))
		hideErrorBox(element.attr('id'));
	else
		showErrorBox(element.attr('id'), signUpConstants.lastNameErrorDescription);
}

function userNameOnChange(element) {
	if (validateUserName(element.val()))
		hideErrorBox(element.attr('id'));
	else
		showErrorBox(element.attr('id'), signUpConstants.userNameErrorDescription);
}

function emailOnChange(element) {
	if (validateEmail(element.val()))
		hideErrorBox(element.attr('id'));
	else
		showErrorBox(element.attr('id'), signUpConstants.emailErrorDescription);
}

function passwordOnChange(element) {
	if (validatePassword(element.val()))
		hideErrorBox(element.attr('id'));
	else
		showErrorBox(element.attr('id'), signUpConstants.passwordErrorDescription);
	
	var verificationElement = $('#' + signUpConstants.passwordVerificationId);
	if (verificationElement.val().length > 0)
		passwordVerificationOnChange(verificationElement);
}

function passwordVerificationOnChange(element) {
	if (validatePasswordVerification($('#' + signUpConstants.passwordId).val(), element.val()))
		hideErrorBox(element.attr('id'));
	else
		showErrorBox(element.attr('id'), signUpConstants.passwordVerificationErrorDescription);
}

function genreOnChange(element) {
	if (validateGenre(element.val()))
		hideErrorBox(element.attr('id'));
	else
		showErrorBox(element.attr('id'), signUpConstants.genreErrorDescription);
}
