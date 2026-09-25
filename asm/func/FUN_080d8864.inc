	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x5c
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _080D889A
	movs r2, #1
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _080D8888
	movs r0, #1
	b _080D888A
_080D8888:
	movs r0, #0
_080D888A:
	cmp r0, #0
	beq _080D88DA
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2]
	ands r0, r1
	strb r0, [r2]
	b _080D88DA
_080D889A:
	movs r1, #1
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D88AC
	movs r0, #1
	b _080D88AE
_080D88AC:
	movs r0, #0
_080D88AE:
	cmp r0, #0
	beq _080D88D4
	ldr r2, _080D88E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D88E4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D88E8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	ldrh r1, [r5, #0x1c]
	subs r1, #0xa
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
_080D88D4:
	ldrh r0, [r4, #0x3c]
	subs r0, #1
	strh r0, [r4, #0x3c]
_080D88DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D88E0: .4byte 0x030046B8
_080D88E4: .4byte 0x000003FF
_080D88E8: .4byte 0x0203B400
