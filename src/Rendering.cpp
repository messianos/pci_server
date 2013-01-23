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
				"\t\t\t\t\t\t\tQuestion\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
				"\t\t\t\t\t\t<div class=\"pci_clarifications_answer_content pci_clarifications_column_header\">\n"
				"\t\t\t\t\t\t\tAnswer\n"
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
					"\t\t\t\t\tThere are are no clarifications\n"
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
				"\t\t\t\t\t\t<a class=\"pci_button_0\" href=\"";
			#line 52 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 60 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_0 pci_header_bar_button\">\n"
				"\t\t\t\t\t\t\t\tIngresar\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 60 "Template.tmpl"
		} // end of template header_bar
		#line 63 "Template.tmpl"
		virtual void information_footer() {
			#line 75 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_information_footer_main_container\">\n"
				"\t\t\t\t<div id=\"pci_information_footer_central_container\">\n"
				"\t\t\t\t\t<div id=\"pci_information_footer_TO_DEFINE_container\">\n"
				"\t\t\t\t\t\tSome information\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_information_footer_link_container\">\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tHeader 1\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 75 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 80 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 80 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 85 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 85 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 95 "Template.tmpl"
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
			#line 95 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 100 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 100 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 105 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 105 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 115 "Template.tmpl"
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
			#line 115 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 120 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 120 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 125 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 125 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 135 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tHeader 4\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 135 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 140 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 140 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 145 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 145 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 153 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 153 "Template.tmpl"
		} // end of template information_footer
		#line 156 "Template.tmpl"
		virtual void navigation_menu() {
			#line 158 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_navigation_menu_main_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 158 "Template.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 166 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_button\" id=\"pci_navigation_menu_problems_button\">\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_image\" id=\"pci_navigation_menu_problems_button_image\"></div>\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_text\">\n"
				"\t\t\t\t\t\t\tProblems\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 166 "Template.tmpl"
			content.app().mapper().map(out(),"/ideas");
			#line 174 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_button\" id=\"pci_navigation_menu_ideas_button\">\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_image\" id=\"pci_navigation_menu_ideas_button_image\"></div>\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_text\">\n"
				"\t\t\t\t\t\t\tIdeas\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 174 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 183 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_button\" id=\"pci_navigation_menu_profile_button\">\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_image\" id=\"pci_navigation_menu_profile_button_image\"></div>\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_text\">\n"
				"\t\t\t\t\t\t\tProfile\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 183 "Template.tmpl"
		} // end of template navigation_menu
		#line 186 "Template.tmpl"
		virtual void css_links() {
			#line 189 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/elements.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/global.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 189 "Template.tmpl"
		} // end of template css_links
		#line 192 "Template.tmpl"
		virtual void page_content() {
			#line 193 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 193 "Template.tmpl"
		} // end of template page_content
		#line 196 "Template.tmpl"
		virtual void render() {
			#line 201 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<!DOCTYPE html>\n"
				"\t\t\t\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 201 "Template.tmpl"
			css_links();
			#line 204 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 204 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 209 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t";
			#line 209 "Template.tmpl"
			page_content();
			#line 212 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 212 "Template.tmpl"
		} // end of template render
	#line 215 "Template.tmpl"
	}; // end of class template_view
#line 216 "Template.tmpl"
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
			#line 13 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/header_bar.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/index.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/information_footer.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 13 "Index.tmpl"
		} // end of template css_links
		#line 16 "Index.tmpl"
		virtual void page_content() {
			#line 17 "Index.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 17 "Index.tmpl"
			template_view::header_bar();
			#line 27 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_index_main_container\">\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\tIndex content\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\t<br />\n"
				"\t\t\t\t<br />\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 27 "Index.tmpl"
			template_view::information_footer();
			#line 28 "Index.tmpl"
			out()<<"\n"
				"\t\t";
		#line 28 "Index.tmpl"
		} // end of template page_content
	#line 31 "Index.tmpl"
	}; // end of class index_view
