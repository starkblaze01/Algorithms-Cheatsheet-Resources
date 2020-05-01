// Define the color codes as macros 
#define RESET_COLOR "\e[m" // Restore default terminal text color
#define MAKE_GREEN "\e[32m" // Green color for executables
#define MAKE_BLUE "\e[36m" // Blue color for folders

// function to list files/directories in the current directory
void ls(char* currdir, int flag)
{	
	// variables to hold current directory, DIR pointer, dirent structs and a counter
	char *curr_dir = NULL; 
	DIR *dp = NULL; 
	struct dirent *dptr = NULL; 
	unsigned int i = 0; 
	int totalEntries;
	struct dirent ** dir_entry;	

	// winsize : window attributes
	// FILENO : file number
	// GWINSZ : get window size and passed w's address
	struct winsize w; 
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); 

	curr_dir = currdir; 
	if(NULL == curr_dir) { 
		printf("\n ERROR : Could not get the working directory\n"); 
	} 

	dp = opendir((const char*)curr_dir);    
	if(NULL == dp) { 
		printf("\n ERROR : Could not open the working directory\n"); 
	} 
	
	if ( (totalEntries = scandir(curr_dir, &dir_entry, 0, alphasort)) < 0 )
		perror("Could not scan the current directory");
	
	// execute till dptr is reading the current directory
	for(i = 0; i < totalEntries; i++) { 
		if(dir_entry[i]->d_name[0] != '.') { 
			// Check if the file is executable 
			if(!access(dir_entry[i]->d_name,X_OK)) { // X_OK : file read successfully
				int fd = -1;
				// stat struct to handle file properties
				struct stat st; 
				
				// open in read-only with no permissions
				fd = open(dir_entry[i]->d_name, O_RDONLY, 0); 
				if(-1 == fd) { 
						printf("\n Opening file/Directory failed\n"); 

				} 
				
				// if file is read successfully write file attributes in st
				fstat(fd, &st);
				
				// Check if it actaully was a directory with execute 
				// permissions on it. 
				if(S_ISDIR(st.st_mode)) { 
					// If it was a directory, print it in Blue 
					printf(MAKE_BLUE"%s\n"RESET_COLOR,dir_entry[i]->d_name); 
				} 
				else {            
					// If it was a normal executable 
					// Print it in green 
					printf(MAKE_GREEN"%s\n"RESET_COLOR, dir_entry[i]->d_name); 
				} 
				close(fd); 
			} 
			else { 
				// No executable flag ON 
				// Print it in black(default) 
				printf("%s\n", dir_entry[i]->d_name); 
			} 
		}
		else if(flag)
			printf("%s\n", dir_entry[i]->d_name);
	} 
	printf("\n"); 


}
