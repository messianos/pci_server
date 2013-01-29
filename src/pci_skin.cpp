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
				#line 71 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<div id=\"pci_sign_in_floating_form\"></div>\n"
					"\t\t\t\t\t\t\t<!-- onclick=\"javascript:show_sign_in_form()\" > --><a href=\"";
				#line 71 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_in");
				#line 76 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\" id=\"pci_header_bar_button_sign_in\">\n"
					"\t\t\t\t\t\t\t\t\tIngresar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t\t<a href=\"";
				#line 76 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_up");
				#line 81 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_classic pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tRegistrar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t";
			#line 81 "Template.tmpl"
			}
			#line 85 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 85 "Template.tmpl"
		} // end of template header_bar
		#line 88 "Template.tmpl"
		virtual void information_footer() {
			#line 102 "Template.tmpl"
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
			#line 102 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 107 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAcerca de\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 107 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 112 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tFilosofía\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 112 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 124 "Template.tmpl"
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
			#line 124 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 129 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 129 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 134 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 134 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 146 "Template.tmpl"
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
			#line 146 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 151 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAyuda\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 151 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 156 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCondiciones de servicio\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_footer\" href=\"";
			#line 156 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 164 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCopyright\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 164 "Template.tmpl"
		} // end of template information_footer
		#line 167 "Template.tmpl"
		virtual void navigation_menu() {
			#line 169 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_navigation_menu_main_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 169 "Template.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 174 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_problems_button\">\n"
				"\t\t\t\t\t\tProblemas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 174 "Template.tmpl"
			content.app().mapper().map(out(),"/ideas");
			#line 179 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_ideas_button\">\n"
				"\t\t\t\t\t\tIdeas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t";
			#line 179 "Template.tmpl"
			if(content.user_signed_in) {
				#line 181 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<div class=\"pci_horizontal_line\" ></div>\n"
					"\t\t\t\t\t<a href=\"";
				#line 181 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 186 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t<div class=\"pci_button_square pci_navigation_menu_button\" id=\"pci_navigation_menu_profile_button\">\n"
					"\t\t\t\t\t\t\tPerfil\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t</a>\n"
					"\t\t\t\t";
			#line 186 "Template.tmpl"
			} // endif
			#line 188 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 188 "Template.tmpl"
		} // end of template navigation_menu
		#line 191 "Template.tmpl"
		virtual void publication_description(PublicationPointer publication) {
			#line 192 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<a class=\"pci_link_description\" href=\"";
			#line 192 "Template.tmpl"
			content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(publication->id));
			#line 193 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t";
			#line 193 "Template.tmpl"
			out()<<cppcms::filters::escape(publication->description);
			#line 196 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</a>\n"
				"\t\t\t<span class=\"pci_text_description\">\n"
				"\t\t\t\t<i>Por <a class=\"pci_link_user_name\" href=\"";
			#line 196 "Template.tmpl"
			content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(publication->creator_user_name));
			#line 196 "Template.tmpl"
			out()<<"\">";
			#line 196 "Template.tmpl"
			out()<<cppcms::filters::escape(publication->creator_user_name);
			#line 197 "Template.tmpl"
			out()<<"</a></i>\n"
				"\t\t\t\t- ";
			#line 197 "Template.tmpl"
			out()<<cppcms::filters::escape(publication->creation_datetime->toString("%d/%m/%Y a las %H:%M hs."));
			#line 199 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</span>\n"
				"\t\t";
		#line 199 "Template.tmpl"
		} // end of template publication_description
		#line 202 "Template.tmpl"
		virtual void toolbar_problems() {
			#line 204 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problems_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 204 "Template.tmpl"
			content.app().mapper().map(out(),"/new_problem");
			#line 210 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problems_button\" id=\"pci_toolbar_problems_new_problem_button\">\n"
				"\t\t\t\t\t\tNuevo problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 210 "Template.tmpl"
		} // end of template toolbar_problems
		#line 213 "Template.tmpl"
		virtual void toolbar_problem(std::string problem_id) {
			#line 215 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_problem_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 215 "Template.tmpl"
			content.app().mapper().map(out(),"/new_solution", cppcms::filters::urlencode(problem_id));
			#line 221 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_problem_button\" id=\"pci_toolbar_problem_new_solution_button\">\n"
				"\t\t\t\t\t\tPlantear solución\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 221 "Template.tmpl"
		} // end of template toolbar_problem
		#line 224 "Template.tmpl"
		virtual void toolbar_solution() {
			#line 226 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_toolbar_solution_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 226 "Template.tmpl"
			content.app().mapper().map(out(),"/publication");
			#line 232 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_icon pci_toolbar_solution_button\" id=\"pci_toolbar_solution_go_back_button\">\n"
				"\t\t\t\t\t\tVolver al problema\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 232 "Template.tmpl"
		} // end of template toolbar_solution
		#line 235 "Template.tmpl"
		virtual void css_links() {
			#line 238 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/template.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/ui-lightness/jquery-ui-1.9.2.custom.css\" rel=\"stylesheet\">\n"
				"\t\t";
		#line 238 "Template.tmpl"
		} // end of template css_links
		#line 241 "Template.tmpl"
		virtual void javascript_code() {
			#line 246 "Template.tmpl"
			out()<<"\n"
				"\t\t\tfunction show_sign_in_form(){\n"
				"\t\t\t\t$(\"#pci_sign_in_floating_form\").toggle(300);\n"
				"\t\t\t\t$(\"#pci_header_bar_button_sign_in\").toggleClass('floating_form_visible');\n"
				"\t\t\t}\n"
				"\t\t";
		#line 246 "Template.tmpl"
		} // end of template javascript_code
		#line 249 "Template.tmpl"
		virtual void page_content() {
			#line 250 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 250 "Template.tmpl"
		} // end of template page_content
		#line 253 "Template.tmpl"
		virtual void render() {
			#line 257 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<!DOCTYPE html>\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 257 "Template.tmpl"
			css_links();
			#line 261 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<script src=\"/js/jquery-1.9.0.min.js\"></script>\n"
				"\t\t\t\t\t<script src=\"/js/jquery-ui-1.9.2.custom.js\"></script>\n"
				"\t\t\t\t\t<script>\n"
				"\t\t\t\t\t\t";
			#line 261 "Template.tmpl"
			javascript_code();
			#line 264 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</script>\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 264 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 268 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t";
			#line 268 "Template.tmpl"
			page_content();
			#line 271 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 271 "Template.tmpl"
		} // end of template render
	#line 274 "Template.tmpl"
	}; // end of class template_view
