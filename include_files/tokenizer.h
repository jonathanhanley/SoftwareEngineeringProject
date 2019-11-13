/*
CS3500 - Software Engineering Project

include_files/tokenizer.h

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/
#ifndef __TOKENIZER__
#define __TOKENIZER__

int startTokenizer();
void rest_output_files();
struct Output_type reset_struct(struct Output_type outputType);
void write_item_to_file(struct Output_type outputType);
struct Output_type convert_char_2_object(struct Output_type outputType, char character);
#endif
