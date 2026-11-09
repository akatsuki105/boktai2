	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0810AD7C @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810AD80
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810AD82
	.align 2, 0
_0810AD7C: .4byte 0x0000046D
_0810AD80:
	movs r0, #0
_0810AD82:
	cmp r0, #0
	beq _0810ADBE
	ldr r1, _0810ADAC @ =0x0000070C
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r5, _0810ADB0 @ =0x00000546
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0810ADB4
	movs r1, #0xe2
	lsls r1, r1, #3
	add r1, r8
	movs r0, #0xa
	b _0810ADBC
	.align 2, 0
_0810ADAC: .4byte 0x0000070C
_0810ADB0: .4byte 0x00000546
_0810ADB4:
	movs r1, #0xe2
	lsls r1, r1, #3
	add r1, r8
	movs r0, #5
_0810ADBC:
	strb r0, [r1]
_0810ADBE:
	adds r0, r7, #0
	movs r1, #0x14
	bl Enemy_PlayAnim
	ldr r0, _0810AE34 @ =0x0000070D
	add r0, r8
	ldr r1, _0810AE38 @ =0x0000070C
	add r1, r8
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _0810ADD8
	b _0810AF30
_0810ADD8:
	mov r0, sl
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	beq _0810ADE6
	b _0810AF30
_0810ADE6:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	lsls r0, r0, #6
	adds r2, r0, #0
	adds r2, #0xe0
	ands r2, r3
	ldr r4, _0810AE3C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810AE40 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0810AE44 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r6, r2, r0
	ands r6, r3
	add r5, sp, #0x18
	ldr r1, _0810AE48 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #7
	mov ip, r4
	cmp r0, #0
	blt _0810AE4C
	asrs r2, r0, #0xc
	b _0810AE52
	.align 2, 0
_0810AE34: .4byte 0x0000070D
_0810AE38: .4byte 0x0000070C
_0810AE3C: .4byte 0x030046B8
_0810AE40: .4byte 0x000003FF
_0810AE44: .4byte 0x0203B400
_0810AE48: .4byte gSineTable
_0810AE4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0810AE52:
	movs r0, #0
	strh r2, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	muls r0, r1, r0
	cmp r0, #0
	blt _0810AE6C
	asrs r0, r0, #0xc
	b _0810AE72
_0810AE6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810AE72:
	strh r0, [r5, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r1, sp, #0x18
	add r0, sp, #0x20
	ldrh r2, [r0]
	ldrh r1, [r1]
	adds r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r5, _0810AF70 @ =0xFFFF0000
	ldr r1, [sp, #0x20]
	ands r1, r5
	orrs r1, r2
	str r1, [sp, #0x20]
	ldr r4, _0810AF74 @ =0x0203B400
	mov sb, r4
	mov r1, ip
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _0810AF78 @ =0x000003FF
	ands r2, r4
	str r2, [r1]
	lsls r2, r2, #1
	add r2, sb
	ldr r3, [sp, #0x20]
	asrs r1, r3, #0x10
	adds r1, #0xdc
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldr r2, _0810AF7C @ =0x0000FFFF
	ands r2, r3
	orrs r2, r1
	str r2, [sp, #0x20]
	add r2, sp, #0x18
	ldrh r1, [r0, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, [r0, #4]
	ands r2, r5
	orrs r2, r1
	str r2, [r0, #4]
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ands r1, r4
	str r1, [r2]
	lsls r1, r1, #1
	add r1, sb
	ldrh r5, [r1]
	movs r2, #0xe2
	lsls r2, r2, #3
	add r2, r8
	movs r1, #0xf
	ands r5, r1
	ldrb r2, [r2]
	adds r2, r2, r5
	mov sb, r2
	ldr r1, _0810AF80 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x2c
	ldr r3, _0810AF84 @ =0x00000226
	adds r2, r7, r3
	ldrh r2, [r2]
	ldr r4, _0810AF88 @ =0x0000022E
	adds r3, r7, r4
	ldrh r3, [r3]
	movs r5, #0x90
	lsls r5, r5, #2
	adds r4, r7, r5
	ldr r4, [r4]
	str r4, [sp]
	subs r5, #0xa
	adds r4, r7, r5
	ldrh r4, [r4]
	str r4, [sp, #4]
	mov r4, sb
	str r4, [sp, #8]
	movs r4, #0x78
	str r4, [sp, #0xc]
	movs r4, #0xf0
	str r4, [sp, #0x10]
	str r6, [sp, #0x14]
	bl Entity081f53a8_Spawn
	ldr r1, _0810AF8C @ =0x0000070C
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0810AF30:
	mov r5, sl
	cmp r5, #0x78
	ble _0810AF60
	ldr r4, _0810AF90 @ =Skeleton_StateVolleyEnd
	movs r3, #0x30
	ldr r0, _0810AF94 @ =0x0000046D
	adds r1, r7, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810AF98 @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	ldr r5, _0810AF9C @ =0x00000553
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
_0810AF60:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810AF70: .4byte 0xFFFF0000
_0810AF74: .4byte 0x0203B400
_0810AF78: .4byte 0x000003FF
_0810AF7C: .4byte 0x0000FFFF
_0810AF80: .4byte 0x03002BE0
_0810AF84: .4byte 0x00000226
_0810AF88: .4byte 0x0000022E
_0810AF8C: .4byte 0x0000070C
_0810AF90: .4byte Skeleton_StateVolleyEnd
_0810AF94: .4byte 0x0000046D
_0810AF98: .4byte 0x0000046B
_0810AF9C: .4byte 0x00000553
