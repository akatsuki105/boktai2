	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081087A0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081087A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081087A6
	.align 2, 0
_081087A0: .4byte 0x0000046D
_081087A4:
	movs r0, #0
_081087A6:
	cmp r0, #0
	beq _081087D6
	ldrb r0, [r4, #5]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r4, #5]
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r1, r2
	ldr r0, _08108818 @ =0xFFFFF8FF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_081087D6:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08108810
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	ldr r0, _0810881C @ =0x00000716
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08108820 @ =0x000006FC
	adds r2, r2, r1
	subs r0, #0xe
	ldrh r1, [r2, #0x26]
	ands r0, r1
	strh r0, [r2, #0x26]
	adds r0, r4, #0
	bl Skeleton_LichPSelectAction
	ldr r2, _08108824 @ =0x00000482
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
_08108810:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08108818: .4byte 0xFFFFF8FF
_0810881C: .4byte 0x00000716
_08108820: .4byte 0x000006FC
_08108824: .4byte 0x00000482
