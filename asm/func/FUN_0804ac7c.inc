	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x29
	ldrb r0, [r7]
	cmp r0, #0
	beq _0804AC96
	movs r0, #0
	strb r0, [r7]
_0804AC96:
	bl Save_ReadCurrentSlot
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0804AD24
	adds r6, r5, #0
	adds r6, #0x58
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x2c
	mov sl, r7
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x2a
	movs r0, #0x28
	adds r0, r0, r5
	mov sb, r0
	mov r1, r8
	ldrb r1, [r1]
	cmp r4, r1
	bge _0804ACEE
_0804ACC2:
	lsls r1, r4, #1
	adds r2, r1, #0
	adds r2, #0x1a
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r4, r0
	beq _0804ACD2
	adds r2, #1
_0804ACD2:
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	adds r1, #0x38
	movs r3, #0
	bl MainSprite_SetPose
	adds r4, #1
	adds r6, #0x60
	mov r2, r8
	ldrb r2, [r2]
	cmp r4, r2
	blt _0804ACC2
_0804ACEE:
	movs r4, #0
	ldrsb r4, [r7, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #3
	beq _0804AD14
	movs r0, #2
_0804AD14:
	movs r1, #0
	mov r2, sb
	strb r0, [r2]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	str r1, [r5, #0x34]
	b _0804AD30
_0804AD24:
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x28
	strb r1, [r0]
	strb r1, [r7]
	str r2, [r5, #0x34]
_0804AD30:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
