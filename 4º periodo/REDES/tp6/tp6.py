import socket
print('creating socket...')
#create a socket object

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('socket created')
print("connection with remote host")

client.connect(('google.com', 80))

print ('conection ok')

client.send(b'GEI /index.html HTML/1.1\r\n\r\n')

while 1:
    data = client.recv(128).decode('utf-8')
    print(data)
    if data == "":
        break
print('closing socket...')
client.close()
print('socket closed')