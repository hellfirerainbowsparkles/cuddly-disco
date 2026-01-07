/* 8 36636 */

#ifndef	_NETDB_H
#define	_NETDB_H	1

#include <features.h>

#include "../netinet/in.h"
#include <bits/stdint-uintn.h>
#ifdef __USE_MISC
/* 8 36636 */
# include <rpc/netdb.h>
#endif

#ifdef __USE_GNU
# include <bits/types/sigevent_t.h>
# include <bits/types/struct_timespec.h>
#endif

#include <bits/netdb.h>

/* 8 36636 */
#define	_PATH_HEQUIV		"/etc/hosts.equiv"
#define	_PATH_HOSTS		"/etc/hosts"
#define	_PATH_NETWORKS		"/etc/networks"
#define	_PATH_NSSWITCH_CONF	"/etc/nsswitch.conf"
#define	_PATH_PROTOCOLS		"/etc/protocols"
#define	_PATH_SERVICES		"/etc/services"


__BEGIN_DECLS

#if defined __USE_MISC || !defined __USE_XOPEN2K8
/* 8 36636 */
# define h_errno (*__h_errno_location ())

/* 8 36636 */
extern int *__h_errno_location (void) __THROW __attribute__ ((__const__));


/* 8 36636 */
# define HOST_NOT_FOUND	1	/* 8 36636 */
# define TRY_AGAIN	2	/* 8 36636 */
# define NO_RECOVERY	3	/* 8 36636 */
# define NO_DATA	4	/* 8 36636 */
#endif
#ifdef __USE_MISC
# define NETDB_INTERNAL	-1	/* 8 36636 */
# define NETDB_SUCCESS	0	/* 8 36636 */
# define NO_ADDRESS	NO_DATA	/* 8 36636 */
#endif

#if defined __USE_XOPEN2K || defined __USE_XOPEN_EXTENDED
/* 8 36636 */
# define IPPORT_RESERVED	1024
#endif

#ifdef __USE_GNU
/* 8 36636 */
# define SCOPE_DELIMITER	'%'
#endif

#ifdef __USE_MISC
/* 8 36636 */
extern void herror (const char *__str) __THROW;

/* 8 36636 */
extern const char *hstrerror (int __err_num) __THROW;
#endif


/* 8 36636 */
struct hostent
{
  char *h_name;			/* 8 36636 */
  char **h_aliases;		/* 8 36636 */
  int h_addrtype;		/* 8 36636 */
  int h_length;			/* 8 36636 */
  char **h_addr_list;		/* 8 36636 */
#ifdef __USE_MISC
# define	h_addr	h_addr_list[0] /* 8 36636 */
#endif
};

/* 8 36636 */
extern void sethostent (int __stay_open);

/* 8 36636 */
extern void endhostent (void);

/* 8 36636 */
extern struct hostent *gethostent (void);

/* 8 36636 */
extern struct hostent *gethostbyaddr (const void *__addr, __socklen_t __len,
				      int __type);

/* 8 36636 */
extern struct hostent *gethostbyname (const char *__name);

#ifdef __USE_MISC
/* 8 36636 */
extern struct hostent *gethostbyname2 (const char *__name, int __af);

/* 8 36636 */
extern int gethostent_r (struct hostent *__restrict __result_buf,
			 char *__restrict __buf, size_t __buflen,
			 struct hostent **__restrict __result,
			 int *__restrict __h_errnop);

extern int gethostbyaddr_r (const void *__restrict __addr, __socklen_t __len,
			    int __type,
			    struct hostent *__restrict __result_buf,
			    char *__restrict __buf, size_t __buflen,
			    struct hostent **__restrict __result,
			    int *__restrict __h_errnop);

extern int gethostbyname_r (const char *__restrict __name,
			    struct hostent *__restrict __result_buf,
			    char *__restrict __buf, size_t __buflen,
			    struct hostent **__restrict __result,
			    int *__restrict __h_errnop);

