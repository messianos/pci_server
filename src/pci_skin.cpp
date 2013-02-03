#line 2 "Template.tmpl"
#include "ViewContent.h" 
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
		#line 8 "Template.tmpl"
		virtual void clarifications(ClarificationList clarifications) {
			#line 9 "Template.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "Template.tmpl"
			if(! clarifications->empty()) {
				#line 24 "Template.tmpl"
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
				#line 24 "Template.tmpl"
				if((*clarifications).begin()!=(*clarifications).end()) {
					#line 25 "Template.tmpl"
					out()<<"\n"
						"\t \t\t\t\t\t";
					#line 25 "Template.tmpl"
					for(CPPCMS_TYPEOF((*clarifications).begin()) clarification_ptr=(*clarifications).begin(),clarification_ptr_end=(*clarifications).end();clarification_ptr!=clarification_ptr_end;++clarification_ptr) {
					#line 25 "Template.tmpl"
					CPPCMS_TYPEOF(*clarification_ptr) &clarification=*clarification_ptr;
						#line 29 "Template.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t<div class=\"pci_clarifications_row_container\">\n"
							"\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_question_container\">\n"
							"\t\t\t\t\t\t\t\t\t<div class=\"pci_box_content pci_clarifications_question_content\">\n"
							"\t\t\t\t\t\t\t\t\t\t";
						#line 29 "Template.tmpl"
						out()<<cppcms::filters::escape(clarification->question);
						#line 33 "Template.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
							"\t\t\t\t\t\t\t\t\t";
						#line 33 "Template.tmpl"
						if(! clarification->answer.empty()) {
							#line 35 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t\t<div class=\"pci_box_content pci_clarifications_answer_content\">\n"
								"\t\t\t\t\t\t\t\t\t\t\t";
							#line 35 "Template.tmpl"
							out()<<cppcms::filters::escape(clarification->answer);
							#line 37 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t\t</div>\n"
								"\t\t\t\t\t\t\t\t\t";
						#line 37 "Template.tmpl"
						} // endif
						#line 40 "Template.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t</div>\n"
							"\t  \t\t\t\t\t";
					#line 40 "Template.tmpl"
					} // end of item
					#line 41 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t";
				#line 41 "Template.tmpl"
				 } else {
					#line 43 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\tAún no hay aclaraciones\n"
						"\t\t\t\t\t";
				#line 43 "Template.tmpl"
				} // end of empty
				#line 45 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t</div>\n"
					"\t\t\t";
			#line 45 "Template.tmpl"
			} // endif
			#line 46 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 46 "Template.tmpl"
		} // end of template clarifications
		#line 49 "Template.tmpl"
		virtual void header_bar() {
			#line 53 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_header_bar_main_container\">\n"
				"\t\t\t\t<div id=\"pci_header_bar_central_container\">\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_logo_container\">\n"
				"\t\t\t\t\t\t<a href=\"";
			#line 53 "Template.tmpl"
			content.app().mapper().map(out(),"/");
			#line 58 "Template.tmpl"
			out()<<"\" >\n"
				"\t\t\t\t\t\t\t<div id=\"pci_header_bar_logo\"></div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_sign_container\">\n"
				"\t\t\t\t\t \t";
			#line 58 "Template.tmpl"
			if(content.user_signed_in) {
				#line 59 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a href=\"";
				#line 59 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_out");
				#line 64 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tSalir\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t\t<a href=\"";
				#line 64 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 67 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t \t\t<div id=\"pci_header_bar_user_name_container\">\n"
					"\t\t\t\t\t \t\t\t<span id=\"pci_header_bar_user_name\">\n"
					"\t\t\t\t\t \t\t\t\t";
				#line 67 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_first_name);
				#line 67 "Template.tmpl"
				out()<<" ";
				#line 67 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_last_name);
				#line 71 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t \t\t\t</span>\n"
					"\t\t\t\t \t\t\t</div>\n"
					"\t\t\t\t \t\t\t</a>\n"
					"\t\t\t\t\t\t";
			#line 71 "Template.tmpl"
			}else{
				#line 78 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a href=\"javascript:void(0)\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\" id=\"pci_header_bar_button_sign_in\">\n"
					"\t\t\t\t\t\t\t\t\tIngresar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t\t<div id=\"pci_header_bar_sign_in_container\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 78 "Template.tmpl"
				sign_in_form(content.sign_in_form_info);
				#line 80 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 80 "Template.tmpl"
			}
			#line 84 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 84 "Template.tmpl"
		} // end of template header_bar
		#line 87 "Template.tmpl"
		virtual void information_footer() {
			#line 101 "Template.tmpl"
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
			#line 101 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 106 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAcerca de\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 106 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 111 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tFilosofía\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 111 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 123 "Template.tmpl"
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
			#line 123 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 128 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 128 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 133 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 133 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 145 "Template.tmpl"
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
			#line 145 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 150 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAyuda\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 150 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 155 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCondiciones de servicio\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 155 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 163 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCopyright\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 163 "Template.tmpl"
		} // end of template information_footer
		#line 166 "Template.tmpl"
		virtual void navigation_menu() {
			#line 168 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_navigation_menu_main_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 168 "Template.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 173 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_problems_button\">\n"
				"\t\t\t\t\t\tProblemas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 173 "Template.tmpl"
			content.app().mapper().map(out(),"/ideas");
			#line 178 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_ideas_button\">\n"
				"\t\t\t\t\t\tIdeas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t";
			#line 178 "Template.tmpl"
			if(content.user_signed_in) {
				#line 180 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<div class=\"pci_horizontal_line\" ></div>\n"
					"\t\t\t\t\t<a href=\"";
				#line 180 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 185 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_profile_button\">\n"
					"\t\t\t\t\t\t\tPerfil\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t</a>\n"
					"\t\t\t\t";
			#line 185 "Template.tmpl"
			} // endif
			#line 187 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 187 "Template.tmpl"
		} // end of template navigation_menu
		#line 190 "Template.tmpl"
		virtual void new_problem_form(ViewContent::NewProblemFormInfo &new_problem_form_info) {
			#line 192 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t";
			#line 192 "Template.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (new_problem_form_info).render(_form_context); }
			#line 194 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</form>\n"
				"\t\t";
		#line 194 "Template.tmpl"
		} // end of template new_problem_form
		#line 197 "Template.tmpl"
		virtual void new_solution_form(ViewContent::NewSolutionFormInfo &new_solution_form_info) {
			#line 199 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t";
			#line 199 "Template.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (new_solution_form_info).render(_form_context); }
			#line 201 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</form>\n"
				"\t\t";
		#line 201 "Template.tmpl"
		} // end of template new_solution_form
		#line 204 "Template.tmpl"
		virtual void problem_description(ProblemPointer problem) {
			#line 205 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 205 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem->id));
			#line 206 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t";
			#line 206 "Template.tmpl"
			out()<<cppcms::filters::escape(problem->description);
			#line 209 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t";
			#line 209 "Template.tmpl"
			if(problem->is_anonymous) {
				#line 211 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Publicado Anónimamente</i>\n"
					"\t\t\t\t";
			#line 211 "Template.tmpl"
			}else{
				#line 212 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 212 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(problem->creator_user_name));
				#line 212 "Template.tmpl"
				out()<<"\">";
				#line 212 "Template.tmpl"
				out()<<cppcms::filters::escape(problem->creator_user_name);
				#line 213 "Template.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t";
			#line 213 "Template.tmpl"
			}
			#line 214 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t- ";
			#line 214 "Template.tmpl"
			out()<<cppcms::filters::escape(problem->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 216 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</span>\n"
				"\t\t";
		#line 216 "Template.tmpl"
		} // end of template problem_description
		#line 219 "Template.tmpl"
		virtual void sign_in_form(ViewContent::SignInFormInfo &sign_in_form_info) {
			#line 221 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t";
			#line 221 "Template.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (sign_in_form_info).render(_form_context); }
			#line 223 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</form>\n"
				"\t\t";
		#line 223 "Template.tmpl"
		} // end of template sign_in_form
		#line 226 "Template.tmpl"
		virtual void sign_up_form(ViewContent::SignUpFormInfo &sign_up_form_info) {
			#line 228 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t";
			#line 228 "Template.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (sign_up_form_info).render(_form_context); }
			#line 230 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</form>\n"
				"\t\t";
		#line 230 "Template.tmpl"
		} // end of template sign_up_form
		#line 233 "Template.tmpl"
		virtual void solution_description(ProblemPointer problem,SolutionPointer solution) {
			#line 234 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 234 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem->id), cppcms::filters::urlencode(solution->id));
			#line 235 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t";
			#line 235 "Template.tmpl"
			out()<<cppcms::filters::escape(solution->description);
			#line 238 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t";
			#line 238 "Template.tmpl"
			if(solution->is_anonymous) {
				#line 240 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Publicado Anónimamente</i>\n"
					"\t\t\t\t";
			#line 240 "Template.tmpl"
			}else{
				#line 241 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 241 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(solution->creator_user_name));
				#line 241 "Template.tmpl"
				out()<<"\">";
				#line 241 "Template.tmpl"
				out()<<cppcms::filters::escape(solution->creator_user_name);
				#line 242 "Template.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t";
			#line 242 "Template.tmpl"
			}
			#line 243 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t- ";
			#line 243 "Template.tmpl"
			out()<<cppcms::filters::escape(solution->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 245 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</span>\n"
				"\t\t";
		#line 245 "Template.tmpl"
		} // end of template solution_description
		#line 248 "Template.tmpl"
		virtual void toolbar_problems() {
			#line 250 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problems_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 250 "Template.tmpl"
			content.app().mapper().map(out(),"/new_problem");
			#line 256 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problems_button\" id=\"pci_toolbar_problems_new_problem_button\">\n"
				"\t\t\t\t\t\tNuevo problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 256 "Template.tmpl"
		} // end of template toolbar_problems
		#line 259 "Template.tmpl"
		virtual void toolbar_problem(std::string problem_id) {
			#line 261 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problem_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 261 "Template.tmpl"
			content.app().mapper().map(out(),"/new_solution", cppcms::filters::urlencode(problem_id));
			#line 267 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problem_button\" id=\"pci_toolbar_problem_new_solution_button\">\n"
				"\t\t\t\t\t\tPlantear solución\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 267 "Template.tmpl"
		} // end of template toolbar_problem
		#line 270 "Template.tmpl"
		virtual void toolbar_solution(std::string problem_id) {
			#line 272 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_solution_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 272 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem_id));
			#line 278 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_solution_button\" id=\"pci_toolbar_solution_go_back_button\">\n"
				"\t\t\t\t\t\tVolver al problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 278 "Template.tmpl"
		} // end of template toolbar_solution
		#line 281 "Template.tmpl"
		virtual void css_links() {
			#line 283 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/template.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 283 "Template.tmpl"
		} // end of template css_links
		#line 286 "Template.tmpl"
		virtual void js_links() {
			#line 290 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<script src=\"/js/sign_in.js\"></script>\n"
				"\t\t\t<script src=\"/js/utilities.js\"></script>\n"
				"\t\t\t<script src=\"/lib/jquery/jquery-1.9.0.min.js\"></script>\n"
				"\t\t";
		#line 290 "Template.tmpl"
		} // end of template js_links
		#line 293 "Template.tmpl"
		virtual void javascript_code() {
			#line 299 "Template.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\tconfigureTextfield('pci_sign_in_textfield_user_name', 'Nombre de usuario');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_in_textfield_password', 'Contraseña');\n"
				"\t\t\t\tconfigureSignInFormContainer('pci_header_bar_sign_in_container', 'pci_header_bar_button_sign_in');\n"
				"\t\t\t});\n"
				"\t\t";
		#line 299 "Template.tmpl"
		} // end of template javascript_code
		#line 302 "Template.tmpl"
		virtual void page_content() {
			#line 303 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 303 "Template.tmpl"
		} // end of template page_content
		#line 306 "Template.tmpl"
		virtual void render() {
			#line 310 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<!DOCTYPE html>\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 310 "Template.tmpl"
			css_links();
			#line 311 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t";
			#line 311 "Template.tmpl"
			js_links();
			#line 313 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<script>\n"
				"\t\t\t\t\t\t";
			#line 313 "Template.tmpl"
			javascript_code();
			#line 316 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</script>\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 316 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 320 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t";
			#line 320 "Template.tmpl"
			page_content();
			#line 323 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 323 "Template.tmpl"
		} // end of template render
	#line 326 "Template.tmpl"
	}; // end of class template_view
#line 327 "Template.tmpl"
} // end of namespace pci_skin
#line 2 "Index.tmpl"
#include "ViewContent.h" 
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
			#line 44 "Index.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_first_name', 'Nombre');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_last_name', 'Apellido');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_user_name', 'Nombre de usuario');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_email', 'E-Mail');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_password', 'Contraseña');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_password_verification', 'Confirmar contraseña');\n"
				"\t\t\t\tconfigureTextfield('pci_sign_up_textfield_birth_date', 'Fecha de nacimiento');\n"
				"\t\t\t\tconfigureDropdownlist('pci_sign_up_dropdownlist_genre');\n"
				"\t\t\t\tconfigureDatepicker('pci_sign_up_textfield_birth_date');\n"
				"\t\t\t\tconfigureValidator([\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_first_name', onChangeFunction: firstNameOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_last_name', onChangeFunction: lastNameOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_user_name', onChangeFunction: userNameOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_email', onChangeFunction: emailOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_password', onChangeFunction: passwordOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_textfield_password_verification', onChangeFunction: passwordVerificationOnChange },\n"
				"\t\t\t\t\t{ elementId: 'pci_sign_up_dropdownlist_genre', onChangeFunction: genreOnChange }\n"
				"\t\t\t\t]);\n"
				"\t\t\t});\n"
				"\t\t";
		#line 44 "Index.tmpl"
		} // end of template javascript_code
		#line 47 "Index.tmpl"
		virtual void page_content() {
			#line 48 "Index.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 48 "Index.tmpl"
			template_view::header_bar();
			#line 51 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_index_main_container\">\n"
				"\t\t\t\t<div id=\"pci_index_TO_DEFINE_container\">\n"
				"\t\t\t\t\t<a href=\"";
			#line 51 "Index.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 66 "Index.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t<h2>\n"
				"\t\t\t\t\t\t\tProblemas\n"
				"\t\t\t\t\t\t</h2>\n"
				"\t\t\t\t\t</a>\n"
				"\t\t\t\t\tComienzo content\n"
				"\t\t\t\t\t<br />\n"
				"\t\t\t\t\t<br />\n"
				"\t\t\t\t\t<br />\n"
				"\t\t\t\t\tIndex content\n"
				"\t\t\t\t\t<br />\n"
				"\t\t\t\t\t<br />\n"
				"\t\t\t\t\t<br />\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t<div id=\"pci_index_sign_up_container\">\n"
				"\t\t\t\t\t";
			#line 66 "Index.tmpl"
			template_view::sign_up_form(content.sign_up_form_info);
			#line 69 "Index.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 69 "Index.tmpl"
			template_view::information_footer();
			#line 70 "Index.tmpl"
			out()<<"\n"
				"\t\t";
		#line 70 "Index.tmpl"
		} // end of template page_content
	#line 73 "Index.tmpl"
	}; // end of class index_view
