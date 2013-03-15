
/*

	InputValidator
		Input
			SignIn
				password
				user_name
			SignUp
				birth_date
				email
				first_name
				last_name
				location
				password
				password_confirmation
				user_name
			Problem
				content
				description
			Solution
				content
				description
			Clarification
				content
			Proposal
				content
		hasValidBoundaries
		isValidEmail
		isValidPassword
		isValidUserName
		validateSignInInput
		validateSignUpInput
		validateProblemInput
		validateSolutionInput
		validateClarificationInput
		validateProposalInput

*/

var InputValidator = new Object();
InputValidator.Input = new Object();
InputValidator.Input.SignIn = new Object();
InputValidator.Input.SignUp = new Object();
InputValidator.Input.Problem = new Object();
InputValidator.Input.Solution = new Object();
InputValidator.Input.Clarification = new Object();
InputValidator.Input.Proposal = new Object();

InputValidator.Input.SignIn.password = {
	code: 'password',
	description: 'password', // TODO
	isValid: function(password) {
		return InputValidator.hasValidBoundaries(password, 1, -1);
	}
}

InputValidator.Input.SignIn.user_name = {
	code: 'user_name',
	description: 'user_name', // TODO
	isValid: function(user_name) {
		return InputValidator.hasValidBoundaries(user_name, 1, -1);
	}
}

InputValidator.Input.SignUp.birth_date = {
	code: 'birth_date',
	description: 'birth_date', // TODO
	isValid: function(birth_date) {
		return InputValidator.hasValidBoundaries(birth_date, 10, 10);
	}
}

InputValidator.Input.SignUp.email = {
	code: 'email',
	description: 'email', // TODO
	isValid: function(email) {
		return InputValidator.isValidEmail(email);
	}
}

InputValidator.Input.SignUp.first_name = {
	code: 'first_name',
	description: 'first_name', // TODO
	isValid: function(first_name) {
		return InputValidator.hasValidBoundaries(first_name, 1, 31);
	}
}

InputValidator.Input.SignUp.last_name = {
	code: 'last_name',
	description: 'last_name', // TODO
	isValid: function(last_name) {
		return InputValidator.hasValidBoundaries(last_name, 1, 31);
	}
}

InputValidator.Input.SignUp.location = {
	code: 'location',
	description: 'location', // TODO
	isValid: function(location) {
		return InputValidator.hasValidBoundaries(location, 0, 15); // TODO: to define
	}
}

InputValidator.Input.SignUp.password = {
	code: 'password',
	description: 'password', // TODO
	isValid: function(password) {
		return InputValidator.isValidPassword(password);
	}
}

InputValidator.Input.SignUp.password_confirmation = {
	code: 'password_confirmation',
	description: 'password_confirmation', // TODO
	isValid: function(password, password_confirmation) {
		return password == password_confirmation;
	}
}

InputValidator.Input.SignUp.user_name = {
	code: 'user_name',
	description: 'user_name', // TODO
	isValid: function(user_name) {
		return InputValidator.isValidUserName(user_name);
	}
}

InputValidator.Input.Problem.content = {
	code: 'content',
	description: 'content', // TODO
	isValid: function(content) {
		return InputValidator.hasValidBoundaries(content, 1, 4194304);
	}
}

InputValidator.Input.Problem.description = {
	code: 'description',
	description: 'description', // TODO
	isValid: function(description) {
		return InputValidator.hasValidBoundaries(description, 1, 400);
	}
}

InputValidator.Input.Solution.content = {
	code: 'content',
	description: 'content', // TODO
	isValid: function(content) {
		return InputValidator.hasValidBoundaries(content, 1, 4194304);
	}
}

InputValidator.Input.Solution.description = {
	code: 'description',
	description: 'description', // TODO
	isValid: function(description) {
		return InputValidator.hasValidBoundaries(description, 1, 400);
	}
}

InputValidator.Input.Clarification.content = {
	code: 'content',
	description: 'content', // TODO
	isValid: function(content) {
		return InputValidator.hasValidBoundaries(content, 1, 2000);
	}
}

InputValidator.Input.Proposal.content = {
	code: 'content',
	description: 'content', // TODO
	isValid: function(content) {
		return InputValidator.hasValidBoundaries(content, 1, 4194304);
	}
}

