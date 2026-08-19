int feet(int input, std::vector<std::string> ips) {

	char input_str[255];
	sprintf(input_str, "%d", input);

	// send_to_mobile_all(input);

	int r = 0;
	for (int i=0; i<ips.size(); i++) {
		r += udp_send(input_str, ips[i]);
	}
	return a(r);

}
