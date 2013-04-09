#include <stdio.h>
#include <mysql.h>
int main()
{
    MYSQL mysql_conn; 
    
    
    if (mysql_init(&mysql_conn) != NULL)
    {
        if (mysql_real_connect(&mysql_conn, "localhost", "root",
                    "123", "test", 0, NULL, 0) != NULL)
        
        printf("connect success\n");
        else
        printf("connect failed\n");

        mysql_close(&mysql_conn);
     }
       else
       printf("init failed\n");
       return 0;   
}
        
        
