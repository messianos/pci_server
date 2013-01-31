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
				"\t\t\t\t\t<div id=\"pci_header_bar_button_container\">\n"
				"\t\t\t\t\t \t";
			#line 58 "Template.tmpl"
			if(content.user_signed_in) {
				#line 59 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a href=\"";
				#line 59 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_out");
				#line 66 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tSalir\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t \t\t<div id=\"pci_header_bar_user_name_container\">\n"
					"\t\t\t\t\t \t\t\t<span id=\"pci_header_bar_user_name\">\n"
					"\t\t\t\t\t \t\t\t\t";
				#line 66 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_first_name);
				#line 66 "Template.tmpl"
				out()<<" ";
				#line 66 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_last_name);
				#line 69 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t \t\t\t</span>\n"
					"\t\t\t\t \t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 69 "Template.tmpl"
			}else{
				#line 72 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<div id=\"pci_sign_in_floating_form\">\n"
					"\t\t\t\t\t\t\t\t<form id=\"signInForm\" action=\"\" method=\"post\">\n"
					"\t\t\t\t\t\t\t\t\t";
				#line 72 "Template.tmpl"
				{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.sign_in_form_info).render(_form_context); }
				#line 75 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t</form>\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t<!-- href=\"";
				#line 75 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_in");
				#line 81 "Template.tmpl"
				out()<<"\" -->\n"
					"\t\t\t\t\t\t\t<a onclick=\"javascript:show_sign_in_form()\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\" id=\"pci_header_bar_button_sign_in\">\n"
					"\t\t\t\t\t\t\t\t\tIngresar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t\t<a href=\"";
				#line 81 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_up");
				#line 86 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tRegistrar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t";
			#line 86 "Template.tmpl"
			}
			#line 90 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 90 "Template.tmpl"
		} // end of template header_bar
		#line 93 "Template.tmpl"
		virtual void information_footer() {
			#line 107 "Template.tmpl"
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
			#line 107 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 112 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAcerca de\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 112 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 117 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tFilosofía\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 117 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 129 "Template.tmpl"
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
			#line 129 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 134 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 134 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 139 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 139 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 151 "Template.tmpl"
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
			#line 151 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 156 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAyuda\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 156 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 161 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCondiciones de servicio\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 161 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 169 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCopyright\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 169 "Template.tmpl"
		} // end of template information_footer
		#line 172 "Template.tmpl"
		virtual void navigation_menu() {
			#line 174 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_navigation_menu_main_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 174 "Template.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 179 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_problems_button\">\n"
				"\t\t\t\t\t\tProblemas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 179 "Template.tmpl"
			content.app().mapper().map(out(),"/ideas");
			#line 184 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_ideas_button\">\n"
				"\t\t\t\t\t\tIdeas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t";
			#line 184 "Template.tmpl"
			if(content.user_signed_in) {
				#line 186 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<div class=\"pci_horizontal_line\" ></div>\n"
					"\t\t\t\t\t<a href=\"";
				#line 186 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 191 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_profile_button\">\n"
					"\t\t\t\t\t\t\tPerfil\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t</a>\n"
					"\t\t\t\t";
			#line 191 "Template.tmpl"
			} // endif
			#line 193 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 193 "Template.tmpl"
		} // end of template navigation_menu
		#line 196 "Template.tmpl"
		virtual void problem_description(ProblemPointer problem) {
			#line 197 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 197 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem->id));
			#line 198 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t";
			#line 198 "Template.tmpl"
			out()<<cppcms::filters::escape(problem->description);
			#line 201 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t";
			#line 201 "Template.tmpl"
			if(problem->is_anonymous) {
				#line 203 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Publicado Anónimamente</i>\n"
					"\t\t\t\t";
			#line 203 "Template.tmpl"
			}else{
				#line 204 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 204 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(problem->creator_user_name));
				#line 204 "Template.tmpl"
				out()<<"\">";
				#line 204 "Template.tmpl"
				out()<<cppcms::filters::escape(problem->creator_user_name);
				#line 205 "Template.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t";
			#line 205 "Template.tmpl"
			}
			#line 206 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t- ";
			#line 206 "Template.tmpl"
			out()<<cppcms::filters::escape(problem->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 208 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</span>\n"
				"\t\t";
		#line 208 "Template.tmpl"
		} // end of template problem_description
		#line 211 "Template.tmpl"
		virtual void solution_description(ProblemPointer problem,SolutionPointer solution) {
			#line 212 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 212 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem->id), cppcms::filters::urlencode(solution->id));
			#line 213 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t";
			#line 213 "Template.tmpl"
			out()<<cppcms::filters::escape(solution->description);
			#line 216 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t";
			#line 216 "Template.tmpl"
			if(solution->is_anonymous) {
				#line 218 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Publicado Anónimamente</i>\n"
					"\t\t\t\t";
			#line 218 "Template.tmpl"
			}else{
				#line 219 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 219 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(solution->creator_user_name));
				#line 219 "Template.tmpl"
				out()<<"\">";
				#line 219 "Template.tmpl"
				out()<<cppcms::filters::escape(solution->creator_user_name);
				#line 220 "Template.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t";
			#line 220 "Template.tmpl"
			}
			#line 221 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t- ";
			#line 221 "Template.tmpl"
			out()<<cppcms::filters::escape(solution->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 223 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</span>\n"
				"\t\t";
		#line 223 "Template.tmpl"
		} // end of template solution_description
		#line 226 "Template.tmpl"
		virtual void toolbar_problems() {
			#line 228 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problems_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 228 "Template.tmpl"
			content.app().mapper().map(out(),"/new_problem");
			#line 234 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problems_button\" id=\"pci_toolbar_problems_new_problem_button\">\n"
				"\t\t\t\t\t\tNuevo problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 234 "Template.tmpl"
		} // end of template toolbar_problems
		#line 237 "Template.tmpl"
		virtual void toolbar_problem(std::string problem_id) {
			#line 239 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problem_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 239 "Template.tmpl"
			content.app().mapper().map(out(),"/new_solution", cppcms::filters::urlencode(problem_id));
			#line 245 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problem_button\" id=\"pci_toolbar_problem_new_solution_button\">\n"
				"\t\t\t\t\t\tPlantear solución\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 245 "Template.tmpl"
		} // end of template toolbar_problem
		#line 248 "Template.tmpl"
		virtual void toolbar_solution(std::string problem_id) {
			#line 250 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_solution_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 250 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem_id));
			#line 256 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_solution_button\" id=\"pci_toolbar_solution_go_back_button\">\n"
				"\t\t\t\t\t\tVolver al problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 256 "Template.tmpl"
		} // end of template toolbar_solution
		#line 259 "Template.tmpl"
		virtual void css_links() {
			#line 262 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/template.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/ui-lightness/jquery-ui-1.9.2.custom.css\" rel=\"stylesheet\">\n"
				"\t\t";
		#line 262 "Template.tmpl"
		} // end of template css_links
		#line 265 "Template.tmpl"
		virtual void javascript_code() {
			#line 270 "Template.tmpl"
			out()<<"\n"
				"\t\t\tfunction show_sign_in_form(){\n"
				"\t\t\t\t$(\"#pci_sign_in_floating_form\").toggle(300);\n"
				"\t\t\t\t$(\"#pci_header_bar_button_sign_in\").toggleClass('floating_form_visible');\n"
				"\t\t\t}\n"
				"\t\t";
		#line 270 "Template.tmpl"
		} // end of template javascript_code
		#line 273 "Template.tmpl"
		virtual void page_content() {
			#line 274 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 274 "Template.tmpl"
		} // end of template page_content
		#line 277 "Template.tmpl"
		virtual void render() {
			#line 281 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<!DOCTYPE html>\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 281 "Template.tmpl"
			css_links();
			#line 287 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<script src=\"/js/jquery-1.9.0.min.js\"></script>\n"
				"\t\t\t\t\t<script src=\"/js/jquery-ui-1.9.2.custom.js\"></script>\n"
				"\t\t\t\t\t<script src=\"/lib/ckeditor/ckeditor.js\"></script>\n"
				"\t\t\t\t\t<script src=\"/js/jquery.validate.js\"></script>\n"
				"\t\t\t\t\t<script>\n"
				"\t\t\t\t\t\t";
			#line 287 "Template.tmpl"
			javascript_code();
			#line 290 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</script>\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 290 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 294 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t";
			#line 294 "Template.tmpl"
			page_content();
			#line 297 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 297 "Template.tmpl"
		} // end of template render
	#line 300 "Template.tmpl"
	}; // end of class template_view
#line 301 "Template.tmpl"
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
			#line 11 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/index.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "Index.tmpl"
		} // end of template css_links
		#line 14 "Index.tmpl"
		virtual void page_content() {
			#line 15 "Index.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "Index.tmpl"
			template_view::header_bar();
			#line 18 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_index_main_container\">\n"
				"\t\t\t\n"
				"\t\t\t\t<a href=\"";
			#line 18 "Index.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 28 "Index.tmpl"
			out()<<"\" ><h2>Problemas</h2></a>\n"
				"\t\t\t\tComienzo content\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\tIndex content\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\t<br />\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 28 "Index.tmpl"
			template_view::information_footer();
			#line 29 "Index.tmpl"
			out()<<"\n"
				"\t\t";
		#line 29 "Index.tmpl"
		} // end of template page_content
	#line 32 "Index.tmpl"
	}; // end of class index_view
