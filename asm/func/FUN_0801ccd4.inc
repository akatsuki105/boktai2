	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	bl EntityDA0B_TakeFnChanged
	cmp r0, #0
	bne _0801CCEC
	b _0801CE0A
_0801CCEC:
	ldr r0, _0801CD64 @ =0x00000AA4
	adds r6, r7, r0
	ldr r1, _0801CD68 @ =0x00000978
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0801CD6C @ =0x000009FC
	adds r5, r7, r2
	subs r0, #0x24
	adds r0, r0, r7
	mov sb, r0
	ldr r1, _0801CD70 @ =0x00000B04
	adds r0, r7, r1
	adds r4, r7, #0
	adds r4, #0xf8
	adds r1, r4, #0
	movs r2, #0x39
	movs r3, #0
	bl MainSprite_SetPose
	bl FUN_08049e5c
	adds r0, r7, #0
	mov r1, sb
	bl FUN_0801b688
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x68
	strh r0, [r6, #0x20]
	movs r0, #0x28
	strh r0, [r6, #0x22]
	movs r2, #0
	mov sl, r2
	mov r1, r8
	ldrb r0, [r1, #1]
	ldrb r5, [r5, #1]
	cmp r0, r5
	beq _0801CD52
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r7, r2
	adds r0, r6, #0
	movs r2, #0x42
	movs r3, #0
	bl MainSprite_SetPose
	movs r0, #1
	mov sl, r0
_0801CD52:
	adds r0, r7, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801CD78
	ldr r0, _0801CD74 @ =0x000002DF
	strh r0, [r6, #0x3a]
	movs r0, #0
	b _0801CD80
	.align 2, 0
_0801CD64: .4byte 0x00000AA4
_0801CD68: .4byte 0x00000978
_0801CD6C: .4byte 0x000009FC
_0801CD70: .4byte 0x00000B04
_0801CD74: .4byte 0x000002DF
_0801CD78:
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6, #0x3a]
	movs r0, #1
_0801CD80:
	bl FUN_0801b670
	str r0, [r6, #0x48]
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0801CDE4 @ =0x00000BC4
	adds r0, r7, r2
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #4
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r0, _0801CDE8 @ =0x00000BCC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	ldr r1, _0801CDEC @ =0x0000130C
	adds r0, r7, r1
	ldr r0, [r0]
	bl TextBox_Start
	mov r2, sl
	cmp r2, #0
	bne _0801CDDA
	ldr r0, _0801CDF0 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sb
	ldrb r2, [r2, #3]
	cmp r0, r2
	blt _0801CDF4
_0801CDDA:
	movs r0, #1
	bl TextBox_ShowLine
	b _0801CDFA
	.align 2, 0
_0801CDE4: .4byte 0x00000BC4
_0801CDE8: .4byte 0x00000BCC
_0801CDEC: .4byte 0x0000130C
_0801CDF0: .4byte 0x030046A0
_0801CDF4:
	movs r0, #2
	bl TextBox_ShowLine
_0801CDFA:
	ldr r1, _0801CE40 @ =0x00000DA4
	adds r0, r7, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	bl FUN_08049e5c
_0801CE0A:
	ldr r4, _0801CE44 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801CE48
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801CEA4
	adds r1, r7, #0
	adds r1, #0x95
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801CE36
	movs r0, #0
	strb r0, [r1]
_0801CE36:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0801CEA4
	.align 2, 0
_0801CE40: .4byte 0x00000DA4
_0801CE44: .4byte 0x030044E0
_0801CE48:
	adds r0, r7, #0
	bl FUN_0801c188
	ldrh r1, [r4, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801CE78
	adds r0, r7, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801CE80
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _0801CE74 @ =FUN_0801d6c0
	adds r0, r7, #0
	bl EntityDA0B_SetFn
	b _0801CEB0
	.align 2, 0
_0801CE74: .4byte FUN_0801d6c0
_0801CE78:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801CEA4
_0801CE80:
	ldr r0, _0801CE9C @ =0x00000AA4
	adds r1, r7, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0801CEA0 @ =0x00000BCC
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0801c614
	b _0801CEB0
	.align 2, 0
_0801CE9C: .4byte 0x00000AA4
_0801CEA0: .4byte 0x00000BCC
_0801CEA4:
	adds r0, r7, #0
	bl FUN_0801c7dc
	ldr r0, [r7, #0x44]
	adds r0, #1
	str r0, [r7, #0x44]
_0801CEB0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
