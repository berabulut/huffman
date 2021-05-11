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

void ReadDocument(JRB b,int option){
	IS is = new_inputstruct(".kilit");
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
		}
		
	}
	
  	jettison_inputstruct(is);
}

void EnCoding(char* fileName,JRB b,JRB bn)
{	
	FILE * fp;
	fp = fopen (fileName,"w");
	IS is = new_inputstruct(fileName);
	
	while(get_line(is) >= 0){
		for (int i = 0; i < is->NF; i++)
		{
			bn = jrb_find_str(b, is->fields[i]);
			if (bn != NULL) {
        		fprintf(fp, "%s ",bn->val.s);
			}
		}
	}
	fclose (fp);
}

void DeCoding(char* fileName,JRB b,JRB bn) 
{
	FILE * fp;
	fp = fopen (fileName,"w");
	
  	IS is = new_inputstruct(fileName);
	
	while(get_line(is) >= 0){

		for (int i = 0; i < is->NF; i++)
		{	
			
			bn = jrb_find_str(b, is->fields[i]);
			if (bn != NULL) {			
        		fprintf(fp, "%s ",bn->val.s);
			}
		}
	}
	jettison_inputstruct(is); 
	fclose (fp);

}


int main(int argc, char **argv){
  
  
  if (argc != 4) { fprintf(stderr, "usage: printwords filename\n"); exit(1); }
    char *flag = argv[1];
	char *input_fileName = argv[2]; 
	char *output_fileName = argv[3]; 
	
  
  JRB b,bn;
  b = make_jrb();
  if(strcmp(flag,"-e") == 0)
  {
    	ReadDocument(b,0);
  	EnCoding(output_fileName,b,bn);
  }
  else
  {
  	ReadDocument(b,1);
 	DeCoding(output_fileName,b,bn);
  }
  
  return 0;

}
