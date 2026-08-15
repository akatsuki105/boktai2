	push {r4, r5, r6, lr}
	adds r1, r0, #0
	ldr r0, _0823BB18 @ =gCamera
	ldr r3, [r0]
	adds r6, r0, #0
	cmp r3, #0
	beq _0823BB74
	ldrh r0, [r1]
	adds r2, r3, #0
	adds r2, #0x6c
	strh r0, [r2]
	ldrh r0, [r1, #2]
	movs r4, #0x6e
	adds r4, r4, r3
	strh r0, [r4]
	ldrh r0, [r1, #4]
	adds r3, #0x70
	strh r0, [r3]
	ldr r1, _0823BB1C @ =0x03003540
	ldrh r2, [r2]
	strh r2, [r1]
	ldrh r0, [r4]
	strh r0, [r1, #2]
	ldrh r0, [r3]
	strh r0, [r1, #4]
	ldr r4, _0823BB20 @ =0x030047C8
	adds r5, r1, #0
	lsls r2, r2, #0x10
	asrs r3, r2, #0x11
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823BB24
	asrs r0, r0, #8
	b _0823BB2A
	.align 2, 0
_0823BB18: .4byte gCamera
_0823BB1C: .4byte 0x03003540
_0823BB20: .4byte 0x030047C8
_0823BB24:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823BB2A:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823BB3C
	asrs r0, r0, #8
	b _0823BB42
_0823BB3C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823BB42:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823BB56
	asrs r1, r0, #8
	b _0823BB5C
_0823BB56:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0823BB5C:
	subs r0, r2, r1
	movs r3, #0
	strh r0, [r4, #2]
	adds r0, r2, r1
	strh r0, [r4, #4]
	ldr r1, [r6]
	movs r2, #1
	strh r2, [r1, #0x1c]
	adds r0, r1, #0
	adds r0, #0x68
	strh r2, [r0]
	strh r3, [r1, #0x1e]
_0823BB74:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
