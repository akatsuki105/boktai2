	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x64
	ldr r1, _08042AB4 @ =0x00000434
	adds r0, r6, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08042B00
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
	ble _08042AB8
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
	b _08042AF0
	.align 2, 0
_08042AB4: .4byte 0x00000434
_08042AB8:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08042AC6
	ldrb r0, [r3]
	subs r0, #8
	b _08042ACA
_08042AC6:
	ldrb r0, [r3]
	adds r0, r0, r1
_08042ACA:
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
_08042AF0:
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	mov r8, r0
	b _08042B04
_08042B00:
	movs r2, #0
	mov r8, r2
_08042B04:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08042C02
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r1, [r0]
	ldr r7, _08042BE0 @ =0x00000225
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08042C12
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08042B94
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08042B94
	ldr r7, _08042BE4 @ =0x00000446
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0
	beq _08042B7C
	ldr r2, _08042BE8 @ =0x00000442
	adds r0, r1, r2
	ldrh r0, [r0]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08042B94
_08042B7C:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #1
	bls _08042B90
	cmp r0, #7
	beq _08042B90
	movs r1, #0
_08042B90:
	cmp r1, #0
	bne _08042C12
_08042B94:
	ldr r0, _08042BEC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08042C12
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	beq _08042C12
	movs r7, #0x87
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08042BC6
	bl FUN_080865c0
	movs r1, #1
	cmp r0, #0
	bne _08042BC8
_08042BC6:
	movs r1, #0
_08042BC8:
	cmp r1, #0
	bne _08042BD8
	movs r1, #4
	ldr r0, _08042BF0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08042BF4
_08042BD8:
	adds r0, r4, #0
	movs r1, #0
	b _08042BF8
	.align 2, 0
_08042BE0: .4byte 0x00000225
_08042BE4: .4byte 0x00000446
_08042BE8: .4byte 0x00000442
_08042BEC: .4byte 0x030047A4
_08042BF0: .4byte 0x03002BC0
_08042BF4:
	adds r0, r4, #0
	movs r1, #3
_08042BF8:
	movs r2, #0
	movs r3, #0
	bl FUN_080415cc
	b _08042C12
_08042C02:
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08042C12:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08042CDE
	ldr r3, _08042CEC @ =0x00000434
	adds r0, r6, r3
	ldr r2, [r0]
	movs r7, #0x8a
	lsls r7, r7, #2
	adds r0, r4, r7
	ldr r3, [r0]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r7, #0
	ldrsh r0, [r5, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _08042C50
	rsbs r1, r1, #0
_08042C50:
	cmp r1, r3
	bge _08042C7E
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r7, #2
	ldrsh r0, [r5, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _08042C64
	rsbs r1, r1, #0
_08042C64:
	cmp r1, #0xff
	bgt _08042C7E
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08042C78
	rsbs r0, r0, #0
_08042C78:
	movs r1, #1
	cmp r0, r3
	blt _08042C80
_08042C7E:
	movs r1, #0
_08042C80:
	cmp r1, #0
	beq _08042CDE
	ldr r3, _08042CEC @ =0x00000434
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
	bge _08042CC2
	rsbs r0, r0, #0
_08042CC2:
	cmp r0, #0x3f
	bgt _08042CDE
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08042CD0
	rsbs r0, r0, #0
_08042CD0:
	cmp r0, #0x1f
	bgt _08042CDE
	movs r0, #0x80
	lsls r0, r0, #4
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_08042CDE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042CEC: .4byte 0x00000434
