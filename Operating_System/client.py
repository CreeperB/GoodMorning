# client.py
import socket

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 8888  # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        print("Connected to server\nType 'exit' to exit")
        while True:
            print("Client: ", end="")
            scan = input()
            s.sendall(scan.encode())
            data = s.recv(1024).decode()
            if scan == "exit":
                exit()
            print(data)