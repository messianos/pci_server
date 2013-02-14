OUTPUT_FILE=pci_skin.cpp
OUTPUT_LIB=../lib/libpci_skin.so

cd ../tmpl

pwd

echo -- Building Templates from `pwd`...

cppcms_tmpl_cc Template.tmpl Debug.tmpl Index.tmpl Problems.tmpl Problem.tmpl NewProblem.tmpl User.tmpl Solution.tmpl NewSolution.tmpl Ideas.tmpl -o $OUTPUT_FILE

echo -- Templates built to $OUTPUT_FILE

echo -- Building Dynamic Library...

g++ -shared -fPIC $OUTPUT_FILE -o $OUTPUT_LIB -lcppcms -lbooster

rm -f $OUTPUT_FILE

echo

echo Finished !!
