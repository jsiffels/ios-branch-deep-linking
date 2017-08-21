//
//  BranchUniversalObject.h
//  Branch-TestBed
//
//  Created by Derrick Staten on 10/16/15.
//  Copyright © 2015 Branch Metrics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BNCCallbacks.h"
#import "BNCCommerceEvent.h"
#import "BranchLinkProperties.h"

#pragma mark BranchContentIndexMode

typedef NS_ENUM(NSInteger, BranchContentIndexMode) {
    BranchContentIndexModePublic,
    BranchContentIndexModePrivate,
    BranchContentIndexModeLocal = BranchContentIndexModePrivate,
    BranchContentIndexModeNone
};

#pragma mark - BNCContentSchema

typedef NSString * const BNCContentSchema;

extern BNCContentSchema _Nonnull BNCContentSchemaCommerceAuction;
extern BNCContentSchema _Nonnull BNCContentSchemaCommerceBusiness;
extern BNCContentSchema _Nonnull BNCContentSchemaCommerceOther;
extern BNCContentSchema _Nonnull BNCContentSchemaCommerceProduct;
extern BNCContentSchema _Nonnull BNCContentSchemaCommerceRestaurant;
extern BNCContentSchema _Nonnull BNCContentSchemaCommerceService;
extern BNCContentSchema _Nonnull BNCContentSchemaCommerceTravelFlight;
extern BNCContentSchema _Nonnull BNCContentSchemaCommerceTravelHotel;
extern BNCContentSchema _Nonnull BNCContentSchemaCommerceTravelOther;
extern BNCContentSchema _Nonnull BNCContentSchemaGameState;
extern BNCContentSchema _Nonnull BNCContentSchemaMediaImage;
extern BNCContentSchema _Nonnull BNCContentSchemaMediaMixed;
extern BNCContentSchema _Nonnull BNCContentSchemaMediaMusic;
extern BNCContentSchema _Nonnull BNCContentSchemaMediaOther;
extern BNCContentSchema _Nonnull BNCContentSchemaMediaVideo;
extern BNCContentSchema _Nonnull BNCContentSchemaOther;
extern BNCContentSchema _Nonnull BNCContentSchemaTextArticle;
extern BNCContentSchema _Nonnull BNCContentSchemaTextBlog;
extern BNCContentSchema _Nonnull BNCContentSchemaTextOther;
extern BNCContentSchema _Nonnull BNCContentSchemaTextRecipe;
extern BNCContentSchema _Nonnull BNCContentSchemaTextReview;
extern BNCContentSchema _Nonnull BNCContentSchemaTextSearchResults;
extern BNCContentSchema _Nonnull BNCContentSchemaTextStory;
extern BNCContentSchema _Nonnull BNCContentSchemaTextTechnicalDoc;

#pragma mark - BNCProductCondition

typedef NSString * const BNCProductCondition;

extern BNCProductCondition _Nonnull BNCProductConditionOther;
extern BNCProductCondition _Nonnull BNCProductConditionNew;
extern BNCProductCondition _Nonnull BNCProductConditionGood;
extern BNCProductCondition _Nonnull BNCProductConditionFair;
extern BNCProductCondition _Nonnull BNCProductConditionPoor;
extern BNCProductCondition _Nonnull BNCProductConditionUsed;
extern BNCProductCondition _Nonnull BNCProductConditionRefurbished;

#pragma mark - BranchSchemaData

@interface BranchSchemaData : NSObject

