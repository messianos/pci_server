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
				"\t\t\t<div id=\"pci_clarifications\">\n"
				"\t\t\t\t<div id=\"pci_clarifications_main_container\">\n"
				"\t\t\t\t\t<div class=\"pci_clarifications_row_container\">\n"
				"\t\t\t\t\t\t<div class=\"pci_clarifications_question_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_clarifications_column_header\" id=\"pci_clarifications_question_column_header\">\n"
				"\t\t\t\t\t\t\t\tQuestion\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_clarifications_column_header\" id=\"pci_clarifications_answer_column_header\">\n"
				"\t\t\t\t\t\t\t\tAnswer\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t";
			#line 23 "Template.tmpl"
			if((*clarifications).begin()!=(*clarifications).end()) {
				#line 24 "Template.tmpl"
				out()<<"\n"
					"\t \t\t\t\t\t";
				#line 24 "Template.tmpl"
				for(CPPCMS_TYPEOF((*clarifications).begin()) clarification_ptr=(*clarifications).begin(),clarification_ptr_end=(*clarifications).end();clarification_ptr!=clarification_ptr_end;++clarification_ptr) {
				#line 24 "Template.tmpl"
				CPPCMS_TYPEOF(*clarification_ptr) &clarification=*clarification_ptr;
					#line 28 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t<div class=\"pci_clarifications_row_container\">\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_question_container\">\n"
						"\t\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_content pci_text_box_0\">\n"
						"\t\t\t\t\t\t\t\t\t\t";
					#line 28 "Template.tmpl"
					out()<<cppcms::filters::escape(clarification->question);
					#line 33 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_answer_container\">\n"
						"\t\t\t\t\t\t\t\t\t<div class=\"pci_clarifications_content pci_text_box_0\">\n"
						"\t\t\t\t\t\t\t\t\t\t";
					#line 33 "Template.tmpl"
					out()<<cppcms::filters::escape(clarification->answer);
					#line 37 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t\t\t\t\t\t</div>\n"
						"\t  \t\t\t\t\t";
				#line 37 "Template.tmpl"
				} // end of item
				#line 38 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 38 "Template.tmpl"
			 } else {
				#line 40 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\tThere are are no clarifications\n"
					"\t\t\t\t\t";
			#line 40 "Template.tmpl"
			} // end of empty
			#line 43 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 43 "Template.tmpl"
		} // end of template clarifications
		#line 46 "Template.tmpl"
		virtual void header_bar() {
			#line 66 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_header_bar\">\n"
				"\t\t\t\t<div id=\"pci_header_bar_main_container\">\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_logo_container\">\n"
				"\t\t\t\t\t\tPCI Logo\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_header_bar_button_container\">\n"
				"\t\t\t\t\t\t<a class=\"pci_button_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_0 pci_header_bar_button\">\n"
				"\t\t\t\t\t\t\t\tButton 1\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t<a class=\"pci_button_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_0 pci_header_bar_button\">\n"
				"\t\t\t\t\t\t\t\tButton 2\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 66 "Template.tmpl"
		} // end of template header_bar
		#line 69 "Template.tmpl"
		virtual void ideas() {
			#line 79 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\tIdeas content\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t";
		#line 79 "Template.tmpl"
		} // end of template ideas
		#line 82 "Template.tmpl"
		virtual void index() {
			#line 92 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\tIndex content\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t";
		#line 92 "Template.tmpl"
		} // end of template index
		#line 95 "Template.tmpl"
		virtual void information_footer() {
			#line 185 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_information_footer\">\n"
				"\t\t\t\t<div id=\"pci_information_footer_main_container\">\n"
				"\t\t\t\t\t<div id=\"pci_information_footer_TO_DEFINE_container\">\n"
				"\t\t\t\t\t\tSome information\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_information_footer_link_container\">\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tHeader 1\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tHeader 2\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tHeader 3\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_information_footer_column_container\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_column_header\">\n"
				"\t\t\t\t\t\t\t\tHeader 4\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 1\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 2\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t<div class=\"pci_information_footer_link\">\n"
				"\t\t\t\t\t\t\t\t<a class=\"pci_link_0\" href=\"\">\n"
				"\t\t\t\t\t\t\t\t\tLink 3\n"
				"\t\t\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 185 "Template.tmpl"
		} // end of template information_footer
		#line 188 "Template.tmpl"
		virtual void navigation_menu() {
			#line 221 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_navigation_menu\">\n"
				"\t\t\t\t<div id=\"pci_navigation_menu_main_container\">\n"
				"\t\t\t\t\t<div id=\"pci_navigation_menu_service_container\">\n"
				"\t\t\t\t\t\t<a href=\"\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_service_button\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"pci_button_1_image\" id=\"pci_navigation_menu_problems_button_image\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"pci_button_1_text\">\n"
				"\t\t\t\t\t\t\t\t\tProblems\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t\t<a href=\"\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_service_button\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"pci_button_1_image\" id=\"pci_navigation_menu_ideas_button_image\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"pci_button_1_text\">\n"
				"\t\t\t\t\t\t\t\t\tIdeas\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_navigation_menu_option_container\">\n"
				"\t\t\t\t\t\t<a href=\"\">\n"
				"\t\t\t\t\t\t\t<div class=\"pci_button_1 pci_navigation_menu_option_button\">\n"
				"\t\t\t\t\t\t\t\t<div class=\"pci_button_1_image\" id=\"pci_navigation_menu_profile_button_image\"></div>\n"
				"\t\t\t\t\t\t\t\t<div class=\"pci_button_1_text\">\n"
				"\t\t\t\t\t\t\t\t\tProfile\n"
				"\t\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t</a>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 221 "Template.tmpl"
		} // end of template navigation_menu
		#line 224 "Template.tmpl"
		virtual void problem(ProblemPointer problem,SolutionPointer accepted_solution,SolutionList solutions) {
			#line 236 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<div id=\"pci_problem\">\n"
				"\t\t\t\t<div id=\"pci_problem_main_container\">\n"
				"\t\t\t\t\t<div id=\"pci_problem_problem_container\">\n"
				"\t\t\t\t\t\t<div id=\"pci_problem_problem_header_container\">\n"
				"\t\t\t\t\t\t\tHeader\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\t<div class=\"pci_text_box_0\" id=\"pci_problem_problem_content\">\n"
				"\t\t\t\t\t\t\tContent\n"
				"\t\t\t\t\t\t</div>\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t<div id=\"pci_problem_solution_container\">\n"
				"\t\t\t\t\t\t";
			#line 236 "Template.tmpl"
			if((*solutions).begin()!=(*solutions).end()) {
				#line 237 "Template.tmpl"
				out()<<"\n"
					"\t\t \t\t\t\t\t";
				#line 237 "Template.tmpl"
				for(CPPCMS_TYPEOF((*solutions).begin()) solution_ptr=(*solutions).begin(),solution_ptr_end=(*solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 237 "Template.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 239 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t<div class=\"pci_problem_solution_content pci_text_box_0\">\n"
						"\t\t\t\t\t\t\t\t\t";
					#line 239 "Template.tmpl"
					out()<<cppcms::filters::escape(solution->description);
					#line 241 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t\t\t</div>\n"
						"\t\t  \t\t\t\t\t";
				#line 241 "Template.tmpl"
				} // end of item
				#line 242 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t";
			#line 242 "Template.tmpl"
			 } else {
				#line 244 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t\t\tThere are are no solutions\n"
					"\t\t\t\t\t\t";
			#line 244 "Template.tmpl"
			} // end of empty
			#line 248 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 248 "Template.tmpl"
		} // end of template problem
		#line 251 "Template.tmpl"
		virtual void problems(ProblemList problems) {
			#line 261 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\tProblems content\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t";
			#line 261 "Template.tmpl"
			if((*problems).begin()!=(*problems).end()) {
				#line 262 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\t";
				#line 262 "Template.tmpl"
				for(CPPCMS_TYPEOF((*problems).begin()) problem_ptr=(*problems).begin(),problem_ptr_end=(*problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 262 "Template.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 263 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t<div onclick=\"location.href='/pci/problem/";
					#line 263 "Template.tmpl"
					out()<<cppcms::filters::escape(problem->id);
					#line 264 "Template.tmpl"
					out()<<"'\">\n"
						"\t\t\t\t\t\t";
					#line 264 "Template.tmpl"
					out()<<cppcms::filters::escape(problem->id);
					#line 264 "Template.tmpl"
					out()<<": ";
					#line 264 "Template.tmpl"
					out()<<cppcms::filters::escape(problem->description);
					#line 266 "Template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t</div>\n"
						"\t\t\t\t";
				#line 266 "Template.tmpl"
				} // end of item
				#line 267 "Template.tmpl"
				out()<<"\n"
					"\t\t\t";
			#line 267 "Template.tmpl"
			 } else {
				#line 269 "Template.tmpl"
				out()<<"\n"
					"\t\t\t\tNo problems found\n"
					"\t\t\t";
			#line 269 "Template.tmpl"
			} // end of empty
			#line 270 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 270 "Template.tmpl"
		} // end of template problems
		#line 273 "Template.tmpl"
		virtual void solution(SolutionPointer solution) {
			#line 283 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\tSolution content\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t\t<br />\n"
				"\t\t";
		#line 283 "Template.tmpl"
		} // end of template solution
		#line 286 "Template.tmpl"
		virtual void css_links() {
			#line 289 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/global.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/elements.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 289 "Template.tmpl"
		} // end of template css_links
		#line 292 "Template.tmpl"
		virtual void page_content() {
			#line 293 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 293 "Template.tmpl"
		} // end of template page_content
		#line 296 "Template.tmpl"
		virtual void render() {
			#line 301 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<!DOCTYPE html>\n"
				"\t\t\t\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 301 "Template.tmpl"
			css_links();
			#line 304 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 304 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 309 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t";
			#line 309 "Template.tmpl"
			page_content();
			#line 312 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 312 "Template.tmpl"
		} // end of template render
	#line 315 "Template.tmpl"
	}; // end of class template_view
#line 316 "Template.tmpl"
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
			#line 18 "Index.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 18 "Index.tmpl"
			template_view::index();
			#line 19 "Index.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 19 "Index.tmpl"
			template_view::information_footer();
			#line 20 "Index.tmpl"
			out()<<"\n"
				"\t\t";
		#line 20 "Index.tmpl"
		} // end of template page_content
	#line 23 "Index.tmpl"
	}; // end of class index_view
