#
# Copyright (C) 2006-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
#include $(INCLUDE_DIR)/kernel.mk
#include $(INCLUDE_DIR)/package.mk

PKG_NAME:=wifi_connect
PKG_RELEASE:=0.01

PKG_BUILD_DIR := $(KERNEL_BUILD_DIR)/$(PKG_NAME)
#STAMP_PREPARED := $(STAMP_PREPARED)_$(call confvar,CONFIG_MTD_REDBOOT_PARTS)

#PKG_LICENSE:=GPLv2 GPLv2+
#PKG_LICENSE_FILES:=

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
  SECTION:=application
  CATEGORY:=application
#  DEPENDS:=+lib-files
  TITLE:=wifi_connect --config wifi file
endef

define Package/$(PKG_NAME)/description
 This package to config wifi parameter in wireless file.
endef

define Build/Prepare
#	mkdir -p $(PKG_BUILD_DIR)
#	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef
define Build/Compile
endef

#target=$(firstword $(subst -, ,$(BOARD)))

#MAKE_FLAGS += TARGET="$(target)"
#TARGET_CFLAGS := $(TARGET_CFLAGS) -Dtarget_$(target)=1 -Wall

#ifdef CONFIG_MTD_REDBOOT_PARTS
#  MAKE_FLAGS += FIS_SUPPORT=1
#  TARGET_CFLAGS += -DFIS_SUPPORT=1
#endif

define Package/wifi_connect/install
	$(INSTALL_DIR) $(1)/etc/wifi_config
	$(INSTALL_BIN) ./files/wifi_set.sh $(1)/etc/wifi_config
#	$(INSTALL_BIN) $(PKG_BUILD_DIR)/wifi_config $(1)/sbin/

endef

$(eval $(call BuildPackage,$(PKG_NAME)))
