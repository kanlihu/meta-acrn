DISTRO = "acrn-demo"
DISTRO_NAME = "ACRN Demo"
DISTRO_VERSION = "4.2+snapshot-${DATE}"

DISTRO_FEATURES = "${DISTRO_FEATURES_DEFAULT} \
                   systemd efi largefile opengl ptest multiarch \
                   wayland vulkan pulseaudio bluez5 gobject-introspection-data \
                   pam usrmerge"

VIRTUAL-RUNTIME_init_manager = "systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
# systemd hardcodes /root in its source codes, other values are not offically supported
ROOT_HOME = "/root"

WARN_TO_ERROR_QA = "already-stripped compile-host-path install-host-path \
                    installed-vs-shipped ldflags pn-overrides rpaths staticdev \
                    unknown-configure-option useless-rpaths"
WARN_QA:remove = "${WARN_TO_ERROR_QA}"
ERROR_QA:append = " ${WARN_TO_ERROR_QA}"

require conf/distro/include/no-static-libs.inc
require conf/distro/include/yocto-uninative.inc
require conf/distro/include/security_flags.inc
INHERIT += "uninative"

# Set the Sato network manager to be systemd, instead of connman.
# The Service VM needs to use networkd to get the bridges working correctly, and
# networkd makes guest networking trivial.
NETWORK_MANAGER = "systemd"
