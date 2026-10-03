	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _080AEB08 @ =0x00001348
	adds r3, r5, r0
	ldr r2, _080AEB0C @ =0x0000134A
	adds r1, r5, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bhs _080AEB14
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080AEB90
	ldr r3, _080AEB10 @ =0x0000134C
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	b _080AEB90
	.align 2, 0
_080AEB08: .4byte 0x00001348
_080AEB0C: .4byte 0x0000134A
_080AEB10: .4byte 0x0000134C
_080AEB14:
	ldr r0, _080AEB78 @ =0x0000134C
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	strh r2, [r1]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bhi _080AEB8C
	movs r0, #0x1f
	ands r2, r0
	cmp r2, #0
	bne _080AEB90
	ldr r0, _080AEB7C @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _080AEB80 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r2, _080AEB84 @ =0x0203B400
	adds r1, r1, r2
	ldrb r4, [r1]
	movs r6, #7
_080AEB44:
	movs r3, #0x9b
	lsls r3, r3, #5
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r2, _080AEB88 @ =0x0000134E
	adds r1, r5, r2
	ldrh r1, [r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r2, r5, r3
	str r2, [sp]
	adds r2, r4, #0
	movs r3, #0x18
	bl FUN_0805d80c
	adds r4, #0x20
	movs r0, #0xff
	ands r4, r0
	subs r6, #1
	cmp r6, #0
	bge _080AEB44
	adds r0, #0x7b
	bl PlaySound_082406e0
	b _080AEB90
	.align 2, 0
_080AEB78: .4byte 0x0000134C
_080AEB7C: .4byte 0x030046B8
_080AEB80: .4byte 0x000003FF
_080AEB84: .4byte 0x0203B400
_080AEB88: .4byte 0x0000134E
_080AEB8C:
	movs r0, #0
	strh r0, [r3]
_080AEB90:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
