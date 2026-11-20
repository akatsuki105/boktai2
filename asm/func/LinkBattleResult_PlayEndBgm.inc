	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _081DD37C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DD388
	b _081DD3BA
	.align 2, 0
_081DD37C: .4byte 0x03002C68
_081DD380:
	movs r0, #0xa9
	bl sound_08240264
	b _081DD3BA
_081DD388:
	movs r2, #0x18
	ldrsh r3, [r0, r2]
	cmp r3, #0
	blt _081DD3BA
	movs r2, #0
	ldr r4, _081DD3C0 @ =0x00000859
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r2, r0
	bge _081DD3BA
	adds r4, r0, #0
	ldr r0, _081DD3C4 @ =0x000006FC
	adds r1, r1, r0
_081DD3A6:
	ldrb r0, [r1]
	cmp r0, r3
	bne _081DD3B2
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081DD380
_081DD3B2:
	adds r1, #1
	adds r2, #1
	cmp r2, r4
	blt _081DD3A6
_081DD3BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DD3C0: .4byte 0x00000859
_081DD3C4: .4byte 0x000006FC
