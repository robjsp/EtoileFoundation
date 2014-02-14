/**	
	<abstract>Formatter subclass to convert numbers expressed in bytes to a 
	human-readable format.</abstract>
 
	Copyright (C) 2010 Quentin Mathe
 
	Author:  Quentin Mathe <quentin.mathe@gmail.com>
	Date:  January 2010
	License:  Modified BSD (see COPYING)
 */

#import <Foundation/Foundation.h>

/** @group String Manipulation and Formatting

ETByteSizeFormatter supports to format NSNumber objects up the terabyte 
unit as detailed in -stringForObjectValue:.

ETByteSizeFormatter is now deprecated in favor of NSByteCountFormatter, we 
still support it on Mac OS X for backward compatibility with 10.6 and 10.7. */
@interface ETByteSizeFormatter : NSFormatter

- (NSString *) stringForObjectValue: (id)anObject;

@end
