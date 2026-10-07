	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r6, #0
	movs r7, #0xea
	lsls r7, r7, #2
	add r7, r8
	movs r0, #1
	rsbs r0, r0, #0
	mov sl, r0
	movs r1, #1
	mov sb, r1
_081D87E2:
	mov r1, sb
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D87F2
	movs r0, #1
	b _081D87F4
_081D87F2:
	movs r0, #0
_081D87F4:
	cmp r0, #0
	beq _081D882A
	movs r0, #0xdc
	muls r0, r6, r0
	adds r0, #0x38
	mov r1, r8
	adds r4, r1, r0
	mov r1, sb
	lsls r1, r6
	ldr r0, [r7]
	bics r0, r1
	str r0, [r7]
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r5, r4, #0
	adds r5, #0xd2
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, sl
	beq _081D882A
	adds r0, r4, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	ldr r0, _081D8844 @ =0x0000FFFF
	strh r0, [r5]
_081D882A:
	adds r6, #1
	cmp r6, #3
	ble _081D87E2
	ldr r1, _081D8848 @ =0x030001A0
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D8844: .4byte 0x0000FFFF
_081D8848: .4byte 0x030001A0
