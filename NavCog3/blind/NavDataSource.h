/*******************************************************************************
 * Copyright (c) 2014, 2016  IBM Corporation, Carnegie Mellon University and others
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NavDataStore.h"
#import "HLPDirectory.h"

@interface NavTableDataSource: NSObject <UITableViewDataSource>{
    @protected NSObject *_filter;
}
@property NSObject *filter;
- (NavDestination*) destinationForRowAtIndexPath:(NSIndexPath *)indexPath;
@end

@interface NavDirectoryDataSource : NavTableDataSource
@property BOOL showCurrentLocation;
@property HLPDirectory *directory;
- (void)update:(NSNotification*)note;
@end

@interface NavDestinationDataSource : NavTableDataSource
@property NSInteger selectedRow;
@property NSDictionary *defaultFilter;
@property HLPDirectory *directory;

@property BOOL showCurrentLocation;
@property BOOL showBuilding;
@property BOOL showShops;
@property BOOL showFacility;
@property BOOL showSectionIndex;
@property BOOL showNearShops;
@property BOOL showShopBuilding;
@property BOOL showShopFloor;
@property BOOL showDialog;

- (NavDestination*) destinationForRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)update:(NSNotification*)note;
@end

@interface NavSearchHistoryDataSource : NSObject < UITableViewDataSource>
- (NSDictionary*) historyAtIndexPath:(NSIndexPath*)indexPath;
- (BOOL)isKnownHist:(NSDictionary*)hist;
@end
