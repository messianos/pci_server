
/*
----------------------------------------------------------------------------------------------
	Global variables/constants
----------------------------------------------------------------------------------------------
*/

var logic_memory = new Object();

logic_memory.url = new Object();
logic_memory.url.root = '/pci';
logic_memory.url.sign_in = logic_memory.url.root + '/sign_in';
logic_memory.url.sign_out = logic_memory.url.root + '/sign_out';
logic_memory.url.toggle_anonymous_mode = logic_memory.url.root + '/toggle_anonymous_mode';
logic_memory.url.unseen_notifications = logic_memory.url.root + '/unseen_notifications';
logic_memory.url.create_user = logic_memory.url.root + '/create_user';
logic_memory.url.create_problem = logic_memory.url.root + '/create_problem';
logic_memory.url.edit_problem = logic_memory.url.root + '/edit_problem';
logic_memory.url.vote_problem = logic_memory.url.root + '/vote_problem';
logic_memory.url.set_accepted_solution = logic_memory.url.root + '/set_accepted_solution';
logic_memory.url.unset_accepted_solution = logic_memory.url.root + '/unset_accepted_solution';
logic_memory.url.create_solution = logic_memory.url.root + '/create_solution';
logic_memory.url.edit_solution = logic_memory.url.root + '/edit_solution';
logic_memory.url.vote_solution = logic_memory.url.root + '/vote_solution';
logic_memory.url.create_clarification = logic_memory.url.root + '/create_clarification';
logic_memory.url.answer_clarification = logic_memory.url.root + '/answer_clarification';
logic_memory.url.fetch_main_page = logic_memory.url.root;
logic_memory.url.fetch_user_page = logic_memory.url.root + '/user';
logic_memory.url.fetch_problems_page = logic_memory.url.root + '/problems';
logic_memory.url.fetch_problem_page = logic_memory.url.root + '/publication';
logic_memory.url.fetch_solution_page = logic_memory.url.root + '/publication';
logic_memory.url.fetch_new_problem_page = logic_memory.url.root + '/new_problem';
logic_memory.url.fetch_new_solution_page = logic_memory.url.root + '/new_solution';
logic_memory.url.fetch_ideas_page = logic_memory.url.root + '/ideas';

logic_memory.error = new Object();

logic_memory.error.id = new Object();
logic_memory.error.id.birth_date = 'birth_date';
logic_memory.error.id.email = 'email';
logic_memory.error.id.first_name = 'first_name';
logic_memory.error.id.last_name = 'last_name';
logic_memory.error.id.location = 'location';
logic_memory.error.id.password = 'password';
logic_memory.error.id.user_name = 'user_name';
logic_memory.error.id.content = 'content';
logic_memory.error.id.description = 'description';
logic_memory.error.id.question = 'question';
logic_memory.error.id.answer = 'answer';

logic_memory.error.description = new Object();
logic_memory.error.description.birth_date = 'birth_date';
logic_memory.error.description.email = 'email';
logic_memory.error.description.first_name = 'first_name';
logic_memory.error.description.last_name = 'last_name';
logic_memory.error.description.location = 'location';
logic_memory.error.description.password = 'password';
logic_memory.error.description.user_name = 'user_name';
logic_memory.error.description.content = 'content';
logic_memory.error.description.description = 'description';
logic_memory.error.description.question = 'question';
logic_memory.error.description.answer = 'answer';

logic_memory.notification_check_interval = 2000;


/*
----------------------------------------------------------------------------------------------
	Server-communication functions
----------------------------------------------------------------------------------------------
*/

