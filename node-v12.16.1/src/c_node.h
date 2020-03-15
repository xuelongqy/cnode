#ifndef c_node_hpp
#define c_node_hpp

#include <stdio.h>
#include "node.h"
#include "v8.h"

/**
 * Before the node program starts
 * @param env Node Environment
 * @param isolate V8 Isolate
 * @param context V8 Context
 */
typedef void
(*OnStartNode)(node::Environment *env, v8::Isolate *isolate, v8::Context *context);

/**
 * After the node program stops
 * @param exitCode Node exit code
 */
typedef void
(*OnStopNode)(int exitCode);

extern "C" {

int nodeStart(int argc, char *argv[]);

int nodeStop(node::Environment *env);

};

#endif