#line 74 "Index.tmpl"
} // end of namespace pci_skin
#line 2 "Problems.tmpl"
#include "ViewContent.h" 
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
			#line 19 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t$('#pci_navigation_menu_problems_button').addClass('active');\n"
				"\t\t\t});\n"
				"\t\t";
		#line 19 "Problems.tmpl"
		} // end of template javascript_code
		#line 22 "Problems.tmpl"
		virtual void page_content() {
			#line 23 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 23 "Problems.tmpl"
			template_view::header_bar();
			#line 24 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 24 "Problems.tmpl"
			template_view::navigation_menu();
			#line 27 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problems_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 27 "Problems.tmpl"
			if(content.user_signed_in) {
				#line 28 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 28 "Problems.tmpl"
				template_view::toolbar_problems();
				#line 30 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<div class=\"pci_horizontal_line\"></div>\n"
					"\t\t\t\t\t";
			#line 30 "Problems.tmpl"
			} // endif
			#line 31 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t\t";
			#line 31 "Problems.tmpl"
			if((*content.problems).begin()!=(*content.problems).end()) {
				#line 32 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 32 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.problems).begin()) problem_ptr=(*content.problems).begin(),problem_ptr_end=(*content.problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 32 "Problems.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 34 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problems_problem_description\">\n"
						"\t\t\t\t\t\t\t\t";
					#line 34 "Problems.tmpl"
					template_view::problem_description(problem);
					#line 36 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t";
				#line 36 "Problems.tmpl"
				} // end of item
				#line 37 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 37 "Problems.tmpl"
			 } else {
				#line 39 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\tNo se encontraron problemas\n"
					"\t\t\t\t\t";
			#line 39 "Problems.tmpl"
			} // end of empty
			#line 42 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 42 "Problems.tmpl"
		} // end of template page_content
	#line 45 "Problems.tmpl"
	}; // end of class problems_view
