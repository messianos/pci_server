OUTPUT_FILE=pci_skin.cpp
OUTPUT_LIB=../lib/libpci_skin.so

cd ../tmpl

pwd

echo -- Building Templates from `pwd`...

cppcms_tmpl_cc 	entity/Template.tmpl \
				pages/TemplatePage.tmpl \
				pages/ErrorPage.tmpl \
				-o $OUTPUT_FILE;

echo -- Templates built to $OUTPUT_FILE

echo -- Building Dynamic Library...

g++ -shared -fPIC $OUTPUT_FILE -o $OUTPUT_LIB -lcppcms -lbooster

rm -f $OUTPUT_FILE

echo

echo Finished !!
