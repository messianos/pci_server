#line 2 "Template.tmpl"
#include "ViewContent.h" 
#line 4 "Template.tmpl"
namespace test_skin {
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
		virtual void head_links() {
			#line 9 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/template.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 9 "Template.tmpl"
		} // end of template head_links
		#line 11 "Template.tmpl"
		virtual void body_header() {
			#line 13 "Template.tmpl"
			out()<<"\n"
				"\t\t\tHeader content\n"
				"\t\t";
		#line 13 "Template.tmpl"
		} // end of template body_header
		#line 15 "Template.tmpl"
		virtual void body_content() {
			#line 16 "Template.tmpl"
			out()<<"\n"
				"\t\t";
		#line 16 "Template.tmpl"
		} // end of template body_content
		#line 18 "Template.tmpl"
		virtual void body_footer() {
			#line 20 "Template.tmpl"
			out()<<"\n"
				"\t\t\tFooter content\n"
				"\t\t";
		#line 20 "Template.tmpl"
		} // end of template body_footer
		#line 22 "Template.tmpl"
		virtual void render() {
			#line 25 "Template.tmpl"
			out()<<"\n"
				"\t\t\t<html>\n"
				"\t\t\t\t<head>\n"
				"\t\t\t\t\t";
			#line 25 "Template.tmpl"
			head_links();
			#line 28 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t\n"
				"\t\t\t    \t<title>\n"
				"\t\t\t    \t\t";
			#line 28 "Template.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
			#line 34 "Template.tmpl"
			out()<<"\n"
				"\t\t\t    \t</title>\n"
				"\t\t\t\t</head>\n"
				"\t\t\t\t\n"
				"\t\t\t\t<body>\n"
				"\t\t\t\t\t<div id=\"template_header\">\n"
				"\t\t\t\t\t\t";
			#line 34 "Template.tmpl"
			body_header();
			#line 38 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\t<div id=\"template_content\">\n"
				"\t\t\t\t\t\t";
			#line 38 "Template.tmpl"
			body_content();
			#line 42 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t\t\n"
				"\t\t\t\t\t<div id=\"template_footer\">\n"
				"\t\t\t\t\t\t";
			#line 42 "Template.tmpl"
			body_footer();
			#line 46 "Template.tmpl"
			out()<<"\n"
				"\t\t\t\t\t</div>\n"
				"\t\t\t\t</body>\n"
				"\t\t\t</html>\n"
				"\t\t";
		#line 46 "Template.tmpl"
		} // end of template render
	#line 48 "Template.tmpl"
	}; // end of class template_view
#line 49 "Template.tmpl"
} // end of namespace test_skin
#line 2 "Welcome.tmpl"
#include "ViewContent.h" 
#line 4 "Welcome.tmpl"
namespace test_skin {
	#line 5 "Welcome.tmpl"
	struct welcome_view :public template_view
	#line 5 "Welcome.tmpl"
	{
	#line 5 "Welcome.tmpl"
		ViewContent::WelcomeContent &content;
	#line 5 "Welcome.tmpl"
		welcome_view(std::ostream &_s,ViewContent::WelcomeContent &_content): template_view(_s,_content),content(_content)
	#line 5 "Welcome.tmpl"
		{
	#line 5 "Welcome.tmpl"
		}
		#line 7 "Welcome.tmpl"
		virtual void head_links() {
			#line 8 "Welcome.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 8 "Welcome.tmpl"
			template_view::head_links();
			#line 10 "Welcome.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/welcome.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 10 "Welcome.tmpl"
		} // end of template head_links
		#line 12 "Welcome.tmpl"
		virtual void body_content() {
			#line 19 "Welcome.tmpl"
			out()<<"\n"
				"\t\t\t<h1>Bienvenido!</h1>\n"
				"\t\t\t<a href=\"/pci/sign_in\">Sign in</a>\n"
				"\t\t\t<br />\n"
				"\t\t\t<a href=\"/pci/problems\">Problems</a>\n"
				"\t\t\t<br />\n"
				"\t\t\t<a href=\"/pci/ideas\">Ideas</a>\n"
				"\t\t";
		#line 19 "Welcome.tmpl"
		} // end of template body_content
	#line 21 "Welcome.tmpl"
	}; // end of class welcome_view
#line 22 "Welcome.tmpl"
} // end of namespace test_skin
#line 2 "SignIn.tmpl"
#include "ViewContent.h" 
#line 4 "SignIn.tmpl"
namespace test_skin {
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
		#line 7 "SignIn.tmpl"
		virtual void head_links() {
			#line 8 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 8 "SignIn.tmpl"
			template_view::head_links();
			#line 10 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/sign_in.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 10 "SignIn.tmpl"
		} // end of template head_links
		#line 12 "SignIn.tmpl"
		virtual void body_content() {
			#line 27 "SignIn.tmpl"
			out()<<"\n"
				"\t\t\t<h1>Sign in</h1>\n"
				"\t\t\t<div>\n"
				"\t\t\t\tUser\n"
				"\t\t\t</div>\n"
				"\t\t\t<div>\n"
				"\t\t\t\t<input type=\"text\" />\n"
				"\t\t\t</div>\n"
				"\t\t\t<div>\n"
				"\t\t\t\tPassword\n"
				"\t\t\t</div>\n"
				"\t\t\t<div>\n"
				"\t\t\t\t<input type=\"password\" />\n"
				"\t\t\t</div>\n"
				"\t\t\t<input type=\"submit\" value=\"Sign in\" />\n"
				"\t\t";
		#line 27 "SignIn.tmpl"
		} // end of template body_content
	#line 29 "SignIn.tmpl"
	}; // end of class sign_in_view
