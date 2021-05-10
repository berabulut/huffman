#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "fields.h"
#include "jrb.h"
#include "jval.h"


char* getString(char *line,int beginIndex,int endIndex){
	char text[endIndex - beginIndex];
	text[endIndex - beginIndex - 1] = '\0';
	int sayac = 0;
	for(int i = beginIndex + 1 ; i < endIndex;i++){
		text[sayac++] = line[i];
	}
	
	return strdup(text);
}

void ReadDocument(IS is, JRB b,JRB bn, int option){
 	while(get_line(is) >= 0){
  		int sayac = 0;
  		char *key,*value;
  		int array[4],arrayIndex = 0;
  	
  		while(is->text1[sayac] != '\0'){
  			char ch = is->text1[sayac];
  			if(ch== '"'){ 
  				array[arrayIndex++] = sayac;
  			}
  			sayac++;
  		}
  		if(arrayIndex >= 3){
  			key = getString(is->text1,array[0],array[1]);
  			value = getString(is->text1,array[2],array[3]);		
  			
			if(option == 0)	
				(void) jrb_insert_str(b,strdup(key),new_jval_v(value));				
				
			if(option == 1)
				(void) jrb_insert_str(b,strdup(value),new_jval_v(key));
		//printf("%s - ",key);
  		//printf("%s  \n",value);
		}
		
	}
}

void EnCoding(JRB b,JRB bn, IS is1, char *output_name)
{	
	FILE * fp;
	fp = fopen (output_name,"w");
	
	while(get_line(is1) >= 0){
		for (int i = 0; i < is1->NF; i++)
		{
			bn = jrb_find_str(b, is1->fields[i]);
			if (bn != NULL) {
        		fprintf(fp, "%s ",bn->val.s);
			}
		}
	}
	fclose (fp);
}

void DeCoding(JRB b,JRB bn, IS is2) 
{
	FILE * fp;
	fp = fopen ("decripted","w");

	
	while(get_line(is2) >= 0){

		for (int i = 0; i < is2->NF; i++)
		{	
			
			bn = jrb_find_str(b, is2->fields[i]);
			if (bn != NULL) {			
        		fprintf(fp, "%s ",bn->val.s);
			}
		}
	}
	fclose (fp);
}

int main(int argc, char **argv){
  
	printf("flag , %s\n", argv[1]);
	printf("in , %s\n", argv[2]);
	printf("o , %s\n", argv[3]);
    char *flag = argv[1];
	char *input_text = argv[2]; 
	char *output_text = argv[3]; 
	
  IS is = new_inputstruct(".kilit");
  IS is1 = new_inputstruct(input_text);
  JRB b,bn;
  b = make_jrb();
  if(strcmp(flag,"-e") == 0)
  {
    	ReadDocument(is,b, bn, 0);
  //	EnCoding(b,bn,is1,output_text);
  }
  else
  {
  //	ReadDocument(is,b, bn, 1);
 //	DeCoding(b,bn,is1);
  }
// ./Test -e ornek_metin2 encripted
// ./Test -d encripted decripted
//  jettison_inputstruct(is);
//  jettison_inputstruct(is1); 
  return 0;

}
