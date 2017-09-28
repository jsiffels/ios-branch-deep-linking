//
//  BranchDelegate.h
//  Branch-SDK
//
//  Created by Edward Smith on 6/30/17.
//  Copyright © 2017 Branch Metrics. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Branch, BranchUniversalObject, BranchLinkProperties;

#pragma mark BranchDelegate Protocol

@protocol BranchDelegate <NSObject>

@optional
- (void) branch:(Branch*_Nonnull)branch willStartSessionWithURL:(NSURL*_Nullable)url;

@optional
- (void) branch:(Branch*_Nonnull)branch
     didStartSessionWithURL:(NSURL*_Nullable)url
            universalObject:(BranchUniversalObject*_Nonnull)universalObject
             linkProperties:(BranchLinkProperties*_Nonnull)linkProperties;

@optional
- (void) branch:(Branch*_Nonnull)branch
didStartSessionWithURL:(NSURL*_Nullable)url
                 error:(NSError*_Nullable)error;
@end

#pragma mark - Branch Notifications

FOUNDATION_EXPORT NSString*_Nonnull const BranchWillStartSessionNotification;
FOUNDATION_EXPORT NSString*_Nonnull const BranchDidStartSessionNotification;

FOUNDATION_EXPORT NSString*_Nonnull const BranchErrorKey;
FOUNDATION_EXPORT NSString*_Nonnull const BranchOriginalURLKey;
FOUNDATION_EXPORT NSString*_Nonnull const BranchUniversalObjectKey;
FOUNDATION_EXPORT NSString*_Nonnull const BranchLinkPropertiesKey;