#line 32 "Index.tmpl"
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
			#line 19 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t<h1>Sign in</h1>\n"
				"\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t";
			#line 19 "SignIn.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 21 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t</form>\n"
				"\t\t";
		#line 21 "SignIn.tmpl"
		} // end of template page_content
		#line 24 "SignIn.tmpl"
		virtual void render_input() {
			#line 26 "SignIn.tmpl"
			out()<<"\n"
				"\t\n"
				"\t\t";
		#line 26 "SignIn.tmpl"
		} // end of template render_input
	#line 28 "SignIn.tmpl"
	}; // end of class sign_in_view
#line 29 "SignIn.tmpl"
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
			#line 13 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/header_bar.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/navigation_menu.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/problems.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 13 "Problems.tmpl"
		} // end of template css_links
		#line 16 "Problems.tmpl"
		virtual void page_content() {
			#line 17 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 17 "Problems.tmpl"
			template_view::header_bar();
			#line 18 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 18 "Problems.tmpl"
			template_view::navigation_menu();
			#line 21 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problems_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_2\" id=\"pci_problems_problem_container\">\n"
				"\t\t\t\t\t";
			#line 21 "Problems.tmpl"
			if((*content.problems).begin()!=(*content.problems).end()) {
				#line 22 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 22 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.problems).begin()) problem_ptr=(*content.problems).begin(),problem_ptr_end=(*content.problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 22 "Problems.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 23 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t<a class=\"pci_box_1\" href=\"";
					#line 23 "Problems.tmpl"
					content.app().mapper().map(out(),"/problem", cppcms::filters::urlencode(problem->id));
					#line 25 "Problems.tmpl"
					out()<<"\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_1 pci_problems_problem_description\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 25 "Problems.tmpl"
					out()<<cppcms::filters::escape(problem->description);
					#line 28 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</a>\n"
						"\t\t\t\t\t\t";
				#line 28 "Problems.tmpl"
				} // end of item
				#line 29 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 29 "Problems.tmpl"
			 } else {
				#line 31 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\tNo problems found\n"
					"\t\t\t\t\t";
			#line 31 "Problems.tmpl"
			} // end of empty
			#line 34 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 34 "Problems.tmpl"
		} // end of template page_content
	#line 37 "Problems.tmpl"
	}; // end of class problems_view
#line 38 "Problems.tmpl"
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
			#line 14 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/clarifications.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/header_bar.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/navigation_menu.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/problem.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 14 "Problem.tmpl"
		} // end of template css_links
		#line 17 "Problem.tmpl"
		virtual void page_content() {
			#line 18 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 18 "Problem.tmpl"
			template_view::header_bar();
			#line 19 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 19 "Problem.tmpl"
			template_view::navigation_menu();
			#line 26 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problem_main_container\">\n"
				"\t\t\t\t<div id=\"pci_problem_header_container\">\n"
				"\t\t\t\t\tHeader (extra info about the Problem)\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t<div id=\"pci_problem_problem_container\">\n"
				"\t\t\t\t\t<div class=\"pci_box_0\" id=\"pci_problem_problem_content\">\n"
				"\t\t\t\t\t\t";
			#line 26 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->content);
			#line 30 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t<div id=\"pci_problem_solution_container\">\n"
				"\t\t\t\t\t";
			#line 30 "Problem.tmpl"
			if(content.problem->is_solved) {
				#line 31 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<a class=\"pci_box_6\" href=\"";
				#line 31 "Problem.tmpl"
				content.app().mapper().map(out(),"/solution", cppcms::filters::urlencode(content.accepted_solution->id));
				#line 33 "Problem.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t<div class=\"pci_box_6 pci_problem_solution_description\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 33 "Problem.tmpl"
				out()<<cppcms::filters::escape(content.accepted_solution->description);
				#line 36 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t";
			#line 36 "Problem.tmpl"
			} // endif
			#line 37 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t";
			#line 37 "Problem.tmpl"
			if((*content.solutions).begin()!=(*content.solutions).end()) {
				#line 38 "Problem.tmpl"
				out()<<"\n"
					"\t \t\t\t\t\t";
				#line 38 "Problem.tmpl"
				for(CPPCMS_TYPEOF((*content.solutions).begin()) solution_ptr=(*content.solutions).begin(),solution_ptr_end=(*content.solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 38 "Problem.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 39 "Problem.tmpl"
					out()<<"\n"
						"\t \t\t\t\t\t\t<a class=\"pci_box_4\" href=\"";
					#line 39 "Problem.tmpl"
					content.app().mapper().map(out(),"/solution", cppcms::filters::urlencode(solution->id));
					#line 41 "Problem.tmpl"
					out()<<"\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_4 pci_problem_solution_description\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 41 "Problem.tmpl"
					out()<<cppcms::filters::escape(solution->description);
					#line 44 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</a>\n"
						"\t  \t\t\t\t\t";
				#line 44 "Problem.tmpl"
				} // end of item
				#line 45 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 45 "Problem.tmpl"
			 } else {
				#line 47 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\tThere are are no solutions\n"
					"\t\t\t\t\t";
			#line 47 "Problem.tmpl"
			} // end of empty
			#line 50 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 50 "Problem.tmpl"
			template_view::clarifications(content.clarifications);
			#line 51 "Problem.tmpl"
			out()<<"\n"
				"\t\t";
		#line 51 "Problem.tmpl"
		} // end of template page_content
	#line 54 "Problem.tmpl"
	}; // end of class problem_view
