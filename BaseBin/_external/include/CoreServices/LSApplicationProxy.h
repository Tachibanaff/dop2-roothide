#import "LSBundleProxy.h"
@interface LSApplicationProxy : LSBundleProxy
@property (getter=isInstalled,nonatomic,readonly) BOOL installed;
+ (instancetype)applicationProxyForIdentifier:(NSString *)identifier;
@end