InputValidator.hasValidBoundaries = function(string, min, max) {
	if (max < 0)
		return string.length >= min;
	
	return string.length >= min && string.length <= max;
}

InputValidator.isValidEmail = function(email) {
	if (email.length > 255)
		return false;

	return email.match(/^[A-Z0-9._+-]+@[A-Z0-9.]+\.[A-Z0-9]{2,}$/i);
}

InputValidator.isValidPassword = function(password) {
	return password.match(/^[\x21-\x7E]{6,}$/);
}

InputValidator.isValidUserName = function(user_name) {
	return user_name.match(/^[A-Z][A-Z0-9_]{3,30}$/i);
}

InputValidator.validateSignInInput = function(on_invalid_input, password, user_name) {
	var invalid_input = false;
	var invalid_input_descriptions = new Object();
	
	if (! InputValidator.Input.SignIn.password.isValid(password)) {
		invalid_input_descriptions[InputValidator.Input.SignIn.password.code] = InputValidator.Input.SignIn.password.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.SignIn.user_name.isValid(user_name)) {
		invalid_input_descriptions[InputValidator.Input.SignIn.user_name.code] = InputValidator.Input.SignIn.user_name.description;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input(invalid_input_descriptions);
	
	return ! invalid_input;
}

InputValidator.validateSignUpInput = function(on_invalid_input, birth_date, email, first_name, last_name, location, password, password_confirmation, user_name) {
	var invalid_input = false;
	var invalid_input_descriptions = new Object();
	
	if (! InputValidator.Input.SignUp.birth_date.isValid(birth_date)) {
		invalid_input_descriptions[InputValidator.Input.SignUp.birth_date.code] = InputValidator.Input.SignUp.birth_date.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.SignUp.email.isValid(email)) {
		invalid_input_descriptions[InputValidator.Input.SignUp.email.code] = InputValidator.Input.SignUp.email.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.SignUp.first_name.isValid(first_name)) {
		invalid_input_descriptions[InputValidator.Input.SignUp.first_name.code] = InputValidator.Input.SignUp.first_name.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.SignUp.last_name.isValid(last_name)) {
		invalid_input_descriptions[InputValidator.Input.SignUp.last_name.code] = InputValidator.Input.SignUp.last_name.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.SignUp.location.isValid(location)) {
		invalid_input_descriptions[InputValidator.Input.SignUp.location.code] = InputValidator.Input.SignUp.location.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.SignUp.password.isValid(password)) {
		invalid_input_descriptions[InputValidator.Input.SignUp.password.code] = InputValidator.Input.SignUp.password.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.SignUp.password_confirmation.isValid(password, password_confirmation)) {
		invalid_input_descriptions[InputValidator.Input.SignUp.password_confirmation.code] = InputValidator.Input.SignUp.password_confirmation.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.SignUp.user_name.isValid(user_name)) {
		invalid_input_descriptions[InputValidator.Input.SignUp.user_name.code] = InputValidator.Input.SignUp.user_name.description;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input(invalid_input_descriptions);
	
	return ! invalid_input;
}

InputValidator.validateProblemInput = function(on_invalid_input, content, description) {
	var invalid_input = false;
	var invalid_input_descriptions = new Object();
	
	if (! InputValidator.Input.Problem.content.isValid(content)) {
		invalid_input_descriptions[InputValidator.Input.Problem.content.code] = InputValidator.Input.Problem.content.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.Problem.description.isValid(description)) {
		invalid_input_descriptions[InputValidator.Input.Problem.description.code] = InputValidator.Input.Problem.description.description;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input(invalid_input_descriptions);
	
	return ! invalid_input;
}

InputValidator.validateSolutionInput = function(on_invalid_input, content, description) {
	var invalid_input = false;
	var invalid_input_descriptions = new Object();
	
	if (! InputValidator.Input.Solution.content.isValid(content)) {
		invalid_input_descriptions[InputValidator.Input.Solution.content.code] = InputValidator.Input.Solution.content.description;
		invalid_input = true;
	}
	
	if (! InputValidator.Input.Solution.description.isValid(description)) {
		invalid_input_descriptions[InputValidator.Input.Solution.description.code] = InputValidator.Input.Solution.description.description;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input(invalid_input_descriptions);
	
	return ! invalid_input;
}

InputValidator.validateClarificationInput = function(on_invalid_input, content) {
	var invalid_input = false;
	var invalid_input_descriptions = new Object();
	
	if (! InputValidator.Input.Clarification.content.isValid(content)) {
		invalid_input_descriptions[InputValidator.Input.Clarification.content.code] = InputValidator.Input.Clarification.content.description;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input(invalid_input_descriptions);
	
	return ! invalid_input;
}

InputValidator.validateProposalInput = function(on_invalid_input, content) {
	var invalid_input = false;
	var invalid_input_descriptions = new Object();
	
	if (! InputValidator.Input.Proposal.content.isValid(content)) {
		invalid_input_descriptions[InputValidator.Input.Proposal.content.code] = InputValidator.Input.Proposal.content.description;
		invalid_input = true;
	}
	
	if (invalid_input)
		on_invalid_input(invalid_input_descriptions);
	
	return ! invalid_input;
}


/*

	Server
		Error
			invalid_parameters
			not_signed_in
			existing_user
			unauthorized_user
			bad_url
			nonexistent_clarification
			nonexistent_problem
			nonexistent_proposal
			nonexistent_solution
			nonexistent_user
			method_not_allowed
			unknown
			getErrorDescription
		Url
			root
			sign_in
			sign_out
			toggle_anonymous_mode
			user_exists
			unseen_notifications
			sign_up
			publicate_problem
			edit_problem
			make_problem_creator_visible
			vote_problem
			set_accepted_solution
			unset_accepted_solution
			publicate_solution
			edit_solution
			make_solution_creator_visible
			vote_solution
			ask_clarification
			answer_clarification
			publicate_proposal
			edit_proposal
			make_proposal_creator_visible
			vote_proposal
			fetch_main_page
			fetch_user_page
			fetch_problems_page
			fetch_problem_page
			fetch_solution_page
			fetch_new_problem_page
			fetch_new_solution_page
			fetch_ideas_page
		signIn
		signOut
		toggleAnonymousMode
		userExists
		unseenNotifications
		signUp
		publicateProblem
		editProblem
		makeProblemCreatorVisible
		voteProblem
		setAcceptedSolution
		unsetAcceptedSolution
		publicateSolution
		editSolution
		makeSolutionCreatorVisible
		voteSolution
		askClarification
		answerClarification
		publicateProposal
		editProposal
		makeProposalCreatorVisible
		voteProposal

*/

var Server = new Object();
Server.Error = new Object();
Server.Url = new Object();

Server.Error.not_signed_in = {
	code: '40101',
	description: 'El usuario no inició sesión' // TODO
}

Server.Error.existing_user = {
	code: '40301',
	description: 'existing_user' // TODO
}

Server.Error.unauthorized_user = {
	code: '40302',
	description: 'unauthorized_user' // TODO
}

Server.Error.bad_url = {
	code: '40401',
	description: 'Página no encontrada'
}

Server.Error.nonexistent_clarification = {
	code: '40402',
	description: 'Aclaración no encontrada'
}

Server.Error.nonexistent_problem = {
	code: '40403',
	description: 'Problema no encontrado'
}

Server.Error.nonexistent_proposal = {
	code: '40404',
	description: 'Propuesta de mejora no encontrada'
}

Server.Error.nonexistent_solution = {
	code: '40405',
	description: 'Solución no encontrada'
}

Server.Error.nonexistent_user = {
	code: '40406',
	description: 'Usuario no encontrado'
}

Server.Error.method_not_allowed = {
	code: '40501',
	description: 'method_not_allowed'
}

Server.Error.unknown = {
	code: '50001',
	description: 'Error desconocido'
}

Server.Error.getErrorDescription = function(error_code) {
	switch(error_code) {
		case Server.Error.invalid_parameters.code : return Server.Error.invalid_parameters.description;
		case Server.Error.not_signed_in.code : return Server.Error.not_signed_in.description;
		case Server.Error.existing_user.code : return Server.Error.existing_user.description;
		case Server.Error.unauthorized_user.code : return Server.Error.unauthorized_user.description;
		case Server.Error.bad_url.code : return Server.Error.bad_url.description;
		case Server.Error.nonexistent_clarification.code : return Server.Error.nonexistent_clarification.description;
		case Server.Error.nonexistent_problem.code : return Server.Error.nonexistent_problem.description;
		case Server.Error.nonexistent_proposal.code : return Server.Error.nonexistent_proposal.description;
		case Server.Error.nonexistent_solution.code : return Server.Error.nonexistent_solution.description;
		case Server.Error.nonexistent_user.code : return Server.Error.nonexistent_user.description;
		case Server.Error.method_not_allowed.code : return Server.Error.method_not_allowed.description;
		case Server.Error.unknown.code : return Server.Error.unknown.description;
	}
}

Server.Url.root = '/pci';  // TODO: when ready, change this to "/"
Server.Url.sign_in = Server.Url.root + '/sign_in';
Server.Url.sign_out = Server.Url.root + '/sign_out';
Server.Url.toggle_anonymous_mode = Server.Url.root + '/toggle_anonymous_mode';
Server.Url.user_exists = Server.Url.root + '/user_exists';
Server.Url.unseen_notifications = Server.Url.root + '/unseen_notifications';
Server.Url.sign_up = Server.Url.root + '/sign_up';
Server.Url.publicate_problem = Server.Url.root + '/publicate_problem';
Server.Url.edit_problem = Server.Url.root + '/edit_problem';
Server.Url.make_problem_creator_visible = Server.Url.root + '/make_problem_creator_visible';
Server.Url.vote_problem = Server.Url.root + '/vote_problem';
Server.Url.set_accepted_solution = Server.Url.root + '/set_accepted_solution';
Server.Url.unset_accepted_solution = Server.Url.root + '/unset_accepted_solution';
Server.Url.publicate_solution = Server.Url.root + '/publicate_solution';
Server.Url.edit_solution = Server.Url.root + '/edit_solution';
Server.Url.make_solution_creator_visible = Server.Url.root + '/make_solution_creator_visible';
Server.Url.vote_solution = Server.Url.root + '/vote_solution';
Server.Url.ask_clarification = Server.Url.root + '/ask_clarification';
Server.Url.answer_clarification = Server.Url.root + '/answer_clarification';
Server.Url.publicate_proposal = Server.Url.root + '/publicate_proposal';
Server.Url.edit_proposal = Server.Url.root + '/edit_proposal';
Server.Url.make_proposal_creator_visible = Server.Url.root + '/make_proposal_creator_visible';
Server.Url.vote_proposal = Server.Url.root + '/vote_proposal';
Server.Url.fetch_main_page = Server.Url.root;
Server.Url.fetch_user_page = function(user_name) { return Server.Url.root + '/user/' + user_name; };
Server.Url.fetch_problems_page = Server.Url.root + '/problems';
Server.Url.fetch_problem_page = function(problem_id) { return Server.Url.root + '/publication/' + problem_id; };
Server.Url.fetch_solution_page = function(solution_id) { return Server.Url.root + '/publication/' + solution_id; };
Server.Url.fetch_new_problem_page = Server.Url.root + '/new_problem';
Server.Url.fetch_new_solution_page = function(problem_id) { return Server.Url.root + '/new_solution/' + problem_id; };
Server.Url.fetch_ideas_page = Server.Url.root + '/ideas';

Server.signIn = function(on_success, on_error, password, user_name) {
	var data = {
		password: password,
		user_name: user_name
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.sign_in
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['signed_in']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
};

Server.signOut = function(on_success, on_error) {
	var request = $.ajax({
		type: 'POST',
		url: Server.Url.sign_out
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.toggleAnonymousMode = function(on_success, on_error) {
	var request = $.ajax({
		type: 'POST',
		url: Server.Url.toggle_anonymous_mode
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['anonymous_mode']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.userExists = function(on_success, on_error, user_name) {
	var data = {
		user_name: user_name
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.user_exists
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['user_exists']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.unseenNotifications = function(on_success, on_error) {
	var request = $.ajax({
		type: 'POST',
		url: Server.Url.unseen_notifications
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['notification_count'], data['notifications']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.signUp = function(on_success, on_error, birth_date, email, first_name, genre, last_name, location, password, user_name) {
	var data = {
		birth_date: birth_date,
		email: email,
		first_name: first_name,
		genre: genre,
		last_name: last_name,
		location: location,
		password: password,
		user_name: user_name
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.sign_up
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.publicateProblem = function(on_success, on_error, content, description) {
	var data = {
		content: content,
		description: description
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.publicate_problem
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['problem_id']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.editProblem = function(on_success, on_error, content, description, problem_id) {
	var data = {
		content: content,
		description: description,
		problem_id: problem_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.edit_problem
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.makeProblemCreatorVisible = function(on_success, on_error, problem_id) {
	var data = {
		problem_id: problem_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.make_problem_creator_visible
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.voteProblem = function(on_success, on_error, is_positive, problem_id) {
	var data = {
		is_positive: is_positive,
		problem_id: problem_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.vote_problem
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['vote_balance']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.setAcceptedSolution = function(on_success, on_error, problem_id, solution_id) {
	var data = {
		problem_id: problem_id,
		solution_id: solution_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.set_accepted_solution
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.unsetAcceptedSolution = function(on_success, on_error, problem_id) {
	var data = {
		problem_id: problem_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.unset_accepted_solution
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.publicateSolution = function(on_success, on_error, content, description, problem_id) {
	var data = {
		content: content,
		description: description,
		problem_id: problem_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.publicate_solution
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['solution_id']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.editSolution = function(on_success, on_error, content, description, solution_id) {
	var data = {
		content: content,
		description: description,
		solution_id: solution_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.edit_solution
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.makeSolutionCreatorVisible = function(on_success, on_error, solution_id) {
	var data = {
		solution_id: solution_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.make_solution_creator_visible
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.voteSolution = function(on_success, on_error, is_positive, solution_id) {
	var data = {
		is_positive: is_positive,
		solution_id: solution_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.vote_solution
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['vote_balance']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.askClarification = function(on_success, on_error, publication_id, question) {
	var data = {
		publication_id: publication_id,
		question: question
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.ask_clarification
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['clarification_id']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.answerClarification = function(on_success, on_error, answer, clarification_id) {
	var data = {
		answer: answer,
		clarification_id: clarification_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.answer_clarification
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.publicateProposal = function(on_success, on_error, content, solution_id) {
	var data = {
		content: content,
		solution_id: solution_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.publicate_proposal
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['proposal_id']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.editProposal = function(on_success, on_error, content, proposal_id) {
	var data = {
		content: content,
		proposal_id: proposal_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.edit_proposal
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.makeProposalCreatorVisible = function(on_success, on_error, proposal_id) {
	var data = {
		proposal_id: proposal_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.make_proposal_creator_visible
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			on_success();
		});

	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}

Server.voteProposal = function(on_success, on_error, is_positive, proposal_id) {
	var data = {
		is_positive: is_positive,
		proposal_id: proposal_id
	};
	
	var request = $.ajax({
		data: data,
		type: 'POST',
		url: Server.Url.vote_proposal
	});
	
	if (on_success != null)
		request.done(function(data, text_status, jq_xhr) {
			data = $.parseJSON(data);
			on_success(data['vote_balance']);
		});
	
	if (on_error != null)
		request.fail(function(jq_xhr, text_status, error_thrown) {
			on_error(jq_xhr.status, error_thrown);
		});
}


/*

	Notification
		Aux
			check_interval
		Event
			<completar>
			getNotificationMessage
		checkNotificationsPeriodically

*/

var Notification = new Object();
Notification.Aux = new Object();
Notification.Event = new Object();

Notification.Aux.check_interval = 2000;

/*

Notification.Event. = {
	code: '',
	message: function(originator_user_name) {}
}

Notification.Event.getNotificationMessage = function(event_code, originator_user_name) {
	switch(event_code) {
		case Server.Event..code : return Server.Event..message(originator_user_name);
	}
}
*/

Notification.checkNotificationsPeriodically = function(container) {
	setInterval(function() {
		var on_success = function(notification_count, notifications) {
			NotificationContainer.emptyContainer(container);
			for (var i = 0; i < notification_count; i++) {
				var notification = notifications[i];
				var url = Server.Url.root + notification['url'];
				var message = Notification.Event.getNotificationMessage(notification['event_code']);
				NotificationContainer.appendNotification(container, url, message);
			}
		};
		Server.unseenNotifications(on_success, null);
	}, Notification.Aux.check_interval);
}
