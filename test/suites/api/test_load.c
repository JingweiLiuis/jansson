/*
 * Copyright (c) 2009, 2010 Petri Lehtinen <petri@digip.org>
 *
 * Jansson is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include <jansson.h>
#include <string.h>
#include "util.h"

int main()
{
    json_t *json;
    json_error_t *error;

    json = json_load_file("/path/to/nonexistent/file.json", 0, &error);
    if(json)
      fail("json_load didn't return an error!");
    if(json_error_line(error) != -1)
        fail("json_load_file returned an invalid line number");
    if(strcmp(json_error_msg(error), "unable to open /path/to/nonexistent/file.json: No such file or directory") != 0)
        fail("json_load_file returned an invalid error message");

    free(error);
    return 0;
}
