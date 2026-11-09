	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _0805ECE8
	movs r0, #0
	strb r0, [r4, #2]
	ldr r0, _0805ED5C @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _0805ECE8
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x18
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #0x1c
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #3]
_0805ECE8:
	ldr r3, [r4, #0x14]
	movs r0, #0xf
	ands r3, r0
	cmp r3, #0xf
	bne _0805ED3A
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0805ED3A
	ldr r2, _0805ED60 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805ED64 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0805ED68 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	ands r1, r3
	ldrb r3, [r4, #3]
	adds r1, r1, r3
	subs r1, #8
	ldrh r2, [r4, #6]
	ldrh r3, [r4, #4]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	ldrh r0, [r4, #0xc]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x18
	str r0, [sp, #0x10]
	adds r0, r5, #0
	bl Entity0805f2dc_Spawn
_0805ED3A:
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #4
	ldr r1, [r4, #0x14]
	cmp r1, r0
	bne _0805ED78
	ldrb r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r4, #0xf]
	cmp r0, r2
	bhs _0805ED6C
	movs r0, #2
	b _0805ED6E
	.align 2, 0
_0805ED5C: .4byte 0x03002BE0
_0805ED60: .4byte 0x030046B8
_0805ED64: .4byte 0x000003FF
_0805ED68: .4byte 0x0203B400
_0805ED6C:
	movs r0, #5
_0805ED6E:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4, #2]
	str r1, [r4, #0x14]
	b _0805ED7C
_0805ED78:
	adds r0, r1, #1
	str r0, [r4, #0x14]
_0805ED7C:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
