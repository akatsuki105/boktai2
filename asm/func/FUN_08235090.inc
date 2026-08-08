	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r0, r4, #0
	bl FUN_08234f44
	adds r3, r0, #0
	cmp r3, #0
	beq _082350AA
	ldrb r0, [r3]
	cmp r0, #0
	bne _082350B6
_082350AA:
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #2]
	strh r0, [r5, #4]
	subs r0, #1
	b _08235170
_082350B6:
	ldr r2, _08235108 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0823510C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08235110 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrb r1, [r3]
	bl Mod
	adds r6, r0, #0
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08234f90
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08235102
	cmp r1, #0
	blt _08235102
	ldr r0, _08235114 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08235102
	ldr r0, _08235118 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823511C
_08235102:
	movs r4, #0
	b _0823512A
	.align 2, 0
_08235108: .4byte 0x030046B8
_0823510C: .4byte 0x000003FF
_08235110: .4byte 0x0203B400
_08235114: .4byte 0x030046A8
_08235118: .4byte 0x030046AC
_0823511C:
	ldr r0, _0823513C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823512A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235140
	adds r0, #4
	b _0823514C
	.align 2, 0
_0823513C: .4byte 0x030046A4
_08235140:
	ldr r0, _08235160 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823514C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08235164
	cmp r2, #2
	beq _08235168
	b _0823516C
	.align 2, 0
_08235160: .4byte 0x030046A4
_08235164:
	ldrb r0, [r5, #4]
	b _0823516A
_08235168:
	ldrb r0, [r5]
_0823516A:
	subs r1, r1, r0
_0823516C:
	strh r1, [r5, #2]
	adds r0, r6, #0
_08235170:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
