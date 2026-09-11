	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0
	str r0, [r7, #0x18]
	ldr r0, _08013210 @ =0x000B8E6E
	str r0, [r7, #0x24]
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _08013098
	b _08013238
_08013098:
	bl VM_GetPC
	bl VM_ParseStringRef
	bl Textbox_LookupString
	ldr r1, _08013214 @ =0x00000444
	adds r4, r7, r1
	str r0, [r4]
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _080130B6
	b _08013238
_080130B6:
	bl VM_GetPC
	movs r2, #0x89
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	cmp r0, #0
	bne _080130C8
	b _08013238
_080130C8:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r7, #0x28]
	adds r0, r7, #0
	bl PasswordScreen_EncodeBits
	adds r5, r7, #0
	adds r5, #0x2a
	movs r1, #0
	mov ip, r4
_080130E0:
	lsls r0, r1, #8
	adds r0, #0x42
	adds r2, r7, r0
	movs r4, #0
	adds r1, #1
	mov r8, r1
_080130EC:
	ldrb r0, [r5]
	lsls r1, r0, #1
	adds r5, #1
	adds r6, r4, #1
	cmp r1, #0x59
	ble _0801310A
	movs r3, #0
	ldr r4, _08013218 @ =0x085AA838
_080130FC:
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, #1
	adds r3, #1
	cmp r3, #7
	ble _080130FC
_0801310A:
	mov r3, ip
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, #1
	ldr r0, [r3]
	adds r0, r1, r0
	ldrb r0, [r0, #1]
	strb r0, [r2]
	adds r2, #1
	cmp r1, #0x59
	ble _08013136
	movs r3, #0
	ldr r4, _0801321C @ =0x085AA844
_08013128:
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, #1
	adds r3, #1
	cmp r3, #8
	ble _08013128
_08013136:
	adds r4, r6, #0
	cmp r4, #5
	ble _080130EC
	movs r0, #0
	strb r0, [r2]
	mov r1, r8
	cmp r1, #3
	ble _080130E0
	adds r0, r7, #0
	movs r1, #0xc
	bl FUN_08012c74
	ldr r0, _08013220 @ =0x0000044C
	adds r6, r7, r0
	movs r0, #2
	movs r1, #5
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	str r0, [r6]
	cmp r0, #0
	blt _08013238
	movs r4, #0
	adds r5, r7, #0
	adds r5, #0x42
_0801316A:
	ldr r0, [r6]
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0804a40c
	movs r1, #0x80
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r4, #1
	cmp r4, #3
	ble _0801316A
	ldr r0, [r6]
	movs r2, #0x89
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r1, [r4]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	movs r3, #0x8a
	lsls r3, r3, #3
	adds r6, r7, r3
	movs r0, #6
	movs r1, #0x11
	movs r2, #0x1c
	movs r3, #1
	bl FUN_0804a084
	str r0, [r6]
	cmp r0, #0
	blt _08013238
	ldr r1, [r4]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	ldr r0, _08013224 @ =0x00000454
	adds r6, r7, r0
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	str r0, [r6]
	cmp r0, #0
	blt _08013238
	ldr r1, [r4]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #2
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	ldr r0, _08013228 @ =0x000092B3
	ldr r1, _0801322C @ =0x0000519C
	bl GetFile
	cmp r0, #0
	beq _08013238
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _08013230 @ =0x03004430
	ldr r2, _08013234 @ =0x04000008
	bl CpuSet
	movs r0, #0
	b _0801323C
	.align 2, 0
_08013210: .4byte 0x000B8E6E
_08013214: .4byte 0x00000444
_08013218: .4byte 0x085AA838
_0801321C: .4byte 0x085AA844
_08013220: .4byte 0x0000044C
_08013224: .4byte 0x00000454
_08013228: .4byte 0x000092B3
_0801322C: .4byte 0x0000519C
_08013230: .4byte 0x03004430
_08013234: .4byte 0x04000008
_08013238:
	movs r0, #1
	rsbs r0, r0, #0
_0801323C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