@property (nonatomic, strong, nullable) BNCContentSchema contentSchema;
@property (nonatomic, assign)           double          quantity;
@property (nonatomic, strong, nullable) NSDecimalNumber *price;
@property (nonatomic, strong, nullable) BNCCurrency     currency;
@property (nonatomic, strong, nullable) NSString        *sku;
@property (nonatomic, strong, nullable) NSString        *productName;
@property (nonatomic, strong, nullable) NSString        *productBrand;
@property (nonatomic, strong, nullable) NSString        *productCategory;
@property (nonatomic, strong, nullable) NSString        *productVariant;
@property (nonatomic, assign)           double          ratingAverage;
@property (nonatomic, assign)           NSInteger       ratingCount;
@property (nonatomic, assign)           double          ratingMaximum;
@property (nonatomic, strong, nullable) NSString        *addressStreet;
@property (nonatomic, strong, nullable) NSString        *addressCity;
@property (nonatomic, strong, nullable) NSString        *addressRegion;
@property (nonatomic, strong, nullable) NSString        *addressCountry;
@property (nonatomic, strong, nullable) NSString        *addressPostalCode;
@property (nonatomic, assign)           double          latitude;
@property (nonatomic, assign)           double          longitude;
@property (nonatomic, strong, nullable) NSArray<NSString*> *imageCaptions;
@property (nonatomic, strong, nullable) NSMutableDictionary<NSString*, NSString*> *userInfo;

- (NSDictionary*_Nonnull) dictionary;
+ (BranchSchemaData*_Nonnull) schemaDataWithDictionary:(NSDictionary*_Nullable)dictionary;
@end

#pragma mark - BranchUniversalObject

@interface BranchUniversalObject : NSObject

- (nonnull instancetype)initWithCanonicalIdentifier:(nonnull NSString *)canonicalIdentifier;
- (nonnull instancetype)initWithTitle:(nonnull NSString *)title;

@property (nonatomic, strong, nullable) NSString *canonicalIdentifier;
@property (nonatomic, strong, nullable) NSString *canonicalUrl;
@property (nonatomic, strong, nullable) NSString *title;
@property (nonatomic, strong, nullable) NSString *contentDescription;
@property (nonatomic, strong, nullable) NSString *imageUrl;
@property (nonatomic, strong, nullable) NSArray<NSString*> *keywords;
@property (nonatomic, strong, nullable) NSDate   *creationDate;
@property (nonatomic, strong, nullable) NSDate   *expirationDate;
@property (nonatomic, assign)           BOOL      indexLocally;
@property (nonatomic, assign)           BOOL      indexPublicly;

@property (nonatomic, strong, nonnull) BranchSchemaData *schemaData;

/*!
 @name Deprecated Properties
*/

// Note: properties found in metadata will overwrite properties on the BranchUniversalObject itself

@property (nonatomic, strong, nullable)
    __attribute__((deprecated(("Use `BranchUniversalObject.schemaData.userInfo` instead."))))
    NSDictionary *metadata;

- (void)addMetadataKey:(nonnull NSString *)key value:(nonnull NSString *)value
    __attribute__((deprecated(("Use `BranchUniversalObject.schemaData.userInfo` instead."))));

@property (nonatomic, strong, nullable)
    __attribute__((deprecated(("Use `BranchUniversalObject.schemaData.contentSchema` instead."))))
    NSString *type;

@property (nonatomic, assign)
    __attribute__((deprecated(("Use `BranchUniversalObject.indexLocally and BranchUniversalObject.indexPublicly` instead."))))
    BranchContentIndexMode contentIndexMode;

@property (nonatomic, strong, nullable)
    __attribute__((deprecated(("Not used due to iOS 10.0 Spotlight changes."))))
    NSString *spotlightIdentifier;

@property (nonatomic, assign)
    __attribute__((deprecated(("Use `BranchUniversalObject.metadata.price` instead."))))
    CGFloat price;

@property (nonatomic, strong, nullable)
    __attribute__((deprecated(("Use `BranchUniversalObject.metadata.currency` instead."))))
    NSString *currency;

@property (nonatomic, assign)
    __attribute__((deprecated(("Use `BranchUniversalObject.metadata.indexLocally` instead."))))
    BOOL automaticallyListOnSpotlight;

- (void)registerView;
- (void)registerViewWithCallback:(nullable callbackWithParams)callback;

/*!
 @name Event Tracking
*/

- (void)userCompletedAction:(nonnull NSString *)action;
- (void)userCompletedAction:(nonnull NSString *)action withState:(nullable NSDictionary *)state;

