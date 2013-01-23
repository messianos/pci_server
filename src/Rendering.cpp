#line 2 "Template.tmpl"
#include "ViewContent.h" 
#line 3 "Template.tmpl"
#include "Server.h" 
#line 5 "Template.tmpl"
namespace pci_skin {
	#line 6 "Template.tmpl"
	struct template_view :public cppcms::base_view
	#line 6 "Template.tmpl"
	{
	#line 6 "Template.tmpl"
		ViewContent::TemplateContent &content;
	#line 6 "Template.tmpl"
		template_view(std::ostream &_s,ViewContent::TemplateContent &_content): cppcms::base_view(_s),content(_content)
	#line 6 "Template.tmpl"
		{
	#line 6 "Template.tmpl"
		}
		#line 8 "Template.tmpl"
		virtual void css_links() {
			#line 14 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/elements.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/global.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/header_bar.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/navigation_menu.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<script type=\"text/javascript\" src=\"/js/jquery-1.9.0.min.js\"></script>\n"
				"\t\t";
		#line 14 "Template.tmpl"
		} // end of template css_links
		#line 17 "Template.tmpl"
		virtual void clarifications(ClarificationList clarifications) {
			#line 32 "Template.tmpl"
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
			#line 32 "Template.tmpl"
			if((*clarifications).begin()!=(*clarifications).end()) {
				#line 33 "Template.tmpl"
				out()<<"\n"
					" \t\t\t\t\t";
				#line 33 "Template.tmpl"
				for(CPPCMS_TYPEOF((*clarifications).begin()) clarification_ptr=(*clarifications).begin(),clarification_ptr_end=(*clarifications).end();clarification_ptr!=clarification_ptr_end;++clarification_ptr) {
				#line 33 "Template.tmpl"
				CPPCMS_TYPEOF(*clarification_ptr) &clarification=*clarification_ptr;
					#line 37 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t<div class=\"pci_clarifications_row_container\">\n"
						"\t\t\t\t\t\t\t<div class=\"pci_clarifications_question_container\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_3 pci_clarifications_question_content\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 37 "Template.tmpl"
					out()<<cppcms::filters::escape(clarification->question);
					#line 42 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_5 pci_clarifications_answer_content\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 42 "Template.tmpl"
					out()<<cppcms::filters::escape(clarification->answer);
					#line 46 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t</div>\n"
						"  \t\t\t\t\t";
				#line 46 "Template.tmpl"
				} // end of item
				#line 47 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t";
			#line 47 "Template.tmpl"
			 } else {
				#line 49 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\tThere are are no clarifications\n"
					"\t\t\t\t";
			#line 49 "Template.tmpl"
			} // end of empty
			#line 51 "Template.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 51 "Template.tmpl"
		} // end of template clarifications
		#line 54 "Template.tmpl"
		virtual void header_bar() {
			#line 61 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_header_bar_main_container\">\n"
				"\t\t\t\t<div id=\"pci_header_bar_central_container\">\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_logo_container\">\n"
				"\t\t\t\t\t\t<div id=\"pci_header_bar_logo\"></div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_button_container\">\n"
				"\t\t\t\t\t \t";
			#line 61 "Template.tmpl"
			if(content.user_logged) {
				#line 62 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t \t\t<div id=\"user_name_box\">Hola, ";
				#line 62 "Template.tmpl"
				out()<<cppcms::filters::escape(content.user_name);
				#line 63 "Template.tmpl"
				out()<<"!</div>\n"
					"\t\t\t\t\t\t\t<a class=\"pci_button_0\" href=\"";
				#line 63 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_out");
				#line 68 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_0 pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tSalir\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t";
			#line 68 "Template.tmpl"
			}else{
				#line 69 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t<a class=\"pci_button_0\" href=\"";
				#line 69 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_in");
				#line 74 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_0 pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tIngresar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t\t<a class=\"pci_button_0\" href=\"";
				#line 74 "Template.tmpl"
				content.app().mapper().map(out(),"/sign_up");
				#line 79 "Template.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t\t<div class=\"pci_button_0 pci_header_bar_button\">\n"
					"\t\t\t\t\t\t\t\t\tRegistrar\n"
					"\t\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t\t";
			#line 79 "Template.tmpl"
			}
			#line 83 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 83 "Template.tmpl"
		} // end of template header_bar
		#line 86 "Template.tmpl"
		virtual void information_footer() {
			#line 98 "Template.tmpl"
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
			#line 98 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 103 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 103 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 108 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 108 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 118 "Template.tmpl"
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
			#line 118 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 123 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 123 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 128 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 128 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 138 "Template.tmpl"
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
			#line 138 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 143 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 143 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 148 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 148 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 158 "Template.tmpl"
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
			#line 158 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 163 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 163 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 168 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"";
			#line 168 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 176 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 176 "Template.tmpl"
		} // end of template information_footer
		#line 179 "Template.tmpl"
		virtual void navigation_menu() {
			#line 181 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_navigation_menu_main_container\">\n"
				"\t\t\t\t<a href=\"";
			#line 181 "Template.tmpl"
			content.app().mapper().map(out(),"/problems");
			#line 189 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_button\" id=\"pci_navigation_menu_problems_button\">\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_image\" id=\"pci_navigation_menu_problems_button_image\"></div>\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_text\">\n"
				"\t\t\t\t\t\t\tProblems\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 189 "Template.tmpl"
			content.app().mapper().map(out(),"/ideas");
			#line 197 "Template.tmpl"
			out()<<"\">\n"
				"\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_button\" id=\"pci_navigation_menu_ideas_button\">\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_image\" id=\"pci_navigation_menu_ideas_button_image\"></div>\n"
				"\t\t\t\t\t\t<div class=\"pci_button_1_text\">\n"
				"\t\t\t\t\t\t\tIdeas\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</a>\n"
				"\t\t\t\t<a href=\"";
			#line 197 "Template.tmpl"
			content.app().mapper().map(out(),"");
			#line 206 "Template.tmpl"
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
		#line 206 "Template.tmpl"
		} // end of template navigation_menu
		#line 208 "Template.tmpl"
		virtual void page_content() {
			#line 209 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 209 "Template.tmpl"
		} // end of template page_content
		#line 212 "Template.tmpl"
		virtual void render() {
			#line 217 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<!DOCTYPE html>\n"
				"\t\t\t\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 217 "Template.tmpl"
			css_links();
			#line 220 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 220 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 225 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t";
			#line 225 "Template.tmpl"
			page_content();
			#line 228 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 228 "Template.tmpl"
		} // end of template render
	#line 231 "Template.tmpl"
	}; // end of class template_view
#line 232 "Template.tmpl"
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
				"\t\t\t<link href=\"/css/information_footer.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 12 "Index.tmpl"
		} // end of template css_links
		#line 15 "Index.tmpl"
		virtual void page_content() {
			#line 17 "Index.tmpl"
			out()<<"\n"
				"\t\t\t<div class=\"wrapper\">\n"
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
			#line 29 "Index.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
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
			#line 13 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/header_bar.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/navigation_menu.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/problems.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 13 "SignIn.tmpl"
		} // end of template css_links
		#line 16 "SignIn.tmpl"
		virtual void page_content() {
			#line 17 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 17 "SignIn.tmpl"
			template_view::header_bar();
			#line 18 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 18 "SignIn.tmpl"
			template_view::navigation_menu();
			#line 22 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problems_main_container\">\n"
				"\t\t\t\t<h1>Sign in</h1>\n"
				"\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t";
			#line 22 "SignIn.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 25 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t\t</form>\n"
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
				"\t\t\t<link href=\"/css/problems.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
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
			#line 20 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problems_main_container\">\n"
				"\t\t\t\t<h1>Registrar</h1>\n"
				"\t\t\t\t<form action=\"\" method=\"post\">\n"
				"\t\t\t\t\t";
			#line 20 "SignUp.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.form_info).render(_form_context); }
			#line 23 "SignUp.tmpl"
			out()<<"\n"
				"\t\t\t\t</form>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 23 "SignUp.tmpl"
		} // end of template page_content
		#line 26 "SignUp.tmpl"
		virtual void render_input() {
			#line 28 "SignUp.tmpl"
			out()<<"\n"
				"\t\n"
				"\t\t";
		#line 28 "SignUp.tmpl"
		} // end of template render_input
	#line 30 "SignUp.tmpl"
	}; // end of class sign_up_view
