	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r3, #0
	ldr r0, _081DD308 @ =0x00000859
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r3, r0
	bge _081DD328
	ldr r0, _081DD30C @ =0x03002C68
	ldr r5, [r0]
	adds r6, r1, #0
	ldr r7, _081DD310 @ =0x000006F4
	adds r2, r4, r7
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r5, r0
_081DD2FE:
	cmp r5, #0
	bne _081DD314
	movs r0, #0
	b _081DD318
	.align 2, 0
_081DD308: .4byte 0x00000859
_081DD30C: .4byte 0x03002C68
_081DD310: .4byte 0x000006F4
_081DD314:
	movs r7, #0
	ldrsh r0, [r1, r7]
_081DD318:
	strh r0, [r2]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r3, r0
	blt _081DD2FE
_081DD328:
	ldr r0, _081DD360 @ =0x000006FC
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r7, _081DD364 @ =0x000006FD
	adds r1, r4, r7
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081DD368 @ =0x000006FE
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	adds r7, #2
	adds r1, r4, r7
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd0b8
	adds r0, r4, #0
	bl FUN_081dd124
	adds r0, r4, #0
	bl FUN_081dd25c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD360: .4byte 0x000006FC
_081DD364: .4byte 0x000006FD
_081DD368: .4byte 0x000006FE
