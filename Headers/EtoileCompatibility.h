/*
    Copyright (C) 2005 Quentin Mathe

    Date:  2005
    
    This file may be used under the terms of either GNU Lesser General Public 
    License Version 2.1 (or later), GNU General Public License Version 2 (or
    later), BSD modified license or Apache License Version 2.
 */

#define __ETOILE__

/* iOS Support */

#if TARGET_OS_IPHONE
#import "NSObject+Etoile.h"

/* NSPoint, NSSize, NSRect and NSValue related additions belong to Foundation on 
   Mac OS X, unlike iOS where these are split between CoreGraphcics and UIKit. */
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#define NSPoint CGPoint
#define NSSize CGSize
#define NSRect CGRect
#define pointValue CGPointValue
#define sizeValue CGSizeValue
#define rectValue CGRectValue
#define NSMakePoint CGPointMake
#define NSMakeSize CGSizeMake
#define NSMakeRect CGRectMake
#define NSEqualPoints CGPointEqualToPoint
#define NSEqualSizes CGSizeEqualToSize
#define NSEqualRects CGRectEqualToRect
#define NSStringFromPoint NSStringFromCGPoint
#define NSStringFromSize NSStringFromCGSize
#define NSStringFromRect NSStringFromCGRect
#define NSPointFromString CGPointFromString
#define NSSizeFromString CGSizeFromString
#define NSRectFromString CGRectFromString
#define valueWithPoint valueWithCGPoint
#define valueWithSize valueWithCGSize
#define valueWithRect valueWithCGRect
#endif

/* Logging Hacks */

// FIXME: Temporary hack until ETLog class is available
#define ETLog NSLog
#ifndef GNUSTEP
/* NSDebugLog and similar macros are not available with Cocoa, please avoid to 
   use them. */
#  define NSDebugLog NSLog
#endif

/* GCC version test code by Kazunobu Kuriyama */

#ifndef GCC_VERSION
#  if __GNUC__ > 3
#    define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCH_LEVEL__)
#  else
#    define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100)
#  endif
#endif

/* How to get GNUstep.h */

#ifdef GNUSTEP
#  import <GNUstepBase/GNUstep.h>
#else
#  import <EtoileFoundation/GNUstep.h>
#endif

/*  Compatibility with non-clang compilers */

#ifndef __has_feature
#   define __has_feature(x) 0
#endif

/* ARC macros taken from Headers/GNUstepBase/Preface.h.in
   Note: Apple GCC + GC supports __weak and __strong qualifiers */

#ifndef __weak
#  if !defined(__clang__) || !__has_feature(objc_arc)
#    if __OBJC_GC__
#      define __weak __attribute__((objc_gc(weak)))
#    elif defined(GNUSTEP)
#      define __weak 
#    endif
#  endif
#endif

#ifndef __strong
#  if !defined(__clang__) || !__has_feature(objc_arc)
#    if __OBJC_GC__
#      define __strong __attribute__((objc_gc(strong)))
#    elif defined(GNUSTEP)
#      define __strong 
#    endif
#  endif
#endif

#ifndef __unsafe_unretained
#  if !defined(__clang__) || !__has_feature(objc_arc)
#    define __unsafe_unretained
#  endif
#endif

#ifndef __bridge
#  if !defined(__clang__) || !__has_feature(objc_arc)
#    define __bridge
#  endif
#endif

/* Missing from GNUstep Base */

#ifdef GNUSTEP_MISSING_API_COMPATIBILITY

#import <Foundation/NSSortDescriptor.h>
#import <Foundation/NSNotification.h>
#import <Foundation/NSSet.h>

@class NSArray, NSOperationQueue;

/* Not present in 1.24.5 */
@interface NSNotificationCenter (ETGNUstepCompatibility)
- (id)addObserverForName: (NSString *)name object: (id)object queue: (NSOperationQueue *)queue usingBlock: (void (^)(NSNotification *))block;
@end

/* Not present in 1.24.5 */
@interface NSSet (ETGNUstepCompatibility) 
- (NSArray *) sortedArrayUsingDescriptors: (NSArray *)sortDescriptors;
@end

/* Not present in 1.24.5 */
@interface NSSortDescriptor (ETGNUstepCompatibility)
+ (id) sortDescriptorWithKey: (NSString *)aKey ascending: (BOOL)ascending;
+ (id) sortDescriptorWithKey: (NSString *)aKey ascending: (BOOL)ascending selector: (SEL)aSelector;
@end

#endif
