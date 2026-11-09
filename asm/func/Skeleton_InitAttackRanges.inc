	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _081056B0 @ =0x000001DF
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #6
	beq _081056E8
	cmp r0, #6
	bgt _081056B4
	cmp r0, #5
	beq _081056BE
	b _081057A4
	.align 2, 0
_081056B0: .4byte 0x000001DF
_081056B4:
	cmp r0, #7
	beq _08105728
	cmp r0, #8
	beq _08105768
	b _081057A4
_081056BE:
	ldr r1, _081056DC @ =0x00000734
	adds r0, r5, r1
	ldr r1, _081056E0 @ =0x00013880
	str r1, [r0]
	ldr r2, _081056E4 @ =0x0000075C
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0xec
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	b _081057A2
	.align 2, 0
_081056DC: .4byte 0x00000734
_081056E0: .4byte 0x00013880
_081056E4: .4byte 0x0000075C
_081056E8:
	ldr r0, _0810571C @ =0x00000734
	adds r1, r5, r0
	movs r0, #0xc8
	lsls r0, r0, #9
	str r0, [r1]
	movs r1, #0xe7
	lsls r1, r1, #3
	adds r2, r5, r1
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r3, _08105720 @ =0x0000073C
	adds r0, r5, r3
	ldr r1, _08105724 @ =0x00014E1F
	str r1, [r0]
	adds r3, #0x20
	adds r0, r5, r3
	str r1, [r0]
	movs r0, #0xec
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r2]
	b _081057A2
	.align 2, 0
_0810571C: .4byte 0x00000734
_08105720: .4byte 0x0000073C
_08105724: .4byte 0x00014E1F
_08105728:
	ldr r2, _08105760 @ =0x00000734
	adds r1, r5, r2
	movs r0, #0xc8
	lsls r0, r0, #9
	str r0, [r1]
	movs r0, #0xe7
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r0, [r1]
	str r0, [r4]
	ldr r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	ldr r3, _08105764 @ =0x0000075C
	adds r0, r5, r3
	str r1, [r0]
	movs r0, #0xec
	lsls r0, r0, #3
	adds r1, r5, r0
	b _081057A0
	.align 2, 0
_08105760: .4byte 0x00000734
_08105764: .4byte 0x0000075C
_08105768:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r4, r3, r1
	ldr r0, [r4]
	lsls r0, r0, #2
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	ldr r2, _081057AC @ =0x00000734
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xe7
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r0, [r4]
	str r0, [r1]
	ldr r0, _081057B0 @ =0x0000073C
	adds r1, r5, r0
	ldr r0, [r4]
	str r0, [r1]
	adds r2, #0x28
	adds r1, r5, r2
	movs r0, #0xc8
	lsls r0, r0, #9
	str r0, [r1]
	adds r3, #0x28
	adds r1, r5, r3
_081057A0:
	ldr r0, [r4]
_081057A2:
	str r0, [r1]
_081057A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081057AC: .4byte 0x00000734
_081057B0: .4byte 0x0000073C