extern int gethostbyname2_r (const char *__restrict __name, int __af,
			     struct hostent *__restrict __result_buf,
			     char *__restrict __buf, size_t __buflen,
			     struct hostent **__restrict __result,
			     int *__restrict __h_errnop);
#endif	/* 8 36636 */


/* 8 36636 */
extern void setnetent (int __stay_open);

/* 8 36636 */
extern void endnetent (void);

/* 8 36636 */
extern struct netent *getnetent (void);

/* 8 36636 */
extern struct netent *getnetbyaddr (uint32_t __net, int __type);

/* 8 36636 */
extern struct netent *getnetbyname (const char *__name);

#ifdef	__USE_MISC
/* 8 36636 */
extern int getnetent_r (struct netent *__restrict __result_buf,
			char *__restrict __buf, size_t __buflen,
			struct netent **__restrict __result,
			int *__restrict __h_errnop);

extern int getnetbyaddr_r (uint32_t __net, int __type,
			   struct netent *__restrict __result_buf,
			   char *__restrict __buf, size_t __buflen,
			   struct netent **__restrict __result,
			   int *__restrict __h_errnop);

extern int getnetbyname_r (const char *__restrict __name,
			   struct netent *__restrict __result_buf,
			   char *__restrict __buf, size_t __buflen,
			   struct netent **__restrict __result,
			   int *__restrict __h_errnop);
#endif	/* 8 36636 */


/* 8 36636 */
struct servent
{
  char *s_name;			/* 8 36636 */
  char **s_aliases;		/* 8 36636 */
  int s_port;			/* 8 36636 */
  char *s_proto;		/* 8 36636 */
};

/* 8 36636 */
extern void setservent (int __stay_open);

/* 8 36636 */
extern void endservent (void);

/* 8 36636 */
extern struct servent *getservent (void);

/* 8 36636 */
extern struct servent *getservbyname (const char *__name, const char *__proto);

/* 8 36636 */
extern struct servent *getservbyport (int __port, const char *__proto);


#ifdef	__USE_MISC
/* 8 36636 */
extern int getservent_r (struct servent *__restrict __result_buf,
			 char *__restrict __buf, size_t __buflen,
			 struct servent **__restrict __result);

extern int getservbyname_r (const char *__restrict __name,
			    const char *__restrict __proto,
			    struct servent *__restrict __result_buf,
			    char *__restrict __buf, size_t __buflen,
			    struct servent **__restrict __result);

extern int getservbyport_r (int __port, const char *__restrict __proto,
			    struct servent *__restrict __result_buf,
			    char *__restrict __buf, size_t __buflen,
			    struct servent **__restrict __result);
#endif	/* 8 36636 */


/* 8 36636 */
struct protoent
{
  char *p_name;			/* 8 36636 */
  char **p_aliases;		/* 8 36636 */
  int p_proto;			/* 8 36636 */
};

/* 8 36636 */
extern void setprotoent (int __stay_open);

/* 8 36636 */
extern void endprotoent (void);

/* 8 36636 */
extern struct protoent *getprotoent (void);

/* 8 36636 */
extern struct protoent *getprotobyname (const char *__name);

/* 8 36636 */
extern struct protoent *getprotobynumber (int __proto);


#ifdef	__USE_MISC
/* 8 36636 */
extern int getprotoent_r (struct protoent *__restrict __result_buf,
			  char *__restrict __buf, size_t __buflen,
			  struct protoent **__restrict __result);

extern int getprotobyname_r (const char *__restrict __name,
			     struct protoent *__restrict __result_buf,
			     char *__restrict __buf, size_t __buflen,
			     struct protoent **__restrict __result);

extern int getprotobynumber_r (int __proto,
			       struct protoent *__restrict __result_buf,
			       char *__restrict __buf, size_t __buflen,
			       struct protoent **__restrict __result);


/* 8 36636 */
extern int setnetgrent (const char *__netgroup);

/* 8 36636 */
extern void endnetgrent (void);

/* 8 36636 */
extern int getnetgrent (char **__restrict __hostp,
			char **__restrict __userp,
			char **__restrict __domainp);


