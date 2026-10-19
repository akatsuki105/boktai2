	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x64
	ldr r1, _08208F34 @ =0x00000434
	adds r0, r6, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08208F80
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r7, #0
	ldrsh r1, [r5, r7]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r7, #4
	ldrsh r2, [r5, r7]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r4, #0
	adds r3, #0x61
	ldrb r1, [r3]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #8
	ble _08208F38
	ldrb r2, [r3]
	adds r2, #8
	strb r2, [r3]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	b _08208F70
	.align 2, 0
_08208F34: .4byte 0x00000434
_08208F38:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08208F46
	ldrb r0, [r3]
	subs r0, #8
	b _08208F4A
_08208F46:
	ldrb r0, [r3]
	adds r0, r0, r1
_08208F4A:
	strb r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r4, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r4, #0x19]
_08208F70:
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	mov r8, r0
	b _08208F84
_08208F80:
	movs r2, #0
	mov r8, r2
_08208F84:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08209048
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r1, [r0]
	ldr r7, _08209038 @ =0x00000225
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08209058
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08209014
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08209014
	ldr r7, _0820903C @ =0x00000446
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0
	beq _08208FFC
	ldr r2, _08209040 @ =0x00000442
	adds r0, r1, r2
	ldrh r0, [r0]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08209014
_08208FFC:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #1
	bls _08209010
	cmp r0, #7
	beq _08209010
	movs r1, #0
_08209010:
	cmp r1, #0
	bne _08209058
_08209014:
	ldr r0, _08209044 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08209058
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	beq _08209058
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl FUN_080415cc
	b _08209058
	.align 2, 0
_08209038: .4byte 0x00000225
_0820903C: .4byte 0x00000446
_08209040: .4byte 0x00000442
_08209044: .4byte 0x030047A4
_08209048:
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_08209058:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r7, #0xb9
	lsls r7, r7, #2
	adds r0, r4, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08209124
	ldr r1, _08209130 @ =0x00000434
	adds r0, r6, r1
	ldr r2, [r0]
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r3, [r0]
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r7, #0
	ldrsh r0, [r5, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _08209096
	rsbs r1, r1, #0
_08209096:
	cmp r1, r3
	bge _082090C4
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r7, #2
	ldrsh r0, [r5, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _082090AA
	rsbs r1, r1, #0
_082090AA:
	cmp r1, #0xff
	bgt _082090C4
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _082090BE
	rsbs r0, r0, #0
_082090BE:
	movs r1, #1
	cmp r0, r3
	blt _082090C6
_082090C4:
	movs r1, #0
_082090C6:
	cmp r1, #0
	beq _08209124
	ldr r3, _08209130 @ =0x00000434
	adds r0, r6, r3
	ldr r2, [r0]
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r7, r8
	subs r0, r7, r0
	adds r1, r4, #0
	adds r1, #0x61
	ldrb r1, [r1]
	adds r1, #0x80
	subs r1, r7, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08209108
	rsbs r0, r0, #0
_08209108:
	cmp r0, #0x3f
	bgt _08209124
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08209116
	rsbs r0, r0, #0
_08209116:
	cmp r0, #0x1f
	bgt _08209124
	movs r0, #0x80
	lsls r0, r0, #4
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_08209124:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08209130: .4byte 0x00000434
