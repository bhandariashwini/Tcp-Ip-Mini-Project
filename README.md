
**TCP BASED CHATING APPLICATION**

Objective:
Here the objective is to implement chating application to allow two
persons for chating over a network i.e.., CLIENT1 and CLIENT2 , with
help of SOCKET programming by using TCP protocols.


TASK:
Here client1 and client2 can not communicate directly, So we need server
to handle client1 and client2.

There are three versions can be posible i.e , simplex , half duplex and full
duplex.

Consider FULL DUPLEX , Client1 will send message to server and that
server will send received message to client2 and vice versa.

Approuch:
 Server should accept two clients connection with help of two
accept() calls i.e.., from client1 and client2

<img width="651" height="322" alt="image" src="https://github.com/user-attachments/assets/d4fbd4a1-33f2-4170-8b31-b06e2b4248ca" />

After connection estlabished , create child server. So , now we have
two server processes i.e parentServer and childServer. Both are
having connection with client1 and client2

<img width="544" height="251" alt="image" src="https://github.com/user-attachments/assets/1c147f9b-54a4-46c0-8151-c9fee3b1b996" />

now our task is to make full duplex, So , we need to create child
process to clients , after connect() call in clients.

<img width="679" height="450" alt="image" src="https://github.com/user-attachments/assets/29abb866-e93e-4a93-acd5-52dec405ee0f" />

Now to make full duplex, manage your if and else blocks in clients
and server as follows.

 client1_child always send MSG to server_child

 server_child always first recv MSG from client1_child and
send to client2_parent.

 client2_parent always recv MSG from server_child

 client2_child always send MSG to serever_parent.

 server_parent always first recv MSG from client2_child
and send to client1_parent.

 client1_parent always recv MSG from server_parent 


<img width="606" height="438" alt="image" src="https://github.com/user-attachments/assets/c895bbcd-12aa-43eb-b597-b9ae121847e6" />

