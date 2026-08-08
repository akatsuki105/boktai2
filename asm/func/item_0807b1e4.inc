	push {r4, r5, r6, lr}
	sub sp, #8
	bl FUN_0807afe8
	ldr r1, _0807B228 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	cmp r6, #0
	beq _0807B2CA
	movs r0, #0x45
	bl prepare_08231510
	cmp r0, #0
	beq _0807B2CA
	bl fetch_082316e4
	adds r4, r0, #0
	ldr r1, _0807B22C @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r5, r0, r1
	ldrh r0, [r5, #2]
	cmp r0, #5
	bne _0807B264
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0807B230
	bl fetch_082316e4
	adds r2, r0, #0
	b _0807B238
	.align 2, 0
_0807B228: .4byte 0x03002BE0
_0807B22C: .4byte 0x08DAA8D8
_0807B230:
	ldrh r1, [r5, #8]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r2, r0, #2
_0807B238:
	ldr r1, _0807B254 @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r0, r0, r1
	ldrh r1, [r0, #6]
	ldr r3, _0807B258 @ =0x00000442
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _0807B25C @ =0x00000446
	adds r0, r6, r1
	strh r2, [r0]
	ldr r2, _0807B260 @ =0x00000444
	adds r0, r6, r2
	strh r4, [r0]
	b _0807B2B8
	.align 2, 0
_0807B254: .4byte 0x08DAA8D8
_0807B258: .4byte 0x00000442
_0807B25C: .4byte 0x00000446
_0807B260: .4byte 0x00000444
_0807B264:
	cmp r0, #1
	bne _0807B2CA
	ldr r1, _0807B290 @ =0x00000366
	adds r4, r6, r1
	ldrh r1, [r4]
	ldrh r0, [r5, #6]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	adds r5, r0, #0
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r3, [r1]
	adds r2, r3, r5
	ldrh r0, [r4]
	cmp r2, r0
	ble _0807B294
	subs r5, r0, r3
	strh r0, [r1]
	b _0807B296
	.align 2, 0
_0807B290: .4byte 0x00000366
_0807B294:
	strh r2, [r1]
_0807B296:
	cmp r5, #0
	ble _0807B2B8
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r6, r3
	adds r3, r6, #0
	adds r3, #0x2c
	movs r2, #0x97
	lsls r2, r2, #4
	adds r1, r6, r2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0805fe7c
_0807B2B8:
	ldr r3, _0807B2D4 @ =0x0000095E
	adds r1, r6, r3
	ldr r0, _0807B2D8 @ =0x00000121
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #0x30
	strh r0, [r1]
_0807B2CA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807B2D4: .4byte 0x0000095E
_0807B2D8: .4byte 0x00000121