#line 31 "SignUp.tmpl"
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
		virtual void page_content() {
			#line 15 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "Problems.tmpl"
			template_view::header_bar();
			#line 16 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "Problems.tmpl"
			template_view::navigation_menu();
			#line 24 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\n"
				"\t\t\t<script type=\"text/javascript\">\n"
				"\t\t\t\t$('#pci_navigation_menu_problems_button').addClass('active');\n"
				"\t\t\t</script>\n"
				"\t\t\t\n"
				"\t\t\t<div id=\"pci_problems_main_container\">\n"
				"\t\t\t\t<div class=\"pci_box_2\" id=\"pci_problems_problem_container\">\n"
				"\t\t\t\t\t";
			#line 24 "Problems.tmpl"
			if((*content.problems).begin()!=(*content.problems).end()) {
				#line 25 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
				#line 25 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.problems).begin()) problem_ptr=(*content.problems).begin(),problem_ptr_end=(*content.problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 25 "Problems.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 26 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t<a class=\"pci_box_1\" href=\"";
					#line 26 "Problems.tmpl"
					content.app().mapper().map(out(),"/problem", cppcms::filters::urlencode(problem->id));
					#line 28 "Problems.tmpl"
					out()<<"\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_1 pci_problems_problem_description\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 28 "Problems.tmpl"
					out()<<cppcms::filters::escape(problem->description);
					#line 31 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</a>\n"
						"\t\t\t\t\t\t";
				#line 31 "Problems.tmpl"
				} // end of item
				#line 32 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 32 "Problems.tmpl"
			 } else {
				#line 34 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\tNo problems found\n"
					"\t\t\t\t\t";
			#line 34 "Problems.tmpl"
			} // end of empty
			#line 37 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 37 "Problems.tmpl"
		} // end of template page_content
	#line 40 "Problems.tmpl"
	}; // end of class problems_view