#line 46 "Problems.tmpl"
} // end of namespace pci_skin
#line 2 "Problem.tmpl"
#include "ViewContent.h" 
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
		#line 14 "Problem.tmpl"
		virtual void page_content() {
			#line 15 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "Problem.tmpl"
			template_view::header_bar();
			#line 16 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "Problem.tmpl"
			template_view::navigation_menu();
			#line 19 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problem_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 19 "Problem.tmpl"
			if(content.user_signed_in) {
				#line 20 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 20 "Problem.tmpl"
				template_view::toolbar_problem(content.problem->id);
				#line 22 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<div class=\"pci_horizontal_line\"></div>\n"
					"\t\t\t\t\t";
			#line 22 "Problem.tmpl"
			} // endif
			#line 25 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<div id=\"pci_problem_header_container\">\n"
				"\t\t\t\t\t\t<h2>\n"
				"\t\t\t\t\t\t\t";
			#line 25 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->description);
			#line 30 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</h2>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_problem_problem_container\">\n"
				"\t\t\t\t\t\t<div class=\"pci_box_content\" id=\"pci_problem_problem_content\">\n"
				"\t\t\t\t\t\t\t";
			#line 30 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->content);
			#line 34 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_problem_solution_container\">\n"
				"\t\t\t\t\t\t";
			#line 34 "Problem.tmpl"
			if(content.problem->is_solved) {
				#line 36 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problem_solution_description\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 36 "Problem.tmpl"
				template_view::solution_description(content.problem,content.accepted_solution);
				#line 38 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 38 "Problem.tmpl"
			} // endif
			#line 39 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t";
			#line 39 "Problem.tmpl"
			if((*content.solutions).begin()!=(*content.solutions).end()) {
				#line 40 "Problem.tmpl"
				out()<<"\n"
					"\t\t \t\t\t\t\t";
				#line 40 "Problem.tmpl"
				for(CPPCMS_TYPEOF((*content.solutions).begin()) solution_ptr=(*content.solutions).begin(),solution_ptr_end=(*content.solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 40 "Problem.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 42 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problem_solution_description\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 42 "Problem.tmpl"
					template_view::solution_description(content.problem,solution);
					#line 44 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t  \t\t\t\t\t";
				#line 44 "Problem.tmpl"
				} // end of item
				#line 45 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
			#line 45 "Problem.tmpl"
			}
			#line 47 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t";
			#line 47 "Problem.tmpl"
			template_view::clarifications(content.clarifications);
			#line 50 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 50 "Problem.tmpl"
		} // end of template page_content
	#line 53 "Problem.tmpl"
	}; // end of class problem_view
