# PhySec
The code does the following.
1. Read CSV file (Wireshark output), and store it in an array called "Row"
2. Split the cells  using the comma "," as a delimiter, and store them in a string array called "csv"
3. Count the number of Packets (not cells)
4. Filter TCP packets and count them and store them in another string array (Filter1)
5. Filter packets coming from a certain IP address  192.168.1.13 and store them in a string array (filter 2)
6. Filter packets based on the packet sequence number, so we can exclude duplicate packets and save them into two arrays seq1 and seq0 array so I only targeted a three-way handshake.
7. Extract and save destination address for seq=1 packets  seq=0  in arrays called "dest_add0"&"dest_add1"
8. Extract packet timestamp from the cells and convert them to long double array "time_array" & "time0_array"
9. Extract source port number and save it in S_port and S_port0
10. Extract the TSVAL of each packet, convert it to long double array TSVAL_SEQ1 & TSVAL_SEQ0
 11. Find the differences in Time and TSVAL for the two correlated packets, to know that packets are correlated they both must be sent from same Ip address to the same destination address on the same port number, one has a seq=0 and the other has seq=1 
12. Scale and calculate the clock skew by subtracting Time-difference from TSval-difference and display it on screen.
