#line 2 "Template.tmpl"
#include "logic/ViewContent.h" 
#line 4 "Template.tmpl"
namespace pci_skin {
	#line 5 "Template.tmpl"
	struct template_view :public cppcms::base_view
	#line 5 "Template.tmpl"
	{
	#line 5 "Template.tmpl"
		ViewContent::TemplateContent &content;
	#line 5 "Template.tmpl"
		template_view(std::ostream &_s,ViewContent::TemplateContent &_content): cppcms::base_view(_s),content(_content)
	#line 5 "Template.tmpl"
		{
	#line 5 "Template.tmpl"
		}
		#line 7 "Template.tmpl"
		virtual void sign_in_form() {
			#line 31 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form id=\"sign_in_form\">\n"
				"\t\t\t\t<input id=\"sign_in_user_name\" placeholder=\"Nombre de usuario\" type=\"text\" /><br />\n"
				"\t\t\t\t<input id=\"sign_in_password\" placeholder=\"Contraseña\" type=\"password\" /><br />\n"
				"\t\t\t\t<input class=\"btn pull-right\" type=\"submit\" value=\"Ingresar\" />\n"
				"\t\t\t</form>\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$('#sign_in_form').submit({\n"
				"\t\t\t\t\tpassword: $('#sign_in_password'),\n"
				"\t\t\t\t\tuser_name: $('#sign_in_user_name')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tevent.preventDefault();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar password = event.data.password.val();\n"
				"\t\t\t\t\tvar user_name = event.data.user_name.val();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_invalid_input = onInvalidInputSignIn(event.data.password, event.data.user_name);\n"
				"\t\t\t\t\tif(validateSignInInput(on_invalid_input, password, user_name)) {\n"
				"\t\t\t\t\t\tvar on_success = onSuccessSignIn();\n"
				"\t\t\t\t\t\tvar on_failure = onFailureSignIn();\n"
				"\t\t\t\t\t\tpostSignIn(on_success, on_failure, password, user_name);\n"
				"\t\t\t\t\t}\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 31 "Template.tmpl"
		} // end of template sign_in_form
		#line 33 "Template.tmpl"
		virtual void sign_out_form() {
			#line 42 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"btn pull-right\" id=\"sign_out_button\">Salir</a>\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$('#sign_out_button').click(function() {\n"
				"\t\t\t\t\tvar on_success = onSuccessSignOut();\n"
				"\t\t\t\t\tvar on_failure = onFailureSignOut()\n"
				"\t\t\t\t\tpostSignOut(on_success, on_failure);\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 42 "Template.tmpl"
		} // end of template sign_out_form
		#line 44 "Template.tmpl"
		virtual void toggle_anonymous_mode_form(bool anonymous_mode) {
			#line 46 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"btn pull-right\" id=\"toggle_anonymous_mode_button\">\n"
				"\t\t\t\t";
			#line 46 "Template.tmpl"
			if(anonymous_mode) {
				#line 48 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\tModo anónimo activado\n"
					"\t\t\t\t";
			#line 48 "Template.tmpl"
			}else{
				#line 50 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\tModo anónimo desactivado\n"
					"\t\t\t\t";
			#line 50 "Template.tmpl"
			}
			#line 59 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$('#toggle_anonymous_mode_button').click(function() {\n"
				"\t\t\t\t\tvar on_success = onSuccessToggleAnonymousMode($(this));\n"
				"\t\t\t\t\tvar on_failure = onFailureToggleAnonymousMode()\n"
				"\t\t\t\t\tpostToggleAnonymousMode(on_success, on_failure);\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 59 "Template.tmpl"
		} // end of template toggle_anonymous_mode_form
		#line 61 "Template.tmpl"
		virtual void create_user_form() {
			#line 116 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<legend>Registrate</legend>\n"
				"\t\t\t<form id=\"create_user_form\">\n"
				"\t\t\t\t<input id=\"create_user_user_name\" placeholder=\"Nombre de usuario\" type=\"text\" /><br />\n"
				"\t\t\t\t<input id=\"create_user_first_name\" placeholder=\"Nombre\" type=\"text\" /><br />\n"
				"\t\t\t\t<input id=\"create_user_last_name\" placeholder=\"Apellido\" type=\"text\" /><br />\n"
				"\t\t\t\t<input id=\"create_user_email\" placeholder=\"E-mail\" type=\"text\" /><br />\n"
				"\t\t\t\t<input id=\"create_user_password\" placeholder=\"Contraseña\" type=\"password\" /><br />\n"
				"\t\t\t\t<!--<input id=\"create_user_location\" placeholder=\"Localidad\" type=\"text\" /><br />-->\n"
				"\t\t\t\t<input id=\"create_user_birth_date\" placeholder=\"Fecha de nacimiento\" readonly type=\"text\" /><br />\n"
				"\t\t\t\t<select id=\"create_user_genre\">\n"
				"\t\t\t\t\t<option value=\"F\">Mujer</option>\n"
				"\t\t\t\t\t<option value=\"M\">Hombre</option>\n"
				"\t\t\t\t</select><br />\n"
				"\t\t\t\t<input class=\"btn pull-right\" type=\"submit\" value=\"Registrar\" />\n"
				"\t\t\t</form>\n"
				"\t\t\t<script>\n"
				"\t\t\t\tvar current_year = new Date().getFullYear();\n"
				"\t\t\t\t$('#create_user_birth_date').datepicker({\n"
				"\t\t\t\t\tshowOn:'focus',\n"
				"\t\t\t\t\tyearRange: (current_year - 100) + ':' + current_year,\n"
				"\t\t\t\t\tdateFormat:'dd/mm/yy',\n"
				"\t\t\t\t\tchangeMonth:true,\n"
				"\t\t\t\t\tchangeYear:true\n"
				"\t\t\t\t});\n"
				"\t\t\t\n"
				"\t\t\t\t$('#create_user_form').submit({\n"
				"\t\t\t\t\tbirth_date: $('#create_user_birth_date'),\n"
				"\t\t\t\t\temail: $('#create_user_email'),\n"
				"\t\t\t\t\tfirst_name: $('#create_user_first_name'),\n"
				"\t\t\t\t\tgenre: $('#create_user_genre'),\n"
				"\t\t\t\t\tlast_name: $('#create_user_last_name'),\n"
				"\t\t\t\t\tlocation: $('#create_user_location'),\n"
				"\t\t\t\t\tpassword: $('#create_user_password'),\n"
				"\t\t\t\t\tuser_name: $('#create_user_user_name')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tevent.preventDefault();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar birth_date = event.data.birth_date.val();\n"
				"\t\t\t\t\tvar email = event.data.email.val();\n"
				"\t\t\t\t\tvar first_name = $.trim(event.data.first_name.val());\n"
				"\t\t\t\t\tvar genre = event.data.genre.val();\n"
				"\t\t\t\t\tvar last_name = $.trim(event.data.last_name.val());\n"
				"\t\t\t\t\tvar location = $.trim(event.data.location.val());\n"
				"\t\t\t\t\tvar password = event.data.password.val();\n"
				"\t\t\t\t\tvar user_name = event.data.user_name.val();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_invalid_input = onInvalidInputCreateUser(event.data.email, event.data.first_name, event.data.last_name, event.data.location, event.data.password, event.data.user_name);\n"
				"\t\t\t\t\tif (validateCreateUserInput(on_invalid_input, email, first_name, last_name, location, password, user_name)) {\n"
				"\t\t\t\t\t\tvar on_success = onSuccessCreateUser();\n"
				"\t\t\t\t\t\tvar on_failure = onFailureCreateUser();\n"
				"\t\t\t\t\t\tpostCreateUser(on_success, on_failure, birth_date, email, first_name, genre, last_name, location, password, user_name);\n"
				"\t\t\t\t\t}\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 116 "Template.tmpl"
		} // end of template create_user_form
		#line 118 "Template.tmpl"
		virtual void create_problem_form() {
			#line 162 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<legend>Crear problema</legend>\n"
				"\t\t\t<form id=\"create_problem_form\">\n"
				"\t\t\t\t<input id=\"create_problem_description\" placeholder=\"Descripción del problema\" type=\"text\" /><br />\n"
				"\t\t\t\t<textarea id=\"create_problem_content\"></textarea><br />\n"
				"\t\t\t\t<input class=\"btn\" type=\"submit\" value=\"Crear problema\" />\n"
				"\t\t\t</form>\n"
				"\t\t\t<script>\n"
				"\t\t\t\tCKEDITOR.replace(create_problem_content, {\n"
				"\t\t\t\t\tcustomConfig: '',\n"
				"\t\t\t\t\textraPlugins: 'bbcode',\n"
				"\t\t\t\t\tfontSize_sizes: \"10/100%; 12/120%; 14/140%; 16/160%; 18/180%; 20/200%\",\n"
				"\t\t\t\t\tlanguage: 'es',\n"
				"\t\t\t\t\tremovePlugins: 'elementspath, colordialog',\n"
				"\t\t\t\t\tresize_enabled: false,\n"
				"\t\t\t\t\tskin: 'moono-dark',\n"
				"\t\t\t\t\ttoolbar: [\n"
				"\t\t\t\t\t\t[ 'Undo', '-', 'Redo' ],\n"
				"\t\t\t\t\t\t[ 'FontSize' ],\n"
				"\t\t\t\t\t\t[ 'Bold', 'Italic', 'Underline', '-', 'TextColor' ],\n"
				"\t\t\t\t\t\t[ 'RemoveFormat' ],\n"
				"\t\t\t\t\t\t[ 'Link', '-', 'Unlink' ],\n"
				"\t\t\t\t\t\t[ 'NumberedList', 'BulletedList', '-', 'Blockquote' ]\n"
				"\t\t\t\t\t]\n"
				"\t\t\t\t});\n"
				"\t\t\t\n"
				"\t\t\t\t$('#create_problem_form').submit({\n"
				"\t\t\t\t\tcontent: $('#create_problem_content'),\n"
				"\t\t\t\t\tdescription: $('#create_problem_description')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tevent.preventDefault();\n"
				"\t\t\t\t\tCKEDITOR.instances.create_problem_content.updateElement();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar content = $.trim(event.data.content.val());\n"
				"\t\t\t\t\tvar description = $.trim(event.data.description.val());\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_invalid_input = onInvalidInputCreateProblem(event.data.content, event.data.description);\n"
				"\t\t\t\t\tif (validateCreateProblemInput(on_invalid_input, content, description)) {\n"
				"\t\t\t\t\t\tvar on_success = onSuccessCreateProblem();\n"
				"\t\t\t\t\t\tvar on_failure = onFailureCreateProblem();\n"
				"\t\t\t\t\t\tpostCreateProblem(on_success, on_failure, content, description);\n"
				"\t\t\t\t\t}\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 162 "Template.tmpl"
		} // end of template create_problem_form
		#line 164 "Template.tmpl"
		virtual void vote_problem_form(std::string problem_id,int vote_balance) {
			#line 166 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"btn\" id=\"vote_problem_positive_button\">Votar positivamente</a>\n"
				"\t\t\t<div id=\"vote_problem_display\">";
			#line 166 "Template.tmpl"
			out()<<cppcms::filters::escape(vote_balance);
			#line 172 "Template.tmpl"
			out()<<"</div>\n"
				"\t\t\t<a class=\"btn\" id=\"vote_problem_negative_button\">Votar negativamente</a>\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$('#vote_problem_positive_button').click({\n"
				"\t\t\t\t\tdisplay: $('#vote_problem_display')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar problem_id = '";
			#line 172 "Template.tmpl"
			out()<<cppcms::filters::escape(problem_id);
			#line 182 "Template.tmpl"
			out()<<"';\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_success = onSuccessVoteProblem(event.data.display);\n"
				"\t\t\t\t\tvar on_failure = onFailureVoteProblem();\n"
				"\t\t\t\t\tpostVoteProblem(on_success, on_failure, true, problem_id);\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\t$('#vote_problem_negative_button').click({\n"
				"\t\t\t\t\tdisplay: $('#vote_problem_display')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar problem_id = '";
			#line 182 "Template.tmpl"
			out()<<cppcms::filters::escape(problem_id);
			#line 189 "Template.tmpl"
			out()<<"';\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_success = onSuccessVoteProblem(event.data.display);\n"
				"\t\t\t\t\tvar on_failure = onFailureVoteProblem();\n"
				"\t\t\t\t\tpostVoteProblem(on_success, on_failure, false, problem_id);\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 189 "Template.tmpl"
		} // end of template vote_problem_form
		#line 191 "Template.tmpl"
		virtual void create_solution_form(std::string problem_id) {
			#line 226 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<legend>Crear solución</legend>\n"
				"\t\t\t<form id=\"create_solution_form\">\n"
				"\t\t\t\t<input id=\"create_solution_description\" placeholder=\"Descripción de la solución\" type=\"text\" /><br />\n"
				"\t\t\t\t<textarea id=\"create_solution_content\"></textarea><br />\n"
				"\t\t\t\t<input class=\"btn\" type=\"submit\" value=\"Crear solución\" />\n"
				"\t\t\t</form>\n"
				"\t\t\t<script>\n"
				"\t\t\t\tCKEDITOR.replace(create_solution_content, {\n"
				"\t\t\t\t\tcustomConfig: '',\n"
				"\t\t\t\t\textraPlugins: 'bbcode',\n"
				"\t\t\t\t\tfontSize_sizes: \"10/100%; 12/120%; 14/140%; 16/160%; 18/180%; 20/200%\",\n"
				"\t\t\t\t\tlanguage: 'es',\n"
				"\t\t\t\t\tremovePlugins: 'elementspath, colordialog',\n"
				"\t\t\t\t\tresize_enabled: false,\n"
				"\t\t\t\t\tskin: 'moono-dark',\n"
				"\t\t\t\t\ttoolbar: [\n"
				"\t\t\t\t\t\t[ 'Undo', '-', 'Redo' ],\n"
				"\t\t\t\t\t\t[ 'FontSize' ],\n"
				"\t\t\t\t\t\t[ 'Bold', 'Italic', 'Underline', '-', 'TextColor' ],\n"
				"\t\t\t\t\t\t[ 'RemoveFormat' ],\n"
				"\t\t\t\t\t\t[ 'Link', '-', 'Unlink' ],\n"
				"\t\t\t\t\t\t[ 'NumberedList', 'BulletedList', '-', 'Blockquote' ]\n"
				"\t\t\t\t\t]\n"
				"\t\t\t\t});\n"
				"\t\t\t\n"
				"\t\t\t\t$('#create_solution_form').submit({\n"
				"\t\t\t\t\tcontent: $('#create_solution_content'),\n"
				"\t\t\t\t\tdescription: $('#create_solution_description')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tevent.preventDefault();\n"
				"\t\t\t\t\tCKEDITOR.instances.create_solution_content.updateElement();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar content = $.trim(event.data.content.val());\n"
				"\t\t\t\t\tvar description = $.trim(event.data.description.val());\n"
				"\t\t\t\t\tvar problem_id =  '";
			#line 226 "Template.tmpl"
			out()<<cppcms::filters::escape(problem_id);
			#line 236 "Template.tmpl"
			out()<<"';\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_invalid_input = onInvalidInputCreateSolution(event.data.content, event.data.description);\n"
				"\t\t\t\t\tif (validateCreateSolutionInput(on_invalid_input, content, description)) {\n"
				"\t\t\t\t\t\tvar on_success = onSuccessCreateSolution(problem_id);\n"
				"\t\t\t\t\t\tvar on_failure = onFailureCreateSolution();\n"
				"\t\t\t\t\t\tpostCreateSolution(on_success, on_failure, content, description, problem_id);\n"
				"\t\t\t\t\t}\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 236 "Template.tmpl"
		} // end of template create_solution_form
		#line 238 "Template.tmpl"
		virtual void vote_solution_form(std::string solution_id,int vote_balance) {
			#line 240 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"btn\" id=\"vote_solution_positive_button\">Votar positivamente</a>\n"
				"\t\t\t<div id=\"vote_solution_display\">";
			#line 240 "Template.tmpl"
			out()<<cppcms::filters::escape(vote_balance);
			#line 246 "Template.tmpl"
			out()<<"</div>\n"
				"\t\t\t<a class=\"btn\" id=\"vote_solution_negative_button\">Votar negativamente</a>\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$('#vote_solution_positive_button').click({\n"
				"\t\t\t\t\tdisplay: $('#vote_solution_display')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar solution_id = '";
			#line 246 "Template.tmpl"
			out()<<cppcms::filters::escape(solution_id);
			#line 256 "Template.tmpl"
			out()<<"';\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_success = onSuccessVoteSolution(event.data.display);\n"
				"\t\t\t\t\tvar on_failure = onFailureVoteSolution();\n"
				"\t\t\t\t\tpostVoteSolution(on_success, on_failure, true, solution_id);\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\t$('#vote_solution_negative_button').click({\n"
				"\t\t\t\t\tdisplay: $('#vote_solution_display')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar solution_id = '";
			#line 256 "Template.tmpl"
			out()<<cppcms::filters::escape(solution_id);
			#line 263 "Template.tmpl"
			out()<<"';\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_success = onSuccessVoteSolution(event.data.display);\n"
				"\t\t\t\t\tvar on_failure = onFailureVoteSolution();\n"
				"\t\t\t\t\tpostVoteSolution(on_success, on_failure, false, solution_id);\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 263 "Template.tmpl"
		} // end of template vote_solution_form
		#line 265 "Template.tmpl"
		virtual void create_clarification_form(std::string associated_publication_id) {
			#line 276 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form id=\"create_clarification_form\">\n"
				"\t\t\t\t<textarea id=\"create_clarification_question\" placeholder=\"Solicitar una aclaración...\"></textarea>\n"
				"\t\t\t\t<input class=\"btn\" type=\"submit\" value=\"Publicar pregunta\" />\n"
				"\t\t\t</form>\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$('#create_clarification_form').submit({\n"
				"\t\t\t\t\tquestion: $('#create_clarification_question')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tevent.preventDefault();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar associated_publication_id = '";
			#line 276 "Template.tmpl"
			out()<<cppcms::filters::escape(associated_publication_id);
			#line 287 "Template.tmpl"
			out()<<"';\n"
				"\t\t\t\t\tvar question = $.trim(event.data.question.val());\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_invalid_input = onInvalidInputCreateClarification(event.data.question);\n"
				"\t\t\t\t\tif (validateCreateClarificationInput(on_invalid_input, question)) {\n"
				"\t\t\t\t\t\tvar on_success = onSuccessCreateClarification();\n"
				"\t\t\t\t\t\tvar on_failure = onFailureCreateClarification();\n"
				"\t\t\t\t\t\tpostCreateClarification(on_success, on_failure, associated_publication_id, question);\n"
				"\t\t\t\t\t}\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 287 "Template.tmpl"
		} // end of template create_clarification_form
		#line 289 "Template.tmpl"
		virtual void answer_clarification_form(std::string clarification_id) {
			#line 290 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form id=\"answer_clarification_form_";
			#line 290 "Template.tmpl"
			out()<<cppcms::filters::escape(clarification_id);
			#line 291 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t<textarea id=\"answer_clarification_answer_";
			#line 291 "Template.tmpl"
			out()<<cppcms::filters::escape(clarification_id);
			#line 295 "Template.tmpl"
			out()<<"\" placeholder=\"Responder...\"></textarea>\n"
				"\t\t\t\t<input class=\"btn\" type=\"submit\" value=\"Publicar respuesta\" />\n"
				"\t\t\t</form>\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$('#answer_clarification_form_";
			#line 295 "Template.tmpl"
			out()<<cppcms::filters::escape(clarification_id);
			#line 296 "Template.tmpl"
			out()<<"').submit({\n"
				"\t\t\t\t\tanswer: $('#answer_clarification_answer_";
			#line 296 "Template.tmpl"
			out()<<cppcms::filters::escape(clarification_id);
			#line 301 "Template.tmpl"
			out()<<"')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tevent.preventDefault();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar answer = $.trim(event.data.answer.val());\n"
				"\t\t\t\t\tvar clarification_id = '";
			#line 301 "Template.tmpl"
			out()<<cppcms::filters::escape(clarification_id);
			#line 311 "Template.tmpl"
			out()<<"';\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar on_invalid_input = onInvalidInputAnswerClarification(event.data.answer);\n"
				"\t\t\t\t\tif (validateAnswerClarificationInput(on_invalid_input, answer)) {\n"
				"\t\t\t\t\t\tvar on_success = onSuccessAnswerClarification();\n"
				"\t\t\t\t\t\tvar on_failure = onFailureAnswerClarification();\n"
				"\t\t\t\t\t\tpostAnswerClarification(on_success, on_failure, answer, clarification_id);\n"
				"\t\t\t\t\t}\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 311 "Template.tmpl"
		} // end of template answer_clarification_form
		#line 313 "Template.tmpl"
		virtual void clarifications(ClarificationList clarifications,PublicationPointer publication) {
			#line 314 "Template.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 314 "Template.tmpl"
			if(! clarifications->empty()) {
				#line 329 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t<div id=\"pci_clarifications_main_container\">\n"
					"\t\t\t\t\t<div class=\"pci_horizontal_line\"></div>\n"
					"\t\t\t\t\t<div class=\"pci_clarifications_row_container\">\n"
					"\t\t\t\t\t\t<div class=\"pci_clarifications_question_container\">\n"
					"\t\t\t\t\t\t\t<div class=\"pci_clarifications_column_header pci_clarifications_question_content\">\n"
					"\t\t\t\t\t\t\t\tPregunta\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
					"\t\t\t\t\t\t\t<div class=\"pci_clarifications_answer_content pci_clarifications_column_header\">\n"
					"\t\t\t\t\t\t\t\tRespuesta\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t</div>\n"
					"\t\t\t\t\t";
				#line 329 "Template.tmpl"
				if((*clarifications).begin()!=(*clarifications).end()) {
					#line 330 "Template.tmpl"
					out()<<"\n"
						"\t \t\t\t\t\t";
					#line 330 "Template.tmpl"
					for(CPPCMS_TYPEOF((*clarifications).begin()) clarification_ptr=(*clarifications).begin(),clarification_ptr_end=(*clarifications).end();clarification_ptr!=clarification_ptr_end;++clarification_ptr) {
					#line 330 "Template.tmpl"
					CPPCMS_TYPEOF(*clarification_ptr) &clarification=*clarification_ptr;
						#line 335 "Template.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t<div class=\"pci_clarifications_row_container\">\n"
							"\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_question_container\">\n"
							"\t\t\t\t\t\t\t\t\t<div class=\"pci_box_content pci_clarifications_question_content\">\n"
							"\t\t\t\t\t\t\t\t\t\t<span class=\"pci_text_clarification\">\n"
							"\t\t\t\t\t\t\t\t\t\t\t";
						#line 335 "Template.tmpl"
						out()<<cppcms::filters::escape(clarification->question);
						#line 340 "Template.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t\t\t</span>\n"
							"\t\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
							"\t\t\t\t\t\t\t\t\t";
						#line 340 "Template.tmpl"
						if(! clarification->answer.empty()) {
							#line 343 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t\t<div class=\"pci_box_content pci_clarifications_answer_content\">\n"
								"\t\t\t\t\t\t\t\t\t\t\t<span class=\"pci_text_clarification\">\n"
								"\t\t\t\t\t\t\t\t\t\t\t\t";
							#line 343 "Template.tmpl"
							out()<<cppcms::filters::escape(clarification->answer);
							#line 346 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t\t\t</span>\n"
								"\t\t\t\t\t\t\t\t\t\t</div>\n"
								"\t\t\t\t\t\t\t\t\t";
						#line 346 "Template.tmpl"
						}else{
							#line 347 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t\t";
							#line 347 "Template.tmpl"
							if(content.user_signed_in && content.user_name.compare(publication->creator_user_name) == 0) {
								#line 349 "Template.tmpl"
								out()<<"\n"
									"\t\t\t\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_answer_content\">\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t";
								#line 349 "Template.tmpl"
								answer_clarification_form(clarification->id);
								#line 351 "Template.tmpl"
								out()<<"\n"
									"\t\t\t\t\t\t\t\t\t\t\t</div>\n"
									"\t\t\t\t\t\t\t\t\t\t";
							#line 351 "Template.tmpl"
							} // endif
							#line 352 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t";
						#line 352 "Template.tmpl"
						}
						#line 355 "Template.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t</div>\n"
							"\t  \t\t\t\t\t";
					#line 355 "Template.tmpl"
					} // end of item
					#line 356 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t";
				#line 356 "Template.tmpl"
				}
				#line 358 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t</div>\n"
					"\t\t\t";
			#line 358 "Template.tmpl"
			} // endif
			#line 359 "Template.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 359 "Template.tmpl"
			if(content.user_signed_in && content.user_name.compare(publication->creator_user_name) != 0) {
				#line 360 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t";
				#line 360 "Template.tmpl"
				create_clarification_form(publication->id);
				#line 361 "Template.tmpl"
				out()<<"\n"
					"\t\t\t";
			#line 361 "Template.tmpl"
			} // endif
			#line 362 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 362 "Template.tmpl"
		} // end of template clarifications
		#line 365 "Template.tmpl"
		virtual void header_bar() {
			#line 369 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_header_bar_main_container\">\n"
				"\t\t\t\t<div id=\"pci_header_bar_central_container\">\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_logo_container\">\n"
				"\t\t\t\t\t\t<a href=\"";
			#line 369 "Template.tmpl"
			content.app().mapper().map(out(),"/");
			#line 374 "Template.tmpl"
			out()<<"\" >\n"
				"\t\t\t\t\t\t\t<div id=\"pci_header_bar_logo\"></div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_sign_container\">\n"
				"\t\t\t\t\t \t";
			#line 374 "Template.tmpl"
			if(content.user_signed_in) {
				#line 375 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t";
				#line 375 "Template.tmpl"
				sign_out_form();
				#line 377 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t \t\t<div id=\"pci_header_bar_user_name_container\">\n"
					"\t\t\t\t\t\t\t\t<a href=\"";
				#line 377 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 379 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t \t\t\t<span id=\"pci_header_bar_user_name\">\n"
					"\t\t\t\t\t\t \t\t\t\t";
				#line 379 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_first_name);
				#line 379 "Template.tmpl"
				out()<<" ";
				#line 379 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_last_name);
				#line 383 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t \t\t\t</span>\n"
					"\t\t\t\t\t \t\t\t</a>\n"
					"\t\t\t\t \t\t\t</div>\n"
					"\t\t\t\t\t \t\t";
				#line 383 "Template.tmpl"
				toggle_anonymous_mode_form(content.anonymous_mode);
				#line 384 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
			#line 384 "Template.tmpl"
			}else{
				#line 391 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a>\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\" id=\"pci_header_bar_button_sign_in\">\n"
					"\t\t\t\t\t\t\t\t\tIngresar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t\t<div id=\"pci_header_bar_sign_in_container\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 391 "Template.tmpl"
				sign_in_form();
				#line 393 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 393 "Template.tmpl"
			}
			#line 397 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 397 "Template.tmpl"
		} // end of template header_bar
		#line 399 "Template.tmpl"
		virtual void information_footer() {
			#line 413 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_information_footer_main_container\">\n"
				"\t\t\t\t<div id=\"pci_information_footer_central_container\">\n"
				"\t\t\t\t\t<div id=\"pci_information_footer_logo_extended_container\">\n"
				"\t\t\t\t\t\t<div id=\"pci_information_footer_logo_extended\"></div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_information_footer_link_container\">\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\t<span class=\"pci_text_footer\">\n"
				"\t\t\t\t\t\t\t\t\tPCI\n"
				"\t\t\t\t\t\t\t\t</span>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 413 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 418 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAcerca de\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 418 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 423 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tFilosofía\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 423 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 435 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\t<span class=\"pci_text_footer\">\n"
				"\t\t\t\t\t\t\t\t\tHeader 2\n"
				"\t\t\t\t\t\t\t\t</span>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 435 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 440 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 440 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 445 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 445 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 457 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\t<span class=\"pci_text_footer\">\n"
				"\t\t\t\t\t\t\t\t\tSoporte\n"
				"\t\t\t\t\t\t\t\t</span>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 457 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 462 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAyuda\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 462 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 467 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCondiciones de servicio\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 467 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 475 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCopyright\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 475 "Template.tmpl"
		} // end of template information_footer
		#line 478 "Template.tmpl"
		virtual void navigation_menu() {
			#line 480 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_navigation_menu_main_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 480 "Template.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 485 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_problems_button\">\n"
				"\t\t\t\t\t\tProblemas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 485 "Template.tmpl"
			content.app().mapper().map(out(),"/ideas");
			#line 490 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_ideas_button\">\n"
				"\t\t\t\t\t\tIdeas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t";
			#line 490 "Template.tmpl"
			if(content.user_signed_in) {
				#line 492 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<div class=\"pci_horizontal_line\" ></div>\n"
					"\t\t\t\t\t<a href=\"";
				#line 492 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 497 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_profile_button\">\n"
					"\t\t\t\t\t\t\tPerfil\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t</a>\n"
					"\t\t\t\t";
			#line 497 "Template.tmpl"
			} // endif
			#line 499 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 499 "Template.tmpl"
		} // end of template navigation_menu
		#line 501 "Template.tmpl"
		virtual void problem_description(ProblemPointer problem) {
			#line 518 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div class=\"pci_box_container pci_problems_problem_description\">\n"
				"\t\t\t\t<div class=\"row-fluid\">\n"
				"\t\t\t\t\t<div class=\"span2\">\n"
				"\t\t\t\t\t\t<div class=\"row-fluid pci_problems_votes\"> <!-- Votes & Answers -->\n"
				"\t\t\t\t\t\t\t<div class=\"span6\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"number\">125</div>\n"
				"\t\t\t\t\t\t\t\t<div>Votos</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"span6\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"number\">6</div>\n"
				"\t\t\t\t\t\t\t\t<div>Soluciones</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div class=\"span9\">\n"
				"\t\t\t\t\t\t<div class=\"row-fluid\">\t\t\t\t\n"
				"\t\t\t\t\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 518 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem->id));
			#line 519 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t";
			#line 519 "Template.tmpl"
			out()<<cppcms::filters::escape(problem->description);
			#line 522 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t\t\t\t\t";
			#line 522 "Template.tmpl"
			if(problem->is_anonymous) {
				#line 524 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t\t<i>Publicado anónimamente</i>\n"
					"\t\t\t\t\t\t\t\t";
			#line 524 "Template.tmpl"
			}else{
				#line 525 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 525 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(problem->creator_user_name));
				#line 525 "Template.tmpl"
				out()<<"\">";
				#line 525 "Template.tmpl"
				out()<<cppcms::filters::escape(problem->creator_user_name);
				#line 526 "Template.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t\t\t\t\t";
			#line 526 "Template.tmpl"
			}
			#line 527 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t- ";
			#line 527 "Template.tmpl"
			out()<<cppcms::filters::escape(problem->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 531 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t</span>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t";
			#line 531 "Template.tmpl"
			if(problem->is_solved) {
				#line 535 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<div class=\"span1\">\n"
					"\t\t\t\t\t\t\t<div class=\"tick_on\"></div>\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t";
			#line 535 "Template.tmpl"
			} // endif
			#line 538 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\t\t\t\t\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 538 "Template.tmpl"
		} // end of template problem_description
		#line 540 "Template.tmpl"
		virtual void publication_description(PublicationPointer publication) {
			#line 541 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 541 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(publication->id));
			#line 542 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t";
			#line 542 "Template.tmpl"
			out()<<cppcms::filters::escape(publication->description);
			#line 545 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t";
			#line 545 "Template.tmpl"
			if(publication->is_anonymous) {
				#line 547 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Publicado anónimamente</i>\n"
					"\t\t\t\t";
			#line 547 "Template.tmpl"
			}else{
				#line 548 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 548 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(publication->creator_user_name));
				#line 548 "Template.tmpl"
				out()<<"\">";
				#line 548 "Template.tmpl"
				out()<<cppcms::filters::escape(publication->creator_user_name);
				#line 549 "Template.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t";
			#line 549 "Template.tmpl"
			}
			#line 550 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t- ";
			#line 550 "Template.tmpl"
			out()<<cppcms::filters::escape(publication->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 552 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</span>\n"
				"\t\t";
		#line 552 "Template.tmpl"
		} // end of template publication_description
		#line 554 "Template.tmpl"
		virtual void solution_description(ProblemPointer problem,SolutionPointer solution) {
			#line 555 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 555 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem->id), cppcms::filters::urlencode(solution->id));
			#line 556 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t";
			#line 556 "Template.tmpl"
			out()<<cppcms::filters::escape(solution->description);
			#line 559 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t";
			#line 559 "Template.tmpl"
			if(solution->is_anonymous) {
				#line 561 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Publicado anónimamente</i>\n"
					"\t\t\t\t";
			#line 561 "Template.tmpl"
			}else{
				#line 563 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Por \n"
					"\t\t\t\t\t\t<a class=\"pci_link_user_name\" href=\"";
				#line 563 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(solution->creator_user_name));
				#line 564 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t";
				#line 564 "Template.tmpl"
				out()<<cppcms::filters::escape(solution->creator_user_name);
				#line 567 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t</i>\n"
					"\t\t\t\t";
			#line 567 "Template.tmpl"
			}
			#line 568 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t- ";
			#line 568 "Template.tmpl"
			out()<<cppcms::filters::escape(solution->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 570 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</span>\n"
				"\t\t";
		#line 570 "Template.tmpl"
		} // end of template solution_description
		#line 573 "Template.tmpl"
		virtual void toolbar_problems() {
			#line 575 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problems_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 575 "Template.tmpl"
			content.app().mapper().map(out(),"/new_problem");
			#line 581 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problems_button\" id=\"pci_toolbar_problems_new_problem_button\">\n"
				"\t\t\t\t\t\tNuevo problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 581 "Template.tmpl"
		} // end of template toolbar_problems
		#line 584 "Template.tmpl"
		virtual void toolbar_problem(std::string problem_id) {
			#line 586 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problem_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 586 "Template.tmpl"
			content.app().mapper().map(out(),"/new_solution", cppcms::filters::urlencode(problem_id));
			#line 592 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problem_button\" id=\"pci_toolbar_problem_new_solution_button\">\n"
				"\t\t\t\t\t\tPlantear solución\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 592 "Template.tmpl"
		} // end of template toolbar_problem
		#line 595 "Template.tmpl"
		virtual void toolbar_solution(std::string problem_id) {
			#line 597 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_solution_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 597 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem_id));
			#line 603 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_solution_button\" id=\"pci_toolbar_solution_go_back_button\">\n"
				"\t\t\t\t\t\tVolver al problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 603 "Template.tmpl"
		} // end of template toolbar_solution
		#line 606 "Template.tmpl"
		virtual void css_links() {
			#line 610 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/template.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"    \t\t<link href=\"/lib/bootstrap/css/bootstrap.min.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"    \t\t<link href=\"/lib/xbbcode/xbbcode.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 610 "Template.tmpl"
		} // end of template css_links
		#line 613 "Template.tmpl"
		virtual void js_links() {
			#line 624 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<script src=\"/js/utilities.js\"></script>\n"
				"\t\t\t<script src=\"/js/logic.js\"></script>\n"
				"\t\t\t<script src=\"/lib/jquery/jquery-1.9.0.min.js\"></script>\n"
				"\t\t\t<script src=\"/lib/xbbcode/xbbcode.js\"></script>\n"
				"\t\t\t\n"
				"\t\t\t<!-- HTML5 shim, for IE6-8 support of HTML5 elements -->\n"
				"\t    \t<!--[if lt IE 9]>\n"
				"\t      \t\t<script src=\"http://html5shim.googlecode.com/svn/trunk/html5.js\"></script>\n"
				"\t    \t<![endif]-->\n"
				"    \t\t<script src=\"/lib/bootstrap/js/bootstrap.min.js\"></script>\n"
				"\t\t";
		#line 624 "Template.tmpl"
		} // end of template js_links
		#line 627 "Template.tmpl"
		virtual void javascript_code() {
			#line 635 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t\tconfigureTextfield('pci_sign_in_textfield_user_name');\n"
				"\t\t\t\t\tconfigurePasswordfield('pci_sign_in_textfield_password');\n"
				"\t\t\t\t\tconfigureSignInFormContainer('pci_header_bar_sign_in_container', 'pci_header_bar_button_sign_in');\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 635 "Template.tmpl"
		} // end of template javascript_code
		#line 638 "Template.tmpl"
		virtual void page_content() {
			#line 639 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 639 "Template.tmpl"
		} // end of template page_content
		#line 642 "Template.tmpl"
		virtual void render() {
			#line 646 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<!DOCTYPE html>\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 646 "Template.tmpl"
			css_links();
			#line 647 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t";
			#line 647 "Template.tmpl"
			js_links();
			#line 648 "Template.tmpl"
			out()<<" <!-- Placed here for faster page loading -->\n"
				"\t\t\t\t\t";
			#line 648 "Template.tmpl"
			javascript_code();
			#line 650 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 650 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 654 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t";
			#line 654 "Template.tmpl"
			page_content();
			#line 657 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 657 "Template.tmpl"
		} // end of template render
	#line 660 "Template.tmpl"
	}; // end of class template_view
#line 661 "Template.tmpl"
} // end of namespace pci_skin
#line 2 "Debug.tmpl"
#include "logic/ViewContent.h" 
#line 4 "Debug.tmpl"
namespace pci_skin {
	#line 5 "Debug.tmpl"
	struct debug_view :public cppcms::base_view
	#line 5 "Debug.tmpl"
	{
	#line 5 "Debug.tmpl"
		ViewContent::TemplateContent &content;
	#line 5 "Debug.tmpl"
		debug_view(std::ostream &_s,ViewContent::TemplateContent &_content): cppcms::base_view(_s),content(_content)
	#line 5 "Debug.tmpl"
		{
	#line 5 "Debug.tmpl"
		}
		#line 7 "Debug.tmpl"
		virtual void pci_logo() {
			#line 8 "Debug.tmpl"
			out()<<"\n"
				"\t\t\t<a href=\"";
			#line 8 "Debug.tmpl"
			content.app().mapper().map(out(),"");
			#line 11 "Debug.tmpl"
			out()<<"\">\n"
				"\t\t\t\t<div class=\"pci_logo\"></div>\n"
				"\t\t\t</a>\n"
				"\t\t";
		#line 11 "Debug.tmpl"
		} // end of template pci_logo
		#line 13 "Debug.tmpl"
		virtual void button(String label,String url,String classes,String id) {
			#line 14 "Debug.tmpl"
			out()<<"\n"
				"\t\t\t<a href=\"";
			#line 14 "Debug.tmpl"
			out()<<cppcms::filters::escape(url);
			#line 15 "Debug.tmpl"
			out()<<"\">\n"
				"\t\t\t\t<div class=\"";
			#line 15 "Debug.tmpl"
			out()<<cppcms::filters::escape(classes);
			#line 15 "Debug.tmpl"
			out()<<"\" id=\"";
			#line 15 "Debug.tmpl"
			out()<<cppcms::filters::escape(id);
			#line 16 "Debug.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t";
			#line 16 "Debug.tmpl"
			out()<<cppcms::filters::escape(label);
			#line 19 "Debug.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</a>\n"
				"\t\t";
		#line 19 "Debug.tmpl"
		} // end of template button
		#line 21 "Debug.tmpl"
		virtual void form_sign_in() {
			#line 22 "Debug.tmpl"
			out()<<"\n"
				"\t\t";
		#line 22 "Debug.tmpl"
		} // end of template form_sign_in
		#line 24 "Debug.tmpl"
		virtual void header_bar() {
			#line 28 "Debug.tmpl"
			out()<<"\n"
				"\t\t\t<div class=\"container_header_bar\">\n"
				"\t\t\t\t<div class=\"container_header_bar_central\">\n"
				"\t\t\t\t\t<div class=\"container_header_bar_left\">\n"
				"\t\t\t\t\t\t";
			#line 28 "Debug.tmpl"
			pci_logo();
			#line 31 "Debug.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div class=\"container_header_bar_right\">\n"
				"\t\t\t\t\t \t";
			#line 31 "Debug.tmpl"
			if(content.user_signed_in) {
				#line 32 "Debug.tmpl"
				out()<<"\n"
					"\t\t\t\t\t \t\t";
				#line 32 "Debug.tmpl"
				button("Salir","javascript:void(0)","button_header_bar","button_sign_out");
				#line 34 "Debug.tmpl"
				out()<<"\n"
					"\t\t\t\t\t \t\t<div id=\"pci_header_bar_user_name_container\">\n"
					"\t\t\t\t\t\t\t\t<a href=\"";
				#line 34 "Debug.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 36 "Debug.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t \t\t\t<span id=\"pci_header_bar_user_name\">\n"
					"\t\t\t\t\t\t \t\t\t\t";
				#line 36 "Debug.tmpl"
				out()<<cppcms::filters::escape(content.user_first_name);
				#line 36 "Debug.tmpl"
				out()<<" ";
				#line 36 "Debug.tmpl"
				out()<<cppcms::filters::escape(content.user_last_name);
				#line 40 "Debug.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t \t\t\t</span>\n"
					"\t\t\t\t\t \t\t\t</a>\n"
					"\t\t\t\t \t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 40 "Debug.tmpl"
			}else{
				#line 41 "Debug.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t";
				#line 41 "Debug.tmpl"
				button("Ingresar","javascript:void(0)","button_header_bar","button_toggle_sign_in");
				#line 43 "Debug.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<div id=\"container_header_bar_sign_in\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 43 "Debug.tmpl"
				form_sign_in();
				#line 45 "Debug.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 45 "Debug.tmpl"
			}
			#line 49 "Debug.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 49 "Debug.tmpl"
		} // end of template header_bar
		#line 51 "Debug.tmpl"
		virtual void render() {
			#line 186 "Debug.tmpl"
			out()<<"\n"
				"\t\t\t\n"
				"\t\t\t\n"
				"\t\t\t\n"
				"\t\t\t\n"
				"<!DOCTYPE html>\n"
				"<html>\n"
				"\t<head>\n"
				"\t\t<link href=\"/css/Debug.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t<script src=\"/js/logic.js\"></script>\n"
				"\t\t<script src=\"/lib/jquery/jquery-1.9.0.min.js\"></script>\n"
				"\t\t<script>\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t\n"
				"\t\t\t\t// TODO: always remember to trim the string obtain from fields\n"
				"\t\t\t\t\n"
				"\t\t\t\t$('#sign_in_submit').click({\n"
				"\t\t\t\t\tpassword: $('#sign_in_password'),\n"
				"\t\t\t\t\tuser_name: $('#sign_in_user_name')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar password = event.data.password.val();\n"
				"\t\t\t\t\tvar user_name = event.data.user_name.val();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar onInvalidInput = onInvalidInputSignIn(event.data.password, event.data.user_name);\n"
				"\t\t\t\t\tif (validateSignInInput(onInvalidInput, password, user_name))\n"
				"\t\t\t\t\t\tpostSignIn(onSuccessSignIn(), onFailureSignIn(), password, user_name);\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\t$('#sign_out_submit').click(function() {\n"
				"\t\t\t\t\tpostSignOut(onSuccessSignOut(), onFailureSignOut());\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\t$('#create_user_submit').click({\n"
				"\t\t\t\t\tbirth_date: $('#create_user_birth_date'),\n"
				"\t\t\t\t\temail: $('#create_user_email'),\n"
				"\t\t\t\t\tfirst_name: $('#create_user_first_name'),\n"
				"\t\t\t\t\tgenre: $('#create_user_genre'),\n"
				"\t\t\t\t\tlast_name: $('#create_user_last_name'),\n"
				"\t\t\t\t\tlocation: $('#create_user_location'),\n"
				"\t\t\t\t\tpassword: $('#create_user_password'),\n"
				"\t\t\t\t\tuser_name: $('#create_user_user_name')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar birth_date = event.data.birth_date.val();\n"
				"\t\t\t\t\tvar email = event.data.email.val();\n"
				"\t\t\t\t\tvar first_name = $.trim(event.data.first_name.val());\n"
				"\t\t\t\t\tvar genre = event.data.genre.val();\n"
				"\t\t\t\t\tvar last_name = $.trim(event.data.last_name.val());\n"
				"\t\t\t\t\tvar location = $.trim(event.data.location.val());\n"
				"\t\t\t\t\tvar password = event.data.password.val();\n"
				"\t\t\t\t\tvar user_name = event.data.user_name.val();\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tvar onInvalidInput = onInvalidInputCreateUser(event.data.email, event.data.first_name, event.data.last_name, event.data.location, event.data.password, event.data.user_name);\n"
				"\t\t\t\t\tif (validateCreateUserInput(onInvalidInput, email, first_name, last_name, location, password, user_name))\n"
				"\t\t\t\t\t\tpostCreateUser(onSuccessCreateUser(), onFailureCreateUser(), birth_date, email, first_name, genre, last_name, location, password, user_name);\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\t$('#delete_user_submit').click({\n"
				"\t\t\t\t\tuser_name: $('#delete_user_user_name')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar user_name = event.data.user_name.val();\n"
				"\t\t\t\t\tpostDeleteUser(onSuccessDeleteUser(), onFailureDeleteUser(), user_name);\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\t$('#delete_problem_submit').click({\n"
				"\t\t\t\t\tproblem_id: $('#delete_problem_problem_id')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar problem_id = event.data.problem_id.val();\n"
				"\t\t\t\t\tpostDeleteProblem(onSuccessDeleteProblem(), onFailureDeleteProblem(), problem_id);\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\t$('#delete_solution_submit').click({\n"
				"\t\t\t\t\tsolution_id: $('#delete_solution_solution_id')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar solution_id = event.data.solution_id.val();\n"
				"\t\t\t\t\tpostDeleteSolution(onSuccessDeleteSolution(), onFailureDeleteSolution(), solution_id);\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\t$('#delete_clarification_submit').click({\n"
				"\t\t\t\t\tclarification_id: $('#delete_clarification_clarification_id')\n"
				"\t\t\t\t}, function(event) {\n"
				"\t\t\t\t\tvar clarification_id = event.data.clarification_id.val();\n"
				"\t\t\t\t\tpostDeleteClarification(onSuccessDeleteClarification(), onFailureDeleteClarification(), clarification_id);\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t});\n"
				"\t\t</script>\n"
				"\t</head>\n"
				"\t<body>\n"
				"\t\t<h2>Sign in</h2>\n"
				"\t\t<label for=\"sign_in_user_name\">user_name</label><input id=\"sign_in_user_name\" type=\"text\"><br />\n"
				"\t\t<label for=\"sign_in_password\">password</label><input id=\"sign_in_password\" type=\"password\"><br />\n"
				"\t\t<input id=\"sign_in_submit\" type=\"submit\" value=\"Sign in\" />\n"
				"\t\t<div class=\"pci_horizontal_line\"></div>\n"
				"\t\t\n"
				"\t\t<h2>Sign out</h2>\n"
				"\t\t<input id=\"sign_out_submit\" type=\"submit\" value=\"Sign out\" /><div class=\"pci_horizontal_line\"></div>\n"
				"\t\t\n"
				"\t\t<h2>Create user</h2>\n"
				"\t\t<label for=\"create_user_birth_date\">birth_date</label><input id=\"create_user_birth_date\" type=\"text\"><br />\n"
				"\t\t<label for=\"create_user_email\">email</label><input id=\"create_user_email\" type=\"text\"><br />\n"
				"\t\t<label for=\"create_user_first_name\">first_name</label><input id=\"create_user_first_name\" type=\"text\"><br />\n"
				"\t\t<label for=\"create_user_genre\">genre</label><input id=\"create_user_genre\" type=\"text\"><br />\n"
				"\t\t<label for=\"create_user_last_name\">last_name</label><input id=\"create_user_last_name\" type=\"text\"><br />\n"
				"\t\t<label for=\"create_user_location\">location</label><input id=\"create_user_location\" type=\"text\"><br />\n"
				"\t\t<label for=\"create_user_password\">password</label><input id=\"create_user_password\" type=\"password\"><br />\n"
				"\t\t<label for=\"create_user_user_name\">user_name</label><input id=\"create_user_user_name\" type=\"text\"><br />\n"
				"\t\t<input id=\"create_user_submit\" type=\"submit\" value=\"Create user\" />\n"
				"\t\t<div class=\"pci_horizontal_line\"></div>\n"
				"\t\t\n"
				"\t\t<h2>Delete user</h2>\n"
				"\t\t<label for=\"delete_user_user_name\">user_name</label><input id=\"delete_user_user_name\" type=\"text\"><br />\n"
				"\t\t<input id=\"delete_user_submit\" type=\"submit\" value=\"Delete user\" />\n"
				"\t\t<div class=\"pci_horizontal_line\"></div>\n"
				"\t\t\n"
				"\t\t<h2>Delete problem</h2>\n"
				"\t\t<label for=\"delete_problem_problem_id\">problem_id</label><input id=\"delete_problem_problem_id\" type=\"text\"><br />\n"
				"\t\t<input id=\"delete_problem_submit\" type=\"submit\" value=\"Delete problem\" />\n"
				"\t\t<div class=\"pci_horizontal_line\"></div>\n"
				"\t\t\n"
				"\t\t<h2>Delete solution</h2>\n"
				"\t\t<label for=\"delete_solution_solution_id\">solution_id</label><input id=\"delete_solution_solution_id\" type=\"text\"><br />\n"
				"\t\t<input id=\"delete_solution_submit\" type=\"submit\" value=\"Delete solution\" />\n"
				"\t\t<div class=\"pci_horizontal_line\"></div>\n"
				"\t\t\n"
				"\t\t<h2>Delete clarification</h2>\n"
				"\t\t<label for=\"delete_clarification_clarification_id\">clarification_id</label><input id=\"delete_clarification_clarification_id\" type=\"text\"><br />\n"
				"\t\t<input id=\"delete_clarification_submit\" type=\"submit\" value=\"Delete clarification\" />\n"
				"\t\t<div class=\"pci_horizontal_line\"></div>\n"
				"\t</body>\n"
				"</html>\n"
				"\n"
				"\n"
				"\n"
				"\n"
				"\n"
				"\t\t";
		#line 186 "Debug.tmpl"
		} // end of template render
	#line 187 "Debug.tmpl"
	}; // end of class debug_view
#line 188 "Debug.tmpl"
} // end of namespace pci_skin
#line 2 "Index.tmpl"
#include "logic/ViewContent.h" 
#line 4 "Index.tmpl"
namespace pci_skin {
	#line 5 "Index.tmpl"
	struct index_view :public template_view
	#line 5 "Index.tmpl"
	{
	#line 5 "Index.tmpl"
		ViewContent::IndexContent &content;
	#line 5 "Index.tmpl"
		index_view(std::ostream &_s,ViewContent::IndexContent &_content): template_view(_s,_content),content(_content)
	#line 5 "Index.tmpl"
		{
	#line 5 "Index.tmpl"
		}
		#line 8 "Index.tmpl"
		virtual void css_links() {
			#line 9 "Index.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "Index.tmpl"
			template_view::css_links();
			#line 12 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/index.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/lib/jquery-ui/ui-lightness/jquery-ui-1.10.0.custom.min.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 12 "Index.tmpl"
		} // end of template css_links
		#line 15 "Index.tmpl"
		virtual void js_links() {
			#line 16 "Index.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "Index.tmpl"
			template_view::js_links();
			#line 19 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<script src=\"/js/sign_up.js\"></script>\n"
				"\t\t\t<script src=\"/lib/jquery-ui/jquery-ui-1.10.0.custom.min.js\"></script>\n"
				"\t\t";
		#line 19 "Index.tmpl"
		} // end of template js_links
		#line 22 "Index.tmpl"
		virtual void javascript_code() {
			#line 23 "Index.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 23 "Index.tmpl"
			template_view::javascript_code();
			#line 46 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\tconfigureValidator([\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_first_name', onChangeFunction: firstNameOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_last_name', onChangeFunction: lastNameOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_user_name', onChangeFunction: userNameOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_email', onChangeFunction: emailOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_password', onChangeFunction: passwordOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_password_verification', onChangeFunction: passwordVerificationOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_dropdownlist_genre', onChangeFunction: genreOnChange }\n"
				"\t\t\t\t]);\n"
				"\t\t\t\t\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_first_name');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_last_name');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_user_name');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_email');\n"
				"\t\t\t\tconfigurePasswordfield('pci_sign_up_textfield_password');\n"
				"\t\t\t\tconfigurePasswordfield('pci_sign_up_textfield_password_verification');\n"
				"\t\t\t\tconfigureDatepicker('pci_sign_up_textfield_birth_date');\n"
				"\t\t\t\tconfigureDropdownlist('pci_sign_up_dropdownlist_genre');\n"
				"\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 46 "Index.tmpl"
		} // end of template javascript_code
		#line 49 "Index.tmpl"
		virtual void page_content() {
			#line 50 "Index.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 50 "Index.tmpl"
			template_view::header_bar();
			#line 53 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_index_main_container\">\n"
				"\t\t\t\t<div id=\"pci_index_TO_DEFINE_container\">\n"
				"\t\t\t\t\t<a href=\"";
			#line 53 "Index.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 58 "Index.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t<img src=\"img/community.jpg\" >\n"
				"\t\t\t\t\t</a>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t<div id=\"pci_index_sign_up_container\">\n"
				"\t\t\t\t\t";
			#line 58 "Index.tmpl"
			template_view::create_user_form();
			#line 61 "Index.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 61 "Index.tmpl"
			template_view::information_footer();
			#line 62 "Index.tmpl"
			out()<<"\n"
				"\t\t";
		#line 62 "Index.tmpl"
		} // end of template page_content
	#line 65 "Index.tmpl"
	}; // end of class index_view
#line 66 "Index.tmpl"
} // end of namespace pci_skin
#line 2 "Problems.tmpl"
#include "logic/ViewContent.h" 
#line 4 "Problems.tmpl"
namespace pci_skin {
	#line 5 "Problems.tmpl"
	struct problems_view :public template_view
	#line 5 "Problems.tmpl"
	{
	#line 5 "Problems.tmpl"
		ViewContent::ProblemsContent &content;
	#line 5 "Problems.tmpl"
		problems_view(std::ostream &_s,ViewContent::ProblemsContent &_content): template_view(_s,_content),content(_content)
	#line 5 "Problems.tmpl"
		{
	#line 5 "Problems.tmpl"
		}
		#line 8 "Problems.tmpl"
		virtual void css_links() {
			#line 9 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "Problems.tmpl"
			template_view::css_links();
			#line 11 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/problems.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "Problems.tmpl"
		} // end of template css_links
		#line 14 "Problems.tmpl"
		virtual void javascript_code() {
			#line 15 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "Problems.tmpl"
			template_view::javascript_code();
			#line 21 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\tsetActiveNavigationButton('pci_navigation_menu_problems_button');\n"
				"\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 21 "Problems.tmpl"
		} // end of template javascript_code
		#line 24 "Problems.tmpl"
		virtual void page_content() {
			#line 25 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 25 "Problems.tmpl"
			template_view::header_bar();
			#line 26 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 26 "Problems.tmpl"
			template_view::navigation_menu();
			#line 29 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problems_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 29 "Problems.tmpl"
			if(content.user_signed_in) {
				#line 30 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 30 "Problems.tmpl"
				template_view::toolbar_problems();
				#line 31 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 31 "Problems.tmpl"
			} // endif
			#line 39 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<ul class=\"nav nav-tabs\">\n"
				"\t\t\t\t\t\t<li class=\"active\"><a href=\"#tab1\" data-toggle=\"tab\">Al azar</a></li>\n"
				"\t\t\t\t\t\t<li><a href=\"#tab2\" data-toggle=\"tab\">Recientes</a></li>\n"
				"\t\t\t\t\t\t<li><a href=\"#tab3\" data-toggle=\"tab\">Sin resolver</a></li>\n"
				"\t\t\t\t\t</ul>\n"
				"\t\t\t\t\t<div class=\"tab-content\">\n"
				"\t\t\t\t\t\t<div class=\"tab-pane active\" id=\"tab1\">\n"
				"\t\t\t\t\t\t\t";
			#line 39 "Problems.tmpl"
			if((*content.random_problems).begin()!=(*content.random_problems).end()) {
				#line 40 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t";
				#line 40 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.random_problems).begin()) problem_ptr=(*content.random_problems).begin(),problem_ptr_end=(*content.random_problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 40 "Problems.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 41 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 41 "Problems.tmpl"
					template_view::problem_description(problem);
					#line 42 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t";
				#line 42 "Problems.tmpl"
				} // end of item
				#line 43 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t";
			#line 43 "Problems.tmpl"
			 } else {
				#line 45 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\tNo se encontraron problemas\n"
					"\t\t\t\t\t\t\t";
			#line 45 "Problems.tmpl"
			} // end of empty
			#line 48 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"tab-pane\" id=\"tab2\">\n"
				"\t\t\t\t\t\t\t";
			#line 48 "Problems.tmpl"
			if((*content.latest_problems).begin()!=(*content.latest_problems).end()) {
				#line 49 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t";
				#line 49 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.latest_problems).begin()) problem_ptr=(*content.latest_problems).begin(),problem_ptr_end=(*content.latest_problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 49 "Problems.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 50 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 50 "Problems.tmpl"
					template_view::problem_description(problem);
					#line 51 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t";
				#line 51 "Problems.tmpl"
				} // end of item
				#line 52 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t";
			#line 52 "Problems.tmpl"
			 } else {
				#line 54 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\tNo se encontraron problemas sin resolver\n"
					"\t\t\t\t\t\t\t";
			#line 54 "Problems.tmpl"
			} // end of empty
			#line 57 "Problems.tmpl"
			out()<<"\t\t\t\t\t\t\t\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"tab-pane\" id=\"tab3\">\n"
				"\t\t\t\t\t\t\t";
			#line 57 "Problems.tmpl"
			if((*content.unsolved_problems).begin()!=(*content.unsolved_problems).end()) {
				#line 58 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t";
				#line 58 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.unsolved_problems).begin()) problem_ptr=(*content.unsolved_problems).begin(),problem_ptr_end=(*content.unsolved_problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 58 "Problems.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 59 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 59 "Problems.tmpl"
					template_view::problem_description(problem);
					#line 60 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t";
				#line 60 "Problems.tmpl"
				} // end of item
				#line 61 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t";
			#line 61 "Problems.tmpl"
			 } else {
				#line 63 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\tNo se encontraron problemas sin resolver\n"
					"\t\t\t\t\t\t\t";
			#line 63 "Problems.tmpl"
			} // end of empty
			#line 68 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 68 "Problems.tmpl"
		} // end of template page_content
	#line 71 "Problems.tmpl"
	}; // end of class problems_view
#line 72 "Problems.tmpl"
} // end of namespace pci_skin
#line 2 "Problem.tmpl"
#include "logic/ViewContent.h" 
#line 4 "Problem.tmpl"
namespace pci_skin {
	#line 5 "Problem.tmpl"
	struct problem_view :public template_view
	#line 5 "Problem.tmpl"
	{
	#line 5 "Problem.tmpl"
		ViewContent::ProblemContent &content;
	#line 5 "Problem.tmpl"
		problem_view(std::ostream &_s,ViewContent::ProblemContent &_content): template_view(_s,_content),content(_content)
	#line 5 "Problem.tmpl"
		{
	#line 5 "Problem.tmpl"
		}
		#line 8 "Problem.tmpl"
		virtual void css_links() {
			#line 9 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "Problem.tmpl"
			template_view::css_links();
			#line 11 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/problem.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "Problem.tmpl"
		} // end of template css_links
		#line 13 "Problem.tmpl"
		virtual void js_links() {
			#line 14 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 14 "Problem.tmpl"
			template_view::js_links();
			#line 16 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<script src=\"/lib/ckeditor/ckeditor.js\"></script>\n"
				"\t\t";
		#line 16 "Problem.tmpl"
		} // end of template js_links
		#line 18 "Problem.tmpl"
		virtual void javascript_code() {
			#line 19 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 19 "Problem.tmpl"
			template_view::javascript_code();
			#line 58 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\n"
				"\t\t\t\t// Toggles elements involved in edition\n"
				"\t\t\t\tfunction toggle() {\n"
				"\t\t\t\t\t$(\"#problem_edit_button\").toggle();\n"
				"\t\t\t\t\t$(\"#pci_problem_problem_content\").toggle();\n"
				"\t\t\t\t\t$(\"#problem_cancel_edit_button\").toggle();\n"
				"\t\t\t\t\t$(\"#problem_finish_edit_button\").toggle();\n"
				"\t\t\t\t\t$(\"#ckeditor_container\").toggle();\t\t\t\t\n"
				"\t\t\t\t}\n"
				"\t\t\t\t\n"
				"\t\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t\tvar html_code = XBBCODE.process({\n"
				"\t\t\t\t\t\ttext: $('#pci_problem_problem_content').html()\n"
				"\t\t\t\t\t}).html;\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\t$('#pci_problem_problem_content').empty();\n"
				"\t\t\t\t\t$('#pci_problem_problem_content').append(html_code);\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\tconfigureTexteditor(\"pci_textfield\");\n"
				"\n"
				"\t\t\t\t\t$(\"#ckeditor_container\").hide();\n"
				"\t\t\t\t\t$(\"#problem_cancel_edit_button\").hide();\n"
				"\t\t\t\t\t$(\"#problem_finish_edit_button\").hide();\n"
				"\t\t\t\t\t$(\"#problem_edit_button\").click(function(){\n"
				"\t\t\t\t\t\ttoggle();\n"
				"\t\t\t\t\t});\n"
				"\t\n"
				"\t\t\t\t\t$(\"#problem_cancel_edit_button\").click(function(){\n"
				"\t\t\t\t\t\ttoggle();\n"
				"\t\t\t\t\t});\n"
				"\t\n"
				"\t\t\t\t\t$(\"#problem_finish_edit_button\").click(function(){\n"
				"\t\t\t\t\t\ttoggle();\n"
				"\t\t\t\t\t\talert('Edition submit dumb method to be replaced with AJAX');\n"
				"\t\t\t\t\t});\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 58 "Problem.tmpl"
		} // end of template javascript_code
		#line 60 "Problem.tmpl"
		virtual void page_content() {
			#line 61 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 61 "Problem.tmpl"
			template_view::header_bar();
			#line 62 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 62 "Problem.tmpl"
			template_view::navigation_menu();
			#line 65 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problem_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 65 "Problem.tmpl"
			if(content.user_signed_in) {
				#line 66 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 66 "Problem.tmpl"
				template_view::toolbar_problem(content.problem->id);
				#line 68 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<div class=\"pci_horizontal_line\"></div>\n"
					"\t\t\t\t\t";
			#line 68 "Problem.tmpl"
			} // endif
			#line 76 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<div id=\"pci_problem_header_container\">\n"
				"\t\t\t\t\t\t<a id=\"problem_edit_button\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_classic\">\n"
				"\t\t\t\t\t\t\t\tEditar\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t<h2>\n"
				"\t\t\t\t\t\t\t";
			#line 76 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->description);
			#line 79 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</h2>\n"
				"\t\t\t\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t\t\t\t";
			#line 79 "Problem.tmpl"
			if(content.problem->is_anonymous) {
				#line 81 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t<i>Publicado Anónimamente</i>\n"
					"\t\t\t\t\t\t\t";
			#line 81 "Problem.tmpl"
			}else{
				#line 82 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 82 "Problem.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.problem->creator_user_name));
				#line 82 "Problem.tmpl"
				out()<<"\">";
				#line 82 "Problem.tmpl"
				out()<<cppcms::filters::escape(content.problem->creator_user_name);
				#line 83 "Problem.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t\t\t\t";
			#line 83 "Problem.tmpl"
			}
			#line 84 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t- ";
			#line 84 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 102 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</span>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_problem_problem_container\">\n"
				"\t\t\t\t\t\t<div id=\"ckeditor_container\">\n"
				"\t\t\t\t\t\t<textfield id=\"pci_textfield\"></textfield>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<a id=\"problem_finish_edit_button\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_classic\">\n"
				"\t\t\t\t\t\t\t\tFinalizar\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t<a id=\"problem_cancel_edit_button\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_classic\">\n"
				"\t\t\t\t\t\t\t\tCancelar\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t<div class=\"pci_box_content\" id=\"pci_problem_problem_content\">\n"
				"\t\t\t\t\t\t\t";
			#line 102 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->content);
			#line 106 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_problem_solution_container\">\n"
				"\t\t\t\t\t\t";
			#line 106 "Problem.tmpl"
			if(content.problem->is_solved) {
				#line 108 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problem_solution_description\" style=\"background-color:#ABFFAB;\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 108 "Problem.tmpl"
				template_view::solution_description(content.problem,content.accepted_solution);
				#line 110 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 110 "Problem.tmpl"
			} // endif
			#line 111 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t";
			#line 111 "Problem.tmpl"
			if((*content.solutions).begin()!=(*content.solutions).end()) {
				#line 112 "Problem.tmpl"
				out()<<"\n"
					"\t\t \t\t\t\t\t";
				#line 112 "Problem.tmpl"
				for(CPPCMS_TYPEOF((*content.solutions).begin()) solution_ptr=(*content.solutions).begin(),solution_ptr_end=(*content.solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 112 "Problem.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 113 "Problem.tmpl"
					out()<<"\n"
						"\t\t \t\t\t\t\t\t";
					#line 113 "Problem.tmpl"
					if(!content.problem->is_solved || solution->id.compare(content.accepted_solution->id) != 0) {
						#line 115 "Problem.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problem_solution_description\">\n"
							"\t\t\t\t\t\t\t\t\t\t";
						#line 115 "Problem.tmpl"
						template_view::solution_description(content.problem,solution);
						#line 117 "Problem.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t\t";
					#line 117 "Problem.tmpl"
					} // endif
					#line 118 "Problem.tmpl"
					out()<<"\n"
						"\t\t  \t\t\t\t\t";
				#line 118 "Problem.tmpl"
				} // end of item
				#line 119 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
			#line 119 "Problem.tmpl"
			}
			#line 121 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t";
			#line 121 "Problem.tmpl"
			template_view::clarifications(content.clarifications,content.problem);
			#line 124 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 124 "Problem.tmpl"
		} // end of template page_content
	#line 127 "Problem.tmpl"
	}; // end of class problem_view
#line 128 "Problem.tmpl"
} // end of namespace pci_skin
#line 2 "NewProblem.tmpl"
#include "logic/ViewContent.h" 
#line 4 "NewProblem.tmpl"
namespace pci_skin {
	#line 5 "NewProblem.tmpl"
	struct new_problem_view :public template_view
	#line 5 "NewProblem.tmpl"
	{
	#line 5 "NewProblem.tmpl"
		ViewContent::NewProblemContent &content;
	#line 5 "NewProblem.tmpl"
		new_problem_view(std::ostream &_s,ViewContent::NewProblemContent &_content): template_view(_s,_content),content(_content)
	#line 5 "NewProblem.tmpl"
		{
	#line 5 "NewProblem.tmpl"
		}
		#line 8 "NewProblem.tmpl"
		virtual void css_links() {
			#line 9 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "NewProblem.tmpl"
			template_view::css_links();
			#line 11 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/new_problem.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "NewProblem.tmpl"
		} // end of template css_links
		#line 14 "NewProblem.tmpl"
		virtual void js_links() {
			#line 15 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "NewProblem.tmpl"
			template_view::js_links();
			#line 17 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t<script src=\"/lib/ckeditor/ckeditor.js\"></script>\n"
				"\t\t";
		#line 17 "NewProblem.tmpl"
		} // end of template js_links
		#line 20 "NewProblem.tmpl"
		virtual void javascript_code() {
			#line 21 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 21 "NewProblem.tmpl"
			template_view::javascript_code();
			#line 27 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\t\t\t$(document).ready(function(){\n"
				"\t\t\t\tconfigureTexteditor('pci_texteditor');\n"
				"\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 27 "NewProblem.tmpl"
		} // end of template javascript_code
		#line 30 "NewProblem.tmpl"
		virtual void page_content() {
			#line 31 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 31 "NewProblem.tmpl"
			template_view::header_bar();
			#line 32 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 32 "NewProblem.tmpl"
			template_view::navigation_menu();
			#line 35 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_new_problem_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 35 "NewProblem.tmpl"
			create_problem_form();
			#line 38 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 38 "NewProblem.tmpl"
		} // end of template page_content
	#line 41 "NewProblem.tmpl"
	}; // end of class new_problem_view
#line 42 "NewProblem.tmpl"
} // end of namespace pci_skin
#line 2 "User.tmpl"
#include "logic/ViewContent.h" 
#line 4 "User.tmpl"
namespace pci_skin {
	#line 5 "User.tmpl"
	struct user_view :public template_view
	#line 5 "User.tmpl"
	{
	#line 5 "User.tmpl"
		ViewContent::UserContent &content;
	#line 5 "User.tmpl"
		user_view(std::ostream &_s,ViewContent::UserContent &_content): template_view(_s,_content),content(_content)
	#line 5 "User.tmpl"
		{
	#line 5 "User.tmpl"
		}
		#line 8 "User.tmpl"
		virtual void css_links() {
			#line 9 "User.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "User.tmpl"
			template_view::css_links();
			#line 11 "User.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/user.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "User.tmpl"
		} // end of template css_links
		#line 14 "User.tmpl"
		virtual void javascript_code() {
			#line 15 "User.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "User.tmpl"
			template_view::javascript_code();
			#line 21 "User.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\tsetActiveNavigationButton('pci_navigation_menu_profile_button');\n"
				"\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 21 "User.tmpl"
		} // end of template javascript_code
		#line 24 "User.tmpl"
		virtual void page_content() {
			#line 25 "User.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 25 "User.tmpl"
			template_view::header_bar();
			#line 26 "User.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 26 "User.tmpl"
			template_view::navigation_menu();
			#line 35 "User.tmpl"
			out()<<"\n"
				"\t\t\t\n"
				"\t\t\t<div id=\"pci_user_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<div id=\"column_1\">\n"
				"\t\t\t\t\t\t<div id=\"content_wrapper\">\n"
				"\t\t\t\t\t\t\t<div id=\"title_container\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"row-fluid title\">\t\t\t\t\t\t\t\t\n"
				"\t\t\t\t\t\t\t\t\t<div id=\"rank_icon\"></div>\n"
				"\t\t\t\t\t\t\t\t\t<div id=\"big_name\">";
			#line 35 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->first_name);
			#line 35 "User.tmpl"
			out()<<" ";
			#line 35 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->last_name);
			#line 40 "User.tmpl"
			out()<<"</div>\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"row-fluid\">\n"
				"\t\t\t\t\t\t\t\t\t<div class=\"span3\">\n"
				"\t\t\t\t\t\t\t\t\t\t<div>\n"
				"\t\t\t\t\t\t\t\t\t\t\t<div class=\"stat_number\">";
			#line 40 "User.tmpl"
			out()<<cppcms::filters::escape(content.number_of_publications);
			#line 46 "User.tmpl"
			out()<<"</div>\n"
				"\t\t\t\t\t\t\t\t\t\t\t<div class=\"stat_description\">Publicaciones</div>\n"
				"\t\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t<div class=\"span3\">\n"
				"\t\t\t\t\t\t\t\t\t\t<div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_number\">";
			#line 46 "User.tmpl"
			out()<<cppcms::filters::escape(content.number_of_problems);
			#line 52 "User.tmpl"
			out()<<"</div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_description\">Problemas</div>\n"
				"\t\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t<div class=\"span3\">\n"
				"\t\t\t\t\t\t\t\t\t\t<div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_number\">";
			#line 52 "User.tmpl"
			out()<<cppcms::filters::escape(content.number_of_solutions);
			#line 58 "User.tmpl"
			out()<<"</div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_description\">Soluciones</div>\n"
				"\t\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t<div class=\"span3\">\n"
				"\t\t\t\t\t\t\t\t\t\t<div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_number\">";
			#line 58 "User.tmpl"
			out()<<cppcms::filters::escape(content.number_of_accepted_solutions);
			#line 79 "User.tmpl"
			out()<<"</div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_description\">Soluciones aceptadas</div>\n"
				"\t\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t</div>\n"
				"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<h2>Descripcion personal</h2>\n"
				"\t\t\t\t\t\t\t<div id=\"user_customizable_panel\">\n"
				"\t\t\t\t\t\t\t\tMessi nació el 24 de junio de 1987 en la ciudad de Rosario, en la\n"
				"\t\t\t\t\t\t\t\tprovincia de Santa Fe, Argentina. Es hijo de Jorge Horacio Messi, \n"
				"\t\t\t\t\t\t\t\ttrabajador de una fábrica, y de Celia María Cuccittini, una limpiadora \n"
				"\t\t\t\t\t\t\t\tde medio tiempo. Su familia, de parte de su padre, posee \n"
				"\t\t\t\t\t\t\t\tascendencia italiana debido a su bisabuelo Angelo Messi, que vivía en\n"
				"\t\t\t\t\t\t\t\tla ciudad de Ancona, y que se mudó a Argentina en 1883. Tiene dos\n"
				"\t\t\t\t\t\t\t\thermanos llamados Rodrigo y Matías, como también una hermana llamada\n"
				"\t\t\t\t\t\t\t\tMaría Sol. Asimismo, dos de sus primos (Maximiliano y Emanuel Biancucchi)\n"
				"\t\t\t\t\t\t\t\tson también futbolistas.<br>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<h2>Actividad reciente</h2>\n"
				"\t\t\t\t\t\t\t<div id=\"recent_activity\">\n"
				"\t\t\t\t\t\t\t\t";
			#line 79 "User.tmpl"
			if((*content.recent_activity).begin()!=(*content.recent_activity).end()) {
				#line 80 "User.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t\t";
				#line 80 "User.tmpl"
				for(CPPCMS_TYPEOF((*content.recent_activity).begin()) activity_ptr=(*content.recent_activity).begin(),activity_ptr_end=(*content.recent_activity).end();activity_ptr!=activity_ptr_end;++activity_ptr) {
				#line 80 "User.tmpl"
				CPPCMS_TYPEOF(*activity_ptr) &activity=*activity_ptr;
					#line 81 "User.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t\t\t";
					#line 81 "User.tmpl"
					if(!activity->is_anonymous || content.user_name.compare(content.user->user_name) == 0) {
						#line 83 "User.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problems_problem_description\">\n"
							"\t\t\t\t\t\t\t\t\t\t\t\t";
						#line 83 "User.tmpl"
						template_view::publication_description(activity);
						#line 85 "User.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t\t\t\t";
					#line 85 "User.tmpl"
					} // endif
					#line 86 "User.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t\t";
				#line 86 "User.tmpl"
				} // end of item
				#line 87 "User.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t";
			#line 87 "User.tmpl"
			 } else {
				#line 89 "User.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t\tNo hay actividad reciente\n"
					"\t\t\t\t\t\t\t\t";
			#line 89 "User.tmpl"
			} // end of empty
			#line 94 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"column_2\">\n"
				"\t\t\t\t\t\t<div id=\"profile_image\" style=\"background:url('";
			#line 94 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->profile_picture_url);
			#line 102 "User.tmpl"
			out()<<"')\"></div>\n"
				"\t\t\t\t\t\t<div id=\"user_personal_info\">\n"
				"\t\t\t\t\t\t\t<div class=\"feature_container\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_title\">\n"
				"\t\t\t\t\t\t\t\t\tNombre de usuario\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"horizontal_line\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_value\">\n"
				"\t\t\t\t\t\t\t\t\t";
			#line 102 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->user_name);
			#line 111 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"feature_container\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_title\">\n"
				"\t\t\t\t\t\t\t\t\tNombre\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"horizontal_line\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_value\">\n"
				"\t\t\t\t\t\t\t\t\t";
			#line 111 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->first_name);
			#line 120 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"feature_container\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_title\">\n"
				"\t\t\t\t\t\t\t\t\tApellido\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"horizontal_line\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_value\">\n"
				"\t\t\t\t\t\t\t\t\t";
			#line 120 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->last_name);
			#line 129 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"feature_container\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_title\">\n"
				"\t\t\t\t\t\t\t\t\tSexo\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"horizontal_line\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_value\">\n"
				"\t\t\t\t\t\t\t\t\t";
			#line 129 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->genre);
			#line 138 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"feature_container\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_title\">\n"
				"\t\t\t\t\t\t\t\t\tFecha de nacimiento\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"horizontal_line\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_value\">\n"
				"\t\t\t\t\t\t\t\t\t";
			#line 138 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->birth_date->toString("%d/%m/%Y"));
			#line 147 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"feature_container\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_title\">\n"
				"\t\t\t\t\t\t\t\t\tE-mail\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"horizontal_line\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_value\">\n"
				"\t\t\t\t\t\t\t\t\t";
			#line 147 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->email);
			#line 156 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"feature_container\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_title\">\n"
				"\t\t\t\t\t\t\t\t\tFecha de registro\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"horizontal_line\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_value\">\n"
				"\t\t\t\t\t\t\t\t\t";
			#line 156 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->sign_up_datetime->toString("%d/%m/%Y %H:%M:%S"));
			#line 164 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\n"
				"\t\t";
		#line 164 "User.tmpl"
		} // end of template page_content
	#line 167 "User.tmpl"
	}; // end of class user_view
#line 168 "User.tmpl"
} // end of namespace pci_skin
#line 2 "Solution.tmpl"
#include "logic/ViewContent.h" 
#line 4 "Solution.tmpl"
namespace pci_skin {
	#line 5 "Solution.tmpl"
	struct solution_view :public template_view
	#line 5 "Solution.tmpl"
	{
	#line 5 "Solution.tmpl"
		ViewContent::SolutionContent &content;
	#line 5 "Solution.tmpl"
		solution_view(std::ostream &_s,ViewContent::SolutionContent &_content): template_view(_s,_content),content(_content)
	#line 5 "Solution.tmpl"
		{
	#line 5 "Solution.tmpl"
		}
		#line 8 "Solution.tmpl"
		virtual void css_links() {
			#line 9 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "Solution.tmpl"
			template_view::css_links();
			#line 11 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/solution.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "Solution.tmpl"
		} // end of template css_links
		#line 14 "Solution.tmpl"
		virtual void javascript_code() {
			#line 15 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "Solution.tmpl"
			template_view::javascript_code();
			#line 28 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t\tvar html_code = XBBCODE.process({\n"
				"\t\t\t\t\t\ttext: $('#pci_solution_solution_content').html(),\n"
				"\t\t\t\t\t\tremoveMisalignedTags: false,\n"
				"\t\t\t\t\t\taddInLineBreaks: true\n"
				"\t\t\t\t\t}).html;\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\t$('#pci_solution_solution_content').empty();\n"
				"\t\t\t\t\t$('#pci_solution_solution_content').append(html_code);\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 28 "Solution.tmpl"
		} // end of template javascript_code
		#line 31 "Solution.tmpl"
		virtual void page_content() {
			#line 32 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 32 "Solution.tmpl"
			template_view::header_bar();
			#line 33 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 33 "Solution.tmpl"
			template_view::navigation_menu();
			#line 36 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_solution_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 36 "Solution.tmpl"
			template_view::toolbar_solution(content.problem_id);
			#line 40 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<div class=\"pci_horizontal_line\"></div>\n"
				"\t\t\t\t\t<div id=\"pci_solution_header_container\">\n"
				"\t\t\t\t\t\t<h2>\n"
				"\t\t\t\t\t\t\t";
			#line 40 "Solution.tmpl"
			out()<<cppcms::filters::escape(content.solution->description);
			#line 44 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</h2>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div class=\"pci_box_content\" id=\"pci_solution_solution_content\">\n"
				"\t\t\t\t\t\t";
			#line 44 "Solution.tmpl"
			out()<<cppcms::filters::escape(content.solution->content);
			#line 46 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t";
			#line 46 "Solution.tmpl"
			template_view::clarifications(content.clarifications,content.solution);
			#line 49 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 49 "Solution.tmpl"
		} // end of template page_content
	#line 52 "Solution.tmpl"
	}; // end of class solution_view
#line 53 "Solution.tmpl"
} // end of namespace pci_skin
#line 2 "NewSolution.tmpl"
#include "logic/ViewContent.h" 
#line 4 "NewSolution.tmpl"
namespace pci_skin {
	#line 5 "NewSolution.tmpl"
	struct new_solution_view :public template_view
	#line 5 "NewSolution.tmpl"
	{
	#line 5 "NewSolution.tmpl"
		ViewContent::NewSolutionContent &content;
	#line 5 "NewSolution.tmpl"
		new_solution_view(std::ostream &_s,ViewContent::NewSolutionContent &_content): template_view(_s,_content),content(_content)
	#line 5 "NewSolution.tmpl"
		{
	#line 5 "NewSolution.tmpl"
		}
		#line 8 "NewSolution.tmpl"
		virtual void css_links() {
			#line 9 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "NewSolution.tmpl"
			template_view::css_links();
			#line 11 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/new_solution.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "NewSolution.tmpl"
		} // end of template css_links
		#line 14 "NewSolution.tmpl"
		virtual void js_links() {
			#line 15 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "NewSolution.tmpl"
			template_view::js_links();
			#line 17 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t<script src=\"/lib/ckeditor/ckeditor.js\"></script>\n"
				"\t\t";
		#line 17 "NewSolution.tmpl"
		} // end of template js_links
		#line 20 "NewSolution.tmpl"
		virtual void javascript_code() {
			#line 21 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 21 "NewSolution.tmpl"
			template_view::javascript_code();
			#line 27 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\t\t\t$(document).ready(function(){\n"
				"\t\t\t\tconfigureTexteditor('pci_texteditor');\n"
				"\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 27 "NewSolution.tmpl"
		} // end of template javascript_code
		#line 30 "NewSolution.tmpl"
		virtual void page_content() {
			#line 31 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 31 "NewSolution.tmpl"
			template_view::header_bar();
			#line 32 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 32 "NewSolution.tmpl"
			template_view::navigation_menu();
			#line 35 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_new_solution_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 35 "NewSolution.tmpl"
			create_solution_form(content.problem_id);
			#line 38 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 38 "NewSolution.tmpl"
		} // end of template page_content
	#line 41 "NewSolution.tmpl"
	}; // end of class new_solution_view
#line 42 "NewSolution.tmpl"
} // end of namespace pci_skin
#line 2 "Ideas.tmpl"
#include "logic/ViewContent.h" 
#line 4 "Ideas.tmpl"
namespace pci_skin {
	#line 5 "Ideas.tmpl"
	struct ideas_view :public template_view
	#line 5 "Ideas.tmpl"
	{
	#line 5 "Ideas.tmpl"
		ViewContent::IdeasContent &content;
	#line 5 "Ideas.tmpl"
		ideas_view(std::ostream &_s,ViewContent::IdeasContent &_content): template_view(_s,_content),content(_content)
	#line 5 "Ideas.tmpl"
		{
	#line 5 "Ideas.tmpl"
		}
		#line 8 "Ideas.tmpl"
		virtual void css_links() {
			#line 9 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "Ideas.tmpl"
			template_view::css_links();
			#line 11 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/ideas.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "Ideas.tmpl"
		} // end of template css_links
		#line 14 "Ideas.tmpl"
		virtual void javascript_code() {
			#line 15 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "Ideas.tmpl"
			template_view::javascript_code();
			#line 21 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\tsetActiveNavigationButton('pci_navigation_menu_ideas_button');\n"
				"\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 21 "Ideas.tmpl"
		} // end of template javascript_code
		#line 24 "Ideas.tmpl"
		virtual void page_content() {
			#line 25 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 25 "Ideas.tmpl"
			template_view::header_bar();
			#line 26 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 26 "Ideas.tmpl"
			template_view::navigation_menu();
			#line 32 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_ideas_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\tIdeas content\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 32 "Ideas.tmpl"
		} // end of template page_content
	#line 35 "Ideas.tmpl"
	}; // end of class ideas_view
#line 36 "Ideas.tmpl"
} // end of namespace pci_skin
#line 37 "Ideas.tmpl"
namespace {
#line 37 "Ideas.tmpl"
 cppcms::views::generator my_generator; 
#line 37 "Ideas.tmpl"
 struct loader { 
#line 37 "Ideas.tmpl"
  loader() { 
#line 37 "Ideas.tmpl"
   my_generator.name("pci_skin");
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::template_view,ViewContent::TemplateContent>("template_view",true);
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::debug_view,ViewContent::TemplateContent>("debug_view",true);
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::index_view,ViewContent::IndexContent>("index_view",true);
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problems_view,ViewContent::ProblemsContent>("problems_view",true);
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problem_view,ViewContent::ProblemContent>("problem_view",true);
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::new_problem_view,ViewContent::NewProblemContent>("new_problem_view",true);
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::user_view,ViewContent::UserContent>("user_view",true);
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::solution_view,ViewContent::SolutionContent>("solution_view",true);
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::new_solution_view,ViewContent::NewSolutionContent>("new_solution_view",true);
#line 37 "Ideas.tmpl"
   my_generator.add_view<pci_skin::ideas_view,ViewContent::IdeasContent>("ideas_view",true);
#line 37 "Ideas.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 37 "Ideas.tmpl"
 }
#line 37 "Ideas.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 37 "Ideas.tmpl"
} a_loader;
#line 37 "Ideas.tmpl"
} // anon 
