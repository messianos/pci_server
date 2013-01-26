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
			#line 23 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_clarifications_main_container\">\n"
				"\t\t\t\t<div class=\"pci_horizontal_line\"></div>\n"
				"\t\t\t\t<div class=\"pci_clarifications_row_container\">\n"
				"\t\t\t\t\t<div class=\"pci_clarifications_question_container\">\n"
				"\t\t\t\t\t\t<div class=\"pci_clarifications_column_header pci_clarifications_question_content\">\n"
				"\t\t\t\t\t\t\tPregunta\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
				"\t\t\t\t\t\t<div class=\"pci_clarifications_answer_content pci_clarifications_column_header\">\n"
				"\t\t\t\t\t\t\tRespuesta\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t";
			#line 23 "Template.tmpl"
			if((*clarifications).begin()!=(*clarifications).end()) {
				#line 24 "Template.tmpl"
				out()<<"\n"
					" \t\t\t\t\t";
				#line 24 "Template.tmpl"
				for(CPPCMS_TYPEOF((*clarifications).begin()) clarification_ptr=(*clarifications).begin(),clarification_ptr_end=(*clarifications).end();clarification_ptr!=clarification_ptr_end;++clarification_ptr) {
				#line 24 "Template.tmpl"
				CPPCMS_TYPEOF(*clarification_ptr) &clarification=*clarification_ptr;
					#line 28 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t<div class=\"pci_clarifications_row_container\">\n"
						"\t\t\t\t\t\t\t<div class=\"pci_clarifications_question_container\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_3 pci_clarifications_question_content\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 28 "Template.tmpl"
					out()<<cppcms::filters::escape(clarification->question);
					#line 33 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_5 pci_clarifications_answer_content\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 33 "Template.tmpl"
					out()<<cppcms::filters::escape(clarification->answer);
					#line 37 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t</div>\n"
						"  \t\t\t\t\t";
				#line 37 "Template.tmpl"
				} // end of item
				#line 38 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t";
			#line 38 "Template.tmpl"
			 } else {
				#line 40 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\tAún no hay aclaraciones\n"
					"\t\t\t\t";
			#line 40 "Template.tmpl"
			} // end of empty
			#line 42 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 42 "Template.tmpl"
		} // end of template clarifications
		#line 45 "Template.tmpl"
		virtual void header_bar() {
			#line 52 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_header_bar_main_container\">\n"
				"\t\t\t\t<div id=\"pci_header_bar_central_container\">\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_logo_container\">\n"
				"\t\t\t\t\t\t<div id=\"pci_header_bar_logo\"></div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_button_container\">\n"
				"\t\t\t\t\t \t";
			#line 52 "Template.tmpl"
			if(content.user_signed_in) {
				#line 53 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a class=\"pci_button_0\" href=\"";
				#line 53 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_out");
				#line 60 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_0 pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tSalir\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t \t\t<div id=\"pci_header_bar_user_name_container\">\n"
					"\t\t\t\t\t \t\t\t<span id=\"pci_header_bar_user_name\">\n"
					"\t\t\t\t\t \t\t\t\t";
				#line 60 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_first_name);
				#line 60 "Template.tmpl"
				out()<<" ";
				#line 60 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_last_name);
				#line 63 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t \t\t\t</span>\n"
					"\t\t\t\t \t\t\t</div>\n"
					"\t\t\t\t\t\t";
			#line 63 "Template.tmpl"
			}else{
				#line 64 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a class=\"pci_button_0\" href=\"";
				#line 64 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_in");
				#line 69 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_0 pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tIngresar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t\t<a class=\"pci_button_0\" href=\"";
				#line 69 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_up");
				#line 74 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_0 pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tRegistrar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t";
			#line 74 "Template.tmpl"
			}
			#line 78 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 78 "Template.tmpl"
		} // end of template header_bar
		#line 81 "Template.tmpl"
		virtual void information_footer() {
			#line 93 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_information_footer_main_container\">\n"
				"\t\t\t\t<div id=\"pci_information_footer_central_container\">\n"
				"\t\t\t\t\t<div id=\"pci_information_footer_TO_DEFINE_container\">\n"
				"\t\t\t\t\t\tSome information\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_information_footer_link_container\">\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tPCI\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 93 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 98 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAcerca de\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 98 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 103 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 103 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 113 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tHeader 2\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 113 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 118 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 118 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 123 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 123 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 133 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tHeader 3\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 133 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 138 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 138 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 143 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 143 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 153 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tSoporte\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 153 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 158 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tAyuda\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 158 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 163 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCondiciones de servicio\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 163 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 171 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tCopyright\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 171 "Template.tmpl"
		} // end of template information_footer
		#line 174 "Template.tmpl"
		virtual void navigation_menu() {
			#line 176 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_navigation_menu_main_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 176 "Template.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 181 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_button\" id=\"pci_navigation_menu_problems_button\">\n"
				"\t\t\t\t\t\tProblemas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 181 "Template.tmpl"
			content.app().mapper().map(out(),"/ideas");
			#line 186 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_button\" id=\"pci_navigation_menu_ideas_button\">\n"
				"\t\t\t\t\t\tIdeas\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t";
			#line 186 "Template.tmpl"
			if(content.user_signed_in) {
				#line 187 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t<a href=\"";
				#line 187 "Template.tmpl"
				content.app().mapper().map(out(),"/user", cppcms::filters::urlencode(content.user_name));
				#line 192 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_button\" id=\"pci_navigation_menu_profile_button\">\n"
					"\t\t\t\t\t\t\tPerfil\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t</a>\n"
					"\t\t\t\t";
			#line 192 "Template.tmpl"
			} // endif
			#line 194 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 194 "Template.tmpl"
		} // end of template navigation_menu
		#line 197 "Template.tmpl"
		virtual void toolbar() {
			#line 198 "Template.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 198 "Template.tmpl"
			if(content.user_signed_in) {
				#line 200 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t<div class=\"pci_box_7 pci_toolbar_main_container\">\n"
					"\t\t\t\t\t<a href=\"";
				#line 200 "Template.tmpl"
				content.app().mapper().map(out(),"/new_problem");
				#line 206 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t<div class=\"pci_button_2 pci_toolbar_button\" id=\"pci_toolbar_new_problem_button\">\n"
					"\t\t\t\t\t\t\tNuevo problema\n"
					"\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t</a>\n"
					"\t\t\t\t</div>\n"
					"\t\t\t";
			#line 206 "Template.tmpl"
			} // endif
			#line 207 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 207 "Template.tmpl"
		} // end of template toolbar
		#line 210 "Template.tmpl"
		virtual void css_links() {
			#line 212 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/template.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 212 "Template.tmpl"
		} // end of template css_links
		#line 215 "Template.tmpl"
		virtual void javascript_code() {
			#line 216 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 216 "Template.tmpl"
		} // end of template javascript_code
		#line 219 "Template.tmpl"
		virtual void page_content() {
			#line 220 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 220 "Template.tmpl"
		} // end of template page_content
		#line 223 "Template.tmpl"
		virtual void render() {
			#line 227 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<!DOCTYPE html>\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 227 "Template.tmpl"
			css_links();
			#line 230 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t<script src=\"/js/jquery-1.9.0.min.js\"></script>\n"
				"\t\t\t\t\t<script>\n"
				"\t\t\t\t\t\t";
			#line 230 "Template.tmpl"
			javascript_code();
			#line 233 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</script>\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 233 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 237 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t";
			#line 237 "Template.tmpl"
			page_content();
			#line 240 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 240 "Template.tmpl"
		} // end of template render
	#line 243 "Template.tmpl"
	}; // end of class template_view
