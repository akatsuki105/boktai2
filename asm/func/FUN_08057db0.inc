	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	adds r5, r1, #0
	adds r7, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	str r0, [sp, #0xc]
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _08057E00
	movs r0, #0
	strb r0, [r5, #8]
	ldr r0, _08057E70 @ =0x00000EBC
	add r0, sl
	ldr r4, [r0]
	ldrh r0, [r4, #0x2c]
	ldr r1, _08057E74 @ =0xFFFFFF00
	adds r2, r1, #0
	ands r2, r0
	movs r3, #3
	adds r0, r7, #0
	ands r0, r3
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r3, #0
	strh r2, [r5, #0x1c]
	ldrh r0, [r4, #0x30]
	ands r1, r0
	asrs r0, r7, #2
	lsls r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	strb r3, [r5, #0xc]
	movs r0, #1
	strb r0, [r5, #0x10]
_08057E00:
	adds r4, r5, #0
	adds r4, #0x78
	adds r0, r4, #0
	movs r1, #0x20
	bl AuxAnim_SetAnimSpeed
	mov r2, sl
	ldr r1, [r2, #0x18]
	movs r3, #0
	ldrb r2, [r5, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r4, #0
	cmp r0, #1
	bhi _08057E22
	movs r3, #1
_08057E22:
	movs r0, #0
	cmp r2, #1
	bls _08057E2A
	movs r0, #1
_08057E2A:
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	ldr r0, [r5, #0x14]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08057E64
	ldr r0, _08057E70 @ =0x00000EBC
	add r0, sl
	ldr r4, [r0]
	ldrh r0, [r4, #0x2c]
	ldr r1, _08057E74 @ =0xFFFFFF00
	adds r2, r1, #0
	ands r2, r0
	movs r3, #3
	adds r0, r7, #0
	ands r0, r3
	lsls r0, r0, #5
	adds r2, r2, r0
	strh r2, [r5, #0x1c]
	ldrh r0, [r4, #0x30]
	ands r1, r0
	asrs r0, r7, #2
	lsls r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
_08057E64:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08057E78
	subs r0, #1
	strb r0, [r5, #0xe]
	b _08057EAE
	.align 2, 0
_08057E70: .4byte 0x00000EBC
_08057E74: .4byte 0xFFFFFF00
_08057E78:
	ldr r1, [r5, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057EAE
	ldrb r0, [r5, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057E90
	subs r0, #1
	strb r0, [r5, #0xf]
	b _08057EAE
_08057E90:
	movs r0, #0x1e
	strb r0, [r5, #0xf]
	movs r0, #0x78
	strb r0, [r5, #0xe]
	movs r1, #5
	mov r3, sl
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _08057EA4
	movs r1, #8
_08057EA4:
	strb r1, [r5, #4]
	movs r0, #1
	strb r0, [r5, #8]
	str r2, [r5, #0x14]
	b _080581CA
_08057EAE:
	ldrh r0, [r6, #0xa]
	cmp r0, #1
	bne _08057ECC
	ldr r2, _08057EC8 @ =0x085AB9A4
	ldrh r1, [r6, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #4
	asrs r0, r0, #6
	b _08057ECE
	.align 2, 0
_08057EC8: .4byte 0x085AB9A4
_08057ECC:
	movs r0, #0
_08057ECE:
	movs r4, #0
	strb r0, [r5, #6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08057EDA
	b _080581A0
_08057EDA:
	adds r2, r5, #0
	adds r2, #0x4c
	movs r6, #0x1c
	ldrsh r1, [r5, r6]
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	movs r6, #0x1e
	ldrsh r1, [r5, r6]
	movs r6, #0x20
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _08057EFA
	rsbs r0, r3, #0
_08057EFA:
	cmp r0, #0x17
	bgt _08057F36
	adds r0, r1, #0
	cmp r1, #0
	bge _08057F06
	rsbs r0, r1, #0
_08057F06:
	cmp r0, #0x17
	bgt _08057F28
	strb r4, [r5, #6]
	movs r0, #0xff
	strb r0, [r5, #0xb]
	movs r3, #1
	mov r7, sl
	ldr r1, [r7, #0x30]
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r5, #4]
	strb r3, [r5, #8]
	str r4, [r5, #0x14]
	b _080581CA
_08057F28:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r6, #1
	ldrb r4, [r5, #0xb]
	b _08057F8A
_08057F36:
	adds r0, r1, #0
	cmp r1, #0
	bge _08057F3E
	rsbs r0, r1, #0
_08057F3E:
	cmp r0, #0x17
	bgt _08057F56
	movs r2, #1
	cmp r3, #0
	bge _08057F4A
	movs r2, #3
_08057F4A:
	mvns r0, r1
	asrs r6, r0, #0x1f
	movs r0, #2
	ands r6, r0
	ldrb r4, [r5, #0xb]
	b _08057F90
_08057F56:
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	ldrb r4, [r5, #0xb]
	cmp r0, #0
	blt _08057F66
	movs r0, #1
	ands r0, r4
	b _08057F6A
_08057F66:
	movs r0, #1
	ands r0, r7
_08057F6A:
	cmp r0, #0
	bne _08057F80
	movs r2, #1
	cmp r3, #0
	bge _08057F76
	movs r2, #3
_08057F76:
	mvns r0, r1
	asrs r6, r0, #0x1f
	movs r0, #2
	ands r6, r0
	b _08057F90
_08057F80:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r6, #1
_08057F8A:
	cmp r3, #0
	bge _08057F90
	movs r6, #3
_08057F90:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08057FA6
	movs r0, #1
	adds r1, r6, #0
	ands r1, r0
	ands r0, r4
	cmp r1, r0
	bne _08057FA6
	movs r6, #0xb
	ldrsb r6, [r5, r6]
_08057FA6:
	str r5, [sp, #0x10]
	mov r8, r2
	str r6, [sp, #0x14]
	ldrb r0, [r5, #6]
	mov sb, r0
	adds r1, r5, #0
	adds r1, #0x20
	str r1, [sp, #0x18]
_08057FB6:
	ldr r0, [sp, #0x10]
	adds r0, #0x68
	ldrh r0, [r0]
	ldr r1, _08057FEC @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #0x6c
	ldrh r0, [r0]
	add r4, sp, #4
	ldr r2, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	movs r0, #1
	mov r7, r8
	ands r0, r7
	cmp r0, #0
	bne _08058000
	cmp r7, #0
	bne _08057FF0
	ldrh r0, [r4, #4]
	mov r3, sb
	subs r0, r0, r3
	b _08057FF4
	.align 2, 0
_08057FEC: .4byte 0xFFFF0000
_08057FF0:
	ldrh r0, [r4, #4]
	add r0, sb
_08057FF4:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	b _08058020
_08058000:
	mov r7, r8
	cmp r7, #1
	bne _0805800E
	add r0, sp, #4
	ldrh r0, [r0]
	add r0, sb
	b _08058016
_0805800E:
	add r0, sp, #4
	ldrh r0, [r0]
	mov r2, sb
	subs r0, r0, r2
_08058016:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
_08058020:
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058048
	cmp r1, #0
	blt _08058048
	ldr r0, _0805804C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058048
	ldr r0, _08058050 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058054
_08058048:
	movs r4, #0
	b _08058062
	.align 2, 0
_0805804C: .4byte 0x030046A8
_08058050: .4byte 0x030046AC
_08058054:
	ldr r0, _08058074 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058062:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08058078
	adds r0, #4
	b _08058084
	.align 2, 0
_08058074: .4byte 0x030046A4
_08058078:
	ldr r0, _080580BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058084:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08058120
	add r7, sp, #4
	adds r0, r7, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080580B6
	cmp r1, #0
	blt _080580B6
	ldr r0, _080580C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080580B6
	ldr r0, _080580C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080580C8
_080580B6:
	movs r4, #0
	b _080580D6
	.align 2, 0
_080580BC: .4byte 0x030046A4
_080580C0: .4byte 0x030046A8
_080580C4: .4byte 0x030046AC
_080580C8:
	ldr r0, _080580E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080580D6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080580EC
	adds r0, #4
	b _080580F8
	.align 2, 0
_080580E8: .4byte 0x030046A4
_080580EC:
	ldr r0, _0805810C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080580F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058110
	cmp r2, #2
	beq _08058114
	b _08058118
	.align 2, 0
_0805810C: .4byte 0x030046A4
_08058110:
	ldrb r0, [r7, #4]
	b _08058116
_08058114:
	ldrb r0, [r7]
_08058116:
	subs r1, r1, r0
_08058118:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _08058136
_08058120:
	ldr r3, [sp, #0x14]
	cmp r3, #0
	blt _08058130
	mov r8, r3
	movs r7, #1
	rsbs r7, r7, #0
	str r7, [sp, #0x14]
	b _08057FB6
_08058130:
	movs r2, #1
	rsbs r2, r2, #0
	b _08058138
_08058136:
	mov r2, r8
_08058138:
	cmp r2, r6
	bne _08058140
	strb r2, [r5, #0xb]
	b _08058144
_08058140:
	movs r0, #0xff
	strb r0, [r5, #0xb]
_08058144:
	cmp r2, #0
	bge _0805814C
	movs r2, #0
	strb r2, [r5, #6]
_0805814C:
	strb r2, [r5, #5]
	movs r3, #0
	ldrb r1, [r5, #5]
	ldrb r0, [r5, #6]
	ldr r2, [sp, #0x18]
	strh r3, [r2, #2]
	cmp r1, #1
	beq _08058178
	cmp r1, #1
	bgt _08058166
	cmp r1, #0
	beq _08058170
	b _0805818C
_08058166:
	cmp r1, #2
	beq _0805817E
	cmp r1, #3
	beq _08058184
	b _0805818C
_08058170:
	strh r3, [r5, #0x20]
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	b _0805818C
_08058178:
	strh r0, [r5, #0x20]
	strh r3, [r2, #4]
	b _0805818C
_0805817E:
	strh r3, [r5, #0x20]
	strh r0, [r2, #4]
	b _0805818C
_08058184:
	rsbs r0, r0, #0
	strh r0, [r5, #0x20]
	ldr r0, [sp, #0x18]
	strh r3, [r0, #4]
_0805818C:
	ldrh r0, [r5, #0x20]
	ldr r1, [sp, #0xc]
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	strh r0, [r2, #0x1c]
	ldrh r0, [r5, #0x24]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
_080581A0:
	mov r0, sl
	adds r1, r5, #0
	bl FUN_08056a34
	cmp r0, #0
	beq _080581C4
	movs r2, #2
	mov r6, sl
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _080581B8
	movs r2, #8
_080581B8:
	movs r1, #0
	strb r2, [r5, #4]
	movs r0, #1
	strb r0, [r5, #8]
	str r1, [r5, #0x14]
	b _080581CA
_080581C4:
	ldr r0, [r5, #0x14]
	adds r0, #1
	str r0, [r5, #0x14]
_080581CA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