#line 30 "SignIn.tmpl"
} // end of namespace test_skin
#line 2 "Problems.tmpl"
#include "ViewContent.h" 
#line 4 "Problems.tmpl"
namespace test_skin {
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
		#line 7 "Problems.tmpl"
		virtual void head_links() {
			#line 8 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 8 "Problems.tmpl"
			template_view::head_links();
			#line 10 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/problems.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 10 "Problems.tmpl"
		} // end of template head_links
		#line 12 "Problems.tmpl"
		virtual void body_content() {
			#line 15 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t<h1>Problems</h1>\n"
				"\t\t\t<div>\n"
				"\t\t\t\t";
			#line 15 "Problems.tmpl"
			if((*content.problems).begin()!=(*content.problems).end()) {
				#line 16 "Problems.tmpl"
				out()<<"\n"
					" \t\t\t\t\t";
				#line 16 "Problems.tmpl"
				for(CPPCMS_TYPEOF((*content.problems).begin()) problem_ptr=(*content.problems).begin(),problem_ptr_end=(*content.problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 16 "Problems.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 17 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t<div onclick=\"location.href='/pci/problem/";
					#line 17 "Problems.tmpl"
					out()<<cppcms::filters::escape(problem->id);
					#line 18 "Problems.tmpl"
					out()<<"'\">\n"
						"\t\t\t\t\t\t\t";
					#line 18 "Problems.tmpl"
					out()<<cppcms::filters::escape(problem->id);
					#line 18 "Problems.tmpl"
					out()<<": ";
					#line 18 "Problems.tmpl"
					out()<<cppcms::filters::escape(problem->description);
					#line 20 "Problems.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t</div>\n"
						"  \t\t\t\t\t";
				#line 20 "Problems.tmpl"
				} // end of item
				#line 21 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t";
			#line 21 "Problems.tmpl"
			 } else {
				#line 23 "Problems.tmpl"
				out()<<"\n"
					"\t\t\t\t\tNo problems found\n"
					"\t\t\t\t";
			#line 23 "Problems.tmpl"
			} // end of empty
			#line 25 "Problems.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t";
		#line 25 "Problems.tmpl"
		} // end of template body_content
	#line 27 "Problems.tmpl"
	}; // end of class problems_view
#line 28 "Problems.tmpl"
} // end of namespace test_skin
#line 2 "Problem.tmpl"
#include "ViewContent.h" 
#line 4 "Problem.tmpl"
namespace test_skin {
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
		#line 7 "Problem.tmpl"
		virtual void head_links() {
			#line 8 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 8 "Problem.tmpl"
			template_view::head_links();
			#line 10 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/problem.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 10 "Problem.tmpl"
		} // end of template head_links
		#line 12 "Problem.tmpl"
		virtual void body_content() {
			#line 13 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<h1>Problem ";
			#line 13 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->id);
			#line 16 "Problem.tmpl"
			out()<<"</h1>\n"
				"\t\t\t<div class = \"button_wrapper\">\n"
				"\t\t\t\t<div class = \"publication\">\n"
				"\t\t\t\t\tDescripcion: ";
			#line 16 "Problem.tmpl"
			out()<<cppcms::filters::escape(content.problem->description);
			#line 20 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t<h2>Aclaraciones</h2>\n"
				"\t\t\t";
			#line 20 "Problem.tmpl"
			if((*content.clarifications).begin()!=(*content.clarifications).end()) {
				#line 21 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t";
				#line 21 "Problem.tmpl"
				for(CPPCMS_TYPEOF((*content.clarifications).begin()) clarification_ptr=(*content.clarifications).begin(),clarification_ptr_end=(*content.clarifications).end();clarification_ptr!=clarification_ptr_end;++clarification_ptr) {
				#line 21 "Problem.tmpl"
				CPPCMS_TYPEOF(*clarification_ptr) &clarification=*clarification_ptr;
					#line 23 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t<div class = \"publication\">\n"
						"\t\t\t\t\t\tID: ";
					#line 23 "Problem.tmpl"
					out()<<cppcms::filters::escape(clarification->id);
					#line 23 "Problem.tmpl"
					out()<<" Pregunta: ";
					#line 23 "Problem.tmpl"
					out()<<cppcms::filters::escape(clarification->question);
					#line 24 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\tRespuesta: ";
					#line 24 "Problem.tmpl"
					out()<<cppcms::filters::escape(clarification->answer);
					#line 26 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t</div>\n"
						"\t\t\t\t";
				#line 26 "Problem.tmpl"
				} // end of item
				#line 27 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t";
			#line 27 "Problem.tmpl"
			 } else {
				#line 29 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\tNo hay aclaraciones\n"
					"\t\t\t";
			#line 29 "Problem.tmpl"
			} // end of empty
			#line 31 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<h2>Solucion</h2>\n"
				"\t\t\t";
			#line 31 "Problem.tmpl"
			if(content.problem->is_solved) {
				#line 32 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t<div class= \"publication\" onclick=\"location.href='/pci/solution/";
				#line 32 "Problem.tmpl"
				out()<<cppcms::filters::escape(content.accepted_solution->id);
				#line 33 "Problem.tmpl"
				out()<<"'\">\n"
					"\t\t\t\t\tDescripcion: ";
				#line 33 "Problem.tmpl"
				out()<<cppcms::filters::escape(content.accepted_solution->description);
				#line 35 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t</div>\n"
					"\t\t\t";
			#line 35 "Problem.tmpl"
			}else{
				#line 37 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t<p>No hay una solucion aceptada</p>\n"
					"\t\t\t";
			#line 37 "Problem.tmpl"
			}
			#line 39 "Problem.tmpl"
			out()<<"\n"
				"\t\t\t<h2>Soluciones Propuestas</h2>\n"
				"\t\t\t";
			#line 39 "Problem.tmpl"
			if((*content.solutions).begin()!=(*content.solutions).end()) {
				#line 40 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t";
				#line 40 "Problem.tmpl"
				for(CPPCMS_TYPEOF((*content.solutions).begin()) solution_ptr=(*content.solutions).begin(),solution_ptr_end=(*content.solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 40 "Problem.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 41 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t<div class = \"publication\" onclick=\"location.href='/pci/solution/";
					#line 41 "Problem.tmpl"
					out()<<cppcms::filters::escape(solution->id);
					#line 42 "Problem.tmpl"
					out()<<"'\">\n"
						"\t\t\t\t\t\tID: ";
					#line 42 "Problem.tmpl"
					out()<<cppcms::filters::escape(solution->id);
					#line 42 "Problem.tmpl"
					out()<<" Descripcion: ";
					#line 42 "Problem.tmpl"
					out()<<cppcms::filters::escape(solution->description);
					#line 44 "Problem.tmpl"
					out()<<"\n"
						"\t\t\t\t\t</div>\n"
						"\t\t\t\t";
				#line 44 "Problem.tmpl"
				} // end of item
				#line 45 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\t";
			#line 45 "Problem.tmpl"
			 } else {
				#line 47 "Problem.tmpl"
				out()<<"\n"
					"\t\t\t\tNo hay soluciones propuestas\n"
					"\t\t\t";
			#line 47 "Problem.tmpl"
			} // end of empty
			#line 48 "Problem.tmpl"
			out()<<"\n"
				"\t\t";
		#line 48 "Problem.tmpl"
		} // end of template body_content
	#line 50 "Problem.tmpl"
	}; // end of class problem_view
#line 51 "Problem.tmpl"
} // end of namespace test_skin
#line 2 "Solution.tmpl"
#include "ViewContent.h" 
#line 4 "Solution.tmpl"
namespace test_skin {
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
		#line 7 "Solution.tmpl"
		virtual void head_links() {
			#line 8 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 8 "Solution.tmpl"
			template_view::head_links();
			#line 10 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/solution.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 10 "Solution.tmpl"
		} // end of template head_links
		#line 12 "Solution.tmpl"
		virtual void body_content() {
			#line 13 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t<h1>Solucion ";
			#line 13 "Solution.tmpl"
			out()<<cppcms::filters::escape(content.solution->id);
			#line 16 "Solution.tmpl"
			out()<<"</h1>\n"
				"\t\t\t<div class = \"button_wrapper\">\n"
				"\t\t\t\t<div class = \"publication\">\n"
				"\t\t\t\t\tDescripcion: ";
			#line 16 "Solution.tmpl"
			out()<<cppcms::filters::escape(content.solution->description);
			#line 20 "Solution.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t<h2>Aclaraciones</h2>\n"
				"\t\t\t";
			#line 20 "Solution.tmpl"
			if((*content.clarifications).begin()!=(*content.clarifications).end()) {
				#line 21 "Solution.tmpl"
				out()<<"\n"
					"\t\t\t\t";
				#line 21 "Solution.tmpl"
				for(CPPCMS_TYPEOF((*content.clarifications).begin()) clarification_ptr=(*content.clarifications).begin(),clarification_ptr_end=(*content.clarifications).end();clarification_ptr!=clarification_ptr_end;++clarification_ptr) {
				#line 21 "Solution.tmpl"
				CPPCMS_TYPEOF(*clarification_ptr) &clarification=*clarification_ptr;
					#line 23 "Solution.tmpl"
					out()<<"\n"
						"\t\t\t\t\t<div class = \"publication\">\n"
						"\t\t\t\t\t\tID: ";
					#line 23 "Solution.tmpl"
					out()<<cppcms::filters::escape(clarification->id);
					#line 23 "Solution.tmpl"
					out()<<" Pregunta: ";
					#line 23 "Solution.tmpl"
					out()<<cppcms::filters::escape(clarification->question);
					#line 24 "Solution.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\tRespuesta: ";
					#line 24 "Solution.tmpl"
					out()<<cppcms::filters::escape(clarification->answer);
					#line 26 "Solution.tmpl"
					out()<<"\n"
						"\t\t\t\t\t</div>\n"
						"\t\t\t\t";
				#line 26 "Solution.tmpl"
				} // end of item
				#line 27 "Solution.tmpl"
				out()<<"\n"
					"\t\t\t\t";
			#line 27 "Solution.tmpl"
			 } else {
				#line 29 "Solution.tmpl"
				out()<<"\n"
					"\t\t\t\tNo hay aclaraciones\n"
					"\t\t\t";
			#line 29 "Solution.tmpl"
			} // end of empty
			#line 30 "Solution.tmpl"
			out()<<"\n"
				"\t\t";
		#line 30 "Solution.tmpl"
		} // end of template body_content
	#line 32 "Solution.tmpl"
	}; // end of class solution_view
