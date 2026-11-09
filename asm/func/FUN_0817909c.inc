	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xa0
	ldr r4, _081790D4 @ =0x00001008
	adds r0, r7, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081790D8
	movs r0, #1
	b _081790DA
	.align 2, 0
_081790D4: .4byte 0x00001008
_081790D8:
	movs r0, #0
_081790DA:
	cmp r0, #0
	beq _081790E8
	ldr r0, _081790E4 @ =0x00000FB5
	adds r1, r7, r0
	b _08179202
	.align 2, 0
_081790E4: .4byte 0x00000FB5
_081790E8:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r3
	cmp r2, #0
	blt _08179134
	cmp r1, #0
	blt _08179134
	ldr r0, _08179138 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08179134
	ldr r0, _0817913C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08179140
_08179134:
	movs r4, #0
	b _0817914E
	.align 2, 0
_08179138: .4byte 0x030046A8
_0817913C: .4byte 0x030046AC
_08179140:
	ldr r0, _08179160 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0817914E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08179164
	adds r0, #4
	b _08179170
	.align 2, 0
_08179160: .4byte 0x030046A4
_08179164:
	ldr r0, _08179184 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08179170:
	ldrh r6, [r0, #2]
	mov r8, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08179188
	adds r0, #4
	b _08179194
	.align 2, 0
_08179184: .4byte 0x030046A4
_08179188:
	ldr r0, _081791A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08179194:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081791AC
	cmp r2, #2
	beq _081791B2
	b _081791B8
	.align 2, 0
_081791A8: .4byte 0x030046A4
_081791AC:
	mov r2, r8
	ldrb r0, [r2, #4]
	b _081791B6
_081791B2:
	mov r3, r8
	ldrb r0, [r3]
_081791B6:
	subs r1, r1, r0
_081791B8:
	ldr r4, _081791F0 @ =0x00000472
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, r1
	blt _081791CA
	movs r0, #0x43
	ands r6, r0
	cmp r6, #0
	beq _081791DC
_081791CA:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_081791DC:
	movs r1, #0xa4
	ldr r3, _081791F4 @ =0x00001008
	adds r0, r7, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081791F8
	movs r0, #1
	b _081791FA
	.align 2, 0
_081791F0: .4byte 0x00000472
_081791F4: .4byte 0x00001008
_081791F8:
	movs r0, #0
_081791FA:
	cmp r0, #0
	beq _0817920C
	ldr r4, _08179208 @ =0x00000FB5
	adds r1, r7, r4
_08179202:
	movs r0, #0
	strb r0, [r1]
	b _081792EA
	.align 2, 0
_08179208: .4byte 0x00000FB5
_0817920C:
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _081792E4
	ldr r0, _0817928C @ =0x00000FB5
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _081792EA
	ldr r1, _08179290 @ =0x00001021
	adds r2, r7, r1
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_08175898
	mov r2, sp
	ldr r3, _08179294 @ =0x000004A4
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	mov r4, sb
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r5, r4
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0817929C
	ldr r0, _08179298 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081792AA
	.align 2, 0
_0817928C: .4byte 0x00000FB5
_08179290: .4byte 0x00001021
_08179294: .4byte 0x000004A4
_08179298: .4byte 0xFFFFFF00
_0817929C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081792AA
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081792AA:
	cmp r1, #0
	bge _081792B0
	rsbs r1, r1, #0
_081792B0:
	cmp r1, #0x20
	ble _081792EA
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _081792DC @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _081792E0 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _081792EA
	.align 2, 0
_081792DC: .4byte 0x00000469
_081792E0: .4byte 0x0000046C
_081792E4:
	ldr r2, _081792F8 @ =0x00000FB5
	adds r0, r7, r2
	strb r1, [r0]
_081792EA:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081792F8: .4byte 0x00000FB5
