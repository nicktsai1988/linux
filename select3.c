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
void display_header()
{
	MYSQL_FIELD *field_ptr;
	printf("column details: \n");
    while((field_ptr=mysql_fetch_field(res_ptr))!=NULL)
	{
		printf("\t Name: %s\n",field_ptr->name);
		printf("\t Type: ");
		if(IS_NUM(field_ptr->type))
		{
			printf("Numeric field\n");
		}
		else
		{
			switch(field_ptr->type)
			{
				case FIELD_TYPE_VAR_STRING:
					printf("VARCHAR\n");
				break;
				case FIELD_TYPE_LONG:
				    printf("LONG\n");
                break;
				default:
				    printf("Type is %d,check in mysql_com.h\n",field_ptr->type);
			}
		}
		printf("\t Max width %ld\n",field_ptr->length);
		if(field_ptr->flags&AUTO_INCREMENT_FLAG)
			printf("\t Auto increments\n");
		printf("\n");
	}
}


int main()
{ 
	int res;
	int first_row=1;
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
				//	printf("fetched data\n") 
				 //  printf("%5s %10s %5s\n",sqlrow[0],sqlrow[1],sqlrow[2]); 
				   if(first_row)
				   {
					   display_header();
					   first_row=0;
				   }
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
	
