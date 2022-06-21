char fix_ip[22] = {0};

char * defangIPaddr(char * address){
    char *fix_ip = (char *)malloc(sizeof(char) * 22);
    int ip_1 = 0, ip_2 = 0, ip_3 = 0, ip_4 = 0;
    sscanf(address, "%d.%d.%d.%d", &ip_1, &ip_2, &ip_3, &ip_4);
    sprintf(fix_ip, "%d[.]%d[.]%d[.]%d", ip_1, ip_2, ip_3, ip_4);
    return fix_ip;
}
