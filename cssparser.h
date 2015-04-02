#ifndef CSSPARSER_H
#define CSSPARSER_H

#include <stdio.h>

void cssparser_handle_id_selector(char* id)
{
    fprintf(stderr, "id %s\n", id);
}

void cssparser_handle_class_selector(char* cssclass)
{
    fprintf(stderr, "class %s\n", cssclass);
}

void cssparser_handle_type_selector(char* type)
{
    fprintf(stderr, "type %s\n", type);
}

void cssparser_handle_empty_attribute_selector(char* attribute)
{
    fprintf(stderr, "attr %s\n", attribute);
}

void cssparser_handle_attribute_selector(char* attribute, char* cssoperator, char* value)
{
    fprintf(stderr, "attr %s %s %s\n", attribute, cssoperator, value);
}

void cssparser_handle_charset(char* charset)
{
    fprintf(stderr, "charset %s\n", charset);
}

#endif // CSSPARSER_H