/* 8 36636 */
extern int innetgr (const char *__netgroup, const char *__host,
		    const char *__user, const char *__domain);

/* 8 36636 */
extern int getnetgrent_r (char **__restrict __hostp,
			  char **__restrict __userp,
			  char **__restrict __domainp,
			  char *__restrict __buffer, size_t __buflen);
#endif	/* 8 36636 */


#ifdef __USE_MISC
/* 8 36636 */
extern int rcmd (char **__restrict __ahost, unsigned short int __rport,
		 const char *__restrict __locuser,
		 const char *__restrict __remuser,
		 const char *__restrict __cmd, int *__restrict __fd2p);

/* 8 36636 */
extern int rcmd_af (char **__restrict __ahost, unsigned short int __rport,
		    const char *__restrict __locuser,
		    const char *__restrict __remuser,
		    const char *__restrict __cmd, int *__restrict __fd2p,
		    sa_family_t __af);

/* 8 36636 */
extern int rexec (char **__restrict __ahost, int __rport,
		  const char *__restrict __name,
		  const char *__restrict __pass,
		  const char *__restrict __cmd, int *__restrict __fd2p);

/* 8 36636 */
extern int rexec_af (char **__restrict __ahost, int __rport,
		     const char *__restrict __name,
		     const char *__restrict __pass,
		     const char *__restrict __cmd, int *__restrict __fd2p,
		     sa_family_t __af);

/* 8 36636 */
extern int ruserok (const char *__rhost, int __suser,
		    const char *__remuser, const char *__locuser);

/* 8 36636 */
extern int ruserok_af (const char *__rhost, int __suser,
		       const char *__remuser, const char *__locuser,
		       sa_family_t __af);

/* 8 36636 */
extern int iruserok (uint32_t __raddr, int __suser,
		     const char *__remuser, const char *__locuser);

/* 8 36636 */
extern int iruserok_af (const void *__raddr, int __suser,
			const char *__remuser, const char *__locuser,
			sa_family_t __af);

/* 8 36636 */
extern int rresvport (int *__alport);

/* 8 36636 */
extern int rresvport_af (int *__alport, sa_family_t __af);
#endif


/* 8 36636 */
#ifdef __USE_XOPEN2K
/* 8 36636 */
struct addrinfo
{
  int ai_flags;			/* 8 36636 */
  int ai_family;		/* 8 36636 */
  int ai_socktype;		/* 8 36636 */
  int ai_protocol;		/* 8 36636 */
  socklen_t ai_addrlen;		/* 8 36636 */
  struct sockaddr *ai_addr;	/* 8 36636 */
  char *ai_canonname;		/* 8 36636 */
  struct addrinfo *ai_next;	/* 8 36636 */
};

# ifdef __USE_GNU
/* 8 36636 */
struct gaicb
{
  const char *ar_name;		/* 8 36636 */
  const char *ar_service;	/* 8 36636 */
  const struct addrinfo *ar_request; /* 8 36636 */
  struct addrinfo *ar_result;	/* 8 36636 */
  /* 8 36636 */
  int __return;
  int __glibc_reserved[5];
};

/* 8 36636 */
#  define GAI_WAIT	0
#  define GAI_NOWAIT	1
# endif

/* 8 36636 */
# define AI_PASSIVE	0x0001	/* 8 36636 */
# define AI_CANONNAME	0x0002	/* 8 36636 */
# define AI_NUMERICHOST	0x0004	/* 8 36636 */
# define AI_V4MAPPED	0x0008	/* 8 36636 */
# define AI_ALL		0x0010	/* 8 36636 */
# define AI_ADDRCONFIG	0x0020	/* 8 36636 */
# ifdef __USE_GNU
#  define AI_IDN	0x0040	/* 8 36636 */
#  define AI_CANONIDN	0x0080	/* 8 36636 */
#  define AI_IDN_ALLOW_UNASSIGNED \
  __glibc_macro_warning ("AI_IDN_ALLOW_UNASSIGNED is deprecated") 0x0100
