	push {r4, r5, lr}
	mov ip, r0
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, ip
	ldr r2, _080A7374 @ =0x0000033E
	add r2, ip
	mov r1, ip
	adds r1, #0x20
	movs r3, #7
_080A7338:
	ldrh r0, [r4]
	strb r0, [r1]
	ldrh r0, [r2]
	strb r0, [r1, #1]
	adds r1, #0x50
	subs r3, #1
	cmp r3, #0
	bge _080A7338
	movs r3, #3
	movs r1, #0
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, ip
	movs r2, #0x92
	lsls r2, r2, #1
	add r2, ip
_080A7358:
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r0, #0x40
	ble _080A7378
	ldrh r0, [r2, #0x2c]
	subs r0, r0, r1
	strh r0, [r2]
	subs r1, #0x10
	movs r5, #0
	ldrsh r0, [r4, r5]
	asrs r0, r0, #2
	adds r1, r1, r0
	b _080A737C
	.align 2, 0
_080A7374: .4byte 0x0000033E
_080A7378:
	ldrh r0, [r2, #0x2c]
	strh r0, [r2]
_080A737C:
	subs r2, #0x50
	subs r3, #1
	cmp r3, #0
	bge _080A7358
	movs r1, #0
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, ip
	movs r2, #0xba
	lsls r2, r2, #1
	add r2, ip
	movs r3, #3
_080A7394:
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r0, #0x40
	ble _080A73AE
	ldrh r0, [r2, #0x2c]
	adds r0, r0, r1
	strh r0, [r2]
	subs r1, #0x10
	movs r5, #0
	ldrsh r0, [r4, r5]
	asrs r0, r0, #2
	adds r1, r1, r0
	b _080A73B2
_080A73AE:
	ldrh r0, [r2, #0x2c]
	strh r0, [r2]
_080A73B2:
	adds r2, #0x50
	subs r3, #1
	cmp r3, #0
	bge _080A7394
	pop {r4, r5}
	pop {r0}
	bx r0
