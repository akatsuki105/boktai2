	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080749C8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080749EE
	cmp r0, #1
	bgt _080749CC
	cmp r0, #0
	beq _080749D2
	b _08074A3A
	.align 2, 0
_080749C8: .4byte 0x0000037D
_080749CC:
	cmp r0, #2
	beq _08074A18
	b _08074A3A
_080749D2:
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074A3A
	adds r0, r5, #0
	movs r1, #0x10
	movs r2, #1
	bl FUN_08060b84
	b _08074A3A
_080749EE:
	ldr r1, _08074A10 @ =0x0000021A
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08074A14 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08074A3A
	adds r0, r5, #0
	bl FUN_080726b4
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _08074A3A
	.align 2, 0
_08074A10: .4byte 0x0000021A
_08074A14: .4byte 0x0000037E
_08074A18:
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074A3A
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	bl FUN_08072620
	adds r0, r5, #0
	bl FUN_080726b4
_08074A3A:
	pop {r4, r5}
	pop {r0}
	bx r0
