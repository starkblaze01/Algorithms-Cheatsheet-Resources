#define MAX_MSG_LEN 200    /* Maximum length of temporary string */
 
/* Define all the error messages */
char * error_msg[] = {
              "\nUsage: ./13lsl\n\n",
              "\nCould not retrieve the current working directory\n\n",
              "\nCould not open the current working directory\n\n",
              "\nError doing 'stat' on file\n\n",
              "\nCould not scan the directory\n\n"
       };
 
void print_error(int msg_num, int exit_code);
 
int lsdetailed(char * path)
{
       int i;      		                   /* A counter */
       char msg[MAX_MSG_LEN] = "";       /* A temporary string */
       struct passwd * passwd_details;   /* Structure to retrieve user name */
       struct group * group_details;     /* Structure to retrieve group name */
       struct tm * tmptime;              /* To store file modification time in 'tm' struc */
       char time_str[MAX_MSG_LEN];       /* String representation of time */
       char mode_str[11];                /* String to hold file type and permissions */
       mode_t file_perm;                 /* File permissions */
       DIR * dir_to_read;                /* Handle to directory to be read */
       struct dirent ** dir_entry;       /* Array to hold individual entries of dir sorted */
       int num_entries;                  /* Number of entries in the directory */
       struct stat file_details;         /* Detailed file info */
       char * cur_work_dir = path;       /* String to hold current working directory name */
       char success_msg[] = "\nCommand executed successfully\n\n";

       /* Open the current working directory */
       if ( (dir_to_read = opendir(cur_work_dir)) == NULL )
					print_error(2,4);
             
       /* Get the current directory alphabetically sorted */
       if ( (num_entries = scandir(cur_work_dir, &dir_entry, 0, alphasort)) < 0 )
              print_error(4,6);
       else
       {
              /* Loop through sorted current working directory and display each file
              name till all the entries are exhausted */
              for ( i = 0; i < num_entries; i++ )
              {	
				char * fname = dir_entry[i]->d_name;
				if(fname[0] == '.') {
					continue;		
				}
				
                 /* Retrieve the file details */
                 if (lstat(dir_entry[i]->d_name,&file_details) < 0)
                       print_error(3,5);
                      
                 /* Prepare the mode string */
         
                 /* Get the file type */
                 if ( S_ISREG(file_details.st_mode) ) strcpy(mode_str,"-");
                 else if ( S_ISDIR(file_details.st_mode) ) strcpy(mode_str,"d");
                 else if ( S_ISLNK(file_details.st_mode) ) strcpy(mode_str,"l");
                 else strcpy(mode_str,"?");
         
                 /* Get the octal file permissions */
                 file_perm = file_details.st_mode & ~S_IFMT;
                 if ( file_perm & S_IRUSR )
                       strcat(mode_str,"r");
                 else
                       strcat(mode_str,"-");
                 if ( file_perm & S_IWUSR )
                       strcat(mode_str,"w");
                 else
                       strcat(mode_str,"-");
                 if ( file_perm & S_IXUSR )
                       strcat(mode_str,"x");
                 else
                       strcat(mode_str,"-");
                 if ( file_perm & S_IRGRP )
                       strcat(mode_str,"r");
                 else
                       strcat(mode_str,"-");
                 if ( file_perm & S_IWGRP )
                       strcat(mode_str,"w");
                 else
                       strcat(mode_str,"-");
                 if ( file_perm & S_IXGRP )
                       strcat(mode_str,"x");
                 else
                       strcat(mode_str,"-");
                 if ( file_perm & S_IROTH )
                       strcat(mode_str,"r");
                 else
                       strcat(mode_str,"-");
                 if ( file_perm & S_IWOTH )
                       strcat(mode_str,"w");
                 else
                       strcat(mode_str,"-");
                 if ( file_perm & S_IXOTH )
                       strcat(mode_str,"x");
                 else
                       strcat(mode_str,"-");
         
                 /* Initialize the temporary string 'msg' */
                 strcpy(msg,"");
         
                 /* Get the file permissions in temporary string 'msg' */
                 sprintf(msg,"%s%s ",msg,mode_str);
         
                 /* Get the number of links */
                 sprintf(msg,"%s%d ",msg,(int)file_details.st_nlink);

                 /* Get the User name */
                 passwd_details = getpwuid(file_details.st_uid);
                 sprintf(msg,"%s%s ",msg,passwd_details->pw_name);
         
                 /* Get the Group name */
                 group_details = getgrgid(file_details.st_gid);
                 sprintf(msg,"%s%s ",msg,group_details->gr_name);
         
                 /* Get the size of the file */
                 sprintf(msg,"%s%6d ",msg,(int)file_details.st_size);
         
                 /* Get the last modification time of the file */
                 tmptime = localtime(&file_details.st_mtime);
                 strftime(time_str, sizeof(time_str), "%F %R", tmptime);
                 sprintf(msg,"%s%s ",msg,time_str);

                 /* Get the file name */
                 sprintf(msg,"%s%s\n",msg,dir_entry[i]->d_name);
         
                 /* Display file details */
               	printf("%s",msg);

              } /* end for */
       } /* end else */
       printf("%s", success_msg);
       return 1;
}
 
void print_error(int error_index, int exit_code)
{
       fprintf(stderr, "%s", error_msg[error_index]);
       exit(exit_code);
}