#line 33 "Solution.tmpl"
} // end of namespace test_skin
#line 2 "Ideas.tmpl"
#include "ViewContent.h" 
#line 4 "Ideas.tmpl"
namespace test_skin {
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
		#line 7 "Ideas.tmpl"
		virtual void head_links() {
			#line 8 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t";
			#line 8 "Ideas.tmpl"
			template_view::head_links();
			#line 10 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<link href=\"/css/ideas.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
				"\t\t";
		#line 10 "Ideas.tmpl"
		} // end of template head_links
		#line 12 "Ideas.tmpl"
		virtual void body_content() {
			#line 14 "Ideas.tmpl"
			out()<<"\n"
				"\t\t\t<h1>Ideas</h1>\n"
				"\t\t";
		#line 14 "Ideas.tmpl"
		} // end of template body_content
	#line 16 "Ideas.tmpl"
	}; // end of class ideas_view
#line 17 "Ideas.tmpl"
} // end of namespace test_skin
#line 18 "Ideas.tmpl"
namespace {
#line 18 "Ideas.tmpl"
 cppcms::views::generator my_generator; 
#line 18 "Ideas.tmpl"
 struct loader { 
#line 18 "Ideas.tmpl"
  loader() { 
#line 18 "Ideas.tmpl"
   my_generator.name("test_skin");
#line 18 "Ideas.tmpl"
   my_generator.add_view<test_skin::template_view,ViewContent::TemplateContent>("template_view",true);
#line 18 "Ideas.tmpl"
   my_generator.add_view<test_skin::welcome_view,ViewContent::WelcomeContent>("welcome_view",true);
#line 18 "Ideas.tmpl"
   my_generator.add_view<test_skin::sign_in_view,ViewContent::SignInContent>("sign_in_view",true);
#line 18 "Ideas.tmpl"
   my_generator.add_view<test_skin::problems_view,ViewContent::ProblemsContent>("problems_view",true);
#line 18 "Ideas.tmpl"
   my_generator.add_view<test_skin::problem_view,ViewContent::ProblemContent>("problem_view",true);
#line 18 "Ideas.tmpl"
   my_generator.add_view<test_skin::solution_view,ViewContent::SolutionContent>("solution_view",true);
#line 18 "Ideas.tmpl"
   my_generator.add_view<test_skin::ideas_view,ViewContent::IdeasContent>("ideas_view",true);
#line 18 "Ideas.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 18 "Ideas.tmpl"
 }
#line 18 "Ideas.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 18 "Ideas.tmpl"
} a_loader;
#line 18 "Ideas.tmpl"
} // anon 
