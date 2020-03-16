#ifndef c_node_hpp
#define c_node_hpp

#include <stdio.h>
#include "node.h"
#include "v8.h"

/**
 * Before the node program starts
 * @param id Node program identification
 * @param env Node Environment
 */
typedef void(*OnStartNode)(int id, node::Environment *env);

/**
 * After the node program stops
 * @param exitCode Node exit code
 */
typedef void
(*OnStopNode)(int exitCode);

extern "C" {

int nodeStart(int argc, char *argv[], int id, OnStartNode onStartNode);

int nodeStop(node::Environment *env);

};

#endif
