#line 1 "pci_template.tmpl"
#include "main_screen_content.h" 
#line 2 "pci_template.tmpl"
namespace main_screen_skin {
	#line 3 "pci_template.tmpl"
	struct welcome :public cppcms::base_view
	#line 3 "pci_template.tmpl"
	{
	#line 3 "pci_template.tmpl"
		main_screen_content::content &content;
	#line 3 "pci_template.tmpl"
		welcome(std::ostream &_s,main_screen_content::content &_content): cppcms::base_view(_s),content(_content)
	#line 3 "pci_template.tmpl"
		{
	#line 3 "pci_template.tmpl"
		}
		#line 4 "pci_template.tmpl"
		virtual void render() {
			#line 11 "pci_template.tmpl"
			out()<<"  \n"
				"<html> \n"
				"\t<head>\n"
				"\t    <link href=\"/css/basic_style.css\" rel=\"stylesheet\" type=\"text/css\">\n"
				"\t</head>\n"
				"\t<body>\n"
				"\t\t<div class=\"content\">\n"
				"\t\t\t<h1>Bienvenido ";
			#line 11 "pci_template.tmpl"
			out()<<cppcms::filters::escape(content.user_id);
			#line 23 "pci_template.tmpl"
			out()<<"!</h1>\n"
				"\t\t\t<div class = \"button_wrapper\">\n"
				"\t\t\t\t<div class = \"big_button\" id=\"problems\" onclick=\"location.href='/pci/problemsHome'\">\n"
				"\t\t\t\t\tProblemas\n"
				"\t\t\t\t</div>\n"
				"\t\t\t\t<div class = \"big_button\" id=\"ideas\" onclick=\"location.href='/pci/ideasHome'\">\n"
				"\t\t\t\t\tIdeas\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t</div>\n"
				"\t</body>  \n"
				"<html>  \n"
				"";
		#line 23 "pci_template.tmpl"
		} // end of template render
	#line 24 "pci_template.tmpl"
	}; // end of class welcome
	#line 26 "pci_template.tmpl"
	struct problemsHome :public cppcms::base_view
	#line 26 "pci_template.tmpl"
	{
	#line 26 "pci_template.tmpl"
		main_screen_content::problemsHome &content;
	#line 26 "pci_template.tmpl"
		problemsHome(std::ostream &_s,main_screen_content::problemsHome &_content): cppcms::base_view(_s),content(_content)
	#line 26 "pci_template.tmpl"
		{
	#line 26 "pci_template.tmpl"
		}
		#line 27 "pci_template.tmpl"
		virtual void render() {
			#line 36 "pci_template.tmpl"
			out()<<"\n"
				"<html> \n"
				"\t<head>\n"
				"\t    <link href=\"/css/problemsHome.css\" rel=\"stylesheet\" type=\"text/css\">\n"
				"\t</head>\n"
				"\t<body>\n"
				"\t\t<div class=\"content\">\n"
				"\t\t\t<h1>Problemas</h1>\n"
				"\t\t\t<div class = \"button_wrapper\">\n"
				"\t\t\t\t";
			#line 36 "pci_template.tmpl"
			if((*content.problems).begin()!=(*content.problems).end()) {
				#line 37 "pci_template.tmpl"
				out()<<"  \n"
					" \t\t\t\t\t";
				#line 37 "pci_template.tmpl"
				for(CPPCMS_TYPEOF((*content.problems).begin()) problem_ptr=(*content.problems).begin(),problem_ptr_end=(*content.problems).end();problem_ptr!=problem_ptr_end;++problem_ptr) {
				#line 37 "pci_template.tmpl"
				CPPCMS_TYPEOF(*problem_ptr) &problem=*problem_ptr;
					#line 38 "pci_template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t<div class = \"publication\" onclick=\"location.href='/pci/problem/";
					#line 38 "pci_template.tmpl"
					out()<<cppcms::filters::escape(problem->id);
					#line 39 "pci_template.tmpl"
					out()<<"'\">\n"
						"\t\t\t\t\t\t\t";
					#line 39 "pci_template.tmpl"
					out()<<cppcms::filters::escape(problem->id);
					#line 39 "pci_template.tmpl"
					out()<<":";
					#line 39 "pci_template.tmpl"
					out()<<cppcms::filters::escape(problem->description);
					#line 41 "pci_template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\t</div>  \n"
						"  \t\t\t\t\t";
				#line 41 "pci_template.tmpl"
				} // end of item
				#line 42 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\t\t";
			#line 42 "pci_template.tmpl"
			 } else {
				#line 44 "pci_template.tmpl"
				out()<<"  \n"
					"  \t\t\t\t\t<h2>No problems</h2>\n"
					"\t\t\t\t";
			#line 44 "pci_template.tmpl"
			} // end of empty
			#line 49 "pci_template.tmpl"
			out()<<"\n"
				"\t\t\t</div>\n"
				"\t\t</div>\n"
				"\t</body>  \n"
				"<html>  \n"
				"";
		#line 49 "pci_template.tmpl"
		} // end of template render
	#line 50 "pci_template.tmpl"
	}; // end of class problemsHome
	#line 52 "pci_template.tmpl"
	struct problemInfo :public cppcms::base_view
	#line 52 "pci_template.tmpl"
	{
	#line 52 "pci_template.tmpl"
		main_screen_content::problemInfo &content;
	#line 52 "pci_template.tmpl"
		problemInfo(std::ostream &_s,main_screen_content::problemInfo &_content): cppcms::base_view(_s),content(_content)
	#line 52 "pci_template.tmpl"
		{
	#line 52 "pci_template.tmpl"
		}
		#line 53 "pci_template.tmpl"
		virtual void render() {
			#line 60 "pci_template.tmpl"
			out()<<"\n"
				"<html> \n"
				"\t<head>\n"
				"\t    <link href=\"/css/problemsHome.css\" rel=\"stylesheet\" type=\"text/css\">\n"
				"\t</head>\n"
				"\t<body>\n"
				"\t\t<div class=\"content\">\n"
				"\t\t\t<h1>Problema ";
			#line 60 "pci_template.tmpl"
			out()<<cppcms::filters::escape(content.problem->id);
			#line 63 "pci_template.tmpl"
			out()<<"</h1>\n"
				"\t\t\t<div class = \"button_wrapper\">\n"
				"\t\t\t\t<div class = \"publication\">\n"
				"\t\t\t\t\tDescripcion: ";
			#line 63 "pci_template.tmpl"
			out()<<cppcms::filters::escape(content.problem->description);
			#line 67 "pci_template.tmpl"
			out()<<"\n"
				"\t\t\t\t</div>\n"
				"\t\t\t</div>\n"
				"\t\t\t<h2>Aclaraciones</h2>\n"
				"\t\t\t";
			#line 67 "pci_template.tmpl"
			if((*content.clarifications).begin()!=(*content.clarifications).end()) {
				#line 68 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\t";
				#line 68 "pci_template.tmpl"
				for(CPPCMS_TYPEOF((*content.clarifications).begin()) clarification_ptr=(*content.clarifications).begin(),clarification_ptr_end=(*content.clarifications).end();clarification_ptr!=clarification_ptr_end;++clarification_ptr) {
				#line 68 "pci_template.tmpl"
				CPPCMS_TYPEOF(*clarification_ptr) &clarification=*clarification_ptr;
					#line 70 "pci_template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t<div class = \"publication\">\n"
						"\t\t\t\t\t\tID: ";
					#line 70 "pci_template.tmpl"
					out()<<cppcms::filters::escape(clarification->id);
					#line 70 "pci_template.tmpl"
					out()<<" Pregunta: ";
					#line 70 "pci_template.tmpl"
					out()<<cppcms::filters::escape(clarification->question);
					#line 71 "pci_template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t\tRespuesta: ";
					#line 71 "pci_template.tmpl"
					out()<<cppcms::filters::escape(clarification->answer);
					#line 73 "pci_template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t</div>\n"
						"\t\t\t\t";
				#line 73 "pci_template.tmpl"
				} // end of item
				#line 74 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\t";
			#line 74 "pci_template.tmpl"
			 } else {
				#line 76 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\tNo hay aclaraciones\n"
					"\t\t\t";
			#line 76 "pci_template.tmpl"
			} // end of empty
			#line 78 "pci_template.tmpl"
			out()<<"\n"
				"\t\t\t<h2>Solucion</h2>\n"
				"\t\t\t";
			#line 78 "pci_template.tmpl"
			if(content.problem->is_solved) {
				#line 80 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\t<div class= \"publication\">\n"
					"\t\t\t\t\tDescripcion: ";
				#line 80 "pci_template.tmpl"
				out()<<cppcms::filters::escape(content.accepted_solution->description);
				#line 82 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\t</div>\n"
					"\t\t\t";
			#line 82 "pci_template.tmpl"
			}else{
				#line 84 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\t<p>No hay una solucion aceptada</p>\n"
					"\t\t\t";
			#line 84 "pci_template.tmpl"
			}
			#line 86 "pci_template.tmpl"
			out()<<"\n"
				"\t\t\t<h2>Soluciones Propuestas</h2>\n"
				"\t\t\t";
			#line 86 "pci_template.tmpl"
			if((*content.solutions).begin()!=(*content.solutions).end()) {
				#line 87 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\t";
				#line 87 "pci_template.tmpl"
				for(CPPCMS_TYPEOF((*content.solutions).begin()) solution_ptr=(*content.solutions).begin(),solution_ptr_end=(*content.solutions).end();solution_ptr!=solution_ptr_end;++solution_ptr) {
				#line 87 "pci_template.tmpl"
				CPPCMS_TYPEOF(*solution_ptr) &solution=*solution_ptr;
					#line 89 "pci_template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t<div class = \"publication\">\n"
						"\t\t\t\t\t\tID: ";
					#line 89 "pci_template.tmpl"
					out()<<cppcms::filters::escape(solution->id);
					#line 89 "pci_template.tmpl"
					out()<<" Descripcion: ";
					#line 89 "pci_template.tmpl"
					out()<<cppcms::filters::escape(solution->description);
					#line 91 "pci_template.tmpl"
					out()<<"\n"
						"\t\t\t\t\t</div>\n"
						"\t\t\t\t";
				#line 91 "pci_template.tmpl"
				} // end of item
				#line 92 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\t";
			#line 92 "pci_template.tmpl"
			 } else {
				#line 94 "pci_template.tmpl"
				out()<<"\n"
					"\t\t\t\tNo hay soluciones propuestas\n"
					"\t\t\t";
			#line 94 "pci_template.tmpl"
			} // end of empty
			#line 98 "pci_template.tmpl"
			out()<<"\n"
				"\t\t</div>\n"
				"\t</body>  \n"
				"<html>  \n"
				"";
		#line 98 "pci_template.tmpl"
		} // end of template render
	#line 99 "pci_template.tmpl"
	}; // end of class problemInfo
#line 100 "pci_template.tmpl"
} // end of namespace main_screen_skin
#line 100 "pci_template.tmpl"
namespace {
#line 100 "pci_template.tmpl"
 cppcms::views::generator my_generator; 
#line 100 "pci_template.tmpl"
 struct loader { 
#line 100 "pci_template.tmpl"
  loader() { 
#line 100 "pci_template.tmpl"
   my_generator.name("main_screen_skin");
#line 100 "pci_template.tmpl"
   my_generator.add_view<main_screen_skin::welcome,main_screen_content::content>("welcome",true);
#line 100 "pci_template.tmpl"
   my_generator.add_view<main_screen_skin::problemsHome,main_screen_content::problemsHome>("problemsHome",true);
#line 100 "pci_template.tmpl"
   my_generator.add_view<main_screen_skin::problemInfo,main_screen_content::problemInfo>("problemInfo",true);
#line 100 "pci_template.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 100 "pci_template.tmpl"
 }
#line 100 "pci_template.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 100 "pci_template.tmpl"
} a_loader;
#line 100 "pci_template.tmpl"
} // anon 
