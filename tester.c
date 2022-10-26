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

    char cur_char ;



    while ((cur_char = fgetc(file)) != EOF)
    {
        printf("%c", cur_char);
        STATE_MACHINE_RETURN_VALUE ret_value = at_command_parse( cur_char );

        if (ret_value == STATE_MACHINE_NOT_READY)
            continue;

        if(ret_value == STATE_MACHINE_READY_OK)
            return;

        if(ret_value == STATE_MACHINE_READY_WITH_ERROR)
            return;
    }

    fclose(file);
    //return;
}