#line 33 "Index.tmpl"
} // end of namespace pci_skin
#line 2 "SignIn.tmpl"
#include "ViewContent.h" 
#line 4 "SignIn.tmpl"
namespace pci_skin {
	#line 5 "SignIn.tmpl"
	struct sign_in_view :public template_view
	#line 5 "SignIn.tmpl"
	{
	#line 5 "SignIn.tmpl"
		ViewContent::SignInContent &content;
	#line 5 "SignIn.tmpl"
		sign_in_view(std::ostream &_s,ViewContent::SignInContent &_content): template_view(_s,_content),content(_content)
	#line 5 "SignIn.tmpl"
		{
	#line 5 "SignIn.tmpl"
		}
		#line 8 "SignIn.tmpl"
		virtual void css_links() {
			#line 9 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "SignIn.tmpl"
			template_view::css_links();
			#line 11 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/sign_in.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "SignIn.tmpl"
		} // end of template css_links
		#line 13 "SignIn.tmpl"
		virtual void javascript_code() {
			#line 110 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t\tfunction addTextfieldLabel(textfieldId, labelText) {\n"
				"\t\t\t\t\tvar textfield = $('#' + textfieldId);\n"
				"\t\t\t\t\tvar label = $('<label>' + labelText + '</label>');\n"
				"\t\t\t\t\tlabel.attr('id', textfieldId + '_label');\n"
				"\t\t\t\t\tlabel.attr('for', textfieldId);\n"
				"\t\t\t\t\tlabel.css('position', 'absolute');\n"
				"\t\t\t\t\tlabel.offset(textfield.offset());\n"
				"\t\t\t\t\tlabel.addClass('pci_label_textfield');\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\ttextfield.blur(function() {\n"
				"\t\t\t\t\t\tif ($(this).val().length == 0) {\n"
				"\t\t\t\t\t\t\tvar label = $('#' + $(this).attr('id') + '_label');\n"
				"\t\t\t\t\t\t\tlabel.removeClass('focus');\n"
				"\t\t\t\t\t\t\tlabel.css('display', 'inline');\n"
				"\t\t\t\t\t\t}\n"
				"\t\t\t\t\t});\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\ttextfield.change(function() {\n"
				"\t\t\t\t\t\thideErrorBox($(this).attr('id'));\n"
				"\t\t\t\t\t\tif ($(this).val().length > 0)\n"
				"\t\t\t\t\t\t\t$('#' + $(this).attr('id') + '_label').css('display', 'none');\n"
				"\t\t\t\t\t});\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\ttextfield.focus(function() {\n"
				"\t\t\t\t\t\tif ($(this).val().length == 0)\n"
				"\t\t\t\t\t\t\t$('#' + $(this).attr('id') + '_label').addClass('focus');\n"
				"\t\t\t\t\t});\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\ttextfield.keydown(function() {\n"
				"\t\t\t\t\t\t$('#' + $(this).attr('id') + '_label').css('display', 'none');\n"
				"\t\t\t\t\t});\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\ttextfield.parent().prepend(label);\n"
				"\t\t\t\t}\n"
				"\t\t\t\t\n"
				"\t\t\t\tfunction showErrorBox(elementId, errorDescription) {\n"
				"\t\t\t\t\tvar element = $('#' + elementId);\n"
				"\t\t\t\t\tvar box = $('<div>' + errorDescription + '</div>');\n"
				"\t\t\t\t\tbox.attr('id', elementId + '_error_box');\n"
				"\t\t\t\t\tbox.css('position', 'absolute');\n"
				"\t\t\t\t\tvar offset = element.offset();\n"
				"\t\t\t\t\toffset.left += element.outerWidth() + 8;\n"
				"\t\t\t\t\tbox.offset(offset);\n"
				"\t\t\t\t\tbox.addClass('pci_box_error');\n"
				"\t\t\t\t\telement.addClass('error');\n"
				"\t\t\t\t\telement.parent().append(box);\n"
				"\t\t\t\t}\n"
				"\t\t\t\t\n"
				"\t\t\t\tfunction hideErrorBox(elementId) {\n"
				"\t\t\t\t\t$('#' + elementId).removeClass('error');\n"
				"\t\t\t\t\t$('#' + elementId + '_error_box').remove();\n"
				"\t\t\t\t}\n"
				"\t\t\t\t\n"
				"\t\t\t\tfunction hideErrorBoxes() {\n"
				"\t\t\t\t\t$('.error').removeClass('error');\n"
				"\t\t\t\t\t$('div.pci_box_error').remove();\n"
				"\t\t\t\t}\n"
				"\t\t\t\t\n"
				"\t\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t\taddTextfieldLabel('pci_textfield_sign_in_user_name', 'Nombre de usuario');\n"
				"\t\t\t\t\taddTextfieldLabel('pci_textfield_sign_in_password', 'Contraseña');\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\t$(\"#signInForm\").validate(\n"
				"\t   \t\t\t\t \t{  rules: {\n"
				"\t    \t\t\t\t\t\t\tpassword: {\n"
				"\t    \t\t\t\t\t\t\t\t\t\trequired: true,\n"
				"\t    \t\t\t\t\t\t\t\t\t\tminlength: 6,\n"
				"\t    \t\t\t\t\t\t\t\t\t\t}\n"
				"\t    \t\t\t\t\t\t\t},\n"
				"\t  \t\t\t\t\t  errorPlacement: function(error, element){\n"
				"\t  \t\t\t\t\t  \t\tshowErrorBox(element.attr('id'), error.html());\n"
				"\t  \t\t\t\t\t  }\n"
				"\t                   }\n"
				"\t   \t\t\t\t \n"
				"\t   \t\t\t\t );\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\tjQuery.extend(jQuery.validator.messages, {\n"
				"\t\t\t\t\trequired: \"Campo requerido.\",\n"
				"\t\t\t\t\temail: \"La dirección de correo es inválida. \",\n"
				"\t\t\t\t\turl: \"Please enter a valid URL.\",\n"
				"\t\t\t\t\tdate: \"Please enter a valid date.\",\n"
				"\t\t\t\t\tdateISO: \"Please enter a valid date (ISO).\",\n"
				"\t\t\t\t\tnumber: \"Please enter a valid number.\",\n"
				"\t\t\t\t\tdigits: \"Please enter only digits.\",\n"
				"\t\t\t\t\tcreditcard: \"Please enter a valid credit card number.\",\n"
				"\t\t\t\t\tequalTo: \"Las contraseñas no coinciden.\",\n"
				"\t\t\t\t\taccept: \"Please enter a value with a valid extension.\",\n"
				"\t\t\t\t\tmaxlength: jQuery.validator.format(\"Please enter no more than {0} characters.\"),\n"
				"\t\t\t\t\tminlength: jQuery.validator.format(\"La contraseña debe tener al menos {0} caracters.\"),\n"
				"\t\t\t\t\trangelength: jQuery.validator.format(\"Please enter a value between {0} and {1} characters long.\"),\n"
				"\t\t\t\t\trange: jQuery.validator.format(\"Please enter a value between {0} and {1}.\"),\n"
				"\t\t\t\t\tmax: jQuery.validator.format(\"Please enter a value less than or equal to {0}.\"),\n"
				"\t\t\t\t\tmin: jQuery.validator.format(\"Please enter a value greater than or equal to {0}.\")\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t";
		#line 110 "SignIn.tmpl"
		} // end of template javascript_code
		#line 112 "SignIn.tmpl"
		virtual void page_content() {
			#line 113 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 113 "SignIn.tmpl"
			template_view::header_bar();
			#line 114 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 114 "SignIn.tmpl"
			template_view::navigation_menu();
			#line 119 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_sign_in_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<h1>Ingrese sus datos</h1>\n"
				"\t\t\t\t\t<form id=\"signInForm\" action=\"\" method=\"post\">\n"
				"\t\t\t\t\t\t";
			#line 119 "SignIn.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.sign_in_form_info).render(_form_context); }
			#line 123 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</form>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 123 "SignIn.tmpl"
		} // end of template page_content
	#line 125 "SignIn.tmpl"
	}; // end of class sign_in_view
#line 126 "SignIn.tmpl"
} // end of namespace pci_skin
#line 2 "SignUp.tmpl"
#include "ViewContent.h" 
#line 4 "SignUp.tmpl"
namespace pci_skin {
	#line 5 "SignUp.tmpl"
	struct sign_up_view :public template_view
	#line 5 "SignUp.tmpl"
	{
	#line 5 "SignUp.tmpl"
		ViewContent::SignUpContent &content;
	#line 5 "SignUp.tmpl"
		sign_up_view(std::ostream &_s,ViewContent::SignUpContent &_content): template_view(_s,_content),content(_content)
	#line 5 "SignUp.tmpl"
		{
	#line 5 "SignUp.tmpl"
		}
		#line 8 "SignUp.tmpl"
		virtual void css_links() {
			#line 9 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 9 "SignUp.tmpl"
			template_view::css_links();
			#line 11 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/sign_up.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 11 "SignUp.tmpl"
		} // end of template css_links
		#line 13 "SignUp.tmpl"
		virtual void javascript_code() {
			#line 140 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\tfunction addTextfieldLabel(textfieldId, labelText) {\n"
				"\t\t\t\tvar textfield = $('#' + textfieldId);\n"
				"\t\t\t\tvar label = $('<label>' + labelText + '</label>');\n"
				"\t\t\t\tlabel.attr('id', textfieldId + '_label');\n"
				"\t\t\t\tlabel.attr('for', textfieldId);\n"
				"\t\t\t\tlabel.css('position', 'absolute');\n"
				"\t\t\t\tlabel.offset(textfield.offset());\n"
				"\t\t\t\tlabel.addClass('pci_label_textfield');\n"
				"\t\t\t\t\n"
				"\t\t\t\ttextfield.blur(function() {\n"
				"\t\t\t\t\tif ($(this).val().length == 0) {\n"
				"\t\t\t\t\t\tvar label = $('#' + $(this).attr('id') + '_label');\n"
				"\t\t\t\t\t\tlabel.removeClass('focus');\n"
				"\t\t\t\t\t\tlabel.css('display', 'inline');\n"
				"\t\t\t\t\t}\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\ttextfield.change(function() {\n"
				"\t\t\t\t\thideErrorBox($(this).attr('id'));\n"
				"\t\t\t\t\tif ($(this).val().length > 0)\n"
				"\t\t\t\t\t\t$('#' + $(this).attr('id') + '_label').css('display', 'none');\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\ttextfield.focus(function() {\n"
				"\t\t\t\t\tif ($(this).val().length == 0)\n"
				"\t\t\t\t\t\t$('#' + $(this).attr('id') + '_label').addClass('focus');\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\ttextfield.keydown(function() {\n"
				"\t\t\t\t\t$('#' + $(this).attr('id') + '_label').css('display', 'none');\n"
				"\t\t\t\t});\n"
				"\t\t\t\t\n"
				"\t\t\t\ttextfield.parent().prepend(label);\n"
				"\t\t\t}\n"
				"\t\t\t\n"
				"\t\t\tfunction configureDropdownlist(dropdownlistId) {\n"
				"\t\t\t\t$('#' + dropdownlistId).change(function() {\n"
				"\t\t\t\t\tif($(this).prop('selectedIndex') > 0) {\n"
				"\t\t\t\t\t\t$(this).addClass('selected');\n"
				"\t\t\t\t\t\thideErrorBox($(this).attr('id'));\n"
				"\t\t\t\t\t} else\n"
				"\t\t\t\t\t\t$(this).removeClass('selected');\n"
				"\t\t\t\t});\n"
				"\t\t\t}\n"
				"\t\t\t\n"
				"\t\t\tfunction configureDatepicker(elementId) {\n"
				"\t\t\t\t$('#' + elementId).datepicker({\n"
				"\t\t\t\t    showOn:'focus',\n"
				"\t\t\t    \tyearRange:'1920:2010',\n"
				"\t\t\t    \tdateFormat:'dd-mm-yy',\n"
				"\t\t\t    \tchangeMonth:true,\n"
				"\t\t\t    \tchangeYear:true\n"
				"\t\t\t\t});\n"
				"\t\t\t}\n"
				"\t\t\t\n"
				"\t\t\tfunction showErrorBox(elementId, errorDescription) {\n"
				"\t\t\t\tvar element = $('#' + elementId);\n"
				"\t\t\t\tvar box = $('<div>' + errorDescription + '</div>');\n"
				"\t\t\t\tbox.attr('id', elementId + '_error_box');\n"
				"\t\t\t\tbox.css('position', 'absolute');\n"
				"\t\t\t\tvar offset = element.offset();\n"
				"\t\t\t\toffset.left += element.outerWidth() + 8;\n"
				"\t\t\t\tbox.offset(offset);\n"
				"\t\t\t\tbox.addClass('pci_box_error');\n"
				"\t\t\t\telement.addClass('error');\n"
				"\t\t\t\telement.parent().append(box);\n"
				"\t\t\t}\n"
				"\t\t\t\n"
				"\t\t\tfunction hideErrorBox(elementId) {\n"
				"\t\t\t\t$('#' + elementId).removeClass('error');\n"
				"\t\t\t\t$('#' + elementId + '_error_box').remove();\n"
				"\t\t\t}\n"
				"\t\t\t\n"
				"\t\t\tfunction hideErrorBoxes() {\n"
				"\t\t\t\t$('.error').removeClass('error');\n"
				"\t\t\t\t$('div.pci_box_error').remove();\n"
				"\t\t\t}\n"
				"\t\t\t\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\taddTextfieldLabel('pci_textfield_sign_up_first_name', 'Nombre');\n"
				"\t\t\t\taddTextfieldLabel('pci_textfield_sign_up_last_name', 'Apellido');\n"
				"\t\t\t\taddTextfieldLabel('pci_textfield_sign_up_user_name', 'Nombre de usuario');\n"
				"\t\t\t\taddTextfieldLabel('pci_textfield_sign_up_email', 'E-Mail');\n"
				"\t\t\t\taddTextfieldLabel('pci_textfield_sign_up_password', 'Contraseña');\n"
				"\t\t\t\taddTextfieldLabel('pci_textfield_sign_up_password_verification', 'Confirmar contraseña');\n"
				"\t\t\t\taddTextfieldLabel('pci_textfield_sign_up_date', 'Fecha de nacimiento');\n"
				"\t\t\t\tconfigureDropdownlist('pci_dropdownlist_sign_up_genre');\n"
				"\t\t\t\tconfigureDatepicker('pci_textfield_sign_up_date');\n"
				"\t\t\t\t\n"
				"\t\t\t\t$(\"#signUpForm\").validate(\n"
				"   \t\t\t\t \t{  rules: {\n"
				"    \t\t\t\t\t\t\tpassword: {\n"
				"    \t\t\t\t\t\t\t\t\t\trequired: true,\n"
				"    \t\t\t\t\t\t\t\t\t\tminlength: 6,\n"
				"    \t\t\t\t\t\t\t\t\t\t},\n"
				"   \t\t\t\t\t\t\t\tpassword_verification: {\n"
				"      \t\t\t\t\t\t\t\t\t\tequalTo: \"#pci_textfield_sign_up_password\"\n"
				"    \t\t\t\t\t\t\t\t\t\t\t\t\t}\n"
				"  \t\t\t\t\t\t\t\t},\n"
				"  \t\t\t\t\t  errorPlacement: function(error, element){\n"
				"  \t\t\t\t\t  \t\tshowErrorBox(element.attr('id'), error.html());\n"
				"  \t\t\t\t\t  }\n"
				"                   }\n"
				"   \t\t\t\t \n"
				"   \t\t\t\t );\n"
				"\t\t\t});\n"
				"\t\t\t\n"
				"\t\t\tjQuery.extend(jQuery.validator.messages, {\n"
				"\t\t\t\trequired: \"Campo requerido.\",\n"
				"\t\t\t\temail: \"La dirección de correo es inválida. \",\n"
				"\t\t\t\turl: \"Please enter a valid URL.\",\n"
				"\t\t\t\tdate: \"Please enter a valid date.\",\n"
				"\t\t\t\tdateISO: \"Please enter a valid date (ISO).\",\n"
				"\t\t\t\tnumber: \"Please enter a valid number.\",\n"
				"\t\t\t\tdigits: \"Please enter only digits.\",\n"
				"\t\t\t\tcreditcard: \"Please enter a valid credit card number.\",\n"
				"\t\t\t\tequalTo: \"Las contraseñas no coinciden.\",\n"
				"\t\t\t\taccept: \"Please enter a value with a valid extension.\",\n"
				"\t\t\t\tmaxlength: jQuery.validator.format(\"Please enter no more than {0} characters.\"),\n"
				"\t\t\t\tminlength: jQuery.validator.format(\"La contraseña debe tener al menos {0} caracters.\"),\n"
				"\t\t\t\trangelength: jQuery.validator.format(\"Please enter a value between {0} and {1} characters long.\"),\n"
				"\t\t\t\trange: jQuery.validator.format(\"Please enter a value between {0} and {1}.\"),\n"
				"\t\t\t\tmax: jQuery.validator.format(\"Please enter a value less than or equal to {0}.\"),\n"
				"\t\t\t\tmin: jQuery.validator.format(\"Please enter a value greater than or equal to {0}.\")\n"
				"\t\t\t});\n"
				"\t\t\t\n"
				"\t\t";
		#line 140 "SignUp.tmpl"
		} // end of template javascript_code
		#line 142 "SignUp.tmpl"
		virtual void page_content() {
			#line 143 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 143 "SignUp.tmpl"
			template_view::header_bar();
			#line 144 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 144 "SignUp.tmpl"
			template_view::navigation_menu();
			#line 149 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_sign_up_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<h1>Registrar</h1>\n"
				"\t\t\t\t\t<form id=\"signUpForm\" action=\"\" method=\"post\">\n"
				"\t\t\t\t\t\t";
			#line 149 "SignUp.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 153 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</form>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 153 "SignUp.tmpl"
		} // end of template page_content
	#line 156 "SignUp.tmpl"
	}; // end of class sign_up_view
#line 157 "SignUp.tmpl"
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
			#line 18 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t$('#pci_navigation_menu_problems_button').addClass('active');\n"
				"\t\t\t});\n"
				"\t\t";
		#line 18 "Problems.tmpl"
		} // end of template javascript_code
		#line 21 "Problems.tmpl"
		virtual void page_content() {
			#line 22 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 22 "Problems.tmpl"
			template_view::header_bar();
			#line 23 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 23 "Problems.tmpl"
			template_view::navigation_menu();
			#line 26 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problems_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 26 "Problems.tmpl"
			if(content.user_signed_in) {
				#line 27 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 27 "Problems.tmpl"
				template_view::toolbar_problems();
				#line 29 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<div class=\"pci_horizontal_line\"></div>\n"
					"\t\t\t\t\t";
			#line 29 "Problems.tmpl"
			} // endif
			#line 30 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t\t";
			#line 30 "Problems.tmpl"
			if((*content.problems).begin()!=(*content.problems).end()) {
				#line 31 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 31 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.problems).begin()) problem_ptr=(*content.problems).begin(),problem_ptr_end=(*content.problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 31 "Problems.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 33 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problems_problem_description\">\n"
						"\t\t\t\t\t\t\t\t";
					#line 33 "Problems.tmpl"
					template_view::problem_description(problem);
					#line 35 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t";
				#line 35 "Problems.tmpl"
				} // end of item
				#line 36 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 36 "Problems.tmpl"
			 } else {
				#line 38 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\tNo se encontraron problemas\n"
					"\t\t\t\t\t";
			#line 38 "Problems.tmpl"
			} // end of empty
			#line 41 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 41 "Problems.tmpl"
		} // end of template page_content
	#line 44 "Problems.tmpl"
	}; // end of class problems_view
