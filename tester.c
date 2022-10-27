//
// Created by Melkor on 10/27/2022.
//

#include <stdio.h>
#include <string.h>
#include "parser.h"

void main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");

    if (NULL == file) {
        printf("file can't be opened \n");
    }

    int cur_char ;
    STATE_MACHINE_RETURN_VALUE ret_value;


    while ((cur_char = fgetc(file)) != EOF)
    {
        printf("%c", cur_char);
        ret_value = at_command_parse( (char) cur_char );
        if (ret_value == STATE_MACHINE_NOT_READY)
        {
            printf("ret_value = %u\n", ret_value);
            continue;
        }

        if(ret_value == STATE_MACHINE_READY_OK)
        {
            printf("ok!");
            return;
        }


        if(ret_value == STATE_MACHINE_READY_WITH_ERROR)
        {
            printf("error!");
            return;
        }
    }

    fclose(file);
    //return;
}
