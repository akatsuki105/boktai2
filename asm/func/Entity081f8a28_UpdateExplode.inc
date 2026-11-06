	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r4, r1, #0
	movs r0, #0x91
	lsls r0, r0, #1
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081F869E
	adds r0, r4, #0
	adds r0, #0x1c
	movs r1, #0x40
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	movs r1, #0x10
	str r1, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0x80
	bl SpawnAttackBox
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	mov r8, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081F86AC @ =0x00000111
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081F8676
	adds r0, r4, #0
	adds r0, #0x3c
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
_081F8676:
	adds r0, r4, #0
	bl AuxSprite_Remove
	ldr r0, _081F86B0 @ =0x0000011F
	adds r2, r4, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x38]
	bics r0, r1
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r1, r8
	strb r1, [r0]
	strb r1, [r7]
_081F869E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F86AC: .4byte 0x00000111
_081F86B0: .4byte 0x0000011F
