#include <libgncyf.h>

static unsigned int  cyf_do_table(const struct nf_hook_ops *ops, struct sk_buff *skb,
		    const struct net_device *in, const struct net_device *out,
		    int (*okfn)(struct sk_buff *)){


}   

static void cyf_make_key_flowtable(struct sk_buff *skb,struct fltbl_key *key ){

    struct iphdr *iph;
	struct udphdr *udph;
	struct tcphdr *tcph;
	struct ethhdr *mh = eth_hdr(skb);
	iph = ip_hdr(skb);
    int src_port ;
	int dest_port;

	if (iph->protocol == IPPROTO_UDP)
	{	
		udph = udp_hdr(skb);
		dest_port = 	ntohs(udph->dest);
		src_port = 	ntohs(udph->source);

	}else if (iph->protocol == IPPROTO_TCP){
		tcph = tcp_hdr(skb);
		dest_port = 	ntohs(tcph->dest);
		src_port = 	ntohs(tcph->source);
	}
    new_req->key.src_port = src_port;
    new_req->key.dst_port = dest_port;
    new_req->key.vid = skb->vlan_tci;
    new_req->key.ethertype = 0x8000;
    new_req->key.protocol= iph->protocol;
    new_req->key.src_mac[5] = mh->h_source[5];
    new_req->key.src_mac[4] = mh->h_source[4];
    new_req->key.src_mac[3] = mh->h_source[3];
    new_req->key.src_mac[2] = mh->h_source[2];
    new_req->key.src_mac[1] = mh->h_source[1];
    new_req->key.src_mac[0] = mh->h_source[0];
    new_req->key.dst_mac[5] = mh->h_dest[5];
    new_req->key.dst_mac[4] = mh->h_dest[4];
    new_req->key.dst_mac[3] = mh->h_dest[3];
    new_req->key.dst_mac[2] = mh->h_dest[2];
    new_req->key.dst_mac[1] = mh->h_dest[1];
    new_req->key.dst_mac[0] = mh->h_dest[0];
    new_req->key.src_ipv4 =  iph->saddr;
    new_req->key.dst_ipv4 = iph->daddr;

    
}

static void cyf_vlan_load(){


}