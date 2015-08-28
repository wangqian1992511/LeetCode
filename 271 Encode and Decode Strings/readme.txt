001.cpp (92ms):

Use the idea of byte stuffing in P2P protocol. The flag 0x7E indicates the bound of the frame. The flag 0x7D is the escape octet, followed by pecial characters XORed with 0x20.