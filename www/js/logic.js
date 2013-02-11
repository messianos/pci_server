
/*
----------------------------------------------------------------------------------------------
	Global constants
----------------------------------------------------------------------------------------------
*/

var url_root = '/pci';
var url = {
	sign_in: url_root + '/sign_in',
	sign_out: url_root + '/sign_out',
	create_user: url_root + '/create_user',
	update_user: url_root + '/update_user',
	delete_user: url_root + '/delete_user',
	create_problem: url_root + '/create_problem',
	update_problem: url_root + '/update_problem',
	delete_problem: url_root + '/delete_problem',
	create_solution: url_root + '/create_solution',
	update_solution: url_root + '/update_solution',
	delete_solution: url_root + '/delete_solution',
	create_clarification: url_root + '/create_clarification',
	update_clarification: url_root + '/update_clarification',
	delete_clarification: url_root + '/delete_clarification',
	fetch_main_page: url_root + '',
	fetch_user_page: url_root + '/user/',
	fetch_problems_page: url_root + '/problems',
	fetch_problem_page: url_root + '/publication/',
	fetch_solution_page: url_root + '/publication/',
	fetch_ideas_page: url_root + '/ideas'
};

var error = {
	id: {
		email: 'email',
		first_name: 'first_name',
		last_name: 'last_name',
		location: 'location',
		password: 'password',
		user_name: 'user_name',
		content: 'content',
		description: 'description',
		question: 'question'
	},
	description: {
		email: 'DESCRIPCION ERROR email',
		first_name: 'DESCRIPCION ERROR first_name',
		last_name: 'DESCRIPCION ERROR last_name',
		location: 'DESCRIPCION ERROR location',
		password: 'DESCRIPCION ERROR password',
		user_name: 'DESCRIPCION ERROR user_name',
		content: 'DESCRIPCION ERROR content',
		description: 'DESCRIPCION ERROR description',
		question: 'DESCRIPCION ERROR question'
	}
};


/*
----------------------------------------------------------------------------------------------
	Validation functions
----------------------------------------------------------------------------------------------
*/

function isValidEmail(email) {
	if (email.length > 255)
		return false;

	return email.match(/^[A-Z0-9._+-]+@[A-Z0-9.]+\.[A-Z0-9]{2,}$/i);
}

function isValidFirstName(first_name) {
	return first_name.length > 0 && first_name.length <= 31;
}

function isValidLastName(last_name) {
	return last_name.length > 0 && last_name.length <= 31;
}

function isValidLocation(location) {
	return location.length <= 15; // TODO: to define
}

function isValidPassword(password) {
	if (password.length < 6)
		return false;
	
	return password.match(/^[\x21-\x7E]*$/);
}

function isValidUserName(user_name) {
	if (user_name.length < 4 || user_name.length > 31)
		return false;

	return user_name.match(/^[A-Z][A-Z0-9_]*$/i);
}

function isValidPublicationContent(content) {
	return content.length > 0 && content.length <= 4194304;
}

function isValidPublicationDescription(description) {
	return description.length > 0 && description.length <= 400;
}

function isValidClarificationContent(content) {
	return content.length > 0 && content.length <= 2000;
}