#line 275 "Template.tmpl"
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
		#line 14 "SignIn.tmpl"
		virtual void page_content() {
			#line 15 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "SignIn.tmpl"
			template_view::header_bar();
			#line 16 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "SignIn.tmpl"
			template_view::navigation_menu();
			#line 21 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_sign_in_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<h1>Ingrese sus datos</h1>\n"
				"\t\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t\t";
			#line 21 "SignIn.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 25 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</form>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 25 "SignIn.tmpl"
		} // end of template page_content
	#line 27 "SignIn.tmpl"
	}; // end of class sign_in_view
#line 28 "SignIn.tmpl"
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
			#line 25 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t$(function() {\n"
				"\t\t\t\t$(\"#datepicker\").datepicker({\n"
				"\t\t\t\t    showOn: \"both\",\n"
				"\t\t\t    \tbuttonImage: \"/css/ui-lightness/images/calendar.gif\",\n"
				"\t\t\t    \tbuttonImageOnly: true,\n"
				"\t\t\t    \tyearRange: '1920:2010',\n"
				"\t\t\t    \tdateFormat: 'dd-mm-yy',\n"
				"\t\t\t    \tchangeMonth: true,\n"
				"\t\t\t    \tchangeYear: true\n"
				"\t\t\t\t});\n"
				"\t\t\t});\n"
				"\t\t";
		#line 25 "SignUp.tmpl"
		} // end of template javascript_code
		#line 27 "SignUp.tmpl"
		virtual void page_content() {
			#line 28 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 28 "SignUp.tmpl"
			template_view::header_bar();
			#line 29 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 29 "SignUp.tmpl"
			template_view::navigation_menu();
			#line 34 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_sign_up_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<h1>Registrar</h1>\n"
				"\t\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t\t";
			#line 34 "SignUp.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 38 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</form>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 38 "SignUp.tmpl"
		} // end of template page_content
	#line 41 "SignUp.tmpl"
	}; // end of class sign_up_view
