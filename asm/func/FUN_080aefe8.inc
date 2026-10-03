	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r0, _080AF018 @ =0x00001348
	adds r3, r5, r0
	ldr r2, _080AF01C @ =0x0000134A
	adds r1, r5, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bhs _080AF024
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080AF0A2
	ldr r3, _080AF020 @ =0x0000134C
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	b _080AF0A2
	.align 2, 0
_080AF018: .4byte 0x00001348
_080AF01C: .4byte 0x0000134A
_080AF020: .4byte 0x0000134C
_080AF024:
	ldr r0, _080AF090 @ =0x0000134C
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	movs r6, #0
	strh r2, [r1]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bhi _080AF0A0
	movs r0, #0x1f
	ands r2, r0
	cmp r2, #0
	bne _080AF0A2
	ldr r0, _080AF094 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r4, r5, r3
	movs r3, #0
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r3, _080AF098 @ =0x00000504
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r0, #0
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r3, _080AF09C @ =0x0000134E
	adds r2, r5, r3
	ldrh r3, [r2]
	movs r2, #0xa
	str r2, [sp]
	movs r2, #0x78
	str r2, [sp, #4]
	movs r2, #0x5a
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r2, #0xf
	bl FUN_0805f320
	b _080AF0A2
	.align 2, 0
_080AF090: .4byte 0x0000134C
_080AF094: .4byte 0x03002BE0
_080AF098: .4byte 0x00000504
_080AF09C: .4byte 0x0000134E
_080AF0A0:
	strh r6, [r3]
_080AF0A2:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
