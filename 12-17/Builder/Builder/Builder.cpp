#include "Builder.h"

void Director::convertXML(){
	ConverterXML *converter = new ConverterXML();
	converter->convert(filename);
}

void Director::ConverterXML::convert(std::string name){
	toXML(name);
}
