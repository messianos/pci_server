OUTPUT_FILE=../src/pci_skin.cpp
OUTPUT_LIB=lib/libpci_skin.so

cd ../tmpl

pwd

echo -- Building Templates from `pwd`...

cppcms_tmpl_cc Template.tmpl Index.tmpl SignIn.tmpl SignUp.tmpl Problems.tmpl Problem.tmpl NewProblem.tmpl Profile.tmpl Solution.tmpl Ideas.tmpl -o $OUTPUT_FILE

echo -- Templates built to $OUTPUT_FILE

echo -- Building Dynamic Library...

g++ -shared -fPIC $OUTPUT_FILE -o $OUTPUT_LIB -lcppcms -lbooster

echo

echo Finished !!
