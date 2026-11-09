	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08178B3A
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x20
	ldr r2, _08178AF8 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08178AFC
	movs r0, #1
	b _08178AFE
	.align 2, 0
_08178AF8: .4byte 0x00001008
_08178AFC:
	movs r0, #0
_08178AFE:
	adds r2, r0, #0
	cmp r2, #0
	bne _08178B3A
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldr r0, _08178B44 @ =0x00000FAA
	adds r1, r1, r0
	ldrh r0, [r5, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	add r4, sp, #0xc
	str r2, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _08178B48 @ =0x05000002
	bl CpuSet
	ldrh r1, [r5, #0x3e]
	adds r3, r6, #0
	adds r3, #0x1c
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0
	bl CreateDamageNumber
_08178B3A:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08178B44: .4byte 0x00000FAA
_08178B48: .4byte 0x05000002
