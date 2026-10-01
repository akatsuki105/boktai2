	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0809E2FC @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	beq _0809E392
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0xf
	bhi _0809E392
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _0809E300
	bl VM_GetValue
	ldrb r2, [r5]
	movs r1, #0xa8
	muls r1, r2, r1
	adds r1, r6, r1
	adds r1, #0xc4
	strh r0, [r1]
	b _0809E30C
	.align 2, 0
_0809E2FC: .4byte 0x03000140
_0809E300:
	ldrb r1, [r5]
	movs r0, #0xa8
	muls r0, r1, r0
	adds r0, r6, r0
	adds r0, #0xc4
	strh r2, [r0]
_0809E30C:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809E392
	bl VM_GetValue
	ldrb r1, [r5]
	movs r4, #0xa8
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xcc
	strh r0, [r1]
	bl VM_GetValue
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xce
	strh r0, [r1]
	bl VM_GetValue
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xd0
	strh r0, [r1]
	bl VM_GetValue
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xd2
	strh r0, [r1]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xcc
	ldr r2, _0809E39C @ =0xFFFF0000
	ldrh r0, [r0]
	str r0, [sp]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xce
	ldrh r1, [r0]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl GetMapAreaAt
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xca
	strh r0, [r1]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc6
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_0809E392:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E39C: .4byte 0xFFFF0000
