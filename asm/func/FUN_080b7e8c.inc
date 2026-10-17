	push {r4, r5, r6, lr}
	ldr r2, _080B7ED4 @ =0x0000142B
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _080B7ED8 @ =0x00001458
	adds r2, r0, r3
	adds r1, r2, r1
	ldrb r6, [r1]
	ldr r1, _080B7EDC @ =0x0000142E
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	ldrb r5, [r2]
	ldr r0, _080B7EE0 @ =0x030046A0
	ldr r3, [r0]
	lsls r2, r6, #1
	adds r2, r2, r3
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r2, r2, r1
	movs r0, #0
	ldrsh r4, [r2, r0]
	lsls r0, r5, #1
	adds r0, r0, r3
	adds r0, r0, r1
	ldrh r1, [r0]
	strh r1, [r2]
	strh r4, [r0]
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, r6
	bne _080B7EE4
	strh r5, [r3]
	b _080B7EEA
	.align 2, 0
_080B7ED4: .4byte 0x0000142B
_080B7ED8: .4byte 0x00001458
_080B7EDC: .4byte 0x0000142E
_080B7EE0: .4byte 0x030046A0
_080B7EE4:
	cmp r0, r5
	bne _080B7EEA
	strh r6, [r3]
_080B7EEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
