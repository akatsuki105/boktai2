	push {r4, r5, r6, lr}
	sub sp, #0x20
	mov r6, sp
	lsls r4, r1, #1
	ldr r3, _081DD0B0 @ =0x000006F4
	adds r5, r0, r3
	adds r4, r5, r4
	ldrh r3, [r4]
	strh r3, [r6, #0x10]
	mov r3, sp
	ldr r6, _081DD0B4 @ =0x000006FC
	adds r0, r0, r6
	adds r1, r0, r1
	ldrb r6, [r1]
	strb r6, [r3, #0x18]
	lsls r3, r2, #1
	adds r5, r5, r3
	ldrh r3, [r5]
	strh r3, [r4]
	adds r0, r0, r2
	ldrb r2, [r0]
	strb r2, [r1]
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r5]
	strb r6, [r0]
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DD0B0: .4byte 0x000006F4
_081DD0B4: .4byte 0x000006FC
