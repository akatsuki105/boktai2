	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _08177578 @ =0x00001012
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _08177596
	movs r5, #1
	adds r6, r2, #0
	ldr r7, _0817757C @ =0x00000755
	adds r2, r1, r7
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r4, #0x92
	lsls r4, r4, #1
_0817756C:
	ldrb r0, [r2]
	ands r0, r5
	cmp r0, #0
	beq _08177580
	movs r0, #1
	b _08177582
	.align 2, 0
_08177578: .4byte 0x00001012
_0817757C: .4byte 0x00000755
_08177580:
	movs r0, #0
_08177582:
	cmp r0, #0
	beq _08177588
	str r5, [r1]
_08177588:
	adds r2, r2, r4
	adds r1, r1, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _0817756C
_08177596:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
