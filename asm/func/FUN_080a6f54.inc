	push {lr}
	adds r3, r0, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #5
	bhi _080A6F90
	ldr r2, _080A6F84 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A6F88 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A6F8C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0xf
	ands r0, r1
	subs r0, #7
	adds r1, r3, #0
	adds r1, #0x58
	strh r0, [r1]
	b _080A6F9C
	.align 2, 0
_080A6F84: .4byte 0x030046B8
_080A6F88: .4byte 0x000003FF
_080A6F8C: .4byte 0x0203B400
_080A6F90:
	adds r0, r3, #0
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A6F9C:
	pop {r0}
	bx r0
