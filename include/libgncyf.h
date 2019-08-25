#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux_list.h>
#include <libctfw/fltbl_api.h>
#include <libctfw/fltbl.h>
#define VLAN_TABLE "/etc/cyf_vlan"
#define DNS_TABLE "/etc/cyf_dns"
#define DHCP_TABLE "/etc/cyf_dhcp"

typedef struct cyf_vlan{
    struct list_head list;
    int vlan_id;
    char alias[512];
    char inf_name[512];
    u_int8_t address_mod;
    char ip_mask[128];
}cyf_vlan_t;

typedef struct cyf_dhcp{
    u_int8_t mod;
    char start_ip[64];
    char end_ip[64];
    char netmask[64];
    char default_gateway[64];
    char dns_server;
    u_int64_t lease_time;
} cyf_dhcp_t;

typedef struct cyf_dns{
    char primary_dns[64];
    char second_dns[64];
    char local_domain[128];
} cyf_dns_t;

static void cyf_vlan_load();
static unsigned int cyf_do_table(const struct nf_hook_ops *ops, struct sk_buff *skb,
		    const struct net_device *in, const struct net_device *out,
		    int (*okfn)(struct sk_buff *));
static void cyf_make_key_flowtable(struct sk_buff *skb,struct fltbl_key *key );
