	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08136DD0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldr r2, _08136D80 @ =0x00000AD8
	adds r1, r7, r2
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _08136DD0
	ldr r0, [r4, #0x44]
	ldr r5, [r0, #0x1c]
	ldr r6, [r0, #0x20]
	movs r0, #0
	mov ip, r0
	ldr r2, _08136D84 @ =0x00000B3A
	adds r1, r7, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp ip, r0
	bge _08136DD0
	movs r0, #2
	mov sl, r0
	movs r2, #1
	mov sb, r2
	mov r8, r1
	adds r3, r7, #0
	ldr r7, _08136D88 @ =0x00000755
	adds r4, r3, r7
_08136D72:
	ldrb r0, [r4]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _08136D8C
	movs r0, #1
	b _08136D8E
	.align 2, 0
_08136D80: .4byte 0x00000AD8
_08136D84: .4byte 0x00000B3A
_08136D88: .4byte 0x00000755
_08136D8C:
	movs r0, #0
_08136D8E:
	cmp r0, #0
	beq _08136DBA
	ldrb r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08136DA0
	movs r0, #1
	b _08136DA2
_08136DA0:
	movs r0, #0
_08136DA2:
	cmp r0, #0
	bne _08136DBA
	ldr r7, _08136DE0 @ =0x00000674
	adds r0, r3, r7
	ldr r1, [r0]
	ldr r2, [r0, #4]
	adds r7, #0xf0
	adds r0, r3, r7
	str r5, [r0]
	str r6, [r0, #4]
	adds r6, r2, #0
	adds r5, r1, #0
_08136DBA:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r3, r3, r0
	adds r4, r4, r0
	movs r1, #1
	add ip, r1
	mov r2, r8
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp ip, r0
	blt _08136D72
_08136DD0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136DE0: .4byte 0x00000674
