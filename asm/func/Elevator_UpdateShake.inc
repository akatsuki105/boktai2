	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0xc6
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _081D2F2C
	ldrh r2, [r7, #0x1e]
	adds r0, r1, r2
	strh r0, [r7, #0x1e]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #2
	bl Div
	strh r0, [r4]
_081D2F2C:
	movs r2, #0x80
	adds r1, r7, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081D2F40
	movs r0, #1
	b _081D2F42
_081D2F40:
	movs r0, #0
_081D2F42:
	cmp r0, #0
	bne _081D2FAE
	movs r1, #0x20
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D2F54
	movs r0, #1
	b _081D2F56
_081D2F54:
	movs r0, #0
_081D2F56:
	cmp r0, #0
	beq _081D2FB8
	ldr r2, _081D2FC4 @ =0x0203B400
	mov r8, r2
	ldr r4, _081D2FC8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081D2FCC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xc
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #6
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	ldrh r2, [r7, #0x1e]
	adds r1, r1, r2
	strh r1, [r7, #0x1e]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xc
	bl Mod
	ldrh r1, [r7, #0x20]
	subs r1, #6
	adds r1, r1, r0
	strh r1, [r7, #0x20]
_081D2FAE:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
_081D2FB8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2FC4: .4byte 0x0203B400
_081D2FC8: .4byte 0x030046B8
_081D2FCC: .4byte 0x000003FF
