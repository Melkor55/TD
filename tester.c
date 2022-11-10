//
// Created by Melkor on 10/27/2022.
//

#include <stdio.h>
#include <string.h>
#include "parser.h"

void cleanData()
{
    for(int k = 0 ; k < AT_COMMAND_MAX_LINES; k++)
        for(int p = 0 ; p < AT_COMMAND_MAX_LINE_SIZE+1; p++)
            data.data[k][p]=0;
    j=0;
    i=0;
//            printf("cleaned");
}

void printData()
{
    for(int k = 0 ; k < AT_COMMAND_MAX_LINES; k++)
        for(int p = 0 ; p < AT_COMMAND_MAX_LINE_SIZE+1; p++)
            if(data.data[k][p]!=0)
                printf("%c",data.data[k][p]);
//    printf("printed");
}

void main(int argc, char *argv[])
{
    for (int i = 1 ; i < argc ; i ++)
    {
        FILE *file = fopen(argv[i], "rb");

        if (NULL == file) {
            printf("file can't be opened \n");
        }
        char cur_char ;
        STATE_MACHINE_RETURN_VALUE ret_value ;
        do
        {
            (cur_char = fgetc(file));
            //    printf("%c", cur_char);
            ret_value = at_command_parse( cur_char );
            if (ret_value == STATE_MACHINE_NOT_READY)
            {
                //printf("ret_value = %u\n", ret_value);
                continue;
            }

            if(ret_value == STATE_MACHINE_READY_OK)
            {
                //printf("ok!");
                break;
            }

            if(ret_value == STATE_MACHINE_READY_WITH_ERROR)
            {
                //printf("error!");
                break;
            }
        } while ( cur_char != EOF);

        printData();
        cleanData();

        printf( "\n-----------------------\t\tEOF for %s\t-----------------------\n\n",argv[i]);

        fclose(file);

        if (ret_value != STATE_MACHINE_NOT_READY)
            data.ok = 1;
        else
            data.ok = 0;

        //return;
    }
//    for(int k = 0 ; k < AT_COMMAND_MAX_LINES; k++)
//        for(int p = 0 ; p < AT_COMMAND_MAX_LINE_SIZE+1; p++)
//            if(data.data[k][p]!=0)
//                printf("%c",data.data[k][p]);
//    for(int k = 0 ; k < AT_COMMAND_MAX_LINES; k++)
//        for(int p = 0 ; p < AT_COMMAND_MAX_LINE_SIZE+1; p++)
//            printf("%c",data.data[k][p]);
}
