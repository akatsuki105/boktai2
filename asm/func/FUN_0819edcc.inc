	push {r4, r5, r6, r7, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	ldr r0, [r0, #0x44]
	movs r5, #0
	ldr r4, [r0, #0x38]
	ldr r0, _0819EE14 @ =0x000008DC
	adds r2, r1, r0
	subs r0, #0x20
	adds r3, r1, r0
	movs r7, #0
	ldr r6, _0819EE18 @ =0x00007FFF
	adds r0, #0x60
	adds r1, r1, r0
_0819EDEC:
	strh r7, [r3]
	movs r0, #0x1f
	strh r0, [r2]
	movs r0, #0xf8
	lsls r0, r0, #7
	strh r0, [r2, #0x20]
	strh r6, [r1]
	ldrh r0, [r4]
	strh r0, [r1, #0x20]
	adds r4, #2
	adds r2, #2
	adds r3, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _0819EDEC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819EE14: .4byte 0x000008DC
_0819EE18: .4byte 0x00007FFF
