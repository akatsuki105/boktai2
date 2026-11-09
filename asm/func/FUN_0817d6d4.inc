	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _0817D714 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _0817D718 @ =0x00004EA0
	adds r6, r0, r2
	movs r2, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r5, r1, r0
_0817D6EE:
	lsls r0, r2, #5
	adds r4, r2, #1
	adds r3, r6, #0
	adds r2, r0, r5
	movs r1, #0xf
_0817D6F8:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _0817D6F8
	adds r2, r4, #0
	cmp r2, #2
	ble _0817D6EE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817D714: .4byte 0x03003584
_0817D718: .4byte 0x00004EA0
