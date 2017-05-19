//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TSAccountManager.h"

typedef NS_ENUM(NSInteger, RefreshPreKeysMode) {
    // Refresh the signed prekey AND the one-time prekeys.
    RefreshPreKeysMode_SignedAndOneTime,
    // Only refresh the signed prekey, which should happen around every 48 hours.
    //
    // Most users will refresh their signed prekeys much more often than their
    // one-time prekeys, so we use a "signed only" mode to avoid updating the
    // one-time keys in this case.
    //
    // We do not need a "one-time only" mode.
    RefreshPreKeysMode_SignedOnly,
};

@interface TSPreKeyManager : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (BOOL)isAppLockedDueToPreKeyUpdateFailures;

+ (void)registerPreKeysWithMode:(RefreshPreKeysMode)mode
                        success:(void (^)())successHandler
                        failure:(void (^)(NSError *error))failureHandler;

// This method should be called in response to PreKeyWhisperMessages.
//
// It will check the the prekeys at a fast (but throttled) rate.
+ (void)checkPreKeysWithDebounce;

// This method should be called in response to app activation, etc.
//
// It will check the the prekeys at a slow rate.
+ (void)checkPreKeysIfNecessary;

@end
