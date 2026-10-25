	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r8, sb
	mov r1, sb
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024E7E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08024E84
_08024E7E:
	movs r0, #0
	mov r1, sb
	adds r1, #0xa7
_08024E84:
	str r1, [sp, #8]
	cmp r0, #0
	beq _08024EA6
	movs r0, #3
	mov r1, sb
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x18
	ldr r0, _08024ED0 @ =0x0000055C
	add r0, r8
	strh r1, [r0]
	movs r1, #0xac
	lsls r1, r1, #3
	add r1, r8
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
_08024EA6:
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, sp
	ldr r2, _08024ED4 @ =0xFFFFFE00
	adds r0, r2, #0
	ldrh r3, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	ldr r0, _08024ED8 @ =0x0000054C
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08024EDC
	movs r0, #0x80
	b _08024EE0
	.align 2, 0
_08024ED0: .4byte 0x0000055C
_08024ED4: .4byte 0xFFFFFE00
_08024ED8: .4byte 0x0000054C
_08024EDC:
	movs r0, #0xc0
	lsls r0, r0, #2
_08024EE0:
	strh r0, [r1, #2]
	mov r2, sp
	mov r7, r8
	mov r0, sp
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _08024EFC @ =0x0000011F
	cmp r1, r0
	bgt _08024F00
	movs r1, #0x90
	lsls r1, r1, #1
	mov r0, sp
	strh r1, [r0]
	b _08024F0C
	.align 2, 0
_08024EFC: .4byte 0x0000011F
_08024F00:
	movs r3, #0xbe
	lsls r3, r3, #4
	cmp r1, r3
	ble _08024F0C
	mov r0, sp
	strh r3, [r0]
_08024F0C:
	movs r0, #4
	ldrsh r1, [r2, r0]
	ldr r0, _08024F1C @ =0x0000021F
	cmp r1, r0
	bgt _08024F20
	adds r0, #1
	b _08024F28
	.align 2, 0
_08024F1C: .4byte 0x0000021F
_08024F20:
	movs r0, #0xce
	lsls r0, r0, #4
	cmp r1, r0
	ble _08024F2A
_08024F28:
	strh r0, [r2, #4]
_08024F2A:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r4, [r2, r3]
	adds r3, r7, #0
	adds r3, #0xcc
	movs r2, #0
	mov sl, r2
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0xce
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r4, [r2]
	adds r6, r7, #0
	adds r6, #0xdc
	mov r0, sl
	strb r0, [r6]
	adds r1, r7, #0
	adds r1, #0x48
	movs r0, #0
	ldrsh r5, [r3, r0]
	movs r3, #8
	ldrsh r0, [r1, r3]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	movs r3, #1
	strb r3, [r6]
	ldr r1, [sp, #8]
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024FC8
	movs r2, #0x10
	mov r0, r8
	adds r0, #0xa4
	mov r1, sl
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	mov r1, r8
	adds r1, #0xbc
	movs r0, #0
	str r0, [r1]
	mov r0, r8
	adds r0, #0xa8
	strb r3, [r0]
	ldr r0, _08024FC4 @ =0x0000055A
	add r0, r8
	strh r2, [r0]
	b _08024FD2
	.align 2, 0
_08024FC4: .4byte 0x0000055A
_08024FC8:
	mov r1, sb
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08024FD2:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
