@interface Window : Responder
{
    NXRect              frame;
    id                  contentView;
    id                  delegate;
    id                  firstResponder;
    id                  lastLeftHit;
    id                  lastRightHit;
    id                  counterpart;
    id                  fieldEditor;
    int                 winEventMask;
    int                 windowNum;
    float               backgroundGray;

    id                  _borderView;
    short               _displayDisabled;
    short               _flushDisabled;
    void               *_cursorRects;
    NXHashTable        *_trectTable;
    id                  _invalidCursorView;
    id			_miniIcon;
    void	       *_private;
}

+ getFrameRect:(NXRect *)fRect forContentRect:(const NXRect *)cRect style:(int)aStyle;
+ getContentRect:(NXRect *)cRect forFrameRect:(const NXRect *)fRect style:(int)aStyle;
+ (NXCoord)minFrameWidth:(const char *)aTitle forStyle:(int)aStyle buttonMask:(int)aMask;
+ (NXWindowDepth)defaultDepthLimit;

- init;
- initContent:(const NXRect *)contentRect style:(int)aStyle backing:(int)bufferingType buttonMask:(int)mask defer:(BOOL)flag;
- initContent:(const NXRect *)contentRect style:(int)aStyle backing:(int)bufferingType buttonMask:(int)mask defer:(BOOL)flag screen:(const NXScreen *)screen;
- free;
- awake;
- setTitle:(const char *)aString;
- setTitleAsFilename:(const char *)aString;
- setExcludedFromWindowsMenu:(BOOL)flag;
- (BOOL)isExcludedFromWindowsMenu;
- setContentView:aView;
- contentView;
- setDelegate:anObject;
- delegate;
- (const char *)title;
- (int)buttonMask;
- (int)windowNum;
- getFieldEditor:(BOOL)createFlag for:anObject;
- endEditingFor:anObject;
- placeWindowAndDisplay:(const NXRect *)frameRect;
- placeWindow:(const NXRect *)frameRect;
- placeWindow:(const NXRect *)frameRect screen:(const NXScreen *)screen;
- (BOOL)constrainFrameRect:(NXRect *)frameRect toScreen:(const NXScreen *)screen;
- sizeWindow:(NXCoord)width :(NXCoord)height;
- moveTo:(NXCoord)x :(NXCoord)y;
- moveTopLeftTo:(NXCoord)x :(NXCoord)y;
- moveTo:(NXCoord)x :(NXCoord)y screen:(const NXScreen *)screen;
- moveTopLeftTo:(NXCoord)x :(NXCoord)y screen:(const NXScreen *)screen;
- getFrame:(NXRect *)theRect;
- getFrame:(NXRect *)rect andScreen:(const NXScreen **)screen;
- getMouseLocation:(NXPoint *)thePoint;
- (int)style;
- useOptimizedDrawing:(BOOL)flag;
- disableFlushWindow;
- reenableFlushWindow;
- (BOOL)isFlushWindowDisabled;
- flushWindow;
- flushWindowIfNeeded;
- disableDisplay;
- reenableDisplay;
- (BOOL)isDisplayEnabled;
- displayIfNeeded;
- display;
- update;
- (int)setEventMask:(int)newMask;
- (int)addToEventMask:(int)newEvents;
- (int)removeFromEventMask:(int)oldEvents;
- (int)eventMask;
- setTrackingRect:(const NXRect *)aRect inside:(BOOL)insideFlag owner:anObject tag:(int)trackNum left:(BOOL)leftDown right:(BOOL)rightDown;
- discardTrackingRect:(int)trackNum;
- makeFirstResponder:aResponder;
- firstResponder;
- sendEvent:(NXEvent *)theEvent;
- windowExposed:(NXEvent *)theEvent;
- windowMoved:(NXEvent *)theEvent;
- screenChanged:(NXEvent *)theEvent;
- (int)resizeFlags;
- makeKeyWindow;
- becomeKeyWindow;
- resignKeyWindow;
- becomeMainWindow;
- resignMainWindow;
- displayBorder;
- rightMouseDown:(NXEvent *)theEvent;
- (BOOL)commandKey:(NXEvent *)theEvent;
- close;
- setFreeWhenClosed:(BOOL)flag;
- miniaturize:sender;
- deminiaturize:sender;
- (BOOL)tryToPerform:(SEL)anAction with:anObject;
- validRequestorForSendType:(NXAtom)sendType andReturnType:(NXAtom)returnType;
- setBackgroundGray:(float)value;
- (float)backgroundGray;
- setBackgroundColor:(NXColor)color;
- (NXColor)backgroundColor;
- dragFrom:(float)x :(float)y eventNum:(int)num;
- setHideOnDeactivate:(BOOL)flag;
- (BOOL)doesHideOnDeactivate;
- center;
- makeKeyAndOrderFront:sender;
- orderFront:sender;
- orderBack:sender;
- orderOut:sender;
- orderWindow:(int)place relativeTo:(int)otherWin;
- orderFrontRegardless;
- setMiniwindowIcon:(const char *)anIcon;
- setMiniwindowImage:image;
- setMiniwindowTitle:(const char *)title;
- (const char *)miniwindowIcon;
- (NXImage *)miniwindowImage;
- (const char *)miniwindowTitle;
- setDocEdited:(BOOL)flag;
- (BOOL)isDocEdited;
- (BOOL)isVisible;
- (BOOL)isKeyWindow;
- (BOOL)isMainWindow;
- (BOOL)canBecomeKeyWindow;
- (BOOL)canBecomeMainWindow;
- (BOOL)worksWhenModal;
- convertBaseToScreen:(NXPoint *)aPoint;
- convertScreenToBase:(NXPoint *)aPoint;
- performClose:sender;
- performMiniaturize:sender;
- (int)gState;
- setOneShot:(BOOL)flag;
- (BOOL)isOneShot;
- faxPSCode:sender;
- printPSCode:sender;
- copyPSCodeInside:(const NXRect *)rect to:(NXStream *)stream;
- smartFaxPSCode:sender;
- smartPrintPSCode:sender;
- (BOOL)knowsPagesFirst:(int *)firstPageNum last:(int *)lastPageNum;
- openSpoolFile:(char *)filename;
- beginPSOutput;
- beginPrologueBBox:(const NXRect *)boundingBox creationDate:(const char *)dateCreated createdBy:(const char *)anApplication fonts:(const char *)fontNames forWhom:(const char *)user pages:(int)numPages title:(const char *)aTitle;
- endHeaderComments;
- endPrologue;
- beginSetup;
- endSetup;
- beginPage:(int)ordinalNum label:(const char *)aString bBox:(const NXRect *)pageRect fonts:(const char *)fontNames;
- beginPageSetupRect:(const NXRect *)aRect placement:(const NXPoint *)location;
- endPageSetup;
- endPage;
- beginTrailer;
- endTrailer;
- endPSOutput;
- spoolFile:(const char *)filename;
- (float)heightAdjustLimit;
- (float)widthAdjustLimit;
- (BOOL)getRect:(NXRect *)theRect forPage:(int)page;
- placePrintRect:(const NXRect *)aRect offset:(NXPoint *)location;
- addCursorRect:(const NXRect *)aRect cursor:anObj forView:aView;
- removeCursorRect:(const NXRect *)aRect cursor:anObj forView:aView;
- disableCursorRects;
- enableCursorRects;
- discardCursorRects;
- invalidateCursorRectsForView:aView;
- resetCursorRects;
- setBackingType:(int)bufferingType;
- (int)backingType;
- setAvoidsActivation:(BOOL)flag;
- (BOOL)avoidsActivation;
- setDepthLimit:(NXWindowDepth)limit;
- (NXWindowDepth)depthLimit;
- setDynamicDepthLimit:(BOOL)flag;
- (BOOL)hasDynamicDepthLimit;
- (const NXScreen *)screen;
- (const NXScreen *)bestScreen;
- (BOOL)canStoreColor;
- counterpart;
- (void)saveFrameToString:(char *)string;
- (void)setFrameFromString:(const char *)string;
- (void)saveFrameUsingName:(const char *)name;
- (BOOL)setFrameUsingName:(const char *)name;
- (BOOL)setFrameAutosaveName:(const char *)name;
- (const char *)frameAutosaveName;
+ (void)removeFrameUsingName:(const char *)name;
- getMinSize:(NXSize *)size;
- getMaxSize:(NXSize *)size;
- setMinSize:(const NXSize *)size;
- setMaxSize:(const NXSize *)size;
- write:(NXTypedStream *)stream;
- read:(NXTypedStream *)stream;

