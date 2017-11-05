import socket

print 'Welcome to IP address to DNS:'
IP=raw_input('Enter IP Address : ')
addr6=socket.gethostbyaddr(IP)
print addr6


/*OUTPUT:-
[root@localhost ccoew]# python ipdns63.py
Welcome to IP address to DNS:
Enter IP Address31.13.78.35
('edge-star-mini-shv-01-sit4.facebook.com', [], ['31.13.78.35'])
[root@localhost ccoew]# python ipdns63.py
Welcome to IP address to DNS:
Enter IP Address206.190.36.45
('ir1.fp.vip.gq1.yahoo.com', [], ['206.190.36.45'])
[root@localhost ccoew]# python ipdns63.py
Welcome to IP address to DNS:
Enter IP Addressgmail.co.in
('maa03s23-in-f5.1e100.net', [], ['172.217.26.197'])
*/
