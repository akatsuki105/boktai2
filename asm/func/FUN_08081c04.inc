	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _08081C30 @ =0x000009C8
	adds r6, r7, r0
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08081C38
	bl VM_GetValue
	ldr r2, _08081C34 @ =0x00000A7A
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetValue
	adds r5, r0, #0
	b _08081C42
	.align 2, 0
_08081C30: .4byte 0x000009C8
_08081C34: .4byte 0x00000A7A
_08081C38:
	ldr r0, _08081CFC @ =0x00000A7A
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	movs r5, #0x1e
_08081C42:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0x20
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x14
	strh r0, [r1]
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r1, _08081D00 @ =0x00002110
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0x43
	bl AuxSprite_Add
	movs r0, #4
	strh r0, [r6, #0x10]
	adds r0, r4, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	movs r1, #2
	mov r8, r1
	mov r2, r8
	strb r2, [r6, #7]
	movs r0, #0x7f
	strb r0, [r6, #9]
	strb r0, [r6, #8]
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r2, _08081D04 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xaa
	orrs r0, r3
	ldr r1, _08081D08 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, _08081D0C @ =0xFFEC0000
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08081D10 @ =0x00002101
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	mov r1, r8
	str r1, [sp]
	ldr r2, _08081D14 @ =0x00000A7E
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x32
	movs r3, #0x10
	bl Hitbox_SetAttack
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081CFC: .4byte 0x00000A7A
_08081D00: .4byte 0x00002110
_08081D04: .4byte 0xFFFF0000
_08081D08: .4byte 0x0000FFFF
_08081D0C: .4byte 0xFFEC0000
_08081D10: .4byte 0x00002101
_08081D14: .4byte 0x00000A7E