#line 54 "Problem.tmpl"
} // end of namespace pci_skin
#line 2 "NewProblem.tmpl"
#include "ViewContent.h" 
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
			#line 25 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function(){\n"
				"\t\t\t\tconfigureTexteditor('pci_texteditor');\n"
				"\t\t\t});\n"
				"\t\t";
		#line 25 "NewProblem.tmpl"
		} // end of template javascript_code
		#line 28 "NewProblem.tmpl"
		virtual void page_content() {
			#line 29 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 29 "NewProblem.tmpl"
			template_view::header_bar();
			#line 30 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 30 "NewProblem.tmpl"
			template_view::navigation_menu();
			#line 33 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_new_problem_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 33 "NewProblem.tmpl"
			template_view::new_problem_form(content.new_problem_form_info);
			#line 36 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 36 "NewProblem.tmpl"
		} // end of template page_content
	#line 39 "NewProblem.tmpl"
	}; // end of class new_problem_view
#line 40 "NewProblem.tmpl"
} // end of namespace pci_skin
#line 2 "User.tmpl"
#include "ViewContent.h" 
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
			#line 19 "User.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t$('#pci_navigation_menu_profile_button').addClass('active');\n"
				"\t\t\t});\n"
				"\t\t";
		#line 19 "User.tmpl"
		} // end of template javascript_code
		#line 22 "User.tmpl"
		virtual void page_content() {
			#line 23 "User.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 23 "User.tmpl"
			template_view::header_bar();
			#line 24 "User.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 24 "User.tmpl"
			template_view::navigation_menu();
			#line 32 "User.tmpl"
			out()<<"\n"
				"\t\t\t\n"
				"\t\t\t<div id=\"pci_user_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<div id=\"column_1\">\n"
				"\t\t\t\t\t\t<div id=\"content_wrapper\">\n"
				"\t\t\t\t\t\t\t<div id=\"title_container\">\n"
				"\t\t\t\t\t\t\t\t<div id=\"rank_icon\"></div>\n"
				"\t\t\t\t\t\t\t\t<div id=\"big_name\">";
			#line 32 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->first_name);
			#line 32 "User.tmpl"
			out()<<" ";
			#line 32 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->last_name);
			#line 97 "User.tmpl"
			out()<<"</div>\n"
				"\t\t\t\t\t\t\t\t<div id=\"user_stats\">\n"
				"\t\t\t\t\t\t\t\t\t<div class=\"stat_container\">\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_number\">1000</div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_description\">Publicaciones</div>\n"
				"\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t<div class=\"stat_container\">\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_number\">400</div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_description\">Problemas</div>\n"
				"\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t<div class=\"stat_container\">\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_number\">900</div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_description\">Soluciones</div>\n"
				"\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t\t<div class=\"stat_container\">\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_number\">600</div>\n"
				"\t\t\t\t\t\t\t\t\t\t<div class=\"stat_description\">Soluciones aceptadas</div>\n"
				"\t\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\t\n"
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
				"\t\t\t\t\t\t\t\tCon apenas cinco años, Lionel Messi dio sus primeros pasos en Grandoli,\n"
				"\t\t\t\t\t\t\t\tun club de barrio a pocas manzanas de su casa, al sur de la ciudad \n"
				"\t\t\t\t\t\t\t\targentina de Rosario. El club era dirigido por su padre, Jorge.\n"
				"\t\t\t\t\t\t\t\tPosteriormente jugó algunos partidos con el Club Atlético Central Córdoba.\n"
				"\t\t\t\t\t\t\t\t En 1995, Messi comenzó a entrenarse en las divisiones inferiores de \n"
				"\t\t\t\t\t\t\t\tNewell's Old Boys, club con el que obtuvo la Copa de la Amistad de Perú\n"
				"\t\t\t\t\t\t\t\ten 1997. A la edad de 11 años, le fue diagnosticada una deficiencia de la\n"
				"\t\t\t\t\t\t\t\thormona de crecimiento. El Club Atlético River Plate mostró cierto interés\n"
				"\t\t\t\t\t\t\t\ten el progreso de Messi sin embargo, no creyó conveniente desembolsar el\n"
				"\t\t\t\t\t\t\t\tdinero para pagar el tratamiento que tenía un costo de $900 por mes.\n"
				"\t\t\t\t\t\t\t\tCarles Rexach, director técnico del Barcelona, notó el talento de Messi \n"
				"\t\t\t\t\t\t\t\ty éste tenía parientes en Lérida, España, siendo capaz, junto con su padre,\n"
				"\t\t\t\t\t\t\t\tde iniciar un viaje. El Barcelona lo fichó después de verlo jugar, \n"
				"\t\t\t\t\t\t\t\tofreciéndose entonces a pagar los costosos tratamientos si él se mudaba a\n"
				"\t\t\t\t\t\t\t\tEspaña. Su familia se trasladó a Barcelona donde comenzó a jugar con \n"
				"\t\t\t\t\t\t\t\tequipos juveniles.<br>\n"
				"\t\t\t\t\t\t\t\tMessi empezó a jugar en las categorias inferiores del FC Barcelona a la \n"
				"\t\t\t\t\t\t\t\tedad de 13 años. En ellas fue compañero de equipo de Cesc Fabregas y Gerard\n"
				"\t\t\t\t\t\t\t\tPiqué entre otros. Uno de sus primeros técnicos fue Tito Vilanova, quien años\n"
				"\t\t\t\t\t\t\t\tmás tarde sería su entrenador en el primer equipo.\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div id=\"recent_activity\">\n"
				"\t\t\t\t\t\t\t\trecent_activity\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"column_2\">\n"
				"\t\t\t\t\t\t<div id=\"profile_image\"></div>\n"
				"\t\t\t\t\t\t<div id=\"user_personal_info\">\n"
				"\t\t\t\t\t\t\t<div class=\"feature_container\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_title\">\n"
				"\t\t\t\t\t\t\t\t\tNombre de usuario\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"horizontal_line\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"feature_value\">\n"
				"\t\t\t\t\t\t\t\t\t";
			#line 97 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->user_name);
			#line 106 "User.tmpl"
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
			#line 106 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->first_name);
			#line 115 "User.tmpl"
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
			#line 115 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->last_name);
			#line 124 "User.tmpl"
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
			#line 124 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->genre);
			#line 133 "User.tmpl"
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
			#line 133 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->birth_date->toString("%d/%m/%Y"));
			#line 142 "User.tmpl"
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
			#line 142 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->email);
			#line 151 "User.tmpl"
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
			#line 151 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->sign_up_datetime->toString("%d/%m/%Y %H:%M:%S"));
			#line 159 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\n"
				"\t\t";
		#line 159 "User.tmpl"
		} // end of template page_content
	#line 162 "User.tmpl"
	}; // end of class user_view
