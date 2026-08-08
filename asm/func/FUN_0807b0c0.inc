	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B0E0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r2, r1, #0
	cmp r1, #0
	bne _0807B0E8
	ldr r0, _0807B0E4 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x36
	ldrsh r0, [r0, r1]
	b _0807B110
	.align 2, 0
_0807B0E0: .4byte 0x03002BE0
_0807B0E4: .4byte 0x030046A0
_0807B0E8:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0807B104
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	b _0807B110
_0807B104:
	ldr r3, _0807B114 @ =0x000003BD
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
_0807B110:
	pop {r1}
	bx r1
	.align 2, 0
_0807B114: .4byte 0x000003BD
