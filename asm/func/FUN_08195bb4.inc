	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08195C0C @ =0x00000C6C
	adds r5, r4, r0
	ldr r0, [r5]
	lsls r0, r0, #4
	ldr r2, _08195C10 @ =0x00000CC2
	adds r1, r4, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl Div
	ldr r3, _08195C14 @ =0x00000C34
	adds r2, r4, r3
	strb r0, [r2]
	ldr r0, [r5]
	subs r0, #1
	str r0, [r5]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _08195C20
	ldr r1, _08195C18 @ =0x00000C36
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	adds r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	orrs r0, r1
	ldr r2, _08195C1C @ =0x00000CA2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0
	b _08195C54
	.align 2, 0
_08195C0C: .4byte 0x00000C6C
_08195C10: .4byte 0x00000CC2
_08195C14: .4byte 0x00000C34
_08195C18: .4byte 0x00000C36
_08195C1C: .4byte 0x00000CA2
_08195C20:
	movs r3, #0xc6
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, _08195C5C @ =FUN_081958b4
	str r0, [r1]
	movs r0, #0
	str r0, [r5]
	ldr r1, _08195C60 @ =0x00000C36
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	subs r3, #0x2b
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	orrs r0, r1
	ldr r2, _08195C64 @ =0x00000CA2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #1
_08195C54:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08195C5C: .4byte FUN_081958b4
_08195C60: .4byte 0x00000C36
_08195C64: .4byte 0x00000CA2