#line 24 "Index.tmpl"
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
			#line 19 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 19 "Problems.tmpl"
			template_view::problems(content.problems);
			#line 20 "Problems.tmpl"
			out()<<"\n"
				"\t\t";
		#line 20 "Problems.tmpl"
		} // end of template page_content
	#line 23 "Problems.tmpl"
	}; // end of class problems_view
#line 24 "Problems.tmpl"
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
			#line 20 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 20 "Problem.tmpl"
			template_view::problem(content.problem,content.accepted_solution,content.solutions);
			#line 21 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 21 "Problem.tmpl"
			template_view::clarifications(content.clarifications);
			#line 22 "Problem.tmpl"
			out()<<"\n"
				"\t\t";
		#line 22 "Problem.tmpl"
		} // end of template page_content
	#line 25 "Problem.tmpl"
	}; // end of class problem_view
#line 26 "Problem.tmpl"
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
			#line 13 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/clarifications.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/header_bar.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/solution.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 13 "Solution.tmpl"
		} // end of template css_links
		#line 16 "Solution.tmpl"
		virtual void page_content() {
			#line 17 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 17 "Solution.tmpl"
			template_view::header_bar();
			#line 18 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 18 "Solution.tmpl"
			template_view::solution(content.solution);
			#line 19 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 19 "Solution.tmpl"
			template_view::clarifications(content.clarifications);
			#line 20 "Solution.tmpl"
			out()<<"\n"
				"\t\t";
		#line 20 "Solution.tmpl"
		} // end of template page_content
	#line 23 "Solution.tmpl"
	}; // end of class solution_view
