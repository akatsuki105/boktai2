	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BE6A
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BE6A:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	ldr r2, _0807BEAC @ =0x000003F6
	adds r0, r4, r2
	strh r5, [r0]
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0
	bl FUN_08060b84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807BEB4
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BEB0 @ =FUN_080765a0
	b _0807BED0
	.align 2, 0
_0807BEAC: .4byte 0x000003F6
_0807BEB0: .4byte FUN_080765a0
_0807BEB4:
	cmp r0, #4
	bne _0807BEC8
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0807BED8 @ =0x00000381
	adds r0, r4, r2
	strb r1, [r0]
_0807BEC8:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BEDC @ =FUN_080738b4
_0807BED0:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BED8: .4byte 0x00000381
_0807BEDC: .4byte FUN_080738b4