#  define AI_IDN_USE_STD3_ASCII_RULES \
  __glibc_macro_warning ("AI_IDN_USE_STD3_ASCII_RULES is deprecated") 0x0200
# endif
# define AI_NUMERICSERV	0x0400	/* 8 36636 */

/* 8 36636 */
# define EAI_BADFLAGS	  -1	/* 8 36636 */
# define EAI_NONAME	  -2	/* 8 36636 */
# define EAI_AGAIN	  -3	/* 8 36636 */
# define EAI_FAIL	  -4	/* 8 36636 */
# define EAI_FAMILY	  -6	/* 8 36636 */
# define EAI_SOCKTYPE	  -7	/* 8 36636 */
# define EAI_SERVICE	  -8	/* 8 36636 */
# define EAI_MEMORY	  -10	/* 8 36636 */
# define EAI_SYSTEM	  -11	/* 8 36636 */
# define EAI_OVERFLOW	  -12	/* 8 36636 */
# ifdef __USE_GNU
#  define EAI_NODATA	  -5	/* 8 36636 */
#  define EAI_ADDRFAMILY  -9	/* 8 36636 */
#  define EAI_INPROGRESS  -100	/* 8 36636 */
#  define EAI_CANCELED	  -101	/* 8 36636 */
#  define EAI_NOTCANCELED -102	/* 8 36636 */
#  define EAI_ALLDONE	  -103	/* 8 36636 */
#  define EAI_INTR	  -104	/* 8 36636 */
#  define EAI_IDN_ENCODE  -105	/* 8 36636 */
# endif

# ifdef __USE_MISC
#  define NI_MAXHOST      1025
#  define NI_MAXSERV      32
# endif

# define NI_NUMERICHOST	1	/* 8 36636 */
# define NI_NUMERICSERV 2	/* 8 36636 */
# define NI_NOFQDN	4	/* 8 36636 */
# define NI_NAMEREQD	8	/* 8 36636 */
# define NI_DGRAM	16	/* 8 36636 */
# ifdef __USE_GNU
#  define NI_IDN	32	/* 8 36636 */
#  define NI_IDN_ALLOW_UNASSIGNED \
  __glibc_macro_warning ("NI_IDN_ALLOW_UNASSIGNED is deprecated") 64
#  define NI_IDN_USE_STD3_ASCII_RULES \
  __glibc_macro_warning ("NI_IDN_USE_STD3_ASCII_RULES is deprecated") 128
# endif

/* 8 36636 */
extern int getaddrinfo (const char *__restrict __name,
			const char *__restrict __service,
			const struct addrinfo *__restrict __req,
			struct addrinfo **__restrict __pai);

/* 8 36636 */
extern void freeaddrinfo (struct addrinfo *__ai) __THROW;

/* 8 36636 */
extern const char *gai_strerror (int __ecode) __THROW;

/* 8 36636 */
extern int getnameinfo (const struct sockaddr *__restrict __sa,
			socklen_t __salen, char *__restrict __host,
			socklen_t __hostlen, char *__restrict __serv,
			socklen_t __servlen, int __flags);
#endif	/* 8 36636 */

#ifdef __USE_GNU
/* 8 36636 */
extern int getaddrinfo_a (int __mode, struct gaicb *__list[__restrict_arr],
			  int __ent, struct sigevent *__restrict __sig);

/* 8 36636 */
extern int gai_suspend (const struct gaicb *const __list[], int __ent,
			const struct timespec *__timeout);

# ifdef __USE_TIME64_REDIRECTS
#  if defined(__REDIRECT)
extern int __REDIRECT (gai_suspend, (const struct gaicb *const __list[],
                                     int __ent,
                                     const struct timespec *__timeout),
                       __gai_suspend_time64);
#  else
#   define gai_suspend __gai_suspend_time64
#  endif
# endif

/* 8 36636 */
extern int gai_error (struct gaicb *__req) __THROW;

/* 8 36636 */
extern int gai_cancel (struct gaicb *__gaicbp) __THROW;
#endif	/* 8 36636 */

__END_DECLS

#endif	/* 8 36636 */