#line 42 "SignUp.tmpl"
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
					template_view::publication_description(problem);
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
				#line 35 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a href=\"";
				#line 35 "Problem.tmpl"
				content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(content.accepted_solution->id));
				#line 37 "Problem.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problem_solution_description\">\n"
					"\t\t\t\t\t\t\t\t\t";
				#line 37 "Problem.tmpl"
				template_view::publication_description(content.accepted_solution);
				#line 40 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t";
			#line 40 "Problem.tmpl"
			} // endif
			#line 41 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\t";
			#line 41 "Problem.tmpl"
			if((*content.solutions).begin()!=(*content.solutions).end()) {
				#line 42 "Problem.tmpl"
				out()<<"\n"
					"\t\t \t\t\t\t\t";
				#line 42 "Problem.tmpl"
				for(CPPCMS_TYPEOF((*content.solutions).begin()) solution_ptr=(*content.solutions).begin(),solution_ptr_end=(*content.solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 42 "Problem.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 43 "Problem.tmpl"
					out()<<"\n"
						"\t\t \t\t\t\t\t\t<a href=\"";
					#line 43 "Problem.tmpl"
					content.app().mapper().map(out(),"/publication", cppcms::filters::urlencode(solution->id));
					#line 45 "Problem.tmpl"
					out()<<"\">\n"
						"\t\t\t\t\t\t\t\t\t<div class=\"pci_box_description pci_problem_solution_description\">\n"
						"\t\t\t\t\t\t\t\t\t\t";
					#line 45 "Problem.tmpl"
					template_view::publication_description(solution);
					#line 48 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t\t</a>\n"
						"\t\t  \t\t\t\t\t";
				#line 48 "Problem.tmpl"
				} // end of item
				#line 49 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
			#line 49 "Problem.tmpl"
			}
			#line 51 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t";
			#line 51 "Problem.tmpl"
			template_view::clarifications(content.clarifications);
			#line 54 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 54 "Problem.tmpl"
		} // end of template page_content
	#line 57 "Problem.tmpl"
	}; // end of class problem_view
#line 58 "Problem.tmpl"
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
		virtual void page_content() {
			#line 15 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "NewProblem.tmpl"
			template_view::header_bar();
			#line 16 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "NewProblem.tmpl"
			template_view::navigation_menu();
			#line 20 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_new_problem_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t\t";
			#line 20 "NewProblem.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 24 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</form>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 24 "NewProblem.tmpl"
		} // end of template page_content
	#line 27 "NewProblem.tmpl"
	}; // end of class new_problem_view
#line 28 "NewProblem.tmpl"
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
			#line 26 "User.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_user_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_container\">\n"
				"\t\t\t\t\tNombre de usuario: ";
			#line 26 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->user_name);
			#line 27 "User.tmpl"
			out()<<"<br />\n"
				"\t\t\t\t\tNombre: ";
			#line 27 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->first_name);
			#line 28 "User.tmpl"
			out()<<"<br />\n"
				"\t\t\t\t\tApellido: ";
			#line 28 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->last_name);
			#line 29 "User.tmpl"
			out()<<"<br />\n"
				"\t\t\t\t\tSexo: ";
			#line 29 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->genre);
			#line 30 "User.tmpl"
			out()<<"<br />\n"
				"\t\t\t\t\tFecha de nacimiento: ";
			#line 30 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->birth_date->toString("%d/%m/%Y"));
			#line 31 "User.tmpl"
			out()<<"<br />\n"
				"\t\t\t\t\tE-mail: ";
			#line 31 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->email);
			#line 32 "User.tmpl"
			out()<<"<br />\n"
				"\t\t\t\t\tFecha de registro: ";
			#line 32 "User.tmpl"
			out()<<cppcms::filters::escape(content.user->sign_up_datetime->toString("%d/%m/%Y %H:%M:%S"));
			#line 35 "User.tmpl"
			out()<<"<br />\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 35 "User.tmpl"
		} // end of template page_content
	#line 38 "User.tmpl"
	}; // end of class user_view
#line 39 "User.tmpl"
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
			template_view::toolbar_solution();
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