#line 41 "Problems.tmpl"
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
			#line 12 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/clarifications.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/problem.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 12 "Problem.tmpl"
		} // end of template css_links
		#line 15 "Problem.tmpl"
		virtual void page_content() {
			#line 16 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "Problem.tmpl"
			template_view::header_bar();
			#line 17 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 17 "Problem.tmpl"
			template_view::navigation_menu();
			#line 24 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problem_main_container\">\n"
				"\t\t\t\t<div id=\"pci_problem_header_container\">\n"
				"\t\t\t\t\tHeader (extra info about the Problem)\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t<div id=\"pci_problem_problem_container\">\n"
				"\t\t\t\t\t<div class=\"pci_box_0\" id=\"pci_problem_problem_content\">\n"
				"\t\t\t\t\t\t";
			#line 24 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->content);
			#line 28 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t<div id=\"pci_problem_solution_container\">\n"
				"\t\t\t\t\t";
			#line 28 "Problem.tmpl"
			if(content.problem->is_solved) {
				#line 29 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t<a class=\"pci_box_6\" href=\"";
				#line 29 "Problem.tmpl"
				content.app().mapper().map(out(),"/solution", cppcms::filters::urlencode(content.accepted_solution->id));
				#line 31 "Problem.tmpl"
				out()<<"\">\n"
					"\t\t\t\t\t\t\t<div class=\"pci_box_6 pci_problem_solution_description\">\n"
					"\t\t\t\t\t\t\t\t";
				#line 31 "Problem.tmpl"
				out()<<cppcms::filters::escape(content.accepted_solution->description);
				#line 34 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\t</div>\n"
					"\t\t\t\t\t\t</a>\n"
					"\t\t\t\t\t";
			#line 34 "Problem.tmpl"
			} // endif
			#line 35 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t\t";
			#line 35 "Problem.tmpl"
			if((*content.solutions).begin()!=(*content.solutions).end()) {
				#line 36 "Problem.tmpl"
				out()<<"\n"
					"\t \t\t\t\t\t";
				#line 36 "Problem.tmpl"
				for(CPPCMS_TYPEOF((*content.solutions).begin()) solution_ptr=(*content.solutions).begin(),solution_ptr_end=(*content.solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 36 "Problem.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 37 "Problem.tmpl"
					out()<<"\n"
						"\t \t\t\t\t\t\t<a class=\"pci_box_4\" href=\"";
					#line 37 "Problem.tmpl"
					content.app().mapper().map(out(),"/solution", cppcms::filters::urlencode(solution->id));
					#line 39 "Problem.tmpl"
					out()<<"\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_box_4 pci_problem_solution_description\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 39 "Problem.tmpl"
					out()<<cppcms::filters::escape(solution->description);
					#line 42 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</a>\n"
						"\t  \t\t\t\t\t";
				#line 42 "Problem.tmpl"
				} // end of item
				#line 43 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 43 "Problem.tmpl"
			 } else {
				#line 45 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\tThere are are no solutions\n"
					"\t\t\t\t\t";
			#line 45 "Problem.tmpl"
			} // end of empty
			#line 48 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 48 "Problem.tmpl"
			template_view::clarifications(content.clarifications);
			#line 49 "Problem.tmpl"
			out()<<"\n"
				"\t\t";
		#line 49 "Problem.tmpl"
		} // end of template page_content
	#line 52 "Problem.tmpl"
	}; // end of class problem_view
