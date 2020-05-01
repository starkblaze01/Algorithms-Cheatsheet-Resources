// Method to print path of current directory
char *print_working_directory() {

	long size;	// Variable to store length of the absolute path of the directory
	char *buffer;	// Buffer to allocate memory to store path
	char *path;	// Pointer to store pathname

	// pathconf() function returns length of pathname of the current working directory
	size = pathconf(".", _PC_PATH_MAX);

	// Buffer allocates memory of size of pathmane and returns the pointer with pathname to path variable
	if ( (buffer = (char *) malloc( (size_t)size) ) != NULL)
		path = getcwd(buffer, (size_t)size);

	free(buffer);

	return path;
}	
