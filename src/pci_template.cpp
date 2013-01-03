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
				"\t    <link href=\"css/basic_style.css\" rel=\"stylesheet\" type=\"text/css\">\n"
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
#line 25 "pci_template.tmpl"
} // end of namespace main_screen_skin
#line 25 "pci_template.tmpl"
namespace {
#line 25 "pci_template.tmpl"
 cppcms::views::generator my_generator; 
#line 25 "pci_template.tmpl"
 struct loader { 
#line 25 "pci_template.tmpl"
  loader() { 
#line 25 "pci_template.tmpl"
   my_generator.name("main_screen_skin");
#line 25 "pci_template.tmpl"
   my_generator.add_view<main_screen_skin::welcome,main_screen_content::content>("welcome",true);
#line 25 "pci_template.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 25 "pci_template.tmpl"
 }
#line 25 "pci_template.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 25 "pci_template.tmpl"
} a_loader;
#line 25 "pci_template.tmpl"
} // anon 
