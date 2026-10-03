	push {r4, r5, lr}
	adds r5, r0, #0
	bl SuspendSunlight
	ldr r0, _0804E18C @ =0x030000E0
	adds r1, r5, #0
	adds r1, #0x33
	ldrb r1, [r1]
	str r1, [r0]
	adds r0, r5, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804E1B0
	cmp r0, #1
	bgt _0804E190
	cmp r0, #0
	beq _0804E196
	b _0804E1E2
	.align 2, 0
_0804E18C: .4byte 0x030000E0
_0804E190:
	cmp r0, #2
	beq _0804E1CA
	b _0804E1E2
_0804E196:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E1A8
	adds r0, r5, #0
	bl FUN_0804de70
	b _0804E1E2
_0804E1A8:
	adds r0, r5, #0
	bl FUN_0804dee8
	b _0804E1E2
_0804E1B0:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E1C2
	adds r0, r5, #0
	bl FUN_0804df18
	b _0804E1E2
_0804E1C2:
	adds r0, r5, #0
	bl FUN_0804e028
	b _0804E1E2
_0804E1CA:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E1DC
	adds r0, r5, #0
	bl FUN_0804e0bc
	b _0804E1E2
_0804E1DC:
	adds r0, r5, #0
	bl FUN_0804e128
_0804E1E2:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804E204
	movs r4, #0
	strb r4, [r1]
	movs r0, #1
	bl rfu_LMAN_stopManager
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x38]
	str r4, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804E204:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _0804E230
	ldr r0, _0804E228 @ =0x0300481C
	movs r1, #0
	str r1, [r0]
	ldr r0, _0804E22C @ =0x03002B58
	str r1, [r0]
	adds r0, r5, #0
	bl RemoveEntity
	adds r0, r5, #0
	bl Free
	bl FUN_0824172c
	b _0804E24E
	.align 2, 0
_0804E228: .4byte 0x0300481C
_0804E22C: .4byte 0x03002B58
_0804E230:
	ldrh r0, [r5, #0x38]
	subs r0, #9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x11
	bhi _0804E242
	ldr r1, _0804E258 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_0804E242:
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x48]
	adds r0, #1
	str r0, [r5, #0x48]
_0804E24E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804E258: .4byte 0x030047B8