function validateSignInInput(on_invalid_input_callback_function, password, user_name) {
	var invalid_input = false;
	var error_information = new Object();
	
	if (! isValidPassword(password)) {
		error_information[error.id.password] = error.description.password;
		invalid_input = true;
	}
	
	if (! isValidUserName(user_name)) {
		error_information[error.id.user_name] = error.description.user_name;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input_callback_function(error_information);
	
	return ! invalid_input;
}

function validateCreateUserInput(on_invalid_input_callback_function, email, first_name, last_name, location, password, user_name) {
	var invalid_input = false;
	var error_information = new Object();
	
	if (! isValidEmail(email)) {
		error_information[error.id.email] = error.description.email;
		invalid_input = true;
	}
	
	if (! isValidFirstName(first_name)) {
		error_information[error.id.first_name] = error.description.first_name;
		invalid_input = true;
	}
	
	if (! isValidLastName(last_name)) {
		error_information[error.id.last_name] = error.description.last_name;
		invalid_input = true;
	}
	
	if (! isValidLocation(location)) {
		error_information[error.id.location] = error.description.location;
		invalid_input = true;
	}
	
	if (! isValidPassword(password)) {
		error_information[error.id.password] = error.description.password;
		invalid_input = true;
	}
	
	if (! isValidUserName(user_name)) {
		error_information[error.id.user_name] = error.description.user_name;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input_callback_function(error_information);
	
	return ! invalid_input;
}

function validateCreateProblemInput(on_invalid_input_callback_function, content, description) {
	var invalid_input = false;
	var error_information = new Object();
	
	if (! isValidPublicationContent(content)) {
		error_information[error.id.content] = error.description.content;
		invalid_input = true;
	}
	
	if (! isValidPublicationDescription(description)) {
		error_information[error.id.description] = error.description.description;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input_callback_function(error_information);
	
	return ! invalid_input;
}

function validateCreateSolutionInput(on_invalid_input_callback_function, content, description) {
	var invalid_input = false;
	var error_information = new Object();
	
	if (! isValidPublicationContent(content)) {
		error_information[error.id.content] = error.description.content;
		invalid_input = true;
	}
	
	if (! isValidPublicationDescription(description)) {
		error_information[error.id.description] = error.description.description;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input_callback_function(error_information);
	
	return ! invalid_input;
}

function validateCreateClarificationInput(on_invalid_input_callback_function, question) {
	var invalid_input = false;
	var error_information = new Object();
	
	if (! isValidClarificationQuestion(question)) {
		error_information[error.id.question] = error.description.question;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input_callback_function(error_information);
	
	return ! invalid_input;
}


/*
----------------------------------------------------------------------------------------------
	Server-communication functions
----------------------------------------------------------------------------------------------
*/

function postSignIn(on_success_callback_function, on_failure_callback_function, password, user_name) {
	var request = postRequest({
		password: password,
		user_name: user_name
	}, url.sign_in);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postSignOut(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
	}, url.sign_out);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postCreateUser(on_success_callback_function, on_failure_callback_function, birth_date, email, first_name, genre, last_name, location, password, user_name) {
	var request = postRequest({
		birth_date: birth_date,
		email: email,
		first_name: first_name,
		genre: genre,
		last_name: last_name,
		location: location,
		password: password,
		user_name: user_name
	}, url.create_user);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postUpdateUser(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
		// TODO
	}, url.update_user);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postDeleteUser(on_success_callback_function, on_failure_callback_function, user_name) {
	var request = postRequest({
		user_name: user_name
	}, url.delete_user);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postCreateProblem(on_success_callback_function, on_failure_callback_function, content, description, is_anonymous) {
	var request = postRequest({
		content: content,
		description: description,
		is_anonymous: is_anonymous
	}, url.create_problem);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postUpdateProblem(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
		// TODO
	}, url.update_problem);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postDeleteProblem(on_success_callback_function, on_failure_callback_function, problem_id) {
	var request = postRequest({
		problem_id: problem_id
	}, url.delete_problem);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postCreateSolution(on_success_callback_function, on_failure_callback_function, content, description, is_anonymous, problem_id) {
	var request = postRequest({
		content: content,
		description: description,
		is_anonymous: is_anonymous,
		problem_id: problem_id
	}, url.create_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postUpdateSolution(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
		// TODO
	}, url.update_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postDeleteSolution(on_success_callback_function, on_failure_callback_function, solution_id) {
	var request = postRequest({
		solution_id: solution_id
	}, url.delete_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postCreateClarification(on_success_callback_function, on_failure_callback_function, associated_publication_id, question) {
	var request = postRequest({
		associated_publication_id: associated_publication_id,
		question: question
	}, url.create_clarification);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postUpdateClarification(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
	}, url.update_clarification);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postDeleteClarification(on_success_callback_function, on_failure_callback_function, clarification_id) {
	var request = postRequest({
		clarification_id: clarification_id
	}, url.delete_clarification);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}


/*
----------------------------------------------------------------------------------------------
	Callback functions
----------------------------------------------------------------------------------------------
*/

function onInvalidInputSignIn(password_passwordfield, user_name_textfield) {
	return function(error_information) {
		if (error.id.password in error_information)
			showErrorFloatingBox(password_passwordfield, error_information[error.id.password]);
		if (error.id.user_name in error_information)
			showErrorFloatingBox(user_name_textfield, error_information[error.id.user_name]);
	};
}

function onSuccessSignIn() {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);
		if (data['user_signed_in'])
			//TODO: DON'T REDIRECT, RELOAD
			window.location.href = url.fetch_main_page;
		else
			alert("INVALID USER_NAME AND PASSWORD. DO SOMETHING"); // TODO: DO SOMETHING WHEN SIGN IN FAILS
	};
}

function onFailureSignIn() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessSignOut() {
	return function(data, text_status, jq_xhr) {
		window.location.href = url.fetch_main_page;
	};
}

function onFailureSignOut() {
	return null;
}

function onInvalidInputCreateUser(email_textfield, first_name_textfield, last_name_textfield, location_textfield, password_passwordfield, user_name_textfield) {
	return function(error_information) {
		if (error.id.email in error_information)
			showErrorFloatingBox(email_textfield, error_information[error.id.email]);
		if (error.id.first_name in error_information)
			showErrorFloatingBox(first_name_textfield, error_information[error.id.first_name]);
		if (error.id.last_name in error_information)
			showErrorFloatingBox(last_name_textfield, error_information[error.id.last_name]);
		if (error.id.location in error_information)
			showErrorFloatingBox(location_textfield, error_information[error.id.location]);
		if (error.id.password in error_information)
			showErrorFloatingBox(password_passwordfield, error_information[error.id.password]);
		if (error.id.user_name in error_information)
			showErrorFloatingBox(user_name_textfield, error_information[error.id.user_name]);
	};
}

function onSuccessCreateUser() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureCreateUser() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessUpdateUser() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureUpdateUser() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessDeleteUser() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureDeleteUser() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onInvalidInputCreateProblem(content_textarea, description_textfield) {
	return function(error_information) {
		if (error.id.content in error_information)
			showErrorFloatingBox(content_textarea, error_information[error.id.content]);
		if (error.id.description in error_information)
			showErrorFloatingBox(description_textfield, error_information[error.id.description]);
	};
}

function onSuccessCreateProblem() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureCreateProblem() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessUpdateProblem() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureUpdateProblem() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessDeleteProblem() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureDeleteProblem() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onInvalidInputCreateSolution(content_textarea, description_textfield) {
	return function(error_information) {
		if (error.id.content in error_information)
			showErrorFloatingBox(content_textarea, error_information[error.id.content]);
		if (error.id.description in error_information)
			showErrorFloatingBox(description_textfield, error_information[error.id.description]);
	};
}

function onSuccessCreateSolution() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureCreateSolution() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessUpdateSolution() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureUpdateSolution() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessDeleteSolution() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureDeleteSolution() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onInvalidInputCreateClarification(question_textarea) {
	return function(error_information) {
		if (error.id.question in error_information)
			showErrorFloatingBox(question_textarea, error_information[error.id.question]);
	};
}

function onSuccessCreateClarification() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureCreateClarification() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessUpdateClarification() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureUpdateClarification() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessDeleteClarification() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureDeleteClarification() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}


/*
----------------------------------------------------------------------------------------------
	Auxiliar functions
----------------------------------------------------------------------------------------------
*/

function postRequest(data, url) {
	return $.ajax({
		data: data,
		type: 'POST',
		url: url
	});
}


/*
----------------------------------------------------------------------------------------------
	Graphical functions
----------------------------------------------------------------------------------------------
*/

function showErrorFloatingBox(input_element, error_description) {
	// TODO
	alert(input_element.val() + ' - Descripcion del error: ' + error_description);
}

function showErrorLateralBox(error_description) {
	$('div.dialog_error_report').animate({
		left: -$(this).outerWidth() - 16
	}, 800, function() {
		$(this).remove();
	});
	
	var dialog = $('<div class="dialog_error_report"></div>');
	dialog.css('background-color', '#FF0000');
	dialog.css('border-bottom-right-radius', '12px');
	dialog.css('border-top-right-radius', '12px');
	dialog.css('box-shadow', '1px 1px 3px 0px #555555');
	dialog.css('max-width', '448px');
	dialog.css('opacity', '0.95');
	dialog.css('padding', '8px 8px 8px 0px');
	dialog.css('position', 'fixed');
	dialog.hover(function() {
		$(this).animate({
			opacity: 1
		}, {
			duration: 300,
			queue: false
		});
	}, function() {
		$(this).animate({
			opacity: 0.95
		}, {
			duration: 500,
			queue: false
		});
	});
	
	var close_button = $('<a>X</a>');
	close_button.css('background-color', '#111111');
	close_button.css('border-color', '#E0E0E0');
	close_button.css('border-radius', '28px');
	close_button.css('border-style', 'solid');
	close_button.css('border-width', '2px');
	close_button.css('color', '#D2D2D2');
	close_button.css('cursor', 'pointer');
	close_button.css('font-family', 'Arial');
	close_button.css('font-weight', 'bold');
	close_button.css('height', '28px');
	close_button.css('line-height', '28px');
	close_button.css('position', 'absolute');
	close_button.css('right', '-7px');
	close_button.css('text-align', 'center');
	close_button.css('text-decoration', 'none');
	close_button.css('top', '-7px');
	close_button.css('width', '28px');
	close_button.click({
		dialog: dialog
	}, function(event) {
		dialog.animate({
			left: -dialog.outerWidth() - 16
		}, 800, function() {
			dialog.remove();
		});
	});
	
	var container = $('<div><h3>Se ha producido un error</h3><p>' + error_description + '</p></div>');
	container.css('background-color', '#F84444');
	container.css('border-color', '#E0E0E0');
	container.css('border-top-right-radius', '8px');
	container.css('border-bottom-right-radius', '8px');
	container.css('border-style', 'solid');
	container.css('border-width', '1px 1px 1px 0px');
	container.css('color', '#FFFFFF');
	container.css('font-family', 'Lucida Console');
	container.css('letter-spacing', '0.0625em');
	container.css('padding', '8px 24px 8px 64px');
	container.css('text-shadow', '0px 0px 0.125em #000000');
	container.css('word-break', 'break-word');
	
	dialog.append(close_button);
	dialog.append(container);
	$('body').append(dialog);
	
	dialog.css('bottom', '64px');
	dialog.css('left', -dialog.outerWidth()) - 16;
	dialog.animate({
		left: 0
	}, {
		duration: 1000, queue: false
	});
}
