/*
 * Copyright 2012 StreetHawk
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Created by Christine XYS    Jan 08, 2014
 */

#import <Cordova/CDV.h>
#import <StreetHawkCoreCompact/StreetHawkCoreCompact.h>

/*
 * Class hosting streethawk's API for phonegap
 */
@interface Streethawk : CDVPlugin <ISHPhonegapObserver, ISHCustomiseHandler>

//////////////////  Functions  ///////////////////////////////////

/**
 * Initialise Streethawk. Command arguement is empty. Before calling this function, make sure following properties are setup correctly, otherwise default value will be used. 
 * shSetEnableLogs(true/false), by default use false.
 * shSetiTunesId(string_value), by default use null.
 */
- (void)streethawkinit:(CDVInvokedUrlCommand *)command;

/**
 * Tag numeric for a key. Command arguement is [key_string, number_value];
 */
- (void)tagNumeric:(CDVInvokedUrlCommand *)command;

/**
 * Tag string for a key. Command arguement is [key_string, string_value];
 */
- (void)tagString:(CDVInvokedUrlCommand *)command;

/**
 * Tag datetime for a key. Command arguement is [key_string, datetime_value];
 */
- (void)tagDatetime:(CDVInvokedUrlCommand *)command;

/**
 * Increment tag for a key. Command arguement is [key_string];
 */
- (void)incrementTag:(CDVInvokedUrlCommand *)command;

/**
 * Remove tag for a key. Command arguement is [key_string];
 */
- (void)removeTag:(CDVInvokedUrlCommand *)command;

/**
 * Send dictionary for tag user. Command arguement is array contains a dictionary. It will be deprecated in next release, iOS not implement it.
 */
- (void)sendLogForTagUser:(CDVInvokedUrlCommand *)command;

/**
 * Send log to trace current page is entered. Command arguement is [view_string]. 
 */
- (void)currentPage:(CDVInvokedUrlCommand *)command;

/**
 * Send feedback with only title and message to StreetHawk server. Command arguement is [title_string, message_string].
 */
- (void)shSendSimpleFeedback:(CDVInvokedUrlCommand *)command;

/**
 * Send custom activity, which defines mapping of [friendly_name: view_name]. Command arguement is array contains an array each is a dictionary, for example [[{SettingsPG:"settings"}, {home:"index"}]].
 */
- (void)shCustomActivityList:(CDVInvokedUrlCommand *)command;

/**
 * Get stored view name for push 8004, this is used for App launches and check whether a 8004 push notification occured. If this App is waken up by 8004 push notification, the view name is stored locally and read by this function, so that App knows a specific page should be loaded.
 */
- (void)shGetViewName:(CDVInvokedUrlCommand *)command;

/**
 * Callback for directing to page when 8004 happen and App in FG.
 */
- (void)shRegisterViewCallback:(CDVInvokedUrlCommand *)command;

/**
 * Callback for handling 8049 json push.
 */
- (void)shRawJsonCallback:(CDVInvokedUrlCommand *)command;

/**
 * Callback for handling open url.
 */
- (void)shDeeplinking:(CDVInvokedUrlCommand *)command;

/**
 * Reports manual locations to streethawk server.
 */
- (void)shSetManualLocation:(CDVInvokedUrlCommand *)command;

//////////////////  Properties  ///////////////////////////////////

/**
 * Get current Streethawk library version. Command return string like "1/1.3.3".
 */
- (void)getSHLibraryVersion:(CDVInvokedUrlCommand *)command;

/**
 * Get current datetime string in Streethawk format (UTC and yyyy-MM-dd HH:mm:ss). Command return string like "2014-12-26 50:32:17".
 */
- (void)getCurrentFormattedDateTime:(CDVInvokedUrlCommand *)command;

/**
 * Set whether enable console log for debugging. Command arguement is [bool_value].
 */
- (void)shSetEnableLogs:(CDVInvokedUrlCommand *)command;

/**
 * Get whether enable console log for debugging. Command returns bool value.
 */
- (void)shEnableLogs:(CDVInvokedUrlCommand *)command;

/**
 * Set iTunes registered App Id. Command arguement is [string_value] like ['507040546'] or [''] or [null] if not register yet.
 */
- (void)shSetiTunesId:(CDVInvokedUrlCommand *)command;

/**
 * Get iTunes registered App Id. Command returns string value.
 */
- (void)shiTunesId:(CDVInvokedUrlCommand *)command;

/**
 * Set is push notification is enabled by default, set this to false to avoid asking system permission when App launch. Command arguement is [bool_value].
 */
- (void)shSetDefaultPushNotificationSupport:(CDVInvokedUrlCommand *)command;

/**
 * Set whether support push notification, set this later to have push notification enabled and ask for permission. Command arguement is [bool_value].
 */
- (void)shSetIsPushNotificationEnabled:(CDVInvokedUrlCommand *)command;

/**
 * Get whether support push notification. Command return bool.
 */
- (void)shIsPushNotificationEnabled:(CDVInvokedUrlCommand *)command;

/**
 * Set is location service is enabled by default, set this to false to avoid asking system permission when App launch. Command arguement is [bool_value].
 */
- (void)shSetDefaultLocationSupport:(CDVInvokedUrlCommand *)command;

/**
 * Set whether enable location service, set this later to have location service enabled and ask for permission. Command arguement is [bool_value].
 */
- (void)shSetIsUseLocation:(CDVInvokedUrlCommand *)command;

/**
 * Get whether enable location service. Command return bool.
 */
- (void)shIsUseLocation:(CDVInvokedUrlCommand *)command;

/**
 * Set alert settings times measured by minutes. Command arguement is [int_value].
 */
- (void)shSetAlertSetting:(CDVInvokedUrlCommand *)command;

/**
 * Get alert settings times measured by minutes. Command return int.
 */
- (void)shAlertSettings:(CDVInvokedUrlCommand *)command;

//////////////////  None iOS Implementation  ///////////////////////////////////

/**
 * Android needs this function to send install/log when App from BG to FG. iOS SDK has handle this inside already, this function is empty.
 */
- (void)shOnResume:(CDVInvokedUrlCommand *)command;

/**
 * Android needs this function to send install/log when App from FG to BG. iOS SDK has handle this inside already, this function is empty.
 */
- (void)shOnPause:(CDVInvokedUrlCommand *)command;

/**
 * Nothing to do in iOS part. ios doesn't support third party beacon library.
 */
- (void)shEnterBeacon:(CDVInvokedUrlCommand *)command;

/**
 * Nothing to do in iOS part. ios doesn't support third party beacon library.
 */
- (void)shExitBeacon:(CDVInvokedUrlCommand *)command;

/**
 * Nothing to do in iOS part. ios doesn't support third party beacon library.
 */
- (void)shSetBeaconSupport:(CDVInvokedUrlCommand *)command;

/**
 * Displays badge for feeds. Not supported in ios now.
 */
- (void)displayBadge:(CDVInvokedUrlCommand *)command;

/**
 * Android function, ignored in ios.
 */
- (void)shSetGcmSenderId:(CDVInvokedUrlCommand *)command;

@end
