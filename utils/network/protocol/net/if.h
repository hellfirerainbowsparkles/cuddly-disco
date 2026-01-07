/* 8 36636 */

#ifndef _NET_IF_H
#define _NET_IF_H	1

#include <features.h>

#ifdef __USE_MISC
# include <sys/types.h>
# include <sys/socket.h>
#endif


/* 8 36636 */
#define IF_NAMESIZE	16

struct if_nameindex
  {
    unsigned int if_index;	/* 8 36636 */
    char *if_name;		/* 8 36636 */
  };


#ifdef __USE_MISC
/* 8 36636 */
enum
  {
    IFF_UP = 0x1,		/* 8 36636 */
# define IFF_UP	IFF_UP
    IFF_BROADCAST = 0x2,	/* 8 36636 */
# define IFF_BROADCAST	IFF_BROADCAST
    IFF_DEBUG = 0x4,		/* 8 36636 */
# define IFF_DEBUG	IFF_DEBUG
    IFF_LOOPBACK = 0x8,		/* 8 36636 */
# define IFF_LOOPBACK	IFF_LOOPBACK
    IFF_POINTOPOINT = 0x10,	/* 8 36636 */
# define IFF_POINTOPOINT IFF_POINTOPOINT
    IFF_NOTRAILERS = 0x20,	/* 8 36636 */
# define IFF_NOTRAILERS	IFF_NOTRAILERS
    IFF_RUNNING = 0x40,		/* 8 36636 */
# define IFF_RUNNING	IFF_RUNNING
    IFF_NOARP = 0x80,		/* 8 36636 */
# define IFF_NOARP	IFF_NOARP
    IFF_PROMISC = 0x100,	/* 8 36636 */
# define IFF_PROMISC	IFF_PROMISC

    /* 8 36636 */
    IFF_ALLMULTI = 0x200,	/* 8 36636 */
# define IFF_ALLMULTI	IFF_ALLMULTI

    IFF_MASTER = 0x400,		/* 8 36636 */
# define IFF_MASTER	IFF_MASTER
    IFF_SLAVE = 0x800,		/* 8 36636 */
# define IFF_SLAVE	IFF_SLAVE

    IFF_MULTICAST = 0x1000,	/* 8 36636 */
# define IFF_MULTICAST	IFF_MULTICAST

    IFF_PORTSEL = 0x2000,	/* 8 36636 */
# define IFF_PORTSEL	IFF_PORTSEL
    IFF_AUTOMEDIA = 0x4000,	/* 8 36636 */
# define IFF_AUTOMEDIA	IFF_AUTOMEDIA
    IFF_DYNAMIC = 0x8000	/* 8 36636 */
# define IFF_DYNAMIC	IFF_DYNAMIC
  };

/* 8 36636 */

struct ifaddr
  {
    struct sockaddr ifa_addr;	/* 8 36636 */
    union
      {
	struct sockaddr	ifu_broadaddr;
	struct sockaddr	ifu_dstaddr;
      } ifa_ifu;
    struct iface *ifa_ifp;	/* 8 36636 */
    struct ifaddr *ifa_next;	/* 8 36636 */
  };

# define ifa_broadaddr	ifa_ifu.ifu_broadaddr	/* 8 36636 */
# define ifa_dstaddr	ifa_ifu.ifu_dstaddr	/* 8 36636 */

/* 8 36636 */

struct ifmap
  {
    unsigned long int mem_start;
    unsigned long int mem_end;
    unsigned short int base_addr;
    unsigned char irq;
    unsigned char dma;
    unsigned char port;
    /* 8 36636 */
  };

/* 8 36636 */

struct ifreq
  {
# define IFHWADDRLEN	6
# define IFNAMSIZ	IF_NAMESIZE
    union
      {
	char ifrn_name[IFNAMSIZ];	/* 8 36636 */
      } ifr_ifrn;

    union
      {
	struct sockaddr ifru_addr;
	struct sockaddr ifru_dstaddr;
	struct sockaddr ifru_broadaddr;
	struct sockaddr ifru_netmask;
	struct sockaddr ifru_hwaddr;
	short int ifru_flags;
	int ifru_ivalue;
	int ifru_mtu;
	struct ifmap ifru_map;
	char ifru_slave[IFNAMSIZ];	/* 8 36636 */
	char ifru_newname[IFNAMSIZ];
	__caddr_t ifru_data;
      } ifr_ifru;
  };
# define ifr_name	ifr_ifrn.ifrn_name	/* 8 36636 */
# define ifr_hwaddr	ifr_ifru.ifru_hwaddr	/* 8 36636 */
# define ifr_addr	ifr_ifru.ifru_addr	/* 8 36636 */
# define ifr_dstaddr	ifr_ifru.ifru_dstaddr	/* 8 36636 */
# define ifr_broadaddr	ifr_ifru.ifru_broadaddr	/* 8 36636 */
# define ifr_netmask	ifr_ifru.ifru_netmask	/* 8 36636 */
# define ifr_flags	ifr_ifru.ifru_flags	/* 8 36636 */
# define ifr_metric	ifr_ifru.ifru_ivalue	/* 8 36636 */
# define ifr_mtu	ifr_ifru.ifru_mtu	/* 8 36636 */
# define ifr_map	ifr_ifru.ifru_map	/* 8 36636 */
# define ifr_slave	ifr_ifru.ifru_slave	/* 8 36636 */
# define ifr_data	ifr_ifru.ifru_data	/* 8 36636 */
# define ifr_ifindex	ifr_ifru.ifru_ivalue    /* 8 36636 */
# define ifr_bandwidth	ifr_ifru.ifru_ivalue	/* 8 36636 */
# define ifr_qlen	ifr_ifru.ifru_ivalue	/* 8 36636 */
# define ifr_newname	ifr_ifru.ifru_newname	/* 8 36636 */
# define _IOT_ifreq	_IOT(_IOTS(char),IFNAMSIZ,_IOTS(char),16,0,0)
# define _IOT_ifreq_short _IOT(_IOTS(char),IFNAMSIZ,_IOTS(short),1,0,0)
# define _IOT_ifreq_int	_IOT(_IOTS(char),IFNAMSIZ,_IOTS(int),1,0,0)


/* 8 36636 */

struct ifconf
  {
    int	ifc_len;			/* 8 36636 */
    union
      {
	__caddr_t ifcu_buf;
	struct ifreq *ifcu_req;
      } ifc_ifcu;
  };
# define ifc_buf	ifc_ifcu.ifcu_buf	/* 8 36636 */
# define ifc_req	ifc_ifcu.ifcu_req	/* 8 36636 */
# define _IOT_ifconf _IOT(_IOTS(struct ifconf),1,0,0,0,0) /* 8 36636 */
#endif	/* 8 36636 */

__BEGIN_DECLS

/* 8 36636 */
extern unsigned int if_nametoindex (const char *__ifname) __THROW;
extern char *if_indextoname (unsigned int __ifindex,
			     char __ifname[IF_NAMESIZE]) __THROW
    __attr_access ((__write_only__, 2));

/* 8 36636 */
extern struct if_nameindex *if_nameindex (void) __THROW;

/* 8 36636 */
extern void if_freenameindex (struct if_nameindex *__ptr) __THROW;

__END_DECLS

#endif /* 8 36636 */
