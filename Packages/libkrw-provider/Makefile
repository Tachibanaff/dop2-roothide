TARGET = libkrw-plugin.dylib
CC = clang

CFLAGS = -I../../BaseBin/.include -Isrc -isysroot $(shell xcrun --sdk iphoneos --show-sdk-path) -arch arm64 -arch arm64e -miphoneos-version-min=15.0 -fobjc-arc -O2
LDFLAGS = -dynamiclib -rpath @loader_path/.jbroot -L../../BaseBin/.build -ljailbreak

all: $(TARGET) sign

sign: $(TARGET)
	@ldid -S $^

$(TARGET): $(wildcard src/*.c)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	install_name_tool -change "@loader_path/libjailbreak.dylib" "@rpath/usr/lib/libjailbreak.dylib" $@

clean:
	@rm -f $(TARGET)
	@rm -f libkrw-plugin.deb

package: all
	@mkdir -p .package/DEBIAN
	@mkdir -p .package/usr/lib/libkrw
	@cp control .package/DEBIAN/control
	@cp libkrw-plugin.dylib .package/usr/lib/libkrw/libkrw-plugin.dylib
	@dpkg-deb --root-owner-group -Zzstd -b .package ./libkrw-plugin.deb
	@rm -rf .package
