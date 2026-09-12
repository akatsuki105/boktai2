	push {lr}
	mov ip, r0
	cmp r1, #2
	beq _0820FAA2
	cmp r1, #2
	bgt _0820FA92
	cmp r1, #1
	beq _0820FA98
	b _0820FAB6
_0820FA92:
	cmp r1, #3
	beq _0820FAAC
	b _0820FAB6
_0820FA98:
	movs r1, #0xc3
	lsls r1, r1, #2
	add r1, ip
	movs r0, #5
	b _0820FAB4
_0820FAA2:
	movs r1, #0xc3
	lsls r1, r1, #2
	add r1, ip
	movs r0, #6
	b _0820FAB4
_0820FAAC:
	movs r1, #0xc3
	lsls r1, r1, #2
	add r1, ip
	movs r0, #7
_0820FAB4:
	strh r0, [r1, #0x10]
_0820FAB6:
	mov r3, ip
	adds r3, #0xb4
	ldr r1, [r3]
	movs r2, #0xdc
	lsls r2, r2, #2
	add r2, ip
	ldr r0, [r2]
	ldrb r0, [r0, #0x18]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0xca
	lsls r1, r1, #2
	add r1, ip
	strh r0, [r1]
	ldr r1, _0820FB14 @ =0x00000356
	add r1, ip
	ldr r0, [r2]
	ldrb r0, [r0, #0x19]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r1, _0820FB18 @ =0x0000032A
	add r1, ip
	strh r0, [r1]
	ldr r0, [r3]
	ldrh r1, [r0, #4]
	movs r0, #0xcb
	lsls r0, r0, #2
	add r0, ip
	strh r1, [r0]
	ldr r0, [r2]
	ldrb r1, [r0, #0x1a]
	movs r0, #0xc5
	lsls r0, r0, #2
	add r0, ip
	strb r1, [r0]
	ldr r0, [r2]
	ldrb r1, [r0, #0x1b]
	ldr r0, _0820FB1C @ =0x00000315
	add r0, ip
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0820FB14: .4byte 0x00000356
_0820FB18: .4byte 0x0000032A
_0820FB1C: .4byte 0x00000315
