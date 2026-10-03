	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08092C6C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08092C2E
	ldr r0, [r5, #0x40]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl TextBox_SetRect
	ldr r1, _08092C70 @ =0x00003F9E
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0xff
	bl TextBox_ShowLine
	ldr r1, _08092C74 @ =0x00003F9F
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #0
	bl TextBox_SetVarValue
_08092C2E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _08092C4C
	cmp r0, #0xf
	bls _08092C64
	ldr r0, _08092C78 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08092C64
_08092C4C:
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r5, #0
	bl FUN_08092744
_08092C64:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08092C6C: .4byte 0x000009EE
_08092C70: .4byte 0x00003F9E
_08092C74: .4byte 0x00003F9F
_08092C78: .4byte 0x030044E0
