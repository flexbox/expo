// Copyright 2015-present 650 Industries. All rights reserved.

#import <ABI33_0_0UMTaskManagerInterface/ABI33_0_0UMTaskInterface.h>
#import <ABI33_0_0UMTaskManagerInterface/ABI33_0_0UMTaskLaunchReason.h>

// Interface for task consumers. Task consumers are the objects that are responsible for handling tasks.
// Consumers are getting signals from TaskManager (and service) about a few events that are happening during task's lifecycle.

@protocol ABI33_0_0UMTaskConsumerInterface <NSObject>

@property (nonatomic, strong) id<ABI33_0_0UMTaskInterface> task;

@required

/**
 *  The type of the task, like "location" or "geofencing".
 */
- (nonnull NSString *)taskType;

/**
 *  Called by ABI33_0_0UMTaskService when the task is created and associated with the consumer.
 */
- (void)didRegisterTask:(id<ABI33_0_0UMTaskInterface>)task;

@optional

/**
 *  Static method returning boolean value whether the consumer supports launch reason.
 */
+ (BOOL)supportsLaunchReason:(ABI33_0_0UMTaskLaunchReason)launchReason;

/**
 *  Version of the consumer. Increase returned number in case of any breaking changes made to the task consumer,
 *  so the existing tasks will be automatically unregistered when the native code gets upgraded.
 */
+ (NSUInteger)taskConsumerVersion;

/**
 *  Sets options for the task.
 */
- (void)setOptions:(nonnull NSDictionary *)options;

/**
 *  Called by ABI33_0_0UMTaskService to inform the consumer that the associated task is ready to be executed.
 */
- (void)didBecomeReadyToExecute;

/**
 *  Called right after the task has been unregistered.
 */
- (void)didUnregister;

/**
 *  Called by ABI33_0_0UMTaskManager when the task has been completed and we received a result from JS app.
 */
- (void)didFinish;

/**
 *  Method used to normalize task result that comes from JS app.
 */
- (NSUInteger)normalizeTaskResult:(id)result;

@end
