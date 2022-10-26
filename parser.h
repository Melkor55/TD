#ifndef TD_PARSER_H
#define TD_PARSER_H

#include <stdint.h>

#define  AT_COMMAND_MAX_LINES 100
#define  AT_COMMAND_MAX_LINE_SIZE 100

typedef struct
{
    uint8_t ok;
    uint8_t data[AT_COMMAND_MAX_LINES][AT_COMMAND_MAX_LINE_SIZE + 1];
    uint32_t count;
}AT_COMMAND_DATA;       // for testing multiple files

typedef enum
{
    STATE_MACHINE_NOT_READY,
    STATE_MACHINE_READY_OK,
    STATE_MACHINE_READY_WITH_ERROR
}STATE_MACHINE_RETURN_VALUE;
STATE_MACHINE_RETURN_VALUE at_command_parse(uint8_t current_character);

#endif //TD_PARSER_H
