	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	mov r2, r8
	mov r1, r8
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024D10
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08024D16
_08024D10:
	movs r0, #0
	movs r1, #0xa7
	add r1, r8
_08024D16:
	mov sb, r1
	cmp r0, #0
	beq _08024D38
	movs r0, #2
	mov r1, r8
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x18
	ldr r3, _08024D64 @ =0x0000055C
	adds r0, r2, r3
	strh r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #3
	adds r1, r2, r0
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
_08024D38:
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, sp
	ldr r3, _08024D68 @ =0xFFFFFE00
	adds r0, r3, #0
	ldrh r3, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	ldr r3, _08024D6C @ =0x0000054C
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08024D70
	movs r0, #0x80
	b _08024D74
	.align 2, 0
_08024D64: .4byte 0x0000055C
_08024D68: .4byte 0xFFFFFE00
_08024D6C: .4byte 0x0000054C
_08024D70:
	movs r0, #0xc0
	lsls r0, r0, #2
_08024D74:
	strh r0, [r1, #2]
	mov r4, sp
	adds r7, r2, #0
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08024D90 @ =0x0000011F
	cmp r1, r0
	bgt _08024D94
	movs r1, #0x90
	lsls r1, r1, #1
	mov r0, sp
	strh r1, [r0]
	b _08024DA0
	.align 2, 0
_08024D90: .4byte 0x0000011F
_08024D94:
	movs r2, #0xbe
	lsls r2, r2, #4
	cmp r1, r2
	ble _08024DA0
	mov r0, sp
	strh r2, [r0]
_08024DA0:
	movs r3, #4
	ldrsh r1, [r4, r3]
	ldr r0, _08024DB0 @ =0x0000021F
	cmp r1, r0
	bgt _08024DB4
	adds r0, #1
	b _08024DBC
	.align 2, 0
_08024DB0: .4byte 0x0000021F
_08024DB4:
	movs r0, #0xce
	lsls r0, r0, #4
	cmp r1, r0
	ble _08024DBE
_08024DBC:
	strh r0, [r4, #4]
_08024DBE:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r3, #4
	ldrsh r4, [r4, r3]
	adds r3, r7, #0
	adds r3, #0xcc
	movs r5, #0
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0xce
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r4, [r2]
	adds r6, r7, #0
	adds r6, #0xdc
	strb r5, [r6]
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
	movs r2, #1
	strb r2, [r6]
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #0
	beq _08024E40
	movs r0, #3
	mov r1, r8
	adds r1, #0xa6
	strb r0, [r1]
	adds r1, #0x16
	movs r0, #0
	str r0, [r1]
	mov r0, r8
	adds r0, #0xa8
	strb r2, [r0]
	b _08024E4A
_08024E40:
	mov r1, r8
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08024E4A:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
