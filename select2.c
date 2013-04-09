#include<stdlib.h>
#include<stdio.h>
#include"mysql.h"

MYSQL my_connection;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;
void display_row()
{
	unsigned int field_count;
	field_count=0;
	while(field_count < mysql_field_count(&my_connection))
			{
		printf("%10s",sqlrow[field_count]);
		field_count++;
		}
			printf("\n");
}

int main()
{ 
	int res;
	mysql_init(&my_connection);
	if(mysql_real_connect(&my_connection,"localhost","root","123","test",0,NULL,0))
 	{
		printf("connection success\n");
		res = mysql_query(&my_connection,"select childno,fname,age from children where age>5");
		if(res)
		printf("seleect error: %s\n,",mysql_error(&my_connection));
		else
	
	{
			res_ptr=mysql_use_result(&my_connection);
            if(res_ptr)

			{
				 printf("retrived %lu rows\n",(unsigned long)mysql_num_rows(res_ptr));
				while((sqlrow=mysql_fetch_row(res_ptr)))
 				{
				//	printf("fetched data\n");
                 //   printf("%5s %10s %5s\n",sqlrow[0],sqlrow[1],sqlrow[2]); 
                   display_row();
				}
				if(mysql_errno(&my_connection))
					fprintf(stderr,"retrive error: %s\n",mysql_error(&my_connection));
				mysql_free_result(res_ptr);
 			}
			mysql_close(&my_connection);
 		}
 	}	
	else
	{
        fprintf(stderr,"connection failed\n");
		if(mysql_errno(&my_connection))
		{
			fprintf(stderr,"connection error %d: %s\n",mysql_errno(&my_connection),mysql_error(&my_connection));

		}

 	}
	return 0;
} 
	
