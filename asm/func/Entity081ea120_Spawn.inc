	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r8, r1
	str r2, [sp, #4]
	cmp r0, #0
	beq _081E9F96
	ldr r0, _081E9F9C @ =0x030001B8
	ldr r6, [r0]
	cmp r6, #0
	bne _081E9FA0
_081E9F96:
	movs r0, #1
	rsbs r0, r0, #0
	b _081EA01E
	.align 2, 0
_081E9F9C: .4byte 0x030001B8
_081E9FA0:
	movs r7, #0
	cmp r7, r8
	bge _081EA01C
	movs r0, #1
	mov sl, r0
	lsls r3, r3, #0x10
	str r3, [sp, #8]
_081E9FAE:
	adds r0, r6, #0
	bl Entity081ea120_AllocItem
	adds r5, r0, #0
	cmp r5, #0
	beq _081E9F96
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	movs r0, #0x2c
	adds r4, r1, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r6, r4
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5]
	str r1, [r5, #4]
	adds r0, r4, #0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	lsls r0, r0, #4
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	ldr r1, [r6, #0x18]
	movs r2, #0
	str r2, [sp]
	ldr r3, [sp, #8]
	lsrs r2, r3, #0x10
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r4, #0xc]
	ldr r1, [sp, #0x2c]
	bl Video_SetAuxSpritePltt
	ldr r0, [r4]
	mov r1, sl
	orrs r0, r1
	str r0, [r4]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r4, #7]
	strb r1, [r5, #0xa]
	adds r7, #1
	cmp r7, r8
	blt _081E9FAE
_081EA01C:
	movs r0, #0
_081EA01E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
