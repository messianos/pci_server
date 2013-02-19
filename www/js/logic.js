
/*
----------------------------------------------------------------------------------------------
	Global variables/constants
----------------------------------------------------------------------------------------------
*/

var global_memory = new Object();

var url_root = '/pci';
var url = {
	sign_in: url_root + '/sign_in',
	sign_out: url_root + '/sign_out',
	toggle_anonymous_mode: url_root + '/toggle_anonymous_mode',
	create_user: url_root + '/create_user',
	create_problem: url_root + '/create_problem',
	edit_problem: url_root + '/edit_problem',
	vote_problem: url_root + '/vote_problem',
	set_accepted_solution: url_root + '/set_accepted_solution',
	unset_accepted_solution: url_root + '/unset_accepted_solution',
	create_solution: url_root + '/create_solution',
	edit_solution: url_root + '/edit_solution',
	vote_solution: url_root + '/vote_solution',
	create_clarification: url_root + '/create_clarification',
	answer_clarification: url_root + '/answer_clarification',
	fetch_main_page: url_root + '',
	fetch_user_page: url_root + '/user',
	fetch_problems_page: url_root + '/problems',
	fetch_problem_page: url_root + '/publication',
	fetch_solution_page: url_root + '/publication',
	fetch_new_problem_page: url_root + '/new_problem',
	fetch_new_solution_page: url_root + '/new_solution',
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
		question: 'question',
		answer: 'answer'
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
		question: 'DESCRIPCION ERROR question',
		answer: 'DESCRIPCION ERROR answer'
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
	
	if (! isValidClarificationContent(question)) {
		error_information[error.id.question] = error.description.question;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input_callback_function(error_information);
	
	return ! invalid_input;
}

function validateAnswerClarificationInput(on_invalid_input_callback_function, answer) {
	var invalid_input = false;
	var error_information = new Object();
	
	if (! isValidClarificationContent(answer)) {
		error_information[error.id.answer] = error.description.answer;
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

function postToggleAnonymousMode(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
	}, url.toggle_anonymous_mode);
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

function postCreateProblem(on_success_callback_function, on_failure_callback_function, content, description) {
	var request = postRequest({
		content: content,
		description: description
	}, url.create_problem);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postEditProblem(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
		// TODO
	}, url.edit_problem);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postVoteProblem(on_success_callback_function, on_failure_callback_function, is_positive, problem_id) {
	var request = postRequest({
		is_positive: is_positive,
		problem_id: problem_id
	}, url.vote_problem);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postSetAcceptedSolution(on_success_callback_function, on_failure_callback_function, problem_id, solution_id) {
	var request = postRequest({
		problem_id: problem_id,
		solution_id: solution_id
	}, url.set_accepted_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postUnsetAcceptedSolution(on_success_callback_function, on_failure_callback_function, problem_id) {
	var request = postRequest({
		problem_id: problem_id
	}, url.unset_accepted_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postCreateSolution(on_success_callback_function, on_failure_callback_function, content, description, problem_id) {
	var request = postRequest({
		content: content,
		description: description,
		problem_id: problem_id
	}, url.create_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postEditSolution(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
		// TODO
	}, url.edit_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postVoteSolution(on_success_callback_function, on_failure_callback_function, is_positive, solution_id) {
	var request = postRequest({
		is_positive: is_positive,
		solution_id: solution_id
	}, url.vote_solution);
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

function postAnswerClarification(on_success_callback_function, on_failure_callback_function, answer, clarification_id) {
	var request = postRequest({
		answer: answer,
		clarification_id: clarification_id
	}, url.answer_clarification);
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
			location.reload(true);
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
		location.reload(true);
	};
}

function onFailureSignOut() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessToggleAnonymousMode(toggle_button) {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);

		$(toggle_button).tooltip('hide');
		
		if (data['anonymous_mode'])
			$(toggle_button).attr('data-original-title', 'Modo anónimo activado');
		else
			$(toggle_button).attr('data-original-title', 'Modo anónimo desactivado');
		
		$(toggle_button).tooltip('fixTitle');
		$(toggle_button).tooltip('show');
		$(toggle_button).toggleClass('on');
	};
}

function onFailureToggleAnonymousMode() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
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

function onSuccessCreateUser(user_name) {
	return function(data, text_status, jq_xhr) {
		window.location.href = url.fetch_user_page + '/' + user_name;
	};
}

function onFailureCreateUser() {
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
		data = $.parseJSON(data);
		window.location.href = url.fetch_problem_page + '/' + data['problem_id'];
	};
}

function onFailureCreateProblem() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessEditProblem() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureEditProblem() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessVoteProblem(display, vote_offset) {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);
		display.html(data['vote_balance'].toString());
		global_memory.user_vote = global_memory.user_vote + vote_offset;
	};
}

function onFailureVoteProblem() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessSetAcceptedSolution(button, problem_id, solution_id) {
	return function(data, text_status, jq_xhr) {
		var on_button = $('.tick.on');
		if (on_button.length > 0) {
			on_button.parent().removeClass('accepted_solution');
			on_button.removeClass('on');
			on_button.unbind('click');
			on_button.click(function() {
				var accepted_solution_id = $(this).attr('id');
				
				var on_success = onSuccessSetAcceptedSolution($(this), problem_id, accepted_solution_id);
				var on_failure = onFailureSetAcceptedSolution();
				postSetAcceptedSolution(on_success, on_failure, problem_id, accepted_solution_id);
			});
		}
		
		button.parent().addClass('accepted_solution');
		button.addClass('on');
		button.unbind('click');
		button.click(function() {
			var on_success = onSuccessUnsetAcceptedSolution($(this), problem_id, solution_id);
			var on_failure = onFailureUnsetAcceptedSolution();
			postUnsetAcceptedSolution(on_success, on_failure, problem_id);
		});
	};
}

function onFailureSetAcceptedSolution() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessUnsetAcceptedSolution(button, problem_id, accepted_solution_id) {
	return function(data, text_status, jq_xhr) {
		button.parent().removeClass('accepted_solution');
		button.removeClass('on');
		button.unbind('click');
		button.click(function() {
			var on_success = onSuccessSetAcceptedSolution($(this), problem_id, accepted_solution_id);
			var on_failure = onFailureSetAcceptedSolution();
			postSetAcceptedSolution(on_success, on_failure, problem_id, accepted_solution_id);
		});
	};
}

function onFailureUnsetAcceptedSolution() {
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

function onSuccessCreateSolution(problem_id) {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);
		window.location.href = url.fetch_solution_page + '/' + problem_id + '/' + data['solution_id'];
	};
}

function onFailureCreateSolution() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessEditSolution() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureEditSolution() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessVotSolution(display) {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);
		display.html(data['vote_balance'].toString());
	};
}

function onFailureVoteSolution() {
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
		showToast('Su pregunta ha sido enviada al autor de la publicación.');
	};
}

function onFailureCreateClarification() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorLateralBox('Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onInvalidInputAnswerClarification(answer_textarea) {
	return function(error_information) {
		if (error.id.answer in error_information)
			showErrorFloatingBox(answer_textarea, error_information[error.id.answer]);
	};
}

function onSuccessAnswerClarification(form, answer) {
	return function(data, text_status, jq_xhr) {
		var new_node = $('<span class="text_clarification">' + answer + '</span>');
		var parent = form.parent();
		parent.empty();
		parent.addClass('box_content');
		parent.append(new_node);
	};
}

function onFailureAnswerClarification() {
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

function showToast(message) {
	// TODO
	alert(message);
	
	var toast = $('<div></div>');
	toast.css('background-color', '#FF0000');
	toast.css('border-radius', '12px');
	toast.css('box-shadow', '1px 1px 3px 0px #555555');
	toast.css('max-width', '448px');
	toast.css('opacity', '0.95');
	toast.css('padding', '8px 8px 8px 0px');
	toast.css('position', 'fixed');
	// TODO---> set actual toast position
	
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
		toast: toast
	}, function(event) {
		dialog.animate({
			left: -dialog.outerWidth() - 16
		}, 800, function() {
			dialog.remove();
		});
	});
}
