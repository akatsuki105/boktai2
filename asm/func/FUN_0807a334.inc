	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _0807A354
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_0807A354:
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0
	bl FUN_08060b84
	ldr r0, _0807A394 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r6, r4, #0
	adds r6, #0x2c
	ldrh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0807A38E
	cmp r1, #0
	blt _0807A38E
	ldr r0, _0807A398 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0807A38E
	ldr r0, _0807A39C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807A3A0
_0807A38E:
	movs r5, #0
	b _0807A3AE
	.align 2, 0
_0807A394: .4byte 0x000003F6
_0807A398: .4byte 0x030046A8
_0807A39C: .4byte 0x030046AC
_0807A3A0:
	ldr r0, _0807A3C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0807A3AE:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807A3C4
	adds r0, #4
	b _0807A3D0
	.align 2, 0
_0807A3C0: .4byte 0x030046A4
_0807A3C4:
	ldr r0, _0807A3E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0807A3D0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0807A3E8
	cmp r2, #2
	beq _0807A3EC
	b _0807A3F0
	.align 2, 0
_0807A3E4: .4byte 0x030046A4
_0807A3E8:
	ldrb r0, [r6, #4]
	b _0807A3EE
_0807A3EC:
	ldrb r0, [r6]
_0807A3EE:
	subs r1, r1, r0
_0807A3F0:
	ldrh r0, [r4, #0x2e]
	subs r0, r0, r1
	movs r2, #0xfe
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #4
	bls _0807A424
	movs r0, #8
	subs r0, r0, r1
	ldr r2, _0807A41C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0807A420 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807A430
	.align 2, 0
_0807A41C: .4byte 0x000002E6
_0807A420: .4byte 0x000002E7
_0807A424:
	ldr r2, _0807A444 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0807A448 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807A430:
	strb r0, [r1]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A444: .4byte 0x000002E6
_0807A448: .4byte 0x000002E7
