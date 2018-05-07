//desc : change case ::tolower || ::toupper
void transform(sour.begin(), sour.end(), des.begin(), ::toupper);

//desc : search substr
//time : strlen(sour) * strlen(des)
char * strstr(char *sour, const char *des);  //case sensitive
char * stristr(char *sour, const char *des); //case insensitive