#line 244 "Template.tmpl"
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
			#line 26 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_index_main_container\">\n"
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
			#line 26 "Index.tmpl"
			template_view::information_footer();
			#line 27 "Index.tmpl"
			out()<<"\n"
				"\t\t";
		#line 27 "Index.tmpl"
		} // end of template page_content
	#line 30 "Index.tmpl"
	}; // end of class index_view
#line 31 "Index.tmpl"
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
				"\t\t\t\t<div class=\"pci_box_9\">\n"
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
		#line 28 "SignIn.tmpl"
		virtual void render_input() {
			#line 30 "SignIn.tmpl"
			out()<<"\n"
				"\t\n"
				"\t\t";
		#line 30 "SignIn.tmpl"
		} // end of template render_input
	#line 32 "SignIn.tmpl"
	}; // end of class sign_in_view
#line 33 "SignIn.tmpl"
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
		#line 14 "SignUp.tmpl"
		virtual void page_content() {
			#line 15 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "SignUp.tmpl"
			template_view::header_bar();
			#line 16 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "SignUp.tmpl"
			template_view::navigation_menu();
			#line 21 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_sign_up_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_9\">\n"
				"\t\t\t\t\t<h1>Registrar</h1>\n"
				"\t\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t\t";
			#line 21 "SignUp.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 25 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</form>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 25 "SignUp.tmpl"
		} // end of template page_content
	#line 28 "SignUp.tmpl"
	}; // end of class sign_up_view
