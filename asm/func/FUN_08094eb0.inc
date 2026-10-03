	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	ldr r0, _08094EC8 @ =0x00003AEB
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0xf
	bls _08094ED0
	ldr r1, _08094ECC @ =0x0000204C
	adds r0, r6, r1
	b _08094F06
	.align 2, 0
_08094EC8: .4byte 0x00003AEB
_08094ECC: .4byte 0x0000204C
_08094ED0:
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _08094EF2
	movs r1, #0xff
	lsls r1, r1, #6
	adds r0, r6, r1
	mov r1, sp
	bl FUN_08242a98
	b _08094EFA
_08094EF2:
	ldrb r0, [r1]
	mov r1, sp
	bl FUN_08242b14
_08094EFA:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _08094F1C
	ldr r2, _08094F18 @ =0x0000204C
	adds r0, r6, r2
_08094F06:
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	b _08094F72
	.align 2, 0
_08094F18: .4byte 0x0000204C
_08094F1C:
	ldr r0, _08094F7C @ =0x0000204C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094F80 @ =0x00002044
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0xa0
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetPose
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, [r6, #0x44]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	ldr r2, _08094F84 @ =0x000009E4
	adds r1, r6, r2
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r6, #0x44]
	mov r0, sp
	bl FUN_08094d48
_08094F72:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08094F7C: .4byte 0x0000204C
_08094F80: .4byte 0x00002044
_08094F84: .4byte 0x000009E4
