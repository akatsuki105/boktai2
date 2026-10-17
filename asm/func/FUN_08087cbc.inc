	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _08087CF0 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08087CEC
	cmp r1, #0
	blt _08087CEC
	ldr r0, _08087CF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087CEC
	ldr r0, _08087CF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087CFC
_08087CEC:
	movs r4, #0
	b _08087D0A
	.align 2, 0
_08087CF0: .4byte 0x03002BE0
_08087CF4: .4byte 0x030046A8
_08087CF8: .4byte 0x030046AC
_08087CFC:
	ldr r0, _08087D1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087D0A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08087D20
	adds r0, #4
	b _08087D2C
	.align 2, 0
_08087D1C: .4byte 0x030046A4
_08087D20:
	ldr r0, _08087D6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087D2C:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	adds r6, r7, #0
	adds r6, #0x48
	cmp r0, #0
	beq _08087D3C
	b _08087E64
_08087D3C:
	ldr r0, _08087D70 @ =0x03002BE0
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08087D68
	cmp r1, #0
	blt _08087D68
	ldr r0, _08087D74 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087D68
	ldr r0, _08087D78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087D7C
_08087D68:
	movs r4, #0
	b _08087D8A
	.align 2, 0
_08087D6C: .4byte 0x030046A4
_08087D70: .4byte 0x03002BE0
_08087D74: .4byte 0x030046A8
_08087D78: .4byte 0x030046AC
_08087D7C:
	ldr r0, _08087D9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087D8A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08087DA0
	adds r0, #4
	b _08087DAC
	.align 2, 0
_08087D9C: .4byte 0x030046A4
_08087DA0:
	ldr r0, _08087DC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087DAC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087DC4
	cmp r2, #2
	beq _08087DC8
	b _08087DCC
	.align 2, 0
_08087DC0: .4byte 0x030046A4
_08087DC4:
	ldrb r0, [r5, #4]
	b _08087DCA
_08087DC8:
	ldrb r0, [r5]
_08087DCA:
	subs r1, r1, r0
_08087DCC:
	mov r8, r1
	adds r5, r7, #0
	adds r5, #0x48
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r5, #0
	cmp r2, #0
	blt _08087DF8
	cmp r1, #0
	blt _08087DF8
	ldr r0, _08087DFC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087DF8
	ldr r0, _08087E00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087E04
_08087DF8:
	movs r4, #0
	b _08087E12
	.align 2, 0
_08087DFC: .4byte 0x030046A8
_08087E00: .4byte 0x030046AC
_08087E04:
	ldr r0, _08087E24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087E12:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08087E28
	adds r0, #4
	b _08087E34
	.align 2, 0
_08087E24: .4byte 0x030046A4
_08087E28:
	ldr r0, _08087E48 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087E34:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087E4C
	cmp r2, #2
	beq _08087E50
	b _08087E54
	.align 2, 0
_08087E48: .4byte 0x030046A4
_08087E4C:
	ldrb r0, [r5, #4]
	b _08087E52
_08087E50:
	ldrb r0, [r5]
_08087E52:
	subs r1, r1, r0
_08087E54:
	mov r2, r8
	subs r0, r2, r1
	cmp r0, #0
	bge _08087E5E
	rsbs r0, r0, #0
_08087E5E:
	cmp r0, #0xff
	bgt _08087E64
	b _08087F72
_08087E64:
	ldr r2, _08087E90 @ =0x03002BE0
	ldr r1, [r2]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08087E8C
	cmp r1, #0
	blt _08087E8C
	ldr r0, _08087E94 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08087E8C
	ldr r0, _08087E98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087E9C
_08087E8C:
	movs r4, #0
	b _08087EAA
	.align 2, 0
_08087E90: .4byte 0x03002BE0
_08087E94: .4byte 0x030046A8
_08087E98: .4byte 0x030046AC
_08087E9C:
	ldr r0, _08087ED4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_08087EAA:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08087ECE
	cmp r1, #0
	blt _08087ECE
	ldr r0, _08087ED8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08087ECE
	ldr r0, _08087EDC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087EE0
_08087ECE:
	movs r3, #0
	b _08087EEE
	.align 2, 0
_08087ED4: .4byte 0x030046A4
_08087ED8: .4byte 0x030046A8
_08087EDC: .4byte 0x030046AC
_08087EE0:
	ldr r0, _08087F04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_08087EEE:
	adds r0, r4, #1
	cmp r3, r0
	bne _08087F08
	ldr r1, [r2]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	strh r0, [r1, #0x2c]
	b _08087F72
	.align 2, 0
_08087F04: .4byte 0x030046A4
_08087F08:
	subs r0, r4, #1
	cmp r3, r0
	bne _08087F20
	ldr r1, [r2]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
	strh r0, [r1, #0x2c]
	b _08087F72
_08087F20:
	ldr r0, _08087F44 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r1, [r0, r5]
	adds r0, r4, r1
	cmp r3, r0
	bne _08087F48
	ldr r1, [r2]
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	b _08087F70
	.align 2, 0
_08087F44: .4byte 0x030046A4
_08087F48:
	subs r0, r4, r1
	cmp r3, r0
	bne _08087F62
	ldr r1, [r2]
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
	b _08087F70
_08087F62:
	ldr r1, [r2]
	ldrh r0, [r6]
	strh r0, [r1, #0x2c]
	ldr r1, [r2]
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
_08087F70:
	strh r0, [r1, #0x30]
_08087F72:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
