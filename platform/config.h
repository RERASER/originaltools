#pragma once

#include <windows.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct amvideo_config {
    bool enable;
};

struct hwmon_config {
    bool enable;
};

struct misc_config {
    bool enable;
};

struct nusec_config {
    bool enable;
    char keychip_id[16];
    char game_id[4];
    char platform_id[4];
    uint8_t region;
    uint8_t system_flag;
    uint32_t subnet;
    wchar_t billing_ca[MAX_PATH];
    wchar_t billing_pub[MAX_PATH];
};

struct vfs_config {
    bool enable;
    wchar_t amfs[MAX_PATH];
    wchar_t appdata[MAX_PATH];
};

struct nu_config {
    struct amvideo_config amvideo;
    struct hwmon_config hwmon;
    struct misc_config misc;
    struct nusec_config nusec;
    struct vfs_config vfs;
};

void nu_config_load(struct nu_config *cfg,const wchar_t *filename);
void amvideo_config_load(struct amvideo_config *cfg, const wchar_t *filename);
void hwmon_config_load(struct hwmon_config *cfg, const wchar_t *filename);
void misc_config_load(struct misc_config *cfg, const wchar_t *filename);
void nusec_config_load(struct nusec_config *cfg, const wchar_t *filename);
void vfs_config_load(struct vfs_config *cfg, const wchar_t *filename);