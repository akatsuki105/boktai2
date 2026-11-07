	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08143338 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814333C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814333E
	.align 2, 0
_08143338: .4byte 0x0000046D
_0814333C:
	movs r0, #0
_0814333E:
	cmp r0, #0
	beq _08143358
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_08143358:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r5, #0x13
	bgt _0814337A
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0814337A:
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0814339A
	asrs r0, r0, #2
	b _081433A0
_0814339A:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081433A0:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r6, #8
	adds r1, r7, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _081433BE
	asrs r0, r0, #2
	b _081433C4
_081433BE:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081433C4:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081433CE
	movs r3, #0xc8
	b _081433D8
_081433CE:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081433D8
	adds r3, r0, #0
_081433D8:
	cmp r2, #0xc8
	ble _081433E0
	movs r2, #0xc8
	b _081433EA
_081433E0:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081433EA
	adds r2, r0, #0
_081433EA:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0814340E
	cmp r2, #0
	bne _0814340E
	movs r0, #1
	b _08143410
_0814340E:
	movs r0, #0
_08143410:
	cmp r0, #0
	beq _081434BE
	cmp r5, #0x1e
	ble _081434BE
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #0xa
	movs r5, #0
	movs r2, #0
	mov sb, r2
	strh r0, [r1]
	ldr r3, _081434CC @ =0x0000046B
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xce
	lsls r0, r0, #3
	add r0, r8
	strb r5, [r0]
	adds r0, r7, #0
	bl FUN_081447cc
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r3, r7, r1
	ldrb r0, [r3]
	strb r0, [r7, #5]
	ldr r2, _081434D0 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r6, _081434D4 @ =0x0000046D
	adds r0, r7, r6
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	mov r6, sb
	strh r6, [r0]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _081434D8 @ =0x00000469
	adds r0, r7, r2
	strb r5, [r0]
	ldr r6, _081434DC @ =0x0000046A
	adds r0, r7, r6
	strb r4, [r0]
	adds r1, #0x1c
	adds r0, r7, r1
	mov r2, sb
	str r2, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldrb r0, [r3]
	strb r0, [r7, #5]
	subs r1, #2
	adds r0, r7, r1
	strh r4, [r0]
_081434BE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081434CC: .4byte 0x0000046B
_081434D0: .4byte Enemy_ClearStateBegun
_081434D4: .4byte 0x0000046D
_081434D8: .4byte 0x00000469
_081434DC: .4byte 0x0000046A