#line 29 "SignUp.tmpl"
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
			#line 25 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problems_main_container\">\n"
				"\t\t\t\t";
			#line 25 "Problems.tmpl"
			template_view::toolbar();
			#line 27 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t<div class=\"pci_box_2\" id=\"pci_problems_problem_container\">\n"
				"\t\t\t\t\t";
			#line 27 "Problems.tmpl"
			if((*content.problems).begin()!=(*content.problems).end()) {
				#line 28 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 28 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.problems).begin()) problem_ptr=(*content.problems).begin(),problem_ptr_end=(*content.problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 28 "Problems.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 29 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t<a class=\"pci_box_1\" href=\"";
					#line 29 "Problems.tmpl"
					content.app().mapper().map(out(),"/problem", cppcms::filters::urlencode(problem->id));
					#line 31 "Problems.tmpl"
					out()<<"\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_1 pci_problems_problem_description\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 31 "Problems.tmpl"
					out()<<cppcms::filters::escape(problem->description);
					#line 31 "Problems.tmpl"
					out()<<"<br />";
					#line 31 "Problems.tmpl"
					out()<<cppcms::filters::escape(problem->creation_datetime->toString("%d/%m/%Y %H:%M:%S"));
					#line 34 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</a>\n"
						"\t\t\t\t\t\t";
				#line 34 "Problems.tmpl"
				} // end of item
				#line 35 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 35 "Problems.tmpl"
			 } else {
				#line 37 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\tNo se encontraron problemas\n"
					"\t\t\t\t\t";
			#line 37 "Problems.tmpl"
			} // end of empty
			#line 40 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 40 "Problems.tmpl"
		} // end of template page_content
	#line 43 "Problems.tmpl"
	}; // end of class problems_view
