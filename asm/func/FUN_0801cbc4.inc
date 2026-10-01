	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3e
	ldrb r0, [r6]
	lsls r1, r0, #5
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0801CC74 @ =0x00000978
	adds r1, r1, r0
	adds r1, r1, r5
	mov r8, r1
	adds r0, r5, #0
	bl EntityDA0B_TakeFnChanged
	cmp r0, #0
	beq _0801CC88
	adds r7, r5, #0
	adds r7, #0x3d
	ldrb r0, [r7]
	lsls r1, r0, #5
	adds r1, r1, r0
	lsls r1, r1, #2
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r5, r1
	mov r0, r8
	movs r2, #0xd
	bl FUN_0801c7bc
	mov r3, r8
	ldr r0, [r3, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x2c]
	ldrb r0, [r6]
	adds r4, r5, #0
	adds r4, #0x41
	adds r0, r4, r0
	ldrb r1, [r7]
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r4, r0
	movs r1, #1
	ldrb r0, [r0]
	lsls r1, r0
	ldr r0, [r5, #0x50]
	bics r0, r1
	str r0, [r5, #0x50]
	ldrb r0, [r6]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r1]
	movs r0, #1
	bl FUN_0801b670
	ldrb r1, [r6]
	adds r4, r4, r1
	ldrb r1, [r4]
	lsls r2, r1, #5
	adds r2, r2, r1
	lsls r2, r2, #2
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0801CC78
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0x10
	b _0801CC7E
	.align 2, 0
_0801CC74: .4byte 0x00000978
_0801CC78:
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0x40
_0801CC7E:
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0x56
	movs r0, #0x28
	strh r0, [r1]
_0801CC88:
	mov r0, r8
	adds r0, #0x44
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r2, [r1]
	lsls r1, r2, #5
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r2, r5, #0
	adds r2, #0x54
	ldr r3, [r5, #0x44]
	movs r4, #3
	str r4, [sp]
	bl LerpVec3
	ldr r0, [r5, #0x44]
	cmp r0, #7
	bls _0801CCBC
	adds r0, r5, #0
	bl FUN_0801c70c
	b _0801CCC8
_0801CCBC:
	adds r0, r5, #0
	bl FUN_0801c7dc
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801CCC8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
