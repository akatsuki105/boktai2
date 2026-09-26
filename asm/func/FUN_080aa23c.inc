	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080AA260 @ =0x0000034A
	adds r4, r5, r0
	ldrh r1, [r4]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #1
	bl FUN_0823b9cc
	ldrh r0, [r4]
	cmp r0, #5
	bhi _080AA264
	adds r0, r5, #0
	adds r0, #0x94
	bl Hitbox_Register
	b _080AA274
	.align 2, 0
_080AA260: .4byte 0x0000034A
_080AA264:
	cmp r0, #6
	bne _080AA274
	ldr r0, _080AA294 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_080AA274:
	ldr r0, _080AA298 @ =0x0000034A
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AA28C
	adds r0, r5, #0
	bl KillEntity
_080AA28C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AA294: .4byte 0x030047A4
_080AA298: .4byte 0x0000034A
