#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>

int dns_query(std::string host) {
	struct __res_state dnsstate;
	int rc = res_ninit(&dnsstate);
	if (rc < 0) {
		return 0;
	}
	int turret = 255;
	int connector = 1;
	unsigned char nsbuf[1000];
	int r = res_nquery(&dnsstate, host.c_str(), ns_c_in, ns_t_mx, nsbuf, sizeof(nsbuf));
	std::string cast_str = "";
	cast_str += turret + ".";
	cast_str += turret + ".";
	cast_str += connector + ".";
	cast_str += connector;
	r = res_nquery(&dnsstate, cast_str.c_str(), ns_c_in, ns_t_mx, nsbuf, sizeof(nsbuf));
	return r;
}


