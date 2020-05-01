// Comprehensive function to force delete a directory by unlinking it's contents

int rm(char *path){   		// "path"- parameter passing for directory to be removed
   DIR *d = opendir(path);  		// Move to the desired path to remove directory
   size_t path_len = strlen(path);  // length of path
   int r = -1;  					// Status variable 
   if (d){    						// if the path exists
      struct dirent *p;		// in-built dirent structure (used only d_name attribute for validity, permissions of file)
      r = 0;   							// Status variable
      while (!r && (p=readdir(d))){    //  execute the loop until the directory isn't empty 
          int r2 = -1;  			// status variable 
          char *buf; 					// storing and updating the current path in this variable
          size_t len;					// for pathlen


          if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, "..")){   // Check for "." & ".." files ; if found, continue
             continue;  // don't remove the above files i.e skip the current iteration
          }
          len = path_len + strlen(p->d_name) + 2;  //   "+2" for '/' in between and a null char at end
          buf = malloc(len);  // Allocate memory at runtime
          if (buf){          // If block statement for checking and deleting file/directory
             struct stat statbuf;  // in-built statbuf structure (used only st_mode attribute for validity, permissions of directory )
             snprintf(buf, len, "%s/%s", path, p->d_name); // // Print Formatted Data to Buffer i.e complete path length in buf	
             if (!stat(buf, &statbuf)){    // check if at the given path file is present or not
                if (S_ISDIR(statbuf.st_mode)){    // Check for valid permissions of directory
                   r2 = rm(buf);    // remove directory ----- NOTE: RECURSIVE CALL HERE
                }
                else{
                   r2 = unlink(buf);    // unlink command for deleting files
                }
             }
             free(buf);     // Free the allocated memory so as it can be used the next time the rmdir command is executed
          }
          r = r2;  // updating the status variable
      }
      closedir(d);  //trace back to the original path
   }

   if (!r){
      r = rmdir(path);    // if r!=0 or the outermost directory hasn't been deleted, remove it  
   }
	return r;
}


// function to remove directory with tags handling
void remove_directory(char * argv[]) { 	

	// when -r is passed as tag, force delete
	if(strcmp(argv[1],"-r")==0 && strcmp(argv[0],"rm")==0){
		int d=rm(argv[2]);
		if(d!=0)
		perror("Directory not found\n");
	}

	// -v is being passed as tag
	else if(strcmp(argv[1],"-v")==0){	
		DIR *d = opendir(argv[2]);
		int ret=remove(argv[2]);
		if( ret != 0 )
		perror( "Error deleting file" );
		else
		printf( "Directory %s successfully deleted\n", argv[2] );	 		
    } 
	
	// -p is passed  as tag
	else if(strcmp(argv[1],"-p")==0){	
		DIR *d = opendir(argv[2]);
		int ret=remove(argv[2]);
		if( ret != 0 )
		perror( "Error deleting file" );
	} 
	
	// default execution i.e no tags
	else{
		DIR *d  = opendir(argv[1]);
		int ret = remove(argv[1]);
		if( ret != 0 )
			perror( "Error deleting file" );
	} 
}
