#ifndef _CCGROUP_H_
#define _CCGROUP_H_

#include <time.h>
#include <stdbool.h>

struct condor_group {
	char name[256];		/*!< Name of cgroup under root */
	char root_path[60];	/*!< Path where cgroup is mounted */
	char slot_name[16];	/*!< Extracted slot name */
	uint32_t sort_order;
	uint32_t num_procs;
	uint32_t num_tasks;
	uint64_t cpu_shares;
	uint64_t user_cpu_usage;
	uint64_t sys_cpu_usage;
	uint64_t rss_used;
	uint64_t swap_used;
	uint64_t cache_used;
	time_t start_time;
};

extern const char *default_cgroup_name;

void get_condor_cgroups(const char *controller, const char *condor_cgroup);
void get_cgroup_statistics(const char *cgroup_name);

bool group_for_each(struct condor_group **g);
bool groups_empty(void);
void cleanup_groups(void);

#endif
