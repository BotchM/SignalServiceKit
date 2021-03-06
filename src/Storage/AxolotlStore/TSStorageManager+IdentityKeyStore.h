//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

#import <AxolotlKit/IdentityKeyStore.h>
#import "TSStorageManager.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const TSStorageManagerTrustedKeysCollection;

@interface TSStorageManager (IdentityKeyStore) <IdentityKeyStore>

/**
 * Explicitly mark an identity as approved for blocking/nonblocking use
 * e.g. in response to a user confirmation action.
 *
 * @param   identityKey key data used to identify the recipient
 * @param   recipientId unique stable identifier for the recipient, e.g. e164 phone number
 * @param   approvedForBlockingUse if the user wants explicit confirmation before sending to changed numbers, whether
 * that confirmation has occurred.
 * @param   approvedForNonBlockingUse YES to override the duration during which we consider an SN "too soon" to send.
 *
 * @returns YES if we are replacing an existing known identity key for recipientId.
 *          NO  if there was no previously stored identity key for the recipient.
 */
- (BOOL)saveRemoteIdentity:(NSData *)identityKey
               recipientId:(NSString *)recipientId
    approvedForBlockingUse:(BOOL)approvedForBlockingUse
 approvedForNonBlockingUse:(BOOL)approvedForNonBlockingUse;

- (void)generateNewIdentityKey;
- (nullable NSData *)identityKeyForRecipientId:(NSString *)recipientId;
- (void)removeIdentityKeyForRecipient:(NSString *)receipientId;

@end

NS_ASSUME_NONNULL_END
