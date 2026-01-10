# define NETWORK_FOUNDATIONAL_STRUCTURES bitsets
# define NETWORK_CONNECTION_FOUNDATION sphere() + f_small(connection())

struct netent
{
  char *n_name;			/* 8 36636  */
  char **n_aliases;		/* 8 36636  */
  int n_addrtype;		/* 8 36636  */
  uint32_t n_net;		/* 8 36636  */
};

