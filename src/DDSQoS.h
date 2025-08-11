#ifndef _DDS_QOS_H_
#define _DDS_QOS_H_
#include "DDSDef.h"
#ifdef __cplusplus
extern "C"
{
#endif

struct dds_qos_t;
typedef struct dds_qos_t DDSQoS_t;

typedef enum DDSDurabilityKind
{
    DDSDurabilityVolatile,
    DDSDurabilityTransientLocal,
    DDSDurabilityTransient,
    DDSDurabilityPersistent
}DDSDurabilityKind_t;

typedef enum DDSHistoryKind
{
    DDSHistoryKeepLast,
    DDSHistoryKeepAll
}DDSHistoryKind_t;

typedef enum DDSLivelinessKind
{
    DDSLivelinessAutomatic,
    DDSLivelinessManualByParticpant,
    DDSLivelinessManualByTopic
}DDSLivelinessKind_t;


typedef enum DDSReliabilityKind
{
    DDSReliabilityBestEffort,
    DDSReliabilityReliable
}DDSReliabilityKind_t;

typedef enum DDSDestinationOrderKind
{
    DDSDestinationOrderByReceptionTimestamp,
    DDSDestinationOrderBySourceTimestamp
}DDSDestinationOrderKind_t;

DDSQoS_t *DDSQosInit();
void DDSQoSDelete(DDSQoS_t *__restrict qos);
void DDSQoSReset(DDSQoS_t *__restrict qos);
void DDSQoSCopy(DDSQoS_t *__restrict dst, DDSQoS_t *__restrict src);
void DDSQoSMerge(DDSQoS_t *__restrict dst, DDSQoS_t *__restrict src);
bool DDSQoSEqual(DDSQoS_t *__restrict a, DDSQoS_t *__restrict b);


void DDSQSetUserData(DDSQoS_t *__restrict qos, const void* __restrict value, size_t sz);
void DDSQSetTopicData(DDSQoS_t *__restrict qos, const void *__restrict value, size_t sz);
void DDSQSetDurability(DDSQoS_t *__restrict qos, DDSDurabilityKind_t durability);
void DDSQSetHistory(DDSQoS_t *__restrict qos, DDSHistoryKind_t history, int32_t depth);
void DDSQSetResourceLimits(DDSQoS_t *__restrict qos, int32_t max_samples, int32_t max_instances, int32_t max_samples_per_instance);
void DDSQSetLifespan(DDSQoS_t *__restrict qos, DDSTime_t lifespan);
void DDSQSetLiveliness(DDSQoS_t *__restrict qos, DDSLivelinessKind_t liveliness, DDSTime_t lease_duration);
void DDSQSetReliability(DDSQoS_t *__restrict qos, DDSReliabilityKind_t reliability, DDSTime_t max_blocking_time);
void DDSQSetDestination_order(DDSQoS_t *__restrict qos, DDSDestinationOrderKind_t order);
/* extend method */
DDSQoS_t *DDSQoSCreateSHMQoS(int historyDeep, int resourcelimit);


#ifdef __cplusplus
}
#endif
#endif