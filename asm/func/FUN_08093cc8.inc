	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08093D2C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08093CF4
	ldr r0, [r5, #0x40]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl TextBox_SetRect
	ldr r0, _08093D30 @ =0x00000103
	bl TextBox_ShowLine
_08093CF4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _08093D12
	cmp r0, #0xf
	bls _08093D24
	ldr r0, _08093D34 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093D24
_08093D12:
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r5, #0
	bl FUN_08092744
_08093D24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093D2C: .4byte 0x000009EE
_08093D30: .4byte 0x00000103
_08093D34: .4byte 0x030044E0
