	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r1, #8
	bl ClearMemory
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #8
	bl ClearMemory
	ldr r2, _0815EB40 @ =0x000006C2
	adds r0, r4, r2
	movs r5, #0
	strh r5, [r0]
	ldr r1, _0815EB44 @ =0x000006DC
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _0815EB48 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0815EB4C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0815EB50 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r2, _0815EB54 @ =0x000006EE
	adds r1, r4, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Mod
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _0815EB58 @ =0x000006CA
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r5, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #0x16
	adds r0, r4, r2
	strh r5, [r0]
	adds r1, #0x16
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r5, [r0]
	adds r1, #6
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r5, [r0]
	subs r1, #0xa
	adds r0, r4, r1
	strh r5, [r0]
	subs r2, #2
	adds r0, r4, r2
	strh r5, [r0]
	ldr r0, _0815EB5C @ =0x00000704
	adds r4, r4, r0
	str r5, [r4]
	adds r0, r6, #0
	bl Enemy_StepTowardPathNode
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0815EB60
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0815EB68
	.align 2, 0
_0815EB40: .4byte 0x000006C2
_0815EB44: .4byte 0x000006DC
_0815EB48: .4byte 0x030046B8
_0815EB4C: .4byte 0x000003FF
_0815EB50: .4byte 0x0203B400
_0815EB54: .4byte 0x000006EE
_0815EB58: .4byte 0x000006CA
_0815EB5C: .4byte 0x00000704
_0815EB60:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0815EB68:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0815EB8C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0815EB94
_0815EB8C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0815EB94:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0815EBCC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0815EC04
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0815EBD0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0815EBC4
	ldrb r0, [r4, #5]
_0815EBC4:
	subs r0, #1
	strh r0, [r4, #8]
	b _0815EBE0
	.align 2, 0
_0815EBCC: .4byte 0x0000FFFF
_0815EBD0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0815EBE0
	strh r1, [r4, #8]
_0815EBE0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815EC04
	movs r0, #1
	strb r0, [r4, #7]
_0815EC04:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
