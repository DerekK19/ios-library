/*
 Copyright 2009-2014 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "UAEvent.h"

#define kUAAttributionHardOpen @"ua_hard_open"
#define kUAAttributionLandingPage @"ua_landing_page"
#define kUAAttributionMCRAP @"ua_mcrap"

@class UAInboxMessage;

@interface UACustomEvent : UAEvent

/**
 * Factory method for creating a custom event.
 *
 * @param eventName The name of the event. The event's name must not exceed
 * 255 characters or it will be ignored.
 */
+ (instancetype)eventWithName:(NSString *)eventName;

/**
 * Factory method for creating a custom event with a value from a string.
 *
 * @param eventName The name of the event. The event's name must not exceed
 * 255 characters or it will be ignored.
 * @param eventValue The value of the event as a string. The value must be a valid
 * number between -2^31 and 2^31 - 1 or it will be ignored.
 */
+ (instancetype)eventWithName:(NSString *)eventName valueFromString:(NSString *)eventValue;

/**
 * Factory method for creating a custom event with a value.
 *
 * @param eventName The name of the event. The event's name must not exceed
 * 255 characters or it will be ignored.
 * @param eventValue The value of the event. The value must be between -2^31 and
 * 2^31 - 1 or it will be ignored.
 */
+ (instancetype)eventWithName:(NSString *)eventName value:(NSNumber *)eventValue;

/**
 * The event's value. The value must be between -2^31 and
 * 2^31 - 1 or it will be ignored.
 */
@property(nonatomic, strong) NSDecimalNumber *eventValue;

/**
 * The event's name. The name's length must not exceed 255 characters or it will
 * be ignored.
 */
@property(nonatomic, copy) NSString *eventName;

/**
 * The event's attribution ID. The ID's length must not exceed 255 characters or it will
 * be ignored.
 */
@property(nonatomic, copy) NSString *attributionID;

/**
 * The event's attribution type. The type's length must not exceed 255 characters or it will
 * be ignored.
 */
@property(nonatomic, copy) NSString *attributionType;

/**
 * The event's transaction ID. The ID's length must not exceed 255 characters or it will
 * be ignored.
 */
@property(nonatomic, copy) NSString *transactionID;

/**
 * Sets the custom event's attribution type and ID from a UAInboxMessage.
 */
- (void)setAttributionFromMessage:(UAInboxMessage *)message;
@end
