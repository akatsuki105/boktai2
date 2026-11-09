	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0814CAB8 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814CABC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814CABE
	.align 2, 0
_0814CAB8: .4byte 0x0000046D
_0814CABC:
	movs r0, #0
_0814CABE:
	cmp r0, #0
	beq _0814CAD2
	adds r0, r5, #0
	movs r1, #0xb
	bl Enemy_PlayAnim
	ldr r0, _0814CB04 @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_0814CAD2:
	ldr r1, _0814CB08 @ =0x00000482
	adds r3, r5, r1
	ldrh r6, [r3]
	movs r1, #0x80
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814CAEC
	movs r0, #3
	strh r0, [r3]
_0814CAEC:
	ldr r1, _0814CB0C @ =0x0000A02F
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814CB10
	ldr r0, _0814CB08 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0814CB20
	.align 2, 0
_0814CB04: .4byte 0x0000046E
_0814CB08: .4byte 0x00000482
_0814CB0C: .4byte 0x0000A02F
_0814CB10:
	ldr r1, _0814CB44 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0814CB20
	movs r0, #1
	strh r0, [r2]
_0814CB20:
	ldr r1, _0814CB48 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814CB4C
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _0814CB64
	.align 2, 0
_0814CB44: .4byte 0x00000482
_0814CB48: .4byte 0x0000025D
_0814CB4C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_0814CB64:
	ldr r1, _0814CB84 @ =0x00000482
	adds r0, r5, r1
	strh r6, [r0]
	subs r1, #0x14
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814CB7C
	ldr r0, _0814CB88 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0814CB7C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814CB84: .4byte 0x00000482
_0814CB88: .4byte 0x0000046B
