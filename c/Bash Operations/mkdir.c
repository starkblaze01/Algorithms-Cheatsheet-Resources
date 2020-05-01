void makedir(char* argv[]) {
	// execute when -v is passed as flag
	if(strcmp(argv[1],"-v")==0){	                                             // 'v' stands for verbose which prints a message. 
		const int dir_err = mkdir(argv[2] ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);  // modes to provide all permissions except 	
   		if (-1 == dir_err) {                                                      // writing permisson for 'others '   
			perror("Error creating directory!\n");                                    // -1 is returned by mkdir when directory 
    	    }                                                                     //is not created.    
		else {                                                                    // perror handles the errors , if any.    
		        printf("Directory %s created successfully!\n",argv[2]);	             
			}                                                                           
    } 
	
	// execute when -p is passed as flag
	else if(strcmp(argv[1],"-p")==0){	                                          // 'p' stands for path (absolute)         
		const int dir_err = mkdir(argv[2] ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	// all permissions execpt writing for 
   		if (-1 == dir_err) {                                                       // 'others'
			perror("Error creating directory!\n");
    	    } 
    } 
	
	// deafult execution case
	else{	
		const int dir_err = mkdir(argv[1] ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	//  all permissions except writing for
		if (-1 == dir_err) {                                                        // others  
		perror("Error creating directory!\n");
		} 
    } 
}
