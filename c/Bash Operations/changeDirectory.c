//Global Variables
char * currdir = NULL; //Stores current directory -> USED THROUGHOUT THE CODE
char * prevDir = NULL;// Stores previous directory


//Function to store previously opened path
char * storePreviousDirectory(char * dir){
	char * previous = (char * )malloc(100*sizeof(char));//Memory allocation
	strcpy(previous, dir);	//stores previous path in previous variable
	return previous;
}


//Funtion to concat two strings by efficiently allocating required memory.
//The normal concat function in C giving segmentation fault hence this function.
char * concat(const char *s1, const char *s2) {
	char *result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

//Changes the directory
char * changeDir(char * args[]){
	char * buff = (char *)malloc(100*sizeof(char));	//Buffer to send error message  if the directory doesn't exist.
	char * temp = (char *)malloc(100*sizeof(char));	//Temporarily stores value of current directory.
	strcpy(temp, currdir);
	temp = concat(temp, "/"); 
	temp = concat(temp, args[1]);
	//If directory doesn't exist, exit the function with error message
	//Also we must check that the user is not calling "cd -" because that returns the previously opened directory
	if(chdir(temp) == -1 && strcmp(args[1], "-")!=0){
		snprintf(buff, 100, "The directory %s doesn't exists", args[1]);//Puts the error message into buff and return but doesn't print.
		printf("The directory doesn't exist\n"); 
		return buff;
	}
	
	//If '-' return previous directory
	//else store this path in previous directory
	if(strcmp(args[1], "-")==0){
		chdir(prevDir);
		currdir = prevDir;
		return prevDir;
	}else{
		prevDir = storePreviousDirectory(currdir);
	}
	
	
	//If user types (cd ..) then return to the previous directory
	//Iterates upto previous '/' chatacter in the string to return the previous path
	if(strcmp(args[1],"..")==0){
		int l=strlen(currdir); 
		int i;
		for(i=l-1;currdir[i]!='/';i--){
			currdir[i]='\0';
		} 
		currdir[i]='\0';  
		return currdir;                         
	}

	// returns the current directory
	if(strcmp(args[1], ".") == 0)
		return currdir;

	
	//If user just types 'cd', go to home directory
	if(strcmp(args[1], "") == 0){
		chdir(getenv("HOME"));//getenv returns the root path, hence we change the current path
		getcwd(currdir, 100);
		return currdir;
	}
	
	currdir = temp;	//If the given path is valid, update the currdir path.
	return currdir;
}

