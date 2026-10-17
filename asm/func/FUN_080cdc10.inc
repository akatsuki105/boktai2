	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080cdbb0
	ldr r0, _080CDC60 @ =0x0000094C
	adds r1, r4, r0
	ldr r0, _080CDC64 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0x95
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080CDC68 @ =0x00000938
	adds r5, r4, r1
	ldrh r0, [r5]
	adds r1, r4, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r3, r4, r1
	str r3, [r0]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, [r2]
	ldrh r0, [r5]
	strh r0, [r1, #6]
	ldr r0, [r2]
	str r3, [r0, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080cd958
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CDC60: .4byte 0x0000094C
_080CDC64: .4byte 0x0000FFFF
_080CDC68: .4byte 0x00000938
