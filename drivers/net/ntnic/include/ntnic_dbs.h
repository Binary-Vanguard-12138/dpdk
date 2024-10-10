/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2023 Napatech A/S
 */

#ifndef _NTNIC_DBS_H_
#define _NTNIC_DBS_H_

#include "nthw_fpga_model.h"

#define NT_DBS_RX_QUEUES_MAX (128)
#define NT_DBS_TX_QUEUES_MAX (128)

/*
 * Struct for implementation of memory bank shadows
 */

struct nthw_dbs_s {
	nthw_fpga_t *mp_fpga;
	nthw_module_t *mp_mod_dbs;
	int mn_instance;

	int mn_param_dbs_present;

	nthw_register_t *mp_reg_rx_control;
	nthw_field_t *mp_fld_rx_control_last_queue;
	nthw_field_t *mp_fld_rx_control_avail_monitor_enable;
	nthw_field_t *mp_fld_rx_control_avail_monitor_scan_speed;
	nthw_field_t *mp_fld_rx_control_used_write_enable;
	nthw_field_t *mp_fld_rx_control_used_writer_update_speed;
	nthw_field_t *mp_fld_rx_control_rx_queues_enable;

	nthw_register_t *mp_reg_tx_control;
	nthw_field_t *mp_fld_tx_control_last_queue;
	nthw_field_t *mp_fld_tx_control_avail_monitor_enable;
	nthw_field_t *mp_fld_tx_control_avail_monitor_scan_speed;
	nthw_field_t *mp_fld_tx_control_used_write_enable;
	nthw_field_t *mp_fld_tx_control_used_writer_update_speed;
	nthw_field_t *mp_fld_tx_control_tx_queues_enable;

	nthw_register_t *mp_reg_rx_init;
	nthw_field_t *mp_fld_rx_init_init;
	nthw_field_t *mp_fld_rx_init_queue;
	nthw_field_t *mp_fld_rx_init_busy;

	nthw_register_t *mp_reg_rx_init_val;
	nthw_field_t *mp_fld_rx_init_val_idx;
	nthw_field_t *mp_fld_rx_init_val_ptr;

	nthw_register_t *mp_reg_rx_ptr;
	nthw_field_t *mp_fld_rx_ptr_ptr;
	nthw_field_t *mp_fld_rx_ptr_queue;
	nthw_field_t *mp_fld_rx_ptr_valid;

	nthw_register_t *mp_reg_tx_init;
	nthw_field_t *mp_fld_tx_init_init;
	nthw_field_t *mp_fld_tx_init_queue;
	nthw_field_t *mp_fld_tx_init_busy;

	nthw_register_t *mp_reg_tx_init_val;
	nthw_field_t *mp_fld_tx_init_val_idx;
	nthw_field_t *mp_fld_tx_init_val_ptr;

	nthw_register_t *mp_reg_tx_ptr;
	nthw_field_t *mp_fld_tx_ptr_ptr;
	nthw_field_t *mp_fld_tx_ptr_queue;
	nthw_field_t *mp_fld_tx_ptr_valid;

	nthw_register_t *mp_reg_rx_idle;
	nthw_field_t *mp_fld_rx_idle_idle;
	nthw_field_t *mp_fld_rx_idle_queue;
	nthw_field_t *mp_fld_rx_idle_busy;

	nthw_register_t *mp_reg_tx_idle;
	nthw_field_t *mp_fld_tx_idle_idle;
	nthw_field_t *mp_fld_tx_idle_queue;
	nthw_field_t *mp_fld_tx_idle_busy;
};

typedef struct nthw_dbs_s nthw_dbs_t;

nthw_dbs_t *nthw_dbs_new(void);
int dbs_init(nthw_dbs_t *p, nthw_fpga_t *p_fpga, int n_instance);
void dbs_reset(nthw_dbs_t *p);

int set_rx_control(nthw_dbs_t *p,
	uint32_t last_queue,
	uint32_t avail_monitor_enable,
	uint32_t avail_monitor_speed,
	uint32_t used_write_enable,
	uint32_t used_write_speed,
	uint32_t rx_queue_enable);
int set_tx_control(nthw_dbs_t *p,
	uint32_t last_queue,
	uint32_t avail_monitor_enable,
	uint32_t avail_monitor_speed,
	uint32_t used_write_enable,
	uint32_t used_write_speed,
	uint32_t tx_queue_enable);
int set_rx_init(nthw_dbs_t *p, uint32_t start_idx, uint32_t start_ptr, uint32_t init,
	uint32_t queue);
int get_rx_init(nthw_dbs_t *p, uint32_t *init, uint32_t *queue, uint32_t *busy);
int set_tx_init(nthw_dbs_t *p, uint32_t start_idx, uint32_t start_ptr, uint32_t init,
	uint32_t queue);
int get_tx_init(nthw_dbs_t *p, uint32_t *init, uint32_t *queue, uint32_t *busy);

#endif	/* _NTNIC_DBS_H_ */