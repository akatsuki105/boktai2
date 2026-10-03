	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r0, _08093F14 @ =0x000009EE
	adds r6, r5, r0
	ldrh r0, [r6]
	cmp r0, #0
	bne _08093EB6
	bl TextBox_Close
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	ldr r0, _08093F18 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #4
	bl FUN_08242b14
	ldr r2, _08093F1C @ =0x00004018
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0x1e
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r1, [r5, #0x44]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldr r1, _08093F20 @ =0x000009E4
	adds r2, r5, r1
	add r1, sp, #4
	bl FUN_08094d30
	ldr r0, [r4]
	bl TextPanel_Start
_08093EB6:
	ldrh r0, [r6]
	cmp r0, #8
	bne _08093ED0
	ldr r0, [r5, #0x40]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #0x82
	lsls r0, r0, #1
	bl TextBox_ShowLine
_08093ED0:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _08093EEE
	cmp r0, #0xf
	bls _08093F0A
	ldr r0, _08093F24 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093F0A
_08093EEE:
	ldr r2, _08093F1C @ =0x00004018
	adds r0, r5, r2
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r5, #0
	bl FUN_08092744
_08093F0A:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093F14: .4byte 0x000009EE
_08093F18: .4byte 0x030046A0
_08093F1C: .4byte 0x00004018
_08093F20: .4byte 0x000009E4
_08093F24: .4byte 0x030044E0
