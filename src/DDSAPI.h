#ifndef _DDS_API_H_
#define _DDS_API_H_

#include <stdint.h>
#include "DDSDef.h"
#include "DDSQoS.h"


#ifdef __cplusplus
extern "C"
{
#endif

DDSEntity_t DDSCreateParticipant(uint32_t domain_id, const DDSQoS_t *participantQoS, const char *ddsconf_file);
DDSEntity_t DDSCreateParticipantWithCfg(uint32_t domain_id, const DDSQoS_t *participantQoS, DDSInitConfig *cfg);
DDSEntity_t DDSCloseParticipant(DDSEntity_t participant);
DDSEntity_t DDSRegisterTopic(DDSEntity_t participant, const char *topic_name, DDSQoS_t *topic_qos, DDSQoS_t *writer_qos, DDSQoS_t *reader_qos);
DDSEntity_t DDSRegisterCustomSizeTopic(DDSEntity_t participant, const char *topic_name, DDS_FRAME_SIZE frame_sz, DDSQoS_t *topic_qos, DDSQoS_t *writer_qos, DDSQoS_t *reader_qos);
DDSEntity_t DDSRegisterSHMTopic(DDSEntity_t participant, const char *topic_name, DDS_FRAME_SIZE frame_sz);
DDSRetCode_t DDSUnRegisterTopic(DDSEntity_t participant, DDSEntity_t topic);
DDSRetCode_t DDSUnRegisterTopic_n(DDSEntity_t participant, const char *topic_name);
DDSRetCode_t DDSPublishData(DDSEntity_t participant, DDSEntity_t topic, void *data, size_t data_sz, DDSPubConf_t *pub_conf);
DDSRetCode_t DDSPublishData_n(DDSEntity_t participant, const char *topic_name, void *data, size_t data_sz, DDSPubConf_t *pub_conf);
DDSRetCode_t DDSSubscribeData(DDSEntity_t participant, DDSEntity_t topic, dds_callback_handler data_recv);
DDSRetCode_t DDSSubscribeData_n(DDSEntity_t participant, const char *topic_name, dds_callback_handler data_recv);
DDSRetCode_t DDSSubscribeDataAll(DDSEntity_t participant, DDSEntity_t topic, dds_callback_handler_allinfo data_recv, void *arg);
DDSRetCode_t DDSCancelSubscribeTopic(DDSEntity_t participant, DDSEntity_t topic);
DDSRetCode_t DDSCancelSubscribeTopic_n(DDSEntity_t participant, const char *topic_name);
const char *DDSDescRetCode(DDSRetCode_t ret__);
DDSTime_t DDSGetTime();
void DDSSleep(DDSDuration_t t);
bool DDSGetWriterStatus(DDSEntity_t participant, DDSEntity_t topic, char *desc, uint32_t desc_sz);
uint32_t DDSGetPubsConnectedStatus(DDSEntity_t participant, DDSEntity_t topic, uint32_t *current_subs);
DDSEntity_t DDSGetSubConnectedPubs(DDSEntity_t participant, DDSEntity_t topic, uint32_t *current_pubs);
bool DDSGetTopicHasBeenSubscribed(DDSEntity_t participant, DDSEntity_t topic);
DDSEntity_t DDSFindTopicInParticipant(DDSEntity_t participant, const char *topic_name);
const char *DDSGetTopicName(DDSEntity_t participant, DDSEntity_t topic);
uint32_t DDSGetDomain(DDSEntity_t participant);
void DDSGetVersionInfo(DDSMVersionInfo *verinfo);
bool DDS_IS_IOXROUDI_Working();
DDSRetCode_t DDSDelete(DDSEntity_t entity);

#ifdef __cplusplus
}
#endif
#endif