/*!
 @name Short Links
*/

/// Returns a Branch short URL to the content item with the passed link properties.
- (nullable NSString *)getShortUrlWithLinkProperties:(nonnull BranchLinkProperties *)linkProperties;

/// Returns a Branch short URL to the content item with the passed link properties.
/// Ignores the first access of the item (usually due to a robot indexing the item) for statistics.
- (nullable NSString *)getShortUrlWithLinkPropertiesAndIgnoreFirstClick:(nonnull BranchLinkProperties *)linkProperties;

/// Returns a Branch short URL to the content item with the passed link properties with a callback.
- (void)getShortUrlWithLinkProperties:(nonnull BranchLinkProperties *)linkProperties andCallback:(nonnull callbackWithUrl)callback;

/*!
 @name Share Sheet Handling
*/

- (nullable UIActivityItemProvider *)getBranchActivityItemWithLinkProperties:(nonnull BranchLinkProperties *)linkProperties;

- (void)showShareSheetWithShareText:(nullable NSString *)shareText
                         completion:(void (^ _Nullable)(NSString * _Nullable activityType, BOOL completed))completion;

- (void)showShareSheetWithLinkProperties:(nullable BranchLinkProperties *)linkProperties
                            andShareText:(nullable NSString *)shareText
                      fromViewController:(nullable UIViewController *)viewController
                              completion:(void (^ _Nullable)(NSString * _Nullable activityType, BOOL completed))completion;

// Returns with activityError as well
- (void)showShareSheetWithLinkProperties:(nullable BranchLinkProperties *)linkProperties
                            andShareText:(nullable NSString *)shareText
                      fromViewController:(nullable UIViewController *)viewController
                     completionWithError:(void (^ _Nullable)(NSString * _Nullable activityType, BOOL completed, NSError*_Nullable error))completion;

// iPad
- (void)showShareSheetWithLinkProperties:(nullable BranchLinkProperties *)linkProperties
                            andShareText:(nullable NSString *)shareText
                      fromViewController:(nullable UIViewController *)viewController
                                  anchor:(nullable UIBarButtonItem *)anchor
                              completion:(void (^ _Nullable)(NSString * _Nullable activityType, BOOL completed))completion;

// Returns with activityError as well
- (void)showShareSheetWithLinkProperties:(nullable BranchLinkProperties *)linkProperties
                            andShareText:(nullable NSString *)shareText
                      fromViewController:(nullable UIViewController *)viewController
                                  anchor:(nullable UIBarButtonItem *)anchor
                     completionWithError:(void (^ _Nullable)(NSString * _Nullable activityType, BOOL completed, NSError*_Nullable error))completion;

/*!
 @name List items on Spotlight
*/

- (void)listOnSpotlight;
- (void)listOnSpotlightWithCallback:(nullable callbackWithUrl)callback;
- (void)listOnSpotlightWithIdentifierCallback:(nullable callbackWithUrlAndSpotlightIdentifier)spotlightCallback
    __attribute__((deprecated((
        "iOS 10 has changed how Spotlight indexing works and we’ve updated the SDK to reflect this. "
        "Please see https://dev.branch.io/features/spotlight-indexing/overview/ for instructions on migration"
    ))));;

// Convenience method for initSession methods that return BranchUniversalObject, but can be used safely by anyone.
+ (nonnull BranchUniversalObject *)getBranchUniversalObjectFromDictionary:(nonnull NSDictionary *)dictionary;

- (NSDictionary*_Nonnull)getParamsForServerRequest;
- (NSDictionary*_Nonnull)getDictionaryWithCompleteLinkProperties:(BranchLinkProperties*_Nonnull)linkProperties;
- (NSDictionary*_Nonnull)getParamsForServerRequestWithAddedLinkProperties:(BranchLinkProperties*_Nonnull)linkProperties;

- (NSDictionary*_Nonnull) dictionary;
+ (BranchUniversalObject*_Null_unspecified) objectWithDictionary:(NSDictionary*_Null_unspecified)dictionary;
@end
