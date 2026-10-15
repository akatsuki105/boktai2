	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x20]
	mov sl, r1
	movs r1, #0
	movs r6, #0
	movs r0, #1
	mov r2, sl
	strb r0, [r2, #2]
	strb r0, [r2, #1]
	strh r6, [r2, #8]
	strb r1, [r2, #0xd]
	strb r1, [r2, #0xc]
	mov r4, sl
	adds r4, #0xbc
	mov r5, sl
	adds r5, #0xe8
	ldr r1, _08059CFC @ =0x00005292
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl AuxSprite_Add
	movs r0, #3
	strh r0, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #7]
	movs r0, #0xd8
	add r0, sl
	mov r8, r0
	str r6, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _08059D00 @ =0x05000002
	bl CpuSet
	mov r7, sl
	adds r7, #0x6c
	ldr r2, _08059D04 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08059D08 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _08059D0C @ =0x00004005
	movs r0, #0x10
	mov sb, r0
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08059D10 @ =FUN_08059bb0
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1e]
	adds r0, r7, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r7, #0
	bl Hitbox_Register
	subs r7, #0x50
	movs r1, #0x20
	strh r1, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	strh r1, [r5, #4]
	strh r6, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	strh r6, [r4, #4]
	ldr r2, _08059D14 @ =0x00002001
	mov r0, sb
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08059D18 @ =FUN_08059bcc
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1c]
	movs r0, #0x80
	lsls r0, r0, #0xa
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r2, #0x1e
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059CFC: .4byte 0x00005292
_08059D00: .4byte 0x05000002
_08059D04: .4byte 0xFFFF0000
_08059D08: .4byte 0x0000FFFF
_08059D0C: .4byte 0x00004005
_08059D10: .4byte FUN_08059bb0
_08059D14: .4byte 0x00002001
_08059D18: .4byte FUN_08059bcc
