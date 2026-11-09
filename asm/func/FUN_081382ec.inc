	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08138304
	b _081384F2
_08138304:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
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
	blt _0813835A
	cmp r1, #0
	blt _0813835A
	ldr r0, _08138360 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813835A
	ldr r0, _08138364 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08138368
_0813835A:
	movs r4, #0
	b _08138376
	.align 2, 0
_08138360: .4byte 0x030046A8
_08138364: .4byte 0x030046AC
_08138368:
	ldr r0, _08138388 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08138376:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0813838C
	adds r0, #4
	b _08138398
	.align 2, 0
_08138388: .4byte 0x030046A4
_0813838C:
	ldr r0, _081383AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08138398:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081383B0
	adds r0, #4
	b _081383BC
	.align 2, 0
_081383AC: .4byte 0x030046A4
_081383B0:
	ldr r0, _081383D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081383BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081383D4
	cmp r2, #2
	beq _081383D8
	b _081383DC
	.align 2, 0
_081383D0: .4byte 0x030046A4
_081383D4:
	ldrb r0, [r7, #4]
	b _081383DA
_081383D8:
	ldrb r0, [r7]
_081383DA:
	subs r1, r1, r0
_081383DC:
	ldr r2, _08138490 @ =0x00000472
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, r1
	blt _081383EE
	movs r0, #0x43
	ands r6, r0
	cmp r6, #0
	beq _08138400
_081383EE:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r1, [r0]
_08138400:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _081384EC
	ldr r1, _08138494 @ =0x00000ADD
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _081384F2
	ldr r2, _08138498 @ =0x00000B49
	add r2, r8
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_081355f0
	mov r2, sp
	ldr r1, _0813849C @ =0x000004A4
	adds r0, r5, r1
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
	ble _081384A4
	ldr r0, _081384A0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081384B2
	.align 2, 0
_08138490: .4byte 0x00000472
_08138494: .4byte 0x00000ADD
_08138498: .4byte 0x00000B49
_0813849C: .4byte 0x000004A4
_081384A0: .4byte 0xFFFFFF00
_081384A4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081384B2
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081384B2:
	cmp r1, #0
	bge _081384B8
	rsbs r1, r1, #0
_081384B8:
	cmp r1, #0x20
	ble _081384F2
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _081384E4 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _081384E8 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _081384F2
	.align 2, 0
_081384E4: .4byte 0x00000469
_081384E8: .4byte 0x0000046C
_081384EC:
	ldr r0, _08138500 @ =0x00000ADD
	add r0, r8
	strb r1, [r0]
_081384F2:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08138500: .4byte 0x00000ADD