#line 53 "Problem.tmpl"
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
			#line 12 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/clarifications.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/solution.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 12 "Solution.tmpl"
		} // end of template css_links
		#line 15 "Solution.tmpl"
		virtual void page_content() {
			#line 16 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "Solution.tmpl"
			template_view::header_bar();
			#line 17 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 17 "Solution.tmpl"
			template_view::navigation_menu();
			#line 19 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_solution_main_container\">\n"
				"\t\t\t\t";
			#line 19 "Solution.tmpl"
			out()<<cppcms::filters::escape(content.solution->content);
			#line 21 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t\t";
			#line 21 "Solution.tmpl"
			template_view::clarifications(content.clarifications);
			#line 22 "Solution.tmpl"
			out()<<"\n"
				"\t\t";
		#line 22 "Solution.tmpl"
		} // end of template page_content
	#line 25 "Solution.tmpl"
	}; // end of class solution_view
#line 26 "Solution.tmpl"
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
		virtual void page_content() {
			#line 15 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 15 "Ideas.tmpl"
			template_view::header_bar();
			#line 16 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "Ideas.tmpl"
			template_view::navigation_menu();
			#line 25 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t\n"
				"\t\t\t<script type=\"text/javascript\">\n"
				"\t\t\t\t$('#pci_navigation_menu_ideas_button').addClass('active');\n"
				"\t\t\t</script>\n"
				"\t\t\t\n"
				"\t\t\t<div id=\"pci_ideas_main_container\">\n"
				"\t\t\t\tIdeas content\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 25 "Ideas.tmpl"
		} // end of template page_content
	#line 28 "Ideas.tmpl"
	}; // end of class ideas_view
#line 29 "Ideas.tmpl"
} // end of namespace pci_skin
#line 30 "Ideas.tmpl"
namespace {
#line 30 "Ideas.tmpl"
 cppcms::views::generator my_generator; 
#line 30 "Ideas.tmpl"
 struct loader { 
#line 30 "Ideas.tmpl"
  loader() { 
#line 30 "Ideas.tmpl"
   my_generator.name("pci_skin");
#line 30 "Ideas.tmpl"
   my_generator.add_view<pci_skin::template_view,ViewContent::TemplateContent>("template_view",true);
#line 30 "Ideas.tmpl"
   my_generator.add_view<pci_skin::index_view,ViewContent::IndexContent>("index_view",true);
#line 30 "Ideas.tmpl"
   my_generator.add_view<pci_skin::sign_in_view,ViewContent::SignInContent>("sign_in_view",true);
#line 30 "Ideas.tmpl"
   my_generator.add_view<pci_skin::sign_up_view,ViewContent::SignUpContent>("sign_up_view",true);
#line 30 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problems_view,ViewContent::ProblemsContent>("problems_view",true);
#line 30 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problem_view,ViewContent::ProblemContent>("problem_view",true);
#line 30 "Ideas.tmpl"
   my_generator.add_view<pci_skin::solution_view,ViewContent::SolutionContent>("solution_view",true);
#line 30 "Ideas.tmpl"
   my_generator.add_view<pci_skin::ideas_view,ViewContent::IdeasContent>("ideas_view",true);
#line 30 "Ideas.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 30 "Ideas.tmpl"
 }
#line 30 "Ideas.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 30 "Ideas.tmpl"
} a_loader;
#line 30 "Ideas.tmpl"
} // anon 