#line 45 "Problems.tmpl"
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
		#line 13 "NewProblem.tmpl"
		virtual void javascript_code() {
			#line 33 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function(){\n"
				"\t\t\t\tCKEDITOR.replace('pci_text_editor', {\n"
				"\t\t\t\t\tcustomConfig: '',\n"
				"\t\t\t\t\textraPlugins: 'bbcode',\n"
				"\t\t\t\t\tfontSize_sizes: \"10/100%; 12/120%; 14/140%; 16/160%; 18/180%; 20/200%\",\n"
				"\t\t\t\t\tlanguage: 'es',\n"
				"\t\t\t\t\tremovePlugins: 'elementspath, colordialog',\n"
				"\t\t\t\t\tresize_enabled: false,\n"
				"\t\t\t\t\ttoolbar: [\n"
				"\t\t\t\t\t\t[ 'Undo', '-', 'Redo' ],\n"
				"\t\t\t\t\t\t[ 'FontSize' ],\n"
				"\t\t\t\t\t\t[ 'Bold', 'Italic', 'Underline', '-', 'TextColor' ],\n"
				"\t\t\t\t\t\t[ 'RemoveFormat' ],\n"
				"\t\t\t\t\t\t[ 'Link', '-', 'Unlink' ],\n"
				"\t\t\t\t\t\t[ 'NumberedList', 'BulletedList', '-', 'Blockquote' ]\n"
				"\t\t\t\t\t],\n"
				"\t\t\t\t\tuiColor: '#6CA4C8'\n"
				"\t\t\t\t});\n"
				"\t\t\t});\n"
				"\t\t";
		#line 33 "NewProblem.tmpl"
		} // end of template javascript_code
		#line 36 "NewProblem.tmpl"
		virtual void page_content() {
			#line 37 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 37 "NewProblem.tmpl"
			template_view::header_bar();
			#line 38 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 38 "NewProblem.tmpl"
			template_view::navigation_menu();
			#line 42 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_new_problem_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t\t";
			#line 42 "NewProblem.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 46 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</form>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 46 "NewProblem.tmpl"
		} // end of template page_content
	#line 49 "NewProblem.tmpl"
	}; // end of class new_problem_view
