	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _08229BF8 @ =0x03000248
	str r7, [r0]
	ldr r0, _08229BFC @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r7, #0x18]
	ldr r0, _08229C00 @ =0x00000D9C
	adds r5, r7, r0
	ldr r0, _08229C04 @ =0x0000922E
	ldr r1, _08229C08 @ =0x0000C6A0
	bl GetFile
	ldr r2, _08229C0C @ =0x00000E34
	adds r1, r7, r2
	str r0, [r1]
	ldr r3, _08229C10 @ =0x00000DC8
	adds r4, r7, r3
	adds r0, r4, #0
	ldr r1, _08229C14 @ =0x000097D3
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #8
	rsbs r1, r1, #0
	movs r2, #0x13
	rsbs r2, r2, #0
	bl FUN_0822a4f8
	movs r6, #0
	strb r6, [r5, #7]
	movs r0, #3
	str r0, [r5]
	ldr r0, _08229C18 @ =0x00000DF4
	adds r4, r7, r0
	ldr r2, _08229C1C @ =0x00000DB8
	adds r1, r7, r2
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_080136b4
	ldr r3, _08229C20 @ =0x00000E3A
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08229C24 @ =0x00000E38
	adds r0, r7, r1
	strh r6, [r0]
	ldr r2, _08229C28 @ =0x00000E3C
	adds r0, r7, r2
	strh r6, [r0]
	subs r3, #0x72
	adds r0, r7, r3
	adds r2, #0xc8
	adds r1, r7, r2
	ldr r0, [r0, #0xc]
	str r0, [r1]
	adds r4, r0, #0
	ldr r5, _08229C2C @ =0x0000FFFF
	adds r3, r4, #0
	ldr r0, _08229C30 @ =0x00000EC4
	adds r2, r7, r0
	movs r6, #0xf
_08229AC0:
	ldrh r0, [r3]
	strh r0, [r2, #0x20]
	ldrh r1, [r3]
	adds r0, r5, #0
	ands r0, r1
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r6, #1
	cmp r6, #0
	bge _08229AC0
	adds r2, r4, #0
	adds r2, #0x20
	ldr r3, _08229C34 @ =0x00000EA4
	adds r1, r7, r3
	movs r6, #0xf
_08229AE0:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r6, #1
	cmp r6, #0
	bge _08229AE0
	ldr r1, _08229C38 @ =0x00000F22
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08229C3C @ =0x00000F1C
	adds r0, r7, r2
	movs r2, #0
	strh r1, [r0]
	ldr r3, _08229C40 @ =0x00000F27
	adds r0, r7, r3
	strb r2, [r0]
	movs r6, #0
	movs r0, #1
	mov r8, r0
	ldr r2, _08229C44 @ =0x08224DCD
	mov sb, r2
_08229B0E:
	movs r0, #0xd8
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r7, r4
	adds r5, r4, #0
	adds r5, #0x2c
	adds r0, r5, #0
	ldr r1, _08229C48 @ =0x0000A850
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r4, #0
	movs r1, #8
	rsbs r1, r1, #0
	movs r2, #0x10
	rsbs r2, r2, #0
	bl FUN_0822a4f8
	mov r3, r8
	str r3, [r4]
	adds r0, r4, #0
	adds r0, #0xac
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0xad
	movs r0, #2
	strb r0, [r2]
	adds r4, #0xa8
	mov r0, sb
	str r0, [r4]
	ldrb r1, [r2]
	mov r0, r8
	orrs r0, r1
	strb r0, [r2]
	adds r6, #1
	cmp r6, #0xf
	ble _08229B0E
	movs r1, #0xf5
	lsls r1, r1, #4
	adds r0, r7, r1
	movs r5, #0
	str r5, [r0]
	ldr r2, _08229C4C @ =0x00000F54
	adds r0, r7, r2
	str r5, [r0]
	ldr r3, _08229C1C @ =0x00000DB8
	adds r0, r7, r3
	strh r5, [r0]
	ldr r1, _08229C50 @ =0x00000DBA
	adds r0, r7, r1
	strh r5, [r0]
	ldr r2, _08229C54 @ =0x00000DBC
	adds r0, r7, r2
	strh r5, [r0]
	adds r3, #0xd0
	adds r0, r7, r3
	strh r5, [r0]
	adds r1, #0xcc
	adds r0, r7, r1
	strh r5, [r0]
	adds r2, #0xc8
	adds r0, r7, r2
	strh r5, [r0]
	adds r3, #0xae
	adds r0, r7, r3
	strh r5, [r0]
	ldr r0, _08229C58 @ =0x00000E8C
	adds r1, r7, r0
	movs r0, #0x19
	strh r0, [r1]
	adds r2, #0xa
	adds r1, r7, r2
	movs r0, #0x66
	strh r0, [r1]
	subs r3, #0xa6
	adds r0, r7, r3
	strh r5, [r0]
	ldr r0, _08229C5C @ =0x00000F1A
	adds r1, r7, r0
	movs r0, #0xc8
	strh r0, [r1]
	ldr r1, _08229C60 @ =0x00000F46
	adds r4, r7, r1
	ldrh r0, [r4]
	bl FUN_0823b2d0
	cmp r0, #0
	bne _08229BE0
	movs r2, #0xe4
	lsls r2, r2, #4
	adds r0, r7, r2
	ldrh r1, [r4]
	ldr r3, _08229C64 @ =0x00000E9C
	adds r2, r7, r3
	movs r3, #7
	str r3, [sp]
	str r7, [sp, #4]
	movs r3, #0
	bl FUN_0823b400
_08229BE0:
	ldr r1, _08229C68 @ =0x00000F5C
	adds r0, r7, r1
	str r5, [r0]
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08229BF8: .4byte 0x03000248
_08229BFC: .4byte 0x03002BE0
_08229C00: .4byte 0x00000D9C
_08229C04: .4byte 0x0000922E
_08229C08: .4byte 0x0000C6A0
_08229C0C: .4byte 0x00000E34
_08229C10: .4byte 0x00000DC8
_08229C14: .4byte 0x000097D3
_08229C18: .4byte 0x00000DF4
_08229C1C: .4byte 0x00000DB8
_08229C20: .4byte 0x00000E3A
_08229C24: .4byte 0x00000E38
_08229C28: .4byte 0x00000E3C
_08229C2C: .4byte 0x0000FFFF
_08229C30: .4byte 0x00000EC4
_08229C34: .4byte 0x00000EA4
_08229C38: .4byte 0x00000F22
_08229C3C: .4byte 0x00000F1C
_08229C40: .4byte 0x00000F27
_08229C44: .4byte 0x08224DCD
_08229C48: .4byte 0x0000A850
_08229C4C: .4byte 0x00000F54
_08229C50: .4byte 0x00000DBA
_08229C54: .4byte 0x00000DBC
_08229C58: .4byte 0x00000E8C
_08229C5C: .4byte 0x00000F1A
_08229C60: .4byte 0x00000F46
_08229C64: .4byte 0x00000E9C
_08229C68: .4byte 0x00000F5C
