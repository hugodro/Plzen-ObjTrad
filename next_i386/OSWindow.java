/* Obj-C to Java:
* Class: NSWindow.
* Source File: NSWindow.h.
* Module: OpenStep : AppKit.
* Time stamp: Mon Jun 23 22:53:13 1997.
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
    boolean is_key;
    boolean is_main;
    boolean is_edited;
    boolean is_released_when_closed;
    boolean is_miniaturized;
    boolean disable_flush_window;
    boolean menu_exclude;
    boolean hides_on_deactivate;
    boolean accepts_mouse_moved;
    Object be_wind_reserved;

	// Methods.
    static OSRect contentRectForFrameRect_styleMask(OSRect aRect, int aStyle)
    {
	return null;
    }

    static OSRect frameRectForContentRect_styleMask(OSRect aRect, int aStyle)
    {
	return null;
    }

    static OSRect minFrameWidthWithTitle_styleMask(String aTitle, int aStyle)
    {
	return null;
    }

    static void removeFrameUsingName(String name)
    {
    }

    Object initWithContentRect_styleMask_backing_defer(OSRect contentRect, int aStyle, OSBackingStoreType bufferingType, boolean flag)
    {
	return null;
    }

    Object initWithContentRect_styleMask_backing_defer_screen(OSRect contentRect, int aStyle, OSBackingStoreType bufferingType, boolean flag, Object aScreen)
    {
	return null;
    }

    Object contentView()
    {
	return null;
    }

    void setContentView(OSView aView)
    {
    }

    OSColor backgroundColor()
    {
	return null;
    }

    String representedFilename()
    {
	return null;
    }

    void setBackgroundColor(OSColor color)
    {
    }

    void setRepresentedFilename(String aString)
    {
    }

    void setTitle(String aString)
    {
    }

    void setTitleWithRepresentedFilename(String aString)
    {
    }

    int styleMask()
    {
	return 0;
    }

    String title()
    {
	return null;
    }

    OSBackingStoreType backingType()
    {
	return null;
    }

    OSDictionary deviceDescription()
    {
	return null;
    }

    int gState()
    {
	return 0;
    }

    boolean isOneShot()
    {
	return false;
    }

    void setBackingType(OSBackingStoreType type)
    {
    }

    void setOneShot(boolean flag)
    {
    }

    int windowNumber()
    {
	return 0;
    }

    void setWindowNumber(int windowNum)
    {
    }

    OSImage miniwindowImage()
    {
	return null;
    }

    String miniwindowTitle()
    {
	return null;
    }

    void setMiniwindowImage(OSImage image)
    {
    }

    void setMiniwindowTitle(String title)
    {
    }

    void endEditingFor(Object anObject)
    {
    }

    OSText fieldEditor_forObject(boolean createFlag, Object anObject)
    {
	return null;
    }

    void becomeKeyWindow()
    {
    }

    void becomeMainWindow()
    {
    }

    boolean canBecomeKeyWindow()
    {
	return false;
    }

    boolean canBecomeMainWindow()
    {
	return false;
    }

    boolean hidesOnDeactivate()
    {
	return false;
    }

    boolean isKeyWindow()
    {
	return false;
    }

    boolean isMainWindow()
    {
	return false;
    }

    boolean isMiniaturized()
    {
	return false;
    }

    boolean isVisible()
    {
	return false;
    }

    int level()
    {
	return 0;
    }

    void makeKeyAndOrderFront(Object sender)
    {
    }

    void makeKeyWindow()
    {
    }

    void makeMainWindow()
    {
    }

    void orderBack(Object sender)
    {
    }

    void orderFront(Object sender)
    {
    }

    void orderFrontRegardless()
    {
    }

    void orderOut(Object sender)
    {
    }

    void orderWindow_relativeTo(OSWindowOrderingMode place, int otherWin)
    {
    }

    void resignKeyWindow()
    {
    }

    void resignMainWindow()
    {
    }

    void setHidesOnDeactivate(boolean flag)
    {
    }

    void setLevel(int newLevel)
    {
    }

    OSPoint cascadeTopLeftFromPoint(OSPoint topLeftPoint)
    {
	return null;
    }

    void center()
    {
    }

    OSRect constrainFrameRect_toScreen(OSRect frameRect, Object screen)
    {
	return null;
    }

    OSRect frame()
    {
	return null;
    }

    OSSize minSize()
    {
	return null;
    }

    OSSize maxSize()
    {
	return null;
    }

    void setContentSize(OSSize aSize)
    {
    }

    void setFrame_display(OSRect frameRect, boolean flag)
    {
    }

    void setFrameOrigin(OSPoint aPoint)
    {
    }

    void setFrameTopLeftPoint(OSPoint aPoint)
    {
    }

    void setMinSize(OSSize aSize)
    {
    }

    void setMaxSize(OSSize aSize)
    {
    }

    OSPoint convertBaseToScreen(OSPoint aPoint)
    {
	return null;
    }

    OSPoint convertScreenToBase(OSPoint aPoint)
    {
	return null;
    }

    void display()
    {
    }

    void disableFlushWindow()
    {
    }

    void displayIfNeeded()
    {
    }

    void enableFlushWindow()
    {
    }

    void flushWindow()
    {
    }

    void flushWindowIfNeeded()
    {
    }

    boolean isAutodisplay()
    {
	return false;
    }

    boolean isFlushWindowDisabled()
    {
	return false;
    }

    void setAutoDisplay(boolean flag)
    {
    }

    void setViewsNeedDisplay(boolean flag)
    {
    }

    void update()
    {
    }

    void useOptimizedDrawing(boolean flag)
    {
    }

    boolean viewsNeedDisplay()
    {
	return false;
    }

    static OSWindowDepth defaultDepthLimit()
    {
	return null;
    }

    boolean canStoreColor()
    {
	return false;
    }

    OSScreen deepestScreen()
    {
	return null;
    }

    OSWindowDepth depthLimit()
    {
	return null;
    }

    boolean hasDynamicDepthLimit()
    {
	return false;
    }

    OSScreen screen()
    {
	return null;
    }

    void setDepthLimit(OSWindowDepth limit)
    {
    }

    void setDynamicDepthLimit(boolean flag)
    {
    }

    boolean areCursorRectsEnabled()
    {
	return false;
    }

    void disableCursorRects()
    {
    }

    void discardCursorRects()
    {
    }

    void enableCursorRects()
    {
    }

    void invalidateCursorRectsForView(OSView aView)
    {
    }

    void resetCursorRects()
    {
    }

    void close()
    {
    }

    void deminiaturize(Object sender)
    {
    }

    boolean isDocumentEdited()
    {
	return false;
    }

    boolean isReleasedWhenClosed()
    {
	return false;
    }

    void miniaturize(Object sender)
    {
    }

    void performClose(Object sender)
    {
    }

    void performMiniaturize(Object sender)
    {
    }

    int resizeFlags()
    {
	return 0;
    }

    void setDocumentEdited(boolean flag)
    {
    }

    void setReleasedWhenClosed(boolean flag)
    {
    }

    boolean acceptsMouseMovedEvents()
    {
	return false;
    }

    OSEvent currentEvent()
    {
	return null;
    }

    void discardEventsMatchingMask_beforeEvent(int mask, OSEvent lastEvent)
    {
    }

    OSResponder firstResponder()
    {
	return null;
    }

    void keyDown(OSEvent theEvent)
    {
    }

    boolean makeFirstResponder(OSResponder aResponder)
    {
	return false;
    }

    OSPoint mouseLocationOutsideOfEventStream()
    {
	return null;
    }

    OSEvent nextEventMatchingMask(int mask)
    {
	return null;
    }

    OSEvent nextEventMatchingMask_untilDate_inMode_dequeue(int mask, OSDate expiration, String mode, boolean deqFlag)
    {
	return null;
    }

    void postEvent_atStart(OSEvent event, boolean flag)
    {
    }

    void setAcceptsMouseMovedEvents(boolean flag)
    {
    }

    void sendEvent(OSEvent theEvent)
    {
    }

    boolean tryToPerform_with(Method anAction, Object anObject)
    {
	return false;
    }

    boolean worksWhenModal()
    {
	return false;
    }

    void dragImage_at_offset_event_pasteboard_source_slideBack(OSImage anImage, OSPoint baseLocation, OSSize initialOffset, OSEvent event, OSPasteboard pboard, Object sourceObject, boolean slideFlag)
    {
    }

    void registerForDraggedTypes(OSArray newTypes)
    {
    }

    void unregisterDraggedTypes()
    {
    }

    boolean isExcludedFromWindowsMenu()
    {
	return false;
    }

    void setExcludedFromWindowsMenu(boolean flag)
    {
    }

    Object validRequestorForSendType_returnType(String sendType, String returnType)
    {
	return null;
    }

    String frameAutosaveName()
    {
	return null;
    }

    void saveFrameUsingName(String name)
    {
    }

    boolean setFrameAutosaveName(String name)
    {
	return false;
    }

    void setFrameFromString(String string)
    {
    }

    boolean setFrameUsingName(String name)
    {
	return false;
    }

    String stringWithSavedFrame()
    {
	return null;
    }

    OSData dataWithEPSInsideRect(OSRect rect)
    {
	return null;
    }

    void fax(Object sender)
    {
    }

    void print(Object sender)
    {
    }

    Object delegate()
    {
	return null;
    }

    void setDelegate(Object anObject)
    {
    }

    boolean windowShouldClose(Object sender)
    {
	return false;
    }

    OSSize windowWillResize_toSize(OSWindow sender, OSSize frameSize)
    {
	return null;
    }

    Object windowWillReturnFieldEditor_toObject(OSWindow sender, Object client)
    {
	return null;
    }

    void windowDidBecomeKey(OSNotification aNotification)
    {
    }

    void windowDidBecomeMain(OSNotification aNotification)
    {
    }

    void windowDidChangeScreen(OSNotification aNotification)
    {
    }

    void windowDidDeminiaturize(OSNotification aNotification)
    {
    }

    void windowDidExpose(OSNotification aNotification)
    {
    }

    void windowDidMiniaturize(OSNotification aNotification)
    {
    }

    void windowDidMove(OSNotification aNotification)
    {
    }

    void windowDidResignKey(OSNotification aNotification)
    {
    }

    void windowDidResignMain(OSNotification aNotification)
    {
    }

    void windowDidResize(OSNotification aNotification)
    {
    }

    void windowDidUpdate(OSNotification aNotification)
    {
    }

    void windowWillClose(OSNotification aNotification)
    {
    }

    void windowWillMiniaturize(OSNotification aNotification)
    {
    }

    void windowWillMove(OSNotification aNotification)
    {
    }

    void encodeWithCoder(Object aCoder)
    {
    }

    Object initWithCoder(Object aDecoder)
    {
	return null;
    }


}


