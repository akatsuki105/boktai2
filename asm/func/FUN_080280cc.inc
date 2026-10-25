	push {r4, r5, lr}
	adds r2, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080280E6
	adds r0, r2, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x40
	bgt _08028100
_080280E6:
	ldr r0, _08028104 @ =0x000008DD
	adds r5, r2, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08028100
	ldr r1, _08028108 @ =0x00000888
	adds r3, r2, r1
	ldrh r0, [r3]
	adds r4, r0, #0
	cmp r4, #0
	beq _0802810C
	subs r0, #1
	strh r0, [r3]
_08028100:
	movs r0, #0
	b _0802812C
	.align 2, 0
_08028104: .4byte 0x000008DD
_08028108: .4byte 0x00000888
_0802810C:
	ldr r1, _08028134 @ =0x000008D2
	adds r0, r2, r1
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r3]
	strb r1, [r5]
	movs r0, #0x11
	adds r1, r2, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xbc
	str r4, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
_0802812C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08028134: .4byte 0x000008D2
