	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq _08017BBA
	ldr r2, _08017BCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08017BD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08017BD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r4, #0x2e]
	bl Mod
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x20]
_08017BBA:
	ldrh r0, [r4, #0x20]
	cmp r0, #9
	bhi _08017BC4
	movs r0, #0xa
	strh r0, [r4, #0x20]
_08017BC4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08017BCC: .4byte 0x030046B8
_08017BD0: .4byte 0x000003FF
_08017BD4: .4byte 0x0203B400