#line 55 "Problem.tmpl"
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
			#line 14 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/clarifications.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/header_bar.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/navigation_menu.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/solution.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 14 "Solution.tmpl"
		} // end of template css_links
		#line 17 "Solution.tmpl"
		virtual void page_content() {
			#line 18 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 18 "Solution.tmpl"
			template_view::header_bar();
			#line 19 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 19 "Solution.tmpl"
			template_view::navigation_menu();
			#line 21 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_solution_main_container\">\n"
				"\t\t\t\t";
			#line 21 "Solution.tmpl"
			out()<<cppcms::filters::escape(content.solution->content);
			#line 23 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 23 "Solution.tmpl"
			template_view::clarifications(content.clarifications);
			#line 24 "Solution.tmpl"
			out()<<"\n"
				"\t\t";
		#line 24 "Solution.tmpl"
		} // end of template page_content
	#line 27 "Solution.tmpl"
	}; // end of class solution_view
#line 28 "Solution.tmpl"
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
			#line 13 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/header_bar.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/ideas.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/navigation_menu.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 13 "Ideas.tmpl"
		} // end of template css_links
		#line 16 "Ideas.tmpl"
		virtual void page_content() {
			#line 17 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 17 "Ideas.tmpl"
			template_view::header_bar();
			#line 18 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 18 "Ideas.tmpl"
			template_view::navigation_menu();
			#line 22 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_ideas_main_container\">\n"
				"\t\t\t\tIdeas content\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 22 "Ideas.tmpl"
		} // end of template page_content
	#line 25 "Ideas.tmpl"
	}; // end of class ideas_view
#line 26 "Ideas.tmpl"
} // end of namespace pci_skin
#line 27 "Ideas.tmpl"
namespace {
#line 27 "Ideas.tmpl"
 cppcms::views::generator my_generator; 
#line 27 "Ideas.tmpl"
 struct loader { 
#line 27 "Ideas.tmpl"
  loader() { 
#line 27 "Ideas.tmpl"
   my_generator.name("pci_skin");
#line 27 "Ideas.tmpl"
   my_generator.add_view<pci_skin::template_view,ViewContent::TemplateContent>("template_view",true);
#line 27 "Ideas.tmpl"
   my_generator.add_view<pci_skin::index_view,ViewContent::IndexContent>("index_view",true);
#line 27 "Ideas.tmpl"
   my_generator.add_view<pci_skin::sign_in_view,ViewContent::SignInContent>("sign_in_view",true);
#line 27 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problems_view,ViewContent::ProblemsContent>("problems_view",true);
#line 27 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problem_view,ViewContent::ProblemContent>("problem_view",true);
#line 27 "Ideas.tmpl"
   my_generator.add_view<pci_skin::solution_view,ViewContent::SolutionContent>("solution_view",true);
#line 27 "Ideas.tmpl"
   my_generator.add_view<pci_skin::ideas_view,ViewContent::IdeasContent>("ideas_view",true);
#line 27 "Ideas.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 27 "Ideas.tmpl"
 }
#line 27 "Ideas.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 27 "Ideas.tmpl"
} a_loader;
#line 27 "Ideas.tmpl"
} // anon 
