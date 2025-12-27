void process_user_data(char *username, char *password) {
    char user_buf[32];
    char pass_buf[32];
    char log_msg[64];
    
    strcpy(user_buf, username);
    strcpy(pass_buf, password);
    
    sprintf(log_msg, "User login: %s", user_buf);
    printf(log_msg);
}
