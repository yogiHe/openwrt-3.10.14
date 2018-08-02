#
# Copyright (C) 2007-2014 OpenWrt.org
# Copyright (C) 2010 Vertical Communications
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/version.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=appdbg
PKG_RELEASE:=0.01


PKG_BUILD_DIR := $(KERNEL_BUILD_DIR)/$(PKG_NAME)

#PKG_FILE_DEPENDS:=$(PLATFORM_DIR)/ $(GENERIC_PLATFORM_DIR)/$(PKG_NAME)/
#PKG_BUILD_DEPENDS:=

include $(INCLUDE_DIR)/package.mk


define Package/$(PKG_NAME)
  SECTION:=application
  CATEGORY:=application
#  DEPENDS:=+libpthread +libnvram +libDebugPrint +libGwRead
  TITLE:=debug for application
endef



define Package/$(PKG_NAME)/description
	debug for application
endef



define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

TARGET_CFLAGS += \
	-I$(LINUX_DIR)/drivers/char \
	$(foreach c, $(PKG_KCONFIG),$(if $(CONFIG_$c),-DCONFIG_$(c)))

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
	CC="$(TARGET_CC)" \
	CFLAGS="$(TARGET_CFLAGS) -Wall" \
	LDFLAGS="$(TARGET_LDFLAGS)"
endef

Build/Compile = $(Build/Compile/Default)

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/bin
#	$(INSTALL_BIN) ./files/wifi_set.sh $(1)/etc/wifi_config
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/bin/

endef


$(eval $(call BuildPackage,$(PKG_NAME)))
