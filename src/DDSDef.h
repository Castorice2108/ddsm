#ifndef _DDS_DEF_H_
#define _DDS_DEF_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define DDS_CONF_XML_FILE "/etc/dds.xml"
#define DDS_CONF_XML_FILE2 "/etc/com/dds.xml"
#define DDS_CONF_XML_FILE3 "/platform/framework/auto/com/dds.xml"
#define DDS_CONF_XML_FILE2 "/etc/mid/dds.xml"

#define DDS_DEFAULT_DOMAIN_ID (1)
#define DDS_SHM_DOMAIN_ID_1 (11)
#define DDS_SHM_DOMAIN_ID_2 (12)
#define DDS_SHM_DOMAIN_ID_3 (13)
#define DDS_SHM_DOMAIN_ID_4 (14)

static const int dds_all_shm_domainids[] = {
    DDS_SHM_DOMAIN_ID_1,DDS_SHM_DOMAIN_ID_2,DDS_SHM_DOMAIN_ID_3,DDS_SHM_DOMAIN_ID_4
};

static inline bool dds_domain_valid_shm(uint32_t domain_id){
    for (int i = 0; i < 4; i++)
    {
        if (domain_id == (uint32_t)dds_all_shm_domainids[i])
        {
            return true;
        }
    }
    return false;
}

#define DDS_MAX_TOPIC 32
#define DDS_TOPIC_NAME_MAXLEN 32
#define DDS_RECV_MAX_SAMPLE 10
#define DDS_TAKE_SLEEP_MSEC 50

typedef int32_t DDSRetCode_t;
typedef int32_t DDSEntity_t;
typedef int64_t DDSTime_t;
typedef int64_t DDSDuration_t;

#define DDS_N_IN_S INT64_C(1000000000)
#define DDS_N_IN_M INT64_C(1000000)
#define DDS_N_IN_USEC INT64_C(1000)
#define DDS_FORMAT_SECS(n) ((n) * DDS_N_IN_S)
#define DDS_FORMAT_MSECS(n) ((n) * DDS_N_IN_M)
#define DDS_FORMAT_USECS(n) ((n) * DDS_N_IN_USEC)

typedef enum DDS_DATA_READ_STATE
{
    DDS_DATA_READ_STATE_READ,
    DDS_DATA_READ_STATE_NOTREAD
}DDS_DATA_READ_STATE_t;

typedef enum DDS_DATA_VIEW_STATE
{
    DDS_DATA_VIEW_STATE_NEW,
    DDS_DATA_VIEW_STATE_NOTVIEW
}DDS_DATA_VIEW_STATE_t;

typedef enum DDS_INST_STATE
{
    DDS_INST_STATE_ALIVE,
    DDS_INST_STATE_DISPOSED,
    DDS_INST_STATE_NOT_ALIVE_NO_WRITERS
}DDS_INST_STATE_t;

typedef struct DDSInitConfig
{
    bool interface_autodetermine;
    char interface_address[32];
    char interface_name[16];
}DDSInitConfig;

#define DDS_INITCFG_INITIALIZER {true, {0}, {0}}

typedef struct DDS_DATA_INFO
{
    DDS_DATA_READ_STATE_t sample_state;
    DDS_DATA_VIEW_STATE_t view_state;
    DDS_INST_STATE_t instance_state;
    bool valid_data;
    DDSTime_t source_timestamp;
    uint64_t instance_handle;
    uint64_t publication_handle;
    uint32_t disposed_generation_count;
    uint32_t no_writers_generation_count;
    uint32_t sample_rank;
    uint32_t generation_rank;
    uint32_t absolute_generation_rank;
}DDS_DATA_INFO_t

typedef struct DDSPubConf
{
    bool wait_connect;
    int wait_max_time;
    bool skip_pub_ifnotconnect;
}DDSPubConf_t

typedef enum DDS_FRAME_SIZE
{
    DDS_FRAME_SIZE_ULIMITED = 0;
    DDS_FRAME_SIZE_64B,
    DDS_FRAME_SIZE_256B,
    DDS_FRAME_SIZE_512B,
    DDS_FRAME_SIZE_1024B,
    DDS_FRAME_SIZE_4096B,
    DDS_FRAME_SIZE_10K,
    DDS_FRAME_SIZE_100K,
    DDS_FRAME_SIZE_1M,
    DDS_FRAME_SIZE_4M,
    DDS_FRAME_SIZE_8M,
}DDS_FRAME_SIZE;

static inline bool is_valid_shm_size(DDS_FRAME_SIZE fsize)
{
    return (fsize >= DDS_FRAME_SIZE_64B && fsize <= DDS_FRAME_SIZE_8M);
}

typedef void (*dds_callback_handler)(void *dataptr, uint32_t data_len, uint32_t sessionid);
typedef void (*dds_callback_handler_allinfo)(DDSEntity_t topic, const char * topic_n, void *dataptr, uint32_t data_len, void *args, DDS_DATA_INFO_t *datainfos);


#define DDS_RET_OK (0)
#define DDS_RET_ERROR (-1)
#define DDS_RET_UNSUPPORTED (-2)
#define DDS_RET_BAD_PARAMETER (-3)






#ifdef __cplusplus
}
#endif
#endif