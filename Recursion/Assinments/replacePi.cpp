


void replacePi(char input[]) {
	
	if(input[0]=='\0'){
		return;
	}
	if(input[1]=='\0'){
		return;
	}
	
	replacePi(input+1);
	if(input[0]=='p' && input[1]=='i'){
		int n=0;
		for(int i=0; input[i]!='\0'; i++){
			n++;
		}
		for(int i=n-1; i>=0; i--){
			input[i+2]=input[i];
		}
		input[0]='3';
		input[1]='.';
		input[2]='1';
		input[3]='4';
	}
	return;
}