#line 50 "NewProblem.tmpl"
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
			#line 18 "User.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t$('#pci_navigation_menu_profile_button').addClass('active');\n"
				"\t\t\t});\n"
				"\t\t";
		#line 18 "User.tmpl"
		} // end of template javascript_code
		#line 21 "User.tmpl"
		virtual void page_content() {
			#line 22 "User.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 22 "User.tmpl"
			template_view::header_bar();
			#line 23 "User.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 23 "User.tmpl"
			template_view::navigation_menu();
			#line 31 "User.tmpl"
			out()<<"\n"
				"\t\t\t\n"
				"\t\t\t<div id=\"pci_user_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<div id=\"column_1\">\n"
				"\t\t\t\t\t\t<div id=\"content_wrapper\">\n"
				"\t\t\t\t\t\t\t<div id=\"title_container\">\n"
				"\t\t\t\t\t\t\t\t<div id=\"rank_icon\"></div>\n"
				"\t\t\t\t\t\t\t\t<div id=\"big_name\">";
			#line 31 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->first_name);
			#line 31 "User.tmpl"
			out()<<" ";
			#line 31 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->last_name);
			#line 96 "User.tmpl"
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
			#line 96 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->user_name);
			#line 105 "User.tmpl"
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
			#line 105 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->first_name);
			#line 114 "User.tmpl"
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
			#line 114 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->last_name);
			#line 123 "User.tmpl"
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
			#line 123 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->genre);
			#line 132 "User.tmpl"
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
			#line 132 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->birth_date->toString("%d/%m/%Y"));
			#line 141 "User.tmpl"
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
			#line 141 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->email);
			#line 150 "User.tmpl"
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
			#line 150 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->sign_up_datetime->toString("%d/%m/%Y %H:%M:%S"));
			#line 158 "User.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\n"
				"\t\t";
		#line 158 "User.tmpl"
		} // end of template page_content
	#line 161 "User.tmpl"
	}; // end of class user_view
