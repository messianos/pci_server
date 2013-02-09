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
		virtual void clarifications(ClarificationList clarifications,PublicationPointer publication) {
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
						#line 30 "Template.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t<div class=\"pci_clarifications_row_container\">\n"
							"\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_question_container\">\n"
							"\t\t\t\t\t\t\t\t\t<div class=\"pci_box_content pci_clarifications_question_content\">\n"
							"\t\t\t\t\t\t\t\t\t\t<span class=\"pci_text_clarification\">\n"
							"\t\t\t\t\t\t\t\t\t\t\t";
						#line 30 "Template.tmpl"
						out()<<cppcms::filters::escape(clarification->question);
						#line 35 "Template.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t\t\t</span>\n"
							"\t\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
							"\t\t\t\t\t\t\t\t\t";
						#line 35 "Template.tmpl"
						if(! clarification->answer.empty()) {
							#line 38 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t\t<div class=\"pci_box_content pci_clarifications_answer_content\">\n"
								"\t\t\t\t\t\t\t\t\t\t\t<span class=\"pci_text_clarification\">\n"
								"\t\t\t\t\t\t\t\t\t\t\t\t";
							#line 38 "Template.tmpl"
							out()<<cppcms::filters::escape(clarification->answer);
							#line 41 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t\t\t</span>\n"
								"\t\t\t\t\t\t\t\t\t\t</div>\n"
								"\t\t\t\t\t\t\t\t\t";
						#line 41 "Template.tmpl"
						}else{
							#line 42 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t\t";
							#line 42 "Template.tmpl"
							if(content.user_signed_in && content.user_name.compare(publication->creator_user_name) == 0) {
								#line 44 "Template.tmpl"
								out()<<"\n"
									"\t\t\t\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_answer_content\">\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t<textarea class=\"pci_clarifications_answer_textarea pci_textarea_small\" id=\"textarea_";
								#line 44 "Template.tmpl"
								out()<<cppcms::filters::escape(clarification->id);
								#line 47 "Template.tmpl"
								out()<<"\">Responder</textarea>\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_button_container\">\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t\t<a href=\"javascript:void(0)\">\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_clarifications_answer_button\" id=\"answer_button_";
								#line 47 "Template.tmpl"
								out()<<cppcms::filters::escape(clarification->id);
								#line 53 "Template.tmpl"
								out()<<"\">\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tResponder\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t\t\t</div>\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t\t</a>\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t</div>\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t<script>\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t\tconfigureClarificationTextarea('textarea_";
								#line 53 "Template.tmpl"
								out()<<cppcms::filters::escape(clarification->id);
								#line 53 "Template.tmpl"
								out()<<"', 'answer_button_";
								#line 53 "Template.tmpl"
								out()<<cppcms::filters::escape(clarification->id);
								#line 53 "Template.tmpl"
								out()<<"', '";
								#line 53 "Template.tmpl"
								out()<<cppcms::filters::escape(clarification->id);
								#line 56 "Template.tmpl"
								out()<<"');\n"
									"\t\t\t\t\t\t\t\t\t\t\t\t</script>\n"
									"\t\t\t\t\t\t\t\t\t\t\t</div>\n"
									"\t\t\t\t\t\t\t\t\t\t";
							#line 56 "Template.tmpl"
							} // endif
							#line 57 "Template.tmpl"
							out()<<"\n"
								"\t\t\t\t\t\t\t\t\t";
						#line 57 "Template.tmpl"
						}
						#line 60 "Template.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t</div>\n"
							"\t  \t\t\t\t\t";
					#line 60 "Template.tmpl"
					} // end of item
					#line 61 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t";
				#line 61 "Template.tmpl"
				 } else {
					#line 63 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\tAún no hay aclaraciones\n"
						"\t\t\t\t\t";
				#line 63 "Template.tmpl"
				} // end of empty
				#line 65 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t</div>\n"
					"\t\t\t";
			#line 65 "Template.tmpl"
			} // endif
			#line 66 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 66 "Template.tmpl"
		} // end of template clarifications
		#line 69 "Template.tmpl"
		virtual void header_bar() {
			#line 73 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_header_bar_main_container\">\n"
				"\t\t\t\t<div id=\"pci_header_bar_central_container\">\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_logo_container\">\n"
				"\t\t\t\t\t\t<a href=\"";
			#line 73 "Template.tmpl"
			content.app().mapper().map(out(),"/");
			#line 78 "Template.tmpl"
			out()<<"\" >\n"
				"\t\t\t\t\t\t\t<div id=\"pci_header_bar_logo\"></div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_sign_container\">\n"
				"\t\t\t\t\t \t";
			#line 78 "Template.tmpl"
			if(content.user_signed_in) {
				#line 79 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a href=\"";
				#line 79 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_out");
				#line 85 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tSalir\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t \t\t<div id=\"pci_header_bar_user_name_container\">\n"
					"\t\t\t\t\t\t\t<a href=\"";
				#line 85 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 87 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t \t\t\t<span id=\"pci_header_bar_user_name\">\n"
					"\t\t\t\t\t \t\t\t\t";
				#line 87 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_first_name);
				#line 87 "Template.tmpl"
				out()<<" ";
				#line 87 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_last_name);
				#line 91 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t \t\t\t</span>\n"
					"\t\t\t\t \t\t\t</a>\n"
					"\t\t\t\t \t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 91 "Template.tmpl"
			}else{
				#line 98 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a href=\"javascript:void(0)\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\" id=\"pci_header_bar_button_sign_in\">\n"
					"\t\t\t\t\t\t\t\t\tIngresar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t\t<div id=\"pci_header_bar_sign_in_container\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 98 "Template.tmpl"
				sign_in_form(content.sign_in_form_info);
				#line 100 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 100 "Template.tmpl"
			}
			#line 104 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 104 "Template.tmpl"
		} // end of template header_bar
		#line 106 "Template.tmpl"
		virtual void information_footer() {
			#line 120 "Template.tmpl"
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
			#line 120 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 125 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAcerca de\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 125 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 130 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tFilosofía\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 130 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 142 "Template.tmpl"
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
			#line 142 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 147 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 147 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 152 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 152 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 164 "Template.tmpl"
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
			#line 164 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 169 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAyuda\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 169 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 174 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCondiciones de servicio\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 174 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 182 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCopyright\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 182 "Template.tmpl"
		} // end of template information_footer
		#line 185 "Template.tmpl"
		virtual void navigation_menu() {
			#line 187 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_navigation_menu_main_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 187 "Template.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 192 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_problems_button\">\n"
				"\t\t\t\t\t\tProblemas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 192 "Template.tmpl"
			content.app().mapper().map(out(),"/ideas");
			#line 197 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_ideas_button\">\n"
				"\t\t\t\t\t\tIdeas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t";
			#line 197 "Template.tmpl"
			if(content.user_signed_in) {
				#line 199 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<div class=\"pci_horizontal_line\" ></div>\n"
					"\t\t\t\t\t<a href=\"";
				#line 199 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 204 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_profile_button\">\n"
					"\t\t\t\t\t\t\tPerfil\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t</a>\n"
					"\t\t\t\t";
			#line 204 "Template.tmpl"
			} // endif
			#line 206 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 206 "Template.tmpl"
		} // end of template navigation_menu
		#line 209 "Template.tmpl"
		virtual void new_problem_form(ViewContent::NewProblemFormInfo &new_problem_form_info) {
			#line 211 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t";
			#line 211 "Template.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (new_problem_form_info).render(_form_context); }
			#line 213 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</form>\n"
				"\t\t";
		#line 213 "Template.tmpl"
		} // end of template new_problem_form
		#line 216 "Template.tmpl"
		virtual void new_solution_form(ViewContent::NewSolutionFormInfo &new_solution_form_info) {
			#line 218 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t";
			#line 218 "Template.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (new_solution_form_info).render(_form_context); }
			#line 220 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</form>\n"
				"\t\t";
		#line 220 "Template.tmpl"
		} // end of template new_solution_form
		#line 223 "Template.tmpl"
		virtual void problem_description(ProblemPointer problem) {
			#line 240 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div class=\"pci_box_container pci_problems_problem_description\">\n"
				"\t\t\t\t<div class=\"row-fluid\">\n"
				"\t\t\t\t\t<div class=\"span2\">\n"
				"\t\t\t\t\t\t<div class=\"row-fluid\"> <!-- Votes & Answers -->\n"
				"\t\t\t\t\t\t\t<div class=\"span6\">\n"
				"\t\t\t\t\t\t\t\t<center>125</center>\n"
				"\t\t\t\t\t\t\t\t<center>Votos</center>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"span6\">\n"
				"\t\t\t\t\t\t\t\t<center>6</center>\n"
				"\t\t\t\t\t\t\t\t<center>Soluciones</center>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div class=\"span9\">\n"
				"\t\t\t\t\t\t<div class=\"row-fluid\">\t\t\t\t\n"
				"\t\t\t\t\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 240 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem->id));
			#line 241 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t";
			#line 241 "Template.tmpl"
			out()<<cppcms::filters::escape(problem->description);
			#line 244 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t\t\t\t\t";
			#line 244 "Template.tmpl"
			if(problem->is_anonymous) {
				#line 246 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t\t<i>Publicado Anónimamente</i>\n"
					"\t\t\t\t\t\t\t\t";
			#line 246 "Template.tmpl"
			}else{
				#line 247 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 247 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(problem->creator_user_name));
				#line 247 "Template.tmpl"
				out()<<"\">";
				#line 247 "Template.tmpl"
				out()<<cppcms::filters::escape(problem->creator_user_name);
				#line 248 "Template.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t\t\t\t\t";
			#line 248 "Template.tmpl"
			}
			#line 249 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t\t- ";
			#line 249 "Template.tmpl"
			out()<<cppcms::filters::escape(problem->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 253 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t</span>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t";
			#line 253 "Template.tmpl"
			if(problem->is_solved) {
				#line 257 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<div class=\"span1\">\n"
					"\t\t\t\t\t\t\t<div class=\"tick_on\"></div>\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t";
			#line 257 "Template.tmpl"
			} // endif
			#line 260 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\t\t\t\t\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 260 "Template.tmpl"
		} // end of template problem_description
		#line 262 "Template.tmpl"
		virtual void publication_description(PublicationPointer publication) {
			#line 263 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 263 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(publication->id));
			#line 264 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t";
			#line 264 "Template.tmpl"
			out()<<cppcms::filters::escape(publication->description);
			#line 267 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t";
			#line 267 "Template.tmpl"
			if(publication->is_anonymous) {
				#line 269 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Publicado Anónimamente</i>\n"
					"\t\t\t\t";
			#line 269 "Template.tmpl"
			}else{
				#line 270 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 270 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(publication->creator_user_name));
				#line 270 "Template.tmpl"
				out()<<"\">";
				#line 270 "Template.tmpl"
				out()<<cppcms::filters::escape(publication->creator_user_name);
				#line 271 "Template.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t";
			#line 271 "Template.tmpl"
			}
			#line 272 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t- ";
			#line 272 "Template.tmpl"
			out()<<cppcms::filters::escape(publication->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 274 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</span>\n"
				"\t\t";
		#line 274 "Template.tmpl"
		} // end of template publication_description
		#line 276 "Template.tmpl"
		virtual void sign_in_form(ViewContent::SignInFormInfo &sign_in_form_info) {
			#line 278 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t";
			#line 278 "Template.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (sign_in_form_info).render(_form_context); }
			#line 280 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</form>\n"
				"\t\t";
		#line 280 "Template.tmpl"
		} // end of template sign_in_form
		#line 283 "Template.tmpl"
		virtual void sign_up_form(ViewContent::SignUpFormInfo &sign_up_form_info) {
			#line 285 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t";
			#line 285 "Template.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (sign_up_form_info).render(_form_context); }
			#line 287 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</form>\n"
				"\t\t";
		#line 287 "Template.tmpl"
		} // end of template sign_up_form
		#line 290 "Template.tmpl"
		virtual void solution_description(ProblemPointer problem,SolutionPointer solution) {
			#line 291 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 291 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem->id), cppcms::filters::urlencode(solution->id));
			#line 292 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t";
			#line 292 "Template.tmpl"
			out()<<cppcms::filters::escape(solution->description);
			#line 295 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t";
			#line 295 "Template.tmpl"
			if(solution->is_anonymous) {
				#line 297 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Publicado Anónimamente</i>\n"
					"\t\t\t\t";
			#line 297 "Template.tmpl"
			}else{
				#line 299 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<i>Por \n"
					"\t\t\t\t\t\t<a class=\"pci_link_user_name\" href=\"";
				#line 299 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(solution->creator_user_name));
				#line 300 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t";
				#line 300 "Template.tmpl"
				out()<<cppcms::filters::escape(solution->creator_user_name);
				#line 303 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t</i>\n"
					"\t\t\t\t";
			#line 303 "Template.tmpl"
			}
			#line 304 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t- ";
			#line 304 "Template.tmpl"
			out()<<cppcms::filters::escape(solution->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 306 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</span>\n"
				"\t\t";
		#line 306 "Template.tmpl"
		} // end of template solution_description
		#line 309 "Template.tmpl"
		virtual void toolbar_problems() {
			#line 311 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problems_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 311 "Template.tmpl"
			content.app().mapper().map(out(),"/new_problem");
			#line 317 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problems_button\" id=\"pci_toolbar_problems_new_problem_button\">\n"
				"\t\t\t\t\t\tNuevo problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 317 "Template.tmpl"
		} // end of template toolbar_problems
		#line 320 "Template.tmpl"
		virtual void toolbar_problem(std::string problem_id) {
			#line 322 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problem_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 322 "Template.tmpl"
			content.app().mapper().map(out(),"/new_solution", cppcms::filters::urlencode(problem_id));
			#line 328 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problem_button\" id=\"pci_toolbar_problem_new_solution_button\">\n"
				"\t\t\t\t\t\tPlantear solución\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 328 "Template.tmpl"
		} // end of template toolbar_problem
		#line 331 "Template.tmpl"
		virtual void toolbar_solution(std::string problem_id) {
			#line 333 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_solution_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 333 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(problem_id));
			#line 339 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_solution_button\" id=\"pci_toolbar_solution_go_back_button\">\n"
				"\t\t\t\t\t\tVolver al problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 339 "Template.tmpl"
		} // end of template toolbar_solution
		#line 342 "Template.tmpl"
		virtual void css_links() {
			#line 346 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/template.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"    \t\t\n"
				"    \t\t<link href=\"/css/bootstrap.min.css\" rel=\"stylesheet\">\n"
				"\t\t";
		#line 346 "Template.tmpl"
		} // end of template css_links
		#line 349 "Template.tmpl"
		virtual void js_links() {
			#line 358 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<script src=\"/js/utilities.js\"></script>\n"
				"\t\t\t<script src=\"/lib/jquery/jquery-1.9.0.min.js\"></script>\n"
				"\t\t\t\n"
				"\t\t\t<!-- HTML5 shim, for IE6-8 support of HTML5 elements -->\n"
				"\t    \t<!--[if lt IE 9]>\n"
				"\t      \t\t<script src=\"http://html5shim.googlecode.com/svn/trunk/html5.js\"></script>\n"
				"\t    \t<![endif]-->\n"
				"    \t\t<script src=\"/js/bootstrap.min.js\"></script>\n"
				"\t\t";
		#line 358 "Template.tmpl"
		} // end of template js_links
		#line 361 "Template.tmpl"
		virtual void javascript_code() {
			#line 369 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\t\t\t\t$(document).ready(function() {\n"
				"\t\t\t\t\tconfigureTextfield('pci_sign_in_textfield_user_name');\n"
				"\t\t\t\t\tconfigurePasswordfield('pci_sign_in_textfield_password');\n"
				"\t\t\t\t\tconfigureSignInFormContainer('pci_header_bar_sign_in_container', 'pci_header_bar_button_sign_in');\n"
				"\t\t\t\t});\n"
				"\t\t\t</script>\n"
				"\t\t";
		#line 369 "Template.tmpl"
		} // end of template javascript_code
		#line 372 "Template.tmpl"
		virtual void page_content() {
			#line 373 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 373 "Template.tmpl"
		} // end of template page_content
		#line 376 "Template.tmpl"
		virtual void render() {
			#line 380 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<!DOCTYPE html>\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 380 "Template.tmpl"
			css_links();
			#line 382 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 382 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 386 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t";
			#line 386 "Template.tmpl"
			page_content();
			#line 387 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t";
			#line 387 "Template.tmpl"
			js_links();
			#line 388 "Template.tmpl"
			out()<<" <!-- Placed here for faster page loading -->\n"
				"\t\t\t\t\t";
			#line 388 "Template.tmpl"
			javascript_code();
			#line 391 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 391 "Template.tmpl"
		} // end of template render
	#line 394 "Template.tmpl"
	}; // end of class template_view
#line 395 "Template.tmpl"
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
			#line 68 "Index.tmpl"
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
			#line 68 "Index.tmpl"
			template_view::sign_up_form(content.sign_up_form_info);
			#line 71 "Index.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 71 "Index.tmpl"
			template_view::information_footer();
			#line 72 "Index.tmpl"
			out()<<"\n"
				"\t\t";
		#line 72 "Index.tmpl"
		} // end of template page_content
	#line 75 "Index.tmpl"
	}; // end of class index_view
