/* Obj-C to Java:
* Class: NSWindow.
* Source File: NSWindow.h.
* Module: OpenStep : AppKit.
* Time stamp: Mon Jun 23 18:53:24 1997
.
*/

package openstep.appkit;

import openstep.foundation.*;
import openstep.appkit.*;

public class OSWindow extends OSResponder implements OSCoding {
	// Instance Variables.
    OSRect frame;
    OSSize minimum_size;
    OSSize maximum_size;
    Object content_view;
    Object first_responder;
    Object original_responder;
    Object delegate;
    int window_num;
    OSColor background_color;
    String represented_filename;
    String miniaturized_title;
    OSImage miniaturized_image;
    String window_title;
    OSPoint last_point;
    OSBackingStoreType backing_type;
    int style_mask;
    int window_level;
    boolean is_one_shot;
    boolean needs_display;
    boolean is_autodisplay;
    boolean optimize_drawing;
    boolean views_need_display;
    OSWindowDepth depth_limit;
    boolean dynamic_depth_limit;
    boolean cursor_rects_enabled;
    boolean visible;
    boo