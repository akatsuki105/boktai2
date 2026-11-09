	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _0818DE44 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818DE48
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818DE4A
	.align 2, 0
_0818DE44: .4byte 0x0000046C
_0818DE48:
	movs r0, #0
_0818DE4A:
	adds r1, r0, #0
	cmp r1, #0
	bne _0818DE52
	b _0818E028
_0818DE52:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _0818DEE8 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	subs r4, #0xd3
	strh r4, [r6, #8]
	movs r0, #0xfc
	lsls r0, r0, #8
	strh r0, [r6, #0xa]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r6, #0xc]
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0819014c
	movs r0, #0x20
	ldr r1, _0818DEEC @ =0x00000474
	adds r3, r6, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0818DEF0 @ =0x00000F2C
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0818DEF4 @ =0x0000047A
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r4, r6, r4
	ldrh r0, [r4]
	adds r1, r1, r0
	ldr r4, _0818DEF8 @ =0x0000025D
	adds r0, r6, r4
	ldrb r0, [r0]
	adds r7, r5, #0
	mov r8, r3
	adds r5, r2, #0
	cmp r0, #0
	bne _0818DEFC
	ldr r0, [r6, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _0818DF08
	.align 2, 0
_0818DEE8: .4byte 0x0000046D
_0818DEEC: .4byte 0x00000474
_0818DEF0: .4byte 0x00000F2C
_0818DEF4: .4byte 0x0000047A
_0818DEF8: .4byte 0x0000025D
_0818DEFC:
	ldr r2, [r6, #0x44]
	ldr r0, _0818DF78 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0818DF08:
	ldr r0, _0818DF7C @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #6
	movs r3, #0
	bl FUN_0819328c
	ldr r0, _0818DF80 @ =0x03002BE0
	add r2, sp, #4
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	strb r0, [r6, #5]
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r6, r4
	ldrb r4, [r6, #5]
	movs r0, #0x16
	mov ip, r0
	ldr r2, _0818DF84 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _0818DF88
	asrs r1, r0, #0xc
	b _0818DF8E
	.align 2, 0
_0818DF78: .4byte 0x03003584
_0818DF7C: .4byte 0xFFFFFEFF
_0818DF80: .4byte 0x03002BE0
_0818DF84: .4byte gSineTable
_0818DF88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818DF8E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0818DFAC @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0818DFB0
	asrs r0, r0, #0xc
	b _0818DFB6
	.align 2, 0
_0818DFAC: .4byte gSineTable
_0818DFB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818DFB6:
	movs r1, #0
	strh r0, [r3, #4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r0, #0x30
	strh r0, [r2]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	subs r4, #0x42
	adds r2, r6, r4
	ldr r1, _0818E014 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r6, #0
	bl FUN_081929cc
	ldr r1, _0818E018 @ =0x00000472
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl FUN_08191a14
	ldr r0, _0818E01C @ =0x000003E7
	bl PlaySound_082406e0
	ldr r0, _0818E020 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818E024 @ =0xFFFF7FFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	b _0818E146
	.align 2, 0
_0818E014: .4byte 0xFFEFFFFF
_0818E018: .4byte 0x00000472
_0818E01C: .4byte 0x000003E7
_0818E020: .4byte 0x000003E5
_0818E024: .4byte 0xFFFF7FFF
_0818E028:
	ldr r2, _0818E058 @ =0x00000484
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, #9
	bgt _0818E060
	add r4, sp, #0xc
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0818E05C @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
_0818E046:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #2
	ble _0818E046
	b _0818E0B8
	.align 2, 0
_0818E058: .4byte 0x00000484
_0818E05C: .4byte 0x05000002
_0818E060:
	cmp r0, #0x13
	bgt _0818E090
	add r4, sp, #0x14
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0818E08C @ =0x05000002
	bl CpuSet
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r5, #0
_0818E078:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #5
	ble _0818E078
	b _0818E0B8
	.align 2, 0
_0818E08C: .4byte 0x05000002
_0818E090:
	cmp r0, #0x3b
	bgt _0818E0B8
	add r4, sp, #0x1c
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0818E12C @ =0x05000002
	bl CpuSet
	movs r0, #0x40
	strh r0, [r4, #2]
	movs r5, #0
_0818E0A8:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #5
	ble _0818E0A8
_0818E0B8:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r6, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r3, #0xa
	ldrsh r1, [r6, r3]
	ldr r4, _0818E130 @ =0x00000472
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r1, r0
	blt _0818E0E0
	ldr r0, [r6, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0818E0E0:
	adds r0, r7, #0
	bl FUN_0818f008
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0818E13C
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x15
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818E134 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _0818E138 @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _0818E146
	.align 2, 0
_0818E12C: .4byte 0x05000002
_0818E130: .4byte 0x00000472
_0818E134: .4byte 0x00000469
_0818E138: .4byte 0x00000484
_0818E13C:
	ldr r4, _0818E154 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818E146:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818E154: .4byte 0x00000484
