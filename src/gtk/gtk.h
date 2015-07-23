/*
 * This file contains the include for <gtk/gtk.h> encased in pragmas that
 * suppress clang -Weverything warnings still in the gtk source code.
 * The necessity of this file should be verified after every minor release of
 * GTK+
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wcast-qual"
#pragma clang diagnostic ignored "-Wshift-sign-overflow"

#include <gtk/gtk.h>

#pragma clang diagnostic pop