#line 24 "Solution.tmpl"
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
			#line 12 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/header_bar.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t\t<link href=\"/css/ideas.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 12 "Ideas.tmpl"
		} // end of template css_links
		#line 15 "Ideas.tmpl"
		virtual void page_content() {
			#line 16 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 16 "Ideas.tmpl"
			template_view::header_bar();
			#line 17 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 17 "Ideas.tmpl"
			template_view::ideas();
			#line 18 "Ideas.tmpl"
			out()<<"\n"
				"\t\t";
		#line 18 "Ideas.tmpl"
		} // end of template page_content
	#line 21 "Ideas.tmpl"
	}; // end of class ideas_view
#line 22 "Ideas.tmpl"
} // end of namespace pci_skin
#line 23 "Ideas.tmpl"
namespace {
#line 23 "Ideas.tmpl"
 cppcms::views::generator my_generator; 
#line 23 "Ideas.tmpl"
 struct loader { 
#line 23 "Ideas.tmpl"
  loader() { 
#line 23 "Ideas.tmpl"
   my_generator.name("pci_skin");
#line 23 "Ideas.tmpl"
   my_generator.add_view<pci_skin::template_view,ViewContent::TemplateContent>("template_view",true);
#line 23 "Ideas.tmpl"
   my_generator.add_view<pci_skin::index_view,ViewContent::IndexContent>("index_view",true);
#line 23 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problems_view,ViewContent::ProblemsContent>("problems_view",true);
#line 23 "Ideas.tmpl"
   my_generator.add_view<pci_skin::problem_view,ViewContent::ProblemContent>("problem_view",true);
#line 23 "Ideas.tmpl"
   my_generator.add_view<pci_skin::solution_view,ViewContent::SolutionContent>("solution_view",true);
#line 23 "Ideas.tmpl"
   my_generator.add_view<pci_skin::ideas_view,ViewContent::IdeasContent>("ideas_view",true);
#line 23 "Ideas.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 23 "Ideas.tmpl"
 }
#line 23 "Ideas.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 23 "Ideas.tmpl"
} a_loader;
#line 23 "Ideas.tmpl"
} // anon 