/* 
 * The following new... methods are now obsolete.  They remain in this  
 * interface file for backward compatibility only.  Use Object's alloc method  
 * and the init... methods defined in this class instead.
 */
+ newContent:(const NXRect *)contentRect style:(int)aStyle backing:(int)bufferingType buttonMask:(int)mask defer:(BOOL)flag;
+ newContent:(const NXRect *)contentRect style:(int)aStyle backing:(int)bufferingType buttonMask:(int)mask defer:(BOOL)flag screen:(const NXScreen *)screen;
+ new;

@end


@interface Window(Drag)
- dragImage:anImage at:(NXPoint *)baseLocation offset:(NXPoint *)initialOffset event:(NXEvent *)event pasteboard:(Pasteboard *)pboard source:sourceObj slideBack:(BOOL)slideFlag;

- registerForDraggedTypes:(const char *const *)newTypes count:(int)numTypes;
- unregisterDraggedTypes;
@end


@interface Object(WindowDelegate)
- windowWillClose:sender;
- windowWillReturnFieldEditor:sender toObject:client;
- windowWillResize:sender toSize:(NXSize *)frameSize;
- windowDidResize:sender;
- windowDidExpose:sender;
- windowWillMove:sender;
- windowDidMove:sender;
- windowDidBecomeKey:sender;
- windowDidResignKey:sender;
- windowDidBecomeMain:sender;
- windowDidResignMain:sender;
- windowWillMiniaturize:sender toMiniwindow:miniwindow;
- windowDidMiniaturize:sender;
- windowDidDeminiaturize:sender;
- windowDidUpdate:sender;
- windowDidChangeScreen:sender;
@end
