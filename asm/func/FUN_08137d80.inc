	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08137E86
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	movs r2, #0
	mov sb, r2
	ldr r7, _08137DD0 @ =0x00000B3A
	adds r0, r6, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	bge _08137E86
	adds r4, r6, #0
	ldr r2, _08137DD4 @ =0x0000076E
	adds r3, r6, r2
	movs r7, #2
	mov r8, r7
	movs r0, #0x90
	lsls r0, r0, #1
	mov ip, r0
	ldr r1, _08137DD8 @ =0x00000755
	adds r5, r6, r1
_08137DC0:
	ldrb r0, [r5]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _08137DDC
	movs r0, #1
	b _08137DDE
	.align 2, 0
_08137DD0: .4byte 0x00000B3A
_08137DD4: .4byte 0x0000076E
_08137DD8: .4byte 0x00000755
_08137DDC:
	movs r0, #0
_08137DDE:
	cmp r0, #0
	beq _08137E70
	movs r1, #1
	ldrb r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08137DF0
	movs r0, #1
	b _08137DF2
_08137DF0:
	movs r0, #0
_08137DF2:
	cmp r0, #0
	bne _08137E70
	ldr r7, _08137E2C @ =0x00000674
	adds r1, r4, r7
	ldr r0, _08137E30 @ =0x0000076C
	adds r2, r4, r0
	ldrh r0, [r2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldr r0, _08137E34 @ =0x00000676
	adds r1, r4, r0
	ldrh r0, [r3]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r3, #2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _08137E38
	asrs r1, r0, #1
	b _08137E3E
	.align 2, 0
_08137E2C: .4byte 0x00000674
_08137E30: .4byte 0x0000076C
_08137E34: .4byte 0x00000676
_08137E38:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08137E3E:
	ldr r2, _08137E50 @ =0x0000076C
	adds r0, r4, r2
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, #0
	blt _08137E54
	asrs r0, r0, #1
	b _08137E5A
	.align 2, 0
_08137E50: .4byte 0x0000076C
_08137E54:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08137E5A:
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _08137E68
	asrs r0, r0, #1
	b _08137E6E
_08137E68:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08137E6E:
	strh r0, [r3, #2]
_08137E70:
	add r4, ip
	add r5, ip
	add r3, ip
	movs r2, #1
	add sb, r2
	ldr r7, _08137E94 @ =0x00000B3A
	adds r0, r6, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	blt _08137DC0
_08137E86:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08137E94: .4byte 0x00000B3A
