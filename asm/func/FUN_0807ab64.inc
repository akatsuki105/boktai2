	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r1, #0
	mov sb, r2
	mov r8, r3
	ldr r6, [r4, #0x1c]
	cmp r6, #1
	bne _0807AB88
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r5, [r4, #0x20]
	ands r5, r0
	cmp r5, #0
	beq _0807AB8E
_0807AB88:
	movs r0, #1
	rsbs r0, r0, #0
	b _0807AC66
_0807AB8E:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _0807ABA0
	adds r0, r4, #0
	bl FUN_0807ab14
_0807ABA0:
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	adds r2, r4, #0
	adds r2, #0xa8
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0807ABCC
	adds r0, r4, #0
	adds r0, #0x90
	ldr r1, [r0]
	orrs r1, r6
	str r1, [r0]
	ldr r2, _0807ABC8 @ =0x000003FE
	adds r0, r4, r2
	strb r5, [r0]
	b _0807AC02
	.align 2, 0
_0807ABC8: .4byte 0x000003FE
_0807ABCC:
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0807AC54 @ =0x000003FE
	adds r0, r4, r1
	strb r6, [r0]
	ldr r2, _0807AC58 @ =0x000002E7
	adds r1, r4, r2
	ldr r0, [sp, #0x24]
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x14
	bl FUN_08066ee4
	adds r1, r0, #0
	add r1, r8
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
_0807AC02:
	ldr r2, [sp, #0x28]
	cmp r2, #0
	ble _0807AC16
	ldr r1, _0807AC5C @ =0x0000095A
	adds r0, r4, r1
	strh r2, [r0]
	ldr r0, _0807AC60 @ =0x0000095C
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
_0807AC16:
	ldr r1, [sp, #0x30]
	cmp r1, #0
	ble _0807AC64
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x34]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0807e7fc
	adds r3, r0, #0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807AC50
	mov r2, sb
	cmp r2, #0
	beq _0807AC50
	movs r0, #0x97
	lsls r0, r0, #4
	adds r2, r4, r0
	mov r4, sb
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
_0807AC50:
	adds r0, r3, #0
	b _0807AC66
	.align 2, 0
_0807AC54: .4byte 0x000003FE
_0807AC58: .4byte 0x000002E7
_0807AC5C: .4byte 0x0000095A
_0807AC60: .4byte 0x0000095C
_0807AC64:
	movs r0, #0
_0807AC66:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
