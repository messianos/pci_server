OUTPUT_FILE=pci_skin.cpp
OUTPUT_LIB=../lib/libpci_skin.so

cd ../tmpl

pwd

echo -- Building Templates from `pwd`...

cppcms_tmpl_cc 	entity/User.tmpl \
				pages/TemplatePage.tmpl \
				entity/Solution.tmpl \
				entity/Problem.tmpl \
				entity/Clarification.tmpl \
				pages/UserPage.tmpl \
				pages/ProblemPage.tmpl \
				pages/NewSolutionPage.tmpl \
				pages/IndexPage.tmpl \
				pages/IdeasPage.tmpl \
				pages/NewProblemPage.tmpl \
				pages/Error404Page.tmpl \
				pages/ProblemsPage.tmpl \
				pages/DebugPage.tmpl \
				pages/SolutionPage.tmpl \
				-o $OUTPUT_FILE;

echo -- Templates built to $OUTPUT_FILE

echo -- Building Dynamic Library...

g++ -shared -fPIC $OUTPUT_FILE -o $OUTPUT_LIB -lcppcms -lbooster

rm -f $OUTPUT_FILE

echo

echo Finished !!
