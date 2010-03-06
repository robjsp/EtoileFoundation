/*
	Copyright (C) 2009 Eric Wasylishen

	Author:  Eric Wasylishen <ewasylishen@gmail.com>
	Date:  July 2009
	License:  Modified BSD (see COPYING)
 */

#import "ETModelElementDescription.h"
#import "ETEntityDescription.h"
#import "ETPropertyDescription.h"
#import "ETUTI.h"
#import "Macros.h"
#import "EtoileCompatibility.h"


@implementation ETModelElementDescription

static ETEntityDescription *desc = nil;

+ (ETEntityDescription *) entityDescription
{
	if (nil != desc) return desc;

	desc = [[ETEntityDescription alloc] initWithName: @"ETModelElementDescription"];
	
	ETPropertyDescription *name = [ETPropertyDescription descriptionWithName: @"name" owner: desc];
	ETPropertyDescription *UTI = [ETPropertyDescription descriptionWithName: @"type" owner: desc];
	ETPropertyDescription *itemIdentifier = [ETPropertyDescription descriptionWithName: @"itemIdentifier" owner: desc];

	[desc setAbstract: YES];	
	[desc setPropertyDescriptions: A(name, UTI, itemIdentifier)];
	[desc setType: [ETUTI typeWithClass: [ETModelElementDescription class]]];
	// FIXME: set a sensible parent for desc? currently it's nil

	return desc;
}

+ (id) descriptionWithName: (NSString *)name
{
	return [[[[self class] alloc] initWithName: name] autorelease];
}

- (id) initWithName: (NSString *)name
{
	if ([[self class] isMemberOfClass: [ETModelElementDescription class]])
	{
		DESTROY(self);
		return nil;
	}
	NILARG_EXCEPTION_TEST(name);
	// TODO: Check the name is not in use once we have a repository.

	SUPERINIT;
	ASSIGN(_name, name);
	ASSIGN(_UTI, [ETUTI typeWithClass: [NSObject class]]);
	return self;
}

- (void) dealloc
{
	DESTROY(_name);
	DESTROY(_UTI);
	DESTROY(_itemIdentifier);
	[super dealloc];
}

- (NSString *) name
{
	return _name;
}

- (void) setName: (NSString *)name
{
	ASSIGN(_name, name);
}

- (ETUTI *) type
{
	return _UTI;
}

- (void) setType: (ETUTI *)UTI
{
	ASSIGN(_UTI, UTI);
}

- (NSString *) itemIdentifier;
{
	return _itemIdentifier;
}

- (void) setItemIdentifier: (NSString *)anIdentifier
{
	ASSIGN(_itemIdentifier, anIdentifier);
}

@end