function postSignIn(on_success_callback_function, on_failure_callback_function, password, user_name) {
	var request = postRequest({
		password: password,
		user_name: user_name
	}, logic_memory.url.sign_in);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postSignOut(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
	}, logic_memory.url.sign_out);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postToggleAnonymousMode(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
	}, logic_memory.url.toggle_anonymous_mode);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postUnseenNotifications(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
	}, logic_memory.url.unseen_notifications);
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
	}, logic_memory.url.create_user);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postCreateProblem(on_success_callback_function, on_failure_callback_function, content, description) {
	var request = postRequest({
		content: content,
		description: description
	}, logic_memory.url.create_problem);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postEditProblem(on_success_callback_function, on_failure_callback_function, content, problem_id) {
	var request = postRequest({
		content: content,
		problem_id: problem_id
	}, logic_memory.url.edit_problem);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postVoteProblem(on_success_callback_function, on_failure_callback_function, is_positive, problem_id) {
	var request = postRequest({
		is_positive: is_positive,
		problem_id: problem_id
	}, logic_memory.url.vote_problem);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postSetAcceptedSolution(on_success_callback_function, on_failure_callback_function, problem_id, solution_id) {
	var request = postRequest({
		problem_id: problem_id,
		solution_id: solution_id
	}, logic_memory.url.set_accepted_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postUnsetAcceptedSolution(on_success_callback_function, on_failure_callback_function, problem_id) {
	var request = postRequest({
		problem_id: problem_id
	}, logic_memory.url.unset_accepted_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postCreateSolution(on_success_callback_function, on_failure_callback_function, content, description, problem_id) {
	var request = postRequest({
		content: content,
		description: description,
		problem_id: problem_id
	}, logic_memory.url.create_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postEditSolution(on_success_callback_function, on_failure_callback_function) {
	var request = postRequest({
		// TODO
	}, logic_memory.url.edit_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postVoteSolution(on_success_callback_function, on_failure_callback_function, is_positive, solution_id) {
	var request = postRequest({
		is_positive: is_positive,
		solution_id: solution_id
	}, logic_memory.url.vote_solution);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postCreateClarification(on_success_callback_function, on_failure_callback_function, associated_publication_id, question) {
	var request = postRequest({
		associated_publication_id: associated_publication_id,
		question: question
	}, logic_memory.url.create_clarification);
	request.done(on_success_callback_function);
	request.fail(on_failure_callback_function);
}

function postAnswerClarification(on_success_callback_function, on_failure_callback_function, answer, clarification_id) {
	var request = postRequest({
		answer: answer,
		clarification_id: clarification_id
	}, logic_memory.url.answer_clarification);
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
		// TODO: DON'T SHOW tooltip ---> just refuse sign in?
		if (logic_memory.error.id.password in error_information)
			showTooltip(password_passwordfield, 'left', error_information[logic_memory.error.id.password]);
		if (logic_memory.error.id.user_name in error_information)
			showTooltip(user_name_textfield, 'left', error_information[logic_memory.error.id.user_name]);
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
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessSignOut() {
	return function(data, text_status, jq_xhr) {
		location.reload(true);
	};
}

function onFailureSignOut() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
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
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessUnseenNotifications(notification_container) {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);
		
		notification_container.empty();
		var length = data['notification_count'];
		for (var i = 0; i < length; i++)
			appendNotification(notification_container, data['unseen_notifications'][i]['url'], data['unseen_notifications'][i]['message']);
	}
}

function onFailureUnseenNotifications() {
	return null;
}

function onInvalidInputCreateUser(birth_date_textfield, email_textfield, first_name_textfield, last_name_textfield, location_textfield, password_passwordfield, user_name_textfield) {
	return function(error_information) {
		if (logic_memory.error.id.birth_date in error_information)
			showTooltip(birth_date_textfield, 'left', error_information[logic_memory.error.id.birth_date]);
		if (logic_memory.error.id.email in error_information)
			showTooltip(email_textfield, 'left', error_information[logic_memory.error.id.email]);
		if (logic_memory.error.id.first_name in error_information)
			showTooltip(first_name_textfield, 'left', error_information[logic_memory.error.id.first_name]);
		if (logic_memory.error.id.last_name in error_information)
			showTooltip(last_name_textfield, 'left', error_information[logic_memory.error.id.last_name]);
		if (logic_memory.error.id.location in error_information)
			showTooltip(location_textfield, 'left', error_information[logic_memory.error.id.location]);
		if (logic_memory.error.id.password in error_information)
			showTooltip(password_passwordfield, 'left', error_information[logic_memory.error.id.password]);
		if (logic_memory.error.id.user_name in error_information)
			showTooltip(user_name_textfield, 'left', error_information[logic_memory.error.id.user_name]);
	};
}

function onSuccessCreateUser(user_name) {
	return function(data, text_status, jq_xhr) {
		window.location.href = logic_memory.url.fetch_user_page + '/' + user_name;
	};
}

function onFailureCreateUser() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onInvalidInputCreateProblem(content_textarea, description_textfield) {
	return function(error_information) {
		if (logic_memory.error.id.content in error_information)
			showTooltip(content_textarea, 'left', error_information[logic_memory.error.id.content]);
		if (logic_memory.error.id.description in error_information)
			showTooltip(description_textfield, 'left', error_information[logic_memory.error.id.description]);
	};
}

function onSuccessCreateProblem() {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);
		window.location.href = logic_memory.url.fetch_problem_page + '/' + data['problem_id'];
	};
}

function onFailureCreateProblem() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onInvalidInputEditProblem(content_textarea) {
	return function(error_information) {
		if (logic_memory.error.id.content in error_information)
			showTooltip(content_textarea, 'left', error_information[logic_memory.error.id.content]);
	}
}

function onSuccessEditProblem(content) {
	return function(data, text_status, jq_xhr) {
		logic_memory.problem_bbcode = content;
		CKEDITOR.instances.edit_problem_content.setData(logic_memory.problem_bbcode);
		
		var html_code = XBBCODE.process({
			text: logic_memory.problem_bbcode,
			addInLineBreaks: true
		}).html;
		
		$('#problem_problem_content').empty();
		$('#problem_problem_content').append(html_code);

		$("#problem_edit_button").show();
		$("#problem_problem_content").show();
		$('#edit_problem_form').hide();
	};
}

function onFailureEditProblem() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessVoteProblem(display, vote_offset) {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);
		display.html(data['vote_balance'].toString());
		logic_memory.user_vote = logic_memory.user_vote + vote_offset;
		// TODO: Confirm the following line goes here
		refreshVotesButtonsColors();
	};
}

function onFailureVoteProblem() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
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
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
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
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onInvalidInputCreateSolution(content_textarea, description_textfield) {
	return function(error_information) {
		if (logic_memory.error.id.content in error_information)
			showTooltip(content_textarea, 'left', error_information[logic_memory.error.id.content]);
		if (logic_memory.error.id.description in error_information)
			showTooltip(description_textfield, 'left', error_information[logic_memory.error.id.description]);
	};
}

function onSuccessCreateSolution() {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);
		window.location.href = logic_memory.url.fetch_solution_page + '/' + data['solution_id'];
	};
}

function onFailureCreateSolution() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessEditSolution() {
	return function(data, text_status, jq_xhr) {
		// TODO
	};
}

function onFailureEditSolution() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onSuccessVoteSolution(display) {
	return function(data, text_status, jq_xhr) {
		data = $.parseJSON(data);
		display.html(data['vote_balance'].toString());
	};
}

function onFailureVoteSolution() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onInvalidInputCreateClarification(question_textarea) {
	return function(error_information) {
		if (logic_memory.error.id.question in error_information)
			showTooltip(question_textarea, 'left', error_information[logic_memory.error.id.question]);
	};
}

function onSuccessCreateClarification(row_parent, textarea, question) {
	return function(data, text_status, jq_xhr) {
		textarea.val('');
		
		var row = $('<div class="clarifications_row_container"></div>');
		var question_container = $('<div class="clarifications_question_container"><div class="box_content clarifications_question_content"><span class="text_clarification">' + question + '</div></div></div>');
		var answer_container = $('<div class="clarifications_answer_container"></div>');
		
		row.append(question_container);
		row.append(answer_container);
		row_parent.append(row);
	};
}

function onFailureCreateClarification() {
	return function(jq_xhr, text_status, error_thrown) {
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}

function onInvalidInputAnswerClarification(answer_textarea) {
	return function(error_information) {
		if (logic_memory.error.id.answer in error_information)
			showTooltip(answer_textarea, 'left', error_information[logic_memory.error.id.answer]);
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
		showErrorToast('<b>Se ha producido un error</b><br />Error ' + jq_xhr.status + ' - ' + error_thrown);
	};
}


/*
----------------------------------------------------------------------------------------------
	Validation functions
----------------------------------------------------------------------------------------------
*/

function isValidBirthDate(birth_date) {
	return birth_date.length > 0;
}

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
		error_information[logic_memory.error.id.password] = logic_memory.error.description.password;
		invalid_input = true;
	}
	
	if (! isValidUserName(user_name)) {
		error_information[logic_memory.error.id.user_name] = logic_memory.error.description.user_name;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input_callback_function(error_information);
	
	return ! invalid_input;
}

function validateCreateUserInput(on_invalid_input_callback_function, birth_date, email, first_name, last_name, location, password, user_name) {
	var invalid_input = false;
	var error_information = new Object();
	
	if (! isValidBirthDate(birth_date)) {
		error_information[logic_memory.error.id.birth_date] = logic_memory.error.description.birth_date;
		invalid_input = true;
	}
	
	if (! isValidEmail(email)) {
		error_information[logic_memory.error.id.email] = logic_memory.error.description.email;
		invalid_input = true;
	}
	
	if (! isValidFirstName(first_name)) {
		error_information[logic_memory.error.id.first_name] = logic_memory.error.description.first_name;
		invalid_input = true;
	}
	
	if (! isValidLastName(last_name)) {
		error_information[logic_memory.error.id.last_name] = logic_memory.error.description.last_name;
		invalid_input = true;
	}
	
	if (! isValidLocation(location)) {
		error_information[logic_memory.error.id.location] = logic_memory.error.description.location;
		invalid_input = true;
	}
	
	if (! isValidPassword(password)) {
		error_information[logic_memory.error.id.password] = logic_memory.error.description.password;
		invalid_input = true;
	}
	
	if (! isValidUserName(user_name)) {
		error_information[logic_memory.error.id.user_name] = logic_memory.error.description.user_name;
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
		error_information[logic_memory.error.id.content] = logic_memory.error.description.content;
		invalid_input = true;
	}
	
	if (! isValidPublicationDescription(description)) {
		error_information[logic_memory.error.id.description] = logic_memory.error.description.description;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input_callback_function(error_information);
	
	return ! invalid_input;
}

function validateEditProblemInput(on_invalid_input_callback_function, content) {
	var invalid_input = false;
	var error_information = new Object();
	
	if (! isValidPublicationContent(content)) {
		error_information[logic_memory.error.id.content] = logic_memory.error.description.content;
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
		error_information[logic_memory.error.id.content] = logic_memory.error.description.content;
		invalid_input = true;
	}
	
	if (! isValidPublicationDescription(description)) {
		error_information[logic_memory.error.id.description] = logic_memory.error.description.description;
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
		error_information[logic_memory.error.id.question] = logic_memory.error.description.question;
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
		error_information[logic_memory.error.id.answer] = logic_memory.error.description.answer;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input_callback_function(error_information);
	
	return ! invalid_input;
}


/*
----------------------------------------------------------------------------------------------
	Notification functions
----------------------------------------------------------------------------------------------
*/

function checkNotificationsPeriodically(notification_container) {
	setInterval(function() {
		var on_success = onSuccessUnseenNotifications(notification_container);
		var on_failure = onFailureUnseenNotifications();
		postUnseenNotifications(on_success, on_failure);
	}, logic_memory.notification_check_interval);
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
