	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0818ABFC @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818AC00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818AC02
	.align 2, 0
_0818ABFC: .4byte 0x0000046D
_0818AC00:
	movs r0, #0
_0818AC02:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	beq _0818AC54
	adds r0, r6, #0
	bl FUN_081957c4
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, #4
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	strb r0, [r6, #5]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0818AC98 @ =0xFFEFFFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0818AC9C @ =0x00000F2C
	adds r2, r4, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818AC54:
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Serpent_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0818ACA0 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818ACAC
	ldr r1, _0818ACA4 @ =0x000004B7
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _0818ACA8 @ =0x0000046E
	adds r7, r6, r2
	b _0818AD2E
	.align 2, 0
_0818AC98: .4byte 0xFFEFFFFF
_0818AC9C: .4byte 0x00000F2C
_0818ACA0: .4byte 0x0000025D
_0818ACA4: .4byte 0x000004B7
_0818ACA8: .4byte 0x0000046E
_0818ACAC:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _0818AD1C @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0818AD20 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _0818ACE6
	ldrb r0, [r7]
	cmp r0, #0
	bne _0818ACE6
	cmp r4, #1
	bne _0818ACD8
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0818AD32
_0818ACD8:
	cmp r4, #0
	bne _0818ACE6
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0818AD32
_0818ACE6:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0818ACF8
	movs r3, #6
_0818ACF8:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0818AD24
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _0818AD2C
	.align 2, 0
_0818AD1C: .4byte 0x000004B7
_0818AD20: .4byte 0x0000046E
_0818AD24:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0818AD2C:
	str r0, [r5, #8]
_0818AD2E:
	movs r0, #0
	strb r0, [r7]
_0818AD32:
	adds r0, r6, #0
	movs r1, #0x12
	movs r2, #6
	movs r3, #0
	bl FUN_0818faf0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	movs r1, #0x10
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0818ADA4
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _0818AD94 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r4, _0818AD98 @ =FUN_0818adc4
	movs r2, #0x24
	ldr r0, _0818AD9C @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818ADA0 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	b _0818ADB4
	.align 2, 0
_0818AD94: .4byte 0xFFFFFEFF
_0818AD98: .4byte FUN_0818adc4
_0818AD9C: .4byte 0x0000046D
_0818ADA0: .4byte 0x0000046B
_0818ADA4:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0818ADB4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
