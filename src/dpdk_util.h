#ifndef __DPDK_UTIL_H__
#define __DPDK_UTIL_H__

#include <rte_ethdev.h>
#include <stdint.h>

#include <rte_atomic.h>
#include <rte_eal.h>
#include <rte_errno.h>
#include <rte_ethdev.h>
#include <rte_ether.h>
#include <rte_flow.h>
#include <rte_ip.h>
#include <rte_log.h>
#include <rte_malloc.h>
#include <rte_mbuf.h>
#include <rte_mempool.h>
#include <rte_ring.h>
#include <rte_udp.h>

#include "udp_util.h"

#define DEFAULT_SEED 7
#define BURST_SIZE 8
#define RING_ELEMENTS 512 * 1024
#define MEMPOOL_CACHE_SIZE 512
#define MAX_RTE_FLOW_PATTERN 4
#define MAX_RTE_FLOW_ACTIONS 4
#define PKTMBUF_POOL_ELEMENTS 512 * 1024 - 1
#define RTE_LOGTYPE_UDP_GENERATOR RTE_LOGTYPE_USER1

extern uint32_t min_lcores;
extern uint64_t TICKS_PER_US;
extern struct rte_ring *rx_ring;
extern struct rte_mempool *pktmbuf_pool_tx;
extern control_block_t *control_blocks;

void clean_hugepages ();
void print_DPDK_stats ();
void insert_flow (uint16_t portid, uint32_t i);
void init_DPDK (uint16_t portid, uint64_t nr_queues);
void create_dpdk_rings ();
int init_DPDK_port (uint16_t portid, uint16_t nb_rx_queue,
                    uint16_t nb_tx_queue, struct rte_mempool *mbuf_pool);

#endif // __DPDK_UTIL_H__