#line 162 "User.tmpl"
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
		virtual void page_content() {
			#line 15 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "NewSolution.tmpl"
			template_view::header_bar();
			#line 16 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "NewSolution.tmpl"
			template_view::navigation_menu();
			#line 20 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_new_solution_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t\t";
			#line 20 "NewSolution.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 24 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</form>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 24 "NewSolution.tmpl"
		} // end of template page_content
	#line 27 "NewSolution.tmpl"
	}; // end of class new_solution_view
#line 28 "NewSolution.tmpl"
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
			#line 18 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t$('#pci_navigation_menu_ideas_button').addClass('active');\n"
				"\t\t\t});\n"
				"\t\t";
		#line 18 "Ideas.tmpl"
		} // end of template javascript_code
		#line 21 "Ideas.tmpl"
		virtual void page_content() {
			#line 22 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 22 "Ideas.tmpl"
			template_view::header_bar();
			#line 23 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 23 "Ideas.tmpl"
			template_view::navigation_menu();
			#line 29 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_ideas_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\tIdeas content\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 29 "Ideas.tmpl"
		} // end of template page_content
	#line 32 "Ideas.tmpl"
	}; // end of class ideas_view
#line 33 "Ideas.tmpl"
} // end of namespace pci_skin
#line 34 "Ideas.tmpl"
namespace {
#line 34 "Ideas.tmpl"
 cppcms::views::generator my_generator; 
#line 34 "Ideas.tmpl"
 struct loader { 
#line 34 "Ideas.tmpl"
  loader() { 
#line 34 "Ideas.tmpl"
   my_generator.name("pci_skin");
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::template_view,ViewContent::TemplateContent>("template_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::index_view,ViewContent::IndexContent>("index_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::sign_in_view,ViewContent::SignInContent>("sign_in_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::sign_up_view,ViewContent::SignUpContent>("sign_up_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problems_view,ViewContent::ProblemsContent>("problems_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problem_view,ViewContent::ProblemContent>("problem_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::new_problem_view,ViewContent::NewProblemContent>("new_problem_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::user_view,ViewContent::UserContent>("user_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::solution_view,ViewContent::SolutionContent>("solution_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::new_solution_view,ViewContent::NewSolutionContent>("new_solution_view",true);
#line 34 "Ideas.tmpl"
   my_generator.add_view<pci_skin::ideas_view,ViewContent::IdeasContent>("ideas_view",true);
#line 34 "Ideas.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 34 "Ideas.tmpl"
 }
#line 34 "Ideas.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 34 "Ideas.tmpl"
} a_loader;
#line 34 "Ideas.tmpl"
} // anon 
