# Make systemd to take care of personal service   
   
1. Find absolute path for executing server program   
    
For example...   
If `$node myServer.js` is a command to run your server   
    
`$which node` to find `node`'s location,   
for me it was `/usr/local/bin.node`   
    
`/home/`*`USERNAME`*`/workspace/myServer.js` is a source code's absolute path   
   
---
   
2. Write `.service` file      
    
`sudo `*`FavEditor`*` /lib/systemd/system/`*`nameOfService`*`.service`   
to start writing your service.   

      
```
[Unit]
Description=Description of server
Documentation=URL of server, ex) http://myServer.com
After=network.target

[Service]
Type=simple
User=Username
ExecStart=/usr/local/bin/node /home/USERNAME/workspace/myServer.js
Restart=on-failure

[Install]
WantedBy=multi-user.target
```   
   
Replace `User` in [Service] for your user name and `ExecStart` for your service's executive file and source code's absolute path   
   
---
   
3. Start service!   
    
`$systemctl start `*`nameOfService`*: start service   
`$systemctl restart `*`nameOfService`*: restart service   
`$systemctl stop `*`nameOfService`*: stop service   
`$systemctl enable `*`nameOfService`*: activates auto-start of server when pc reboot   
`$systemctl disable `*`nameOfService`*: deactivate auto-start after reboot   
