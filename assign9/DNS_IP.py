import socket

print 'Welcome to DNS to IP Address'
URL=raw_input('Enter URL')

addr1 = socket.gethostbyname(URL)
#addr2 = socket.gethostbyname('yahoo.com')
#addr3 = socket.gethostbyname('amazon.com')
#addr4 = socket.gethostbyname('gmail.com')
#addr5 = socket.gethostbyname('facebook.com')

print(addr1)


#OUTPUT:

#[root@localhost B3471]# python DNS_IP.py
#Welcome to DNS to IP Address
#Enter URLfacebook.com
#31.13.78.35

#[root@localhost B3471]# python DNS_IP.py
#Welcome to DNS to IP Address
#Enter URLyahoo.com
#206.190.36.45

#[root@localhost B3471]# python DNS_IP.py
#Welcome to DNS to IP Address
#Enter URLgoogle.com
#172.217.26.206