#line 44 "Problems.tmpl"
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
			#line 20 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problem_main_container\">\n"
				"\t\t\t\t<div id=\"pci_problem_header_container\">\n"
				"\t\t\t\t\t<h2>\n"
				"\t\t\t\t\t\t";
			#line 20 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->description);
			#line 25 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</h2>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t<div id=\"pci_problem_problem_container\">\n"
				"\t\t\t\t\t<div class=\"pci_box_0\" id=\"pci_problem_problem_content\">\n"
				"\t\t\t\t\t\t";
			#line 25 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->content);
			#line 29 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t<div id=\"pci_problem_solution_container\">\n"
				"\t\t\t\t\t";
			#line 29 "Problem.tmpl"
			if(content.problem->is_solved) {
				#line 30 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<a class=\"pci_box_6\" href=\"";
				#line 30 "Problem.tmpl"
				content.app().mapper().map(out(),"/solution", cppcms::filters::urlencode(content.accepted_solution->id));
				#line 32 "Problem.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t<div class=\"pci_box_6 pci_problem_solution_description\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 32 "Problem.tmpl"
				out()<<cppcms::filters::escape(content.accepted_solution->description);
				#line 35 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t";
			#line 35 "Problem.tmpl"
			} // endif
			#line 36 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t";
			#line 36 "Problem.tmpl"
			if(content.user_signed_in) {
				#line 37 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<a href=\"";
				#line 37 "Problem.tmpl"
				content.app().mapper().map(out(),"/new_solution", cppcms::filters::urlencode(content.problem->id));
				#line 44 "Problem.tmpl"
				out()<<"\" >\n"
					"\t\t\t\t\t\t\t<div class=\"pci_box_7\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_2\" >\n"
					"\t\t\t\t\t\t\t\t\tPlantear solucion\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t";
			#line 44 "Problem.tmpl"
			} // endif
			#line 45 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t";
			#line 45 "Problem.tmpl"
			if((*content.solutions).begin()!=(*content.solutions).end()) {
				#line 46 "Problem.tmpl"
				out()<<"\n"
					"\t \t\t\t\t\t";
				#line 46 "Problem.tmpl"
				for(CPPCMS_TYPEOF((*content.solutions).begin()) solution_ptr=(*content.solutions).begin(),solution_ptr_end=(*content.solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 46 "Problem.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 47 "Problem.tmpl"
					out()<<"\n"
						"\t \t\t\t\t\t\t<a class=\"pci_box_4\" href=\"";
					#line 47 "Problem.tmpl"
					content.app().mapper().map(out(),"/solution", cppcms::filters::urlencode(solution->id));
					#line 49 "Problem.tmpl"
					out()<<"\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_4 pci_problem_solution_description\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 49 "Problem.tmpl"
					out()<<cppcms::filters::escape(solution->description);
					#line 52 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</a>\n"
						"\t  \t\t\t\t\t";
				#line 52 "Problem.tmpl"
				} // end of item
				#line 53 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 53 "Problem.tmpl"
			 } else {
				#line 55 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\tAún no hay soluciones\n"
					"\t\t\t\t\t";
			#line 55 "Problem.tmpl"
			} // end of empty
			#line 58 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 58 "Problem.tmpl"
			template_view::clarifications(content.clarifications);
			#line 59 "Problem.tmpl"
			out()<<"\n"
				"\t\t";
		#line 59 "Problem.tmpl"
		} // end of template page_content
	#line 62 "Problem.tmpl"
	}; // end of class problem_view
#line 63 "Problem.tmpl"
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
			#line 19 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_new_problem_main_container\">\n"
				"\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t";
			#line 19 "NewProblem.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 22 "NewProblem.tmpl"
			out()<<"\n"
				"\t\t\t\t</form>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 22 "NewProblem.tmpl"
		} // end of template page_content
	#line 25 "NewProblem.tmpl"
	}; // end of class new_problem_view
#line 26 "NewProblem.tmpl"
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
				"\t\t\t\t<div class=\"pci_box_8\">\n"
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
				"\t\t\t\t<div class=\"pci_box_0\">\n"
				"\t\t\t\t\t";
			#line 19 "Solution.tmpl"
			out()<<cppcms::filters::escape(content.solution->content);
			#line 22 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 22 "Solution.tmpl"
			template_view::clarifications(content.clarifications);
			#line 23 "Solution.tmpl"
			out()<<"\n"
				"\t\t";
		#line 23 "Solution.tmpl"
		} // end of template page_content
	#line 26 "Solution.tmpl"
	}; // end of class solution_view
#line 27 "Solution.tmpl"
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
			#line 15 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t\n"
				"\t\t\t// TODO: make css if distinct from new problem\n"
				"\t\t\t<!-- <link href=\"/css/new_solution.css\" rel=\"stylesheet\" type=\"text/css\" /> -->\n"
				"\t\t\t\n"
				"\t\t\t<link href=\"/css/new_problem.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 15 "NewSolution.tmpl"
		} // end of template css_links
		#line 18 "NewSolution.tmpl"
		virtual void page_content() {
			#line 19 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 19 "NewSolution.tmpl"
			template_view::header_bar();
			#line 20 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 20 "NewSolution.tmpl"
			template_view::navigation_menu();
			#line 23 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_new_problem_main_container\">\n"
				"\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t";
			#line 23 "NewSolution.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 26 "NewSolution.tmpl"
			out()<<"\n"
				"\t\t\t\t</form>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 26 "NewSolution.tmpl"
		} // end of template page_content
	#line 29 "NewSolution.tmpl"
	}; // end of class new_solution_view
#line 30 "NewSolution.tmpl"
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
				"\t\t\t\t<div class=\"pci_box_9\">\n"
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
