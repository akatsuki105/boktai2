	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, _080BFB24 @ =0x03002BE0
	ldr r1, [r6]
	movs r4, #1
	str r4, [r1, #0x1c]
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, [r6]
	ldr r1, _080BFB28 @ =0x0000037D
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, [r6]
	movs r7, #0
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r6]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
	ldr r0, [r6]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #7
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, _080BFB2C @ =0x000002E6
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	adds r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	bl FUN_080bfa74
	ldr r0, [r6]
	ldr r1, _080BFB30 @ =0x0000042C
	adds r0, r0, r1
	strh r4, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r5, r5, r0
	ldrh r0, [r5]
	cmp r0, #1
	beq _080BFB48
	cmp r0, #1
	bgt _080BFB34
	cmp r0, #0
	beq _080BFB3E
	b _080BFB6E
	.align 2, 0
_080BFB24: .4byte 0x03002BE0
_080BFB28: .4byte 0x0000037D
_080BFB2C: .4byte 0x000002E6
_080BFB30: .4byte 0x0000042C
_080BFB34:
	cmp r0, #2
	beq _080BFB58
	cmp r0, #3
	beq _080BFB62
	b _080BFB6E
_080BFB3E:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x20
	b _080BFB6A
_080BFB48:
	ldr r0, [r6]
	ldr r1, _080BFB54 @ =0x0000042C
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x40
	b _080BFB6A
	.align 2, 0
_080BFB54: .4byte 0x0000042C
_080BFB58:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x10
	b _080BFB6A
_080BFB62:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x80
_080BFB6A:
	orrs r1, r2
	strh r1, [r0]
_080BFB6E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
