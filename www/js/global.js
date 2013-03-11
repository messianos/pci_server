
/*

	Global
		Temp
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

*/

var Global = new Object();
Global.Temp = new Object();
Global.Url = new Object();

Global.Url.root = '/pci';  // TODO: when ready, change this to "/"
Global.Url.sign_in = Global.Url.root + '/sign_in';
Global.Url.sign_out = Global.Url.root + '/sign_out';
Global.Url.toggle_anonymous_mode = Global.Url.root + '/toggle_anonymous_mode';
Global.Url.user_exists = Global.Url.root + '/user_exists';
Global.Url.unseen_notifications = Global.Url.root + '/unseen_notifications';
Global.Url.sign_up = Global.Url.root + '/sign_up';
Global.Url.publicate_problem = Global.Url.root + '/publicate_problem';
Global.Url.edit_problem = Global.Url.root + '/edit_problem';
Global.Url.make_problem_creator_visible = Global.Url.root + '/make_problem_creator_visible';
Global.Url.vote_problem = Global.Url.root + '/vote_problem';
Global.Url.set_accepted_solution = Global.Url.root + '/set_accepted_solution';
Global.Url.unset_accepted_solution = Global.Url.root + '/unset_accepted_solution';
Global.Url.publicate_solution = Global.Url.root + '/publicate_solution';
Global.Url.edit_solution = Global.Url.root + '/edit_solution';
Global.Url.make_solution_creator_visible = Global.Url.root + '/make_solution_creator_visible';
Global.Url.vote_solution = Global.Url.root + '/vote_solution';
Global.Url.ask_clarification = Global.Url.root + '/ask_clarification';
Global.Url.answer_clarification = Global.Url.root + '/answer_clarification';
Global.Url.publicate_proposal = Global.Url.root + '/publicate_proposal';
Global.Url.edit_proposal = Global.Url.root + '/edit_proposal';
Global.Url.make_proposal_creator_visible = Global.Url.root + '/make_proposal_creator_visible';
Global.Url.vote_proposal = Global.Url.root + '/vote_proposal';
Global.Url.fetch_main_page = Global.Url.root;
Global.Url.fetch_user_page = function(user_name) { return Global.Url.root + '/user/' + user_name; };
Global.Url.fetch_problems_page = Global.Url.root + '/problems';
Global.Url.fetch_problem_page = function(problem_id) { return Global.Url.root + '/publication/' + problem_id; };
Global.Url.fetch_solution_page = function(solution_id) { return Global.Url.root + '/publication/' + solution_id; };
Global.Url.fetch_new_problem_page = Global.Url.root + '/new_problem';
Global.Url.fetch_new_solution_page = function(problem_id) { return Global.Url.root + '/new_solution/' + problem_id; };
Global.Url.fetch_ideas_page = Global.Url.root + '/ideas';
