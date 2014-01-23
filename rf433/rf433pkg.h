//*******************************************************************************
// Copyright (C), RHTECH. Co., Ltd.
// Author:          redfox.qu@qq.com
// Date:            2014/01/08
// Version:         1.0.0
// Description:     The 433Mhz module package struct header file
//
// History:
//      <author>            <time>      <version>   <desc>
//      redfox.qu@qq.com    2014/01/08  1.0.0       create this file
//
// TODO:
//*******************************************************************************

#ifndef __RF433_PKG_H__
#define __RF433_PKG_H__

#include <stdint.h>

#pragma pack (1)

typedef struct {
    uint8_t sp[2];                          /* ���ǰ���� */
    uint8_t len;                            /* ���س��� */
    uint8_t crc1;                           /* �ײ�У�� */
} rswp433_pkg_header;

typedef struct {
    uint8_t type;                           /* ���������� */
    float data;                             /* ���������ݣ�����IEEE745��������ʽ */
    uint8_t vol;                            /* ��������ѹ��0xAB��ʾA.B�� */
    uint8_t batt;                           /* ���ʣ�������0-0x64��ʾ0%-100% */
    uint8_t flag;                           /* Ѳ��ң�������� */
    uint8_t watchid;
} rswp433_data;

typedef struct {
    uint32_t dest_addr;                     /* 433����Ŀ���ַ */
    uint32_t src_addr;                      /* 433����Դ��ַ */
    uint8_t cmd;                            /* RSWP433����Э�������� */
    uint8_t crc2;                           /* RSWP433����Э�鱨��У�� */
} rswp433_pkg_content;

typedef struct {
    uint32_t dest_addr;                     /* 433����Ŀ���ַ */
    uint32_t src_addr;                      /* 433����Դ��ַ */
    uint8_t cmd;                            /* RSWP433����Э�������� */
    rswp433_data data;                      /* RSWP433���ߴ��������� */
    uint8_t crc2;                           /* RSWP433����Э�鱨��У�� */
} rswp433_pkg_data_content;

typedef struct {                            /* RSWP433����Э�鱨�ĸ�ʽ */
    rswp433_pkg_header header;
    union {
        rswp433_pkg_content content;
        rswp433_pkg_data_content data_content;
    } u;
} rswp433_pkg;

typedef struct {
    uint32_t addr;                          /* 433���ߴ�������ַ */
    rswp433_data data;                      /* 433���ߴ��������� */
    time_t last_req_tm;                     /* 433���ߴ������������ʱ�� */
    int req_cnt;                            /* 433���ߴ������������ */
    int rsp_cnt;                            /* 433���ߴ�������Ӧ���� */
} se433_data;

#pragma pack ()

#endif  //__RF433_PKG_H__

