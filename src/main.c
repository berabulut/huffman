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


int main(){

  IS is = new_inputstruct("test.json");
  JRB b,bn;
  b = make_jrb();
  
  
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
  		
  		(void) jrb_insert_str(b,strdup(value),new_jval_v(key));
  		
  		
  		//printf("%s - ",key);
  		//printf("%s  \n",value);
	}
}

	jrb_traverse(bn,b){
		printf("%s : %s\n",bn->key.s,bn->val.s);
	}


  jettison_inputstruct(is);
  return 0;

}