#line 163 "User.tmpl"
} // end of namespace pci_skin
#line 2 "Solution.tmpl"
#include "ViewContent.h" 
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
		virtual void page_content() {
			#line 15 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "Solution.tmpl"
			template_view::header_bar();
			#line 16 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "Solution.tmpl"
			template_view::navigation_menu();
			#line 19 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_solution_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 19 "Solution.tmpl"
			template_view::toolbar_solution(content.problem_id);
			#line 23 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<div class=\"pci_horizontal_line\"></div>\n"
				"\t\t\t\t\t<div id=\"pci_solution_header_container\">\n"
				"\t\t\t\t\t\t<h2>\n"
				"\t\t\t\t\t\t\t";
			#line 23 "Solution.tmpl"
			out()<<cppcms::filters::escape(content.solution->description);
			#line 27 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</h2>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div class=\"pci_box_content\" id=\"pci_solution_solution_content\">\n"
				"\t\t\t\t\t\t";
			#line 27 "Solution.tmpl"
			out()<<cppcms::filters::escape(content.solution->content);
			#line 29 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t";
			#line 29 "Solution.tmpl"
			template_view::clarifications(content.clarifications);
			#line 32 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 32 "Solution.tmpl"
		} // end of template page_content
	#line 35 "Solution.tmpl"
	}; // end of class solution_view
