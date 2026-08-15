	push {r4, r5, r6, lr}
	ldr r0, _0823BA44 @ =gCamera
	ldr r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0823BAA2
	ldr r3, _0823BA48 @ =0x03003540
	adds r0, r1, #0
	adds r0, #0x80
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	strh r2, [r3]
	adds r0, r1, #0
	adds r0, #0x82
	ldrh r1, [r3, #4]
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r3, #4]
	ldr r4, _0823BA4C @ =0x030047C8
	adds r5, r3, #0
	lsls r2, r2, #0x10
	asrs r3, r2, #0x11
	lsls r1, r1, #0x10
	asrs r2, r1, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823BA50
	asrs r0, r0, #8
	b _0823BA56
	.align 2, 0
_0823BA44: .4byte gCamera
_0823BA48: .4byte 0x03003540
_0823BA4C: .4byte 0x030047C8
_0823BA50:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823BA56:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823BA68
	asrs r0, r0, #8
	b _0823BA6E
_0823BA68:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823BA6E:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823BA82
	asrs r2, r0, #8
	b _0823BA88
_0823BA82:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r2, r0, #0
_0823BA88:
	subs r0, r3, r2
	movs r1, #0
	strh r0, [r4, #2]
	adds r0, r3, r2
	strh r0, [r4, #4]
	ldr r2, [r6]
	adds r0, r2, #0
	adds r0, #0x7e
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_0823BAA2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
