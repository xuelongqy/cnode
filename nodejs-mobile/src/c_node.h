#ifndef c_node_hpp
#define c_node_hpp

#include "node.h"

/**
 * Before the node program starts, initialization operation
 * @param env Node Environment
 */
typedef void(*InitNode)(node::Environment *env);

extern "C" {

/**
* Start the node program
* @param argc Argument count
* @param argv Arguments
* @param initNode Before the node program starts, initialization operation
* @return exit code
*/
int nodeStart(int argc, char *argv[], InitNode initNode);

/**
* Start the node program in a thread
* @param argc Argument count
* @param argv Arguments
* @param initNode Before the node program starts, initialization operation
* @return exit code (Temporarily useless)
*/
int nodeStartThread(int argc, char *argv[], InitNode initNode);

/**
 * Stop node program
 * @param env Node Environment
 * @return exit code (Temporarily useless)
 */
int nodeStop(node::Environment *env);

};

#endif