#line 36 "Solution.tmpl"
} // end of namespace pci_skin
#line 2 "NewSolution.tmpl"
#include "ViewContent.h" 
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
			#line 25 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function(){\n"
				"\t\t\t\tconfigureTexteditor('pci_texteditor');\n"
				"\t\t\t});\n"
				"\t\t";
		#line 25 "NewSolution.tmpl"
		} // end of template javascript_code
		#line 28 "NewSolution.tmpl"
		virtual void page_content() {
			#line 29 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 29 "NewSolution.tmpl"
			template_view::header_bar();
			#line 30 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 30 "NewSolution.tmpl"
			template_view::navigation_menu();
			#line 33 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_new_solution_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 33 "NewSolution.tmpl"
			template_view::new_solution_form(content.new_solution_form_info);
			#line 36 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 36 "NewSolution.tmpl"
		} // end of template page_content
	#line 39 "NewSolution.tmpl"
	}; // end of class new_solution_view
#line 40 "NewSolution.tmpl"
} // end of namespace pci_skin
#line 2 "Ideas.tmpl"
#include "ViewContent.h" 
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
			#line 19 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t$('#pci_navigation_menu_ideas_button').addClass('active');\n"
				"\t\t\t});\n"
				"\t\t";
		#line 19 "Ideas.tmpl"
		} // end of template javascript_code
		#line 22 "Ideas.tmpl"
		virtual void page_content() {
			#line 23 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 23 "Ideas.tmpl"
			template_view::header_bar();
			#line 24 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 24 "Ideas.tmpl"
			template_view::navigation_menu();
			#line 30 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_ideas_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\tIdeas content\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 30 "Ideas.tmpl"
		} // end of template page_content
	#line 33 "Ideas.tmpl"
	}; // end of class ideas_view