#line 76 "Index.tmpl"
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
				"\t\t\t\t\t\t<li><a href=\"#tab2\" data-toggle=\"tab\">Mas votados</a></li>\n"
				"\t\t\t\t\t\t<li><a href=\"#tab3\" data-toggle=\"tab\">Sin solucion</a></li>\n"
				"\t\t\t\t\t</ul>\n"
				"\t\t\t\t\t<div class=\"tab-content\">\n"
				"\t\t\t\t\t\t<div class=\"tab-pane active\" id=\"tab1\">\n"
				"\t\t\t\t\t\t\t";
			#line 39 "Problems.tmpl"
			if((*content.problems).begin()!=(*content.problems).end()) {
				#line 40 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t";
				#line 40 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.problems).begin()) problem_ptr=(*content.problems).begin(),problem_ptr_end=(*content.problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
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
			#line 56 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"tab-pane\" id=\"tab2\">\n"
				"\t\t\t\t\t\t\t<p>Problemas mas votados</p>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"tab-pane\" id=\"tab3\">\n"
				"\t\t\t\t\t\t\t<p>Problemas sin solucion</p>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 56 "Problems.tmpl"
		} // end of template page_content
	#line 59 "Problems.tmpl"
	}; // end of class problems_view
#line 60 "Problems.tmpl"
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
			#line 51 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<script>\n"
				"\n"
				"\t\t\t\t// Toggles elements involved in edition\n"
				"\t\t\t\tfunction toggle(){\n"
				"\t\t\t\t\t$(\"#problem_edit_button\").toggle();\n"
				"\t\t\t\t\t$(\"#pci_problem_problem_content\").toggle();\n"
				"\t\t\t\t\t$(\"#problem_cancel_edit_button\").toggle();\n"
				"\t\t\t\t\t$(\"#problem_finish_edit_button\").toggle();\n"
				"\t\t\t\t\t$(\"#ckeditor_container\").toggle();\t\t\t\t\n"
				"\t\t\t\t}\n"
				"\t\t\t\t\n"
				"\t\t\t\t$(document).ready(function(){\n"
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
		#line 51 "Problem.tmpl"
		} // end of template javascript_code
		#line 53 "Problem.tmpl"
		virtual void page_content() {
			#line 54 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 54 "Problem.tmpl"
			template_view::header_bar();
			#line 55 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 55 "Problem.tmpl"
			template_view::navigation_menu();
			#line 58 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problem_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t";
			#line 58 "Problem.tmpl"
			if(content.user_signed_in) {
				#line 59 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 59 "Problem.tmpl"
				template_view::toolbar_problem(content.problem->id);
				#line 61 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<div class=\"pci_horizontal_line\"></div>\n"
					"\t\t\t\t\t";
			#line 61 "Problem.tmpl"
			} // endif
			#line 69 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<div id=\"pci_problem_header_container\">\n"
				"\t\t\t\t\t\t<a id=\"problem_edit_button\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_classic\">\n"
				"\t\t\t\t\t\t\t\tEditar\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t<h2>\n"
				"\t\t\t\t\t\t\t";
			#line 69 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->description);
			#line 72 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</h2>\n"
				"\t\t\t\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t\t\t\t";
			#line 72 "Problem.tmpl"
			if(content.problem->is_anonymous) {
				#line 74 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t<i>Publicado Anónimamente</i>\n"
					"\t\t\t\t\t\t\t";
			#line 74 "Problem.tmpl"
			}else{
				#line 75 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
				#line 75 "Problem.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.problem->creator_user_name));
				#line 75 "Problem.tmpl"
				out()<<"\">";
				#line 75 "Problem.tmpl"
				out()<<cppcms::filters::escape(content.problem->creator_user_name);
				#line 76 "Problem.tmpl"
				out()<<"</a></i>\n"
					"\t\t\t\t\t\t\t";
			#line 76 "Problem.tmpl"
			}
			#line 77 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t\t- ";
			#line 77 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 95 "Problem.tmpl"
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
			#line 95 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->content);
			#line 99 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_problem_solution_container\">\n"
				"\t\t\t\t\t\t";
			#line 99 "Problem.tmpl"
			if(content.problem->is_solved) {
				#line 101 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problem_solution_description\" style=\"background-color:#ABFFAB;\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 101 "Problem.tmpl"
				template_view::solution_description(content.problem,content.accepted_solution);
				#line 103 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 103 "Problem.tmpl"
			} // endif
			#line 104 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t";
			#line 104 "Problem.tmpl"
			if((*content.solutions).begin()!=(*content.solutions).end()) {
				#line 105 "Problem.tmpl"
				out()<<"\n"
					"\t\t \t\t\t\t\t";
				#line 105 "Problem.tmpl"
				for(CPPCMS_TYPEOF((*content.solutions).begin()) solution_ptr=(*content.solutions).begin(),solution_ptr_end=(*content.solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 105 "Problem.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 106 "Problem.tmpl"
					out()<<"\n"
						"\t\t \t\t\t\t\t\t";
					#line 106 "Problem.tmpl"
					if(!content.problem->is_solved || solution->id.compare(content.accepted_solution->id) != 0) {
						#line 108 "Problem.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problem_solution_description\">\n"
							"\t\t\t\t\t\t\t\t\t\t";
						#line 108 "Problem.tmpl"
						template_view::solution_description(content.problem,solution);
						#line 110 "Problem.tmpl"
						out()<<"\n"
							"\t\t\t\t\t\t\t\t\t</div>\n"
							"\t\t\t\t\t\t\t\t";
					#line 110 "Problem.tmpl"
					} // endif
					#line 111 "Problem.tmpl"
					out()<<"\n"
						"\t\t  \t\t\t\t\t";
				#line 111 "Problem.tmpl"
				} // end of item
				#line 112 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
			#line 112 "Problem.tmpl"
			}
			#line 114 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t";
			#line 114 "Problem.tmpl"
			template_view::clarifications(content.clarifications,content.problem);
			#line 117 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 117 "Problem.tmpl"
		} // end of template page_content
	#line 120 "Problem.tmpl"
	}; // end of class problem_view
#line 121 "Problem.tmpl"
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
			template_view::new_problem_form(content.new_problem_form_info);
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
				"\t\t\t\t\t\t\t\t<div class=\"row-fluid\">\t\t\t\t\t\t\t\t\n"
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
			template_view::clarifications(content.clarifications,content.solution);
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
			template_view::new_solution_form(content.new_solution_form_info);
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