#line 34 "Ideas.tmpl"
} // end of namespace pci_skin
#line 35 "Ideas.tmpl"
namespace {
#line 35 "Ideas.tmpl"
 cppcms::views::generator my_generator; 
#line 35 "Ideas.tmpl"
 struct loader { 
#line 35 "Ideas.tmpl"
  loader() { 
#line 35 "Ideas.tmpl"
   my_generator.name("pci_skin");
#line 35 "Ideas.tmpl"
   my_generator.add_view<pci_skin::template_view,ViewContent::TemplateContent>("template_view",true);
#line 35 "Ideas.tmpl"
   my_generator.add_view<pci_skin::index_view,ViewContent::IndexContent>("index_view",true);
#line 35 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problems_view,ViewContent::ProblemsContent>("problems_view",true);
#line 35 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problem_view,ViewContent::ProblemContent>("problem_view",true);
#line 35 "Ideas.tmpl"
   my_generator.add_view<pci_skin::new_problem_view,ViewContent::NewProblemContent>("new_problem_view",true);
#line 35 "Ideas.tmpl"
   my_generator.add_view<pci_skin::user_view,ViewContent::UserContent>("user_view",true);
#line 35 "Ideas.tmpl"
   my_generator.add_view<pci_skin::solution_view,ViewContent::SolutionContent>("solution_view",true);
#line 35 "Ideas.tmpl"
   my_generator.add_view<pci_skin::new_solution_view,ViewContent::NewSolutionContent>("new_solution_view",true);
#line 35 "Ideas.tmpl"
   my_generator.add_view<pci_skin::ideas_view,ViewContent::IdeasContent>("ideas_view",true);
#line 35 "Ideas.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 35 "Ideas.tmpl"
 }
#line 35 "Ideas.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 35 "Ideas.tmpl"
} a_loader;
#line 35 "Ideas.tmpl"
} // anon 
